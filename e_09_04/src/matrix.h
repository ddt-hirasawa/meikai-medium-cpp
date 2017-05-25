/*
演習9-4 2次元配列クラスで実現せよ

作成日 2017年5月25日

作成者 平澤敬介
*/

#ifndef MATRIX_H_
#define MATRIX_H_

#include<utility>
#include<algorithm>
#include<iostream>

template <class Type> class Matrix {

	int _height;		//行
	int _width;			//列 をそれぞれデータメンバに加えます

	Type** ptr;		//2次元配列の先頭要素へのポインタ 配列の1つの要素の、中にさらに配列を作るのでポインタのポインタ

public:

	//コンストラクタ
	Matrix(int x, int y) :

			//コンストラクタが呼び出されたとき、コンストラクタ初期化子で初期化する
			_height(x), _width(y) {

		ptr = new Type*[_height+1];					//構築されているオブジェクト代入される ポインタが指す部分から行分
														//ポインタを作成 0 を指すとエラーが出るので要素数を1つ増やす

		*ptr = new Type[(_height+1) * (_width + 1)];//構築されているオブジェクト代入される そのポインタが指す部分から
														//行×列分領域を確保 0 を指すとエラーが出るので要素数を1つ増やす

		//1から行 _height までポインタを走査するためループ処理
		for (int i = 1; i <= _height; i++) {

			*(ptr + i) = *ptr + (i * (_width));		//今指している部分のアドレスを,列に沿ったアドレスに書き換えます
														//width は列を意味しています。height は行を意味しています。
														//ループにより、*(ptr + 1) -> 行1列目の先頭要素のポインタは
														//基準となる *ptr のアドレスから 1 * 10-> 10個分離れたところにあります
														//2以降も同じ。基準となる *ptr からどれだけ離れたところにあるかを指示していく
		}

		//行分初期化するためのループ
		/*for (int i = 1; i <= _height; i++) {

			//列分初期化するためのループ
			for (int j = 1; j <= _width; j++) {

				ptr[i][j] = 0;							//全要素を0で初期化
			}
		}*/
	}

	//コピーコンストラクタ
	Matrix(const Matrix& tmp) {

		_height = tmp._height;			//行の要素数を自分に保管します
		_width = tmp._width;			//列の要素数を自分に保管します

		ptr = new Type*[_height+1];					//構築されているオブジェクト代入される ポインタが指す部分から行分
														//ポインタを作成 0 を指すとエラーが出るので要素数を1つ増やす

		*ptr = new Type[(_height+1) * (_width + 1)];//構築されているオブジェクト代入される そのポインタが指す部分から
														//行×列分領域を確保 0 を指すとエラーが出るので要素数を1つ増やす

		//1から行 _height までポインタを走査するためループ処理
		for (int i = 1; i <= _height; i++) {

			*(ptr + i) = *ptr + (i * (_width));		//今指している部分のアドレスを,列に沿ったアドレスに書き換えます
														//width は列を意味しています。height は行を意味しています。
														//ループにより、*(ptr + 1) -> 行1列目の先頭要素のポインタは
														//基準となる *ptr のアドレスから 1 * 10-> 10個分離れたところにあります
														//2以降も同じ。基準となる *ptr からどれだけ離れたところにあるかを指示していく
		}

		//行分の要素をコピーするためループ
		for (int i = 1; i <= _height; i++) {

			//列分の要素をコピーするためループ
			for (int j = 1; j <= _width; j++) {

				ptr[i][j] =  tmp.ptr[i][j];				//要素の代入 1つずつ代入を行う
			}
		}
	}

	//演算子関数 []
	Type*& operator [](int i) {

		//配列の添字が引数として与えられるので、ポインタの指すオブジェクトを返却する
		return ptr[i];
	}

	// デストラクタ
	~Matrix() {

		delete[] *ptr;		//行の位置の列分確保していた領域を解放
		delete[] ptr;		//行分確保していた領域を解放
	}

	//関数の宣言 長くなるので func.cppにまとめます
	Matrix operator + (const Matrix& tmp);
	Matrix operator - (const Matrix& tmp);
	Matrix operator * (double n);
	Matrix operator = (const Matrix& tmp);

};

#endif /* MATRIX_H_ */
