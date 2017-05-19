/*
演習3-13 List 3-19 を変更し ユーザーが年月日の数値をすべての値を入力してからの判別に変えよ

作成日 2017年5月18日

作成者 平澤敬介
*/

#include<iostream>

#include"class.h"

using namespace std;

int main()
{
	//クラスのメンバ関数へのポインタに対して
	//typedef により Comp の名前を与えます
	typedef int (SimpleDate::*Comp)(int) const;

		//Comp型で メンバ関数の配列を作ります
		Comp pcomp[] ={

				&SimpleDate::comp_year,

				&SimpleDate::comp_month,

				&SimpleDate::comp_day,};


		int year,month,day;				//入力する 年月日

		int diff_y,diff_m,diff_d;		//データメンバとの差 年月日

		int cnt = 10;					//テキストですと正解するまで続く  しかし、困るので10回で止めます

		//コンストラクタにより誕生日を設定
		const SimpleDate birthday(1990,10,11);

		//誕生日はいつですか？
		cout << "誕生日は ? : ";

		//当てるまで延々と続きます
		while(0 <= cnt--){

			//誕生日はいつですか？
			cout << "西暦 何月 何日 ? \n";

			//西暦の入力部分
			cout << "何年 : ";
			cin >> year;

			//月の入力部分
			cout << "何月 : ";
			cin >> month;

			//日の入力部分
			cout << "何日 : ";
			cin >> day;

			diff_y = (birthday.*pcomp[0])(year);	//メンバ関数についてのポインタ型の呼び出し

			diff_m = (birthday.*pcomp[1])(month);	//引数として year month day の部分を

			diff_d = (birthday.*pcomp[2])(day);		//配列にはできない

			//データメンバとの差がすべて０で終了
			if(diff_y == 0 && diff_m == 0 && diff_d == 0) {

				cout << "正解です\n";

				//whileループからの唯一の根け道
				break;

			//外れ
			} else {

				cout << "違います\n";

				//ヒント データメンバとの差を表示します
				cout << diff_y << "年 違います\n";
				cout << diff_m << "月 違います\n";
				cout << diff_d << "日 違います\n";
			}
		}


	return 0;
}
