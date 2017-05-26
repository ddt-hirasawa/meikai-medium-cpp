/*
演習9-8 Array<bool> をインクルードモデル化せよ

作成日 2017年5月26日

作成者 平澤敬介
*/

#include<iostream>
#include<iomanip>
#include"array_bool.h"

using namespace std;

//関数宣言
void print_array(const Array<bool>& tmp);

int main()
{
	Array<bool> tmp1(32);		//bool型の配列を要素64で定義

	cout << "コンストラクタで定義している型は int型 -> 4byte のため\n"
			" 32bitまでは true falseを格納できます\n";

	long long select;			//sizeof演算子用

	//セッタにより配列の要素数を更新
	tmp1.set_vsize(sizeof(select));
	tmp1.set_size(8 * sizeof(select));

	//bool型を アルファベット表記
	cout << boolalpha;

	Array<bool> tmp2(tmp1);		//tmp1 のコピー コピーコンストラクタの確認
	Array<bool> tmp3(5);		//異なる要素を作成 ＝ 演算子のテスト用

	tmp3 = tmp2;

	//配列の全要素を表示します
	for(int i=0; i < tmp1.size(); i++) {

		cout << "tmp1[" << setw(2) << i << "] = " << tmp1[i] << "\n";
	}

	cout << "tmp1 = ";
	//配列に格納されている値を01 ですべて表示する
	print_array(tmp1);
	cout << "\n";

	cout << "tmp2 = ";
	//配列に格納されている値を01 ですべて表示する
	print_array(tmp2);
	cout << "\n";

	cout << "tmp3 = ";
	//配列に格納されている値を01 ですべて表示する
	print_array(tmp3);
	cout << "\n";

	cout << "bool型の配列を格納する配列の要素数\n";
	cout << "tmp1 : " << tmp1.get_vsize() << "\n";
	cout << "tmp2 : " << tmp2.get_vsize() << "\n";
	cout << "tmp3 : " << tmp3.get_vsize() << "\n";

	cout << "bool型の配列の要素数\n";
	cout << "tmp1 : " << tmp1.size() << "\n";
	cout << "tmp2 : " << tmp2.size() << "\n";
	cout << "tmp3 : " << tmp3.size() << "\n";;

	cout << "明示的コンストラスタで定義する変数の大きさに依存する\n";
	cout << "しかし、セッタにより配列の大きさを変更しているので64bitまで格納できる\n";
	cout << "格納する配列の大きさ : " << tmp1.get_vsize() << "\n";

	tmp1[63] = true;
	tmp2[63] = true;
	tmp3[63] = true;

	cout << "tmp1 = ";
	//配列に格納されている値を01 ですべて表示する
	print_array(tmp1);
	cout << "\n";

	cout << "tmp2 = ";
	//配列に格納されている値を01 ですべて表示する
	print_array(tmp2);
	cout << "\n";

	cout << "tmp3 = ";
	//配列に格納されている値を01 ですべて表示する
	print_array(tmp3);
	cout << "\n";

	return 0;
}

//関数 array<bool> の配列を0 1 ですべて表示する
//仮引数 array<bool> の配列
//返却値 無し

void print_array(const Array<bool>& tmp) {

	int len = tmp.size() - 1;

	for(int i=len; 0 <= i ; i--) {

		cout << (tmp[i] ? '1' : '0');
	}

}
