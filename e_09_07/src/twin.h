/*
演習9-7 9-1節のTwin<>をインクルードモデルで実現せよ

作成日 2017年5月26日

作成者 平澤敬介
*/

#ifndef TWIN_H_
#define TWIN_H_

#include<utility>
#include<algorithm>
#include<cstring>
#include<iostream>

//テンプレートクラス
template <class Type> class Twin{

	Type tmp1;		//型の指定をしない変数
	Type tmp2;		//Typeをデータメンバとして定義

public:

	//テンプレートクラスのコンストラクタ
	//初期化子を含めすべて Type 表記
	Twin(const Type& tmp1_ = Type() , const Type& tmp2_ = Type()) :

	//初期化子は変化なし
	tmp1(tmp1_),tmp2(tmp2_) {
	}

	//テンプレートクラスのコピーコンストラクタ
	Twin(const Twin<Type>& tmp) :

	//テンプレートクラスのゲッタで決定
	tmp1(tmp.first_get(),tmp2(tmp.second_get())) {

	}

	//デストラクタ
	~Twin();

	//第一データメンバのゲッタ
	Type first_get() const;

	//第一データメンバのゲッタ
	char first_char_get() const;

	//第一データメンバのセッタ
	Type& first_set();

	//第二データメンバのゲッタ
	Type second_get() const;

	//第一データメンバのゲッタ
	char second_char_get() const;

	//第二データメンバのセッタ
	Type& second_set();

	//データメンバ 2値の決定 引数を代入する
	void set(const Type& set1,const Type& set2);

	//データメンバを比較し小さいほうを返却する
	Type min() const;

	//判別関数 データメンバの一番目が2番目と比較し小さいかどうか
	bool ascending() const;

	//ソート関数 昇順で並べ替え
	void sort();

	Twin operator + (Twin<Twin<Type> >& tmp);
};

//挿入子
template <class Type> inline std::ostream& operator << (std::ostream& stream,const Twin<Type>& tmp) {

	return stream << "[" << tmp.first_get() << "," << tmp.second_get() << "]\n";
}

//挿入子
template <> inline std::ostream& operator << (std::ostream& stream,const Twin<char>& tmp) {

	return stream << "['" << tmp.first_char_get() << "' ,'" << tmp.second_char_get() << "' ]\n";
}

//インクルードモデル化 上に書くのはNG コンパイルできない
#include"twin_include.h"

#endif /* TWIN_H_ */
