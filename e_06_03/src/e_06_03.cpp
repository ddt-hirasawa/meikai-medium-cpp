/*
演習6-3 じゃんけん のプレーヤー を表す抽象クラスを作成せよ

作成日 2017年5月23日

作成者 平澤敬介
*/

#include<iostream>
#include"class.h"
#include"derivation.h"

using namespace std;

int main()
{
	int hand;			//じゃんけんの手

	do{

	cout << "じゃんけん 開始: ";

	cin >> hand;

	}while(hand < 0 || 2 < hand);

	Player* player[] = {

			new Human(),
			new Computer(),
	};

	cout << player[0]->judg(hand);
}
