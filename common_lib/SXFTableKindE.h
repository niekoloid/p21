
/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapTableC.cpp						�쐬���F2000.04.21

	�P�D�@�\�T�v
		��`�e�[�u���̎�ʂ�ENUM�^�Œ�`����

		��`�e�[�u�����	
			1:���C��
			2:����`�F
			3:���[�U��`�F
			4:����`����
			5:���[�U��`����
			6:����
			7:�����t�H���g

	�Q�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.21	
**/

#ifndef _TABLEKIND_H_
#define	_TABLEKIND_H_

typedef enum TableType{
	E_LAYER = 1,	//1:���C��
	E_PRECOLOR,		//2:����`�F
	E_USERCOLOR,	//3:���[�U��`�F
	E_PREFONT,		//4:����`����
	E_USERFONT,		//5:���[�U��`����
	E_WIDTH,		//6:����
	E_TEXTFONT		//7:�����t�H���g
}TableKind;

#endif
