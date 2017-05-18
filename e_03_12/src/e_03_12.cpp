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

	mergesort(&array, max, sizeof(int),reinterpret_cast<int (*)(const void*, const void*)>(int_result));

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

void mergesort(void* base, size_t nmenb, size_t size,
		int (*compar)(const void*, const void*)) {

	//要素数が1以上のときのみソートを行います
	if (0 < nmenb) {

		char* ptr = reinterpret_cast<char*>(base);//先頭要素を変更しない宣言をして char 型のポイントにする

		size_t point_l = 0;								//左カーソル
		size_t point_r = nmenb - 1;						//右カーソル
		size_t point_ml = (point_l + point_r) / 2;		//中央値 左用
		size_t point_mr = point_ml;						//中央値 右用

		char** array_ptr = new char*[nmenb + 1];				//前半と後半で分けた要素を個別に指します 0 -> 前半 1 -> 後半

		//前半部分
		//先頭要素の番号と中間の要素の番号が等しくなるまで継続
		for (; point_l != point_ml;) {

			int cnt = 0;			//割った回数をカウント

			do{

			point_ml /= 2;			//細分化するため、中間点を半分にし続けます

			cnt++;					//回数をカウント

			//先頭要素の 0 になるまで続けます
			}while(point_l != point_ml);
/*
			for(int i=0; i < 25 ; i++) {

				**(array_ptr + i) = ptr[i];
			}

			for(int i=25; i < 50 ; i++) {

				**(array_ptr + i) = ptr[i];
			}*/

			for(int i=0; i < 25 ; i++ )  {

				ptr[i] = **(array_ptr +i) ;
			}
		}

	}
}
