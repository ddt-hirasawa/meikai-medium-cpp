/*
 演習2-6 ここで学習した3つの型変換 同一ビットの型変換 長いビットへの型変換 短いビットへの型変換
 を確認できるプログラムの作成 変更前と変更後を表示せよ

 作成日 2017年5月16日

 作成者 平澤敬介
 */

#include<iostream>
#include<math.h>

using namespace std;

//関数宣言
template<class Type>
const char* bits_of(Type tmp);
template<class Type>
int count_bits(Type tmp);

//func.cppにまとめます
unsigned change_unsigned(char* tmp_int);
short change_short(char* tmp_int);
long long change_long_long(char* tmp_int);

char tmp_short[16];			//静的記憶域間の文字列の配列を定義します ナル文字を含め17文字入ります 	  16bit
char tmp_unsigned[32];		//静的記憶域間の文字列の配列を定義します ナル文字を含め33文字入ります 	  32bit
char tmp_int[32];			//静的記憶域間の文字列の配列を定義します ナル文字を含め33文字入ります 	  32bit
char tmp_long_long[64];		//静的記憶域間の文字列の配列を定義します ナル文字を含め65文字入ります 	  64bit

int main() {

	int tmp = 43690;	//32bitの大きさの変数を定義し、0 1 の文字列にします 4 byte = 32bit

	//宣言 int型 32 bit から unsigned型32bit に変換します
	cout << "同一bitへの変換\n";

	//32bit なので 上位16bit は空になります 43690 が 2の16乗未満です
	cout << "      int : " << bits_of(tmp) << " -> " << tmp << "\n";

	//32bit なので 上位16bit は空になります 43690 が 2の16乗未満です
	cout << " unsigned : ";

	//ビット数が変わらないので配列に格納されている上位ビットから下位ビットまで
	//コピーし表示を行います
	for (int i = 0; i <= 31; i++) {

		tmp_unsigned[i] = tmp_int[i];	//ビットが変わらないので変化しません

		cout << tmp_int[i];				//int と同じ表記になります
	}
	//関数の呼び出し unsigned型に変化させた値を表示します
	cout << " -> " << change_unsigned(tmp_int);
	//区切ります
	cout << "\n";

	//宣言 int型 32 bit から doubled型64bit に変換します
	cout << "短いbitへの変換\n";

	//32bit なので 上位16bit は空になります 43690 が 2の16乗未満です
	cout << "      int : " << bits_of(tmp) << " -> " << tmp << "\n";

	//32bit から 64 bit の変換を行います double -> 64bit
	cout << "    short :                 ";

	//ビット数が変わらないので配列に格納されている上位ビットから下位ビットまで
	//コピーし表示を行います
	for (int i = 0; i < 16; i++) {

		tmp_short[i] = tmp_int[i + 16];	//ビットが変わらないので変化しません

		cout << tmp_short[i];				//int と同じ表記になります
	}
	//関数の呼び出し unsigned型に変化させた値を表示します
	cout << " -> " << change_short(tmp_int);
	//区切ります
	cout << "\n";

	//宣言 int型 32 bit から long long型 64bit に変換します
	cout << "長いbitへの変換\n";

	//32bit なので 上位16bit は空になります 43690 が 2の16乗未満です
	cout << "      int : " << bits_of(tmp) << " -> " << tmp << "\n";

	//long long 型 64bit
	cout << "long long : ";

	//ビット数が変わらないので配列に格納されている上位ビットから下位ビットまで
	//コピーし表示を行います
	//長いビットへの変換なので 31 bit 目を確認し,1ならば 32 bit以降を 1で埋め尽くします
	if (tmp >> 31 & 1U) {
		//上位ビットをすべて変換します
		for (int i = 0; i < 32; i++) {

			tmp += pow(2,i + 32);		//ビットを1に変換するため 2の累乗を加算します

			tmp_long_long[i] = '1';		//文字列を1で埋め尽くします

			cout << tmp_long_long[i];	//64bit に変換し表記します
		}
	//長いビットへの変換なので 31 bit 目を確認し,0ならば 32 bit以降を 0で埋め尽くします
	} else {
		//上位ビットをすべて変換します
		for (int i = 0; i < 32; i++) {

			tmp_long_long[i] = '0';		//文字列を0で埋め尽くします

			cout << tmp_long_long[i];	//64bit に変換し表記します
		}
	}

	//下位ビットを変換します
	for (int i = 32; i < 64; i++) {

		tmp_long_long[i] = tmp_int[i - 32];	//ビットが変わらないので変化しません

		cout << tmp_long_long[i];			//64bit に変換し表記します
	}

	//関数の呼び出し unsigned型に変化させた値を表示します

	cout << " -> " << change_long_long(tmp_int);

	//区切ります

	cout << "\n";

	return 0;
}

//関数 符号なし整数の全ビットを 1 と 0で表した文字列 を作成し、その文字列の先頭を指すポインタを返却する
//仮引数 bit 化する整数
//返却値 そのbit化した整数の文字列の先頭のポインタ

template<class Type>
const char* bits_of(Type tmp) {

	const char* ptr;	//返却する静的記憶域間の配列のポインタ

	int max_bit = count_bits(~0U) - 1;			//整数の全ビット数を求めます 0から始まるので1つ引きます

//32bit の時
	if (sizeof(tmp) == 4) {

		//上位ビットから下位ビットまで走査し文字列の配列を 1 0 で埋め尽くします
		for (int i = max_bit; i >= 0; i--) {

			*(tmp_int + max_bit - i) = ((tmp >> i) & 1U ? '1' : '0');//整数 tmp のビットをシフトしその都度 1 0 を配列に入れます
		}

		ptr = &*(tmp_int + 0);			//静的記憶域間の配列の先頭にポインタを設定します
		//16bit の時
	} else if (sizeof(tmp) == 2) {

		//上位ビットから下位ビットまで走査し文字列の配列を 1 0 で埋め尽くします
		for (int i = max_bit; i >= 0; i--) {

			*(tmp_short + max_bit - i) = ((tmp >> i) & 1U ? '1' : '0');	//整数 tmp のビットをシフトしその都度 1 0 を配列に入れます
		}

		ptr = &*(tmp_short + 0);		//静的記憶域間の配列の先頭にポインタを設定します
		//64bit の時
	} else if (sizeof(tmp) == 8) {

		//上位ビットから下位ビットまで走査し文字列の配列を 1 0 で埋め尽くします
		for (int i = max_bit; i >= 0; i--) {

			*(tmp_long_long + max_bit - i) = ((tmp >> i) & 1U ? '1' : '0');	//整数 tmp のビットをシフトしその都度 1 0 を配列に入れます
		}

		ptr = &*(tmp_long_long + 0);		//静的記憶域間の配列の先頭にポインタを設定します

	}
//設定したポインタを返却し cout でビットを表示します
	return ptr;
}

//関数 整数の中の '1' であるbitを検出します
//仮引数 bit 数を検出したい整数
//返却値 せの整数に '1' がある個数

template<class Type>
int count_bits(Type tmp) {

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

