/*
 ���K2-2 �����Ȃ������̑S�r�b�g���E�� n bit��]�����l��Ԃ��֐��ƍ��� n bit ��]����
 �l��Ԃ��֐������ꂼ��쐬����

 �쐬�� 2017�N5��15��

 �쐬�� ���V�h��
 */

#include<iostream>
#include<math.h>

using namespace std;

//�֐� n bit �� �E�ɉ�]�����l��ԋp����
//������ ��]���鐮���Ɖ�bit��
//�ԋp�l ��]�����Ƃ��̒l

unsigned rrotate(unsigned tmp, int num) {

	//bit�����V�t�g���܂�
	for (int i = 0; i < num; i++) {

		//32�r�b�g�Ȃ̂ŁA�T����͈͂� 0 �` 31 �܂�
		//�擪�� bit �����Ȃ�� �_���ςɂ�� true �ɂȂ�
		if ((tmp >> 0) & 1U) {

			tmp >>= 1;		//�E�ւP�V�t�g

			tmp += pow(2,31);		//��ʃr�b�g�̂݁A�P�̒l�����Z����
									//unsigned�^�� 32 bit �ł���ʂ�bit�� 2 ��31��ł�
		//�擪��bit ��1�ȊO�Ȃ��
		} else {

			tmp >>= 1;		//�E�ւP�V�t�g
		}
	}
	return tmp;
}


//�֐� n bit �� ���ɉ�]�����l��ԋp����
//������ ��]���鐮���Ɖ�bit��
//�ԋp�l ��]�����Ƃ��̒l

unsigned lrotate(unsigned tmp, int num) {

	//bit�����V�t�g���܂�
	for (int i = 0; i < num; i++) {

		//32�r�b�g�Ȃ̂ŁA�T����͈͂� 0 �` 31 �܂�
		//�擪�� bit �����Ȃ�� �_���ςɂ�� true �ɂȂ�
		if ((tmp >> 31) & 1U) {

			tmp <<= 1;		//���ւP�V�t�g

			tmp += 1U;		//���ʃr�b�g�̂݁A�P�̒l�����Z����
		//�擪��bit ��1�ȊO�Ȃ��
		} else {

			tmp <<= 1;		//���ւP�V�t�g
		}
	}
	return tmp;
}

//�֐� 2�i����10�i���ɕϊ����܂�
//������ 0 1 �̗��񂪓������z��
//�ԋp�l 10�i���ɕϊ������l

int out_put(unsigned* tmp) {

	int answer = 0;			//�ԋp����10�i���̒l
	int ex = 1;				//2�ׂ̂����\�����邽�߂̕ϐ�

//���ɁA16bit �܂ł�ϊ��ΏۂƂ��܂�
	for (int i = 0; i < 32; i++) {

		answer += *(tmp + i) * ex;	//�ԋp����l�́A�z��̒l��1��
									//�����̓Y����2�ׂ̂�������Z���Ă���

		ex *= 2;					//2�����[�v���ɐώZ���āA���Z�Ɏg���܂�
	}
	return answer;
}
