/*
 演習3-12 マージソートを実現せよ

 作成日 2017年5月19日

 作成者 平澤敬介
 */

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>

using namespace std;

//関数宣言
void mergesort(void* base, size_t nmenb, size_t size,int (*compar)(const void*, const void*));
int int_result(const int* tmp1, const int* tmp2);


int main()
{
	srand(time(NULL));

	int max = 10;		//要素数を50で固定

	int array[max];			//ソートする配列を定義

	//ソート前
	cout << "ソート前\n";

	//要素数分 乱数を発生させ表示します
	for (int i = 0; i < max; i++) {

		array[i] = rand() % 100;		//0 ～ 99 の間で乱数を発生

		//配列の要素をすべて表示します
		cout << "array[" << setw(2) << i << "] = " << setw(2) << array[i] << "\n";
	}

	//マージソート呼び出し
	mergesort(&array, max, sizeof(int),reinterpret_cast<int (*)(const void*, const void*)>(int_result));

			//ソート後
	cout	<< "ソート後\n";

	//要素数分 ソート後の表示をします
	for (int i = 0; i < max; i++) {

		//配列の要素をすべて表示します
		cout << "array[" << setw(2) << i << "] = " << setw(2) << array[i] << "\n";
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

//関数 クイックソート
//仮引数 オブジェクトの先頭要素のポインタ base,オブジェクトの要素数、オブジェクトの型の大きさ size,比較関数
//返却値 無し

void mergesort(void* base, size_t nmenb, size_t size,int (*compar)(const void*, const void*)) {

	const char* ptr = reinterpret_cast<const char*>(base);//先頭要素を変更しない宣言をして char 型のポイントにする

	size_t point_l = 0;							//左カーソル
	size_t point_r = nmenb - 1;					//右カーソル
	size_t point_m = (point_l + point_r) / 2;	//中央値


	const char* left_p =  &ptr[point_l * size];			//左側の整列用にポインタを配列の先頭に設定

	const char* right_p = &ptr[point_l * size];			//左側の整列用にポインタを配列の中央に設定

	right_p = &*(ptr + point_m);						//右側のポインタのアドレスを中央に変更します

	//マージソートを実行するため 中央値を出し 配列を分割し　左側 右側をそれぞれ整列させます

	//配列の左側 のソート		先頭から中央までをソート
	qsort(const_cast<void*>(reinterpret_cast<const void*>(&left_p[point_l * size])), point_m + 1,size, compar);

	//配列の右側 のソート		中央から後尾までソート
	qsort(const_cast<void*>(reinterpret_cast<const void*>(&right_p[point_l * size])), point_r ,size, compar);

	//配列の先頭から後尾までソート
	qsort(const_cast<void*>(reinterpret_cast<const void*>(&ptr[point_l * size])), point_r ,size, compar);
}
