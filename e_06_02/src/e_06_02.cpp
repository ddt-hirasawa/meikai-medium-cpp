/*
 演習6-2 テキストで挙げている図形クラス群をすべてテストするプログラムの作成

 作成日 2017年5月23日

 作成者 平澤敬介
 */

#include<iostream>
#include"class.h"
#include"derivation1.h"
#include"derivation2.h"

using namespace std;

#define wid 10 //幅
#define hid 10 //高さ

int main() {
	Geometry* tmp[] = {

			new Point(),					//点クラス
			new HorzLine(wid),				//水平直線クラス
			new VertLine(hid),				//垂直直線クラス
			new Square(wid, hid),			//四角形クラス
			new Tri_left_under(wid, hid),	//追加した3角形クラス
			new Tri_left_up(wid, hid),		//演習6-1 からクローン to_string debug をそれぞれ追加し
			new Tri_right_under(wid, hid),	//抽象クラスのメンバ関数とほぼ同じにしました
			new Tri_right_up(wid, hid),		//異なっているのは純粋仮想デストラクタがないことのみ
											//派生先はmain内でdelete[]で削除
			};

	int select;								//キーボード入力で表示する図形を選択します

	int max = sizeof(tmp) / sizeof(tmp[0]);	//図形の種類を変数で保管します

	do {
		//続けて図形の情報を表示させるため do while ループ開始
		cout << "点 : 0 水平直線 : 1 垂直直線 : 2 四角形 : 3\n"
				"三角形 左下直角 : 4 左上直角 : 5 右下直角 : 6 右上直角 : 7\n";
		cout << "それ以外で終了 : ";
		cin >> select;						//キーボード入力で図形を選択

		if (0 <= select && select < max) {

			tmp[select]->debug();
			tmp[select]->draw();
		}

	} while (0 <= select && select < max);

	return 0;
}
