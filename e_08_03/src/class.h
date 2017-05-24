/*
演習8-3 List8-7 を指定した通りに書き換えよ

作成日 2017年5月24日

作成者 平澤敬介
*/

#ifndef CLASS_H_
#define CLASS_H_

//基底クラス 数字
//ただし中身は空
class MathEx{

};

//派生クラス 0の除算
//ただし中身は空
class DividedByZero : public MathEx {

};

//派生クラス オーバーフロー
class OverFlow : public MathEx {

	int tmp;		//データメンバ コンストラクタで初期化される値

public:

	//コンストラクタ
	OverFlow(int tmp_) :
		//データメンバの初期化のみを行う
		tmp(tmp_) {
	}

	//ゲッタ データメンバを返却する関数
	int get_tmp() const {

		return tmp;
	}
};

//派生クラス アンダーフロー
class UnderFlow :  public MathEx {

	int tmp;		//データメンバ コンストラクタで初期化される値

public:

	//コンストラクタ
	UnderFlow(int tmp_) :
		//データメンバの初期化のみを行う
		tmp(tmp_) {
	}

	//ゲッタ データメンバを返却する関数
	int get_tmp() const {

		return tmp;
	}
};

#endif /* CLASS_H_ */
