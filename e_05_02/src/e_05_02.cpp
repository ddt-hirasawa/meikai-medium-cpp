/*
演習5-2 List5-18 の関数の引数をポインタから参照に変更すること

作成日 2017年5月22日

作成者 平澤敬介
*/

#include<iostream>
#include"class.h"
#include"vip.h"
#include"senior.h"

using namespace std;

//関数宣言
void senior_only(Member& tmp);

int main()
{
	Member			name1("平澤 敬介",10,66);					//基底クラス
	VipMember		name2("成田 直之",11,60,"会費免除");		//派生クラス
	SeniorMember	name3("浅田 一志",12,49,1);					//派生クラス

	//基底クラスのデータメンバの表示
	senior_only(name1);

	//派生クラスのデータメンバの表示
	senior_only(name2);

	//派生クラスのデータメンバの表示
	senior_only(name3);

	return 0;
}

//関数 派生先の中でもSeniorクラスのみ表示ができる関数
//仮引数 Memberクラスのオブジェクトを指すポインタ
//返却値 無し

void senior_only(Member& tmp) {

	//dynamic_cast を使うにあたって ランタイムの設定が必要なようです
	//設定の方法を探しています
	//コメントアウトしている部分を外して実行すると異常終了します

	//Member& reference = dynamic_cast<SeniorMember&>(tmp);

	//if(*reference != NULL) {

		//reference.print();
	//}
}
