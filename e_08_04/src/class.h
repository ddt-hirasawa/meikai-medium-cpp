/*
演習8-4 実際にプログラムを作成し、動作を確認せよ -> 多層的クラスによる例外クラスの階層化

作成日 2017年5月24日

作成者 平澤敬介
*/

#ifndef CLASS_H_
#define CLASS_H_

#include<iostream>

//基底クラス 数字
//ただし中身は空
class MathEx{

public:

	//純粋仮想デストラクタ
	//他のクラスオブジェクトで領域を確保してはいないので
	//基底クラスでのみ記述します
	virtual~MathEx() = 0;

	//例外が発生した場合 例外の理由を表示します
	virtual void display() const {

		std::cout << "数値演算例外発生\n";
	}
};

//派生クラス 0の除算
//ただし中身は空
class DividedByZero : public MathEx {

public:

	//例外が発生した場合 例外の理由を表示します
	virtual void display() const {

		std::cout << "0による演算発生\n";
	}

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

	//例外が発生した場合 例外の理由を表示します
	virtual void display() const {

		std::cout << tmp << " : 数値演算例外発生\n";
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

	//例外が発生した場合 例外の理由を表示します
	virtual void display() const {

		std::cout << tmp << " : 数値演算例外発生\n";
	}
};

//純粋仮想デストラクタ
inline MathEx::~MathEx() {

}

#endif /* CLASS_H_ */
