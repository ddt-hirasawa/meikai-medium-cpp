/*
演習3-14 List3-13に示した Person型の配列をクイックソートアルゴリズムで整列せよ
ただし、qsort関数は使うな

作成日 2017年5月18日

作成者 平澤敬介
*/

#ifndef CLASS_H_
#define CLASS_H_


//人の簡易的なパラメータクラス
class Person {

public:

	char* name;	 //名前
	int height;		//身長
	int weight;		//体重
};


#endif /* CLASS_H_ */
