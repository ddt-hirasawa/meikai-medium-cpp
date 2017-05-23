/*
演習7-3 左上直角2等辺3角形 右下直角2等辺3角形 を作成せよ

作成日 2017年5月23日

作成者 平澤敬介
*/

#ifndef DERIVATION2_H_
#define DERIVATION2_H_

#include"derivation1.h"
#include"class.h"

//三角形クラス 抽象クラス
//図形クラス と 2次元クラスの多重継承
class Triangle : public Geometry, public TwoDimensional {

protected:

	int length;			//短辺の長さ

public:

	//コンストラクタ
	Triangle(int length_) :

		//短辺の長さをコンストラクタ初期化子で初期化する
		length(length_) {
	}

	double get_area() const {

		return length * length / 2;
	}

};

//三角形クラス 左下2等辺三角形
class Tri_left_under : public Triangle {

public:

	//コンストラクタ
	Tri_left_under(int length_) :

		length(length_) {

	}

	//複製
	Tri_left_under* clone() const {

		return new Tri_left_under(length);
	}

	//メンバ関数 描絵
	void draw() const {

		//高さ分表示を行うためのループ
		for(int i=1; i <= length; i++) {

			//幅分表示を行うためのループ
			for(int j=1; j <= i; j++) {

				//1cm -> * とする
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
		ostream << "Tri_left_under(length : " << length << ")\n";

		return ostream.str();
	}

	//デバッグ用情報表示
	void debug() const {

		//基底クラスのデバッグの呼び出し
		Geometry::debug();

		std::cout << "length  : " << length << "\n";	}
};

//三角形クラス 左上2等辺三角形
class Tri_left_up : public Triangle {

public:
	//コンストラクタ
	Tri_left_up(int length_) :

		length(length_) {

	}

	//複製
	Tri_left_up* clone() const {

		return new Tri_left_up(length);
	}

	//メンバ関数 描絵
	void draw() const {

		//高さ分表示を行うためのループ
		for(int i=1; i <= length; i++) {

			//幅分表示を行うためのループ
			for(int j=1; j < i; j++) {

				//1cm -> * とする
				std::cout << ' ';
			}

			//幅分表示を行うためのループ
			for(int j=1; j <= length - i + 1; j++) {

				//1cm -> * とする
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
		ostream << "Tri_left_up(length : " << length << ")\n";

		return ostream.str();
	}

	//デバッグ用情報表示
	void debug() const {

		//基底クラスのデバッグの呼び出し
		Geometry::debug();

		std::cout << "length  : " << length << "\n";
	}
};

//三角形クラス 右下2等辺三角形
class Tri_right_under : public Triangle {

public:
	//コンストラクタ
	Tri_right_under(int length_) :

		length(length_){

	}

	//複製
	Tri_right_under* clone() const {

		return new Tri_right_under(length);
	}

	//メンバ関数 描絵
	void draw() const {

		//高さ分表示を行うためのループ
		for(int i=1; i <= length; i++) {

			//幅分表示を行うためのループ
			for(int j=length; j > i; j--) {

				//1cm -> * とする
				std::cout << ' ';
			}

			//幅分表示を行うためのループ
			for(int j=1; j <= i; j++) {

				//1cm -> * とする
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
		ostream << "Tri_right_uuder(length" << length << ")\n";

		return ostream.str();
	}

	//デバッグ用情報表示
	void debug() const {

		//基底クラスのデバッグの呼び出し
		Geometry::debug();

		std::cout << "wlength  : " << length << "\n";
	}
};

//三角形クラス 右上2等辺三角形
class Tri_right_up : public Triangle {

	int length;

public:
	//コンストラクタ
	Tri_right_up(int length_) :

		length(length_){

	}

	//複製
	Tri_right_up* clone() const {

		return new Tri_right_up(length);
	}

	//メンバ関数 描絵
	void draw() const {

		//高さ分表示を行うためのループ
		for(int i=1; i <= length; i++) {

			//幅分表示を行うためのループ
			for(int j=1; j < i; j++) {

				//1cm -> * とする
				std::cout << ' ';
			}

			//幅分表示を行うためのループ
			for(int j=length; j >= i; j--) {

				//1cm -> * とする
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
		ostream << "Tri_right_up(length : " << length << ")\n";

		return ostream.str();
	}

	//デバッグ用情報表示
	void debug() const {

		//基底クラスのデバッグの呼び出し
		Geometry::debug();

		std::cout << "length  : " << length << "\n";
	}
};


#endif /* DERIVATION2_H_ */
