/*
演習4-4 退会済み会員クラス へのポインタから会員クラスへのアップキャストが実行できるか確認せよ

作成日 2017年5月19日

作成者 平澤敬介
*/

#ifndef BASE_H_
#define BASE_H_

#include<string>

//会員クラス
class Member {

	std::string full_name;		//会員の名前
	int number;				//会員番号
	double weight;				//会員の体重

public:

	//コンストラクタ
	Member(const std::string& name,int number_,double weight_) :

		//コンストラクタ初期化子により データメンバを初期化
		full_name(name),number(number_),weight(weight_) {

		set_weight(weight_);			//データメンバの体重を設定
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
};



#endif /* BASE_H_ */
