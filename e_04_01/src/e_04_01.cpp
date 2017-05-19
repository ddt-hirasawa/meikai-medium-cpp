/*
演習4-1 List4-15 のクラスBaseのコンストラクタを書き換え 確認せよ

作成日 2017年5月19日

作成者 平澤敬介
*/

#include<iostream>
#include"class.h"

using namespace std;

int main()
{
	Base sample;		//クラス Base のオブジェクト

	Derived tmp;		//クラス Base の派生クラス 中身は 空

	//クラス Base のデータメンバを表示
	cout << "sample.get_tmp() = " << sample.get_tmp1() << "\n";

	//クラス Base のデータメンバ クラス Deribed が継承して表示
	cout << "   tmp.get_tmp() = " << tmp.get_tmp1();

	return 0;
}
