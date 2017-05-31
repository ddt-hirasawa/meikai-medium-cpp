/*
演習9-2 1-2でのDateクラスをテンプレート化せよ

作成日 2017年5月25日

作成者 平澤敬介
*/

#include"class.h"
#include"data.h"
#include<iostream>

using namespace std;

int main()
{
	Twin<Date<int> >  now(1 , 1);		//Date型のTwin
										//2値での表示
	//[ 日付 , 日付] になる
	cout << "Date型のTwin\n" << now;

	//区切ります
	cout << "\n\n";

	Twin < Twin < Date <int> > >  now1(Twin<Date<int> >(1,1) ,Twin<Date<int> >(1,1));//Date型のTwinのTwin

	//[ [ 日付 , 日付] , //[ 日付 , 日付] ]になるになる
	cout << "Date型のTwinのTwin\n" << now1;

	return 0;
}
