/*
演習9-8 Array<bool> をインクルードモデル化せよ

作成日 2017年5月26日

作成者 平澤敬介
*/

#ifndef ARRAY_H_
#define ARRAY_H_

#include<utility>
#include<algorithm>
#include<iostream>
#include<cstdlib>

template <class Type> class Array {

	int num;				//配列の要素数
	Type* array_ptr;		//配列の先頭を指すポインタ

	//配列として要素数の範囲に収まるか同化の判別
	bool is_valid_index(int idx) {

		return 0 <= idx && idx < num;
	}

public:

	//明示的コンストラクタ
	explicit Array(int size,const Type& ptr);

	//コピーコンストラクタ
	Array(const Array<Type>& tmp);

	//デストラクタ
	~Array();

	//要素数を返却するメンバ関数
	int size() const;

	//代入演算子
	Array& operator = (const Array<Type>& tmp);

	//添字演算子
	Type& operator [] (int i);

	//例外クラス
	class IdxRngErr {

		const Array* ident;		//例外を検出した配列を指すポインタ
		int idx;				//配列の添字

	public:

		//コンストラクタ
		IdxRngErr(Array* ptr, int idx_) :

				ident(ptr), idx(idx_) {
		}

		//メンバ関数
		//配列の添字を返却
		int Index() const {

			return idx;
		}
	};
};

#include"array_include.h"

#endif /* ARRAY_H_ */
