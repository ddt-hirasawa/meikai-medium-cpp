/*
演習12-1 List 12-2 を書き換え動作の確認をせよ

作成日 2017年ｴ5月31日

作成者 平澤敬介
*/

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

//関数宣言
bool file_exist(const char* filename);

int main()
{
	string file_name;		//ファイル名をstring型で入力されます

	cout << "存在を確認したいファイルの名前 : ";

	cin >> file_name;		//文字列としてファイルの名前を入力

	//関数の呼び出し ファイルがあるかないか？
	cout << (file_exist(file_name.c_str()) ? ( "true\n") : ("false\n"));

	return 0;
}

//関数 ファイルがあるかどうかの判別
//仮引数 ファイル名
//返却値 true or false

bool file_exist(const char* filename) {

	ifstream file(filename);		//入力ストリームとしてオープン

	return file.is_open();			//オープンできたか？

	//return file;
	//return !file.fail();
}
