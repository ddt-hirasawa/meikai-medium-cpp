/*
演習9-9 スタッククラステンプレートにメンバ関数を追加せよ

作成日 2017年5月29日

作成者 平澤敬介
*/

#ifndef SIMPLESTACK_H_
#define SIMPLESTACK_H_

#include<utility>
#include<algorithm>
#include<iostream>
#include<cstdlib>

//簡易スタッククラス
template<class Type> class SimpleStack {

	int stack_size;			//スタックの容量
	int stack_ptr;			//スタックのポインタ
	Type* stack;			//スタックの本体

	SimpleStack(const SimpleStack<Type>&);					//コピーコンストラクタを無効化
	SimpleStack& operator = (const SimpleStack<Type>&);		//代入演算子を無効化

public:

	//満杯スタックへのプッシュを例外
	class OverFlow {};

	//空のスタックからのプッシュを例外
	class Empty {};

	//明示的コンストラクタ
	explicit SimpleStack(int stack);

	//デストラクタ
	~SimpleStack();

	//プッシュ
	Type& push(const Type& tmp);

	//ポップ
	Type pop();

	//演習課題
	Type& peek();
	int capacity();
	bool is_full();
	bool is_empty();
};

#include"SimpleStack_include.h"

#endif /* SIMPLESTACK_H_ */
