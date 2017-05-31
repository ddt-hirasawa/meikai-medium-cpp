/*
演習9-5 クラス Array_bool にメンバ関数を追加せよ

作成日 2017年5月26日

作成者 平澤敬介
*/

#ifndef CLASS_H_
#define CLASS_H_
#include"array.h"
#include<limits>

//配列テンプレート bool 特殊版
template <>
class Array<bool> {

	typedef unsigned char BYTE;													//char型のBYTEを定義
	static const int CHAR_BITS = std::numeric_limits<unsigned char>::digits;	//unsigned char型の最大Bit

	int num;			//bool型の配列の要素数
	int num_bool;		//bool型を格納するためのBYTE型配列の要素数
	BYTE* ptr;			//BYTE型配列の先頭のポインタ

	//bool型の要素を格納するのに必要なBYTE型配列の要素数
	static int size_of(int size) {

		//要素数をmainに返却する
		return (size + CHAR_BITS -1) / CHAR_BITS ;
	}

public:

	//メンバ関数 bool型を格納するためのBYTE型配列の要素数を返却する
	//仮引数無し
	//返却値 bool型を格納するためのBYTE型配列の要素数
	int get_vsize() const {

		return num_bool;
	}

	//bitベクトル
	class BitOfByteRef {

		BYTE& vec;		//参照先BYTE
		int idx;		//参照先BYTEのビット番号

	public:

		//コンストラクタ
		BitOfByteRef(BYTE& vec_,int idx_) :

			//コンストラクタ初期化子により初期化
			vec(vec_), idx(idx_) {
		}

		//真偽を取得
		operator bool() const {

			//論理積により、idx番目のbitが１の場合 true
			return ( vec >> idx ) & 1U;
		}

		//真偽を設定
		BitOfByteRef& operator = (bool bit) {

			//bool型の true ならば
			if(bit) {

				vec |= 1U << idx;	//論理和により vec は１になる

			} else {

				vec &= ~(1U << idx);//論理積により 0 がかけられ vec は0になる
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
		IdxRngArray(const Array* ident_,int index_) :

			//コンストラクタ初期化子により初期化
			ident(ident_),index(index_) {
		}

		//例外を検出した配列の添字を返却する
		int Index() const {

			return index;
		}
	};

	//明示的コンストラクタ
	explicit Array(int sz,bool v = bool()) :
	//依存する部分 long long型は64bitなので 8byte の配列にナル
	//explicit Array(long long sz,bool v = bool()) :

		//コンストラクタ初期化子によりbool型の配列の要素数とその配列を格納する配列の要素数を初期化
		num(sz),num_bool(size_of(sz)) {

		ptr = new BYTE[num_bool];		//新たに、bool型の配列を格納する配列の領域を確保

		//確保した配列分ポインタの指す配列部分にbool型の値を代入していく
		for(int i=0; i < num_bool; i++) {

			ptr[i] = v;					//ポインタの指す配列部分に代入
		}
	}

		//コピーコンストラクタ
		Array(const Array& tmp) {

			//自分自身ならば 0 を返す
			if(&tmp == this) {

				num = 0;		//要素数０
				ptr = NULL;		//ポインタはNULLを指す

			//異なる場合
			} else {

				num 	 = tmp.num;			//コピー元と要素数を同じにする
				num_bool = tmp.num_bool;	//コピー元と要素数を同じにする

				ptr = new BYTE[num_bool];	//コピー元と同じ分の領域を確保する

				//確保した配列分ポインタの指す配列部分に代入を行う
				for(int i=0; i < num_bool; i++) {

					ptr[i] = tmp.ptr[i];					//ポインタの指す配列部分に代入
				}
			}
		}

		//デストラクタ
		~Array() {

			delete[] ptr;		//確保した領域を解放
		}

		//bool型の要素数を返却するメンバ関数
		int size() const {

			return num;			//データメンバbool型の要素数
		}

		//代入演算子 =
		Array& operator = (const Array& tmp) {

			//自分自身ならば 0 を返す
			if(&tmp != this) {

				//bool型の配列を格納する配列の要素数が異なる場合
				if(num_bool != tmp.num_bool) {

					delete[] ptr;				//今確保している領域を解放

					num_bool = tmp.num_bool;	//代入元と要素数を同じにする

					ptr = new BYTE[num_bool];	//代入元と同じ分の領域を確保する
				}

				num = tmp.num;					//bool型の配列の要素数を同じにする


				//確保した配列分ポインタの指す配列部分に代入を行う
				for(int i=0; i < num_bool; i++) {

					ptr[i] = tmp.ptr[i];					//ポインタの指す配列部分に代入
				}
			}

			return *this;
		}

		//添字演算子関数
		BitOfByteRef operator [] (int i) {

			//例外発生 のとき 例外を投げる
			if(i < 0 || num <= i) {

				throw IdxRngArray(this,i);
			}
			return BitOfByteRef(ptr[i / CHAR_BITS] , (i & (CHAR_BITS - 1)));
		}

		//添字演算子関数 bool 版
		bool operator [] (int i) const {

			//例外発生 のとき 例外を投げる
			if(i < 0 || num <= i) {

				throw IdxRngArray(this,i);
			}

			return (ptr[i / CHAR_BITS] >> (i & (CHAR_BITS - 1)) & 1U) == 1;
		}
};

#endif /* CLASS_H_ */
