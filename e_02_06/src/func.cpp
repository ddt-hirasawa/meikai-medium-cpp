/*
 演習2-6 ここで学習した3つの型変換 同一ビットの型変換 長いビットへの型変換 短いビットへの型変換
 を確認できるプログラムの作成 変更前と変更後を表示せよ

 作成日 2017年5月16日

 作成者 平澤敬介
 */

#include<iostream>
#include<math.h>

using namespace std;

//関数 int型のbitからunsigned型の変数を作ります
//仮引数 int型のbitが格納されている文字列の配列
//返却値 int型をunsigned型に変化させた値

unsigned change_unsigned(char* tmp_int) {

	unsigned answer = 0;		//返却する unsigned型の変数を定義します 加算するので 0 で初期化

	//int型の bit が格納されている文字列を使います
	//31 -> 上位ビット 0 -> 下位ビット です
	//上位から下位ビットまで繰り返します
	for (int i = 0; i < 32; i++) {

		unsigned select = 0;	//bitの判別を行います

		//仮に、今見ているbitが 1 のとき
		//1を代入します
		if (tmp_int[31 - i] == '1') {

			select = 1;			//演算を行うので1の時2の累乗が加算されます
		}

		answer += pow(2, i) * select;	//bit から整数に戻します
	}
	return answer;
}

//関数 int型のbitからshort型の変数を作ります
//仮引数 int型のbitが格納されている文字列の配列
//返却値 int型をshort型に変化させた値

short change_short(char* tmp_int) {

	short answer = 0;

	//int型の bit が格納されている文字列を使います
	//31 -> 上位ビット 0 -> 下位ビット です
	//上位から下位ビットまで繰り返します
	for (int i = 0; i < 16; i++) {

		short select = 0;	//bitの判別を行います

		//仮に、今見ているbitが 1 のとき
		//1を代入します
		if (tmp_int[i + 16] == '1') {

			select = 1;			//演算を行うので1の時2の累乗が加算されます
		}

		answer += pow(2, i) * select;	//bit から整数に戻します
	}
	return answer;
}

//関数 int型のbitからlong longt型の変数を作ります
//仮引数 int型のbitが格納されている文字列の配列
//返却値 int型をlong long型に変化させた値

long long change_long_long(char* tmp_int) {

	long long answer = 0;		//返却する long long型の変数を定義します 加算するので 0 で初期化

	//int型の bit が格納されている文字列を使います
	//64 -> 上位ビット 0 -> 下位ビット です
	//下位ビット分繰り返します
	for (int i = 0; i < 32; i++) {

		long long select = 0;	//bitの判別を行います

		//仮に、今見ているbitが 1 のとき
		//1を代入します
		if (tmp_int[31 - i] == '1') {

			select = 1;			//演算を行うので1の時2の累乗が加算されます
		}

		answer += pow(2, i) * select;	//bit から整数に戻します
	}

	//長いビットへの変換のため、32番目のbitの 0 1 により値が変わります
	//32ビット目が 1 なら 上位ビットはすべて 1 で埋められ
	//32ビット目が 0 ばら 上位ビットはすべて 0 で埋められます
	if (tmp_int[31] == '1') {

		//上位ビット以降のビットを 0 から 1にすべて変換します
		for (int i = 32; i < 64; i++) {

			answer += pow(2, i);		//ビットを1に変換するため 2の累乗を加算します
		}
	}

	return answer;
}
