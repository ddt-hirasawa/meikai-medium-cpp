/*
演習4-3 List 4-12 のクラスに対し、アップキャスト ダウンキャストを試みるプログラムの作成

作成日 2017年5月19日

作成者 平澤敬介
*/

#include<iostream>
#include"class.h"

using namespace std;

//アップキャスト 派生クラスオブジェクトを基底クラスへのポインタや参照に変換すること
//ダウンキャスト 基底クラスオブジェクトを派生クラスへのポインタや参照に変換すること  < -  例外ありで基本ダメ

int main(){


	Base base(1,2);				//基底クラス

	Derived tmp(4,5,6);			//派生クラス

	Base* base_ptr = &base;		//基底クラスのポインタ

	Derived* deri_ptr = &tmp;	//派生クラスのポインタ

	cout << "基底クラスの関数 \n";

	base.func();

	cout << "派生クラスから基底クラスの関数 \n";

	//基底クラスのデータメンバの表示
	tmp.func();

	cout << "派生クラスの関数 \n";

	//派生クラスのデータメンバの表示
	tmp.method();

	cout << "基底クラスのデータメンバtmp1 : " << base_ptr -> get_tmp1() << "\n";
	cout << "基底クラスのデータメンバtmp2 : " << base_ptr -> get_tmp2() << "\n";

	cout << "派生クラスのデータメンバtmp1 : " << deri_ptr -> get_tmp1() << "\n";	//アップキャスト 基底クラスのゲッタ
	cout << "派生クラスのデータメンバtmp2 : " << deri_ptr -> get_tmp2() << "\n";	//アップキャスト 基底クラスのゲッタ
	cout << "派生クラスのデータメンバtmp3 : " << deri_ptr -> get_tmp3() << "\n";

	base_ptr = &tmp;		//基底クラスのポインタ	を派生クラスのオブジェクトの参照にする
	cout << "基底クラスから派生クラスのデータメンバtmp1 : " << base_ptr -> get_tmp1() << "\n";
	//cout << "基底クラスから派生クラスのデータメンバtmp1 : " << base_ptr -> get_tmp3() << "\n"; //ダウンキャスト 不可

	return 0;
}
