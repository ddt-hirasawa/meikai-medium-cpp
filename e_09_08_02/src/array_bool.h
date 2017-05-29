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
	class BitOfByteRef {

		BYTE& vec;		//参照先BYTE

		int idx;		//参照先BYTEのビット番号

	public:

		//コンストラクタ
		BitOfByteRef(BYTE& vec_, int idx_);

		//真偽を取得
		operator bool() const;

		//真偽を設定
		BitOfByteRef& operator =(bool bit);
	};

	//添字演算子関数
	BitOfByteRef operator [](int i);

	//例外クラス
	class IdxRngArray {

		const Array* ident;		//配列クラスのポインタ

		int index;				//例外を検出した配列の添字

	public:

		//コンストラクタ

		IdxRngArray(const Array* ident_, int index_);

		//例外を検出した配列の添字を返却する
		int Index() const;

	};

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

	//添字演算子関数 bool 版
	bool operator [](int i) const;

	//代入演算子 =
	Array& operator = (const Array& tmp);

	//コピーコンストラクタ
	Array(const Array& tmp);
};

#include"Array_bool_include.h"

#endif /* ARRAY_BOOL_H_ */
