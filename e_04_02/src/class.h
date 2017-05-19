/*
演習4-2 デストラクタの起動の順番を確認せよ

作成日 2017年5月19日

作成者 平澤敬介
*/

#ifndef CLASS_H_
#define CLASS_H_

#include<iostream>

//簡易クラス 継承
class Base {

	int tmp1;	//データメンバ

public:

	//コンストラクタ
	Base(int test = 0) : tmp1(test){

		//宣言 コンストラクタが呼び出されたとき表示される
		std::cout << "  Base::tmp1 を" << tmp1 << "で初期化\n";
	}

	//デストラクタ
	~Base() {

		std::cout <<  "   Base::tmp1 を" << tmp1 << "で破棄\n";
	}

	//ゲッタ データメンバ tmp1 を呼び出す
	int get_tmp1() const {

		return tmp1;
	}
};

//クラス Derivedに含ませるクラス
class Menb {

	int menb_tmp;	//データメンバ テスト

public:

	//コンストラクタ
	Menb(int test = 0) : menb_tmp(test) {

		std::cout << "  Menb::tmp1 を" << menb_tmp << "で初期化\n";
	}

	//デストラクタ
	~Menb() {

		std::cout <<  "  Menb::tmp1 を" << menb_tmp << "で破棄\n";
	}

};


//派生クラス クラス Base の情報を引き継ぐ
class Derived : public Base {

	//データメンバ クラスを含む 3つ
	int derived_tmp;
    Menb date1;
	Menb date2;

	//関数 表示を行う
	void say() {

		derived_tmp = 0;	//データメンバを0で初期化

		std::cout << "Derived::tmp を" << derived_tmp << "で初期化\n";
	}

public:

	//デフォルトコンストラクタ
	Derived(){

		say();
	}

	//コンストラクタ
	/*
	 * テキストでは 、コンストラクタ初期化子で書かれていますが警告が出ており、初期化に不具合がある様でした
	 * コンストラクタ内での実質の代入に変更し、実行したところ
	 * メンバとして与えたクラスが、初期化が終わりメンバとして加えた時点で破棄されていることがわかりました。
	 * デストラクタの動作により、メンバとして派生クラスに与えた時点で基底クラスの役割が切れていることがわかりました
	 */
	Derived( int test1, int test2, int test3) {

		date1 = Menb(test1);

		date2 = Menb(test2);

		Base tmp(test3);

		say();
	}

	//デストラクタ
	~Derived() {

		std::cout <<  "Derived::tmp1 を" << derived_tmp << "で破棄\n";
	}
};




#endif /* CLASS_H_ */
