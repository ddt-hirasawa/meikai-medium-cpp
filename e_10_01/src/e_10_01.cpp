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
	const int max = 5;			//回数 5回が限度

	vector<Date> now_time;	//ベクタークラスオブジェクト生成 int型 空オブジェクト

	//コンテナにプッシュする用のループ
	for(int i=0; i < max; i++) {

		Date now(-1);				//現在時刻 クラスオブジェクト

		now_time.push_back(now);	//現在時刻をプッシュします

		cout << "プッシュ\n";
	}

	cout << "ポップ開始\n";

	//コンテナに格納した分ループしポップします
	for(vector<int>::size_type i=0; i < now_time.size(); i++) {

		cout << i + 1 << "回目 : " << now_time[i];		//先入れ先出し構造のため入れた順で西暦から
	}

	return 0;
}

