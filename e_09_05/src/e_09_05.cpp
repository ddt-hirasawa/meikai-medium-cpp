/*
演習9-5 クラス Array_bool にメンバ関数を追加せよ

作成日 2017年5月26日

作成者 平澤敬介
*/

#include<iostream>
#include"class.h"
#include"array.h"

using namespace std;

//関数宣言
void print_array(const Array<bool>& tmp);

int main()
{
	Array<bool> tmp1(10);

	cout << boolalpha;

	for(int i=0; i < tmp1.size(); i++) {


		cout << "tmp1[" << i << "] = " << tmp1[i] << "\n";
	}

	Array<bool> tmp2(tmp1);

	Array<bool> tmp3(5);


	cout << "tmp1 = " << print_array(tmp1) << "\n";
	cout << "tmp2 = " << print_array(tmp2) << "\n";
	cout << "tmp3 = " << print_array(tmp3) << "\n";

	return 0;
}

//関数 array<bool> の配列を0 1 ですべて表示する
//仮引数 array<bool> の配列
//返却値 無し

void print_array(const Array<bool>& tmp) {


	for(int i=0; i < tmp.size(); i++) {

		cout << (tmp[i] ? '1' : '0');
	}

}
