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

//関数の宣言 func.cppに順にまとめます
void out_put(unsigned);

int main()
{
	unsigned tmp = 40;				//32個 0 1 の羅列を表現できる変数

	//基準となる10進数の数字の表示
	cout << "10進数 : " << tmp;

	//宣言 2進数 bitを表示します
	cout << " 2進数 : ";

	//関数呼び出し 整数のbitを表示します
	out_put(tmp);

	//左シフトで 乗算になります
	cout << "\n左シフト\n";

	tmp <<= 1;		//2倍になります

	//基準となる10進数の数字の表示
	cout << "10進数 : " << tmp;

	//宣言 2進数 bitを表示します
	cout << " 2進数 : ";

	//関数呼び出し 整数のbitを表示します
	out_put(tmp);

	//右シフトで 徐算になります
	cout << "\n右シフト\n";

	tmp >>= 2;		//1 / 4になります

	//基準となる10進数の数字の表示
	cout << "10進数 : " << tmp;

	//宣言 2進数 bitを表示します
	cout << " 2進数 : ";

	//関数呼び出し 整数のbitを表示します
	out_put(tmp);

	return 0;
}

//関数 整数の中の '1' であるbitを検出します
//仮引数 bit 数を検出したい整数
//返却値 せの整数に '1' がある個数

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
