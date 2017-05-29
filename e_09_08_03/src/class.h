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
		IdxRngArray(const FixedArray* ident_, int index_) :
			ident(ident_),index(index_){
		}

		//例外を検出した配列の添字を返却する
		int Index() const {

			return index;
		}
	};

	//明示的コンストラクタ
	explicit FixedArray(const Type& array_tmp = Type()) {

		//配列の固定長分代入を行う
		for(int i=0; i < N; i++) {

			vec[i] = array_tmp;		//Typeによりデフォルト値が与えられる
		}
	}

	//コピーコンストラクタ
	FixedArray(const FixedArray& tmp_array) {

		//初期化子が自分自身でなければ代入をお粉う
		if(&tmp_array != this) {

			//固定長分代入を行う
			for(int i=0; i < N; i++) {

				vec[i] = tmp_array.vec[i];	//代入により同じ配列になる
			}
		}
	}

	//固定長を返却するメンバ関数
	int size() const {

		return N;
	}

	//代入演算子 =
	FixedArray& operator = (const FixedArray& tmp_array) {

		//固定長分代入を行う
		for(int i=0; i < N; i++) {

			vec[i] = tmp_array.vec[i];		//代入により同じ配列になる
		}

		//thisポインタにより反映させる
		return *this;
	}

	//添字演算子関数
	Type& operator [] (int select) {

		//配列の要素が要素の範囲外であれば例外とする
		if(select < 0 || N <= select) {

			//例外クラス生成
			throw IdxRngArray(this, select);
		}
		//例外が無い場合、配列の値を返却
		return vec[select];
	}
	//添字演算子関数
	const Type& operator [] (int select) const {

		//配列の要素が要素の範囲外であれば例外とする
		if(select < 0 || N <= select) {
			//例外クラス生成
			throw IdxRngArray(this, select);
		}
		//例外が無い場合、配列の値を返却
		return vec[select];
	}
};



#endif /* CLASS_H_ */
