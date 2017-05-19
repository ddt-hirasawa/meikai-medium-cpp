/*
演習1-1 クラスHuman のコンストラクタを書き換え、コンストラクタ初期化子で行うように変更せよ

作成日 2017年5月15日

 編集日 2017年5月19日

作成者 平澤敬介
*/

#ifndef CLASS_H_
#define CLASS_H_

#include<string>

//クラス人間
class Human {

	std::string full_name;			//当人の名前

	float height;					//身長

	float weight;					//体重

public:

	//コンストラクタ 演習部分 コンストラクタ初期化子
	Human(std::string name,float height_,float weight_) :
		full_name(name),height(height_),weight(weight_)
	{
		//コンストラクタ内部 空
	}

	//ゲッタ
	std::string open_name() const {

		//自分の名前を表示します
		return full_name;
	}

	//ゲッタ
	float open_height() const {

		//自分の身長を表示します
		return height;
	}

	//ゲッタ
	float open_weight() const {

		//自分の身長を表示します
		return weight;
	}
};



#endif /* CLASS_H_ */
