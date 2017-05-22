/*
演習5-2 List5-18 の関数の引数をポインタから参照に変更すること

作成日 2017年5月22日

作成者 平澤敬介
*/

#ifndef CLASS_H_
#define CLASS_H_

#include<iostream>
#include<string>

//会員クラス
class Member {

public:
	std::string full_name;		//会員の名前
	int number;					//会員番号
	double weight;				//会員の体重

public:

	//コンストラクタ
	Member(const std::string& name,int number_,double weight_) :

		//コンストラクタ初期化子により データメンバを初期化
		full_name(name),number(number_){

		set_weight(weight_);			//データメンバの体重を設定
	}

	//仮想関数にした際、仮想関数のデストラクタを要求される？
	virtual ~Member() {

	}

	//ゲッタ データメンバの名前を返す
	std::string get_name() const {

		return full_name;
	}

	//ゲッタ データメンバの会員番号を返す
	int get_number() const {

		return number;
	}

	//ゲッタ データメンバの体重を返す
	double get_weight() const {

		return weight;
	}

	//関数 データメンバの体重を決定する
	void set_weight(double weight_) {

		weight = (weight_ > 0) ? weight_ : 0;
	}

	//関数 データメンバの表示 会員情報の開示
	//仮想関数 virtual を先頭につけることによってメンバ関数が仮想関数になる
	//関数名や引数が同じなら派生先も自動で仮想関数になる
	//仮想関数でないと、派生先で追加したデータメンバの表示ができない Memberクラスのprint関数が呼び出されるから
	virtual void print() const {

		//データメンバを見やすく表示
		std::cout << "No." << number << " : " << full_name << "(" << weight << "kg)\n";
	}

	//演習内容 自己紹介を行う仮想関数
	virtual void introduce() const {

		//基底クラスなので名前、番号、体重のデータしかない
		std::cout << "初めまして" << full_name << "です\n"
				<< "よろしくお願いします\n";
	}
};

#endif /* CLASS_H_ */
