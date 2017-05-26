/*
 演習9-8 Array<bool> をインクルードモデル化せよ

 作成日 2017年5月26日

 作成者 平澤敬介
 */

#ifndef ARRAY_BOOL_H_
#define ARRAY_BOOL_H_

#include<utility>
#include<algorithm>
#include"array.h"
#include<cstdlib>
#include<limits>

//配列テンプレート bool 特殊版
template<>
class Array<bool> {

	typedef unsigned char BYTE;									//char型のBYTEを定義
	static const int CHAR_BITS = std::numeric_limits<unsigned char>::digits;//unsigned char型の最大Bit

	int num_array;			//bool型の配列の要素数
	int num_bool;		//bool型を格納するためのBYTE型配列の要素数
	BYTE* ptr;			//BYTE型配列の先頭のポインタ

	//bool型の要素を格納するのに必要なBYTE型配列の要素数
	static int size_of(int size) {

		//要素数をmainに返却する
		return (size + CHAR_BITS - 1) / CHAR_BITS;
	}

public:

	//bitベクトル
	class BitOfByteRef {};

	//例外クラス
	class IdxRngArray {};

	//明示的コンストラクタ
	explicit Array(int sz, bool v);

	//デストラクタ
	~Array();

	//メンバ関数 bool型を格納するためのBYTE型配列の要素数を返却する
	//仮引数無し
	//返却値 bool型を格納するためのBYTE型配列の要素数
	int get_vsize() const;

	//メンバ関数 bool型を格納するためのBYTE型配列の要素数を返却する
	//仮引数無し
	//返却値 bool型を格納するためのBYTE型配列の要素数
	int get_size() const;

	//メンバ関数 bool型を格納するためのBYTE型配列の要素数を変更する
	//仮引数無し
	//返却値 bool型を格納するためのBYTE型配列の要素数
	int& set_vsize(int);

	//メンバ関数 bool型を格納するためのBYTE型配列の要素数を変更する
	//仮引数無し
	//返却値 bool型を格納するためのBYTE型配列の要素数
	int& set_size(int);

	//bool型の要素数を返却するメンバ関数
	int size() const;

	//添字演算子関数
	BitOfByteRef operator [](int i);

	//添字演算子関数 bool 版
	bool operator [](int i) const;

	//代入演算子 =
	Array& operator =(const Array& tmp) {

		//自分自身ならば 0 を返す
		if (&tmp != this) {

			//bool型の配列を格納する配列の要素数が異なる場合
			if (num_bool != tmp.num_bool) {

				delete[] ptr;				//今確保している領域を解放

				num_bool = tmp.num_bool;	//代入元と要素数を同じにする

				ptr = new BYTE[num_bool];	//代入元と同じ分の領域を確保する
			}

			num_array = tmp.num_array;					//bool型の配列の要素数を同じにする

			//確保した配列分ポインタの指す配列部分に代入を行う
			for (int i = 0; i < num_bool; i++) {

				ptr[i] = tmp.ptr[i];					//ポインタの指す配列部分に代入
			}
		}

		return *this;
	}

	//コピーコンストラクタ
	Array(const Array& tmp) {

		//自分自身ならば 0 を返す
		if (&tmp == this) {

			num_array = 0;		//要素数０
			ptr = NULL;		//ポインタはNULLを指す

			//異なる場合
		} else {

			num_array = tmp.num_array;			//コピー元と要素数を同じにする
			num_bool = tmp.num_bool;			//コピー元と要素数を同じにする

			ptr = new BYTE[num_bool];			//コピー元と同じ分の領域を確保する

			//確保した配列分ポインタの指す配列部分に代入を行う
			for (int i = 0; i < num_bool; i++) {

				ptr[i] = tmp.ptr[i];					//ポインタの指す配列部分に代入
			}
		}
	}
};

#include"Array_bool_include.h"

#endif /* ARRAY_BOOL_H_ */
