/*
 ���K2-3 �w�肵��bit �̒l�� 1 �ɂ���֐� 0 �ɂ���֐� ���]������֐� �����ꂼ��쐬����

 �쐬�� 2017�N5��15��

 �쐬�� ���V�h��
 */

#include<iostream>
#include<math.h>

using namespace std;

//�֐� �w�肵���r�b�g�� 1 �ɂ���
//������ �ϊ����鐮�� 1 �ɂ���r�b�g�̏ꏊ
//�ԋp�l �ϊ���������

unsigned set(unsigned tmp, int pos) {

	//�w�肳�ꂽ bit �̈ʒu�� 32bit ���Ȃ��̎�����������
	//�s���܂�
	if (0 <= pos && pos < 32) {

		//�ύX���镔���� 0 �̎��̂ݏ����������s���܂�
		if (!(tmp >> pos & 1U)) {

			tmp += pow(2, pos);		//�w�肵�� bit �̕����� 1 �ɏ��������܂�
		}
	}
	return tmp;
}

//�֐� �w�肵���r�b�g�� 0 �ɂ���
//������ �ϊ����鐮�� 0 �ɂ���r�b�g�̏ꏊ
//�ԋp�l �ϊ���������

unsigned reset(unsigned tmp,int pos) {

	//�w�肳�ꂽ bit �̈ʒu�� 32bit ���Ȃ��̎�����������
	//�s���܂�
	if (0 <= pos && pos < 32) {

		//�ύX���镔���� 1 �̎��̂ݏ����������s���܂�
		if (tmp >> pos & 1U) {

			tmp -= pow(2, pos);		//�w�肵�� bit �̕����� 0 �ɏ��������܂�
		}
	}
	return tmp;
}

//�֐� �w�肵���r�b�g�� 0 1 �𔽓]����
//������ �ϊ����鐮�� ���]����r�b�g�̏ꏊ
//�ԋp�l �ϊ���������

unsigned inverse(unsigned tmp,int pos) {

	//�w�肳�ꂽ bit �̈ʒu�� 32bit ���Ȃ��̎�����������
	//�s���܂�
	if (0 <= pos && pos < 32) {

		//�ύX���镔���� 0 �̎��̉��Z����
		if (!(tmp >> pos & 1U)) {

			tmp += pow(2, pos);		//�w�肵�� bit �̕����� 1 �ɏ��������܂�

		//�ύX���镔���� 1 �̎��̉��Z����
		} else {

			tmp -= pow(2, pos);		//�w�肵�� bit �̕����� 0 �ɏ��������܂�
		}
	}
	return tmp;
}
