/**
	All Rights Reserved,(c)JACIC 2001
	SXFProj_checkC.cpp						�쐬���F2000.03.30

	�P�D�N���X�T�v
	�⏕���̃��[���`�F�b�N���s���N���X

	�Q�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.03.30	�ЎR(FQS)	�Ȃ��B
**/
#include "stdafx.h"
#include <math.h>
#include "SXFProj_checkC.h"
#include "SXFErrorMsgC.h"
#include "SXF_EXT.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFProj_checkC.cpp					 	�쐬���F2000.03.30

	�P�D�@�\�T�v 
		�R���X�g���N�^
		
	�Q�D�C���^�[�t�F�C�X
		void	SXFProj_checkC::SXFProj_checkC()		
		
	����	�F	�^		������				���e
		�Ȃ�

	���A�l	�F	�Ȃ�

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.03.30	�ЎR(FQS)	�Ȃ��B
**/
SXFProj_checkC::SXFProj_checkC()
{
}
/**
	All Rights Reserved,(c)JACIC 2001
	SXFProj_checkC.cpp					 	�쐬���F2000.03.30

	�P�D�@�\�T�v 
		�f�X�g���N�^
		
	�Q�D�C���^�[�t�F�C�X
		void	SXFProj_checkC::~SXFProj_checkC()		
		
	����	�F	�^		������				���e
		�Ȃ�

	���A�l	�F	�Ȃ�

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.03.30	�ЎR(FQS)	�Ȃ��B
**/
SXFProj_checkC::~SXFProj_checkC()
{
}
/**
	All Rights Reserved,(c)JACIC 2001
	SXFProj_checkC.cpp					 	�쐬���F2000.03.30

	�P�D�@�\�T�v 
		�⏕���̃��[���`�F�b�N
		
	�Q�D�C���^�[�t�F�C�X
		int proj_check(int IN_flg,
						double	IN_ho_x0,
						double	IN_ho_y0,
						double	IN_ho_x1,
						double	IN_ho_y1,
						double	IN_ho_x2,
						double	IN_ho_y2) ;

		
	����	�F	�^			������		���e
				int			IN_flg		�⏕���̗L���t���O(�O�F���A�P�F�L)
				double		IN_ho_x0	�⏕����_�w���W
				double		IN_ho_y0	�⏕����_�x���W
				double		IN_ho_x1	�⏕���n�_�w���W
				double		IN_ho_y1	�⏕���n�_�x���W
				double		IN_ho_x2	�⏕���I�_�w���W
				double		IN_ho_y2	�⏕���I�_�x���W


	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.03.30	�ЎR(FQS)	�Ȃ��B
**/
int SXFProj_checkC::proj_check(int IN_flg,
								double	IN_ho_x0,
								double	IN_ho_y0,
								double	IN_ho_x1,
								double	IN_ho_y1,
								double	IN_ho_x2,
								double	IN_ho_y2)
{
	double L1,L2;
	double xv1,yv1,xv2,yv2;
	double eps,eps2;
	m_ComInfo->Get_Tolerance(eps,eps2);

	//�⏕���̗L���t���O��0�܂���1�ȊO�̂Ƃ�
	if ((IN_flg < 0) || (IN_flg > 1)){
		SXFErrorMsgC::RecordError(SXFPRJFLAG,
									m_feature_name,
									3,
									m_InstanceID,
									IN_flg,
									m_feature_name);
		return SXFPRJFLAG;
	}
	if (IN_flg != 0){
		//�⏕���̎n�_����I�_�܂ł̒�����0�̂Ƃ��i���e�덷eps��菬�����Ƃ��j
		L1= calc_length(IN_ho_x1,IN_ho_y1,IN_ho_x2,IN_ho_y2);
		if (L1 < eps){
			SXFErrorMsgC::RecordError(SXFLENGTHZERO,
										m_feature_name,
										3,
										m_InstanceID,
										L1,
										m_feature_name);
			return SXFLENGTHZERO;
		}
		//�⏕���̊�_����I�_�܂ł̒���
		L2= calc_length(IN_ho_x0,IN_ho_y0,IN_ho_x2,IN_ho_y2);
		//�⏕���̎n�_�ƏI�_�̃x�N�g��
		xv1 = (IN_ho_x2 - IN_ho_x1) / L1;
		yv1 = (IN_ho_y2 - IN_ho_y1) / L1;
		//�⏕���̊�_�ƏI�_�̃x�N�g��
		xv2 = (IN_ho_x2 - IN_ho_x0) / L2;
		yv2 = (IN_ho_y2 - IN_ho_y0) / L2;
		//�⏕���̊�_�A�n�_�A�I�_�̍��W���꒼����ɂȂ��Ƃ�
		if (((fabs(xv2 - xv1)) >= eps) && ((fabs(yv2 - yv1)) >= eps)){
			SXFErrorMsgC::RecordError(SXFERRORCOORDINATE,
										m_feature_name,
										4,
										m_InstanceID,
										IN_ho_x1,
										IN_ho_y1,
										m_feature_name);
			return SXFERRORCOORDINATE;
		}
	}
	return 0;
}
