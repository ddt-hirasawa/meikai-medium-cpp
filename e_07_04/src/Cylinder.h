/*
演習7-4 3次元クラス を抽象基底クラスとして定義し、継承するクラスを定義せよ

作成日 2017年5月23日

作成者 平澤敬介
*/

#ifndef CYLINDER_H_
#define CYLINDER_H_

#include"stereo.h"
#include"three.h"

//円柱	立体抽象クラス 3次元抽象クラスを基底クラスとする
class Cylinder : public Stereo, public ThreeDimensional{

	double radius;			//円柱の半径をデータメンバとします

	double height;			//円柱の高さをデータメンバとしま

public:

	//コンストラクタ
	Cylinder(double r,double h) :

		//コンストラクタ初期化子で初期化
		radius(r), height(h) {}

	//クローン 同じオブジェクトを 確保しそのポインタを返却
	Cylinder* clone() const {

		return new Cylinder(radius,height);
	}

	//文字列で立体の名称を返却
	std::string to_string() const {

		std::ostringstream stream;

		//円錐の半径を出力
		stream << "Cone(radius : " << radius << " )";
		//円錐の高さを出力
		stream << "Cone(height : " << height << " )";

		return stream.str();
	}

	//デバッグ用情報表示
	void debug() const {

		//アドレスや型の情報を表示
		Stereo::debug();
		//円錐の半径を表示
		std::cout << "radius : " << radius << "\n";
		//円錐の高さを表示
		std::cout << "height : " << height << "\n";
 	}

	//体積を返却する関数 体積はそれぞれの公式により求めます
	double get_region() const {

		return PAI * radius * radius * height;
	}
};



#endif /* CYLINDER_H_ */
