/*
演習2-6 ここで学習した3つの型変換 同一ビットの型変換 長いビットへの型変換 短いビットへの型変換
を確認できるプログラムの作成 変更前と変更後を表示せよ

作成日 2017年5月16日

作成者 平澤敬介
*/

#include<iostream>

using namespace std;

//関数宣言
const char* bits_of(unsigned tmp);
int count_bits(unsigned tmp);
//func.cppにまとめます
unsigned change_unsigned(char* tmp_int);
double change_double(char* tmp_int);

char tmp_short[16];			//静的記憶域間の文字列の配列を定義します ナル文字を含め17文字入ります 	  16bit
char tmp_unsigned[32];		//静的記憶域間の文字列の配列を定義します ナル文字を含め33文字入ります 	  32bit
char tmp_int[32];			//静的記憶域間の文字列の配列を定義します ナル文字を含め33文字入ります 	  32bit
char tmp_double[64];		//静的記憶域間の文字列の配列を定義します ナル文字を含め65文字入ります     64bit

int main()
{
	int tmp = 43690;	//32bitの大きさの変数を定義し、0 1 の文字列にします 4 byte = 32bit
	short tmp1;			//基準をint の変数としてそれぞれ bitの異なる変数に変換します
	unsigned tmp2;		//short -> 16bit unsigned -> 32bit(符号無し) double -> 64bit(浮動小数点)
	double tmp3;		//この変数にビットを変化させた値を格納します


	//宣言 int型 32 bit から unsigned型32bit に変換します
	cout << "同一bitへの変換\n";

	//32bit なので 上位16bit は空になります 43690 が 2の16乗未満です
	cout << "     int : " << bits_of(tmp) << " -> " << tmp << "\n";

	//32bit なので 上位16bit は空になります 43690 が 2の16乗未満です
	cout << "unsigned : ";

	//ビット数が変わらないので配列に格納されている上位ビットから下位ビットまで
	//コピーし表示を行います
	for(int i=0; i <= 31; i++) {

		tmp_unsigned[i] = tmp_int[i];	//ビットが変わらないので変化しません

		cout << tmp_int[i];				//int と同じ表記になります
	}
	//関数の呼び出し unsigned型に変化させた値を表示します
	cout << " -> " << change_unsigned(tmp_int);
	//区切ります
	cout << "\n";

	//宣言 int型 32 bit から doubled型64bit に変換します
	cout << "長いbitへの変換\n";

	//32bit なので 上位16bit は空になります 43690 が 2の16乗未満です
	cout << "     int : " << bits_of(tmp) << " -> " << tmp << "\n";

	//32bit から 64 bit の変換を行います double -> 64bit
	cout << "  double : ";

	//ビット数が変わらないので配列に格納されている上位ビットから下位ビットまで
	//コピーし表示を行います
	for(int i=0; i <= 63; i++) {

		tmp_double[i] = tmp_int[i-31];	//ビットが変わらないので変化しません

		cout << tmp_double[i];				//int と同じ表記になります
	}
	//関数の呼び出し unsigned型に変化させた値を表示します
	cout << " -> " << change_double(tmp_int);
	//区切ります
	cout << "\n";

	return 0;
}

//関数 符号なし整数の全ビットを 1 と 0で表した文字列 を作成し、その文字列の先頭を指すポインタを返却する
//仮引数 bit 化する整数
//返却値 そのbit化した整数の文字列の先頭のポインタ

const char* bits_of(unsigned tmp) {

	int max_bit = count_bits(~0U) - 1;				//整数の全ビット数を求めます 0から始まるので1つ引きます

	//上位ビットから下位ビットまで走査し文字列の配列を 1 0 で埋め尽くします
	for(int i=max_bit; i>=0; i--) {

		*(tmp_int + max_bit-i) = ((tmp >> i) & 1U ? '1' : '0');	//整数 tmp のビットをシフトしその都度 1 0 を配列に入れます
	}

	const char* ptr = &*(tmp_int + 0) ;				//静的記憶域間の配列の先頭にポインタを設定します

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

