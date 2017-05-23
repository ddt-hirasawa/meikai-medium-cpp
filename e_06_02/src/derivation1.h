/*
演習6-2 テキストで挙げている図形クラス群をすべてテストするプログラムの作成

作成日 2017年5月23日

作成者 平澤敬介
*/

#ifndef DERIVATION1_H_
#define DERIVATION1_H_

#include<iostream>
#include<sstream>
#include<string>
#include<typeinfo>
#include"class.h"

//点 クラス
class Point : public Geometry {

public:

	//描画
	void draw() const {

		std::cout << "+\n";
	}

	//複製
	Point* clone() const {

		//クラスオブジェクトのポインタを返却
		return new Point;
	}

	//文字列表現
	std::string to_string() const {

		//文字列 そのものを返却
		return "Point";
	}

	//デバッグ用情報表示
	void debug() const {

		//基底クラスのデバッグの呼び出し
		Geometry::debug();
	}
};

//直線 クラス
class Line : public Geometry {

public:
	int length;

public:

	//コンストラクタ
	Line(int len) :

		//コンストラクタ初期化子による初期化
		length(len) {

	}

	//ゲッタ 長さを返却
	int get_len() const {

		return length;
	}

	//セッタ 長さを指定
	void set_len(int len) {

		//データメンバに代入
		length = len;
	}

	//デバッグ用情報表示
	void debug() const {

		//基底クラスのデバッグの呼び出し
		Geometry::debug();

		std::cout << "Length : " << length << "\n";
	}
};

//水平直線 クラス
class HorzLine : public Line {

public:

	//コンストラクタ
	HorzLine(int len) :

		//コンストラクタ初期化子によりクラスオブジェクトを初期化
		Line(len) {

	}

	//複製
	virtual HorzLine* clone() const {

		return new HorzLine(length);
	}
	//描画
	void draw() const {

		//指定された長さ分繰り返し表示を行う
		for(int i=0; i < length; i++) {

			std::cout << "-";
		}
		std::cout << "\n";
	}

	//文字列表現
	std::string to_string() const {

		//string ヘッダの抽出子
		std::ostringstream ostream;

		//表示する文字を指定
		ostream << "HorzLine(length : " << length << " )\n";

		return ostream.str();
	}
};

//垂直直線 クラス
class VertLine : public Line {

public:

	//コンストラクタ
	VertLine(int len) :

		//コンストラクタ初期化子によりクラスオブジェクトを初期化
		Line(len) {

	}

	//複製
	virtual VertLine* clone() const {

		return new VertLine(length);
	}
	//描画
	void draw() const {

		//指定された長さ分繰り返し表示を行う
		for(int i=0; i < length; i++) {

			std::cout << "|\n";
		}
	}

	//文字列表現
	std::string to_string() const {

		//string ヘッダの抽出子
		std::ostringstream ostream;

		//表示する文字を指定
		ostream << "VertLine(length : " << length << " )\n";

		return ostream.str();
	}
};

class Square : public Geometry{

	int width;		//幅
	int height;		//高さ

public:

	//コンストラクタ
	Square(int wid,int hid) :

		//コンストラクタ初期化子による初期化
		width(wid),height(hid) {
	}

	//複製
	Square* clone() const {

		return new Square(width,height);
	}

	//描画
	void draw() const {

		//高さ分の表示を行うループ処理
		for(int i=1; i <= height; i++) {

			//幅分の表示を行うループ処理
			for(int j=1; j <= width; j++) {

				//1cm -> * となる
				std::cout << '*';
			}

			std::cout << "\n";
		}
	}

	//文字列表現
	std::string to_string() const {

		//string ヘッダの抽出子
		std::ostringstream ostream;

		//表示する文字を指定
		ostream << "Square(width : " << width << " , height : " << height << " )\n";

		return ostream.str();
	}

	//デバッグ用情報表示
	void debug() const {

		//基底クラスのデバッグの呼び出し
		Geometry::debug();

		std::cout << "width  : " << width << "\n";
		std::cout << "height : " << height << "\n";
	}

};

//挿入子
inline std::ostream& operator << (std::ostream& stream , const Geometry& tmp) {

	return stream << tmp.to_string();
}

#endif /* DERIVATION1_H_ */
