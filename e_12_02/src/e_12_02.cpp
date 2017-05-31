/*
演習12-2 List12-2 を書き換え ifstream -> ofstream に変更せよ
これにより、ファイルの内容が消去されることを確認せよ

作成日 2017年5月31日

作成者 平澤敬介平澤敬介
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

	cout << "中身を削除したいファイルの名前 : ";

	cin >> file_name;		//文字列としてファイルの名前を入力

	//関数の呼び出し ファイルがあるかないか？
	cout << (file_exist(file_name.c_str()) ? ( "true\n") : ("false\n"));

	return 0;
}

//関数 ファイルがあるかどうかの判別
//仮引数 ファイル名
//返却値 true or false

bool file_exist(const char* filename) {

	ofstream file(filename);		//入力ストリームとしてオープン

	return file.is_open();			//オープンできたか？
}
/*
 *  Debug 内の .gitignore を探索したところ true が返却 その後、ファイルを開いて
 *  見たとこを中身が空になっていることを確認しました
 */
