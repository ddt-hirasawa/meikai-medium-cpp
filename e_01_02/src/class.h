/*
���K1-2 �N���XDate �ł��肦�Ȃ����ɂ����������悤�ɂ��Ă�������

�쐬�� 2017�N5��15��

�쐬�� ���V�h��
*/

#ifndef CLASS_H_
#define CLASS_H_

#include<iostream>

//�����N���X
class Date {
public:
	int year;		//�f�[�^�����o ����
	int month;		//�f�[�^�����o ��
	int day;		//�f�[�^�����o ��

public:

	//�f�t�H���g�R���X�g���N�^
	Date();

	//�R���X�g���N�^
	Date(int year_,int month_ = 1,int day_ = 1) :

		//�R���X�g���N�^�������q�ŏ��������܂�
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
