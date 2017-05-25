/*
演習9-2 1-2でのDateクラスをテンプレート化せよ

作成日 2017年5月25日

作成者 平澤敬介
*/

#include"class.h"
#include"date.h"
#include<iostream>

using namespace std;

int main()
{
	Date<int> tmp1(-1);				//テンプレートクラス化した日付クラスの呼び出し 現在時刻
	Date<int> tmp2(2018,12,31);				//

	Twin<Date<int > >  now(Date<int> tmp1 , Date<int> tmp2);

	//cout << now;

	return 0;
}
