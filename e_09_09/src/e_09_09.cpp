/*
演習9-9 スタッククラステンプレートにメンバ関数を追加せよ

作成日 2017年5月29日

作成者 平澤敬介
*/

#include<iostream>
#include<string>
#include"SimpleStack.h"

using namespace std;

int main()
{
	string tmp;				//文字列で模擬テスト

	//宣言文字列入力
	cout << "文字列 : ";
	cin >> tmp;

	//スタッククラスオブジェクト生成
	SimpleStack<char> stack(tmp.length());

	//SimpleStack<char> stack(1);		//スタックは 1 なので 2文字以上入力するとオーバーフローオーバーフロー

	//これ以降、例外が発生する可能性がある
	try {

		int len = tmp.length();			//入力された文字列の長さを格納

		//文字列分プッシュする
		for(int i=0; i < len; i++) {

			stack.push(tmp[i]);
		}

		char answer = stack.peek() ;	//文字として受けます
		int max		= stack.capacity();	//文字数を返却する

		cout << "スタックは " << (stack.is_full() ?( "満杯です\n" ): ("満杯ではありません\n"));
		cout << "スタックは " << (stack.is_empty() ? ("空です\n" ) : ("空ではありません\n"));

		cout << "頂上のデータ : " << answer << "\n";
		cout << "スタック容量 : " << max << "\n";


		//文字列分ポップする
		for(int i=0; i < len; i++) {

			char tmp_c = stack.pop();	//文字列で入力されたので1文字ずつ返すため char型

			//1文字ずつ表示
			cout << tmp_c;
		}

		cout << "\nポップ後\n";

		cout << "スタックは " << (stack.is_full() ?( "満杯です\n" ): ("満杯ではありません\n"));
		cout << "スタックは " << (stack.is_empty() ? ("空です\n" ) : ("空ではありません\n"));
	}
	//例外発生 満杯
	catch(const SimpleStack<char>::OverFlow&) {


		cout << "満杯のスタックにプッシュしようとしました\n";

	}
	//例外発生 空
	catch(const SimpleStack<char>::Empty&) {

		cout << "空のスタックにプッシュしようとしました\n";
	}

	return 0;
}
