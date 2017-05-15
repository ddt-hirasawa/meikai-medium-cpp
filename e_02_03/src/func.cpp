/*
 演習2-3 指定したbit の値を 1 にする関数 0 にする関数 反転させる関数 をそれぞれ作成せよ

 作成日 2017年5月15日

 作成者 平澤敬介
 */

#include<iostream>
#include<math.h>

using namespace std;

//関数 指定したビットを 1 にする
//仮引数 変換する整数 1 にするビットの場所
//返却値 変換した整数

unsigned set(unsigned tmp, int pos) {

	//指定された bit の位置が 32bit いないの時書き換えを
	//行います
	if (0 <= pos && pos < 32) {

		//変更する部分が 0 の時のみ書き換えを行います
		if (!(tmp >> pos & 1U)) {

			tmp += pow(2, pos);		//指定した bit の部分を 1 に書き換えます
		}
	}
	return tmp;
}

//関数 指定したビットを 0 にする
//仮引数 変換する整数 0 にするビットの場所
//返却値 変換した整数

unsigned reset(unsigned tmp,int pos) {

	//指定された bit の位置が 32bit いないの時書き換えを
	//行います
	if (0 <= pos && pos < 32) {

		//変更する部分が 1 の時のみ書き換えを行います
		if (tmp >> pos & 1U) {

			tmp -= pow(2, pos);		//指定した bit の部分を 0 に書き換えます
		}
	}
	return tmp;
}

//関数 指定したビットの 0 1 を反転する
//仮引数 変換する整数 反転するビットの場所
//返却値 変換した整数

unsigned inverse(unsigned tmp,int pos) {

	//指定された bit の位置が 32bit いないの時書き換えを
	//行います
	if (0 <= pos && pos < 32) {

		//変更する部分が 0 の時の演算部分
		if (!(tmp >> pos & 1U)) {

			tmp += pow(2, pos);		//指定した bit の部分を 1 に書き換えます

		//変更する部分が 1 の時の演算部分
		} else {

			tmp -= pow(2, pos);		//指定した bit の部分を 0 に書き換えます
		}
	}
	return tmp;
}
