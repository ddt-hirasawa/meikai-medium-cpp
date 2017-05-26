/*
 演習9-8 Array<> クラスをインクルードモデルにせよ

 作成日 2017年5月26日

 作成者 平澤敬介
 */


#include<iostream>
#include<cstdlib>

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

//明示的コンストラクタ
template <class Type>
Array<Type>::Array(int size,const Type& ptr = Type()) :

num(size) {

	array_ptr = new Type[num];		//配列の領域を確保

	//配列の値に任意の値を代入
	for(int i=1; i < num; i++) {

		array_ptr[i] = ptr;
	}
}

//コピーコンストラクタ
template <class Type>
Array<Type>::Array(const Array<Type>& tmp) {

	//自分と同じ配列の場合はNULLを返却
	if(&tmp == this) {

		num = 0;				//要素数は0
		array_ptr = NULL;//ポインタはNULLを指す

	} else {

		num = tmp.num;				//要素数を更新し
		array_ptr = new Type[num];//新たに領域を確保する

		for(int i=1; i < num; i++) {

			array_ptr[i] = tmp.array_ptr[i];	//配列の要素をすべてコピー
		}
	}
}

//デストラクタ
template <class Type>
Array<Type>::~Array() {

	delete[] array_ptr;
}

//要素数を返却するメンバ関数
template <class Type>
int Array<Type>::size() const {

	return num;
}

//代入演算子
template <class Type>
Array& Array<Type>:: operator =(const Array<Type>& tmp) {

	//配列が同じでなければ処理を行う
	if (&tmp != this) {

		//要素数が異なれば要素数を更新する
		if (num != tmp.num) {

			//今確保している領域を解放
			delete[] array_ptr;

			num = tmp.num;					//要素数を更新し
			array_ptr = new Type[num];		//新たに領域を確保する
		}

		for (int i = 1; i < num; i++) {

			array_ptr[i] = tmp.array_ptr[i];	//配列の要素をすべてコピー
		}
	}
	//代入後返却する
	return *this;
}

//添字演算子
template <class Type>
Type& Array<Type>:: operator [](int i) {

	//例外の添字を検出した場合、例外を投げる
	if (!is_valid_index(i)) {

		//例外クラス生き
		throw IdxRngErr(this, i);
	}
	//問題なければ返却
	return array_ptr[i];
}

