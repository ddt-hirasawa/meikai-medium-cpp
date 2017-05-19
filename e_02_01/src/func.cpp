/*
演習2-1 符号なし整数 （正の整数）を左右にシフトした値が、
2のべき乗での乗算や除算の演算結果と一致することを確認せよ

作成日 2017年5月15日

 編集日 2017年5月19日

作成者 平澤敬介
*/

#include<iostream>

using namespace std;

//関数 10進数を2進数に右シフト変換して表示します
//仮引数 整数値
//返却値 無し

void out_put(unsigned tmp) {

	//仮に、16bit までを変換対象とします
	for(int i=0; i <= 15; i++) {

		//右から左にシフトし 0 1 を表示します
		cout << (tmp >> (15 - i) & 1U ? '1' : '0');
	}
}
