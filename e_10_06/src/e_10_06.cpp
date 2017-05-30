/*
演習10-6 functinal で提供されている算術演算子のファンクタ と transformアルゴリズムを組み合わせたプログラムの作成

作成日 2017年5月30日

作成者 平澤敬介
*/

#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<cstdlib>
#include<ctime>

using namespace std;

//関数宣言
template <class InputIterator>
void print(InputIterator first,InputIterator last);

template <class Type>
//差分を求める算術演算を行う
struct diff : public binary_function<const Type&,const Type&, Type>
{
	Type operator()(const Type& tmp1,const Type& tmp2) {

		//必ず正の値になるように条件式を記述
		return (tmp1 < tmp2) ? tmp2 - tmp1 : tmp1 - tmp2;
	}
};

int main()
{
	const int num = 10;			//コンテナの大きさ

	vector<int> vector_1;	//配列test1用のコンテナを用意
	vector<int> vector_2;	//配列test2用のコンテナを用意

	//乱数の種を生成
	srand(time(NULL));

	for(int i=0; i < num; i++) {

		int test1 = rand() % 10;		//0から9の乱数で埋め尽くす
		int test2 = rand() % 10;		//0から9の乱数で埋め尽くす

		vector_1.push_back(test1);		//生成した乱数をプッシュ
		vector_2.push_back(test2);		//生成した乱数をプッシュ
	}

	//宣言 int型の全要素を表示
	cout << "int    : ";

	//全要素を表示する関数の呼び出し
	print(vector_1.begin(),vector_1.end());

	//宣言 int型の全要素を表示
	cout << "int    : ";

	//全要素を表示する関数の呼び出し
	print(vector_2.begin(),vector_2.end());

	cout << "差分\n";

	vector<int> result(num);			//演算の結果を格納するコンテナ

	transform(vector_1.begin(),vector_1.end(),vector_2.begin(),result.begin(),diff<int>());

	//宣言 int型の全要素を表示
	cout << "int    : ";

	//全要素を表示する関数の呼び出し
	print(result.begin(),result.end());

	return 0;
}

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
