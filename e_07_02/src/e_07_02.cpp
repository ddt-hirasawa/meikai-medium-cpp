/*
演習7-2 List7-1 のクラス Derivedにメンバ関数print を追加せよ

作成日 2017年5月23日

作成者 平澤敬介
*/

#include<iostream>
#include"class.h"

using namespace std;

int main()
{
	Derived tmp(1,2,3);		//派生クラスオブジェクトの初期化

	//基底クラス 1 の書き換え前の値を表示
	tmp.Base1::print();

	//基底クラス 2 の書き換え前の値を表示
	tmp.Base2::print();

	//基底クラスから引き継いだデータメンバを書き換える
	tmp.func(10,100);

	//基底クラス 1 の書き換え後の値を表示
	tmp.Base1::print();

	//基底クラス 2 の書き換え後の値を表示
	tmp.Base2::print();

	cout << "演習内容\n";

	//追加したメンバ関数 基底クラスのデータメンバも含めて表示する
	tmp.print();

	return 0;
}
