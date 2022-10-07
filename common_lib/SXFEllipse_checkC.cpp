/**
	All Rights Reserved,(c) JACIC 2001
	SXFEllipse_checkC.cpp								�쐬���F2000.4.3

	�P�D�N���X�T�v
	�ȉ~�t�B�[�`���̃��[���`�F�b�N���s���N���X

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/

#include "stdafx.h"
#include "SXFEllipse_checkC.h"
#include "SXFErrorMsgC.h"
#include "SXFTableManagerC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFEllipse_checkC.cpp								�쐬���F2000.4.3

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void	SXFEllipse_checkC::SXFEllipse_checkC()
		
	����	�F	�^		������				���e
		�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/
SXFEllipse_checkC::SXFEllipse_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFEllipse_checkC.cpp								�쐬���F2000.4.3

	�P�D�@�\�T�v
		�f�X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void	SXFEllipse_checkC::~SXFEllipse_checkC()
		
	����	�F	�^		������				���e
		�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/
SXFEllipse_checkC::~SXFEllipse_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFEllipse_checkC.cpp								�쐬���F2000.4.3

	�P�D�@�\�T�v
		�ȉ~�t�B�[�`���̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int Feature_rule_check(Ellipse_Struct IN_ellipse_str,
							SXFTableManagerC* IN_TableManager,
							CString IN_InstanceID);

	����:	�^					������				���e
			Ellipse_Struct		IN_ellipse_str		�ȉ~�\����
			SXFTableManagerC*	IN_TableManager		��`�e�[�u���v�f�Ǘ��I�u�W�F�N�g
			CString				IN_InstanceID		�C���X�^���XID

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/
int SXFEllipse_checkC::Feature_rule_check(Ellipse_Struct* IN_ellipse_str,
										  SXFTableManagerC* IN_TableManager,
										  CString IN_InstanceID)
{
	int ret;

	m_feature_name = DEF_ELLIPSE;
	m_TableManager = IN_TableManager;
	m_InstanceID = IN_InstanceID;
	/** �����̃��[���`�F�b�N **/
	ret = attr_rule_check(IN_ellipse_str);
	if (ret < 0)
		return ret;
	/** �����ȊO�̃��[���`�F�b�N **/
	ret = str_rule_check(IN_ellipse_str);
	if (ret < 0)
		return ret;

	return 0;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFEllipse_checkC.cpp								�쐬���F2000.4.3

	�P�D�@�\�T�v
		�ȉ~�t�B�[�`���̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int attr_rule_check(Ellipse_Struct IN_ellipse_str);

	����:	�^					������				���e
			Ellipse_Struct		IN_ellipse_str		�ȉ~�\����
			
	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/
int SXFEllipse_checkC::attr_rule_check(Ellipse_Struct* IN_ellipse_str)
{
	m_layer = IN_ellipse_str->layer ;
	m_color = IN_ellipse_str->color ;
	m_type = IN_ellipse_str->type ;
	m_line_width = IN_ellipse_str->line_width ;

	int ret = LineFeature_Check() ;
	return ret ;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFEllipse_checkC.cpp								�쐬���F2000.4.3

	�P�D�@�\�T�v
		�ȉ~�t�B�[�`���̑����ȊO�̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int str_rule_check(Ellipse_Struct IN_ellipse_str);
	
	����:	�^					������				���e
			Ellipse_Struct		IN_ellipse_str		�ȉ~�\����
			
	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/
int SXFEllipse_checkC::str_rule_check(Ellipse_Struct* IN_ellipse_str)
{
	//X�������a���O�ȉ��̎�
	if (double_check(IN_ellipse_str->radius_x) < 0){
		SXFErrorMsgC::RecordError(SXFRADIUSZERO,
									m_feature_name,
									3,
									m_InstanceID,
									IN_ellipse_str->radius_x,
									m_feature_name) ;
		return SXFRADIUSZERO ;
	}	
	//Y�������a���O�ȉ��̎�
	if (double_check(IN_ellipse_str->radius_y) < 0){
		SXFErrorMsgC::RecordError(SXFRADIUSZERO,
									m_feature_name,
									3,
									m_InstanceID,
									IN_ellipse_str->radius_y,
									m_feature_name) ;
		return SXFRADIUSZERO ;
	}	
	//��]�p���O�x����360�x�łȂ��Ƃ�
	if (angle_check(IN_ellipse_str->rotation_angle) < 0){
		SXFErrorMsgC::RecordError(SXFERRORANGLE,
									m_feature_name,
									3,
									m_InstanceID,
									IN_ellipse_str->rotation_angle,
									m_feature_name);
		return SXFERRORANGLE;
	}
	return 0 ;
}
