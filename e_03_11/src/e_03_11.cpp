/*
演習3-11 quicksort 関数を使用したプログラムの作成

作成日 2017年5月18日

作成者 平澤敬介
*/

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>


using namespace std;

//関数宣言
void quicksort(void* base,size_t nmenb,size_t size,int(*compar)(const void*,const void*));
int int_result(const int* tmp1, const int* tmp2);
namespace {

void memswap(void* tmp1, void* tmp2, size_t num);

}

int main()
{
	srand(time(NULL));

	int max = 50;		//要素数を50で固定

	int array[max];			//ソートする配列を定義

	//ソート前
	cout << "ソート前\n";

	//要素数分 乱数を発生させ表示します
	for(int i=0; i < max; i++) {

		array[i] = rand() % 100;		//0 ～ 99 の間で乱数を発生

		//配列の要素をすべて表示します
		cout << "array[" << setw(2) << i << "] = " << setw(2) << array[i] << "\n";
	}

	//クイックソート呼び出し

	quicksort(&array,max,sizeof(int),reinterpret_cast<int (*)(const void*,const void*)>(int_result));

	//ソート後
	cout << "ソート後\n";

	//要素数分 ソート後の表示をします
	for(int i=0; i < max; i++) {

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
	} else if(*tmp2 > *tmp1) {


		answer = -1;	//-1を代入し,tmp2が大きいことにする
	}

	//いずれにしても 1 0 -1どれかが返却される
	return answer;
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



//関数 クイックソート
//仮引数 オブジェクトの先頭要素のポインタ base,オブジェクトの要素数、オブジェクトの型の大きさ size,比較関数
//返却値 無し

void quicksort(void* base,size_t nmenb,size_t size,int(*compar)(const void*,const void*)) {

	//要素数が1以上のときのみソートを行います
	if (0 < nmenb) {

		const char* ptr = reinterpret_cast<const char*>(base);//先頭要素を変更しない宣言をして char 型のポイントにする

		size_t point_l = 0;						//左カーソル
		size_t point_r = nmenb - 1;				//右カーソル
		size_t point_v = nmenb;					//枢軸
		size_t point_new = (point_l + point_r) / 2;	//枢軸の更新値

			const char* ptr_v;						//枢軸へのポインタ

			//枢軸 と 枢軸の更新値 が異なる場合
			if (point_v != point_new) {

				ptr_v = &ptr[(point_v = point_new) * size];	//枢軸へのポインタはオブジェクトの 枢軸 の番号の値を指す

				//比較関数により、-1 が返却される限り続く
				while (compar(
						reinterpret_cast<const void*>(&ptr[point_l * size]),
						ptr_v) < 0) {

					point_l++;	//左カーソルを進める

				}

				//比較関数により、-1 が返却される限り続く
				while (compar(
						reinterpret_cast<const void*>(&ptr[point_r * size]),ptr_v) > 0) {

					point_r--;	//右カーソルを戻す

				}

				//左カーソルと右カーソルが同じか、右カーソルの方が進んでいるとき
				if (point_l <= point_r) {

					point_new = (point_l == point_v) ? point_r :
								(point_r == point_v) ? point_l : point_v;//枢軸の更新値は
																		 //条件式により決定する
					//名前なしの名前空間にある入れ替え関数を使います
					memswap(
							const_cast<void*>(reinterpret_cast<const void*>(&ptr[point_l
									* size])),

							const_cast<void*>(reinterpret_cast<const void*>(&ptr[point_r
									* size])), size);
				}
				point_l++; //左カーソルを進める

				//符号なし整数 0　からのデクリメントを避ける
				if (point_r == 0) {

					goto QuickRight;
					//goto 文を使用します テキスト記述のため
				}

				point_r--; //右カーソルを戻す
			}


		//右カーソルが1以上の時
		if (0 < point_r) {

			//クイックソートの呼び出し 先頭の要素と右カーソルの指す要素　比較
			quicksort(const_cast<void*>(reinterpret_cast<const void*>(&ptr[0])),
					point_r + 1, size, compar);
		}

		//goto 文からくる部分
		QuickRight:
		//左カーソルが 要素以下を指しているとき
		if (point_l < nmenb - 1) {

			//クイックソートの呼び出し 左カーソルの指すの要素と要素数と左カーソルの差分を指す要素
			quicksort(
					const_cast<void*>(reinterpret_cast<const void*>(&ptr[point_l
							* size])), nmenb - point_l, size, compar);
		}
	}
}
