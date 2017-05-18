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
int com_name(const Person* tmp1,int num);
int com_weight(const Person* tmp1,int num);
int com_height(const Person* tmp1,int num);
void swap(const void**,const void**);

int main()
{
	const int num = 4;			//人数

	//クラスオブジェクト　4人分入力します
	Person human[] = {

	{ "SHIBATA", 170, 52 },
	{ "TAKAOKA", 180, 70 },
	{ "NANGOH", 172, 63 },
	{"SUGIYAMA", 165, 50 } };

	char* Person:: *ptr_name;	//クラスオブジェクト 名前へのポインタ

	int Person:: *ptr_weight;	//クラスオブジェクト 体重へのポインタ

	int Person:: *ptr_height;	//クラスオブジェクト 身長へのポインタ

	ptr_name   = &Person::name;

	ptr_weight = &Person::weight;

	ptr_height = &Person::height;

	swap(human.*ptr_weight,human.*ptr_weight);


	//ソート前の表示
	print_person(human, num);




	return 0;
}

//関数 クラスオブジェクトを指すポインタを交換します
//仮引数 クラスオブジェクトを指すポインタ
//返却値 無し

void swap(const void** tmp1,const void** tmp2) {

	const Person* tmp = reinterpret_cast<Person>(*tmp1);
	*tmp1       = reinterpret_cast<Person>(*tmp2);
	*tmp2       =  tmp;
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

int com_name(const Person* tmp1,const Person* tmp2) {

	//cstring の関数により判別値を返却
	return strcmp(tmp1->name,tmp2->name);
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
