/*
演習5-2 List5-18 の関数の引数をポインタから参照に変更すること

作成日 2017年5月22日

作成者 平澤敬介
*/

#ifndef SENIOR_H_
#define SENIOR_H_

#include<iostream>
#include<string>
#include"class.h"

//長寿会員クラス
class SeniorMember : public Member{

	int care_level;		//要介護度

public:
	//コンストラクタ
	SeniorMember(const std::string& name, int number_, double weight_, int level) :

		//基底クラスをコンストラクタ初期化子により初期化
		Member(name, number_, weight_) {

		//メンバ関数により 要介護度をセッタにより決定
		set_care_level(level);
	}

	//仮想関数にした際、仮想関数のデストラクタを要求される？
	virtual ~SeniorMember() {

	}

	//要介護度の取得 データメンバcare_levelのゲッタ
	int get_care_level() const {

		return care_level;
	}

	//要介護度の取得 データメンバcare_levelのセッタ
	void set_care_level(int level) {

		//mainからの引数で範囲外の場合 介護の必要無し
		care_level = (1 <= level && level <= 5) ? level : 0;
	}

	//関数 データメンバの表示 顧客情報の開示
	virtual void print() const {

		//データメンバを見やすく表示 Member に要介護度を加えている
		std::cout << "No." << number << " : " << full_name << "("
				<< weight << "kg)" << "要介護度 = " << care_level << "\n";
	}

	//演習内容 自己紹介を行う仮想関数
	virtual void introduce() const {

		//派生クラスなので名前、番号、体重のデータに介護レベルが追加されている
		std::cout << "初めまして" << full_name << "です\n"
				<< "SeniorMember なので 介護レベル " << care_level << "です\n";
	}
};






#endif /* SENIOR_H_ */
