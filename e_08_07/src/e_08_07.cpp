/*
演習8-7 List8-13 を修正し const exception型のみに改編せよ

作成日 2017年5月25日

作成者 平澤敬介
*/

#include<iostream>
#include<cstdlib>
#include<stdexcept>
#include<exception>

using namespace std;

//関数宣言
int add(int,int);

int main()
{
	int tmp1 = 1;			//変数の定義 例外を検出するため、
	int tmp2 = 99;			//整数を代入 どちらか一方でもエラーなら値は表示されない
							//また、合計値がその範囲を超えた場合も例外として検出する

	try {
		//関数の呼び出し 範囲外で例外なし故、合計の最大値は 198
		cout << "加算した値は " << add(tmp1,tmp2) << "です\n";

	//ロジックエラー 引数が範囲外であるときに使用
	//変更部分 logic error -> const exception に変更
	//変更した結果、const exception は 素となる例外ハンドラの基底クラスなので
	//例外ハンドラを1つで済ませることができました。
	} catch (const exception& tmp) {

		//out_of_range -> what に投げられる
		cout << "論理エラー発生 : " << tmp.what() << "\n";
	}

	return 0;
}

//関数 引数として与えた値が不整値（負の値もしくは100以上）のとき例外とする
//また、合計が範囲を超えた場合も検出する
//仮引数 整数2つ
//返却値 整数の加算値

int add(int tmp1,int tmp2) {

	//tmp1 の不整値を検出します
	if(tmp1 < 0 || 99 < tmp1) {

		//例外を投げます ライブラリに定義されている例外オブジェクト
		throw out_of_range("tmp1 の値が不正");
	}

	//tmp2 の不整値を検出します
	if(tmp2 < 0 || 99 < tmp2) {

		//例外を投げます ライブラリに定義されている例外オブジェクト
		throw out_of_range("tmp2 の値が不正");

	}

	//合計 の不整値を検出します
	if(tmp1 + tmp2 < 0 || 99 < tmp1 + tmp2) {

		//例外を投げます ライブラリに定義されている例外オブジェクト
		throw out_of_range("合計値が不正");

	}

	return tmp1 + tmp2;

}
