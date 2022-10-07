/**
	All Rights Reserved,(c)JACIC 2001
	SXFCircle_checkC.cpp					�쐬���F2000.03.29

	�P�D�N���X�T�v
	�~�t�B�[�`���̃��[���`�F�b�N���s���N���X
	
	�Q�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.03.29	�ЎR(FQS)	�Ȃ��B
**/

#include "stdafx.h"
#include "SXFCircle_checkC.h"
#include "SXFErrorMsgC.h"
#include "max.h"
#include "SXFTableManagerC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFCircle_checkC.cpp					 	�쐬���F2000.03.29

	�P�D�@�\�T�v 
		�R���X�g���N�^
		
	�Q�D�C���^�[�t�F�C�X
		void	 SXFCircle_checkC::SXFCircle_checkC()
		
	����	�F	�^		������				���e
		�Ȃ�

	���A�l	�F	�Ȃ�

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.03.29	�ЎR(FQS)	�Ȃ��B
**/
SXFCircle_checkC::SXFCircle_checkC()
{
}
/**
	All Rights Reserved,(c)JACIC 2001
	SXFCircle_checkC.cpp						�쐬���F2000.03.29

	�P�D�@�\�T�v
		�f�X�g���N�^
		
	�Q�D�C���^�[�t�F�C�X
		void 	SXFCircle_checkC::~SXFCircle_checkC ()
		
	����	�F	�^		������				���e
		�Ȃ�

	���A�l	�F	�Ȃ�

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.03.29	�ЎR(FQS)	�Ȃ��B
**/
SXFCircle_checkC::~SXFCircle_checkC ()
{
}
/**
	All Rights Reserved,(c)JACIC 2001
	SXFCircle_checkC.cpp						�쐬���F2000.03.29

	�P�D�@�\�T�v
		�~�t�B�[�`���̑����̃��[���`�F�b�N
		
	�Q�D�C���^�[�t�F�C�X
		int 	SXFCircle_checkC::attr_rule_check (Circle_Struct IN_circle_str)
		
	�����F	�^				������				���e
			Circle_Struct	IN_circle_str		�~�̍\����
			
	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.03.29	�ЎR(FQS)	�Ȃ��B
**/
int SXFCircle_checkC::attr_rule_check (Circle_Struct* IN_circle_str)
{
	m_layer = IN_circle_str->layer ;
	m_color = IN_circle_str->color ;
	m_type = IN_circle_str->type ;
	m_line_width = IN_circle_str->line_width ;

	int ret = LineFeature_Check() ;
	return ret ;
}
/**
	All Rights Reserved,(c)JACIC 2001
	SXFCircle_checkC.cpp						�쐬���F2000.03.29

	�P�D�@�\�T�v
		�~�t�B�[�`���̑����ȊO�̃��[���`�F�b�N
		
	�Q�D�C���^�[�t�F�C�X
		int SXFCircle_checkC::circlestr_rule_check (Circle_Struct IN_circle_str)
		
	�����F	�^				������				���e
			Circle_Struct	IN_circle_str		�~�̍\����

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.03.29	�ЎR(FQS)	�Ȃ��B
**/
int SXFCircle_checkC::circlestr_rule_check (Circle_Struct* IN_circle_str)
{
	//���a���O�ȉ��̎�
	if (double_check(IN_circle_str->radius) < 0){
		SXFErrorMsgC::RecordError(SXFRADIUSZERO,
									m_feature_name,
									3,
									m_InstanceID,
									IN_circle_str->radius,
									m_feature_name) ;
		return SXFRADIUSZERO ;
	}
	return 0 ;
}
/**
	All Rights Reserved,(c)JACIC 2001
	SXFCircle_checkC.cpp						�쐬���F2000.03.29

	�P�D�@�\�T�v
		�~�t�B�[�`���̃��[���`�F�b�N
		
	�Q�D�C���^�[�t�F�C�X
		int SXFCircle_checkC::Feature_rule_check(
										Circle_Struct IN_circle_str,
										SXFTableManagerC* IN_TableManager,
										CString IN_InstanceID)
		
	�����F	�^					������				���e
			Circle_Struct		IN_circle_str		�~�̍\����
			SXFTableManagerC*	IN_TableManager		��`�e�[�u���v�f�Ǘ��I�u�W�F�N�g
			CString				IN_InstanceID		�C���X�^���XID

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.03.29	�ЎR(FQS)	�Ȃ��B
**/
int SXFCircle_checkC::Feature_rule_check(Circle_Struct* IN_circle_str,
										 SXFTableManagerC* IN_TableManager,
										 CString IN_InstanceID)
{
	int ret ;

	m_feature_name = DEF_CIRCLE;
	m_TableManager = IN_TableManager;
	m_InstanceID = IN_InstanceID;
	/** �����̃��[���`�F�b�N **/
	ret  = attr_rule_check(IN_circle_str) ;
	if (ret < 0)
		return ret ;
	/** �����ȊO�̃��[���`�F�b�N **/
	ret  = circlestr_rule_check(IN_circle_str) ;
	if (ret < 0)
		return ret ;

	return 0 ;
}
