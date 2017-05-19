/*
 演習3-14 List3-13に示した Person型の配列をクイックソートアルゴリズムで整列せよ
 ただし、qsort関数は使うな

 作成日 2017年5月18日

 作成者 平澤敬介
 */

#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<cstring>
#include"class.h"

using namespace std;
//関数宣言
void print_person(const Person tmp[], int num);
int com_name(const char** tmp1,const char** tmp2);
int com_weight(const Person* tmp1,const Person* tmp2);
int com_height(const Person* tmp1,const Person* tmp2);
void quicksort(void* base,size_t nmenb,size_t size,int(*compar)(const void*,const void*));
namespace {

void memswap(void* tmp1, void* tmp2, size_t num);

}

int main()
{
	const int num = 4;			//人数

	//クラスオブジェクト　4人分入力します
	Person human[num] = {

	{ "SHIBATA", 170, 52 },
	{ "TAKAOKA", 180, 70 },
	{ "NANGOH", 172, 63 },
	{"SUGIYAMA", 165, 50 }, };

	const char* Person:: *ptr_name;	//クラスオブジェクト 名前へのポインタ

	int Person:: *ptr_weight;	//クラスオブジェクト 体重へのポインタ

	int Person:: *ptr_height;	//クラスオブジェクト 身長へのポインタ

	ptr_name   = &Person::name;		//データメンバ 名前へのポインタ

	ptr_weight = &Person::weight;	//データメンバ 体重へのポインタ

	ptr_height = &Person::height;	//データメンバ 身長へのポインタ


	//ソート前の表示
	print_person(human, num);

	cout << "名前ソート\n";

	quicksort(human,num,sizeof(Person),reinterpret_cast<int (*)(const void*,const void*)>(com_name));

	//名前ソート後の表示
	print_person(human, num);

	cout << "体重ソート\n";

	quicksort(human,num,sizeof(Person),reinterpret_cast<int (*)(const void*,const void*)>(com_weight));

	//体重ソート後の表示
	print_person(human, num);

	cout << "身長ソート\n";

	quicksort(human,num,sizeof(Person),reinterpret_cast<int (*)(const void*,const void*)>(com_height));

	//身長ソート後の表示
	print_person(human, num);

	return 0;
}


//関数 クラスのデータメンバをすべて表示します
//仮引数 クラスオブジェクト 人数
//返却値 無し

void print_person(const Person tmp[], int num) {

	//人数分のデータメンバを表示します
	for (int i = 0; i < num; i++) {

		//データメンバを人数分すべて表示します
		cout << setw(10) << tmp[i].name << " " << tmp[i].weight << "kg" << " "
				<< tmp[i].height << "cm\n";
	}
}

//比較関数 クラスのデータメンバ 名前を比較します
//仮引数 クラスオブジェクトを指すポインタ
//返却値 判別地 1 0 -1

int com_name(const char** tmp1,const char** tmp2) {

	//cstring の関数により判別値を返却
	return strcmp(*tmp1,*tmp2);
}

//比較関数 クラスのデータメンバ 体重を比較します
//仮引数 クラスオブジェクトを指すポインタ
//返却値 判別値 1 0 -1

int com_weight(const Person* tmp1,const Person* tmp2) {

	//条件式により判別地を返却
	return tmp1 -> weight < tmp2 -> weight ? 1 : tmp1 -> weight > tmp2 -> weight ? -1 : 0;
}

//比較関数 クラスのデータメンバ 体重を比較します
//仮引数 クラスオブジェクトを指すポインタ
//返却値 判別値 1 0 -1

int com_height(const Person* tmp1,const Person* tmp2) {

	//条件式により判別地を返却
	return tmp1 -> height < tmp2 -> height ? 1 : tmp1 -> height > tmp2 -> height ? -1 : 0;
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
