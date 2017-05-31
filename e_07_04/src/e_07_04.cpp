/*
演習7-4 3次元クラス を抽象基底クラスとして定義し、継承するクラスを定義せよ

作成日 2017年5月23日

作成者 平澤敬介
*/

#include"Sphere.h"
#include"Cone.h"
#include"Cube.h"
#include"Cylinder.h"
#include"three.h"
#include"stereo.h"
#include<istream>

using namespace std;

int main() {

	const double radius = 3.3;		//立体の体積を出すにあたって使う変数群
	const double width = 4.5;		//それぞれ上から 半径 横幅 縦幅 高さ
	const double length = 6.9;		//演算の値がdoubleなので引数も doubleにします
	const double height = 5.7;		//


	//立体  抽象クラスでまとめます
	Stereo* select[] = {

			new Sphere(radius),						//球体クラス
			new Cone(radius,height),				//円錐クラス
			new Cube(width,length,height),			//立方体クラス
			new Cylinder(radius,height)				//円柱クラス
			};

	const int element = sizeof(select) / sizeof(select[0]);	//立体の種類をsizeof演算子により出す

	//立体の情報を表示するためループ処理します
	for (int i = 0; i < element; i++) {

		//デバッグ情報の表示 名称など
		select[i]->debug();

		//クロスキャストにより変換し体積を表示する紺数を呼び出す
		cout << "体積 : " << dynamic_cast<ThreeDimensional*>(select[i])->get_region();

		cout << "\n";
	}

	//確保している領域を解放し処理を終える
	for (int i = 0; i < element; i++) {

			delete select[i];
	}

	return 0;
}
