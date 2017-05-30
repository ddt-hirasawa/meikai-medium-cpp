/*
演習9-11 キュークラス群とその利用例を作成せよ

作成日 2017年5月30日

作成者 平澤敬介
*/

#ifndef LIST_QUEUE_H_
#define LIST_QUEUE_H_

#include<utility>
#include<algorithm>
#include<cstdlib>
#include<limits>
#include"class.h"

//線形リストによるキュークラス
template<class Type>
class ListQueue : public Queue<Type> {

	template <class Queue>

	class Node {

		friend class ListQueue<Type>;	//
		Type* data_queue;				//キューのデータ
		Node* next_queue;				//キューの後続ポインタ

	public:

		//コンストラクタ
		Node(Type* data_queue_ , Node* next_queue_) :

			//データと後続ポインタを初期化
			data_queue(data_queue_),next_queue(next_queue_) {
		}
	};

	Node<Type>* top_node;		//先頭ノードへのポインタ
	Node<Type>* dummy_node;		//ダミーノードへのポインタ

public:

	//コンストラクタ
	ListQueue()
	{
		top_node = dummy_node = new Node<Type>(NULL, NULL);		//先頭、ダミーノードをNULLで初期化
	}

	//デストラクタ
	~ListQueue(){

		Node<Type>* ptr = top_node;		//先頭ノードへのポインタを生成

		//先頭とダミーノードが異なる限り続く
		while(top_node != dummy_node) {

			//ポインタで指す領域を解放
			delete ptr->data_queue;
			//生成したポインタを破棄
			delete ptr;

		}

		//ダミーノードを破棄
		delete dummy_node;
	}

	//プッシュ
	void push(const Type& tmp){

		Node<Type>* ptr = top_node;		//先頭ノードへのポインタを生成

		//例外を拾うため try
		try{

			top_node = new Node<Type>(new Type(tmp), ptr);	//先頭ノードから領域を確保

		//領域を確保しそこなったら例外
		} catch (const std::bad_alloc& ) {

			//例外クラス生成
			throw Queue<int>::OverFlow();
		}
	}

	//ポップ
	Type& pop() {

		//先頭ノードがダミーノードと同じ場合
		if(top_node == dummy_node) {

			//例外クラス生成
			throw Queue<int>::Empty();

		} else {

			Node<Type>* ptr = top_node->next_queue;

			Type temp = *(top_node->data_queue);	//キューのデータを取り出す

			delete top_node->data_queue;			//先頭ノードが指すデータを破棄
			delete top_node;						//先頭ノードを破棄

			top_node = ptr;

			return temp;							//値を取り出す
		}
	}
};



#endif /* LIST_QUEUE_H_ */
