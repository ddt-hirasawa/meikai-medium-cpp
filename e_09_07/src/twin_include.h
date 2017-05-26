/*
 演習9-7 9-1節のTwin<>をインクルードモデルで実現せよ

 作成日 2017年5月26日

 作成者 平澤敬介
 */

#include<utility>
#include<algorithm>
#include<cstring>

//デストラクタ
template <class Type>
Twin<Type>::~Twin() {

	std::cout << "テンプレートクラス破棄されました\n";
}

//第一データメンバのゲッタ
template <class Type>
Type Twin<Type>::first_get() const {

	return tmp1;
}

//第一データメンバのゲッタ
template <class Type>
char Twin<Type>::first_char_get() const {

	return tmp1;
}

//第一データメンバのセッタ
template <class Type>
Type& Twin<Type>::first_set() {

	return tmp1;
}

//第二データメンバのゲッタ
template <class Type>
Type Twin<Type>::second_get() const {

	return tmp2;
}

//第二データメンバのゲッタ
template <class Type>
char Twin<Type>::second_char_get() const {

	return tmp2;
}

//第二データメンバのセッタ
template <class Type>
Type& Twin<Type>::second_set() {

	return tmp2;
}

//データメンバ 2値の決定 引数を代入する
template <class Type>
void Twin<Type>::set(const Type& set1, const Type& set2) {

	tmp1 = set1;		//第一データメンバ
	tmp2 = set2;		//第二データメンバ
}

//データメンバを比較し小さいほうを返却する
template <class Type>
Type Twin<Type>::min() const {

	//条件演算子による返却
	return tmp1 < tmp2 ? tmp1 : tmp2;
}

//判別関数 データメンバの一番目が2番目と比較し小さいかどうか
template <class Type>
bool Twin<Type>::ascending() const {

	return tmp1 < tmp2;
}

//ソート関数 昇順で並べ替え
template <class Type>
void Twin<Type>:: sort() {

	//if文で検出し
	if (tmp1 < tmp2) {

		//コンパイラにより提供されるデフォルト関数
		std::swap(tmp1, tmp2);
	}
}

