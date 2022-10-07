/**
	All Rights Reserved,(c) JACIC 2001
	SXFWidth_checkC.cpp							�쐬���F2000.4.14

	�P�D�N���X�T�v
		�����t�B�[�`���̃��[���`�F�b�N���s��

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.14			�{��(FQS)			�Ȃ��B

**/

#include "stdafx.h"
#include "SXFWidth_checkC.h"
#include "SXFErrorMsgC.h"
#include "SXFTableManagerC.h"
#include "SXFComInfoC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFWidth_checkC.cpp							�쐬���F2000.4.14

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void SXFWidth_checkC::SXFWidth_checkC()
		
	����	�F	�^		������				���e
		�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.14			�{��(FQS)			�Ȃ��B

**/
SXFWidth_checkC::SXFWidth_checkC()
{

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFWidth_checkC.cpp							�쐬���F2000.4.14

	�P�D�@�\�T�v
		�f�X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void SXFWidth_checkC::~SXFWidth_checkC()
		
	����	�F	�^		������				���e
		�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.14			�{��(FQS)			�Ȃ��B

**/
SXFWidth_checkC::~SXFWidth_checkC()
{

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFWidth_checkC.cpp							�쐬���F2000.4.14

	�P�D�@�\�T�v
		�����t�B�[�`���̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int SXFWidth_checkC::Feature_rule_check(Line_Width_Struct *IN_width_str,
											SXFTableManagerC* IN_TableManager,
											SXFComInfoC* IN_ComInfo)

	����	�F	�^					������			���e
				Line_Width_Struct*	IN_width_str	�����t�B�[�`���\����	
				SXFTableManagerC*	IN_TableManager	��`ð��يǗ���޼ު�Ă̱��ڽ
				SXFComInfoC*		IN_ComInfo		���ʏ���޼ު�Ă̱��ڽ

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.14			�{��(FQS)			�Ȃ��B

**/
int SXFWidth_checkC::Feature_rule_check(Line_Width_Struct *IN_width_str,
										SXFTableManagerC* IN_TableManager,
										SXFComInfoC* IN_ComInfo)
{
	int ret;
	m_feature_name = DEF_LINE_WIDTH;
	m_TableManager = IN_TableManager;
	m_ComInfo = IN_ComInfo;
	//RW_FLAG
	int RW_Flag = -1;
	m_ComInfo->Get_RWFlag(RW_Flag);
	//WRITE(Read�ł͂��ł������ς�)
	if (RW_Flag == 1){
		m_UniqueWidth = IN_width_str->width;
		ret = NameUniqueCheck(6);
		if (ret < 0)
			return ret;
	}
	ret = str_rule_check(IN_width_str);
	return ret;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFWidth_checkC.cpp							�쐬���F2000.4.14

	�P�D�@�\�T�v
		�����t�B�[�`���̑����ȊO�̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
		void SXFWidth_checkC::str_rule_check(Line_Width_Struct *IN_width_str)
		
	����	�F	�^					������			���e
				Line_Width_Struct*	IN_width_str	�����t�B�[�`���\����	

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.14			�{��(FQS)			�Ȃ��B

**/
int SXFWidth_checkC::str_rule_check(Line_Width_Struct *IN_width_str)
{
	if (double_check(IN_width_str->width) < 0){
		SXFErrorMsgC::RecordError(SXFWIDTHERROR,
								m_feature_name,
								1,
								IN_width_str->width);
		return SXFWIDTHERROR;
	}
	return 0;
}
