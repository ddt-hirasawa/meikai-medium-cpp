/*
 演習2-4 符号なし整数の第 pos bit ～ 第 pos + n -1 までの n このビットを
 それぞれ 1 0 反転させた値を返す関数の作成

 作成日 2017年5月15日

 作成者 平澤敬介
 */

#include<iostream>
#include<math.h>

using namespace std;

//関数 指定したbitからn個のbitを1に書き換えます
//仮引数 変換する整数 指定するbitの位置 変換する個数
//返却値 変化させた整数

unsigned set(unsigned tmp, int pos, int num) {

	//指定したbitの位置から n個分 すべて１に変換します
	for (int i = pos; i < pos + num; i++) {

		//今、見ているbitが 1 ではないのならば演算を行います
		if (!(tmp >> i & 1U)) {

			tmp += pow(2, i);	//0 に 1 を代入します 2の累乗が そのbitの 1 になる
		}
	}
	return tmp;
}

//関数 指定したbitからn個のbitを0に書き換えます
//仮引数 変換する整数 指定するbitの位置 変換する個数
//返却値 変化させた整数

unsigned reset(unsigned tmp, int pos, int num) {

	//指定したbitの位置から n個分 すべて0に変換します
	for (int i = pos; i < pos + num; i++) {

		//今、見ているbitが 0 ではないのならば演算を行います
		if (tmp >> i & 1U) {

			tmp -= pow(2, i);	//1 から 1 を引きます 2の累乗が そのbitの 1 になる
		}
	}
	return tmp;
}

//関数 指定したbitからn個のbitを 0 -> 1 に 1 -> 0 に変換します
//仮引数 変換する整数 指定するbitの位置 変換する個数
//返却値 変化させた整数

unsigned inverse(unsigned tmp, int pos, int num) {

	for (int i = pos; i < pos + num; i++) {

			//変更する部分が 0 の時の演算部分
			if (!(tmp >> i & 1U)) {

				tmp += pow(2, i);		//指定した bit の部分を 1 に書き換えます

			//変更する部分が 1 の時の演算部分
			} else if(tmp >> i & 1U){

				tmp -= pow(2, i);		//指定した bit の部分を 0 に書き換えます
			}
	}
	return tmp;
}
