/*
演習2-5 符号なし整数の全ビットを 1 と 0で表した文字列 を作成し、その文字列の先頭を
指すポインタを返却する関数の作成

作成日 2017年5月15日

作成者 平澤敬介
*/

#include<iostream>

using namespace std;

//関数宣言
const char* bits_of(unsigned tmp);
int count_bits(unsigned tmp);

char tmp_[32];		//静的記憶域間の文字列の配列を定義します ナル文字を含め33文字入ります

int main()
{
	unsigned tmp = 43690;	//32bitの大きさの変数を定義し、0 1 の文字列にします

	//32bit なので 上位16bit は空になります 43690 が 2の16乗未満です
	cout << tmp << " ->  bit : " << bits_of(tmp);

	return 0;
}

//関数 符号なし整数の全ビットを 1 と 0で表した文字列 を作成し、その文字列の先頭を指すポインタを返却する
//仮引数 bit 化する整数
//返却値 そのbit化した整数の文字列の先頭のポインタ

const char* bits_of(unsigned tmp) {

	int max_bit = count_bits(~0U) - 1;				//整数の全ビット数を求めます 0から始まるので1つ引きます

	//上位ビットから下位ビットまで走査し文字列の配列を 1 0 で埋め尽くします
	for(int i=max_bit; i>=0; i--) {

		*(tmp_+max_bit-i) = ((tmp >> i) & 1U ? '1' : '0');	//整数 tmp のビットをシフトしその都度 1 0 を配列に入れます
	}

	const char* ptr = &*(tmp_ + 0) ;				//静的記憶域間の配列の先頭にポインタを設定します

	//設定したポインタを返却し cout でビットを表示します
	return ptr;
}

//関数 整数の中の '1' であるbitを検出します
//仮引数 bit 数を検出したい整数
//返却値 せの整数に '1' がある個数

int count_bits(unsigned tmp) {

	int bits = 0;		//カウンタ bit は 0 か 1 0で初期化子カウントします

	const int one = 1;	//1つシフトします 右に左に

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

