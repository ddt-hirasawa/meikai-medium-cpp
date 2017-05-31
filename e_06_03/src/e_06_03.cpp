/*
演習6-3 じゃんけん のプレーヤー を表す抽象クラスを作成せよ

作成日 2017年5月23日

作成者 平澤敬介
*/

#include<iostream>
#include"class.h"
#include"derivation.h"

using namespace std;

//関数宣言
void Hand(int tmp);

int main()
{
	int hand;			//じゃんけんの手

	//0～2に入力を制限します
	do{

	cout << "じゃんけん 開始: \n";

	cout << "グー -> 0 チョキ -> 1 パー -> 2 \n";

	cin >> hand;

	//制限内で終了
	}while(hand < 0 || 2 < hand);

	//抽象クラス
	Player* player[] = {

			new Human(hand),		//派生クラス コンストラクタで入力された値で手を出す
			new Computer(hand),		//派生クラス コンストラクタで乱数を発生させその値で手を出す
	};

	cout << "PLAYER の";

	//勝ち負けあいこを表示する
	Hand(player[0]->judg(player[1]->output_hand()));

	cout << "COM    の";

	//勝ち負けあいこを表示する
	Hand(player[1]->judg(player[0]->output_hand()));

}

//関数 じゃんけんの手で勝ち負けを表示します
//仮引数 -1 ～ 1 の整数 ２つ
//返却値 無し

void Hand(int tmp) {

	switch(tmp){

	case 0 : cout << "あいこです\n"; break;

	case 1 : cout << "勝ちです\n";	 break;

	case -1: cout << "負けです\n";
	}
}
