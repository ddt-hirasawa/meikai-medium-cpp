/*
演習9-8 Array<> クラスをインクルードモデルにせよ

作成日 2017年5月26日

作成者 平澤敬介
*/

#include<new>
#include<iostream>
#include"array.h"

using namespace std;

int main()
{
	const int num = 10;				//要素数

	Array<int> tmp1(num);			//クラス配列の要素数を変数で決定

	//宣言 tmp1 の配列の中身を表示
	cout << "tmp1\n";

	//全要素数で代入と表示を行う
	for(int i=0; i < num; i++) {

		tmp1[i] = i;				//配列の添字を代入

		//各要素の表示を行います
		cout << "tmp1[" << i << "] = " << tmp1[i] << "\n";
	}

	return 0;
}
