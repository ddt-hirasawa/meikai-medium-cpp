/*
 * derivation.h
 *
 *  Created on: 2017/05/22
 *      Author: admin
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
class Tri_left_up : public Geometry {

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
class Tri_right_under : public Geometry {

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
class Tri_right_up : public Geometry {

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

#endif /* DERIVATION_H_ */


