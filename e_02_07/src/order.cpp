/*
演習2-7 クラス Bitsetに各メンバ関数を追加せよ

作成日 2017年5月19日

作成者 平澤敬介
*/

#include<iostream>
#include"class.h"

using namespace std;

//メンバ関数 集合の最小要素を返却する
//仮引数 無し
//返却値 集合の最小要素

int Bitset::min() const {

	int min = -1;		//空集合の場合 -1 を返却

	//要素の最大値から順に探索していきます
	for(int i= LONG_BIT-1; 0 <= i; i--) {

		//集合の中に１の部分を発見したとき
		if(bits & set_of(i)) {

			min = i;	//最小値の位置を更新
		}
	}

	return min;
}

//メンバ関数 集合の最大要素を返却する
//仮引数 無し
//返却値 集合の最大要素

int Bitset::max() const {

	int max = -1;		//空集合の場合 -1 を返却

	//要素の最大値から順に探索していきます
	for(int i= 0; i < LONG_BIT; i++) {

		//集合の中に１の部分を発見したとき
		if(bits & set_of(i)) {

			max = i;	//最大値の位置を更新
		}
	}

	return max;
}

//メンバ関数 集合の空集合にする
//仮引数 無し
//返却値 無し

void Bitset::clear() {

	bits &= 0U;	//論理積 どちらも1なら１なので0を渡せばすべて 0

}

//メンバ関数 集合を集合 tmp と交換する
//仮引数 集合tmp
//返却値 無し

void Bitset::swap(Bitset& tmp) {

	this -> bits = tmp.bits;
}

//関数 集合tmp1 と 集合 tmp2 と交換する
//仮引数 集合tmp1 tmp2
//返却値 無し

void swap(Bitset& tmp1,Bitset& tmp2) {

	Bitset obj = tmp1;	//tmp1 の仮置き場を作る
	tmp1 = tmp2;		//tmp1 と2 の交換
	tmp2 = obj;			//tmp2 を交換前のtmp1 にする

}

//メンバ関数 集合tmp1 と tmp2 の差を返却する
//仮引数 集合tmp1 tmp2
//返却値 集合の差分

Bitset Bitset::sym_diff(const Bitset& tmp1,const Bitset& tmp2) {

	Bitset answer;				//差分の集合を作るため、オブジェクトを生成

	//生成したオブジェクトのbitを差分に書き換える
	answer.bits = tmp1.bits > tmp2.bits ? tmp1.bits - tmp2.bits : tmp2.bits - tmp1.bits;

	return answer;
}

//演算子関数 集合tmp1 と tmp2 の積集合を返却する
//仮引数 集合tmp1 tmp2
//返却値 積集合
Bitset operator&(const Bitset& tmp1,const Bitset& tmp2) {

	Bitset answer;				//積集合を作るため、オブジェクトを生成

	//生成したオブジェクトのbitを積集合に書き換える
	answer.bits = tmp1.bits & tmp2.bits;

	return answer;
}

//演算子関数 集合tmp1 と tmp2 の和集合を返却する
//仮引数 集合tmp1 tmp2
//返却値 和集合
Bitset operator|(const Bitset& tmp1,const Bitset& tmp2) {

	Bitset answer;				//和集合を作るため、オブジェクトを生成

	//生成したオブジェクトのbitを和集合に書き換える
	answer.bits = tmp1.bits | tmp2.bits;

	return answer;
}

//演算子関数 集合tmp1 と tmp2 の差集合を返却する
//仮引数 集合tmp1 tmp2
//返却値 和集合
Bitset operator^(const Bitset& tmp1,const Bitset& tmp2) {

	Bitset answer;				//差集合を作るため、オブジェクトを生成

	//生成したオブジェクトのbitを差集合に書き換える
	answer.bits = tmp1.bits ^ tmp2.bits;

	return answer;
}

//メンバ関数 集合と集合 tmp が部分集合かを判定します
//仮引数 集合tmp
//返却値 true or false

bool Bitset::is_sub_of(const Bitset& tmp) {

	//論理積を出し 重なる部分が1つでもあれば部分集合
	return this->bits & tmp.bits;
}

//メンバ関数 集合と集合 tmp が真部分集合かを判定します
//仮引数 集合tmp
//返却値 true or false

bool Bitset::is_pro_of(const Bitset& tmp) {

	//論理積を出し 重なる部分が1つでもあり、異なる集合である真部分集合
	return (this->bits & tmp.bits) && (this->bits != tmp.bits);
}
