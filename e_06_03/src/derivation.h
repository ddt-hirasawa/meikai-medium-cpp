/*
 演習6-3 じゃんけん のプレーヤー を表す抽象クラスを作成せよ

 作成日 2017年5月23日

 作成者 平澤敬介
 */

#ifndef DERIVATION_H_
#define DERIVATION_H_

#include<iostream>
#include<cstdlib>
#include<ctime>
#include"class.h"

//基底クラス 原点
class Origin : public Player {
public:

	int hand;			//じゃんけんの手

	//コンストラクタ
	Origin(int hand_) :
		hand(hand_)
	{
	}

	//メンバ関数
	//じゃんけんの手をmain内に返却し勝ち負けを判断する
	//返却値 データメンバじゃんけんの手
	int output_hand() const{

		return hand;
	}

	//メンバ関数 プレイヤーの勝ち負けを判定
	//仮引数 相手の手
	//返却値 勝ち負け引き分けを 1 -1 0で返却

	int judg(int tmp) const {

		int answer;

		//あいこの場合
		if (tmp == hand) {

			answer = 0;			//あいこ -> 0 を代入
		//あいこ以外の時
		} else {

			switch (hand) {

			//こちらがグーの時、相手がチョキなら
			case 0:
				if (tmp == 1) {

					answer = 1;		//勝ち -> 1 を代入

				} else {

					answer = -1;	//負け -> -1 を代入
				}
				break;

				//こちらがチョキの時、相手がパーなら
			case 1:
				if (tmp == 2) {

					answer = 1;		//勝ち -> 1 を代入

				} else {

					answer = -1;	//負け -> -1 を代入
				}
				break;

				//こちらがパーの時、相手がグーなら
			case 2:
				if (tmp == 0) {

					answer = 1;		//勝ち -> 1 を代入

				} else {

					answer = -1;	//負け -> -1 を代入
				}
				break;

			}
		}

		return answer;
	}

};

//クラス 人間
class Human: public Origin {

public:

	//デフォルトコンストラクタ 最初はグー
	Human() :
			Origin(0) {

		std::cout << "最初はグー\n";
	}

	//コンストラクタ//
	Human(int hand_) :

			Origin(hand_) {

		//クラスオブジェクトが生成されたとき
		//自分の手を表示します
		switch (hand) {

		case 0:
			std::cout << "プレイヤー : グー\n";
			break;

		case 1:
			std::cout << "プレイヤー : チョキ\n";
			break;

		case 2:
			std::cout << "プレイヤー : パー\n";
			break;
		}
	}
};

//クラス コンピュータ
class Computer: public Origin {

public:

	//デフォルトコンストラクタ 最初はグー
	Computer() :
			Origin(0){

		std::cout << "じゃんけん\n";
	}

	//コンストラクタ//
	Computer(int cpu) :

		Origin(0)
	{

		srand(time(NULL));

		hand = rand() % 3;

		//クラスオブジェクトが生成されたとき
		//自分の手を表示します
		switch (hand) {

		case 0:
			std::cout << "COM        : グー\n";
			break;

		case 1:
			std::cout << "COM        : チョキ\n";
			break;

		case 2:
			std::cout << "COM        : パー\n";
			break;

		}
	}
};

#endif /* DERIVATION_H_ */
