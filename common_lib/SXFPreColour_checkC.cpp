/**
	All Rights Reserved,(c) JACIC 2001
	SXFPreColour_checkC.cpp								�쐬���F2000.4.14

	�P�D�N���X�T�v
		����`�F�t�B�[�`���̃��[���`�F�b�N���s��

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.14			�{��(FQS)			�Ȃ��B

**/

#include "stdafx.h"
#include "SXFPreColour_checkC.h"
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
	SXFPreColour_checkC.cpp								�쐬���F2000.4.14

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void SXFPreColour_checkC::SXFPreColour_checkC()
		
	����	�F	�^						������						���e
		�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.14			�{��(FQS)			�Ȃ��B

**/
SXFPreColour_checkC::SXFPreColour_checkC()
{

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFPreColour_checkC.cpp								�쐬���F2000.4.14

	�P�D�@�\�T�v
		�f�X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void SXFPreColour_checkC::~SXFPreColour_checkC()
		
	����	�F	�^						������						���e
		�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.14			�{��(FQS)			�Ȃ��B

**/
SXFPreColour_checkC::~SXFPreColour_checkC()
{

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFPreColour_checkC.cpp								�쐬���F2000.4.14

	�P�D�@�\�T�v
		����`�F�t�B�[�`���̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int SXFPreColour_checkC::Feature_rule_check(Predefined_Colour_Struct *IN_Struct,
												SXFTableManagerC* IN_TableManager,
												SXFComInfoC* IN_ComInfo)

	����	�F	�^							������				���e
				Predefined_Colour_Struct*	IN_Struct			�\����	
				SXFTableManagerC*			IN_TableManager		��`ð��يǗ���޼ު�Ă̱��ڽ
				SXFComInfoC*				IN_ComInfo			���ʏ���޼ު�Ă̱��ڽ

  ���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.14			�{��(FQS)			�Ȃ��B

**/
int SXFPreColour_checkC::Feature_rule_check(Predefined_Colour_Struct *IN_Struct,
											SXFTableManagerC* IN_TableManager,
											SXFComInfoC* IN_ComInfo)
{
	int ret = 0;
	m_feature_name = DEF_PREDEFINED_COLOUR;
	m_TableManager = IN_TableManager;
	m_ComInfo = IN_ComInfo;
	//RW_FLAG
	int RW_Flag = -1;
	m_ComInfo->Get_RWFlag(RW_Flag);
	//WRITE(Read�ł͂��ł������ς�)
	if (RW_Flag == 1){
		m_UniqueName = IN_Struct->name;
		ret = NameUniqueCheck(2);
	}
	return ret;
}
