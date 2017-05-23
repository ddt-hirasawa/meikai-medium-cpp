/*
演習7-4 3次元クラス を抽象基底クラスとして定義し、継承するクラスを定義せよ

作成日 2017年5月23日

作成者 平澤敬介
*/

#ifndef THREE_H_
#define THREE_H_

//3次元クラス 抽象基底クラス
class ThreeDimensional {

public:

	//純粋仮想デストラクタ
	virtual ~ThreeDimensional() = 0;

	//純粋仮想関数 体積を求める関数
	virtual double get_region() const = 0;

};

//純粋仮想デストラクタ
inline ThreeDimensional::~ThreeDimensional() {
}

#endif /* THREE_H_ */
