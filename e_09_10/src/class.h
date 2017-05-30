/*
演習9-10 キューを実現するクラステンプレートの作成

作成日 2017年5月29日

作成者 平澤敬介
*/

#ifndef CLASS_H_
#define CLASS_H_

#include<utility>
#include<algorithm>
#include<cstdlib>
#include<limits>

//クラステンプレート
template<class Type>
//キュー
class Queue {

	int queue_size;			//キューの容量
	int queue_ptr;			//キューのポインタ
	Type* queue;			//キューの本体

public:

	//満杯スタックへのプッシュを例外
	class OverFlow {};

	//空のスタックからのプッシュを例外
	class Empty {};

	//明示的コンストラクタ
	explicit Queue(int queue_);

	//デストラクタ
	~Queue();

	//プッシュ
	Type& push(const Type& tmp);

	//ポップ
	Type pop();
};

#include"class_include.h"


#endif /* CLASS_H_ */
