/*
演習2-1 符号なし整数 （正の整数）を左右にシフトした値が、
2のべき乗での乗算や除算の演算結果と一致することを確認せよ

作成日 2017年5月15日

作成者 平澤敬介
*/

#include<iostream>

using namespace std;


int count_bits(unsigned tmp);
int int_bits();
void print_bits(unsigned tmp,unsigned* sub);

//関数の宣言 func.cppに順にまとめます
int out_put(unsigned*);

int main()
{
	unsigned tmp;				//32個 0 1 の羅列を表現できる変数

	unsigned sub[100] = {0};	//01 の値を演算に使いたいので格納します。

	unsigned sub1[100] = {0};	//01 の値を演算に使いたいので格納します。

	unsigned sub2[100] = {0};	//01 の値を演算に使いたいので格納します。

	tmp = 100;					//仮に10進数で20とします

	//宣言 20の2進数表記
	cout << "tmp : ";

	//関数の呼び出し部分 0 1 の羅列を表示
	print_bits(tmp,sub);

	//確認のため、配列の 0 1 を並べて表記します
	for(int i=15; i >= 0; i--) {

		// 0 1 の値を表示し続ける
		cout << sub[i];
	}
	//10進数に戻した値を表示します
	cout << " 10進数 : " << out_put(sub);

	//区切ります
	cout << "\n";

	tmp <<= 1;					//左に１つbitをシフトします

	//宣言 20の2のべき乗での乗算の2進数表記
	cout << "tmp : ";

	//関数の呼び出し部分 0 1 の羅列を表示
	print_bits(tmp,sub1);

	//確認のため、配列の 0 1 を並べて表記します
	for(int i=15; i >= 0; i--) {

		// 0 1 の値を表示し続ける
		cout << sub1[i];
	}
	//10進数に戻した値を表示します
	cout << " 10進数 : " << out_put(sub1);
	//区切ります
	cout << "\n";

	tmp >>= 2;					//右に2つbitをシフトします

	//宣言 20の2のべき乗での除算の2進数表記
	cout << "tmp : ";

	//関数の呼び出し部分 0 1 の羅列を表示
	print_bits(tmp,sub2);

	//確認のため、配列の 0 1 を並べて表記します
	for(int i=15; i >= 0; i--) {

		// 0 1 の値を表示し続ける
		cout << sub2[i];
	}
	//10進数に戻した値を表示します
	cout << " 10進数 : " << out_put(sub2);
	//区切ります
	cout << "\n";

	return 0;
}

int count_bits(unsigned tmp) {

	int bits = 0;		//カウンタ bit は 0 か 1 0で初期化子カウントします

	const int one = 1;

	//右にビットを移動していき、0になるまで繰り返します
	while(tmp) {

		//ビットで 1 の部分があったとき
		if(tmp & 1U) {

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

void print_bits(unsigned tmp,unsigned* sub) {

	int max = int_bits() - 1;		//ビットの個数を変数としてもらいます。
									//-1 は 数値は 0 ～ 999 で1000通りと考えるから

	//全ビット数分走査するためループします
	for(; max >= 0; max--) {

		//表示するとき、bit で 1 を指すとき コンソールに1を表示
		sub[max] = ((tmp >> max) & 1U ? 1 : 0);
	}
}
