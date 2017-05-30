/*
演習9-10 キューを実現するクラステンプレートの作成

作成日 2017年5月29日

作成者 平澤敬介
*/

//#include <queue>
#include <iostream>
#include"class.h"

using namespace std;

int main()
{
	try {

		Queue<int> queue(10);		//キュー int型で箱10個

		//キューに添え字 0 ～ 9 を順にプッシュしていく
		for(int i=0; i< 10; i++) {

			//プッシュする値を表示
			cout << i << "をプッシュします\n";

			queue.push(i);			//添え字をプッシュ
		}

		cout << "\n";				//プッシュとポップを区切ります

		//キューからポップしていきます
		for(int i=0; i< 11; i++) {

			//先入れ先出しなので入れた順位出てきます
			cout << queue.pop() << "をポップします\n";
		}

	}
	//例外発生 満杯
	catch(const Queue<int>::OverFlow&) {


		cout << "満杯のキューにプッシュしようとしました\n";

	}
	//例外発生 空
	catch(const Queue<int>::Empty&) {

		cout << "空のキューからポップしようとしました\n";
	}


	return 0;
}
