/*
演習11-1 本文で学習していないstringクラスのメンバ関数を利用したプログラムの作成

作成日 2017年5月30日

作成者 平澤敬介
*/

#include<iostream>
#include<string>

using namespace std;

int main()
{
	string name = "hirasawa_keisuke";		//仮に自分の名前でメンバ関数のテスト

	//メンバ関数 文字数の返却
	cout << "文字数           : " << name.size() << "\n";

	//メンバ関数 最大文字のサイズを返却
	cout << "最大文字のサイズ : " << name.max_size() << "\n";

	//メンバ関数 文字列のサイズを変更する
	//文字数が満たない場合 a で埋め尽くす
	name.resize(20,'a');
	cout << "サイズの変更     : " << name << "\n";

	//メンバ関数 容量（サイズを変更することなく核のできる文字数）を返却する
	cout << "容量             : " << name.capacity() << "\n";

	//メンバ関数 文字列が空かどうかの判別
	cout << (!name.empty() ? "文字列は空ではありません\n" : "文字列は空です\n");

	//メンバ関数 文字列を削除する
	name.clear();
	cout << "文字列           : " << name << "\n";
	cout << (!name.empty() ? "文字列は空ではありません\n" : "文字列は空です\n");

	return 0;
}
