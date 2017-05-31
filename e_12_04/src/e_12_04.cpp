/*
演習12-4 演習12-3 に気分の項目を付けたし表示を行え。ただし、気分が"最高"と入力された場合
日付をバグらせて表示せよ

作成日 2017年5月31日

作成者 平澤敬介
*/

#include<string>
#include<iostream>
#include<fstream>
#include<ctime>
#include"Data.h"

using namespace std;

const char filename[] = "LastTime.txt";

//関数宣言
void get_data_class();
void put_data_class();

int main()
{
	get_data_class();		//日付と気分の表示を行う

	put_data_class();		//日付と気分を書き込む

	return 0;
}

//関数 前回の日付を表示する
//仮引数 無し
//返却値 無し

void get_data_class() {

	ifstream file(filename);	//入力ストリームとしてファイルオープン

	int year, month, day, hour, min, sec;		//日付の各要素をint型で定義

	string condition;							//気分の変数

	//ファイルを開いた時刻を表示 するため変数に値を代入
	file >> year >> month >> day >> hour >> min >> sec >> condition;

	//ファイルが開けるかどうかで分岐
	if(file.fail()) {

		cout << "初回です\n";

	//気分が最高のとき、表示はバグル
	} else if(condition == "最高") {

		cout << "前回 : " << "西暦" << "9999" << "年" << "99" << "月" << "99" << "日"
				<< "99" << "時" << "99" << "分" << "99" << "秒 で最高の気分でした\n";

	//最高以外の時は正確な日付を表示する 気分は様々
	} else {

		cout << "前回 : " << "西暦" << year << "年" << month << "月" << day << "日"
				<< hour << "時" << min << "分" << sec << "秒\n";

		cout << "気分は" << condition << "です\n";
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
				<< ' ' << now.open_hour() << ' '<< now.open_min()  << ' ' << now.open_sec() << ' ';
 	}

	//気分の入力部分
	cout << "気分はどうですか?\n";

	string condition;		//気分の入力を行うための変数

	cin >> condition;		//キーボード入力で気分を決定

	file << condition << "\n";	//出力ストリームに送る
}
