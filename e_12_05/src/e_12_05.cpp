/*
演習12-5 要素型がdouble型で要素数が10である配列の全要素を読み書きするプログラムの作成

作成日 2017年5月31日

作成者 平澤敬介
*/

#include<iomanip>
#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	const int max = 10;			//配列の要素数

	double read_write[max];		//読み書き用のdouble型の配列

	ofstream file("double.txt", ios_base::binary);	//出力ストリーム バイナリーモード

	//ファイルを開けるかで分岐
	if(!file) {

		cout << "ファイルを開けません\n";

	} else {

		//要素数分書き込みを行うためのループ
		for(int i=0; i < max; i++) {

			//宣言 double型の値を入力
			cout << "double型の値 ["  << i << "] : ";
			//値を入力
			cin >> read_write[i];

			//バイナリーモードで書き込み
			file.write(reinterpret_cast<const char*>(&read_write[i]), sizeof(double));

			file << '\n';
		}
		//終了したのでファイルクローズ
		file.close();
	}

	cout << "ファイルオープン\n";

	ifstream file_open("double.txt", ios_base::binary);	//入力ストリーム バイナリーモード

	//ファイルを開けるかで分岐
	if(!file_open) {

		cout << "ファイルを開けません\n";

	} else {

		//要素数分読み込みを行うためのループ
		for(int i=0; i < max; i++) {

			//バイナリーモードで読み込み
			file_open.read(reinterpret_cast<char*>(&read_write[i]), sizeof(double));

			//配列の値を表示するのみ
			cout << "double型の値 ["  << i << "] : " << setprecision(20) << read_write[i] << "\n";
		}
		//終了したのでファイルクローズ
		file.close();
	}

	return 0;
}
