/*
演習6-3 じゃんけん のプレーヤー を表す抽象クラスを作成せよ

作成日 2017年5月23日

作成者 平澤敬介
*/

#ifndef CLASS_H_
#define CLASS_H_

#include<iostream>

//じゃんけんの抽象クラス
class Player{

public:

	//純粋仮想デストラクタ
	virtual ~Player() = 0;

	//純粋仮想関数
	//じゃんけんの手をmain内に返却し勝ち負けを判断する
	//返却値 データメンバじゃんけんの手
	virtual int output_hand() const = 0;

	//純粋仮想関数
	//じゃんけんの勝ち負けを判定する
	//返却値 勝ち負け引き分けをそれぞれ 1 -1 0 で返却
	virtual int judg(int tmp) const = 0;

};

//純粋仮想デストラクタ
inline Player::~Player() {

}

#endif /* CLASS_H_ */
