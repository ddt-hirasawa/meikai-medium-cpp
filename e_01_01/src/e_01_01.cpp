/*
���K1-1 �N���XHuman �̃R���X�g���N�^�����������A�R���X�g���N�^�������q�ōs���悤�ɕύX����

�쐬�� 2017�N5��15��

�쐬�� ���V�h��
*/

#include<iostream>
#include"class.h"

using namespace std;

//�֐��錾
void open(Human *ptr);

int main()
{
	//���V�h�� ���ł�
	Human keisuke("Hirasawa",173.5,65.5);

	//�֐��Ăяo������ �\������܂�
	open(&keisuke);

	return 0;
}

//�֐� �N���X�̃Q�b�^�����ɌĂяo���܂�
//������ �N���X�I�u�W�F�N�g �|�C���^���g���܂�
//�ԋp�l ����

void open(Human *ptr)
{
	//�N���X���̃Q�b�^�����ׂĕ\�������܂�
	cout << "���O : " << ptr -> open_name() << "\n"
			<< "�g�� : " << ptr -> open_height() << "cm\n"
			<< "�̏d : " << ptr -> open_weight() << "kg\n";
}

/*
 * �R���X�g���N�^�������q�ɂ��A���������s���N���X�̃f�[�^�����o�����܂�܂���
 */
