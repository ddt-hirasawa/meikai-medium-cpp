 /*
演習2-2 符号なし整数の全ビットを右に n bit回転した値を返す関数と左に n bit 回転した
値を返す関数をそれぞれ作成せよ

作成日 2017年5月15日

作成者 平澤敬介
*/

#include<iostream>

using namespace std;


//関数 n bit 分 左に回転した値を返却する
//仮引数 回転する整数と回すbit数
//返却値 回転したときの値

unsigned rrotate(unsigned tmp,int num) {

	//bit数分シフトします
	for(int i=0; i < num; i++) {

		//先頭のbit が 1の場合、最後尾のbitを変更します
		if( (tmp >> 31) & 1U) {

			tmp <<= 1;

			tmp >> 0 = 1;

		} else {

			tmp <<= 1;
		}
	}

	return tmp;
}

//関数 2進数を10進数に変換します
//仮引数 0 1 の羅列が入った配列
//返却値 10進数に変換した値

int out_put(unsigned* tmp) {

	int answer = 0;			//返却する10進数の値
	int ex = 1;				//2のべき乗を表現するための変数

	//仮に、16bit までを変換対象とします
	for(int i=0; i < 32; i++) {

		answer += *(tmp + i) * ex;	//返却する値は、配列の値で1の
									//部分の添字の2のべき乗を加算していく

		ex *= 2;					//2をループ毎に積算して、演算に使います
	}
	return answer;
}
