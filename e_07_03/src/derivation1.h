/*
演習7-3 左上直角2等辺3角形 右下直角2等辺3角形 を作成せよ

作成日 2017年5月23日

作成者 平澤敬介
*/

#ifndef DERIVATION1_H_
#define DERIVATION1_H_

#include<iostream>

//2次元抽象クラス
class TwoDimensional{
public:

	//純粋仮想デストラクタ
	virtual ~TwoDimensional() = 0;

	//仮想関数 図形の面積を返却する関数
	virtual double get_area() const = 0;

};
//純粋仮想デストラクタ
inline TwoDimensional::~TwoDimensional() {

	std::cout << "TWO確認\n";
}

#endif /* DERIVATION1_H_ */
