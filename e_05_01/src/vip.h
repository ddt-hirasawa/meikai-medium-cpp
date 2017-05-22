/*
演習5-1 会員クラス群に自己紹介をする仮想関数を追加せよ

作成日 2017年5月22日

作成者 平澤敬介
*/

#ifndef VIP_H_
#define VIP_H_

#include<iostream>
#include<string>
#include"class.h"

//Vip会員クラス
class VipMember : public Member{

	//Vip特典	文字表記のみ
	std::string privilege;

public:
	//コンストラクタ
	VipMember(const std::string& name, int number_, double weight_, const std::string& prv ) :

		//基底クラスをコンストラクタ初期化子により初期化
		Member(name, number_, weight_) {

		//メンバ関数により 特典を設定
		set_prv(prv);
	}

	//仮想関数にした際、仮想関数のデストラクタを要求される？
	virtual ~VipMember() {

	}

	//特典取得 VipMemberクラスのデータメンバのゲッタ
	std::string get_prv() const {

		return privilege;
	}

	//特典設定 VipMemberクラスのデータメンバのセッタ
	void set_prv(const std::string& prv) {

		//mainからの引数で入力がない場合未登録
		privilege = (prv != "") ? prv : "未登録";
	}

	//関数 データメンバの表示 会員情報の開示
	virtual void print() const {

		//データメンバを見やすく表示 Member に特典を加えている
		std::cout << "No." << number << " : " << full_name << "("
				<< weight << "kg)" << "特典 = " << privilege << "\n";
	}

	//演習内容 自己紹介を行う仮想関数
	virtual void introduce() const {

		//派生クラスなので名前、番号、体重のデータに特典が追加されている
		std::cout << "初めまして" << full_name << "です\n"
				<< "VipMember なので  " << privilege << "があります\n";
	}
};

#endif /* VIP_H_ */
