/*
演習7-3 左上直角2等辺3角形 右下直角2等辺3角形 を作成せよ

作成日 2017年5月23日

作成者 平澤敬介
*/

#ifndef CLASS_H_
#define CLASS_H_


#include<iostream>
#include<sstream>
#include<string>
#include<typeinfo>

//図形クラス 基底クラス
class  Geometry{

public:

	//複製 純粋仮想関数
	virtual Geometry* clone() const = 0;

	//描画 純粋仮想関数
	virtual void draw() const = 0;

	//純粋仮想デストラクタ
	virtual ~Geometry() = 0;

	//文字列表現 純粋仮想関数
	virtual std::string to_string() const = 0;

	//デバッグ用情報の表示 純粋仮想関数
	virtual void debug() const = 0;

	//情報解説付き描画
	void print() const {

		//抽出子による表示
		std::cout << to_string() << "\n";

		//図形の表示
		draw();
	}
};

//純粋仮想デストラクタ
inline Geometry::~Geometry() {

}

//デバッグ用情報の表示 純粋仮想関数
inline void Geometry::debug() const {

	std::cout << "--デバッグ情報--\n";
	std::cout << "型 : " << typeid(*this).name() << "\n";
	std::cout << "アドレス : " << this << "\n";
}

//挿入子
inline std::ostream& operator << (std::ostream& stream , const Geometry& tmp) {

	return stream << tmp.to_string();
}

#endif /* CLASS_H_ */
