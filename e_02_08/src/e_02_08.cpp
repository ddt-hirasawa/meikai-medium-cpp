/*
 演習2-9 クラスVecBitset を作成し 動作の確認をせよ

 作成日 2017年5月22日

 作成者 平澤敬介
 */

#include<iostream>
#include"class.h"

using namespace std;

int main() {

	const int max = 63;				//集合の上限値を設定

	const int min = 10;				//集合の下限値を設定

	VecBitset tmp1(min,max);		//クラスオブジェクトの生成 空オブジェクト
	VecBitset tmp2(min, max);		//tmp2 は 配列の値とその要素数から構成
	VecBitset tmp3(min, max);		//tmp3 は 配列の値とその要素数から構成
	VecBitset tmp4(min, max);		//tmp4 は 配列の値とその要素数から構成
	VecBitset tmp5(min, max);		//tmp5 は 配列の値とその要素数から構成
	VecBitset tmp6(min, max);		//tmp6 は 配列の値とその要素数から構成

	int select;						//任意のビットを削除するための変数

	//集合に任意のビットを追加する
	for(int i=min; i <= max; i++) {

		//最小値から始まる変数に30を加え集合に加えられる範囲の値を
		//追加する
		tmp2.add(i+30,min,max);
	}

	//コンストラクタ による集合
	cout << "tmp1 : " << tmp1 << "\n" << "	" << tmp1.bit_string() << "\n";
	cout << "tmp1 は " << (tmp1.empty() ? "空集合ではありません\n" : "空集合です\n");

	//コンストラクタ による集合 ですが 任意のビットが加えられている
	cout << "tmp2 : " << tmp2 << "\n" << "	" << tmp2.bit_string() << "\n";
	cout << "tmp2 は " << (tmp2.empty() ? "空集合ではありません\n" : "空集合です\n");

	//削除関数のテスト
	cout << "tmp2 の 任意のビットを削除します : ";
	//キーボード入力で任意のビットを決定
	cin >> select;

	//任意のビットを削除
	tmp2.remove(select,min,max);

	cout << select << "bitを削除しました\n";

	//削除した結果を表示
	cout << "tmp2 : " << tmp2 << "\n" << "	" << tmp2.bit_string() << "\n";

	//空集合に任意のビットを追加する
	for(int i=min; i <= max; i++) {

		tmp1.add(i+10,min,max-10);			//論理積のテスト用 重なる部分を作る
	}

	//論理積を表示
	cout << "tmp1 : " << tmp1 << "\n" << "	" << tmp1.bit_string() << "\n";

	//演算子関数 &=のテスト 論理積なので両方1の部分が1になる
	tmp1 &= tmp2;

	cout << "tmp1 と tmp2 の論理積\n";
	//論理積を表示
	cout << "tmp1 : " << tmp1 << "\n" << "	" << tmp1.bit_string() << "\n";

	//集合に任意のビットを追加する
	for(int i=10; i < 30; i++) {

		//最小値から始まる変数に30を加え集合に加えられる範囲の値を
		//追加する
		tmp3.add(i,min,max);
	}

	//集合に任意のビットを追加する
	for(int i=30; i <= 40; i++) {

		//最小値から始まる変数に30を加え集合に加えられる範囲の値を
		//追加する
		tmp4.add(i,min,max);
	}
	//論理和を求めるため集合を生成します
	cout << "tmp3 : " << tmp3 << "\n" << "	" << tmp3.bit_string() << "\n";
	cout << "tmp4 : " << tmp4 << "\n" << "	" << tmp4.bit_string() << "\n";

	cout << "tmp3 と tmp4の論理和\n";

	//演算子関数 |=のテスト 論理和なのでどちらかが1の部分が1になる
	tmp3 |= tmp4;

	cout << "tmp3 : " << tmp3 << "\n" << "	" << tmp3.bit_string() << "\n";

	//論理和を求めるため集合を生成します
	cout << "tmp3 : " << tmp3 << "\n" << "	" << tmp3.bit_string() << "\n";
	cout << "tmp4 : " << tmp4 << "\n" << "	" << tmp4.bit_string() << "\n";

	cout << "tmp3 と tmp4の排他的論理和\n";

	//演算子関数 ^=のテスト 排他的論理和なので片方が1の部分が1になる
	tmp3 ^= tmp4;

	cout << "tmp3 : " << tmp3 << "\n" << "	" << tmp3.bit_string() << "\n";

	//等しいかを判別するため集合を表示します
	cout << "tmp5 : " << tmp5 << "\n" << "	" << tmp5.bit_string() << "\n";
	cout << "tmp6 : " << tmp6 << "\n" << "	" << tmp6.bit_string() << "\n";

	//集合の判別を行います
	cout << "集合tmp5 tmp6 は" << (tmp5 == tmp6 ? "等しいです\n" : "異なります\n");
	cout << "集合tmp5 tmp6 は" << (!(tmp5 != tmp6) ? "等しいです\n" : "異なります\n");

	//集合に任意のビットを追加する
	for(int i=10; i < 30; i++) {

		//最小値から始まる変数に30を加え集合に加えられる範囲の値を
		//追加する
		tmp5.add(i,min,max);
	}

	//等しいかを判別するため集合を表示します
	cout << "tmp5 : " << tmp5 << "\n" << "	" << tmp5.bit_string() << "\n";
	cout << "tmp6 : " << tmp6 << "\n" << "	" << tmp6.bit_string() << "\n";

	//集合の判別を行います
	cout << "集合tmp5 tmp6 は" << (tmp5 == tmp6 ? "等しいです\n" : "異なります\n");
	cout << "集合tmp5 tmp6 は" << (!(tmp5 != tmp6) ? "等しいです\n" : "異なります\n");

	return 0;
}
