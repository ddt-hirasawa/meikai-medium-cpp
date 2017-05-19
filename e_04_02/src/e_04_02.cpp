/*
演習4-2 デストラクタの起動の順番を確認せよ

作成日 2017年5月19日

作成者 平澤敬介
*/

#include<iostream>
#include"class.h"

using namespace std;

int main()
{
	cout << "コンストラクタ\n";

	Derived tmp1;			//デフォルトコンストラクタ

	cout << "\n";

	Derived tmp2(1,2,3);	//コンストラクタ

	cout << "\n";

	cout << "デストラクタ\n";

	return 0;
}
