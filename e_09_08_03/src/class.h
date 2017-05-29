/*
演習9-8-3 FixedArray をインクルードモデル化せよ

作成日 2017年5月29日

作成者 平澤敬介
*/

#ifndef CLASS_H_
#define CLASS_H_

#include<utility>
#include<algorithm>
#include<cstdlib>
#include<limits>

//固定値クラス配列
template <class Type, int N> class FixedArray {

	Type vec[N];		//配列 固定長 N

public:

	//例外クラス
	class IdxRngArray {

		const FixedArray* ident;		//配列クラスのポインタ

		int index;				//例外を検出した配列の添字

	public:

		//コンストラクタ
		IdxRngArray(const FixedArray* ident_, int index_);

		//例外を検出した配列の添字を返却する
		int Index() const;
	};

	//明示的コンストラクタ
	explicit FixedArray(const Type& array_tmp);

	//コピーコンストラクタ
	FixedArray(const FixedArray& tmp_array);

	//固定長を返却するメンバ関数
	int size() const;

	//添字演算子関数
	Type& operator [] (int select);
	//添字演算子関数
	const Type& operator [] (int select) const;

	//代入演算子 =
	FixedArray& operator =(const FixedArray& tmp_array) {

	//固定長分代入を行う
	for (int i = 0; i < N; i++) {

		vec[i] = tmp_array.vec[i];		//代入により同じ配列になる
	}

	//thisポインタにより反映させる
		return *this;
	}
};

#include"class_include.h"

#endif /* CLASS_H_ */
