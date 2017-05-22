/*
 演習2-9 クラスVecBitset を作成し 動作の確認をせよ

 作成日 2017年5月22日

 作成者 平澤敬介
 */

#include<limits>
#include<string>
#include<iostream>
#include<sstream>
#include"class.h"

using namespace std;

//引数として与えた値が集合に入るのか辺別する関数
bool VecBitset::contains(int tmp,int min,int max) const {

	return is_valid(tmp,min,max) && (*bits & set_of(tmp));
}

//引数として与えた値を集合に追加する関数
void VecBitset::add(int tmp,int min,int max) {

	int cnt = 1;				//引数として与えた値が配列のどの部分に該当するのか判別
								//するためのカウンタ

	//unsigned型の bit 以上の値の場合
	if (UNSIGNED <= tmp) {

		int tmp1 = tmp;			//値を一時的に保管する

		//判別のループ開始
		do{

			cnt++;				//ビットの配列の上位ビットにあたる部分に向かう

			tmp1 -= UNSIGNED;	//判別する値を最大bit数分デクリメント

		//tmp1 がunsigned型のbit数を超えている限り継続
		}while(tmp1 >= UNSIGNED);
	}

	//引数として与えられた値 tmp が集合に該当するのか辺別します
	if (is_valid(tmp,min,max)) {

		//カウント値の添字の配列部分に論理和として加算する
		bits[cnt] |= set_of(tmp);
	}
}

//引数として与えた値を集合に削除する関数
void VecBitset::remove(int tmp,int min,int max) {

	int cnt = 1;				//引数として与えた値が配列のどの部分に該当するのか判別
								//するためのカウンタ

	//集合に該当するかの判定
	if (is_valid(tmp,min,max)) {

		int tmp1 = tmp;			//値を一時的に保管する

		//unsigned型の bit 以上の値の場合
		if(UNSIGNED <= tmp) {

			//判別のループ開始
			do{

				cnt++;				//ビットの配列の上位ビットにあたる部分に向かう

				tmp1 -= UNSIGNED;	//判別する値を最大bit数分デクリメント

			//tmp1 がunsigned型のbit数を超えている限り継続
			}while(tmp1 >= UNSIGNED);
		}

		bits[cnt] &= ~set_of(tmp);	//ビットの配列の任意のビットを削除
	}
}

//集合が空の集合なのか判別する関数
bool VecBitset::empty() {

	bool answer = false;			//返却値 デフォルトは空集合

	//生成したビットの配列のすべてを判断します
	for(int i=1; i <= element; i++) {

		//一部でも1があれば OK
		if(bits[i]) {

			answer = true;			//返却値を集合に変化させる
		}
	}
	return answer;;
}

//集合 tmp との論理積の集合に更新する
VecBitset& VecBitset::operator&=(const VecBitset& tmp) {

	//生成したビットの配列すべてを論理積にかける
	for(int i=1; i <= element; i++) {

		bits[i] &= tmp.bits[i];		//集合にtmp を論理積
	}
	return *this;
}

//集合 tmp と論理和の集合に更新する
VecBitset& VecBitset::operator|=(const VecBitset& tmp) {

	//生成したビットの配列すべてを論理和にかける
	for(int i=1; i <= element; i++) {

		bits[i] |= tmp.bits[i];		//集合にtmp を論理和
	}

	return *this;
}

//集合 tmp と排他的論理和の集合に更新する
VecBitset& VecBitset::operator^=(const VecBitset& tmp) {

	//生成したビットの配列すべてを排他的論理和にかける
	for(int i=1; i <= element; i++) {

		bits[i] ^= tmp.bits[i];		//集合の差分になる
	}

	return *this;
}

//集合tmpと等しいかの判別関数
bool VecBitset::operator==(const VecBitset& tmp) {

	bool answer = true;			//返却値 デフォルトは等しい

	//生成したビットの配列のすべてを判断します
	for(int i=1; i <= element; i++) {

		//一部でも異なっていれば判定される
		if(bits[i] != tmp.bits[i]) {

			answer = false;			//返却値を異なるに変更
		}
	}

	return answer;
}

//集合tmpと異なるかの判別関数
bool VecBitset::operator!=(const VecBitset& tmp) {

	bool answer = false;			//返却値 デフォルトは等しい

	//生成したビットの配列のすべてを判断します
	for(int i=1; i <= element; i++) {

		//一部でもでも異なっていれば判定される
		if(bits[i] != tmp.bits[i]) {

			answer = true;			//返却値を異なるに変化させる
		}
	}

	return answer;
}

//文字列の表現にして表示するための関数
string VecBitset::to_string() const {

	ostringstream stream;				//sstreeam に定義されている挿入子

	int set[element * LONG_BIT];		//要素数を最大値 * elementで配列を作成
										//elementはコンストラクタの最小値と最大値で決定し
										//32bit未満は 1 64bit未満は 2 128 bit 未満は 4 となる

	int cnt = 0;						//要素数を求めるためのカウンタ

	int select = 1;						//動的に生成した配列を選択するための変数
										//32bit を超えると上位ビットへ移動する

	//0～最大値までカウントを行う
	for (int i = 0; i < element * LONG_BIT; i++) {

		//変数 i がLONG_BITの倍数と等しくなる時
		if(i / LONG_BIT == select) {

			select++;					//上位ビットへ移動する準備をする
		}
		//カウントを行う条件は生成したビットベクトルと一致する部分のみ
		if (bits[select] & set_of(i)) {

			set[cnt++] = i;				//配列にカウント値を代入
		}
	}

	//文字列表現のtため　｛
	stream << "{";

	//ビットベクトルが1個でも存在していれば表示を行う
	if (cnt) {

		//カウンタし値分表示
		for (int i = 0; i < cnt - 1; i++) {

			//カウントされた添字の配列の表示を行う
			stream << set[i] << ",";
		}
		stream << set[cnt - 1];
	}

	//文字列表現のtため　｝
	stream << "}";

	return stream.str();
}

//bitベクトルの文字列表現 01001を返却
string VecBitset::bit_string() const {

	char bp[element * LONG_BIT + 1];	//文字列のため char 型の配列を定義

	int set = 1;						//動的に生成した配列を選択するための変数
										//32bit を超えると上位ビットへ移動する

	//上位ビットから下位ビットまで表示wを行うので最大値から
	//ループ開始
	for (int i = 0; i  < LONG_BIT * element ; i++) {

		//変数 i がLONG_BITの倍数と等しくなる時
		if(i / LONG_BIT == set) {

			set++;						//上位ビットへ移動する準備をする
		}

		//文字列の配列に 1 0 のどちらかを入れていく
		bp[LONG_BIT * element - i - 1] = (set_of(i) & bits[set]) ? '1' : '0';

	}
	bp[element * LONG_BIT ] = '\0'; 	//文字化けするのでナル文字で終了

	return string(bp);
}

//挿入子
ostream& operator <<(ostream& stream, const VecBitset& tmp) {

	return stream << tmp.to_string();
}
