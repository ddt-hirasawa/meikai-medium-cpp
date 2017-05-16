/*
 演習3-1 List3-2 の 「良」「優」「可」の識別表示を行うプログラムを変更し、これまで挙げた識別以外でも識別表示するように変更せよ

 作成日 2017年5月16日

 作成者 平澤敬介
 */

#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

//関数宣言 func.cppにまとめます
bool good(int);
bool excellent(int);
bool usually(int);
void put_list(const int a[], int num, bool (*good)(int),bool (*excellent)(int),bool (*usually)(int));

int main() {
	int num = 100;					//配列の要素数を出します

	int* result = new int[num];		//int型の点数を格納する箱を10個用意します

	//現在時刻で乱数の種を生成します
	srand(time(NULL));

	//要素数分 配列の1つ1つに乱数を発生させます
	for (int i = 0; i < num; i++) {

		*(result + i) = rand() % 101;	//0 ～ 100までの間で乱数を発生させます
	}

	cout << "  点数評価\n";
	cout << " 0～59  : ✖\n"
			<< "60～69  : ○\n"
			<< "70～79  : ◎\n"
			<< "80～100 : ★\n";

	cout << "------------\n";

	//関数呼び出し部分 判定します
	put_list(result, num, good, excellent,usually);

	//用済みなので破棄します
	delete[] result;

	return 0;
}
