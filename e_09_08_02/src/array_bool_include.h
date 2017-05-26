/*
 演習9-8 Array<bool> をインクルードモデル化せよ

 作成日 2017年5月26日

 作成者 平澤敬介
 */

#ifndef ARRAY_BOOL_INCLUDE_H_
#define ARRAY_BOOL_INCLUDE_H_

#include"array_bool.h"
#include<cstdlib>
#include<limits>

//メンバ関数 bool型を格納するためのBYTE型配列の要素数を返却する
//仮引数無し
//返却値 bool型を格納するためのBYTE型配列の要素数
template<class Array>
int Array::set_vsize() const {

	return num_bool;
}

//メンバ関数 bool型を格納するためのBYTE型配列の要素数を返却する
//仮引数無し
//返却値 bool型を格納するためのBYTE型配列の要素数
template<class Array>
int Array::get_size() const {

	return num;
}

//メンバ関数 bool型を格納するためのBYTE型配列の要素数を変更する
//仮引数無し
//返却値 bool型を格納するためのBYTE型配列の要素数
template<class Array>
int& Array::set_vsize(int num) {

	num_bool = num;

	return num_bool;
}

//メンバ関数 bool型を格納するためのBYTE型配列の要素数を変更する
//仮引数無し
//返却値 bool型を格納するためのBYTE型配列の要素数
template<class Array>
int& Array::set_size(int num_) {

	num = num_;

	return num;
}

//bitベクトル
class BitOfByteRef {

	BYTE& vec;		//参照先BYTE
	int idx;		//参照先BYTEのビット番号

public:

	//コンストラクタ
	BitOfByteRef(BYTE& vec_, int idx_) :

			//コンストラクタ初期化子により初期化
			vec(vec_), idx(idx_) {
	}

	//真偽を取得
	operator bool() const {

		//論理積により、idx番目のbitが１の場合 true
		return (vec >> idx) & 1U;
	}

	//真偽を設定
	BitOfByteRef& operator =(bool bit) {

		//bool型の true ならば
		if (bit) {

			vec |= 1U << idx;	//論理和により vec は１になる

		} else {

			vec &= ~(1U << idx);	//論理積により 0 がかけられ vec は0になる
		}

		return *this;			//真偽を返却
	}
};

//例外クラス
class IdxRngArray {

	const Array* ident;		//配列クラスのポインタ
	int index;				//例外を検出した配列の添字

public:

	//コンストラクタ
	IdxRngArray(const Array* ident_, int index_) :

			//コンストラクタ初期化子により初期化
			ident(ident_), index(index_) {
	}

	//例外を検出した配列の添字を返却する
	int Index() const {

		return index;
	}
};

//明示的コンストラクタ
template<class Array>
Array::Array(int sz,bool v = bool()) :
//依存する部分 long long型は64bitなので 8byte の配列にナル
//explicit Array(long long sz,bool v = bool()) :

//コンストラクタ初期化子によりbool型の配列の要素数とその配列を格納する配列の要素数を初期化
num(sz),num_bool(sizeof(sz)) {

	ptr = new BYTE[num_bool];		//新たに、bool型の配列を格納する配列の領域を確保

	//確保した配列分ポインタの指す配列部分にbool型の値を代入していく
	for(int i=0; i < num_bool; i++) {

		//変更動作を見るためにfalse -> true に変更
		ptr[i] = true;//ポインタの指す配列部分に代入
	}
}

//コピーコンストラクタ
template<class Array>
Array::Array(const Array& tmp) {

	//自分自身ならば 0 を返す
	if(&tmp == this) {

		num = 0;		//要素数０
		ptr = NULL;//ポインタはNULLを指す

		//異なる場合
	} else {

		num = tmp.num;			//コピー元と要素数を同じにする
		num_bool = tmp.num_bool;//コピー元と要素数を同じにする

		ptr = new BYTE[num_bool];//コピー元と同じ分の領域を確保する

		//確保した配列分ポインタの指す配列部分に代入を行う
		for(int i=0; i < num_bool; i++) {

			ptr[i] = tmp.ptr[i];					//ポインタの指す配列部分に代入
		}
	}
}

//デストラクタ
template<class Array>
Array::~Array() {

	delete[] ptr;		//確保した領域を解放
}

//bool型の要素数を返却するメンバ関数
template<class Array>
int Array::size() const {

	return num;			//データメンバbool型の要素数
}

//代入演算子 =
template<class Array>
Array& Array::operator =(const Array& tmp) {

	//自分自身ならば 0 を返す
	if (&tmp != this) {

		//bool型の配列を格納する配列の要素数が異なる場合
		if (num_bool != tmp<bool>.num_bool) {

			delete[] ptr;				//今確保している領域を解放

			num_bool = tmp.num_bool;	//代入元と要素数を同じにする

			ptr = new BYTE[num_bool];	//代入元と同じ分の領域を確保する
		}

		num = tmp.num;					//bool型の配列の要素数を同じにする

		//確保した配列分ポインタの指す配列部分に代入を行う
		for (int i = 0; i < num_bool; i++) {

			ptr[i] = tmp.ptr[i];					//ポインタの指す配列部分に代入
		}
	}

	return *this;
}

//添字演算子関数
template<class Array>
BitOfByteRef Array::operator [](int i) {

	//例外発生 のとき 例外を投げる
	if (i < 0 || num <= i) {

		throw IdxRngArray(this, i);
	}
	return BitOfByteRef(ptr[i / CHAR_BITS], (i & (CHAR_BITS - 1)));
}

//添字演算子関数 bool 版
template<class Array>
bool Array::operator [](int i) const {

	//例外発生 のとき 例外を投げる
	if (i < 0 || num <= i) {

		throw IdxRngArray(this, i);
	}

	return (ptr[i / CHAR_BITS] >> (i & (CHAR_BITS - 1)) & 1U) == 1;
}

#endif /* ARRAY_BOOL_INCLUDE_H_ */
