/*
���K1-2 �N���XDate �ł��肦�Ȃ����ɂ����������悤�ɂ��Ă�������

�쐬�� 2017�N5��15��

�쐬�� ���V�h��
*/

#ifndef CLASS_H_
#define CLASS_H_

#include<iostream>

//	1  2  3  4  5  6  7  8  9  10 11 12 ���̖���
const int dmax[] = {31,28,31,30,31,30,31,31,30,31,30,31};

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

	//�Q�b�^ �f�[�^�����o �N��\��������
	int open_year() const {

		return year;
	}

	//�Q�b�^ �f�[�^�����o ����\��������
	int open_month() const {

		return month;
	}

	//�Q�b�^ �f�[�^�����o ����\��������
	int open_day() const {

		return day;
	}

	//���N�����邤�N�Ȃ̂����ʂ��܂�
	static bool leap_year(int year) {

		return ( (year % 4 == 0) && (year % 100 != 0) ) || (year % 400 == 0);
	}

};
//���o�q �}���q�̒�`
std::ostream& operator << (std::ostream& stream,const Date& tmp);
std::istream& operator >> (std::istream& stream,Date& tmp);

#endif /* CLASS_H_ */
