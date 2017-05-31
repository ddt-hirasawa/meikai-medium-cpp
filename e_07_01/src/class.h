/*
演習7-1 クラス群を作成しクラスZ型のオブジェクトを初期化する際の基底クラス部分のオブジェクトの
初期化の順序を示せ

作成日 2017年5月23日

作成者 平澤敬介
*/

#ifndef CLASS_H_
#define CLASS_H_

#include<iostream>

//基底クラス A
class TestA {

	int test;	//変数の定義

public:

	//コンストラクタ
	TestA() :

		test(10){

		std::cout << "基底クラス A 生成 データメンバ : " << test << "\n";
	}
};

//基底クラス B
class TestB {

	int test;	//変数の定義

public:

	//コンストラクタ
	TestB() :

		test(11){

		std::cout << "基底クラス B 生成 データメンバ : " << test << "\n";
	}
};

//派生クラス A
class TestX : TestA , TestB{
public:
	int test;	//変数の定義

	//コンストラクタ
	TestX() :

		TestA(), TestB(){

		test = 12;

		std::cout << "派生クラス A 生成 データメンバ : " << test << "\n";
	}
};

//派生クラス B
class TestY : TestB , TestA{
public:
	int test;	//変数の定義

	//コンストラクタ
	TestY() :

		TestB(), TestA(){

		test = 13;
		std::cout << "派生クラス B 生成 データメンバ : " << test << "\n";
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
		std::cout << "完成クラス A 生成 データメンバ : " << test << "\n";
	}
};

#endif /* CLASS_H_ */
