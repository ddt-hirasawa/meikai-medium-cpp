/*
 演習2-6 ここで学習した3つの型変換 同一ビットの型変換 長いビットへの型変換 短いビットへの型変換
 を確認できるプログラムの作成 変更前と変更後を表示せよ

 作成日 2017年5月16日

 作成者 平澤敬介
 */

#include<iostream>

using namespace std;

//関数 int型のbitからunsigned型の変数を作ります
//仮引数 int型のbitが格納されている文字列の配列
//返却値 int型をunsigned型に変化させた値

unsigned change_unsigned(char* tmp_int) {

	unsigned answer = 0;		//返却する unsigned型の変数を定義します 加算するので 0 で初期化

	unsigned add = 0;			//シフト演算により加算する変数

	//int型の bit が格納されている文字列を使います
	//31 -> 上位ビット 0 -> 下位ビット です
	//上位から下位ビットまで繰り返します
	for (int i = 0; i < 31; i++) {

		//仮に、今見ているbitが 1 のとき
		//1を代入します
		if (tmp_int[i] == '1') {

			add++;			//bit を 0001  の状態にする

			add <<= 31 - i;	//指定するbit 位置まで移動
		}

		answer += add;		//返却値に加算していく

		add = 0;			//次の値に備え 0 を代入
	}
	return answer;
}

//関数 int型のbitからshort型の変数を作ります
//仮引数 int型のbitが格納されている文字列の配列
//返却値 int型をshort型に変化させた値

short change_short(char* tmp_int) {

	short answer = 0;			//返却する short型の変数を定義します 加算するので 0 で初期化

	short add = 0;				//シフト演算により加算する変数

	//int型の bit が格納されている文字列を使います
	//0 -> 上位ビット 31 -> 下位ビット です
	//上位から下位ビットまで繰り返し加算します
	for (int i = 16; i < 31; i++) {

		//仮に、今見ているbitが 1 のとき
		//1を代入します
		if (tmp_int[i] == '1') {

			add++;			//bit を 0001  の状態にする

			add <<= 31 - i;	//指定するbit 位置まで移動
		}

		answer += add;		//返却値に加算していく

		add = 0;			//次の値に備え 0 を代入
	}
	return answer;
}

//関数 int型のbitからlong longt型の変数を作ります
//仮引数 int型のbitが格納されている文字列の配列
//返却値 int型をlong long型に変化させた値

long long change_long_long(char* tmp_int) {

	long long answer = 0;		//返却する long long型の変数を定義します 加算するので 0 で初期化

	long long add = 0;			//シフト演算により加算する変数

	//変更しない下位ビットの演算を行います
	//変換するのは 32bit int型なので
	//配列の 0 -> 上位ビット 31 -> が下位ビットです
	for (int i = 0; i < 32; i++) {

		//配列の文字が 1 の時
		if(tmp_int[i] == '1') {

			add++;			//bit を 0001  の状態にする

			add <<= 31 - i;	//指定するbit 位置まで移動
		}

		answer += add;		//返却値に加算していく

		add = 0;			//次の値に備え 0 を代入
	}

	//int型の最上位のbit が1の時,それ以降のbitすべてを0にします
	if(tmp_int[31] == '1') {

		for (int i = 32; i < 63; i++) {

			add++;			//bit を 0001  の状態にする

			add <<= i;		//指定するbit 位置まで移動
		}

		answer += add;		//返却値に加算していく

		add = 0;			//次の値に備え 0 を代入
	}

	return answer;
}
