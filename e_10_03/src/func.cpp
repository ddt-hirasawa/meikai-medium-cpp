/*
演習10-3 List10-10 10-11 に相当するプログラムの作成

作成日 2017年5月30日

作成者 平澤敬介
*/

#include<iostream>
#include"Date.h"

using namespace std;

//挿入子 現在の日付を表示します
ostream& operator <<(ostream& stream, const Date& tmp) {

	//stream から西暦 月 日 の順番に表示を行います
	return stream << "西暦" << tmp.open_year() << "年" << tmp.open_month() << "月"
			<< tmp.open_day() << "日\n";
}

//抽出子 日付を入力しデータメンバに加えます
istream& operator >>(istream& stream, Date& tmp) {

	//西暦を補正して入力を行います
	do {

		//宣言 1900年～2100年の範囲
		std::cout << "1900から2100年まで\n";
		std::cout << "西暦 : ";
		//データメンバ year を入力します
		stream >> tmp.year;

		//範囲外の西暦は受け付けません
		if (tmp.year < 1900 || 2100 < tmp.year) {

			//宣言 コンソールに表示して範囲内の入力を促します
			cout << "範囲外です\n";
		}
		//範囲外の場合、do文の初めに戻り最初からやり直します
	} while (tmp.year > 1900 && 2100 < tmp.year);

	//宣言 1月～12月の範囲
	do {

		//宣言 1月～12月の範囲
		std::cout << "1月から12月まで\n";
		std::cout << "何月 : ";
		//データメンバ month を入力します
		stream >> tmp.month;

		//範囲外の月は受け付けません
		if (tmp.month < 1 || 12 < tmp.month) {

			//宣言 コンソールに表示して範囲内の入力を促します
			cout << "その月はありません\n";
		}
		//範囲外の場合、do文の初めに戻り最初からやり直します
	} while (tmp.month > 1 && 12 < tmp.month);

	int max_day = dmax[tmp.month - 1];		//ヘッダで定義している月ごとの末日
											//を格納している配列を使います

	//2月はうるう年で影響があるため処理を行います
	if (tmp.month == 2) {

		//式により、うるう年の時 true が返却されるので
		if (tmp.leap_year(tmp.year)) {

			max_day++;						//1日長くなります
		}

	}
	//宣言 1日～その月の末尾までの範囲
	do {

		//宣言 1日～その月の末尾までの範囲
		std::cout << "1日から" << max_day << "日まで\n";
		std::cout << "何日 : ";
		//データメンバ day を入力します
		stream >> tmp.day;

		//範囲外の日は受け付けません
		if (tmp.day < 1 || max_day < tmp.day) {

			//宣言 コンソールに表示して範囲内の入力を促します
			cout << "その日はありません\n";
		}
	//範囲外の場合、do文の初めに戻り最初からやり直します
	} while (tmp.day > 1 && max_day < tmp.day);

	return stream;
}
