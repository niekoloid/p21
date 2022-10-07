/**
	All Rights Reserved,(c)JACIC 2001
	SXFArrow_checkC.cpp						�쐬���F2000.4.3

	�P�D�N���X�T�v
	���̃��[���`�F�b�N���s���N���X

	�Q�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.4.3	�ЎR(FQS)	�Ȃ��B
**/

#include "stdafx.h"
#include "SXFArrow_checkC.h"
#include "SXFErrorMsgC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFArrow_checkC.cpp					 	�쐬���F2000.03.30

	�P�D�@�\�T�v 
		�R���X�g���N�^
		
	�Q�D�C���^�[�t�F�C�X
		void	SXFArrow_checkC::SXFArrow_checkC()		
		
	����	�F	�^		������				���e
		�Ȃ�

	���A�l	�F	�Ȃ�

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.03.30	�ЎR(FQS)	�Ȃ��B
**/
SXFArrow_checkC::SXFArrow_checkC() 	
{
}
/**
	All Rights Reserved,(c)JACIC 2001
	SXFArrow_checkC.cpp					 	�쐬���F2000.03.30

	�P�D�@�\�T�v 
		�f�X�g���N�^
		
	�Q�D�C���^�[�t�F�C�X
		void	SXFArrow_checkC::~SXFArrow_checkC()		
		
	����	�F	�^		������				���e
		�Ȃ�

	���A�l	�F	�Ȃ�

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.03.30	�ЎR(FQS)	�Ȃ��B
**/
SXFArrow_checkC::~SXFArrow_checkC()
{
}
/**
	All Rights Reserved,(c)JACIC 2001
	SXFArrow_checkC.cpp					 	�쐬���F2000.03.30

	�P�D�@�\�T�v 
		���̃��[���`�F�b�N
		
	�Q�D�C���^�[�t�F�C�X
		int		 SXFArrow_checkC::arr_check(int IN_arr_code1,
											int IN_arr_code2,
											double IN_arr_r)
		
	����	�F	�^		������				���e
				int		IN_arr_code1		���R�[�h
				int		IN_arr_code2		�����O�R�[�h
				double	IN_arr_r			���{��

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.03.30	�ЎR(FQS)	�Ȃ��B
**/
int SXFArrow_checkC::arr_check(int IN_arr_code1,int IN_arr_code2,double IN_arr_r)
{

	//�����O�R�[�h��0����2�ȊO�̂Ƃ�
	if ((IN_arr_code2 < 0) || (IN_arr_code2 > 2)){
		SXFErrorMsgC::RecordError(SXFARRINOUTCODE,
									m_feature_name,
									3,
									m_InstanceID,
									IN_arr_code2,
									m_feature_name);
		return SXFARRINOUTCODE;
	}
	if (IN_arr_code2 != 0){
		//���R�[�h��1����11�ȊO�̂Ƃ�
		if ((IN_arr_code1 < 1) || (IN_arr_code1 >11)){
			SXFErrorMsgC::RecordError(SXFARRCODE,
										m_feature_name,
										3,
										m_InstanceID,
										IN_arr_code1,
										m_feature_name);
			return SXFARRCODE;
		}
		//���z�u�{�����K��͈͊O�̂Ƃ�
		if (double_check(IN_arr_r) < 0){
			SXFErrorMsgC::RecordError(SXFERRORSCALE,
										m_feature_name,
										3,
										m_InstanceID,
										IN_arr_r,
										m_feature_name);
			return SXFERRORSCALE;
		}
	}
	return 0 ;
}
