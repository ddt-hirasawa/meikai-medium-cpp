/*
演習4-1 List4-15 のクラスBaseのコンストラクタを書き換え 確認せよ

作成日 2017年5月19日

作成者 平澤敬介
*/

#ifndef CLASS_H_
#define CLASS_H_

#include<iostream>

//簡易クラス 継承
class Base {

	int tmp1;	//データメンバ

public:

	//コンストラクタ コンストラクタ初期化子により tmp2で初期化
	Base(int tmp2 = 99) : tmp1(tmp2) {

		//宣言 コンストラクタが呼び出されたとき表示される
		std::cout << "Base::tmp1 を" << tmp1 << "で初期化\n";
	}

	//ゲッタ データメンバ tmp1 を呼び出す
	int get_tmp1() const {

		return tmp1;
	}
};

//派生クラス クラス Base の情報を引き継ぐ
class Derived : public Base {

	//空
};

#endif /* CLASS_H_ */
