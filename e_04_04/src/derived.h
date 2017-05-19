/*
演習4-4 退会済み会員クラス へのポインタから会員クラスへのアップキャストが実行できるか確認せよ

作成日 2017年5月19日

作成者 平澤敬介
*/

#ifndef DERIVED_H_
#define DERIVED_H_

#include<string>
#include<iostream>
#include"base.h"

//退会済み会員クラス
class ResigningMember : private Member {

	//退会しているので新たに追加するデータメンバは無し

public:

	//コンストラクタ
	ResigningMember(const std::string& name,int number_,double weight_) :

		//会員クラスのデータメンバをすべて引き継ぐ
		Member(name,number_,weight_) {

	}

	//データメンバは与えられているが、退会済みなので実際はデータは破棄されている設定
	double get_weight() {

		//データがありません
		std::cout << "NO DATE\n";

		//false を返却し終了
		return 0;
	}

	//この部分がないと非会員なので閲覧は無理
	using Member::get_number;	//限定公開の設定 using クラス名 :: メンバ名 -> メンバ関数のこと
	using Member::get_weight;	//限定公開の設定 using クラス名 :: メンバ名 -> メンバ関数のこと
	using Member::get_name;		//限定公開の設定 using クラス名 :: メンバ名 -> メンバ関数のこと
};



#endif /* DERIVED_H_ */
