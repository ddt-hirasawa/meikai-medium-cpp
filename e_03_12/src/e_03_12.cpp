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
static void mergesort(void* base,void* copy1,void* copy2,size_t p_zero ,size_t nmenb,size_t size,
		int (*compar)(const void*, const void*));
int int_result(const int* tmp1, const int* tmp2);
namespace {

void memswap(void* tmp1, void* tmp2, size_t num);

}

int main() {

	srand(time(NULL));

	const int max = 20;		//要素数を50で固定

	int array[max];		//ソートする配列を定義

	int copy1[max / 2] = {0};
	int copy2[max / 2] = {0};

	//ソート前
	cout << "ソート前\n";

	//要素数分 乱数を発生させ表示します
	for (int i = 0; i < max; i++) {

		array[i] = rand() % 20;		//0 ～ 99 の間で乱数を発生

		//配列の要素をすべて表示します
		cout << "array[" << setw(2) << i << "] = " << setw(2) << array[i] << "\n";
	}

	//マージソート呼び出し
	mergesort(&array,&copy1,&copy2,0 ,max,sizeof(int),
			reinterpret_cast<int (*)(const void*, const void*)>(int_result));

		//ソート後
	cout	<< "ソート後\n";

	//要素数分 ソート後の表示をします
	for (int i = 0; i < max; i++) {

		//配列の要素をすべて表示します
		cout << "array[" << setw(2) << i << "] = " << setw(2) << array[i] << "\n";
	}

	for (int i = 0; i < max / 2; i++)
	cout << " copy[" << setw(2) << i << "] = " << setw(2) << copy1[i]<<"\n";

	for (int i = 0; i < max / 2; i++)
	cout << " copy[" << setw(2) << i << "] = " << setw(2) << copy2[i] << "\n";

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

		unsigned char obj3 = *obj2;	//ポインタの仮置き場

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

static void mergesort(void* base,void* copy1,void* copy2,size_t p_zero ,size_t nmenb,size_t size,
		int (*compar)(const void*, const void*)) {

	char* ptr = reinterpret_cast<char*>(base);//先頭要素を変更しない宣言をして char 型のポイントにする

	char* copy_p1 = reinterpret_cast<char*>(copy1);//先頭要素を変更しない宣言をして char 型のポイントにする
	char* copy_p2 = reinterpret_cast<char*>(copy2);//先頭要素を変更しない宣言をして char 型のポイントにする

	//再帰の折り返し部分
	if(p_zero >= nmenb) {

		//何もせずに戻る
		return;
	}

	size_t point_m = (p_zero + nmenb) / 2;			//中央値

	//再帰 中央より前
	mergesort(const_cast<void*>(reinterpret_cast<const void*>(&ptr[p_zero])),

			const_cast<void*>(reinterpret_cast<const void*>(&copy_p1[p_zero])),

			const_cast<void*>(reinterpret_cast<const void*>(&copy_p2[p_zero])),

			p_zero,point_m,size,compar);

	//再帰 中央より後ろ
	mergesort(const_cast<void*>(reinterpret_cast<const void*>(&ptr[point_m])),

			const_cast<void*>(reinterpret_cast<const void*>(&copy_p1[point_m])),

			const_cast<void*>(reinterpret_cast<const void*>(&copy_p2[point_m])),

			point_m+1,nmenb,size,compar);

	//前部分の代入部分
	/*for(size_t i = p_zero; i < point_m; i++ ) {

		if(&copy_p[i * size] != '\0' && &ptr[i * size] != '\0')
		memswap(
				const_cast<void*>(reinterpret_cast<const void*>(&copy_p[i * size])),

				const_cast<void*>(reinterpret_cast<const void*>(&ptr[i * size])), size);


	}

	/*for(size_t i = point_m; i < --j; i++) {

		if(&copy_p[i * size] != '\0' && &ptr[j * size] != '\0')
		memswap(
				const_cast<void*>(reinterpret_cast<const void*>(&copy_p[i * size])),

				const_cast<void*>(reinterpret_cast<const void*>(&ptr[j * size])), size);
	}*/

	for(size_t i = p_zero; i <= point_m * size; i++ ) {

		*(copy_p1 + i) = *(ptr + i);

		copy_p2[nmenb * size / 2 - i]  = ptr[i + point_m * size];

	}

	size_t select_l = p_zero;
	size_t select_r = nmenb;

	/*for (size_t set = p_zero; set < nmenb; set++) {

		if (compar(reinterpret_cast<const char*>(&copy_p[select_l * size]),

				//比較関数で拾い要素を入れ替える

						reinterpret_cast<const char*>(&copy_p[select_r * size])) > 0 ) {

			if(&copy_p[select_r * size] != '\0' && &copy_p[select_l * size] != '\0') {


			memswap(
					const_cast<void*>(reinterpret_cast<const void*>(&ptr[set
							* size])),

					const_cast<void*>(reinterpret_cast<const void*>(&copy_p[select_l
							* size])), size);

			select_l++;

		} else {

			memswap(
					const_cast<void*>(reinterpret_cast<const void*>(&ptr[set
							* size])),

					const_cast<void*>(reinterpret_cast<const void*>(&ptr[select_r
							* size])), size);

			select_r--;
		}


		}
	}*/

}

