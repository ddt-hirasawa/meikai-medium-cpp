/*
演習6-2 テキストで挙げている図形クラス群をすべてテストするプログラムの作成

作成日 2017年5月23日

作成者 平澤敬介
*/

#ifndef DERIVATION_H_
#define DERIVATION_H_

#include<iostream>
#include"class.h"

//三角形クラス 左下2等辺三角形
class Tri_left_under : public Geometry {

	int width;			//幅
	int height;			//高さ

public:

	//コンストラクタ
	Tri_left_under(int wid,int hid) :

		width(wid),height(hid) {

	}

	//複製
	Tri_left_under* clone() const {

		return new Tri_left_under(width,height);
	}

	//メンバ関数 描絵
	void draw() const {

		//高さ分表示を行うためのループ
		for(int i=1; i <= height; i++) {

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
		ostream << "Tri_left_under(width : " << width << ", height : " << height << ")\n";

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

//三角形クラス 左上2等辺三角形
class Tri_left_up : public Geometry {

	int width;			//幅
	int height;			//高さ

public:
	//コンストラクタ
	Tri_left_up(int wid,int hid) :

		width(wid),height(hid) {

	}

	//複製
	Tri_left_up* clone() const {

		return new Tri_left_up(width,height);
	}

	//メンバ関数 描絵
	void draw() const {

		//高さ分表示を行うためのループ
		for(int i=1; i <= height; i++) {

			//幅分表示を行うためのループ
			for(int j=1; j < i; j++) {

				//1cm -> * とする
				std::cout << ' ';
			}

			//幅分表示を行うためのループ
			for(int j=1; j <= width - i + 1; j++) {

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
		ostream << "Tri_left_up(width : " << width << ", height : " << height << ")\n";

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

//三角形クラス 右下2等辺三角形
class Tri_right_under : public Geometry {

	int width;			//幅
	int height;			//高さ

public:
	//コンストラクタ
	Tri_right_under(int wid,int hid) :

		width(wid),height(hid) {

	}

	//複製
	Tri_right_under* clone() const {

		return new Tri_right_under(width,height);
	}

	//メンバ関数 描絵
	void draw() const {

		//高さ分表示を行うためのループ
		for(int i=1; i <= height; i++) {

			//幅分表示を行うためのループ
			for(int j=width; j > i; j--) {

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
		ostream << "Tri_right_uuder(width : " << width << ", height : " << height << ")\n";

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

//三角形クラス 右上2等辺三角形
class Tri_right_up : public Geometry {

	int width;			//幅
	int height;			//高さ

public:
	//コンストラクタ
	Tri_right_up(int wid,int hid) :

		width(wid),height(hid) {

	}

	//複製
	Tri_right_up* clone() const {

		return new Tri_right_up(width,height);
	}

	//メンバ関数 描絵
	void draw() const {

		//高さ分表示を行うためのループ
		for(int i=1; i <= height; i++) {

			//幅分表示を行うためのループ
			for(int j=1; j < i; j++) {

				//1cm -> * とする
				std::cout << ' ';
			}

			//幅分表示を行うためのループ
			for(int j=width; j >= i; j--) {

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
		ostream << "Tri_right_up(width : " << width << ", height : " << height << ")\n";

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

#endif /* DERIVATION_H_ */


