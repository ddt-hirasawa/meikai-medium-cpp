/*
 ���K2-4 �����Ȃ������̑� pos bit �` �� pos + n -1 �܂ł� n ���̃r�b�g��
 ���ꂼ�� 1 0 ���]�������l��Ԃ��֐��̍쐬

 �쐬�� 2017�N5��15��

 �쐬�� ���V�h��
 */

#include<iostream>
#include<math.h>

using namespace std;

//�֐� �w�肵��bit����n��bit��1�ɏ��������܂�
//������ �ϊ����鐮�� �w�肷��bit�̈ʒu �ϊ������
//�ԋp�l �ω�����������

unsigned set(unsigned tmp, int pos, int num) {

	//�w�肵��bit�̈ʒu���� n�� ���ׂĂP�ɕϊ����܂�
	for (int i = pos; i < pos + num; i++) {

		//���A���Ă���bit�� 1 �ł͂Ȃ��̂Ȃ�Ή��Z���s���܂�
		if (!(tmp >> i & 1U)) {

			tmp += pow(2, i);	//0 �� 1 �������܂� 2�̗ݏ悪 ����bit�� 1 �ɂȂ�
		}
	}
	return tmp;
}

//�֐� �w�肵��bit����n��bit��0�ɏ��������܂�
//������ �ϊ����鐮�� �w�肷��bit�̈ʒu �ϊ������
//�ԋp�l �ω�����������

unsigned reset(unsigned tmp, int pos, int num) {

	//�w�肵��bit�̈ʒu���� n�� ���ׂ�0�ɕϊ����܂�
	for (int i = pos; i < pos + num; i++) {

		//���A���Ă���bit�� 0 �ł͂Ȃ��̂Ȃ�Ή��Z���s���܂�
		if (tmp >> i & 1U) {

			tmp -= pow(2, i);	//1 ���� 1 �������܂� 2�̗ݏ悪 ����bit�� 1 �ɂȂ�
		}
	}
	return tmp;
}

//�֐� �w�肵��bit����n��bit�� 0 -> 1 �� 1 -> 0 �ɕϊ����܂�
//������ �ϊ����鐮�� �w�肷��bit�̈ʒu �ϊ������
//�ԋp�l �ω�����������

unsigned inverse(unsigned tmp, int pos, int num) {

	for (int i = pos; i < pos + num; i++) {

			//�ύX���镔���� 0 �̎��̉��Z����
			if (!(tmp >> i & 1U)) {

				tmp += pow(2, i);		//�w�肵�� bit �̕����� 1 �ɏ��������܂�

			//�ύX���镔���� 1 �̎��̉��Z����
			} else if(tmp >> i & 1U){

				tmp -= pow(2, i);		//�w�肵�� bit �̕����� 0 �ɏ��������܂�
			}
	}
	return tmp;
}
