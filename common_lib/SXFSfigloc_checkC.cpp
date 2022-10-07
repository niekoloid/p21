/**
	All Rights Reserved,(c) JACIC 2001
	SXFSfigloc_checkC.cpp								�쐬���F2000.4.3

	�P�D�N���X�T�v
	�����}�`�z�u�t�B�[�`���̃��[���`�F�b�N���s���N���X

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/

#include "stdafx.h"
#include "SXFSfigloc_checkC.h"
#include "SXFErrorMsgC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFSfigloc_checkC.cpp								�쐬���F2000.4.3

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void SXFSfigloc_checkC::SXFSfigloc_checkC()
		
	����	�F	�^		������				���e
		�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/
SXFSfigloc_checkC::SXFSfigloc_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFSfigloc_checkC.cpp								�쐬���F2000.4.3

	�P�D�@�\�T�v
		�f�X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void SXFSfigloc_checkC::~SXFSfigloc_checkC()
		
	����	�F	�^		������				���e
		�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/
SXFSfigloc_checkC::~SXFSfigloc_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFSfigloc_checkC.cpp								�쐬���F2000.4.3

	�P�D�@�\�T�v
		�����}�`�z�u�t�B�[�`���̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int Feature_rule_check(Sfigloc_Struct IN_sfigloc_str,
							SXFTableManagerC* IN_TableManager,
							CString IN_InstanceID)

	����:	�^					������				���e
			Sfigloc_Struct		IN_sfigloc_str		�����}�`�z�u�\����
		    SXFTableManagerC*	IN_TableManager		��`ð��يǗ���޼ު�Ă̱��ڽ
			CString				IN_InstanceID		�C���X�^���XID

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/
int SXFSfigloc_checkC::Feature_rule_check(Sfigloc_Struct* IN_sfigloc_str,
										  SXFTableManagerC* IN_TableManager,
										  CString IN_InstanceID)
{
	int ret;

	m_feature_name = DEF_SFIG_LOCATE;
	m_TableManager = IN_TableManager;
	m_InstanceID = IN_InstanceID;
	/** �����̃��[���`�F�b�N **/
	ret = attr_rule_check(IN_sfigloc_str);
	if (ret < 0)
		return ret;
	/** �����ȊO�̃��[���`�F�b�N **/
	ret = str_rule_check(IN_sfigloc_str);
	if (ret < 0)
		return ret;

	return 0;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFSfigloc_checkC.cpp								�쐬���F2000.4.3

	�P�D�@�\�T�v
		�����}�`�z�u�t�B�[�`���̑����̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int attr_rule_check(Sfigloc_Struct IN_sfigloc_str);

	����:	�^					������			���e
			Sfigloc_Struct		IN_sfigloc_str	�����}�`�z�u�\����

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/
int SXFSfigloc_checkC::attr_rule_check(Sfigloc_Struct* IN_sfigloc_str)
{
	m_layer = IN_sfigloc_str->layer;
	int ret = SfiglocFeature_Check() ;
	return ret ;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFSfigloc_checkC.cpp								�쐬���F2000.4.3

	�P�D�@�\�T�v
		�����}�`�z�u�t�B�[�`���̑����ȊO�̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int str_rule_check(Sfigloc_Struct IN_sfigloc_str);

	����:	�^					������			���e
			Sfigloc_Struct		IN_sfigloc_str	�����}�`�z�u�\����

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/
int SXFSfigloc_checkC::str_rule_check(Sfigloc_Struct* IN_sfigloc_str)
{
	//��]�p��0�x����360�x�łȂ��Ƃ�
	if (angle_check(IN_sfigloc_str->angle) < 0){
		SXFErrorMsgC::RecordError(SXFERRORANGLE,
									m_feature_name,
									3,
									m_InstanceID,
									IN_sfigloc_str->angle,
									m_feature_name);
		return SXFERRORANGLE;
	}
	//�ړx���O�ȉ��܂��͂P�O�̂P�T��ȏ�̂Ƃ�
	if (double_check(IN_sfigloc_str->ratio_x) < 0){
		SXFErrorMsgC::RecordError(SXFERRORSCALE,
									m_feature_name,
									3,
									m_InstanceID,
									IN_sfigloc_str->ratio_x,
									m_feature_name);
		return SXFERRORSCALE;
	}
	//�ړx���O�ȉ��܂��͂P�O�̂P�T��ȏ�̂Ƃ�
	if (double_check(IN_sfigloc_str->ratio_y) < 0){
		SXFErrorMsgC::RecordError(SXFERRORSCALE,
									m_feature_name,
									3,
									m_InstanceID,
									IN_sfigloc_str->ratio_y,
									m_feature_name);
		return SXFERRORSCALE;
	}
	return 0;
}
