/*
 演習8-2 テキストの構造でmain 文を作成し動作を確認せよ

 作成日 2017年5月24日

 作成者 平澤敬介
 */

#include<iostream>
#include<cstdlib>

using namespace std;

#define MAX 1000000

int main()
{
	try {

		int tmp = 1;		//例外処理のため変数を定義

		//変数i を制限なくインクリメントしながらシフト演算
		for(int i=0;;i++) {

			tmp <<= i;		//1つ左にビットシフト;

			//シフト結果を回数別に表示
			cout << i + 1 << "回目 : " << tmp << "\n";

			//制限値を超えた場合 例外に投げられる
			if(MAX <= tmp) {

				//制限値を超えたならMAX文字を投げます
				throw "MAX";
			}
		}

	} catch(char) {
		cout << "強制終了\n";
		abort();
	}
}
