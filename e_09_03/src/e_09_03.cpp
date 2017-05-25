/*
演習9-3 Twin< Twin<Date> , Twin<Date>> を要素として持つクラス配列を作成せよ

作成日 2017年5月25日

作成者 平澤敬介
*/

#include<new>
#include<iostream>
#include"array.h"
#include"Twin.h"


using namespace std;

int main()
{
	const int num = 10;						//要素数

	Array<Twin<Twin<int> > >  tmp1(num);	//配列の1つの要素が 1 ->   Twin<int> , Twin<int> にする

	cout << "tmp1\n";

	//全要素数で代入と表示を行う
	for(int i=0; i < num; i++) {

		//配列の1つの要素 = クラス < クラス < 型名 > >( クラス名＜型名＞(引数,引数) , クラス名＜型名＞(引数,引数))
		tmp1[i] = Twin<Twin<int > >(Twin<int>(i,i + 1) , Twin<int>(i + 2,i + 3));

		//各要素の表示を行います
		cout << tmp1[i] << "\n";
	}


	return 0;
}
