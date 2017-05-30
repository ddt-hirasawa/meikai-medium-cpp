/*
演習10-5 List10-5 に print(x.rbegin(), x.rend()) を追加するとどうなるか検証せよ

作成日 2017年5月30日

作成者 平澤敬介
*/

#include<iostream>
#include<vector>

using namespace std;

//関数宣言
template <class InputIterator>
void print(InputIterator first,InputIterator last);

int main()
{
	int test1[] = {1, 2, 3, 4, 5};													//int型の配列でテスト
	vector<int> vector_test1(test1, test1 + sizeof(test1) / sizeof(test1[0]));		//vector int でテスト

	double test2[] = {2.3, 1.9, 3.4, 6.5,2.4};										//double配列でテスト
	vector<double> vector_test2(test2,test2 + sizeof(test2) / sizeof(test2[0]));	//vector double でテスト

	string test3[] = {"abc","def","123456789","asdfgh"};							//string配列でテスト
	vector<string> vector_test3(test3,test3 + sizeof(test3) / sizeof(test3[0]));	//vector string でテスト

	//宣言 int型の全要素を表示
	cout << "int    : ";

	//全要素を表示する関数の呼び出し
	print(test1,test1  + sizeof(test1) / sizeof(test1[0]));

	//宣言 int型の全要素を表示
	cout << "int    : ";

	//全要素を表示する関数の呼び出し
	print(vector_test1.begin(),vector_test1.end());

	//宣言 double型の全要素を表示
	cout << "double : ";

	//全要素を表示する関数の呼び出し
	print(test2,test2  + sizeof(test2) / sizeof(test2[0]));

	//宣言 double型の全要素を表示
	cout << "double : ";

	//全要素を表示する関数の呼び出し
	print(vector_test2.begin(),vector_test2.end());

	//宣言 string型の全要素を表示
	cout << "string : ";

	//全要素を表示する関数の呼び出し
	print(test3,test3  + sizeof(test3) / sizeof(test3[0]));

	//宣言 string型の全要素を表示
	cout << "string : ";

	//全要素を表示する関数の呼び出し
	print(vector_test3.begin(),vector_test3.end());

	//これ以降、演習10-5 部分
	cout << "演習内容\n";

	//宣言 int型の全要素を表示
	cout << "int    : ";
	//演習内容での関数の呼び出し
	print(vector_test1.rbegin(),vector_test1.rend());

	//宣言 double型の全要素を表示
	cout << "double : ";
	//演習内容での関数の呼び出し
	print(vector_test2.rbegin(),vector_test2.rend());

	//宣言 string型の全要素を表示
	cout << "string : ";
	//演習内容での関数の呼び出し
	print(vector_test3.rbegin(),vector_test3.rend());

	return 0;
}
/* rbigin ->  r が付くので biginの反対なので最後尾を先頭とし  rend -> 逆順のVectorの要素を最後尾とする
 *
 * 始まりと終わりで、逆順になっているので先入れ後出しの順番で表示が行われる
 */


template <class InputIterator>

//関数 全要素を {} で囲って表示する
//仮引数 vector の オブジェクト
//返却値 無し

void print(InputIterator first,InputIterator last) {


	cout << "{ ";

	//反復子により先頭から末尾まで走査する
	for(InputIterator i = first; i < last; i++) {

		cout << *i << " ";
	}

	cout << "}\n";
}
