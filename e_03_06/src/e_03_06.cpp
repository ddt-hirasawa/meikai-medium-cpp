/*
演習3-6 bserch関数を使ったプログラムを作成せよ

作成日 2017年5月16日

作成者 平澤敬介
*/

#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;

//関数宣言
int my_strcmp(const char*,const char*);

int main()
{
	//比較するため、文字列の配列を定義します
	char tmp1[][10] = { "select","try","catch","pray","set","type"};	//2次元配列で構成された文字列

	int len1 = sizeof(tmp1) / sizeof(tmp1[0]);							//2次元配列の文字列数

	const char* tmp2[] = { "select","try","catch","pray","set","type"};	//ポインタで構成された文字列

	int len2 = sizeof(tmp2) / sizeof(tmp2[0]);							//ポインタ文字列の文字列数

	//探索前の表示
	cout << "2次元配列\n";
	for(int i=0; i < len1; i++) {

		//配列の i 番目を表示し見やすくします
		cout << "tmp1[" << i << "] = ";

		//ナル文字で区切られるので 仮に 10文字を上限とします
		for(int j=0; j < 10; j++) {

			//配列の文字列を表示していきます
			cout << tmp1[i][j];
		}

		cout << "\n";
	}

	//探索前の表示
	cout << "ポインタ文字列\n";
	for(int i=0; i < len2; i++) {


		cout << "tmp2[" << i << "] = " << *(tmp2 + i);


		cout << "\n";
	}

	const char select[] = "catch";			//探索する文字

	int num = 6;					//文字列数


	int* result = reinterpret_cast<int*>(bsearch(&select,tmp2,num,sizeof(char),
			reinterpret_cast<int (*)(const void*,const void*)>(my_strcmp) ));

	cout << "探索した結果 : " <<  result;

	return 0;
}

//比較関数 文字列を比較して同じ文字列かどうかを判別します
//仮引数 比較する文字列つ
//返却値 同じか違うか true or false

int my_strcmp(const char* tmp1,const char* tmp2) {


	int answer = static_cast<int>(strcmp(tmp1,tmp2));

	return answer;
}
