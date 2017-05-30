/*
演習9-11 キュークラス群とその利用例を作成せよ

作成日 2017年5月30日

作成者 平澤敬介
*/

#ifndef CLASS_H_
#define CLASS_H_

#include<utility>
#include<algorithm>
#include<cstdlib>
#include<limits>

//抽象クラステンプレート
template<class Type>
//キュー
class Queue {
public:

	//満杯スタックへのプッシュを例外
	class OverFlow {};

	//空のスタックからのプッシュを例外
	class Empty {};

	//デストラクタ
	virtual ~Queue() = 0;

	//プッシュ
	virtual void push(const Type& tmp)  = 0;

	//ポップ
	virtual Type& pop() = 0;
};

//仮想デストラクタ
template <class Type>
Queue <Type>::~Queue(){
}

#endif /* CLASS_H_ */
