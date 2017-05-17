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
int my_strcmp(const char*, const char*);
int my_strcmpp(const char**, const char**);

int main() {
	const int line = 6;	//行の要素数

	const int colu = 10;	//列の要素数

	//比較するため、文字列の配列を定義します
	char tmp1[][colu] = { "catch", "pray", "select", "set", "try", "type" };//2次元配列で構成された文字列

	const char* tmp2[] = { "catch", "pray", "select", "set", "try", "type" };//ポインタで構成された文字列

	int len2 = sizeof(tmp2) / sizeof(tmp2[0]);					//ポインタ文字列の文字列数

	//探索前の表示
	cout << "2次元配列\n";
	for (int i = 0; i < line; i++) {

		//配列の i 番目を表示し見やすくします
		cout << "tmp1[" << i << "] = ";

		//ナル文字で区切られるので 仮に 10文字を上限とします
		for (int j = 0; j < colu; j++) {

			//配列の文字列を表示していきます
			cout << tmp1[i][j];
		}

		cout << "\n";
	}

	//探索前の表示
	cout << "ポインタ文字列\n";
	for (int i = 0; i < len2; i++) {

		//先頭のポインタを表示することでナル文字まで表示
		cout << "tmp2[" << i << "] = " << *(tmp2 + i);

		//改行し次の文字列へ
		cout << "\n";
	}

	char select[] = "try";			//探索する文字

	//配列の文字列の探索用 文字列のポインタを返却値としてもらいます
	//関数により、返却されるのは探索された文字列の先頭のポインタなので
	//表示結果は探索した文字列が表示されます
	char* result = reinterpret_cast<char*>(bsearch(&select, tmp1, line,
			sizeof(char[colu]),
			reinterpret_cast<int (*)(const void*, const void*)>(my_strcmp)));

	//返却された値がナル文字 ない場合以外は
	if (result != NULL) {

		//発見したので、そのポインタを表示します
		cout << "配列の文字列を探索した結果 : " << result << "\n";

	//文字列に存在しない場合
	} else {

		//発見できませんでした
		cout << "配列の文字列にありませんでした。\n";
	}

	const char* selectp = "select";			//探索する文字　ポインタの文字列なのでこちらも、ポインタの文字列


	//ポインタの文字列の探索用 文字列のポインタを返却値としてもらいます
	//関数により、返却されるのは探索された文字列の先頭のポインタなので
	//表示結果は探索した文字列が表示されます
	//配列の文字列と違いポインタの文字列を見ているので
	//ポインタのポインタを返却値としてもらいます
	char** resultp = reinterpret_cast<char**>(bsearch(&selectp, tmp2, len2,
			sizeof(*tmp2),
			reinterpret_cast<int (*)(const void*, const void*)>(my_strcmpp)));

	//返却された値がナル文字 ない場合以外は
	if (resultp != NULL) {

		//発見したので、そのポインタを表示します
		cout << "ポインタの配列の文字列を探索した結果 : " << *resultp;

	//文字列に存在しない場合
	} else {

		//発見できませんでした
		cout << "ポインタの配列にありませんでした。\n";
	}

	return 0;
}

//比較関数 文字列を比較して同じ文字列かどうかを判別します
//仮引数 比較する文字列つ
//返却値 同じか違うか true or false

int my_strcmp(const char* tmp1, const char* tmp2) {

	int answer = strcmp(tmp1, tmp2);

	return answer;
}


//比較関数 文字列を比較して同じ文字列かどうかを判別します ポインタ文字列用
//仮引数 比較する文字列つ
//返却値 同じか違うか true or false

int my_strcmpp(const char** tmp1, const char** tmp2) {

	int answer = strcmp(*tmp1, *tmp2);

	return answer;
}
