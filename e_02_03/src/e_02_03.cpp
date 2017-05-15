/*
���K2-3 �w�肵��bit �̒l�� 1 �ɂ���֐� 0 �ɂ���֐� ���]������֐� �����ꂼ��쐬����

�쐬�� 2017�N5��15��

�쐬�� ���V�h��
*/

#include<iostream>

using namespace std;
//�֐��錾
int count_bits(unsigned tmp);
int int_bits();
void print_bits(unsigned tmp, unsigned* sub);
int out_put(unsigned* tmp);
//���K�Ŏw������Ă���֐� func.cpp �ɂ܂Ƃ߂܂�
unsigned set(unsigned tmp,int pos);
unsigned reset(unsigned tmp,int pos);
unsigned inverse(unsigned tmp,int pos);

int main()
{
	unsigned tmp = 100;			//���̐��� ���̐����� bit ��������܂�
	unsigned tmp1;				//�֐� set �̒l��⊮���܂�
	unsigned tmp2;				//�֐� reset �̒l��⊮���܂�
	unsigned tmp3;				//�֐� inverse �̒l��⊮���܂�

	unsigned sub1[32] = {0};	//bit ��10�i���ɕϊ����邽�߂̔z��
	unsigned sub2[32] = {0};	//bit ��10�i���ɕϊ����邽�߂̔z�� �֐� set �̒l��⊮���܂�
	unsigned sub3[32] = {0};	//bit ��10�i���ɕϊ����邽�߂̔z�� �֐� reset �̒l��⊮���܂�
	unsigned sub4[32] = {0};	//bit ��10�i���ɕϊ����邽�߂̔z�� �֐� inverse �̒l��⊮���܂�

	//�錾 2�i���\�L
	cout << " tmp : ";

	//�֐��̌Ăяo������ 0 1 �̗����\��
	print_bits(tmp, sub1);

	//�m�F�̂��߁A�z��� 0 1 ����ׂĕ\�L���܂�
	for (int i = 31; i >= 0; i--) {

		// 0 1 �̒l��\����������
		cout << sub1[i];
	}
	//10�i���ɖ߂����l��\�����܂�
	cout << " 10�i�� : " << out_put(sub1);

	//��؂�܂�
	cout << "\n";

	tmp1 = set(tmp,2);

	//�錾 2�i���\�L
	cout << "tmp1 : ";

	//�֐��̌Ăяo������ 0 1 �̗����\��
	print_bits(tmp1, sub2);

	//�m�F�̂��߁A�z��� 0 1 ����ׂĕ\�L���܂�
	for (int i = 31; i >= 0; i--) {

		// 0 1 �̒l��\����������
		cout << sub2[i];
	}
	//10�i���ɖ߂����l��\�����܂�
	cout << " 10�i�� : " << out_put(sub2);

	//��؂�܂�
	cout << "\n";

	tmp2 = reset(tmp,2);

	//�錾 2�i���\�L
	cout << "tmp2 : ";

	//�֐��̌Ăяo������ 0 1 �̗����\��
	print_bits(tmp2, sub3);

	//�m�F�̂��߁A�z��� 0 1 ����ׂĕ\�L���܂�
	for (int i = 31; i >= 0; i--) {

		// 0 1 �̒l��\����������
		cout << sub3[i];
	}
	//10�i���ɖ߂����l��\�����܂�
	cout << " 10�i�� : " << out_put(sub3);

	//��؂�܂�
	cout << "\n";

	tmp3 = inverse(tmp,2);

	//�錾 2�i���\�L
	cout << "tmp3 : ";

	//�֐��̌Ăяo������ 0 1 �̗����\��
	print_bits(tmp3, sub4);

	//�m�F�̂��߁A�z��� 0 1 ����ׂĕ\�L���܂�
	for (int i = 31; i >= 0; i--) {

		// 0 1 �̒l��\����������
		cout << sub4[i];
	}
	//10�i���ɖ߂����l��\�����܂�
	cout << " 10�i�� : " << out_put(sub4);

	//��؂�܂�
	cout << "\n";

	return 0;
}

int count_bits(unsigned tmp) {

	int bits = 0;		//�J�E���^ bit �� 0 �� 1 0�ŏ������q�J�E���g���܂�

	const int one = 1;

	//�E�Ƀr�b�g���ړ����Ă����A0�ɂȂ�܂ŌJ��Ԃ��܂�
	while (tmp) {

		//�r�b�g�� 1 �̕������������Ƃ�
		if (tmp & 1U) {

			// 1 ������܂����B�J�E���g���܂�
			bits++;
		}

		//tmp ��bit ���E��1���炵�܂�
		tmp >>= one;
	}
	//�J�E���g����bit����ԋp���܂�
	return bits;
}


//�֐� int �^�̃r�b�g����\�����܂� �����̒��� 0 �� 1 �̌�
//������ ����
//�ԋp�l �����̂��ׂẴr�b�g��

int int_bits() {

	return count_bits(~0U);
}


//�֐� ���� tmp ��bit�\����\��
//������ ���ׂ������� tmp
//�ԋp�l ����

void print_bits(unsigned tmp, unsigned* sub) {

	int max = int_bits() - 1;		//�r�b�g�̌���ϐ��Ƃ��Ă��炢�܂��B
									//-1 �� ���l�� 0 �` 999 ��1000�ʂ�ƍl���邩��

	//�S�r�b�g�����������邽�߃��[�v���܂�
	for (; max >= 0; max--) {

		//�\������Ƃ��Abit �� 1 ���w���Ƃ� �R���\�[����1��\��
		sub[max] = ((tmp >> max) & 1U ? 1 : 0);
	}
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
