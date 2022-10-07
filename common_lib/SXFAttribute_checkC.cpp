// SXFAttribute_checkC.cpp: SXFAttribute_checkC �N���X�̃C���v�������e�[�V����
//
//////////////////////////////////////////////////////////////////////
/**
	All Rights Reserved,(c) JACIC 2002
	SXFAttribute_checkC.cpp							�쐬���F2002.12.03

	�P�D�N���X�T�v
	�}�ʕ\�藓�t�B�[�`���̃��[���`�F�b�N���s���N���X

	�Q�D����
	����ԍ�		���t��			�S����				�T�v
	�쐬			2002.12.03		K.Naono(FQS)		Ver3.0�Ή�

**/

#include "stdafx.h"
#include "SXFAttribute_checkC.h"
#include "SXFErrorMsgC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//////////////////////////////////////////////////////////////////////
// �\�z/����
//////////////////////////////////////////////////////////////////////

/**
	All Rights Reserved,(c) JACIC 2002
	SXFAttribute_checkC.cpp							�쐬���F2002.12.03

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void	SXFAttribute_checkC::SXFAttribute_checkC()
		
	����	�F	�^						������						���e
		�Ȃ�

	�R�D����
	����ԍ�		���t��			�S����				�T�v
	�쐬			2002.12.03		K.Naono(FQS)		Ver3.0�Ή�

**/
SXFAttribute_checkC::SXFAttribute_checkC()
{

}

/**
	All Rights Reserved,(c) JACIC 2002
	SXFAttribute_checkC.cpp							�쐬���F2002.12.03

	�P�D�@�\�T�v
		�f�X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void	SXFAttribute_checkC::~SXFAttribute_checkC()
		
	����	�F	�^						������						���e
		�Ȃ�

	�R�D����
	����ԍ�		���t��			�S����				�T�v
	�쐬			2002.12.03		K.Naono(FQS)		Ver3.0�Ή�

**/
SXFAttribute_checkC::~SXFAttribute_checkC()
{

}

/**
	All Rights Reserved,(c) JACIC 2002
	SXFAttribute_checkC.cpp							�쐬���F2002.12.03

	�P�D�@�\�T�v
		�}�ʕ\�藓�t�B�[�`���̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int Feature_rule_check(
							Attribute_Struct*	IN_attribute_str,
							SXFTableManagerC*	IN_TableManager,
							CString				IN_InstanceID)

	����:	�^					������				���e
			Attribute_Struct*	IN_attribute_str	�}�ʕ\�藓�\����
  		    SXFTableManagerC*	IN_TableManager		��`ð��يǗ���޼ު�Ă̱��ڽ
		    CString				IN_InstanceID		�C���X�^���XID

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��			�S����				�T�v
	�쐬			2002.12.03		K.Naono(FQS)		Ver3.0�Ή�

**/
int SXFAttribute_checkC::Feature_rule_check(
						Attribute_Struct*	IN_attribute_str,
						SXFTableManagerC*	IN_TableManager,
						CString				IN_InstanceID)
{
	m_feature_name	= "ATTRIBUTE";
	m_TableManager	= IN_TableManager;
	m_InstanceID	= IN_InstanceID;

	int	ret = 0 ;

	/** �����̃��[���`�F�b�N **/
	if( (ret = attr_rule_check(IN_attribute_str)) < 0 ) {
		return ret;
	}

	/** �����ȊO�̃��[���`�F�b�N **/
	if( (ret = str_rule_check(IN_attribute_str)) < 0 ) {
		return ret;
	}

	return 0 ;
}

/**
	All Rights Reserved,(c) JACIC 2002
	SXFAttribute_checkC.cpp							�쐬���F2002.12.03

	�P�D�@�\�T�v
		�}�ʕ\�藓�t�B�[�`���̑����̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int attr_rule_check(
						Attribute_Struct*	IN_attribute_str)

	����:	�^					������				���e
			Attribute_Struct*	IN_attribute_str	�}�ʕ\�藓�\����

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��			�S����				�T�v
	�쐬			2002.12.03		K.Naono(FQS)		Ver3.0�Ή�

**/
int SXFAttribute_checkC::attr_rule_check(
						Attribute_Struct*	IN_attribute_str)
{
	if( IN_attribute_str->d_month < 1 || IN_attribute_str->d_month > 12 ) {
		SXFErrorMsgC::RecordError(SXFDATEERROR,
									m_feature_name,
									3,
									m_InstanceID,
									IN_attribute_str->d_month,
									m_feature_name);
		return SXFDATEERROR;
	}
	if( IN_attribute_str->d_day < 1 || IN_attribute_str->d_day > 31 ) {
		SXFErrorMsgC::RecordError(SXFDATEERROR,
									m_feature_name,
									3,
									m_InstanceID,
									IN_attribute_str->d_day,
									m_feature_name);
		return SXFDATEERROR;
	}

	return 0 ;
}

/**
	All Rights Reserved,(c) JACIC 2002
	SXFAttribute_checkC.cpp							�쐬���F2002.12.03

	�P�D�@�\�T�v
		�}�ʕ\�藓�t�B�[�`���̑����ȊO�̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int str_rule_check(
						Attribute_Struct*	IN_attribute_str)

	����:	�^					������				���e
			Attribute_Struct*	IN_attribute_str	�}�ʕ\�藓�\����

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��			�S����				�T�v
	�쐬			2002.12.03		K.Naono(FQS)		Ver3.0�Ή�

**/
int SXFAttribute_checkC::str_rule_check(
						Attribute_Struct*	IN_attribute_str)
{
	return 0 ;
}
