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
void mergesort(void* base,void* copy,size_t p_zero ,size_t nmenb,size_t size,
		int (*compar)(const void*, const void*));
int int_result(const int* tmp1, const int* tmp2);

int main() {
	srand(time(NULL));

	int max = 10;		//要素数を50で固定

	int array[max];			//ソートする配列を定義

	int copy[max];			//作業する配列を定義

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
	mergesort(&array,&copy,0 ,max - 1, sizeof(int),
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

void mergesort(void* base,void* copy,size_t p_zero ,size_t nmenb,size_t size,
		int (*compar)(const void*, const void*)) {

	char* ptr = reinterpret_cast<char*>(base);//先頭要素を変更しない宣言をして char 型のポイントにする

	char* copy_p = reinterpret_cast<char*>(copy);//先頭要素を変更しない宣言をして char 型のポイントにする

	size_t point_l = p_zero;							//左カーソル
	size_t point_r = nmenb - 1;							//右カーソル

	if(point_l >= point_r) {

		return;
	}

	size_t point_m = (point_l + point_r) / 2;			//中央値

	mergesort(const_cast<void*>(reinterpret_cast<const void*>(&ptr[point_l * size])),

			const_cast<void*>(reinterpret_cast<const void*>(&copy_p[point_l * size])),

			point_l,point_m,size,compar);

	mergesort(const_cast<void*>(reinterpret_cast<const void*>(&ptr[point_m * size])),

			const_cast<void*>(reinterpret_cast<const void*>(&copy_p[point_m * size])),

			point_m+1,point_r,size,compar);

	for(size_t i = p_zero; i <= point_m; i++ ) {

		*(copy_p + i * size) = *(ptr + i * size);
	}

	size_t j = nmenb;

	for(size_t i = point_m + 1 ; i < nmenb; i++ ) {

		*(copy_p + i * size) = *(ptr + j * size);

		j--;
	}

	size_t select_l = p_zero; /* i とj は作業領域のデーターを */
	size_t select_r = nmenb; /* k は配列の要素を指している */

	for (size_t set = p_zero; set < nmenb; set++) {

		if (compar(reinterpret_cast<const char*>(&*(copy_p + select_l * size)),

				//比較関数で拾い要素を入れ替える

						reinterpret_cast<const char*>(&*(copy_p + select_r * size))) > 0) {

			*(ptr + set * size) = *(copy_p + (select_l) * size);

			select_l++;

		} else {

			*(ptr + set * size) = *(copy_p + (select_r) * size);

			select_r--;
		}
	}
}

