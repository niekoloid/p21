/**
	All Rights Reserved,(c)JACIC 2001
	SXFLinearDim_checkC.h						�쐬���F2000.03.21

	�P�D�N���X�T�v
	�������@�t�B�[�`���̃��[���`�F�b�N���s���N���X

	�Q�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.03.21	�ЎR(FQS)	�Ȃ��B
**/

#ifndef _SXFLINEARDIM_CLASS_
#define _SXFLINEARDIM_CLASS_

#include <afx.h>
#include "SXFArrow_checkC.h"
#include "SXFProj_checkC.h"
#include "SXFTableCheckC.h"
#include "SXFStruct.h"
#include "SXFLine_checkC.h"
#include "SXFText_String_checkC.h"

class SXFComInfoC;

class SXFLinearDim_checkC : public SXFLine_checkC,
							public SXFProj_checkC ,
							public SXFArrow_checkC,
							public SXFText_String_checkC
{
public :
//------------------------------------------------
//	�R���X�g���N�^
//------------------------------------------------
	SXFLinearDim_checkC() ;
//------------------------------------------------
//	�f�X�g���N�^
//------------------------------------------------
	~SXFLinearDim_checkC() ;
//------------------------------------------------
//	�������[���`�F�b�N
//------------------------------------------------
	int attr_rule_check(LinearDim_Struct* IN_LinearDim_str); 
//------------------------------------------------
//	�����ȊO�̃��[���`�F�b�N
//------------------------------------------------
	int lineardim_check(LinearDim_Struct* IN_LinearDim_str);
//------------------------------------------------
//	�t���[�`���[���[���`�F�b�N
//------------------------------------------------
	int Feature_rule_check(LinearDim_Struct* IN_LinearDim_str,
							SXFTableManagerC* IN_TableManager,
							CString IN_InstanceID,
							SXFComInfoC* IN_Info) ;
} ;

#endif