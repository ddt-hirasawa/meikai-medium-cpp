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
static void mergesort(void* base,void* copy,size_t p_zero ,size_t nmenb,size_t size,
		int (*compar)(const void*, const void*));
int int_result(const int* tmp1, const int* tmp2);
namespace {

void memswap(void* tmp1, void* tmp2, size_t num);

}

int main() {

	srand(time(NULL));

	int max = 20;		//要素数を50で固定

	int array[max];			//ソートする配列を定義

	int copy[max];

	//ソート前
	cout << "ソート前\n";

	//要素数分 乱数を発生させ表示します
	for (int i = 0; i < max; i++) {

		array[i] = rand() % 20;		//0 ～ 99 の間で乱数を発生

		copy[i] = array[i];

		//配列の要素をすべて表示します
		cout << "array[" << setw(2) << i << "] = " << setw(2) << array[i] << "\n";
	}

	//マージソート呼び出し
	mergesort(&array,&copy,0 ,max-1, sizeof(int),
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

void memswap(void* tmp1, void* tmp2, size_t num)
{
	unsigned char* obj1 = reinterpret_cast<unsigned char*>(tmp1);	//変数を仮に unsigned char型のポインタに置き換える
	unsigned char* obj2 = reinterpret_cast<unsigned char*>(tmp2);	//変数を仮に unsigned char型のポインタに置き換える

	//要素数が0になるまで続く その間 ポインタは それぞれ進む
	for(; num--; obj1++,obj2++) {


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

static void mergesort(void* base,void* copy,size_t p_zero ,size_t nmenb,size_t size,
		int (*compar)(const void*, const void*)) {

	const char* ptr = reinterpret_cast<const char*>(base);//先頭要素を変更しない宣言をして char 型のポイントにする

	const char* copy_p = reinterpret_cast<const char*>(copy);//先頭要素を変更しない宣言をして char 型のポイントにする

	if(p_zero >= nmenb) {

		return;
	}

	size_t point_m = (p_zero + nmenb) / 2;			//中央値

	mergesort(const_cast<void*>(reinterpret_cast<const void*>(&ptr[p_zero * size])),

			const_cast<void*>(reinterpret_cast<const void*>(&copy_p[p_zero * size])),

			p_zero,point_m,size,compar);

	mergesort(const_cast<void*>(reinterpret_cast<const void*>(&ptr[point_m * size])),

			const_cast<void*>(reinterpret_cast<const void*>(&copy_p[point_m * size])),

			point_m+1,nmenb,size,compar);

	for(size_t i = p_zero; i < point_m; i++ ) {

		memswap(
				const_cast<void*>(reinterpret_cast<const void*>(&copy_p[i * size])),

				const_cast<void*>(reinterpret_cast<const void*>(&ptr[i * size])), size);
	}

	size_t j = nmenb;

	for(size_t i = point_m; i < nmenb; i++ ) {

		/*memswap(
				const_cast<void*>(reinterpret_cast<const void*>(&copy_p[i * size])),

				const_cast<void*>(reinterpret_cast<const void*>(&ptr[j * size])), size);*/
		j--;
	}

	size_t select_l = p_zero; /* i とj は作業領域のデーターを */
	size_t select_r = nmenb; /* k は配列の要素を指している */

	for (size_t set = p_zero; set < nmenb; set++) {

		if (compar(reinterpret_cast<const char*>(&*(copy_p + select_l * size)),

				//比較関数で拾い要素を入れ替える

						reinterpret_cast<const char*>(&*(copy_p + select_r * size))) > 0) {

			/*memswap(
					const_cast<void*>(reinterpret_cast<const void*>(&ptr[set
							* size])),

					const_cast<void*>(reinterpret_cast<const void*>(&copy_p[select_l
							* size])), size);*/

			select_l++;

		} else {

			/*memswap(
					const_cast<void*>(reinterpret_cast<const void*>(&ptr[set
							* size])),

					const_cast<void*>(reinterpret_cast<const void*>(&ptr[select_r
							* size])), size);*/

			select_r--;
		}
	}
}

