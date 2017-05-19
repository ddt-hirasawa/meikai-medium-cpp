/*
 演習4-3 List 4-12 のクラスに対し、アップキャスト ダウンキャストを試みるプログラムの作成

 作成日 2017年5月19日

 作成者 平澤敬介
 */

#ifndef CLASS_H_
#define CLASS_H_

#include<iostream>

//基底クラス
class Base {

	int tmp1;		//データメンバ テスト用
	int tmp2;

public:

	//コンストラクタ
	Base(int tmp1_, int tmp2_) :

			tmp1(tmp1_), tmp2(tmp2_) {

	}
	//基底クラスの関数 データメンバをコンソールに表示するだけ
	void func() const {

		std::cout << "   Base::tmp1 = " << tmp1 << "\n";
		std::cout << "   Base::tmp2 = " << tmp2 << "\n";
	}

	//ゲッタ tmp1
	int get_tmp1() const {

		return tmp1;
	}

	//ゲッタ tmp2
	int get_tmp2() const {

		return tmp2;
	}
};
//派生クラス
class Derived: public Base {

	int tmp3;			//データメンバ テスト用

public:

	//コンストラクタ 変数3つで初期化
	Derived(int test1, int test2, int test3) :

			//基底クラス 、変数1つが
			Base(test1, test2), tmp3(test3) {}

	void method() const {

		//基底クラスの関数を派生クラスで呼び出します
		func();

		std::cout << "Derived::tmp3 = " << tmp3 << "\n";

	}

	//ゲッタ tmp3
	int get_tmp3() const {

		return tmp3;
	}
};

#endif /* CLASS_H_ */
