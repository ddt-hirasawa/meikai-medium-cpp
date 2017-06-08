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
void mergesort(void* base, size_t nmenb, size_t size);
void merge(void*, void*, void*, size_t, size_t, size_t,
		int (*compar)(const void*, const void*));
int int_result(const int* tmp1, const int* tmp2);

int main() {

	srand(time(NULL));		//乱数の種を生成

	const int max = 20;		//要素数を50で固定

	int* array = new int[max];		//ソートする配列を定義

	//ソート前
	cout << "ソート前\n";

	//要素数分 乱数を発生させ表示します
	for (int i = 0; i < max; i++) {

		array[i] = rand() % 20;		//0 ～ 99 の間で乱数を発生

		//配列の要素をすべて表示します
		cout << "array[" << setw(2) << i << "] = " << setw(2) << array[i]
				<< "\n";
	}

	//マージソート呼び出し
	mergesort(array, max, sizeof(int));

	//ソート後
	cout << "ソート後\n";

	//要素数分 ソート後の表示をします
	for (int i = 0; i < max; i++) {

		//配列の要素をすべて表示します
		cout << "array[" << setw(2) << i << "] = " << setw(2) << array[i]
				<< "\n";
	}

	//確保していた領域を解放
	delete array;

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

//関数 マージソート 数値の場合
//仮引数 オブジェクトの先頭要素のポインタ base,オブジェクトの要素数、オブジェクトの型の大きさ size,比較関数
//返却値 無し

void mergesort(void* base, size_t nmenb, size_t size) {

	if (nmenb <= 1) {

		return;
	}

	size_t left_size = nmenb / 2;
	size_t right_size = nmenb - left_size;

	unsigned long* ptr = reinterpret_cast<unsigned long*>(base);//先頭要素を変更しない宣言をして 整数型のポイントにする
	unsigned long* left = new unsigned long[left_size];	//先頭要素を変更しない宣言をして 整数型のポイントにする
	unsigned long* right = new unsigned long[right_size];//先頭要素を変更しない宣言をして 整数型のポイントにする

	//左側の配列の値を作業用にコピー
	for (size_t i = 0; i < left_size; i++) {

		left[i] = ptr[i];				//左端の配列に値を代入
	}

	//右端の配列の値を作業用にコピー
	for (size_t i = left_size; i < left_size + right_size; i++) {

		right[i - left_size] = ptr[i];	//右端の配列に値を代入
	}

	// 左側配列のマージソートを再帰で行う
	mergesort(left, left_size, size);
	// 右側配列のマージソートを再帰で行う
	mergesort(right, right_size, size);
	// 分割した配列をマージする
	merge(base, left, right, left_size, right_size, size,
			reinterpret_cast<int (*)(const void*, const void*)>(int_result));

			//作業用に確保していた配列の領域を解放
	delete left	;
	delete right;
}

//関数 マージ 数値の場合
//仮引数 オブジェクトの先頭要素のポインタ base,オブジェクトの要素数、オブジェクトの型の大きさ size,比較関数
//返却値 無し

void merge(void* base_, void* left_, void* right_, size_t left_size,
		size_t right_size, size_t size,
		int (*compar)(const void*, const void*)) {

	size_t base_index = 0;		// ベース配列の添字
	size_t left_index = 0;		// 左側配列の添字
	size_t right_index = 0;		// 右側配列の添字

	unsigned long* base = reinterpret_cast<unsigned long*>(base_);//先頭要素を変更しない宣言をして 整数型のポイントにする
	unsigned long* left = reinterpret_cast<unsigned long*>(left_);//先頭要素を変更しない宣言をして 整数型のポイントにする
	unsigned long* right = reinterpret_cast<unsigned long*>(right_);//先頭要素を変更しない宣言をして 整数型のポイントにする

	// 左右の配列をどちらか全て走査するまでループする
	for (; left_index < left_size && right_index < right_size;) {

		// 左右の配列の要素を比較する、
		if (compar(&left[left_index], &right[right_index]) < 0
				|| right_index >= right_size) {

			// 左側が小さい場合、左側をベースにセットする
			base[base_index] = left[left_index];

			left_index++;	//左側の配列を進める

		} else {

			// 右側が小さい場合、左側をベースにセットする(等しい場合も含む)
			base[base_index] = right[right_index];

			right_index++;	//右側の配列を進める
		}

		base_index++;		//素の配列を進める
	}

	//左側配列が残っている間
	while (left_index < left_size) {
		// 左側をベースにセットする
		base[base_index] = left[left_index];
		// 左側配列の添字をインクリメントする
		left_index++;
		// ベースの添字をインクリメントする
		base_index++;
	}

	//右側配列が残っている間
	while (right_index < right_size) {
		// 左側をベースにセットする
		base[base_index] = right[right_index];
		// 左側配列の添字をインクリメントする
		right_index++;
		// ベースの添字をインクリメントする
		base_index++;
	}
}
