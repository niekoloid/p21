/**
	All Rights Reserved,(c) JACIC 2001
	SXFLine_checkC.cpp								�쐬���F2000.3.27

	�P�D�N���X�T�v
	�����t�B�[�`���̃��[���`�F�b�N���s���N���X

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.3.27			�{��(FQS)			�Ȃ��B

**/

#include "stdafx.h"
#include "SXFLine_checkC.h"
#include "SXFErrorMsgC.h"
#include "SXFTableManagerC.h"
#include "SXF_EXT.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFLine_checkC.cpp								�쐬���F2000.3.27

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void SXFLine_checkC::SXFLine_checkC()
		
	����	�F	�^		������				���e
		�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.3.27			�{��(FQS)			�Ȃ��B

**/
SXFLine_checkC::SXFLine_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFLine_checkC.cpp								�쐬���F2000.3.27

	�P�D�@�\�T�v
		�f�X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void SXFLine_checkC::~SXFLine_checkC()
		
	����	�F	�^		������				���e
		�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.3.27			�{��(FQS)			�Ȃ��B

**/
SXFLine_checkC::~SXFLine_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFLine_checkC.cpp								�쐬���F2000.3.27

	�P�D�@�\�T�v
		�����t�B�[�`���̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int Feature_rule_check(Line_Struct IN_line_str,
						   SXFTableManagerC* IN_TableManager,
						   CString IN_InstanceID,
							SXFComInfoC* IN_Info);

	����:	�^					������			���e
			Line_Struct			IN_line_str		�����\����
		    SXFTableManagerC*	IN_TableManager	��`ð��يǗ���޼ު�Ă̱��ڽ
            CString				IN_InstanceID	�C���X�^���XID
			SXFComInfoC*		IN_Info			���ʏ���޼ު�Ă̱��ڽ

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.3.27			�{��(FQS)			�Ȃ��B

**/
int SXFLine_checkC::Feature_rule_check(Line_Struct* IN_line_str,
									   SXFTableManagerC* IN_TableManager,
									   CString IN_InstanceID,
									   SXFComInfoC* IN_Info)
{
	int ret;

	m_feature_name = DEF_LINE;
	m_TableManager = IN_TableManager;
	m_InstanceID = IN_InstanceID;
	m_ComInfo = IN_Info;
	/** �����̃��[���`�F�b�N **/
	ret = attr_rule_check(IN_line_str);
	if (ret < 0)
		return ret;
	/** �����ȊO�̃��[���`�F�b�N **/
	ret = linestr_rule_check(IN_line_str);
	if (ret < 0)
		return ret;

	return 0;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFLine_checkC.cpp								�쐬���F2000.3.27

	�P�D�@�\�T�v
		�����t�B�[�`���̑����ȊO�̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int linestr_rule_check(Line_Struct IN_line_str)

	����:	�^					������				���e
			Line_Struct			IN_line_str			�����\����
	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.3.27			�{��(FQS)			�Ȃ��B

**/
int SXFLine_checkC::linestr_rule_check(Line_Struct* IN_line_str)
{
	/////////////////////////////
	//���e�덷�̎擾
	/////////////////////////////
	double tolerance1,tolerance2;
	m_ComInfo->Get_Tolerance(tolerance1,tolerance2);

	double length = calc_length(IN_line_str->start_x,
								IN_line_str->start_y,
								IN_line_str->end_x,
								IN_line_str->end_y);
	if (length < tolerance1){
		SXFErrorMsgC::RecordError(
			SXFLENGTHZERO,//�G���[���b�Z�[�WNO
			m_feature_name,//�t�B�[�`����
			3,//���b�Z�[�W�̈����̌�
			m_InstanceID,//�C���X�^���XID
			length,//�����̒���
			m_feature_name//���b�Z�[�W�p�t�B�[�`����
			);
		return SXFLENGTHZERO;
	}
	return 0;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFLine_checkC.cpp								�쐬���F2000.3.27

	�P�D�@�\�T�v
		�����t�B�[�`���̑����̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int attr_rule_check(Line_Struct IN_line_str);
	����:	�^					������				���e
			Line_Struct			IN_line_str			�����\����

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.3.27			�{��(FQS)			�Ȃ��B

**/
int SXFLine_checkC::attr_rule_check(Line_Struct* IN_line_str)
{
	//�e�[�u�����[���`�F�b�N
	m_layer = IN_line_str->layer;
	m_color = IN_line_str->color;
	m_type = IN_line_str->type;
	m_line_width = IN_line_str->line_width;
	int ret = LineFeature_Check();
	return ret;
}
