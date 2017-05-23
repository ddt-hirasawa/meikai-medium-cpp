/*
演習7-5 仮想派生を行ったクラスオブジェクトでのデストラクタの動作を確認せよ

作成日 2017年5月23日

作成者 平澤敬介
*/

#ifndef CLASS_H_
#define CLASS_H_

#include<iostream>

//基底クラス 1
class TestA {

	int test;	//変数の定義

public:

	//コンストラクタ
	TestA() :

		test(10){

		std::cout << "基底クラス 1 生成 データメンバ : " << test << "\n";
	}
	//デストラクタ
	~TestA() {

		std::cout << "基底クラス 1 破棄 データメンバ : " << test << "\n";
	}
};

//基底クラス
class TestB {

	int test;	//変数の定義

public:

	//コンストラクタ
	TestB() :

		test(11){

		std::cout << "基底クラス 2 生成 データメンバ : " << test << "\n";
	}

	//デストラクタ
	~TestB() {

		std::cout << "基底クラス 2 破棄 データメンバ : " << test << "\n";
	}
};

//派生クラス 1
//変更 仮想派生に変更
class TestX : virtual TestA , virtual TestB{
//class TestX : TestA ,TestB{
public:
	int test;	//変数の定義

	//コンストラクタ
	TestX() :

		TestA(), TestB(){

		test = 12;

		std::cout << "派生クラス 1 生成 データメンバ : " << test << "\n";
	}

	//デストラクタ
	~TestX() {

		std::cout << "派生クラス 1 破棄 データメンバ : " << test << "\n";
	}
};

//派生クラス 2
//変更 仮想派生に変更
class TestY : virtual TestB , virtual TestA{
//class TestY : TestB , TestA{
public:
	int test;

	//コンストラクタ
	TestY() :

		TestB(), TestA(){

		test = 13;
		std::cout << "派生クラス 2 生成 データメンバ : " << test << "\n";
	}

	//デストラクタ
	~TestY() {

		std::cout << "派生クラス 2 破棄 データメンバ : " << test << "\n";
	}
};

//最終派生クラス
class TestZ : TestX , TestY{		//クラスの宣言時 、X -> Y に向かって基底クラスからオブジェクトが
//class TestZ : TestY , TestX{		//生成され派生クラス X Y が初期化された段階でクラス Zが初期化される
public:
	int test;	//変数の定義

	//コンストラクタ
	TestZ() :

		TestX(),TestY(){

		test = 14;
		std::cout << "完成クラス 1 生成 データメンバ : " << test << "\n\n";
	}

	//デストラクタ
	~TestZ() {

		std::cout << "完成クラス 1 破棄 データメンバ : " << test << "\n";
	}
};



#endif /* CLASS_H_ */
