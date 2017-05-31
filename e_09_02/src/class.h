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

//テンプレートクラス
template <class Type>

class Twin {

	Type tmp1;		//型の指定をしない変数
	Type tmp2;		//型の指定をしない変数


public:

	//テンプレートクラスのコンストラクタ
	//初期化子を含めすべて Type 表記
	Twin(const Type& tmp1_ = Type() , const Type& tmp2_ = Type()) :

		//初期化子は変化なし
		tmp1(tmp1_) ,tmp2(tmp2_){
	}

	//デストラクタ
	~Twin(){
	}

	//第一データメンバのゲッタ
	Type first_get() const {

		return tmp1;
	}


	//第二データメンバのゲッタ
	Type second_get() const {

		return tmp2;
	}
};



//挿入子

template <class Type> inline std::ostream& operator << (std::ostream& stream,const Twin<Type> & tmp) {

	return stream << "[ " << tmp.first_get() << "," << tmp.second_get() << " ]";
}

#endif /* CLASS_H_ */
