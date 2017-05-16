/*
演習2-3 指定したbit の値を 1 にする関数 0 にする関数 反転させる関数 をそれぞれ作成せよ

作成日 2017年5月15日

作成者 平澤敬介
*/

#include<iostream>

using namespace std;
//関数宣言
int count_bits(unsigned tmp);
int int_bits();
void print_bits(unsigned tmp, unsigned* sub);
int out_put(unsigned* tmp);
//演習で指示されている関数 func.cpp にまとめます
unsigned set(unsigned tmp,int pos);
unsigned reset(unsigned tmp,int pos);
unsigned inverse(unsigned tmp,int pos);

int main()
{
	unsigned tmp = 100;			//仮の数字 この数字の bit をいじります
	unsigned tmp1;				//関数 set の値を補完します
	unsigned tmp2;				//関数 reset の値を補完します
	unsigned tmp3;				//関数 inverse の値を補完します

	unsigned sub1[32] = {0};	//bit を10進数に変換するための配列
	unsigned sub2[32] = {0};	//bit を10進数に変換するための配列 関数 set の値を補完します
	unsigned sub3[32] = {0};	//bit を10進数に変換するための配列 関数 reset の値を補完します
	unsigned sub4[32] = {0};	//bit を10進数に変換するための配列 関数 inverse の値を補完します

	//宣言 2進数表記
	cout << " tmp : ";

	//関数の呼び出し部分 0 1 の羅列を表示
	print_bits(tmp, sub1);

	//確認のため、配列の 0 1 を並べて表記します
	for (int i = 31; i >= 0; i--) {

		// 0 1 の値を表示し続ける
		cout << sub1[i];
	}
	//10進数に戻した値を表示します
	cout << " 10進数 : " << out_put(sub1);

	//区切ります
	cout << "\n";

	tmp1 = set(tmp,2);

	//宣言 2進数表記
	cout << "tmp1 : ";

	//関数の呼び出し部分 0 1 の羅列を表示
	print_bits(tmp1, sub2);

	//確認のため、配列の 0 1 を並べて表記します
	for (int i = 31; i >= 0; i--) {

		// 0 1 の値を表示し続ける
		cout << sub2[i];
	}
	//10進数に戻した値を表示します
	cout << " 10進数 : " << out_put(sub2);

	//区切ります
	cout << "\n";

	tmp2 = reset(tmp,2);

	//宣言 2進数表記
	cout << "tmp2 : ";

	//関数の呼び出し部分 0 1 の羅列を表示
	print_bits(tmp2, sub3);

	//確認のため、配列の 0 1 を並べて表記します
	for (int i = 31; i >= 0; i--) {

		// 0 1 の値を表示し続ける
		cout << sub3[i];
	}
	//10進数に戻した値を表示します
	cout << " 10進数 : " << out_put(sub3);

	//区切ります
	cout << "\n";

	tmp3 = inverse(tmp,2);

	//宣言 2進数表記
	cout << "tmp3 : ";

	//関数の呼び出し部分 0 1 の羅列を表示
	print_bits(tmp3, sub4);

	//確認のため、配列の 0 1 を並べて表記します
	for (int i = 31; i >= 0; i--) {

		// 0 1 の値を表示し続ける
		cout << sub4[i];
	}
	//10進数に戻した値を表示します
	cout << " 10進数 : " << out_put(sub4);

	//区切ります
	cout << "\n";

	return 0;
}

//関数 整数の中の '1' であるbitを検出します
//仮引数 bit 数を検出したい整数
//返却値 せの整数に '1' がある個数

int count_bits(unsigned tmp) {

	int bits = 0;		//カウンタ bit は 0 か 1 0で初期化子カウントします

	const int one = 1;

	//右にビットを移動していき、0になるまで繰り返します
	while (tmp) {

		//ビットで 1 の部分があったとき
		if (tmp & 1U) {

			// 1 がありました。カウントします
			bits++;
		}

		//tmp のbit を右に1つずらします
		tmp >>= one;
	}
	//カウントしたbit数を返却します
	return bits;
}


//関数 int 型のビット数を表示します 整数の中の 0 と 1 の個数
//仮引数 無し
//返却値 整数のすべてのビット数

int int_bits() {

	return count_bits(~0U);
}


//関数 整数 tmp のbit構成を表示
//仮引数 調べたい整数 tmp
//返却値 無し

void print_bits(unsigned tmp, unsigned* sub) {

	int max = int_bits() - 1;		//ビットの個数を変数としてもらいます。
									//-1 は 数値は 0 ～ 999 で1000通りと考えるから

	//全ビット数分走査するためループします
	for (; max >= 0; max--) {

		//表示するとき、bit で 1 を指すとき コンソールに1を表示
		sub[max] = ((tmp >> max) & 1U ? 1 : 0);
	}
}

//関数 2進数を10進数に変換します
//仮引数 0 1 の羅列が入った配列
//返却値 10進数に変換した値

int out_put(unsigned* tmp) {

	int answer = 0;			//返却する10進数の値
	int ex = 1;				//2のべき乗を表現するための変数

//仮に、16bit までを変換対象とします
	for (int i = 0; i < 32; i++) {

		answer += *(tmp + i) * ex;	//返却する値は、配列の値で1の
									//部分の添字の2のべき乗を加算していく

		ex *= 2;					//2をループ毎に積算して、演算に使います
	}
	return answer;
}
