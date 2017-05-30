/*
演習9-11 キュークラス群とその利用例を作成せよ

作成日 2017年5月30日

作成者 平澤敬介
*/

#ifndef FIXED_LENGTH_H_
#define FIXED_LENGTH_H_

#include<utility>
#include<algorithm>
#include<cstdlib>
#include<limits>
#include"class.h"
//固定長
template <class Type> class ArrayQueue : public Queue<Type> {

	static const int size = 10;			//キューの容量 固定
	int ptr;							//キューのポインタ
	Type Queue_Body[size];				//キューの本体

public:

	//コンストラクタ
	ArrayQueue() :

		ptr(0) {
	}

	//デストラクタ
	~ArrayQueue() {
	}

	//プッシュ
	void push(const Type& tmp) {

		//キューが満杯
		if(size <= ptr) {

			//例外クラス生成
			throw Queue<Type>::OverFlow();
		}
		Queue_Body[ptr++] = tmp;	//キューに代入
	}

	//ポップ
	Type pop() {

		//キューが空
		if(ptr <= 0) {

			//例外クラス生成
			throw Queue<Type>::Empty();
		}
		return Queue_Body[size - (ptr--)];	//キューから取り出し
	}
};

#endif /* FIXED_LENGTH_H_ */
