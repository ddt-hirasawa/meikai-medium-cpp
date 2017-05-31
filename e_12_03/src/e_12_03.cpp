/*
演習12-3 List12-7 のプログラムの現在時刻の取得をクラスデータを使って実行せよ

作成日 2017年5月31日

作成者 平澤敬介
*/

#include<iostream>
#include<fstream>
#include"Data.h"

using namespace std;

const char filename[] = "LastTime.txt";

//関数宣言
void get_data();
void put_data();

int main()
{
	Data time(-1);

	cout << time;


	return 0;
}

//関数 前回の日付を表示する
//仮引数 無し
//返却値 無し

void get_data() {

	ifstream file(filename);

	if(file.fail()) {

		cout << "初回です\n";

	} else {



	}

}
