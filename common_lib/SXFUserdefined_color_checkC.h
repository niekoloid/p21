/**
	All Rights Reserved,(c)JACIC 2001
	SXFUserdefined_color_checkC.h						�쐬���F2000.03.21

	�P�D�N���X�T�v
	���[�U��`�F�t�B�[�`���̃��[���`�F�b�N���s���N���X

	�Q�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.03.21	�ЎR(FQS)	�Ȃ��B
**/

#ifndef _SXFCIRCLEC_CLASS_
#define _SXFCIRCLEC_CLASS_

#include <afx.h>
#include "SXFStruct.h"
#include "SXFCheckInfoC.h"

class SXFUserdefined_color_checkC :public SXFCheckInfoC
{
public :
//------------------------------------------------
//	�R���X�g���N�^
//------------------------------------------------
	SXFUserdefined_color_checkC() ;
//------------------------------------------------
//	�f�X�g���N�^
//------------------------------------------------
	~SXFUserdefined_color_checkC() ;
//------------------------------------------------
//	���[�U��`�F�t�B�[�`���̑����ȊO�̃��[���`�F�b�N
//------------------------------------------------
	int str_rule_check(Userdefined_Colour_Struct* IN_Userdefined_color_str);
//------------------------------------------------
//	���[�U��`�F�t�B�[�`���̃��[���`�F�b�N
//------------------------------------------------
	int Feature_rule_check(Userdefined_Colour_Struct* IN_Userdefined_color_str) ;
} ;

#endif