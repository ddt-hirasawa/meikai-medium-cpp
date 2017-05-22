/*
 演習2-9 クラスVecBitset を作成し 動作の確認をせよ

 作成日 2017年5月22日

 作成者 平澤敬介
 */

#ifndef CLASS_H_
#define CLASS_H_

#include<limits>
#include<string>
#include<iostream>

#define UNSIGNED 32		//unsigned型の bit 数

class VecBitset {

	//unsigned long 型の集合
	unsigned long* bits;

	int max, min, element;			//データメンバ 集合の最大値、最小値、要素数を決める変数

	//long log 型のビット数 データメンバ
	static const int LONG_BIT = std::numeric_limits<unsigned long>::digits;

	//関数 0 以上かを判別する関数 LONG_BITに左右されない
	static bool is_valid(int tmp, int min, int max) {

		//0以上に加え、引数として与えた最小値以上であり
		//最大値以下であることが加える条件になります
		return (0 <= tmp && min <= tmp && tmp <= max) ? 1 : 0;
	}

	//ビットベクトルの生成 tmpの集合
	static unsigned long set_of(int tmp) {

		return 1UL << tmp;
	}

public:

	//コンストラクタ
	VecBitset(int min_, int max_) :

			//0で埋め尽くすことで初期化します
			max(max_), min(min_), element(1 + (max - min) / UNSIGNED) {

		bits = new unsigned long[element];		//配列を動的に確保 入力される max min により決定

		//動的に生成した配列分走査する
		for (int i = 1; i <= element; i++) {

			bits[i] &= 0U;						//0で初期化
		}

	}

	//デストラクタ
	~VecBitset() {

		//配列を動的に生成したので削除を行います
		delete[] bits;
	}

	//関数宣言 func.cppにまとめます
	bool contains(int mp, int min, int max) const;
	void add(int tmp, int min, int max);
	void remove(int tmp, int min, int max);
	bool empty();
	int size() const;
	VecBitset& operator&=(const VecBitset& tmp);
	VecBitset& operator|=(const VecBitset& tmp);
	VecBitset& operator^=(const VecBitset& tmp);
	bool operator==(const VecBitset& tmp);
	bool operator!=(const VecBitset& tmp);
	std::string to_string() const;
	std::string bit_string() const;

};

std::ostream& operator <<(std::ostream& stream, const VecBitset& tmp);

#endif /* CLASS_H_ */
