/**
	All Rights Reserved,(c) JACIC 2001
	SXFTextFont_checkC.cpp								�쐬���F2000.4.14

	�P�D�N���X�T�v
		�����t�H���g�t�B�[�`���̃��[���`�F�b�N���s��

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.14			�{��(FQS)			�Ȃ��B

**/

#include "stdafx.h"
#include "SXFTextFont_checkC.h"
#include "SXFTableManagerC.h"
#include "SXFComInfoC.h"
#include "SXFErrorMsgC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTextFont_checkC.cpp								�쐬���F2000.4.14

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void SXFTextFont_checkC::SXFTextFont_checkC()
		
	����	�F	�^		������				���e
		�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.14			�{��(FQS)			�Ȃ��B

**/
SXFTextFont_checkC::SXFTextFont_checkC()
{

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTextFont_checkC.cpp								�쐬���F2000.4.14

	�P�D�@�\�T�v
		�f�X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void SXFTextFont_checkC::~SXFTextFont_checkC()
		
	����	�F	�^		������				���e
		�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.14			�{��(FQS)			�Ȃ��B

**/
SXFTextFont_checkC::~SXFTextFont_checkC()
{

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTextFont_checkC.cpp								�쐬���F2000.4.14

	�P�D�@�\�T�v
		�����t�H���g�t�B�[�`���̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int SXFTextFont_checkC::Feature_rule_checkC(Text_Font_Struct *IN_Struct, 
												SXFTableManagerC *IN_TableManager,
												SXFComInfoC* IN_ComInfo)
		
	����	�F	�^					������				���e
				Text_Font_Struct*	IN_Struct			�����t�H���g�\����	
				SXFTableManagerC*	IN_TableManager		��`ð��يǗ���޼ު�Ă̱��ڽ
				SXFComInfoC*		IN_ComInfo			���ʏ���޼ު�Ă̱��ڽ

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.14			�{��(FQS)			�Ȃ��B

**/
int SXFTextFont_checkC::Feature_rule_checkC(Text_Font_Struct *IN_Struct, 
											SXFTableManagerC *IN_TableManager,
											SXFComInfoC* IN_ComInfo)
{
	int ret = 0;
	m_feature_name = DEF_TEXT_FONT;
	m_TableManager = IN_TableManager;
	//RW_FLAG
	int RW_Flag = -1;
	IN_ComInfo->Get_RWFlag(RW_Flag);
	//WRITE(Read�ł͂��ł������ς�)
	if (RW_Flag == 1){
		//�t�H���g���̒����O�̂Ƃ��̓G���[
		CString TextfontName = IN_Struct->name;
		if (TextfontName.GetLength() <= 0){
			SXFErrorMsgC::RecordError(SXFFONTNAMEERROR,m_feature_name,0);
			return SXFFONTNAMEERROR;
		}
		m_UniqueName = IN_Struct->name;
		ret = NameUniqueCheck(7);
	}
	return ret;
}
