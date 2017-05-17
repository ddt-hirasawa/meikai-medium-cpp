/*
演習3-4 台形公式によて積分した値を返す関数を作成せよ

作成日 2017年5月16日

作成者 平澤敬介
*/

#include<iostream>

using namespace std;

double drapezoid(double,double,int,double fp(double));
double func(double);

int main()
{
	double min,max;		//グラフ上の下限値と上限値

	int num;			//積分区間の分割数

	double result;		//関数により積分値が代入されます

	//宣言 台形の公式により積分値を出します
	cout << "台形の公式により積分値を求めます\n";

	//積分するにあたっての始まりの位置
	cout << "グラフ上の下限値 : ";

	//正の実数のみ受け付けます
	cin >> min;

	//積分するにあたっての終わりの位置
	cout << "グラフ上の上限値 : ";

	//正の実数のみ受け付けます
	cin >> max;

	//分割数を決めます 分割数が多いほど精度が高いですがその分演算が増えます
	cout << "分割数 : ";

	//回数なので、正の整数のみ受け付けます
	cin >> num;

	result = drapezoid(min,max,num,func);	//関数の呼び出し部分 引数として関数ポインタを使います

	//積分値の表示部分
	cout << "積分値 : " << result;


	return 0;
}

//関数 積分するため、ｘ軸の2乗値をy軸の値にします
//仮引数 x軸に進んだ距離
//返却値 y軸に進んだ距離

double func(double tmp) {

	return tmp * tmp;
}

//関数 台形公式により積分した値を返却します
//仮引数 積分区間の下限値 上限値 積分区間の分割数 x軸に対するy軸の値を返却する関数
//返却値 指定した区間を積分した値

double drapezoid(double min,double max,int num,double func(double)) {

	double wid = (max - min) / num;//分析幅

	double integrai = 0;		   //積分結果を返却するので宣言します

	double drap		= 0;		   //指定した範囲の台形の面積

	double to_result	= min;	    // 積分範囲の下限

	//積分の再現部分 分割数分 加算します
	for(int i = 0; i < num; i++) {

		drap = (func(to_result) + func(to_result + wid)) * wid / 2;	//台形の面積の公式の演算

		integrai += drap;											//返却する積分値の変数に加算します

		to_result += wid;											//分割幅を積分範囲に加算し、次の演算では
																	//グラフ上で隣の台形の演算を行うことになる
	}

	return integrai;												//分割幅分 加算されたので積分値になります
}
