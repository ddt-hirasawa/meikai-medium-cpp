/*
演習1-1 クラスHuman のコンストラクタを書き換え、コンストラクタ初期化子で行うように変更せよ

作成日 2017年5月15日

作成者 平澤敬介
*/

#include<iostream>
#include"class.h"

using namespace std;

//関数宣言
void open(Human *ptr);

int main()
{
	//平澤敬介 私です
	Human keisuke("Hirasawa",173.5,65.5);

	//関数呼び出し部分 表示されます
	open(&keisuke);

	return 0;
}

//関数 クラスのゲッタを順に呼び出します
//仮引数 クラスオブジェクト ポインタを使います
//返却値 無し

void open(Human *ptr)
{
	//クラス内のゲッタをすべて表示させます
	cout << "名前 : " << ptr -> open_name() << "\n"
			<< "身長 : " << ptr -> open_height() << "cm\n"
			<< "体重 : " << ptr -> open_weight() << "kg\n";
}

/*
 * コンストラクタ初期化子により、初期化が行われクラスのデータメンバが決まりました
 */
