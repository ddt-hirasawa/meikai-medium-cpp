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
	const int line  = 3; 		//行の変数
	const int col = 6;			//列の変数
	int set_col;				//List10-11用
	Date now_time(-1);			//日付現在時刻

	//Vectorで配列を作成 コンテナの中にint型のコンテナがある
	//					コンテナの個数  <- の中にあるコンテナの個数
	//List10-10
	vector<vector<Date*> >   array(line, vector<Date*>(col));

	//List10-11
	vector<vector<Twin<int>* > >   array_twin;

	//行分ループ処理
	for(int i=0; i < line; i++) {
		//列分ループ処理
		for(int j=0; j <  col; j++) {

			 array[i][j] = &now_time;	//オブジェクト本体はNG　ポインタを代入する　Vectorがポインタ配列だから
		}
	}
	cout << "日付クラス\n";

	//行分ループ処理
	for(int i=0; i < line; i++) {
		//列分ループ処理
		for(int j=0; j < col; j++) {

			//各配列に今日の日付が代入されていることになる
			cout << "[" << i << "][" << j << "] = " << *array[i][j] << "\n";
		}
	}

	cout << line << "行分の配列の列数を決めてください\n";

	for(int i=0; i < line; i++) {

		cout << i << "行目の列数 : ";
		cin >> set_col;

		array_twin.push_back(vector<Twin<int>* >(set_col));
	}

	Twin<int> tmp(10,100);		//オブジェクトを添字で初期化

	//行分ループ処理
	for(int i=0; i < line; i++) {

		int len = array_twin[i].size();
		//列分ループ処理
		for(int j=0; j < len; j++) {

			array_twin[i][j] = &tmp;	//オブジェクト本体はNG　ポインタを代入する　Vectorがポインタ配列だから
		}
	}

	//行分ループ処理
	for(int i=0; i < line; i++) {

		int len = array_twin[i].size();
		//列分ループ処理
		for(int j=0; j < len; j++) {

			cout << "[" << i << "][" << j << "] = " << *array_twin[i][j] << "\n";
		}
	}

	return 0;
}
