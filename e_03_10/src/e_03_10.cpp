/*
 演習3-10 binsearchx 関数を作成せよ

 作成日 2017年5月17日

 編集日 2017年5月19日

 作成者 平澤敬介
 */

#include<iostream>
#include<cstdlib>
#include<cstdlib>
#include<ctime>
#include<iomanip>

//関数宣言
void* binsearch(const void* key, const void* base, size_t nmenb, size_t size,
		int (*compar)(const void*, const void*));
int int_result(const int*, const int*);

using namespace std;

int main() {

	//乱数の種を生成
	srand(time(NULL));

	const int max = 50;		//配列の要素数を 50 に設定

	int key;				//探す数字 0

	int search_array[max];

	//要素数分乱数を発生させるためループ開始
	for (int i = 0; i < max; i += 2) {

		search_array[i] = i;//rand() % 50;		//0～49の間で乱数を発生 させた場合、乱数のためオーバーフロー

		search_array[i + 1] = i;

		//発生させた乱数を表示	ではなく	0　～　49まで降順
		cout << "array[" << setw(2) << i << "] = " << setw(2) << search_array[i]
				<< "\n";
		cout << "array[" << setw(2) << i + 1 << "] = " << setw(2)
				<< search_array[i + 1] << "\n";
	}

	//コンソールに表示される値を見て決めます
	cout << "探す値 : ";

	//キーボードからの値で探す値を決めます
	cin >> key;

	//int型のポインタ を関数から返却されてくるからポインタを強制キャストで変換します

	int* search_ptr = reinterpret_cast<int*>(binsearch(&key, search_array, max,
			sizeof(int),

			//比較関数も返却値を強制キャストで変換しint型にします
			reinterpret_cast<int (*)(const void*, const void*)>(int_result)));

	//ナル文字以外を指しているとき
	if (search_ptr != '\0') {

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
//返却値  0 -> 同じ 1

int int_result(const int* tmp1, const int* tmp2) {

	int answer = 0;		//返却値 同じ場合は 0

	//tmp1 が大きい場合
	if (*tmp2 < *tmp1) {

		answer = 1;		//1を代入し,tmp1が大きいことにする

		//tmp2 が大きい場合
	} else if (*tmp2 > *tmp1) {

		answer = -1;	//-1を代入し,tmp2が大きいことにする
	}

	//いずれにしても 1 0 -1どれかが返却される
	return answer;
}

//関数 2分探索関数
//仮引数 一致するかどうか探す要素 key オブジェクトの先頭要素のポインタ base その要素数 nmenb 変数の型の大きさ 比較関数
//返却値 なし
void* binsearch(const void* key, const void* base, size_t nmenb, size_t size,
		int (*compar)(const void*, const void*)) {

	void* ptr = NULL;			//返却用のポインタ NULLで初期化

	//要素が1以上ないと探索できません
	if (0 < nmenb) {

		const char* tmp = reinterpret_cast<const char*>(base);//探す文字列の先頭のポインタを保管します

		size_t pl = 0;									//オブジェクトの先頭部分

		size_t pr = nmenb - 1;							//オブジェクトの後端部分

		size_t pc = (pl + pr) / 2 + (pl + pr) % 2;		//オブジェクトの中央付近

		//先端と後端が異なる限り続きます
		for (; pl != pr;) {

			pc = (pl + pr) / 2 + (pl + pr) % 2;		//オブジェクトの中央付近

			int comp = compar(key,
					reinterpret_cast<const void*>(&tmp[pc * size]));//ループごとに関数を呼び出し、0で発見したことに
																	//なります

			//関数により発見したことがわかりました
			if (comp == 0) {

				//1つ前の要素を確認します 仮に同じ要素ならやり直し テキストのfor文を書き換えます
				if (compar(key,reinterpret_cast<const void*>(&tmp[(pc - 1) * size]))== 0) {

					//繰り返し同じ要素がないか探します
					do{
						pc--;		//1つ前の要素を探します

					//一つ前の要素と もう1つ前の要素が同じ場合くｒ
					}while((&tmp[pc * size] == &tmp[(pc - 1) * size]));

				}

				//先頭の要素のポインタが代入されます
				ptr = const_cast<void*>(reinterpret_cast<const void*>(&tmp[pc
						* size]));

				//探索のループから脱却
				break;

				//先頭と後端が等しくなった時
			} else if (pl == pr) {

				//探索のループから脱却　失敗
				break;

				//先頭要素が大きかった場合
			} else if (0 < comp) {

				pl = pc + 1;		//中央値を1つ後ろに進めます

				//後端要素が大きかった場合
			} else {

				pr = pc - 1;		//中央値を1つ前に進めます
			}

		}
	}

	//発見された場合は その部分へのポインタ ない場合はNULLを返却する
	return ptr;
}
