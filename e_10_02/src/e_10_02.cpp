/*
演習10-2 List 10-9 の関数テンプレートを {1, 2, 3, 4, ,5} となるように書き換えよ

作成日 2017年5月30日

作成者 平澤敬介
*/

#include<string>
#include<vector>
#include<string>
#include<utility>
#include<algorithm>
#include<cstdlib>
#include<iostream>

using namespace std;

template <class T, class Allocator>
//関数 ベクトルtmp の全要素を表示する
void print_vector(const vector<T, Allocator>& tmp);

int main()
{
	int test1[] = {1,2,3,4,5};												//int型 コンテナ格納用配列

	vector<int> tmp1(test1,test1 + sizeof(test1) / sizeof(test1[0]));		//int型の大きさでコンテナを定義

	cout << "tmp1のコンテナの先頭のポインタ : " << (test1 + sizeof(test1) / sizeof(test1[0])) << "\n";

	double test2[] = {2.3, 1.9, 3.4, 6.5,2.4};								//double型 コンテナ格納用配列

	vector<double> tmp2(test2,test2 + sizeof(test2) / sizeof(test2[0]));	//double型の大きさでコンテナを定義

	cout << "tmp2のコンテナの先頭のポインタ : " << (test2 + sizeof(test2) / sizeof(test2[0])) << "\n";

	string test3[] = {"abc","def","123456789","asdfgh"};					//string型 コンテナ格納用配列

	vector<string> tmp3(test3,test3 + sizeof(test3) / sizeof(test3[0]));	//string型の大きさでコンテナを定義

	cout << "tmp3のコンテナの先頭のポインタ : " << (test3 + sizeof(test3) / sizeof(test3[0])) << "\n";

	print_vector(tmp1);		//int
	print_vector(tmp2);		//double
	print_vector(tmp3);		//string それぞれで同じ関数を呼び出す

	return 0;
}


template <class T,class Allocator >
//関数 ベクトルtmp の全要素を表示する
//仮引数 Vectorオブジェクト
//返却値 無し

void print_vector(const vector<T,Allocator>& tmp) {

	//括弧で区切ります
	cout << "{";

	//コンテナに格納された数分表示を行う
	for(typename vector<T,Allocator>::size_type i = 0;i < tmp.size(); i++) {

		cout << tmp[i];				//コンテナに格納された順に表示

		//空になる直前まで点とスペースで区切る
		if(i < tmp.size() - 1) {

			//点で値を区切ります
			cout << ", ";
		}
	}

	//括弧で区切ります
	cout << "}\n";
}

