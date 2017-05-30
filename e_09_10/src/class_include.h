/*
演習9-10 キューを実現するクラステンプレートの作成

作成日 2017年5月29日

作成者 平澤敬介
*/

#ifndef CLASS_INCLUDE_H_
#define CLASS_INCLUDE_H_

//明示的コンストラクタ
template <class Type>
Queue<Type>::Queue(int queue_) :

queue_size(queue_),queue_ptr(0){

	queue = new Type[queue_size];		//初期化された際領域を確保する
}

//デストラクタ
template <class Type>
Queue<Type>::~Queue() {

	delete[] queue;
}

//プッシュ
template <class Type>
Type& Queue<Type>::push(const Type& tmp)
{
	//まだ入るなら
	if(queue_size <= queue_ptr) {

		//例外クラス生成
		throw OverFlow();
	}
	//キューを返却する
	return queue[queue_ptr++] = tmp;
}

//ポップ
template <class Type>
Type Queue<Type>::pop() {

	//空っぽなら
	if(0 >= queue_ptr) {

		//例外クラス生成
		throw Empty();
	}
	//キューを返却する
	//先入れ先出しなので、キューの容量からカウント分を引き先頭を出していく
	return queue[queue_size - (queue_ptr--)];
}

#endif /* CLASS_INCLUDE_H_ */
