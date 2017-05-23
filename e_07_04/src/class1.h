/*
演習7-4 3次元クラス を抽象基底クラスとして定義し、継承するクラスを定義せよ

作成日 2017年5月23日

作成者 平澤敬介
*/

#ifndef CLASS1_H_
#define CLASS1_H_

#include"stereo.h"
#include"three.h"

//球体	立体抽象クラス 3次元抽象クラスを基底クラスとする
class Sphere : public Stereo, public ThreeDimensional{

	double radius;			//球体の半径をデータメンバとします

public:

	//コンストラクタ
	Sphere(double r) :

		//コンストラクタ初期化子で初期化
		radius(r) {}

	//クローン 同じオブジェクトを 確保しそのポインタを返却
	Sphere* clone() const {

		return new Sphere(radius);
	}

	//文字列で立体の名称を返却
	std::string to_string() const {

		std::ostringstream stream;

		stream << "Sphere(radius : " << radius << " )";

		return stream.str();
	}

	//デバッグ用情報表示
	void debug() const {

		//アドレスや型の情報を表示
		Stereo::debug();
		//球体の半径を表示
		std::cout << "radius : " << radius << "\n";
 	}

	//体積を返却する関数 体積はそれぞれの公式により求めます
	double get_region() const {

		return 4 * radius * radius * radius * PAI / 3;
	}
};



#endif /* CLASS1_H_ */
