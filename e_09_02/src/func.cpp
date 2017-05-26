/*
演習9-2 1-2でのDateクラスをテンプレート化せよ

作成日 2017年5月25日

作成者 平澤敬介
*/

#include<utility>
#include<algorithm>
#include<iostream>
#include<sstream>
#include"date.h"

using namespace std;

//抽出子 日付を入力しデータメンバに加えます
template <class Type>
istream& operator >>(istream& stream, Type& tmp) {

	//西暦を補正して入力を行います
	do {

		//宣言 1900年～2100年の範囲
		//データメンバ year を入力します
		stream >> tmp.year;

		//範囲外の場合、do文の初めに戻り最初からやり直します
	} while (tmp.year > 1900 && 2100 < tmp.year);

	//宣言 1月～12月の範囲
	do {
		//データメンバ month を入力します
		stream >> tmp.month;

		//範囲外の場合、do文の初めに戻り最初からやり直します
	} while (tmp.month > 1 && 12 < tmp.month);

	int max_day = dmax[tmp.month - 1];		//ヘッダで定義している月ごとの末日
											//を格納している配列を使います

	//2月はうるう年で影響があるため処理を行います
	if (tmp.month == 2) {

		//式により、うるう年の時 true が返却されるので
		if (tmp.leap_year(tmp.year)) {

			max_day++;						//1日長くなります
		}

	}
	//宣言 1日～その月の末尾までの範囲
	do {
		//データメンバ day を入力します
		stream >> tmp.day;

	//範囲外の場合、do文の初めに戻り最初からやり直します
	} while (tmp.day > 1 && max_day < tmp.day);

	return stream;
}

