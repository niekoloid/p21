/**
	All Rights Reserved,(c) JACIC 2001
	SXFCcurveorg_checkC.cpp								�쐬���F2000.4.3

	�P�D�N���X�T�v
	�����Ȑ���`�t�B�[�`���̃��[���`�F�b�N���s���N���X

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/

#include "stdafx.h"
#include "SXFCcurveorg_checkC.h"
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
	SXFCcurveorg_checkC.cpp								�쐬���F2000.4.3

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void	SXFCcurveorg_checkC::SXFCcurveorg_checkC()
		
	����	�F	�^		������				���e
		�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/

SXFCcurveorg_checkC::SXFCcurveorg_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFCcurveorg_checkC.cpp								�쐬���F2000.4.3

	�P�D�@�\�T�v
		�f�X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void	SXFCcurveorg_checkC::~SXFCcurveorg_checkC()
		
	����	�F	�^		������				���e
		�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/
SXFCcurveorg_checkC::~SXFCcurveorg_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFCcurveorg_checkC.cpp								�쐬���F2000.4.3

	�P�D�@�\�T�v
		�����Ȑ���`�t�B�[�`���̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int Feature_rule_check(Ccurveorg_Struct IN_ccurveorg_str,
							SXFTableManagerC* IN_TableManager,
							CString IN_InstanceID);

	����:	�^				������			���e
			Ccurveorg_Struct	IN_ccurveorg_str	�����Ȑ���`�\����
			SXFTableManagerC*	IN_TableManager		��`�e�[�u���v�f�Ǘ��I�u�W�F�N�g
			CString				IN_InstanceID		�C���X�^���XID

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/
int SXFCcurveorg_checkC::Feature_rule_check(Ccurve_Org_Struct* IN_ccurveorg_str,
											SXFTableManagerC* IN_TableManager,
											CString IN_InstanceID)
{
	int ret;

	m_feature_name = DEF_COMPOSITE_CURVE_ORG;
	m_TableManager = IN_TableManager;
	m_InstanceID = IN_InstanceID;
	/** �����̃��[���`�F�b�N **/
	ret = attr_rule_check(IN_ccurveorg_str);
	if (ret < 0)
		return ret;
	/** �����ȊO�̃��[���`�F�b�N **/
	ret = str_rule_check(IN_ccurveorg_str);
	if (ret < 0)
		return ret;

	return 0;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFCcurveorg_checkC.cpp								�쐬���F2000.4.3

	�P�D�@�\�T�v
		�����Ȑ���`�t�B�[�`���̑����̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int attr_rule_check(Ccurveorg_Struct IN_ccurveorg_str);
	
	����:	�^					������				���e
			Ccurveorg_Struct	IN_ccurveorg_str	�����Ȑ���`�\����
			
	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/
int SXFCcurveorg_checkC::attr_rule_check(Ccurve_Org_Struct* IN_ccurveorg_str)
{
	m_color = IN_ccurveorg_str->color;
	m_type = IN_ccurveorg_str->type;
	m_line_width = IN_ccurveorg_str->line_width;
	int ret = CompCurveFeature_Check();
	return ret;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFCcurveorg_checkC.cpp								�쐬���F2000.4.3

	�P�D�@�\�T�v
		�����Ȑ���`�t�B�[�`���̑����ȊO�̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int str_rule_check(Ccurveorg_Struct IN_ccurveorg_str);
	
	����:	�^					������				���e
			Ccurveorg_Struct	IN_ccurveorg_str	�����Ȑ���`�\����
			
	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/
int SXFCcurveorg_checkC::str_rule_check(Ccurve_Org_Struct* IN_ccurveorg_str)
{
	//�\���^��\���t���O���O�܂��͂P�ȊO�̂Ƃ�
	if ((IN_ccurveorg_str->flag < 0) || (IN_ccurveorg_str->flag > 1)){
		SXFErrorMsgC::RecordError(SXFCURVEFLAG,
								m_feature_name,
								1,
								IN_ccurveorg_str->flag);
		return SXFCURVEFLAG;
	}
	return 0;
}
