/*
 演習9-8 Array<bool> をインクルードモデル化せよ

 作成日 2017年5月26日

 作成者 平澤敬介
 */

#ifndef ARRAY_BOOL_H_
#define ARRAY_BOOL_H_

#include"array.h"
#include<cstdlib>
#include<limits>

//配列テンプレート bool 特殊版
template<>
class Array<bool> {

	typedef unsigned char BYTE;									//char型のBYTEを定義
	static const int CHAR_BITS = std::numeric_limits<unsigned char>::digits;//unsigned char型の最大Bit

	int num;			//bool型の配列の要素数
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
	explicit Array(int sz, bool v);

	//コピーコンストラクタ
	Array(const Array& tmp);

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
	int& set_vsize(int num);

	//メンバ関数 bool型を格納するためのBYTE型配列の要素数を変更する
	//仮引数無し
	//返却値 bool型を格納するためのBYTE型配列の要素数
	int& set_size(int num_);

	//bool型の要素数を返却するメンバ関数
	int size() const;

	//代入演算子 =
	Array& operator =(const Array& tmp);

	//添字演算子関数
	BitOfByteRef operator [](int i);

	//添字演算子関数 bool 版
	bool operator [](int i) const;
};

#include"Array_bool_include.h"

#endif /* ARRAY_BOOL_H_ */
