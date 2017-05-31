/*
演習12-3 List12-7 のプログラムの現在時刻の取得をクラスデータを使って実行せよ

作成日 2017年5月31日

作成者 平澤敬介
*/

#include<iostream>
#include<fstream>
#include<ctime>
#include"Data.h"

using namespace std;

const char filename[] = "LastTime.txt";

//関数宣言
void get_data();
void put_data();

void get_data_class();
void put_data_class();

int main()
{
	get_data_class();		//演習内容 クラスを使う

	put_data_class();		//演習内容 クラスを使う

	return 0;
}

//関数 前回の日付を表示する
//仮引数 無し
//返却値 無し

void get_data_class() {

	ifstream file(filename);	//入力ストリームとしてファイルオープン

	//ファイルが開けるかどうかで分岐
	if(file.fail()) {

		cout << "初回です\n";

	} else {

		int year, month, day, hour, min, sec;		//日付の各要素をint型で定義

		//ファイルを開いた時刻を表示 するため変数に値を代入
		file >> year >> month >> day >> hour >> min >> sec;

		cout << "前回 : " << "西暦" << year << "年" << month << "月" << day << "日"
				<< hour << "時" << min << "分" << sec << "秒\n";;
	}

}

//関数 今の日付を書き込む
//仮引数 無し
//返却値 無し

void put_data_class() {

	ofstream file(filename);		//出力ストリームとしてファイルオープン

	//ファイルが開けるかどうかで分岐
	if(file.fail()) {

		cout << "ファイルを開けません\n";

	} else {

		Data now(-1);	//クラスオブジェクト生成 現在時刻

		//ファイルに現在時刻を書き込み
		file << now.open_year() << ' ' << now.open_month() << ' ' << now.open_day()
				<< ' ' << now.open_hour() << ' '<< now.open_min()  << ' ' << now.open_sec() << "\n";
 	}
}

//関数 前回の日付を表示する
//仮引数 無し
//返却値 無し

void get_data() {

	ifstream file(filename);	//入力ストリームとしてファイルオープン

	//ファイルが開けるかどうかで分岐
	if(file.fail()) {

		cout << "初回です\n";

	} else {

		int year, month, day, hour, min, sec;		//日付の各要素をint型で定義

		//ファイルを開いた時刻を表示 するため変数に値を代入
		file >> year >> month >> day >> hour >> min >> sec;

		cout << "前回 : " << "西暦" << year << "年" << month << "月" << day << "日"
				<< hour << "時" << min << "分" << sec << "秒\n";;
	}

}

//関数 今の日付を書き込む
//仮引数 無し
//返却値 無し

void put_data() {

	ofstream file(filename);		//出力ストリームとしてファイルオープン

	//ファイルが開けるかどうかで分岐
	if(file.fail()) {

		cout << "ファイルを開けません\n";

	} else {

		time_t time_set = time(NULL);	//現在時刻を取得

		struct tm* local = localtime(&time_set);		//現在時刻の要素を操作するためポインタを用意

		//ファイルに現在時刻を書き込み
		file << local->tm_year + 1900 << ' ' << local->tm_mon + 1 << ' ' << local->tm_mday
				<< ' ' << local->tm_hour << ' '<< local->tm_min  << ' ' << local->tm_sec << "\n";
 	}
}
