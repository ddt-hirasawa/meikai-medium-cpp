/*
���K1-2 �N���XDate �ł��肦�Ȃ����ɂ����������悤�ɂ��Ă�������

�쐬�� 2017�N5��15��

�쐬�� ���V�h��
*/

#include<iostream>
#include"class.h"

using namespace std;

//�}���q ���݂̓��t��\�����܂�
ostream& operator << (ostream& stream,const Date& tmp) {

	//stream ���琼�� �� �� �̏��Ԃɕ\�����s���܂�
	return stream << "����" << tmp.open_year() << "�N"
			<< tmp.open_month() << "��"
			<< tmp.open_day() << "��\n";
}

//���o�q ���t����͂��f�[�^�����o�ɉ����܂�
istream& operator >> (istream& stream,Date& tmp) {

	//�錾 1900�N�`2100�N�͈̔�
	std::cout << "���� : ";
	//�f�[�^�����o year ����͂��܂�
	stream >> tmp.year;
	//�錾 1���`12���͈̔�
	std::cout << "���� : ";
	//�f�[�^�����o month ����͂��܂�
	stream >> tmp.month;
	//�錾 1���`���̌��̖����܂ł͈̔�
	std::cout << "���� : ";
	//�f�[�^�����o day ����͂��܂�
	stream >> tmp.day;

	return stream;
}
