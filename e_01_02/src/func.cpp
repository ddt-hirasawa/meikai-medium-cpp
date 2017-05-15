/*
演習1-2 クラスDate でありえない日にちを訂正するようにしてください

作成日 2017年5月15日

作成者 平澤敬介
*/

#include<iostream>
#include"class.h"

using namespace std;

//挿入子 現在の日付を表示します
ostream& operator << (ostream& stream,const Date& tmp) {

	//stream から西暦 月 日 の順番に表示を行います
	return stream << "西暦" << tmp.open_year() << "年"
			<< tmp.open_month() << "月"
			<< tmp.open_day() << "日\n";
}

//抽出子 日付を入力しデータメンバに加えます
istream& operator >> (istream& stream,Date& tmp) {

	//宣言 1900年～2100年の範囲
	std::cout << "西暦 : ";
	//データメンバ year を入力します
	stream >> tmp.year;
	//宣言 1月～12月の範囲
	std::cout << "何月 : ";
	//データメンバ month を入力します
	stream >> tmp.month;
	//宣言 1日～その月の末尾までの範囲
	std::cout << "何日 : ";
	//データメンバ day を入力します
	stream >> tmp.day;

	return stream;
}
