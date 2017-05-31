/*
 演習9-9-2 スタッククラステンプレートにメンバ関数を追加せよ

 作成日 2017年5月31日

 作成者 平澤敬介
 */

#ifndef SIMPLESTACK_INCLUDE_H_
#define SIMPLESTACK_INCLUDE_H_

//明示的コンストラクタ
template <class Type>
SimpleStack<Type>::SimpleStack(int stack_) :

stack_size(stack_),stack_ptr(0){

	stack = new Type[stack_size];		//初期化された際領域を確保する
}

//デストラクタ
template <class Type>
SimpleStack<Type>::~SimpleStack() {

	delete[] stack;
}

//プッシュ
template <class Type>
Type& SimpleStack<Type>::push(const Type& tmp)
{
	//まだ入るなら
	if(stack_size <= stack_ptr) {

		//例外クラス生成
		throw OverFlow();
	}
	//スタックを返却する
	return stack[stack_ptr++] = tmp;
}

//ポップ
template <class Type>
Type SimpleStack<Type>::pop() {

	//stack_ptr--;		//プッシュの際、カウントしているのでポップの時1つ減っていれば空のスタックにポップすることになる

	//空っぽなら
	if(0 >= stack_ptr) {

		//例外クラス生成
		throw Empty();
	}
	//スタックを返却する
	return stack[--stack_ptr];
}

//演習 頂上のデータを削除することなく返却するメンバ関数
template <class Type>
Type& SimpleStack<Type>::peek()
{
	//* stack で底のデータなので
	//真逆のデータを返却
	return *(stack + stack_size - 1);
}

//演習 スタックの容量を返却するメンバ関数
template <class Type>
int SimpleStack<Type>::capacity() {

	//データメンバのスタックの容量を返却
	return stack_size;
}

//演習 スタックが満杯かどうかを返却するメンバ関数
template <class Type>
bool SimpleStack<Type>::is_full() {

	bool answer = false;		//デフォルトは空

	//スタックの容量と同じか超えていれば
	if(stack_size <= stack_ptr) {

		answer = true;			//満杯 -> trueを代入
	}

	//呼び出されたとき判断せれ返却する
	return answer;
}

//演習 空が満杯かどうかを返却するメンバ関数
template <class Type>
bool SimpleStack<Type>::is_empty() {

	bool answer = true;		//デフォルトは空

	//スタックの容量と同じか超えていれば
	if(stack_size <= stack_ptr) {

		answer = false;			//満杯 -> trueを代入
	}

	//呼び出されたとき判断せれ返却する
	return answer;
}

#endif /* SIMPLESTACK_INCLUDE_H_ */
