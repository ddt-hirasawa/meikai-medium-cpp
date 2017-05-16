/*
演習3-1 List3-2 の 「良」「優」「可」の識別表示を行うプログラムを変更し、これまで挙げた識別以外でも識別表示するように変更せよ

作成日 2017年5月16日

作成者 平澤敬介
*/

#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

//関数 60～69点の生徒がいた場合、普通判定を出す
//仮引数 その生徒が取った点数
//返却s値 true or false 普通 か それ以外か

bool usually(int tmp) {

	//60～69点以内の生徒は 「普通」
	return tmp >= 60 && tmp <= 69;
}

//関数 70～79点の生徒がいた場合、良判定を出す
//仮引数 その生徒が取った点数
//返却s値 true or false 良 か それ以外か

bool good(int tmp) {

	//70～79点以内の生徒は 「良」
	return tmp >= 70 && tmp <= 79;
}

//関数 80～100点の生徒がいた場合、優判定を出す
//仮引数 その生徒が取った点数
//返却s値 true or false 優 か それ以外

bool excellent(int tmp) {

	//80～100点以内の生徒は 「優」
	return (tmp >= 80 && tmp <= 100);
}

//関数 80～100点の生徒がいた場合、優判定を出す　60～69点の生徒がいた場合、可判定を出す
//仮引数 全生徒がそれぞれ取った点数　生徒の人数　関数ポインタ bool
//返却s値 無し

void put_list(const int a[],int num,bool (*good)(int),bool (*excellent)(int),bool (*usually)(int)) {

	//全生徒の点数を判別します
	for(int i=0; i < num; i++) {

		//関数ポインタ 点数の判別 true or false
		if((*good)(a[i])) {

			//優等生
			cout << "◎";

		//100点クラスを取った人たち
		} else if((*excellent)(a[i])) {

			// 満点組
			cout << "★";

		//60点から69点
		} else if((*usually)(a[i])) {

			cout << "〇";
		//0点から59点
		} else {

			//評価無し
			cout << "✖";
		}

		//10人以下の時
		if(i < 10) {

			//空白文字を表示
			cout << " ";
		}

		//点数の表示
		cout << " a[" << i << "] = " << a[i] << "\n";
	}
}
