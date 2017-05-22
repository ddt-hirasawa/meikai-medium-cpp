/*
演習6-1 図形クラス群に直角2等辺3角形を表すクラス群を作成せよ

作成日 2017年5月22日

作成者 平澤敬介
*/

#ifndef CLASS_H_
#define CLASS_H_

#include<iostream>

//図形クラス 基底クラス 三角形クラス
class Triangle {

public:

	virtual void draw() const = 0;		//純粋指定子 = 0 で純粋仮想関数となる


	//仮想デストラクタ 領域を確保していないので中身は空
	virtual ~Triangle(){

	}

};

//三角形クラス 左下2等辺三角形
class Tri_left_under : public Triangle {

	int width;			//幅
	int height;			//高さ

public:

	//コンストラクタ
	Tri_left_under(int wid,int hid) :

		width(wid),height(hid) {

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
};

//三角形クラス 左上2等辺三角形
class Tri_left_up : public Triangle {

	int width;			//幅
	int height;			//高さ

public:
	//コンストラクタ
	Tri_left_up(int wid,int hid) :

		width(wid),height(hid) {

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
};

//三角形クラス 右下2等辺三角形
class Tri_right_under : public Triangle {

	int width;			//幅
	int height;			//高さ

public:
	//コンストラクタ
	Tri_right_under(int wid,int hid) :

		width(wid),height(hid) {

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
};

//三角形クラス 右上2等辺三角形
class Tri_right_up : public Triangle {

	int width;			//幅
	int height;			//高さ

public:
	//コンストラクタ
	Tri_right_up(int wid,int hid) :

		width(wid),height(hid) {

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
};


#endif /* CLASS_H_ */
