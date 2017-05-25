/*
演習9-2 1-2でのDateクラスをテンプレート化せよ

作成日 2017年5月25日

作成者 平澤敬介
*/

#include<utility>
#include<algorithm>
#include<iostream>
#include<ctime>
#include"class.h"

//	1  2  3  4  5  6  7  8  9  10 11 12 月の末日
const int dmax[] = {31,28,31,30,31,30,31,31,30,31,30,31};

//派生　時刻クラス
template <class Type>

class Date : public Twin {

public:
	Type year;		//データメンバ 西暦
	Type month;		//データメンバ 月
	Type day;		//データメンバ 日

public:

	//デフォルトコンストラクタ
	Date();

	//コンストラクタ
	Date(Type year_ = Type(),Type month_ = Type(),Type day_ = Type()) :

		//コンストラクタ初期化子で初期化します
		year(year_),month(month_),day(day_)
	{
		time_t current =   time(NULL);				//現在の時刻を取得。
		struct tm* local = localtime(&current);		//ポインタにより 年月日をそれぞれ指す

		//不正値が1つでも入力されているのなら、現在時刻に補正します
		if(year_ < 0 || month_ < 1 || 12 < month_ || day_ < 1 || dmax[month_] < day_) {

			year = local -> tm_year + 1900;		//現在時刻 西暦の取得
			month = local -> tm_mon + 1;		//現在時刻 月の取得
			day = local -> tm_mday;				//現在時刻 日の取得
		}
	}

	//ゲッタ データメンバ 年を表示させる
	Type open_year() const {

		return year;
	}

	//ゲッタ データメンバ 月を表示させる
	Type open_month() const {

		return month;
	}

	//ゲッタ データメンバ 日を表示させる
	Type open_day() const {

		return day;
	}

	//今年がうるう年なのか判別します
	static bool leap_year(Type year) {

		return ( (year % 4 == 0) && (year % 100 != 0) ) || (year % 400 == 0);
	}

};
//抽出子 挿入子の定義
template <class Type>
inline std::ostream& operator << (std::ostream& stream,const Type& tmp) {

	//stream から西暦 月 日 の順番に表示を行います
	return stream << tmp.open_year() << tmp.open_month() << tmp.open_day();
}

//抽出子 挿入子の定義
template <>
inline std::ostream& operator << (std::ostream& stream,const Date<int>& tmp) {

	//stream から西暦 月 日 の順番に表示を行います
	return stream << tmp.open_year() << tmp.open_month() << tmp.open_day();;
}

template <class Type>
inline std::istream& operator >> (std::istream& stream,Type& tmp);

