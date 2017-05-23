/*
演習7-2 List7-1 のクラス Derivedにメンバ関数print を追加せよ

作成日 2017年5月23日

作成者 平澤敬介
*/

#ifndef CLASS_H_
#define CLASS_H_

#include<iostream>

//基底クラス
class Base1 {

public:

	int tmp;		//仮のデータメンバ 動作チェック用

	//コンストラクタ
	Base1(int test = 0) :

		//コンストラクタ初期化子で初期化
		tmp(test) {

		//宣言 初期化されたことの確認
		std::cout << "Base1初期化されました\n";
	}

	//メンバ関数 データメンバの表示を行う
	//仮引数 無し
	//返却値 無し
	void print() {

		std::cout << "Base1クラス   : tmp = " << tmp << "\n";
	}
};

//基底クラス
class Base2 {

public:

	int tmp;		//仮のデータメンバ 動作チェック用

	//コンストラクタ
	Base2(int test = 0) :

		//コンストラクタ初期化子で初期化
		tmp(test) {

		//宣言 初期化されたことの確認
		std::cout << "Base2初期化されました\n";
	}

	//メンバ関数 データメンバの表示を行う
	//仮引数 無し
	//返却値 無し
	void print() {

		std::cout << "Base2クラス   : tmp = " << tmp << "\n";
	}
};

//派生クラス
class Derived : public Base1,public Base2 {

	int tmp;		//仮のデータメンバ 動作チェック用 派生クラスは private

public:

	//コンストラクタ
	Derived(int test1,int test2,int test3) :

		//コンストラクタ初期化子で初期化
		//派生の宣言の順番で初期化子を宣言しないと警告が残る
		//派生クラスで宣言しているデータメンバは最後に
		//初期化子を宣言する必要がある
		Base1(test2),Base2(test3),tmp(test1) {

		//宣言 初期化されたことの確認
		std::cout << "Derivedクラス初期化されました\n";
	}

	//メンバ関数 mainから引数として与えた値で基底クラスのデータメンバを書き換える
	//仮引数 mainからの実数
	//返却値 無し

	void func(int add1,int add2) {

		Base1::tmp = add1;
		Base2::tmp = add2;
	}

	//メンバ関数 データメンバの表示を行う
	//仮引数 無し
	//返却値 無し
	void print() {

		Base1::print();
		Base2::print();
		std::cout << "Derivedクラス : tmp = " << tmp << "\n";
	}
};


#endif /* CLASS_H_ */
