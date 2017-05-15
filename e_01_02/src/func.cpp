/*
 ���K1-2 �N���XDate �ł��肦�Ȃ����ɂ����������悤�ɂ��Ă�������

 �쐬�� 2017�N5��15��

 �쐬�� ���V�h��
 */

#include<iostream>
#include"class.h"

using namespace std;

//�}���q ���݂̓��t��\�����܂�
ostream& operator <<(ostream& stream, const Date& tmp) {

	//stream ���琼�� �� �� �̏��Ԃɕ\�����s���܂�
	return stream << "����" << tmp.open_year() << "�N" << tmp.open_month() << "��"
			<< tmp.open_day() << "��\n";
}

//���o�q ���t����͂��f�[�^�����o�ɉ����܂�
istream& operator >>(istream& stream, Date& tmp) {

	//�����␳���ē��͂��s���܂�
	do {

		//�錾 1900�N�`2100�N�͈̔�
		std::cout << "1900����2100�N�܂�\n";
		std::cout << "���� : ";
		//�f�[�^�����o year ����͂��܂�
		stream >> tmp.year;

		//�͈͊O�̐���͎󂯕t���܂���
		if (tmp.year < 1900 || 2100 < tmp.year) {

			//�錾 �R���\�[���ɕ\�����Ĕ͈͓��̓��͂𑣂��܂�
			cout << "�͈͊O�ł�\n";
		}
		//�͈͊O�̏ꍇ�Ado���̏��߂ɖ߂�ŏ������蒼���܂�
	} while (tmp.year > 1900 && 2100 < tmp.year);

	//�錾 1���`12���͈̔�
	do {

		//�錾 1���`12���͈̔�
		std::cout << "1������12���܂�\n";
		std::cout << "���� : ";
		//�f�[�^�����o month ����͂��܂�
		stream >> tmp.month;

		//�͈͊O�̌��͎󂯕t���܂���
		if (tmp.month < 1 || 12 < tmp.month) {

			//�錾 �R���\�[���ɕ\�����Ĕ͈͓��̓��͂𑣂��܂�
			cout << "���̌��͂���܂���\n";
		}
		//�͈͊O�̏ꍇ�Ado���̏��߂ɖ߂�ŏ������蒼���܂�
	} while (tmp.month > 1 && 12 < tmp.month);

	int max_day = dmax[tmp.month - 1];		//�w�b�_�Œ�`���Ă��錎���Ƃ̖���
											//���i�[���Ă���z����g���܂�

	//2���͂��邤�N�ŉe�������邽�ߏ������s���܂�
	if (tmp.month == 2) {

		//���ɂ��A���邤�N�̎� true ���ԋp�����̂�
		if (tmp.leap_year(tmp.year)) {

			max_day++;						//1�������Ȃ�܂�
		}

	}
	//�錾 1���`���̌��̖����܂ł͈̔�
	do {

		//�錾 1���`���̌��̖����܂ł͈̔�
		std::cout << "1������" << max_day << "���܂�\n";
		std::cout << "���� : ";
		//�f�[�^�����o day ����͂��܂�
		stream >> tmp.day;

		//�͈͊O�̓��͎󂯕t���܂���
		if (tmp.day < 1 || max_day < tmp.day) {

			//�錾 �R���\�[���ɕ\�����Ĕ͈͓��̓��͂𑣂��܂�
			cout << "���̓��͂���܂���\n";
		}
	//�͈͊O�̏ꍇ�Ado���̏��߂ɖ߂�ŏ������蒼���܂�
	} while (tmp.day > 1 && max_day < tmp.day);

	return stream;
}
