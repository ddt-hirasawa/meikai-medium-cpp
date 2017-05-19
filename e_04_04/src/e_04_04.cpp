/*
演習4-4 退会済み会員クラス へのポインタから会員クラスへのアップキャストが実行できるか確認せよ

作成日 2017年5月19日

作成者 平澤敬介
*/

#include<iostream>

#include"base.h"
#include"derived.h"

using namespace std;

//関数宣言
void open_date_member(const Member*);
void open_date_resign(const ResigningMember*);

int main()
{
	Member Active("平澤_敬介", 1234, 66);					//基底クラス 会員クラス

	ResigningMember NonActive("平澤敬介", 4321,80);			//派生クラス 退会済みクラス

	Member* active_p 			 = &Active;					//基底クラス 会員クラスのポインタ

	ResigningMember* nonactive_p = &NonActive;				//派生クラス 退会済みクラスのポインタ

	//会員クラスのデータメンバを表示
	open_date_member(active_p);

	//退会済みのメンバ関数の呼び出し
	open_date_resign(nonactive_p);

	//体重の表示 退会済みなので 体重の表示は無理
	cout << nonactive_p->get_weight() << "\n";

	//nonactive_p = &Active;						//ポインタの切り替え 会員クラスのオブジェクトを指します できません

	//会員クラスのデータメンバを表示
	//open_date_member(nonactive_p);  //無理です

	//アロー演算子によってメンバ関数をすべて呼び出します  Memberクラスのメンバ関数の呼び出し OK
	cout << "名前 : " << nonactive_p->get_name() << "\n"
			<< "番号 : " << nonactive_p->get_number() << "\n"
			<< "体重 : " << nonactive_p->get_weight() << " kg\n";   // <- 派生クラスのメンバ関数が呼び出される
																	//return 0により体重 0kg データが消されている
	return 0;
}

//関数 基底クラス 会員クラスのデータメンバの表示を行います
//仮引数 会員クラスのポインタ
//返却値 無し

void open_date_member(const Member* ptr) {

	//アロー演算子によってメンバ関数をすべて呼び出します
	cout << "名前 : " << ptr->get_name() << "\n"
			<< "番号 : " << ptr->get_number() << "\n"
			<< "体重 : " << ptr->get_weight() << " kg\n";
}

//関数 派生クラス 非会員クラスのメンバ関数を実行します
//仮引数 非会員クラスのポインタ
//返却値 無し

void open_date_resign(const ResigningMember* ptr) {

	cout << "退会済み : " << ptr->get_number() << "\n";

			//<< ptr->get_weight(); アロー演算子は使えない ポインタの値が不正だから？
}
