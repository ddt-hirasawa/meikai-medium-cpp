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

	return 0;
}
