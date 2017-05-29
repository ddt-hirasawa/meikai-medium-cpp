/*
演習9-8-3 FixedArray をインクルードモデル化せよ

作成日 2017年5月29日

作成者 平澤敬介
*/

#include <iostream>
#include"class.h"

using namespace std;

template <class Type, int N>
void print_FixedArray(const FixedArray<Type , N>& tmp);

int main()
{
	FixedArray<int,7> tmp;				//固定長配列クラス

	//配列の値に添字を代入
	for(int i=0; i < tmp.size(); i++) {

		tmp[i] = i;		//各配列の要素に添字を代入
	}

	FixedArray<int,7> copy = tmp;		//代入演算子のテスト コピー

	//コンストラスタにより生成されたオブジェクトを表示
	cout << "tmp  : ";
	//関数により簡潔に表示する
	print_FixedArray(tmp);
	//区切ります
	cout << "\n";

	//代入演算子により生成されたオブジェクトを表示
	cout << "copy : ";
	//関数により簡潔に表示する
	print_FixedArray(copy);
	//区切ります
	cout << "\n";

	return 0;
}

//関数 クラス配列の要素を並べて表示する
//仮引数 クラスオブジェクト
//返却値 無し

template <class Type, int N>
void print_FixedArray(const FixedArray<Type , N>& tmp)
{
	//要素を区切る括弧
	cout << "{ ";

	//配列の要素分表示する
	for(int i=0; i < tmp.size(); i++) {

		cout << tmp[i] << " ";
	}

	//要素を区切る閉じ括弧
	cout << "}";
}
