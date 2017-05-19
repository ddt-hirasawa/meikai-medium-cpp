/*
 演習3-5 九九の加算表と乗算表のどちらを表示させるか選択させ、選択された方を表示するプログラムの作成

 作成日 2017年5月16日

 作成者 平澤敬介
 */

#include<iostream>
#include<iomanip>

using namespace std;

//関数宣言
void output(int calc(int,int));
int integration(int,int);
int addition(int,int);

int main()
{

	typedef int (*Func)(int i,int j);						//関数のポインタの配列の宣言 返却値 int 仮引数 int int の関数の配列

	const Func func_array[] = { integration,addition };		//関数の配列 0 1 で呼び出せる

	Func func_select;										//宣言した関数のポインタの配列の仮置き場

	int select;												//キーボードから乗算 加算を選択します

	//入力を制限します 0 1 のみです
	do{

	//0  1  にそれぞれ 乗算 加算 の意味を持たせます
	cout << "九九の乗算 加算 どちらですか？ 0 - > 乗算 1 -> 加算";

	//キーボードからの値でどちらを選ぶか決定します
	cin >> select;

	//0 1 以外ならばやり直しです
	}while(select != 0 && select != 1);

	//List3-8 に準じます
	if(!select) {

		//関数配列の0番目を代入します 乗算
		func_select = func_array[0];

		//1のときの処理
	} else {

		//関数配列の1番目を代入します 加算
		func_select = func_array[1];
	}

	//中身は 乗算 加算に分かれます
	output(func_select);

	return 0;
}

//関数 九九の乗算表を表示します
//仮引数 乗算 加算 をそれぞれ行う関数
//返却値 無し

void output(int calc(int,int)) {

	cout << "  |";

	//行の走査 1から9まで横に表示します
	for (int i = 1; i <= 9; i++) {

		//3文字分最低開けます
		cout << setw(3) << i;
	}

	//基準になります
	cout << "\n--+";

	//横線を入れます
	for (int i = 1; i <= 27; i++) {

		//-をループさせて表示します
		cout << '-';
	}

	//九九の部分に移ります
	cout << "\n";

	//行分演算する値を提供します
	for (int i = 1; i <= 9; i++) {

		//演算を始める前に 行の値を表示し区切ります
		cout << i << " |";

		//列分演算する値を提供します
		for(int j=1; j <= 9; j++) {

			//演算部分
			cout << setw(3) << calc(i,j);
		}

		//次の列に移ります
		cout << "\n";
	}

}

//関数 九九の乗算を行います
//仮引数 行 列 の整数
//返却値 乗算値

int integration(int i,int j) {


	return i * j;
}

//関数 九九の加算を行います
//仮引数 行 列 の整数
//返却値 加算値

int addition(int i,int j) {


	return i + j;
}
