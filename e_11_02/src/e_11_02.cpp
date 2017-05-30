/*
演習11-2 関数テンプレート put_string_vector を []演算子ではなく、反復子を用いよ

作成日 2017年5月30日

作成者 平澤敬介
*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

//関数宣言
template <class InputIterator>
void put_string_vector(InputIterator first, InputIterator last);

int main()
{
	vector<string> test1;		//容量を指定しないコンテナを用意

	test1.push_back("ABCDEF");	//アルファベット順に文字列を格納
	test1.push_back("GHIJKL");	//
	test1.push_back("MNOPQR");	//
	test1.push_back("STUVWX");	//27文字分
	test1.push_back("YZ");		//

	//全要素を表示す関数の呼び出し
	put_string_vector(test1.begin(),test1.end());

	return 0;
}

template <class InputIterator>
//文字列のベクトルを1文字ずつ捜査して表示
void put_string_vector(InputIterator first, InputIterator last)
{
	cout << "{ ";

	//string型の全文字列分走査する
	for(InputIterator i=first; i < last; i++) {

		//文字列を区切ります
		cout << '"';

			//[]演算子から InputIterator に変更しました
			cout << *i;

		//文字列を区切ります
		cout << "\" ";
	}

	cout << "}";
}
