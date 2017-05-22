/*
演習6-2 テキストで挙げている図形クラス群をすべてテストするプログラムの作成

作成日 2017年5月22日

作成者 平澤敬介
*/

#ifndef CLASS_H_
#define CLASS_H_

#include<iostream>
#include<sstream>
#include<string>
#include<typeinfo>

//図形クラス 基底クラス
class Geometry {
public:

	//複製 純粋仮想関数
	virtual Geometry* clone() const = 0;

	//描画 純粋仮想関数
	virtual void draw() const = 0;

	//純粋仮想デストラクタ
	inline virtual ~Geometry() const = 0 {
	}

	//文字列表現 純粋仮想関数
	virtual std::string to_string() const = 0;

	//デバッグ用情報の表示 純粋仮想関数
	inline virtual void debug() const = 0 {

		std::cout << "--デバッグ情報--\n";
		std::cout << "型 : " << typeid(*this).name() << "\n";
		std::cout << "アドレス : " << this << "\n";
	}

	//情報解説付き描画
	void print() const {

		//抽出子による表示
		std::cout << to_string() << "\n";

		//図形の表示
		draw();
	}
};

#endif
