/*
演習9-11 キュークラス群とその利用例を作成せよ

作成日 2017年5月30日

作成者 平澤敬介
*/

//#include <queue>
#include <iostream>
#include"class.h"
#include"List_Queue.h"
#include"Fixed_length.h"

using namespace std;

int main()
{
	Queue<int>* queue_int = new ListQueue<int>();

	int cnt = 10;			//無限ループ回避のため10回を限度にします

	while(cnt--) {

		int menu;			//プッシュ ポップの選択

		//0で終了
		cout << "プッシュ -> 1 ポップ -> 2 終了 -> 0";
		cin >> menu;

		//0が入力されたときwhileループから抜ける
		if(0 == menu) {
			break;
		}

		//スイッチ文で分岐
		switch(menu) {

		int tmp;	//pushする値を決める変数

		//プッシュ
		case 1 :

			//プッシュするデータを決定
			cout << "データ : ";
			cin >> tmp;

			try{

				//アロー演算子でクラスのメンバ関数を呼び出す
				queue_int->push(tmp);

			//例外 基底クラスのOVERFLOW
			} catch (const Queue<int>::OverFlow&) {

				//警告文
				cout << "オーバーフロー発生";

				//whileループから脱却
				break;
			}
			break;

		//ポップ
		case 2 :

			try {

				tmp = queue_int->pop();

				cout << tmp << "をポップしました\n";

			} catch (const Queue<int>::Empty&) {

				//警告文
				cout << "空です";

				break;
			}

		}
	}

	delete queue_int;

	return 0;
}
