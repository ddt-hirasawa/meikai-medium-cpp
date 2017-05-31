/*
演習11-3 コマンドラインから与えられた文字列のソートやシャッフルを行え

作成日 2017年5月31日

作成者 平澤敬介
*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>
#include<cstdlib>

using namespace std;

//関数宣言
vector<string> strptary_to_vec(const char** ptr,int num);
template <class InputIterator>
void print(InputIterator first,InputIterator last);

int main(int argc, const char** argv)
{
	cout << argc << "\n";			//コマンドラインの文字列の数 1つのみ
	cout  << *argv << "\n";			//コマンドライン引数のパラメータ ソースコードのアドレス

	cout << "eclipse では文字列が一つしかないのでシャッフルもソートもできません\n";

	vector<string> main_cmd = strptary_to_vec(argv, argc);		//テキストに沿って記述します

	//コンテナにある文字列分繰り返し表示を行います
	for(vector<string>::size_type i=0; i < main_cmd.size(); i++) {

		//コマンドラインに1つしか文字列が無いので1回のみ
		cout << i << "番目 : " << main_cmd[i] << "\n";
	}

	cout << "文字列をプッシュし直します\n";

	//新たにプッシュ用の文字列を定義
	const char* test1[] = { "eclipse_cmdline",
							"Visual_Studio_cmdline",
							"eclipse_Vsual_Studio"};

	main_cmd = strptary_to_vec(test1, sizeof(test1) / sizeof(test1[0]));		//新たにコンテナに文字列をプッシュしなおします


	//コンテナにある文字列分繰り返し表示を行います
	for(vector<string>::size_type i=0; i < main_cmd.size(); i++) {

		//コマンドラインに1つしか文字列が無いので1回のみ
		cout << i << "番目 : " << main_cmd[i] << "\n";
	}

	cout << "文字列をシャッフル\n";

	random_shuffle(main_cmd.begin(),main_cmd.end());

	//全要素を表示する関数の呼び出し
	print(main_cmd.begin(),main_cmd.end());

	return 0;
}

//関数 全要素を表示する
//仮引数 vector の オブジェクト
//返却値 無し
template <class InputIterator>
void print(InputIterator first,InputIterator last) {

	int cnt = 0;

	//反復子により先頭から末尾まで走査する
	for(InputIterator i = first; i < last; i++) {

		cout << cnt++ << "番目 : "<< *i << " ";

		cout << "\n";
	}
}

//関数 与えられたポインタから文字列をプッシュする
//仮引数 文字列と文字列数
//返却値 コンテナ

vector<string> strptary_to_vec(const char** ptr,int num) {

	vector<string> tmp;				//string型のコンテナを用意

	//与えられた文字数列分繰り返しプッシュします
	for(int i=0; i < num; i++) {

		//ポインタのポインタが指す文字列をプッシュ
		tmp.push_back(ptr[i]);
	}
	return tmp;
}
