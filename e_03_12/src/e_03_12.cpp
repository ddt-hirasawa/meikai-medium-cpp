/*
 演習3-12 マージソートを実現せよ

 作成日 2017年5月19日

 作成者 平澤敬介
 */

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<iomanip>

using namespace std;

//関数宣言
void mergesort(void* base, size_t nmenb, size_t size,
		int (*compar)(const void*, const void*));
void merge1(void* base, size_t nmenb, size_t size,
		int (*compar)(const void*, const void*));
int int_result(const int* tmp1, const int* tmp2);

namespace {

void memswap(void* tmp1, void* tmp2, size_t num);

}

int main() {
	srand(time(NULL));

	int max = 20;		//要素数を50で固定

	int array[max];			//ソートする配列を定義

	//ソート前
	cout << "ソート前\n";

	//要素数分 乱数を発生させ表示します
	for (int i = 0; i < max; i++) {

		array[i] = rand() % 100;		//0 ～ 99 の間で乱数を発生

		//配列の要素をすべて表示します
		cout << "array[" << setw(2) << i << "] = " << setw(2) << array[i]
				<< "\n";
	}

	//マージソート呼び出し
	mergesort(&array, max, sizeof(int),
			reinterpret_cast<int (*)(const void*, const void*)>(strcmp));

			//ソート後
cout	<< "ソート後\n";

	//要素数分 ソート後の表示をします
	for (int i = 0; i < max; i++) {

		//配列の要素をすべて表示します
		cout << "array[" << setw(2) << i << "] = " << setw(2) << array[i]
				<< "\n";
	}

	return 0;
}

namespace {

//入れ替え関数
//仮引数 共通のオブジェクトを指すポインタ 2つ オブジェクトの要素数
//返却値 無し

void memswap(void* tmp1, void* tmp2, size_t num) {

	unsigned char* obj1 = reinterpret_cast<unsigned char*>(tmp1);//変数を仮に unsigned char型のポインタに置き換える
	unsigned char* obj2 = reinterpret_cast<unsigned char*>(tmp2);//変数を仮に unsigned char型のポインタに置き換える

	//要素数が0になるまで続く その間 ポインタは それぞれ進む
	for (; num--; obj1++, obj2++) {

		unsigned char obj3 = *obj1;	//ポインタの仮置き場

		*obj1 = *obj2;				//obj1 と obj2を入れ替え

		*obj2 = obj3;				//obj2 に保管していた値 obj3を代入する
	}
}
}

//関数 比較関数 tmp1 tmp2 で同じかを判別して返却します
//仮引数 整数2つ
//返却値  0 -> 同じ 1

int int_result(const int* tmp1, const int* tmp2) {

	int answer = 0;		//返却値 同じ場合は 0

	//tmp1 が大きい場合
	if (*tmp2 < *tmp1) {

		answer = 1;		//1を代入し,tmp1が大きいことにする

		//tmp2 が大きい場合
	} else if (*tmp2 > *tmp1) {

		answer = -1;	//-1を代入し,tmp2が大きいことにする
	}

	//いずれにしても 1 0 -1どれかが返却される
	return answer;
}

//関数 マージソート
//仮引数 オブジェクトの先頭要素のポインタ base,オブジェクトの要素数、オブジェクトの型の大きさ size,比較関数
//返却値 無し

void mergesort(void* base, size_t nmenb, size_t size,
		int (*compar)(const void*, const void*)) {

	const char* ptr = reinterpret_cast<const char*>(base);//先頭要素を変更しない宣言をして char 型のポイントにする

	size_t point_l = 0;							//左カーソル
	size_t point_r = nmenb - 1;					//右カーソル
	size_t point_m = (point_l + point_r) / 2;	//中央値

	const char* left_p = &ptr[point_l * size];			//左側の整列用にポインタを配列の先頭に設定

	const char* right_p = &ptr[point_l * size];			//左側の整列用にポインタを配列の中央に設定

	right_p = &*(ptr + point_m);						//右側のポインタのアドレスを中央に変更します

	//マージソートを実行するため 中央値を出し 配列を分割し　左側 右側をそれぞれ整列させます

	//配列の左側 のソート		先頭から中央までをソート
	merge1(
			const_cast<void*>(reinterpret_cast<const void*>(&left_p[point_l
					* size])), point_m, size, compar);

}

//関数マージ
//
//

void merge1(void* base, size_t nmenb, size_t size,
		int (*compar)(const void*, const void*)) {

	char* ptr = reinterpret_cast<char*>(base);//変更するのでconstを外します char 型のポイントにする

	//配列の先頭から任意の位置までポインタで個別にさせるのでバラバラになっていると言える

	size_t point_l = 0;					//左カーソル		任意の位置 配列の先頭もしくは中間

	size_t point_r = nmenb;				//右カーソル		任意の位置 配列の中間もしくは終端

	char* copy = new char[(nmenb + 1) * size];				//与えられる配列をそのままコピー

	//左カーソルが右カーソルに追いついたら終了 それまでは繰り返し
	//最初のマージなので要素を1つずつ比較しマージ
	for (; point_l < point_r; point_l += 2) {

		//今見ている要素の１つ後ろが大きい場合
		if (compar(reinterpret_cast<const char*>(&ptr[point_l * size]),

		//比較関数で拾い要素を入れ替える
				reinterpret_cast<const char*>(&ptr[(point_l + 1) * size]))
				> 0) {
			//入れ替え関数の呼び出し
			memswap(
			//引数 左カーソルの指す要素
					const_cast<void*>(reinterpret_cast<const void*>(&ptr[point_l
							* size])),
					//引数 左カーソルの指す要素の1つ後ろ
					const_cast<void*>(reinterpret_cast<const void*>(&ptr[(point_l
							+ 1) * size])), size);
		}

		*(copy + point_l) = *(ptr + point_l);
		*(copy + point_l + 1) = *(ptr + point_l + 1);
	}
	//マージ第一段階終了

	point_l = 0;		//左カーソルを初期値に戻す

	//左カーソルが右カーソルと同じ部分を指すまで継続
	for (; point_l < point_r; point_l++) {

		for (size_t i = 0; i < point_l; i++) {
			//仮に今左カーソルが指す値が比較して大きい場合

			if (compar(reinterpret_cast<const char*>(&copy[i * size]),

			reinterpret_cast<const char*>(&copy[point_l * size])) > 0) {

				for(size_t j = i; j < point_r; j++) {


					copy[j * size] = copy[ (j - 1) * size];
				}

				copy[i * size] = ptr[ point_l * size];


				if(compar(reinterpret_cast<const char*>(&copy[i * size]),

						reinterpret_cast<const char*>(&copy[point_l * size])) > 0) {

				merge1(const_cast<void*>(reinterpret_cast<const void*>(&copy[point_l
								* size])), point_r, size, compar);
				}
			}
		}
	}
}

