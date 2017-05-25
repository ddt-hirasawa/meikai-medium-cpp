/*
 演習9-4 2次元配列クラスで実現せよ

 作成日 2017年5月25日

 作成者 平澤敬介
 */

#include<new>
#include<iostream>
#include"matrix.h"
#include"twin.h"

using namespace std;

int main() {
	const int num = 5;						//要素数

	Matrix<Twin<Twin<int> > > tmp1(num, num);//配列の1つの要素が 1 ->   Twin<int> , Twin<int> にする

	cout << "tmp1\n";

	//全要素数で代入と表示を行う
	for (int i = 1; i <= num; i++) {

		cout << i << "行目\n";

		for (int j = 1; j <= num; j++) {

			//配列の1つの要素 = クラス < クラス < 型名 > >( クラス名＜型名＞(引数,引数) , クラス名＜型名＞(引数,引数))
			tmp1[i][j] = Twin<Twin<int> >(Twin<int>(i, i + 1),Twin<int>(i + 2, i + 3));

			//各要素の表示を行います
			cout << tmp1[i][j];
		}
		cout << "\n";
	}

	return 0;
}
