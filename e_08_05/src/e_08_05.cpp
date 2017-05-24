/*
演習8-5 数値演算例外クラス に what 関数を追加せよ

作成日 2017年5月24日

作成者 平澤敬介
*/

#include<iostream>
#include"class.h"

using namespace std;

//関数宣言
int check(int);
int add(int,int);
int sub(int,int);
int mul(int,int);
int div(int,int);

int main()
{
	int test1 = 10 , test2 = 10;		//関数に代入する変数を定義します

	//演算する変数の値を表示
	cout << "test1 : " << test1 << "\n";
	cout << "test2 : " << test2 << "\n";

	//例外の検出を確認します
	try {

		//それぞれの演算結果の表示
		cout << "加算結果 : " << add(test1,test2) << "\n";
		cout << "減算結果 : " << sub(test1,test2) << "\n";
		cout << "乗算結果 : " << div(test1,test2) << "\n";
		cout << "除算結果 : " << mul(test1,test2) << "\n";

	//除算で0を使った場合、演算が止まらなくなってしまうことがある
	} catch(const DividedByZero& tmp) {

		cout << "0による除算が発生\n";
		tmp.display();
		cout << tmp.what();

	//ひとまとめにしてあるがメンバ関数の呼び出しでは該当する例外を表示する
	} catch(const OverFlow& tmp) {

		cout << "0による演算以外が発生\n";
		tmp.display();
		cout << tmp.what();

	//演算でこれまでにあげた以外のまずい内容を例外とします
	} catch(const UnderFlow& tmp) {

		cout << "0による演算以外が発生\n";
		tmp.display();
		cout << tmp.what();

	}


	return 0;
}

//関数 引数として与えられた値を判別し、0以下99以上の時を例外とする
//仮引数 整数1つ
//返却値 例外がない場合、引数として与えた値

int check(int tmp) {

	//0以下の場合を検出します
	if(tmp < 0) {

		//UnderFlowクラスのオブジェクトを生成しthrowで投げる
		throw UnderFlow(tmp);

	//99以上の場合を検出します
	} else if(100 <= tmp) {

		//OverFlowクラスのオブジェクトを生成しthrowで投げる
		throw OverFlow(tmp);
	}
	return tmp;
}
//関数 引数同士の加算を行う しかし、check関数を通過する条件がある
//仮引数 整数 2つ
//返却値 演算後の整数 しかし、例外が発生する可能性がある

int add(int x,int y) {

	return check(x + y);
}
//関数 引数同士の減算を行う しかし、check関数を通過する条件がある
//仮引数 整数 2つ
//返却値 演算後の整数 しかし、例外が発生する可能性がある

int sub(int x,int y) {

	return check(x - y);
}
//関数 引数同士の除算を行う しかし、check関数を通過する条件がある
//仮引数 整数 2つ
//返却値 演算後の整数 しかし、例外が発生する可能性がある

int mul(int x,int y) {

	//除算のみ、引数のどちらかが0であれば例外
	if(x <= 0 || y <= 0) {

		//除算の例外を投げます
		throw DividedByZero();
	}

	return check(x / y);
}
//関数 引数同士の乗算を行う しかし、check関数を通過する条件がある
//仮引数 整数 2つ
//返却値 演算後の整数 しかし、例外が発生する可能性がある

int div(int x,int y) {

	return check(x * y);
}
