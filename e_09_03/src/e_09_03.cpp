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
	int num = 10;

	Array<Twin<int> >  tmp1[num];

	//for(int i=0; i < num; i++) {

		//tmp1[i] = Twin<Twin<int> > obj(i,i + 1);


		//cout << tmp1[i] << "\n";
	//}



	return 0;
}
