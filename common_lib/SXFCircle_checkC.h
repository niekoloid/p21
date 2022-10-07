/**
	All Rights Reserved,(c)JACIC 2001
	SXFCircleC.h						�쐬���F2000.03.29

	�P�D�N���X�T�v
	�~�t�B�[�`���̃��[���`�F�b�N���s���N���X

	�Q�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.03.29	�ЎR(FQS)	�Ȃ��B
**/

#ifndef _SXFCIRCLEC_check_CLASS_
#define _SXFCIRCLEC_check_CLASS_

#include <afx.h>
#include "SXFStruct.h"
#include "SXFTableCheckC.h"
#include "SXFComFunctionC.h"

class SXFTableManagerC;

class SXFCircle_checkC : virtual public SXFTableCheckC , public SXFComFunctionC
{
public :
//------------------------------------------------
//	�R���X�g���N�^
//------------------------------------------------
	SXFCircle_checkC() ;
//------------------------------------------------
//	�f�X�g���N�^
//------------------------------------------------
	~SXFCircle_checkC() ;
//------------------------------------------------
//	�������[���`�F�b�N
//------------------------------------------------
	int attr_rule_check(Circle_Struct* IN_circle_str);
//------------------------------------------------
//	�����ȊO�̃��[���`�F�b�N
//------------------------------------------------
	int circlestr_rule_check(Circle_Struct* IN_circle_str);
//------------------------------------------------
//	�\���̂��`�F�b�N����
//------------------------------------------------
	int Feature_rule_check(Circle_Struct* IN_circle_str,
							SXFTableManagerC* IN_TableManager,
							CString IN_InstanceID) ;
} ;

#endif