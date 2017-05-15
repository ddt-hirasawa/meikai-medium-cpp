/*
演習1-2 クラスDate でありえない日にちを訂正するようにしてください

作成日 2017年5月15日

作成者 平澤敬介
*/

#ifndef CLASS_H_
#define CLASS_H_

#include<iostream>

//時刻クラス
class Date {
public:
	int year;		//データメンバ 西暦
	int month;		//データメンバ 月
	int day;		//データメンバ 日

public:

	//デフォルトコンストラクタ
	Date();

	//コンストラクタ
	Date(int year_,int month_ = 1,int day_ = 1) :

		//コンストラクタ初期化子で初期化します
		year(year_),month(month_),day(day_)
	{
	}

	int open_year() const {

		return year;
	}

	int open_month() const {

		return month;
	}

	int open_day() const {

		return day;
	}
};

std::ostream& operator << (std::ostream& stream,const Date& tmp);
std::istream& operator >> (std::istream& stream,Date& tmp);

#endif /* CLASS_H_ */
