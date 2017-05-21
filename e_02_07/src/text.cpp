/*
 演習2-7 クラス Bitsetに各メンバ関数を追加せよ

 作成日 2017年5月19日

 作成者 平澤敬介
 */

#include<limits>
#include<string>
#include<iostream>
#include<sstream>
#include"class.h"

using namespace std;

//引数として与えた値が集合に入るのか辺別する関数
bool Bitset::contains(int tmp) const {

	return is_valid(tmp) && (bits & set_of(tmp));
}

//引数として与えた値を集合に追加する関数
void Bitset::add(int tmp) {

	if (is_valid(tmp)) {

		bits |= set_of(tmp);
	}
}

//引数として与えた値を集合に削除する関数
void Bitset::remove(int tmp) {

	if(is_valid(tmp)) {

		bits &= ~set_of(tmp);
	}
}

//集合が空の集合なのか判別する関数
bool Bitset::empty(int tmp) {

	return !bits;
}

//集合に含まる要素数を求める関数
int Bitset::size() const {

	int cnt = 0;			//要素数を求めるためのカウンタ

	unsigned tmp = bits;	//符号なしのビットを変数として異議

	//tmp -> 0 falseにならない限り続く
	while(tmp) {

		tmp &= tmp - 1;		//論理積による減算

		cnt++;				//カウンタを加算
	}
	return cnt;				//カウンタの値 -> 要素数を返却
}

//集合 tmp との論理積の集合に更新する
Bitset& Bitset::operator&= (const Bitset& tmp) {

	bits &= tmp.bits;		//集合にtmp を論理積

	return *this;
}

//集合 tmp と論理和の集合に更新する
Bitset& Bitset::operator|= (const Bitset& tmp) {

	bits |= tmp.bits;		//集合にtmp を論理和

	return *this;
}

//集合 tmp と排他的論理和の集合に更新する
Bitset& Bitset::operator^= (const Bitset& tmp) {

	bits ^= tmp.bits;		//差分を集合とする

	return *this;
}

//集合tmpと等しいかの判別関数
bool Bitset::operator==(const Bitset& tmp) {

	return bits == tmp.bits;
}

//集合tmpと異なるかの判別関数
bool Bitset::operator!=(const Bitset& tmp) {

	return bits != tmp.bits;
}

//文字列の表現にして表示するための関数
string Bitset::to_string() const {

	ostringstream stream;	//sstreeam に定義されている挿入子

	int set[LONG_BIT];		//要素数を最大値で配列を作成

	int cnt = 0;			//要素数を求めるためのカウンタ

	//0～最大値までカウントを行う
	for(int i=0; i < LONG_BIT; i++) {

		//カウントを行う条件は生成したビットベクトルと一致する部分のみ
		if(bits & set_of(i)) {

			set[cnt++] = i;	//配列にカウント値を代入
		}
	}

	//文字列表現のtため　｛
	stream << "{";

	//ビットベクトルが1個でも存在していれば表示を行う
	if(cnt) {

		//カウンタし値分表示
		for(int i=0; i < cnt - 1; i++) {

			stream << set[i] << ",";
		}
		stream << set[cnt -1];
	}

	//文字列表現のtため　｝
	stream << "}";

	return stream.str();
}

//bitベクトルの文字列表現 01001を返却
string Bitset::bit_string() const {

	char bp[LONG_BIT + 1];	//文字列のため char 型の配列を定義

	//上位ビットから下位ビットまで表示wを行うので最大値から
	//ループ開始
	for(int i=LONG_BIT - 1; i >= 0; i--){

		//文字列の配列に 1 0 のどちらかを入れていく
		bp[LONG_BIT - i - 1] = (set_of(i) & bits) ? '1' : '0';
	}
	bp[LONG_BIT] = '\0'; 	//文字化けするのでナル文字で終了

	return string(bp);
}

//挿入子
ostream& operator << (ostream& stream , const Bitset& tmp) {

	return stream << tmp.to_string();
}
