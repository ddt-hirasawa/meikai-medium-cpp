/*
 演習3-8 seqsearch関数を利用するプログラムの作成

 作成日 2017年5月17日

 作成者 平澤敬介
 */

#include<iostream>
#include<cstdlib>
#include<cstdlib>
#include<ctime>
#include<iomanip>

//関数宣言
void* seqsearch(const void* key, const void* base, size_t nmenb, size_t size,
		int (*compar)(const void*, const void*));
int int_result(const int*, const int*);

using namespace std;

int main() {

	//乱数の種を生成
	srand(time(NULL));

	const int max = 50;		//配列の要素数を 100 に設定

	int key;				//探す数字 0

	int search_array[max];

	//要素数分乱数を発生させるためループ開始
	for (int i = 0; i < max; i++) {

		search_array[i] = rand() % 50;		//0～99の間で乱数を発生

		//発生させた乱数を表示
		cout << "array[" << setw(2) << i << "] = " << setw(2) << search_array[i]
				<< "\n";
	}

	//コンソールに表示される値を見て決めます
	cout << "探す値 : ";

	//キーボードからの値で探す値を決めます
	cin >> key;

	//int型のポインタ を関数から返却されてくるからポインタを強制キャストで変換します

	int* search_ptr = reinterpret_cast<int*>(seqsearch(&key, search_array, max,
			sizeof(int),

			//比較関数も返却値を強制キャストで変換しint型にします
			reinterpret_cast<int (*)(const void*, const void*)>(int_result)));

	//ナル文字以外を指しているとき
	if (search_ptr != NULL) {

		//配列の何番目かを表示します
		cout << "配列の" << search_ptr - search_array << "番目にあります\n";
	//ありませんでした
	} else {

		//ナル文字の動作確認
		cout << "ありません\n";
	}
}

//関数 比較関数 tmp1 tmp2 で同じかを判別して返却します
//仮引数 整数2つ
//返却値  1 -> 同じ

int int_result(const int* tmp1, const int* tmp2) {

	int answer = 0;		//返却値 同じ場合は 0

	//tmp1 tmp2が等しい場合
	if (*tmp2 == *tmp1) {

		answer = 1;		//1を代入し,等しいことにする
	}

	//いずれにしても 1 0　どれかが返却される
	return answer;
}

//関数 線形探索関数
//仮引数 一致するかどうか探す要素 key オブジェクトの先頭要素のポインタ base その要素数 nmenb 変数の型の大きさ 比較関数
//返却値 なし
void* seqsearch(const void* key, const void* base, size_t nmenb, size_t size,
		int (*compar)(const void*, const void*)) {

	//中身の変更をしないポインタの文字列の先頭は
	//探すオブジェクトを強制キャストでポインタの文字列として変換した先頭とする
	const char* tmp = reinterpret_cast<const char*>(base);

	//範囲が指定されている部分すべてを操作し一致する要素を探します
	for (size_t i = 0; i < nmenb; i++) {

		//関数により、keyと一致する部分がオブジェクトの中にある場合
		if (compar(key, reinterpret_cast<const void*>(&tmp[i * size]))) {

			//返却値を定置属性を外した配列の要素の1つとします
			return const_cast<void*>(reinterpret_cast<const void*>(&tmp[i * size]));
		}
	}

	//発見された場合は その部分へのポインタ ない場合はNULLを返却する
	return NULL;
}
