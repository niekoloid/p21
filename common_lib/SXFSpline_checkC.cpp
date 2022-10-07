/**
	All Rights Reserved,(c) JACIC 2001
	SXFSpline_checkC.cpp								�쐬���F2000.4.3

	�P�D�N���X�T�v
	�X�v���C���t�B�[�`���̃��[���`�F�b�N���s���N���X

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/

#include "stdafx.h"
#include "SXFSpline_checkC.h"
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
	SXFSpline_checkC.cpp								�쐬���F2000.4.3

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void SXFSpline_checkC::SXFSpline_checkC()
		
	����	�F	�^		������				���e
		�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/
SXFSpline_checkC::SXFSpline_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFSpline_checkC.cpp								�쐬���F2000.4.3

	�P�D�@�\�T�v
		�f�X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void SXFSpline_checkC::~SXFSpline_checkC()
		
	����	�F	�^		������				���e
		�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/
SXFSpline_checkC::~SXFSpline_checkC()
{

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFSpline_checkC.cpp								�쐬���F2000.4.3

	�P�D�@�\�T�v
		�X�v���C���t�B�[�`���̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int Feature_rule_check(Spline_Struct IN_spline_str,
										 SXFTableManagerC* IN_TableManager,
										 int IN_AssemType,
										 CString IN_InstanceID)

	����:	�^					������				���e
			Spline_Struct		IN_spline_str		�X�v���C���\����
			SXFTableManagerC*	IN_TableManager		��`ð��يǗ���޼ު�Ă̱��ڽ
			int					IN_AssemType		�A�Z���u���^
			CString				IN_InstanceID		�C���X�^���XID

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/
int SXFSpline_checkC::Feature_rule_check(Spline_Struct* IN_spline_str,
										 SXFTableManagerC* IN_TableManager,
										 int IN_AssemType,
										 CString IN_InstanceID)
{
	int ret;

	m_feature_name = DEF_SPLINE;
	m_TableManager = IN_TableManager;
	m_InstanceID = IN_InstanceID;
	/** �����Ȑ���ȊO�̗v�f�̂Ƃ� **/
	if (IN_AssemType != 3){
		/** �����̃��[���`�F�b�N **/
		ret = attr_rule_check(IN_spline_str);
		if (ret < 0)
			return ret;
	}
	/** �����ȊO�̃��[���`�F�b�N **/
	ret = str_rule_check(IN_spline_str);
	if (ret < 0)
		return ret;

	return 0;	
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFSpline_checkC.cpp								�쐬���F2000.4.3

	�P�D�@�\�T�v
		�X�v���C���t�B�[�`���̑����̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int attr_rule_check(Spline_Struct IN_spline_str);

	����:	�^					������				���e
			Spline_Struct		IN_spline_str		�X�v���C���\����

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/
int SXFSpline_checkC::attr_rule_check(Spline_Struct* IN_spline_str)
{
	m_layer = IN_spline_str->layer ;
	m_color = IN_spline_str->color ;
	m_type = IN_spline_str->type ;
	m_line_width = IN_spline_str->line_width ;

	int ret = LineFeature_Check() ;
	return ret ;

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFSpline_checkC.cpp								�쐬���F2000.4.3

	�P�D�@�\�T�v
		�X�v���C���t�B�[�`���̑����ȊO�̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int str_rule_check(Spline_Struct IN_spline_str);

	����:	�^					������				���e
			Spline_Struct		IN_spline_str		�X�v���C���\����

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/
int SXFSpline_checkC::str_rule_check(Spline_Struct* IN_spline_str)
{
	//�J�敪���O�A�P�ȊO
	if ((IN_spline_str->open_close < 0) || (IN_spline_str->open_close > 1)){
		SXFErrorMsgC::RecordError(SXFOPENCLOSEERROR,
									m_feature_name,
									3,
									m_InstanceID,
									IN_spline_str->open_close,
									m_feature_name);
		return SXFOPENCLOSEERROR;
	}
	//���_����4����
	if (IN_spline_str->number < 4){
		SXFErrorMsgC::RecordError(SXFVERTEXERRORSPLINE,
									m_feature_name,
									3,
									m_InstanceID,
									IN_spline_str->number,
									m_feature_name);
		return SXFVERTEXERRORSPLINE;
	}
	//���_�������W�̔z�񐔂����Ȃ��ꍇ�̓G���[
	if (IN_spline_str->number > IN_spline_str->x.GetSize()){
		SXFErrorMsgC::RecordError(SXFNOTVERTEXNUMBER,
									m_feature_name,
									3,
									m_InstanceID,
									IN_spline_str->number,
									m_feature_name);
		return SXFNOTVERTEXNUMBER;
	}
	if (IN_spline_str->number > IN_spline_str->y.GetSize()){
		SXFErrorMsgC::RecordError(SXFNOTVERTEXNUMBER,
									m_feature_name,
									3,
									m_InstanceID,
									IN_spline_str->number,
									m_feature_name);
		return SXFNOTVERTEXNUMBER;
	}
	return 0;
}
