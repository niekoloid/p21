/**
	All Rights Reserved,(c)JACIC 2001
	SXFProj_checkC.h						�쐬���F2000.03.30

	�P�D�N���X�T�v
	�⏕���̃��[���`�F�b�N���s���N���X

	�Q�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.03.30	�ЎR(FQS)	�Ȃ��B
**/

#ifndef _SXFPROJ_CHECK_CLASS_
#define _SXFPROJ_CHECK_CLASS_

#include <afx.h>
#include "SXFCheckInfoC.h"
#include "SXFComFunctionC.h"

class SXFComInfoC;

class SXFProj_checkC:virtual public SXFCheckInfoC, public SXFComFunctionC
{
public :
//------------------------------------------------
//	�R���X�g���N�^
//------------------------------------------------
	SXFProj_checkC() ;
//------------------------------------------------
//	�f�X�g���N�^
//------------------------------------------------
	~SXFProj_checkC() ;
//------------------------------------------------
//	���[���`�F�b�N
//------------------------------------------------
	int proj_check(int IN_flg,			//�⏕���̗L���t���O(�O�F���A�P�F�L)
					double	IN_ho_x0,	//�⏕����_�w���W
					double	IN_ho_y0,	//�⏕����_�x���W
					double	IN_ho_x1,	//�⏕���n�_�w���W
					double	IN_ho_y1,	//�⏕���n�_�x���W
					double	IN_ho_x2,	//�⏕���I�_�w���W
					double	IN_ho_y2) ;	//�⏕���I�_�x���W

} ;
#endif