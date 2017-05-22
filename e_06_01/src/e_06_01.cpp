/*
演習6-1 図形クラス群に直角2等辺3角形を表すクラス群を作成せよ

作成日 2017年5月22日

作成者 平澤敬介
*/

#include<iostream>
#include"class.h"

using namespace std;

const int wid = 10;		//底辺
const int hid = 10;		//高さ
const int num = 4;		//3角形の種類

int main()
{
	Triangle* array[num];						//抽象クラスではオブジェクトを生成できない

	array[0] = new Tri_left_under(wid,hid);		//左下2等辺3角形

	array[1] = new Tri_left_up(wid,hid);		//左上2等辺3角形

	array[2] = new Tri_right_under(wid,hid);	//右下2等辺3角形

	array[3] = new Tri_right_up(wid,hid);		//右上2等辺3角形


	//ポインタ配列に定義している順で表示
	for(int i=0; i < num; i++) {

		//アロー演算子により各クラスのメンバ関数を呼び出す
		array[i] -> draw();

		cout << "\n";
	}

	//領域を確保しているのでmain側からdeleteで解放
	for(int i=num; 0 >= num; i--) {

		//配列を1つずつ解放
		//定義と逆の順番で解放
		delete[] array[i];
	}

	return 0;
}
