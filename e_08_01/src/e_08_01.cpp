/*
 演習8-1 set_terminate 関数を使って動作の検証を行え

 作成日 2017年5月24日

 作成者 平澤敬介
 */

/*エラーメッセージ
このアプリケーションは、異常終了するようにランタイムに要求しています。
詳細については、アプリケーションのサポートチームにお問い合わせください。

と表示されました。ほかの正負の値の場合は、それぞれ例外や正常な値が入力されたことが確認できました

 0がキーボード入力されたとき、try内のif文で判断され、throwでcatchに投げられ関数内の
 abort関数によりプログラムが終了させられたことが確認できました
 */

#include<iostream>
#include<cstdlib>

using namespace std;

//関数宣言
void exception_error();

int main() {

	int test1;				//例外処理を確認するため、キーボード入力するための変数を定義

	//演習内容 動作確認のため set_terminate関数を使用
	set_terminate(exception_error);

	//キーボード入力で 0 でset_terminate関数の挙動
	cout << "整数を入力 : ";
	cin >> test1;

	//例外処理を検出します
	try {

		//仮に０が入力された場合
		if (test1 == 0) {

			//catch に受け取った例外 → 0 を例外としたので 0 を投げます
			throw;

		//0より大きい整数の場合も例外とします
		} else if(0 < test1) {

			//catch にint 型の値を投げます
			throw 1;

		//実質負の値の場合、例外はありませんでした
		} else {

			//コンソールに表示し確認します
			cout << "正常な値が入力されました\n";

		}

	//int 型の例外を投げられた場合 拾います
	} catch (int ) {

		//例外、正の整数が入力されました
		cout << "例外：正の整数が入力されました\n";
	}

	return 0;
}

//関数 例外が出てた時文字を表示して終了する
void exception_error() {

	cout << "例外関連のエラー発生\n";

	//cstdlib で定義されているプログラムを終了する関数
	abort();
}
