/**
	All Rights Reserved,(c) JACIC 2001
	SXFPreType_checkC.cpp								�쐬���F2000.4.14

	�P�D�N���X�T�v
		����`����t�B�[�`���̃��[���`�F�b�N���s��

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.14			�{��(FQS)			�Ȃ��B

**/

#include "stdafx.h"
#include "SXFPreType_checkC.h"
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
	SXFPreType_checkC.cpp								�쐬���F2000.4.14

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void	SXFPreType_checkC::SXFPreType_checkC()
		
	����	�F	�^		������				���e
		�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.14			�{��(FQS)			�Ȃ��B

**/
SXFPreType_checkC::SXFPreType_checkC()
{

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFPreType_checkC.cpp								�쐬���F2000.4.14

	�P�D�@�\�T�v
		�f�X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void	SXFPreType_checkC::~SXFPreType_checkC()
		
	����	�F	�^		������				���e
		�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.14			�{��(FQS)			�Ȃ��B

**/
SXFPreType_checkC::~SXFPreType_checkC()
{

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFPreType_checkC.cpp								�쐬���F2000.4.14

	�P�D�@�\�T�v
		����`����t�B�[�`���̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int SXFPreType_checkC::Feature_rule_check(Predefined_Linetype_Struct *IN_Struct,
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
int SXFPreType_checkC::Feature_rule_check(Predefined_Linetype_Struct *IN_Struct, 
										  SXFTableManagerC *IN_TableManager,
										  SXFComInfoC* IN_ComInfo)
{
	int ret = 0;

	m_feature_name = DEF_PREDEFINED_LINETYPE;
	m_TableManager = IN_TableManager;
	//
	//RW_FLAG
	int RW_Flag = -1;
	IN_ComInfo->Get_RWFlag(RW_Flag);
	//When WRITE
	if (RW_Flag == 1){
		m_UniqueName = IN_Struct->name;
		ret = NameUniqueCheck(4);
	}
	return ret;
}
