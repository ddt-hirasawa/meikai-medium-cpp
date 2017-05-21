/*
演習2-7 クラス Bitsetに各メンバ関数を追加せよ

作成日 2017年5月19日

作成者 平澤敬介
*/

#include<iostream>
#include"class.h"

using namespace std;

//関数宣言 order.cpp にまとめます
void swap(Bitset&,Bitset&);

int main()
{
	Bitset tmp1;					//ビットから集合

	int test[] = {2,4,5,6,15,31};		//テスト用の配列 ビットの集合に加える
										//int 型 32bitのため 0 ～ 31 までを集合とする
	int test1[]= {1,3,7,9,16,31};		//swap用の配列


	Bitset tmp2(test, ( sizeof(test) / sizeof(test[0])));		//tmp2 は 配列の値とその要素数から構成

	Bitset tmp3 = tmp2;											//tmp3 は tmp2 のコピー

	Bitset tmp4 = tmp2;											//空集合用

	Bitset tmp5(test1, ( sizeof(test1) / sizeof(test1[0])));	//swap用

	//空集合の表示
	cout << "tmp1 : " << tmp1 << "\n"
			<< "	" << tmp1.bit_string() << "\n";

	//最小値を表示する関数のテスト
	cout << "tmp2 : " << tmp2 << "\n"
			<< "	" << tmp2.bit_string() << "\n"
			<< "最小値 : " << tmp2.min() << "\n";

	//最大値を表示する関数のテスト
	cout << "tmp3 : " << tmp3 << "\n"
			<< "	" << tmp3.bit_string() << "\n"
			<< "最大値 : " << tmp3.max() << "\n";

	//空集合にする関数のテスト
	cout << "tmp4 : " << tmp4 << "\n"
			<< "	" << tmp4.bit_string() << "\n";

	//関数の呼び出し
	tmp4.clear();
	//宣言 0 になる
	cout << "空集合\n";
	cout << "tmp4 : " << tmp4 << "\n"
			<< "	" << tmp4.bit_string() << "\n";

	//swap関数のテスト
	cout << "swap 前 メンバ関数\n";
	cout << "tmp2 : " << tmp2 << "\n"
			<< "	" << tmp2.bit_string() << "\n";

	tmp2.swap(tmp5);

	cout << "swap 後 メンバ関数\n";
	cout << "tmp2 : " << tmp2 << "\n"
			<< "	" << tmp2.bit_string() << "\n";

	//swap関数のテスト tmp2 tmp3 の交換
	cout << "swap前  非メンバ関数\n";
	cout << "tmp2 : " << tmp2 << "\n"
			<< "	" << tmp2.bit_string() << "\n";

	cout << "tmp3 : " << tmp3 << "\n"
			<< "	" << tmp3.bit_string() << "\n";
	//関数の呼び出し
	swap(tmp2,tmp3);

	cout << "swap後  非メンバ関数\n";
	cout << "tmp2 : " << tmp2 << "\n"
			<< "	" << tmp2.bit_string() << "\n";

	cout << "tmp3 : " << tmp3 << "\n"
			<< "	" << tmp3.bit_string() << "\n";

	//対象差の関数のテスト
	cout << "tmp2 と tmp3 の対象差\n";
	Bitset diff = diff.sym_diff(tmp2,tmp3);		//関数の呼び出し 差分の集合の生成

	cout << "diff : " << diff << "\n"
			<< "	" << diff.bit_string() << "\n";

	//演算子関数 & のテスト
	cout << "tmp2 と diff の積集合\n";

	Bitset tmp6 = tmp2 & diff;					//演算子関数 & でオブジェクト生成

	cout << "tmp6 : " << tmp6 << "\n"
			<< "	" << tmp6.bit_string() << "\n";

	//演算子関数 ｜ のテスト
	cout << "tmp2 と diff の和集合\n";

	Bitset tmp7 = tmp2 | diff;					//演算子関数 | でオブジェクト生成

	cout << "tmp7 : " << tmp7 << "\n"
			<< "	" << tmp7.bit_string() << "\n";

	//演算子関数 ^ のテスト
	cout << "tmp7 と tmp2 の差集合\n";

	Bitset tmp8 = tmp7 ^ tmp2;					//演算子関数 ^ でオブジェクト生成

	cout << "tmp8 : " << tmp8 << "\n"
			<< "	" << tmp8.bit_string() << "\n";

	//部分集合 真部分集合 の判定のため 配列とオブジェクトを定義

	int test2[] = {0,1,2,3,4};		//テスト用の配列 ビットの集合に加える
												//部分集合 真部分集合の判定のため
	int test3[] = {0,1,2,3,4};				//配列を複数定義

	Bitset tmp9(test2, ( sizeof(test2) / sizeof(test2[0])));	//基準となる集合

	Bitset tmp10(test3, ( sizeof(test3) / sizeof(test3[0])));	//比較する集合

	Bitset tmp11 = tmp9;										//比較する集合 真部分集合用

	tmp11.add(31);												//コピーした集合に 31を加え異なる集合にする

	//宣言 判定するためコンソールに表示しておきます
	cout << "判定前\n";
	cout << "tmp9 : " << tmp9 << "\n"
			<< "	" << tmp9.bit_string() << "\n";
	cout << "tmp10: " << tmp10 << "\n"
			<< "	" << tmp10.bit_string() << "\n";
	cout << "tmp11: " << tmp11 << "\n"
			<< "	" << tmp11.bit_string() << "\n";

	//関数による判定部分 部分集合の場合 1つでも同じ要素が tmp9 のなかにあれば成立
	cout << "tmp10 の集合は tmp9 の集合に" << ((tmp9.is_sub_of(tmp10)) ? "含まれます\n" : "含まれません\n");
	cout << "よって " << ((tmp9.is_sub_of(tmp10)) ? "部分集合です\n" : "部分集合ではありません\n");

	//関数による判定部分 真部分集合の場合 1つでも同じ要素が tmp9 のなかにあれば成立
	cout << "tmp10 の集合は tmp9 の集合に" << ((tmp9.is_sub_of(tmp10)) ? "含まれます\n" : "含まれません\n");
	cout << "また " << ((tmp9.is_pro_of(tmp10)) ? "真部分集合です\n" : "真部分集合ではありません\n");

	//関数による判定部分 真部分集合の場合 1つでも同じ要素が tmp9 のなかにあれば成立
	cout << "tmp11 の集合は tmp9 の集合に" << ((tmp9.is_sub_of(tmp11)) ? "含まれます\n" : "含まれません\n");
	cout << "また " << ((tmp9.is_pro_of(tmp11)) ? "真部分集合です\n" : "真部分集合ではありません\n");

	return 0;
}
