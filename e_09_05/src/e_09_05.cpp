/*
演習9-5 クラス Array_bool にメンバ関数を追加せよ

作成日 2017年5月26日

作成者 平澤敬介
*/

#include<iostream>
#include"class.h"
#include"array.h"

using namespace std;

//関数宣言
void print_array(const Array<bool>& tmp);

int main()
{
	Array<bool> tmp1(10);		//bool型の配列を要素１０で定義

	//bool型を アルファベット表記
	cout << boolalpha;

	//クラス配列の全要素を表示する truw or false
	for(int i=0; i < tmp1.size(); i++) {

		cout << "tmp1[" << i << "] = " << tmp1[i] << "\n";
	}

	Array<bool> tmp2(tmp1);		//tmp1 のコピー コピーコンストラクタの確認
	Array<bool> tmp3(5);		//異なる要素を作成 ＝ 演算子のテスト用

	tmp3 = tmp2;				//= 演算子により すべての配列が同じ要素にナル

	tmp2[3] = true;				//任意の位置の配列の値を 1 1にする
	tmp2[6] = true;				//任意の位置の配列の値を 1 1にする
	tmp3[5] = true;				//任意の位置の配列の値を 1 1にする
	tmp3[7] = true;				//任意の位置の配列の値を 1 1にする


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
	cout << "tmp3 : " << tmp3.size() << "\n";

	int answer;

	cout << "格納する配列の大きさ : " << sizeof(answer);

	return 0;
}

//関数 array<bool> の配列を0 1 ですべて表示する
//仮引数 array<bool> の配列
//返却値 無し

void print_array(const Array<bool>& tmp) {

	for(int i=0; i < tmp.size(); i++) {

		cout << (tmp[i] ? '1' : '0');
	}

}
