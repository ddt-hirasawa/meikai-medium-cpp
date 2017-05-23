/*
演習7-4 3次元クラス を抽象基底クラスとして定義し、継承するクラスを定義せよ

作成日 2017年5月23日

作成者 平澤敬介
*/

#include"class1.h"
#include"class2.h"
#include"class3.h"
#include"class4.h"
#include"three.h"
#include"stereo.h"
#include<istream>
#define LEN 10

using namespace std;

int main() {
	//図形 クラスの三角形 抽象クラスでまとめます
	Stereo* select[] = {

			};

	const int element = sizeof(select) / sizeof(select[0]);	//図形の種類をsizeof演算子により出す

	//図形分表示を行うので要素数分繰り返します
	for (int i = 0; i < element; i++) {

	}

	//確保している領域を解放し処理を終える
	for (int i = 0; i < element; i++) {

			delete select[i];
	}

	return 0;
}
