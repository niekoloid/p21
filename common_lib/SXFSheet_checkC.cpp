/**
	All Rights Reserved,(c) JACIC 2001
	SXFSheet_checkC.cpp								�쐬���F2000.4.3

	�P�D�N���X�T�v
	�p���t�B�[�`���̃��[���`�F�b�N���s���N���X

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/

#include "stdafx.h"
#include "SXFSheet_checkC.h"
#include "SXFErrorMsgC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFSheet_checkC.cpp								�쐬���F2000.4.3

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void SXFSheet_checkC::SXFSheet_checkC()
		
	����	�F	�^		������				���e
		�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/
SXFSheet_checkC::SXFSheet_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFSheet_checkC.cpp								�쐬���F2000.4.3

	�P�D�@�\�T�v
		�f�X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void SXFSheet_checkC::~SXFSheet_checkC()
		
	����	�F	�^		������				���e
		�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/
SXFSheet_checkC::~SXFSheet_checkC()
{

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFSheet_checkC.cpp								�쐬���F2000.4.3

	�P�D�@�\�T�v
		�p���t�B�[�`���̑����ȊO�̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int str_rule_check(Sheet_Struct IN_sheet_str);

	����:	�^					������				���e
			Sheet_Struct		IN_sheet_str		�p���\����

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/
int SXFSheet_checkC::str_rule_check(Sheet_Struct* in_sheet_str)
{
	//�}�ʖ����ݒ肳��Ă��Ȃ��Ƃ�
	//���O�t�@�C���ɏo�͂���݂̂�
	//���[�j���O�Ƃ���B
	if (strlen(in_sheet_str->name) == 0){
		SXFErrorMsgC::RecordError(SXFNOTSETZNAME,
									m_feature_name,
									0);
	}
	//�p���T�C�Y��ʂ��O�`�S�܂��͂X�ł͂Ȃ��Ƃ�
	if ( (in_sheet_str->type < 0) || (in_sheet_str->type > 4) ){
		if (in_sheet_str->type != 9){
			SXFErrorMsgC::RecordError(SXFSHEETSIZE,
										m_feature_name,
										1,
										in_sheet_str->type);
			return SXFSHEETSIZE;
		}
	}
	//�p���T�C�Y��ʂ��X�Ŏ��R�p������,�c�����ݒ肳��ĂȂ��Ƃ�
	if (in_sheet_str->type == 9){
		if (in_sheet_str->x <= 0){
			SXFErrorMsgC::RecordError(SXFSHEETLENGTH,
										m_feature_name,
										1,
										in_sheet_str->x);
			return SXFSHEETLENGTH;
		}
		if (in_sheet_str->y <= 0){
			SXFErrorMsgC::RecordError(SXFSHEETLENGTH,
										m_feature_name,
										1,
										in_sheet_str->y);
			return SXFSHEETLENGTH;
		}
	}
	//�p���T�C�Y��ʂ��O�`�S�Ŏ��R�p������,�c�����ݒ肳��Ă���Ƃ�
	//���b�Z�[�W�̂݁B�}�C�i�X�͕Ԃ��Ȃ��B�i�G���[�ł͂Ȃ����[�j���O�Ƃ���j
	if ((in_sheet_str->type >= 0) && (in_sheet_str->type <= 4)){
		if (in_sheet_str->x > 0){
			SXFErrorMsgC::RecordError(SXFSHEETLENGTHWARNING,
										m_feature_name,
										1,
										in_sheet_str->x);
		}
		if (in_sheet_str->y > 0){
			SXFErrorMsgC::RecordError(SXFSHEETLENGTHWARNING,
										m_feature_name,
										1,
										in_sheet_str->y);
		}
	}

	//�p���T�C�Y��ʂ��X�ł͂Ȃ��A�c/���敪���O�܂��͂P�ł͂Ȃ��Ƃ�
	//�p���T�C�Y��ʂ��X�łȂ��Ƃ��A�c/���敪�͖���
	if (in_sheet_str->type != 9){
		if ((in_sheet_str->orient < 0) || (in_sheet_str->orient > 1)){
			SXFErrorMsgC::RecordError(SXFORIENTERROR,
										m_feature_name,
										1,
										in_sheet_str->orient);
			return SXFORIENTERROR;
		}
	}
	return 0;
	
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFSheet_checkC.cpp								�쐬���F2000.4.3

	�P�D�@�\�T�v
		�p���t�B�[�`���̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int Feature_rule_check(Sheet_Struct IN_sheet_str);

	����:	�^				������				���e
			Sheet_Struct	IN_sheet_str		�p���\����

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/
int SXFSheet_checkC::Feature_rule_check(Sheet_Struct* IN_sheet_str)
{
	int ret;

	m_feature_name = DEF_SHEET;

	ret = str_rule_check(IN_sheet_str);
	return ret;

}
