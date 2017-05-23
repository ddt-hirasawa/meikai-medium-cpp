/*
演習7-4 3次元クラス を抽象基底クラスとして定義し、継承するクラスを定義せよ

作成日 2017年5月23日

作成者 平澤敬介
*/

#ifndef STEREO_H_
#define STEREO_H_

#include<iostream>
#include<sstream>
#include<string>
#include<typeinfo>

#define PAI 3.14	//円周率

//立体クラス 抽象クラス
class Stereo {

public:

	//純粋仮想デストラクタ
	virtual ~Stereo() = 0;

	//抽象クラスではオブジェクトを生成できない
	//それぞれの立体とおなじポインタを返却する
	virtual Stereo* clone() const = 0;

	//文字列で立体の名称を返却
	virtual std::string to_string() const = 0;

	//デバッグ用情報表示
	virtual void debug() const = 0;
};

//純粋仮想デストラクタ
inline Stereo::~Stereo() {

}
//デバッグ情報の表示
inline void Stereo::debug() const {

	std::cout << "--デバッグ情報--\n";
	std::cout << "型 : " << typeid(*this).name() << "\n";
	std::cout << "アドレス : " << this << "\n";
}

//挿入子
inline std::ostream& operator << (std::ostream& stream , const Stereo& tmp) {

	return stream << tmp.to_string();
}

#endif /* STEREO_H_ */
