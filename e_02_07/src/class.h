/*
演習2-7 クラス Bitsetに各メンバ関数を追加せよ

作成日 2017年5月19日

作成者 平澤敬介
*/

#ifndef CLASS_H_
#define CLASS_H_

#include<limits>
#include<string>
#include<iostream>

class Bitset {

	//unsigned log 型のビット数 データメンバ
	static const int LONG_BIT = std::numeric_limits<unsigned long>::digits;

	//unsigned long 型の集合
	unsigned long bits;

	//関数 0 以上 LONG_BIT以下なのかどうかを判別する関数
	static bool is_valid(int tmp) {

		return 0 <= tmp && tmp < LONG_BIT;
	}

	//ビットベクトルの生成 tmpの集合
	static unsigned long set_of(int tmp) {

		return 1UL << tmp;
	}

public:

	//デフォルトコンストラクタ
	Bitset() :

		//0で埋め尽くされた集合
		bits(0UL) {

	}

	//コンストラクタ
	Bitset(const int tmp[], int num) :

		//0で埋め尽くすことで初期化します
		bits(0UL) {

		//呼び出されたときの要素数でループ
		for(int i=0; i < num; i++) {

			//ビットベクトルを生成する関数の呼び出し
			add(tmp[i]);
		}
	}

	//メンバ関数 最大値を返却する
	static int max_element() {

		return LONG_BIT - 1;

	}

	//メンバ関数 最小値を返却する
	static int min_element() {

		return 0;

	}
	//関数宣言 text.cpp にまとめます
	bool contains(int tmp) const;
	void add(int tmp);
	void remove(int tmp);
	bool empty(int tmp);
	int size() const;
	Bitset& operator&= (const Bitset& tmp);
	Bitset& operator|= (const Bitset& tmp);
	Bitset& operator^= (const Bitset& tmp);
	bool operator==(const Bitset& tmp);
	bool operator!=(const Bitset& tmp);
	std::string to_string() const;
	std::string bit_string() const;

	//関数宣言 order.cpp にまとめます
	int min() const;
	int max() const;
	void clear();
	void swap(Bitset&);
	Bitset sym_diff(const Bitset&,const Bitset&);
	friend Bitset operator&(const Bitset&,const Bitset&);
	friend Bitset operator|(const Bitset&,const Bitset&);
	friend Bitset operator^(const Bitset&,const Bitset&);
	bool is_sub_of(const Bitset&);
	bool is_pro_of(const Bitset&);
};

std::ostream& operator << (std::ostream& stream , const Bitset& tmp);

#endif /* CLASS_H_ */
