/*
 演習3-12 マージソート関数を作成せよ

 作成日 2017年5月18日

 作成者 平澤敬介
 */

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>

using namespace std;

//関数宣言
void mergesort(void* base, size_t nmenb, size_t size,
		int (*compar)(const void*, const void*));
int int_result(const int* tmp1, const int* tmp2);
namespace {
//マージソート用
void memswap(void* tmp1, void* tmp2, size_t num);

}

int main() {
	srand(time(NULL));

	int max = 50;		//要素数を50で固定

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

	//クイックソート呼び出し

	mergesort(&array, max, sizeof(int),
			reinterpret_cast<int (*)(const void*, const void*)>(int_result));

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

	//要素数が1以上のときのみソートを行います
	if (0 < nmenb) {

		const char* ptr = reinterpret_cast<const char*>(base);//先頭要素を変更しない宣言をして char 型のポイントにする

		size_t p_left = 0;						//左カーソル
		size_t p_right = nmenb - 1;				//右カーソル
		size_t p_med = (p_left + p_right) / 2;	//枢軸の更新値

		char** merge = new char*[nmenb * size];

		size_t cnt = 0;

		size_t p_left1 = p_left;						//左カーソル コピー
		size_t p_right1 = p_left;						//右カーソル コピー
		size_t p_med1 = p_med;							//枢軸の更新値 コピー
		size_t p_med2 = p_med;							//枢軸の更新値 コピー

		for (; p_left1 < p_med1;) {

			if (ptr[p_left1 * size] <= ptr[p_med1 * size]) {

				**(merge + cnt) = ptr[p_left1];

				p_left1++;

			} else {

				**(merge + cnt) = ptr[p_med1];

				p_med1++;
			}

			cnt++;
		}

		for (; p_med2 <= p_right1;) {

			if (ptr[p_med2 * size] <= ptr[p_med2 * size]) {

				**(merge + cnt) = ptr[p_med2];

				p_med2++;

			} else {

				**(merge + cnt) = ptr[p_right1];

				p_right1--;
			}
		}

		memswap(
				const_cast<void*>(reinterpret_cast<const void*>(&ptr[p_left
						* size])),

				const_cast<void*>(reinterpret_cast<const void*>(&ptr[p_right
						* size])), size);
	}

	//右カーソルが1以上の時
	if (0 < p_right) {

		//クイックソートの呼び出し 先頭の要素と右カーソルの指す要素　比較
		mergesort(const_cast<void*>(reinterpret_cast<const void*>(&ptr[0])),
				p_right + 1, size, compar);
	}

	//左カーソルが 要素以下を指しているとき
	else if (p_left < nmenb - 1) {

		//クイックソートの呼び出し 左カーソルの指すの要素と要素数と左カーソルの差分を指す要素
		mergesort(
				const_cast<void*>(reinterpret_cast<const void*>(&ptr[p_left
						* size])), nmenb - p_left, size, compar);
	}
}
}
