/*
演習3-13 List 3-19 を変更し ユーザーが年月日の数値をすべての値を入力してからの判別に変えよ

作成日 2017年5月18日

作成者 平澤敬介
*/


#ifndef CLASS_H_
#define CLASS_H_

class SimpleDate{

	int y,m,d;		// 西暦 月 日 を与えるデータメンバを構築する

public:

	// コンストラクタ「
	SimpleDate(int yy = 1, int mm = 1, int dd = 1) :
		y(yy),m(mm),d(dd)
	{

	}


	//メンバ関数 データメンバの年を返却します
	//仮引数 無し
	//返却値 データメンバの年
	int year() const {

		return y;
	}

	//メンバ関数 データメンバの月を返却します
	//仮引数 無し
	//返却値 データメンバの月
	int month() const {

		return m;
	}

	//メンバ関数 データメンバの日を返却します
	//仮引数 無し
	//返却値 データメンバの日
	int day() const {

		return d;
	}

	//メンバ関数 データメンバの年を当てるために入力します
	//仮引数 mainからの年の入力値
	//返却値 データメンバとの差分

	int comp_year(int yy) const {

		return yy - y;
	}

	//メンバ関数 データメンバの月を当てるために入力します
	//仮引数 mainからの月の入力値
	//返却値 データメンバとの差分

	int comp_month(int mm) const {

		return mm - m;
	}

	//メンバ関数 データメンバの日を当てるために入力します
	//仮引数 mainからの日の入力値
	//返却値 データメンバとの差分

	int comp_day(int dd) const {

		return dd - d;
	}

};



#endif /* CLASS_H_ */
