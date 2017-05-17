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

	const int max = 10;		//配列の要素数を 100 に設定

	int key;				//探す数字 0

	/*int search_array[max];		//関数を使って探す配列を作成

	//要素数分乱数を発生させるためループ開始
	for (int i = 0; i < max; i++) {

		search_array[i] = rand() % 50;		//0～99の間で乱数を発生

		//発生させた乱数を表示
		cout << "array[" << setw(2) << i << "] = " << setw(2) << search_array[i]
				<< "\n";
	}
	const_cast<const int>(search_array);*/

	const int search_array[max] = {0,1,2,3,4,5,6,7,8,9};

	//コンソールに表示される値を見て決めます
	cout << "探す値 : ";

	//キーボードからの値で探す値を決めます
	cin >> key;

	//int型のポインタ を関数から返却されてくるからポインタを強制キャストで変換します

	int* search_ptr = reinterpret_cast<int*>(seqsearch(&key, search_array, max,
			sizeof(int),

			//比較関数も返却値を強制キャストで変換しint型にします
			reinterpret_cast<int (*)(const void*, const void*)>(int_result)));

	cout << *(search_ptr - *search_array);

}

//関数 比較関数 tmp1 tmp2 で大きい 小さい 同じを判別して返却します
//仮引数 整数2つ
//返却値 1 -> tmp1 が大きい 0 -> 同じ -1 -> tmp2が大きい

int int_result(const int* tmp1, const int* tmp2) {

	int answer = 0;		//返却値 同じ場合は 0

	//tmp1 の方が大きい場合
	if (tmp2 < tmp1) {

		answer = 1;		//1を代入し,tmp1 が大きい
		//tmp2 の方が大きい場合
	} else {

		answer = -1;	//-1を代入し,tmp2 が大きい
	}
	//いずれにしても 1 0 -1 のどれかが返却される
	return answer;
}

//関数 比較関数 tmp1 tmp2 で大きい 小さい 同じを判別して返却します
//仮引数 一致するかどうか探す要素 key オブジェクトの先頭要素のポインタ base その要素数 nmenb 変数の型の大きさ 比較関数
//返却値 なし
void* seqsearch(const void* key, const void* base, size_t nmenb, size_t size,
		int (*compar)(const void*, const void*)) {

	//中身の変更をしないポインタの文字列の先頭は
	//探すオブジェクトを強制キャストでポインタの文字列として変換した先頭とする
	const char* tmp = reinterpret_cast<const char*>(base);

	void* result;		//返却値 空のポインタの中身をNULLとする

	//範囲が指定されている部分すべてを操作し一致する要素を探します
	for (size_t i = 0; i < nmenb; i++) {

		//関数により、keyと一致する部分がオブジェクトの中にある場合
		if (!compar(key, reinterpret_cast<const void*>(&tmp[i * size]))) {

			//返却値を定置属性を外した配列の要素の1つとします
			result = const_cast<void*>(reinterpret_cast<const void*>(&tmp[i * size]));

			//発見されたので終了します
			break;
		}
	}

	//発見された場合は その部分へのポインタ ない場合はNULLを返却する
	return result;
}
