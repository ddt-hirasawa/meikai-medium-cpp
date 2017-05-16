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
	// テンプレート化 型名 Output  引数 int int 返却値 int
	typedef int (*output)(int,int);

	output select[] = { integration, addition };

	output Select;


	int select_;

	do{


		cin >> select_;


		if(select_ == 0 || select_ == 1) {

			Select = static_cast<output>(select_);

			output(Select);
		}


	}while(select_ != 9999);

	return 0;
}

//関数 九九の乗算表を表示します
//仮引数 乗算 加算 をそれぞれ行う関数
//返却値 無し

void output(int calc(int,int)) {

	cout << "九九の乗算表\n";

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
