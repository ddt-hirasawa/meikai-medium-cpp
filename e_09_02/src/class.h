/*
演習9-2 1-2でのDateクラスをテンプレート化せよ

作成日 2017年5月25日

作成者 平澤敬介
*/

#ifndef CLASS_H_
#define CLASS_H_

#include<utility>
#include<algorithm>
#include<cstring>
#include<iostream>
#include"date.h"


//テンプレートクラス
template <class Type> class Twin {

	Type tmp1;		//型の指定をしない変数

public:

	//テンプレートクラスのコンストラクタ
	//初期化子を含めすべて Type 表記
	Twin(const Type& tmp1_ = Type()) :

		//初期化子は変化なし
		tmp1(tmp1_) {
	}

	//デストラクタ
	~Twin(){

		std::cout << "テンプレートクラス破棄されました\n";
	}

	//第一データメンバのゲッタ
	Type first_get() const {

		return tmp1;
	}

	//第一データメンバのゲッタ
	Type first_char_get() const {

		return tmp1;
	}
};

//挿入子
template <class Type> inline std::ostream& operator << (std::ostream& stream,const Twin<Type>& tmp) {

	return stream << "[" << tmp.first_get() << "," << tmp.second_get() << "]\n";
}

#endif /* CLASS_H_ */
