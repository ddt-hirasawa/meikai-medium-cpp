/*
演習5-1 会員クラス群に自己紹介をする仮想関数を追加せよ

作成日 2017年5月22日

作成者 平澤敬介
*/

#include<iostream>
#include"class.h"
#include"vip.h"
#include"senior.h"

using namespace std;

//関数宣言
void put_member(const Member* tmp);
void put_out(const Member& tmp);

int main()
{
	Member			name1("平澤 敬介",10,66);					//基底クラス
	VipMember		name2("成田 直之",11,60,"会費免除");		//派生クラス
	SeniorMember	name3("浅田 一志",12,49,1);					//派生クラス

	//基底クラスのデータメンバの表示
	name1.print();

	//派生クラスのデータメンバの表示
	name2.print();

	//派生クラスのデータメンバの表示
	name3.print();


	//体重が50kg以上であれば● 以下なら空白を表示
	put_member(&name1);

	//public protected private どのクラス 基底 派生 でも表示される
	put_member(&name2);
	put_member(&name3);

	//演習で追加した仮想関数 すべてのクラスで表示内容を変えているので仮想関数になっていなければ
	//基底クラスのメンバ関数が呼ばれる
	put_out(name1);
	put_out(name2);
	put_out(name3);

	return 0;
}

//関数 データメンバ体重が50kg以上なら●を付ける
//仮引数 Memberクラスオブジェクトのポインタ
//返却値 無し

void put_member(const Member* tmp) {

	cout << (tmp->get_weight() >= 50 ? "●" : "  ");	//●か空白が表示される
	tmp->print();									//それぞれのクラスのメンバ関数
}

//関数 データメンバの表示を行う それぞれのクラスで内容が異なる
//仮引数 Memberクラスオブジェクトのポインタ
//返却値 無し

void put_out(const Member& tmp) {

	tmp.introduce();
}
