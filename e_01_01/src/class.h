/*
���K1-1 �N���XHuman �̃R���X�g���N�^�����������A�R���X�g���N�^�������q�ōs���悤�ɕύX����

�쐬�� 2017�N5��15��

�쐬�� ���V�h��
*/

#ifndef CLASS_H_
#define CLASS_H_

#include<string>

//�N���X�l��
class Human {

	std::string full_name;			//���l�̖��O

	float height;					//�g��

	float weight;					//�̏d

public:

	//�R���X�g���N�^ ���K���� �R���X�g���N�^�������q
	Human(std::string name,float height_,float weight_) :
		full_name(name),height(height_),weight(weight_)
	{
		//�R���X�g���N�^���� ��
	}

	//�Q�b�^
	std::string open_name() const {

		//�����̖��O��\�����܂�
		return full_name;
	}

	//�Q�b�^
	float open_height() const {

		//�����̐g����\�����܂�
		return height;
	}

	//�Q�b�^
	float open_weight() const {

		//�����̐g����\�����܂�
		return weight;
	}
};



#endif /* CLASS_H_ */
