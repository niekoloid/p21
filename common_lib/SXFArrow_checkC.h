/**
	All Rights Reserved,(c)JACIC 2001
	SXFArrow_checkC.h						�쐬���F2000.03.30

	�P�D�N���X�T�v
	���̃��[���`�F�b�N���s���N���X

	�Q�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.03.30	�ЎR(FQS)	�Ȃ��B
**/

#ifndef _SXFARROW_CHECK_CLASS_
#define _SXFARROW_CHECK_CLASS_

#include <afx.h>
#include "SXFComFunctionC.h"
#include "SXFCheckInfoC.h"

class SXFArrow_checkC:public SXFComFunctionC,virtual public SXFCheckInfoC
{
public :
//------------------------------------------------
//	�R���X�g���N�^
//------------------------------------------------
	SXFArrow_checkC() ;
//------------------------------------------------
//	�f�X�g���N�^
//------------------------------------------------
	~SXFArrow_checkC() ;
//------------------------------------------------
//	���[���`�F�b�N
//------------------------------------------------
	int arr_check(int IN_arr_code1,int IN_arr_code2,double IN_arr_r) ;

} ;
#endif