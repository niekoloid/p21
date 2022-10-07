/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableUniqueCheckC.cpp								�쐬���F2000.4.17

	�P�D�N���X�T�v
		��`�e�[�u���v�f�̃��j�[�N�`�F�b�N���s��

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.17			�{��(FQS)			�Ȃ��B

**/

#include "stdafx.h"
#include "SXFTableUniqueCheckC.h"
#include "SXFTableManagerC.h"
#include "SXFErrorMsgC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableUniqueCheckC.cpp								�쐬���F2000.4.17

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void SXFTableUniqueCheckC::SXFTableUniqueCheckC()
		
	����	�F	�^		������				���e
		�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.17			�{��(FQS)			�Ȃ��B

**/
SXFTableUniqueCheckC::SXFTableUniqueCheckC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableUniqueCheckC.cpp								�쐬���F2000.4.17

	�P�D�@�\�T�v
		�f�X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void SXFTableUniqueCheckC::~SXFTableUniqueCheckC()
		
	����	�F	�^		������				���e
		�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.17			�{��(FQS)			�Ȃ��B

**/
SXFTableUniqueCheckC::~SXFTableUniqueCheckC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableUniqueCheckC.cpp								�쐬���F2000.4.17

	�P�D�@�\�T�v
		��`�e�[�u���v�f�̃��j�[�N�`�F�b�N

	�Q�D�C���^�[�t�F�[�X
		void SXFTableUniqueCheckC::NameUniqueCheck(int IN_TableType)
		
	����	�F	�^		������				���e
				int		IN_TableType		�e�[�u���^

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.17			�{��(FQS)			�Ȃ��B

**/
int SXFTableUniqueCheckC::NameUniqueCheck(int IN_TableType)
{
	int error_code = 0;

	//TableManager�̃��\�b�h���Ăяo���B
	switch(IN_TableType){
	case 1://layer
		if (!m_TableManager->CheckSameLayer(m_UniqueName)){
			SXFErrorMsgC::RecordError(SXFSAMENAME,
										m_feature_name,
										1,
										m_UniqueName);
			return SXFSAMENAME;
		}
		break;
	case 2://pre_color
		if (!m_TableManager->CheckSamePreDefColor(m_UniqueName)){
			SXFErrorMsgC::RecordError(SXFSAMENAME,
										m_feature_name,
										1,
										m_UniqueName);
			return SXFSAMENAME;
		}
		break;
	case 3://user_color
		break;
	case 4://pre_type
		if (!m_TableManager->CheckSamePreDefFont(m_UniqueName)){
			SXFErrorMsgC::RecordError(SXFSAMENAME,
										m_feature_name,
										1,
										m_UniqueName);
			return SXFSAMENAME;
		}
		break;
	case 5://user_type
		if (!m_TableManager->CheckSameUserDefFont(m_UniqueName)){
			SXFErrorMsgC::RecordError(SXFSAMENAME,
										m_feature_name,
										1,
										m_UniqueName);
			return SXFSAMENAME;
		}
		break;
	case 6://width
		if (!m_TableManager->CheckSameWidth(m_UniqueWidth)){
			SXFErrorMsgC::RecordError(SXFSAMEWIDTH,
										m_feature_name,
										1,
										m_UniqueWidth);
			return SXFSAMENAME;
		}
		break;
	case 7://text_font
		if (!m_TableManager->CheckSameTextFont(m_UniqueName)){
			SXFErrorMsgC::RecordError(SXFSAMENAME,
										m_feature_name,
										1,
										m_UniqueName);
			return SXFSAMENAME;
		}
		break;
	default:
		break;
	}
	return error_code;

}
