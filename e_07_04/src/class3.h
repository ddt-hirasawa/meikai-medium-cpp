/*
演習7-4 3次元クラス を抽象基底クラスとして定義し、継承するクラスを定義せよ

作成日 2017年5月23日

作成者 平澤敬介
*/

#ifndef CLASS3_H_
#define CLASS3_H_

#include"stereo.h"
#include"three.h"

//立方体	立体抽象クラス 3次元抽象クラスを基底クラスとする
class Cube : public Stereo, public ThreeDimensional{

	double width;			//立方体の1辺をデータメンバとします

	double length;			//立方体の1辺をデータメンバとします

	double height;			//立方体の高さをデータメンバとしま

public:

	//コンストラクタ
	Cube(double wid,double len,double hit) :

		//コンストラクタ初期化子で初期化
		width(wid), height(hit),length(len) {}

	//クローン 同じオブジェクトを 確保しそのポインタを返却
	Cube* clone() const {

		return new Cube(width,length,height);
	}

	//文字列で立体の名称を返却
	std::string to_string() const {

		std::ostringstream stream;

		//立方体の幅を出力
		stream << "Cube(width  : " << width << " )";
		//立方体の長さを出力
		stream << "Cube(length : " << length << " )";
		//立方体の高さを出力
		stream << "Cube(height : " << height << " )";

		return stream.str();
	}

	//デバッグ用情報表示
	void debug() const {

		//アドレスや型の情報を表示
		Stereo::debug();
		//円錐の半径を表示
		std::cout << "width  : " << width << "\n";
		//立方体の長さを出力
		std::cout << "length : " << length << "\n";
		//立方体の高さを出力
		std::cout << "height : " << height << "\n";
 	}

	//体積を返却する関数 体積はそれぞれの公式により求めます
	double get_region() const {

		return width * length * height;
	}
};

#endif /* CLASS3_H_ */
