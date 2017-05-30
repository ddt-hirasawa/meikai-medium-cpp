/*
演習10-3 List10-10 10-11 に相当するプログラムの作成

作成日 2017年5月30日

作成者 平澤敬介
*/

#include<vector>
#include<iostream>
#include"Date.h"
#include"twin.h"

using namespace std;

int main()
{
	const int width  = 3; 		//行の変数
	const int length = 6;		//列の変数
	Date now_time(-1);			//日付現在時刻

	Date* ptr = &now_time;

	//Vectorで配列を作成 コンテナの中にint型のコンテナがある
	//					コンテナの個数  <- の中にあるコンテナの個数
	vector<vector<Date*> >   array(width, vector<Date*>(length));

	//行分ループ処理
	for(int i=0; i < width; i++) {
		//列分ループ処理
		for(int j=0; j < length; j++) {

			 array[i][j] = ptr;
		}
	}

	for(int i=0; i < width; i++) {


		for(int j=0; j < length; j++) {

			cout << "[" << i << "][" << j << "] = " << *array[i][j] << "\n";
		}
	}

	return 0;
}
