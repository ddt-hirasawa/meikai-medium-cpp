/*
 演習7-3 左上直角2等辺3角形 右下直角2等辺3角形 を作成せよ

 作成日 2017年5月23日

 作成者 平澤敬介
 */

#include"class.h"
#include"derivation1.h"
#include"derivation2.h"
#include<istream>
#define LEN 10

using namespace std;

int main() {

	//図形 クラスの三角形 抽象クラスでまとめます
	Geometry* select[] = {

			new Tri_left_under(LEN),			//左下直角2等辺3角形
			new Tri_left_up(LEN),				//左上直角2等辺3角形
			new Tri_right_under(LEN),			//右下直角2等辺3角形
			new Tri_right_up(LEN)				//右上直角2等辺3角形
	};

	const int element = sizeof(select) / sizeof(select[0]);	//図形の種類をsizeof演算子により出す

	//図形分表示を行うので要素数分繰り返します
	for (int i = 0; i < element; i++) {

		//デバッグ情報の表示
		select[i]->debug();

		//図形の表示
		select[i]->draw();

		//クロスキャストを使いTwoDimensionalにある面積を返却する関数を呼び出す
		//クロスキャスト 動的キャストで基底クラスを共有する派生クラス間のポインタを変換する
		cout << "面積 : " << dynamic_cast<TwoDimensional*>(select[i])->get_area() << "\n";
	}

	//確保している領域を解放し処理を終える
	for (int i = 0; i < element; i++) {

			delete select[i];
	}

	return 0;
}
