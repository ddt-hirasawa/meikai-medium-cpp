/*
演習10-1 第1章で作成した日付クラスのベクトルを作成するプログラムの作成

作成日 2017年5月30日

作成者 平澤敬介
*/

#include<iostream>
#include<vector>
#include"Date.h"

using namespace std;

int main()
{
	Date now(-1);			//日付クラス 現在時刻で初期化

	//現在時刻を表示
	cout << now;

	vector<int> now_time;	//ベクタークラスオブジェクト生成 int型 空オブジェクト

	now_time.push_back(now.open_year());	//コンテナに西暦を格納
	now_time.push_back(now.open_month());	//コンテナに月を格納
	now_time.push_back(now.open_day());		//コンテナに日を格納
	now_time.push_back(now.open_hour());	//コンテナに時を格納
	now_time.push_back(now.open_min());		//コンテナに分を格納
	now_time.push_back(now.open_sec());		//コンテナに秒を格納

	cout << "西暦";

	//コンテナに格納した分ループしポップします
	for(vector<int>::size_type i=0; i < now_time.size(); i++) {

		cout << now_time[i];		//先入れ先出し構造のため入れた順で西暦から

		//語尾に単位を付けます
		switch(i) {
		case 0 : cout << "年"; break;
		case 1 : cout << "月"; break;
		case 2 : cout << "日"; break;
		case 3 : cout << "時"; break;
		case 4 : cout << "分"; break;
		case 5 : cout << "秒";
		}
	}

	return 0;
}

