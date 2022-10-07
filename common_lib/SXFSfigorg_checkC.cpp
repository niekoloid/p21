/**
	All Rights Reserved,(c) JACIC 2001
	SXFSfigorg_checkC.cpp								�쐬���F2000.4.3

	�P�D�N���X�T�v
	�����}�`��`�t�B�[�`���̃��[���`�F�b�N���s���N���X

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/

#include "stdafx.h"
#include "SXFSfigorg_checkC.h"
#include "SXFErrorMsgC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFSfigorg_checkC.cpp								�쐬���F2000.4.3

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void SXFSfigorg_checkC::SXFSfigorg_checkC()
		
	����	�F	�^		������				���e
		�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/
SXFSfigorg_checkC::SXFSfigorg_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFSfigorg_checkC.cpp								�쐬���F2000.4.3

	�P�D�@�\�T�v
		�f�X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void SXFSfigorg_checkC::~SXFSfigorg_checkC()
		
	����	�F	�^		������				���e
		�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/
SXFSfigorg_checkC::~SXFSfigorg_checkC()
{

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFSfigorg_checkC.cpp								�쐬���F2000.4.3

	�P�D�@�\�T�v
		�����}�`��`�t�B�[�`���̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int Feature_rule_check(Sfigorg_Struct IN_sfigorg_str,
										  CString IN_InstanceID)

	����:	�^				������				���e
			Sfigorg_Struct	IN_sfigorg_str		�����}�`��`�\����
		    CString			IN_InstanceID		�C���X�^���XID

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/
int SXFSfigorg_checkC::Feature_rule_check(Sfigorg_Struct* IN_sfigorg_str,
										  CString IN_InstanceID)
{
	int ret;

	m_feature_name = DEF_SFIG_ORG;
	m_InstanceID = IN_InstanceID;
	ret = str_rule_check(IN_sfigorg_str);
	return ret;

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFSfigorg_checkC.cpp								�쐬���F2000.4.3

	�P�D�@�\�T�v
		�����}�`��`�t�B�[�`���̑����ȊO�̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int str_rule_check(Sfigorg_Struct IN_sfigorg_str);

	����:	�^					������				���e
			Sfigorg_Struct		IN_sfigorg_str		�����}�`��`�\����

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/
int SXFSfigorg_checkC::str_rule_check(Sfigorg_Struct* IN_sfigorg_str)
{
	if ((IN_sfigorg_str->flag < 1) || (IN_sfigorg_str->flag > 4)){
		SXFErrorMsgC::RecordError(SXFSFIGFLAG,
									m_feature_name,
									3,
									m_InstanceID,
									IN_sfigorg_str->flag,
									m_feature_name);
		return SXFSFIGFLAG;
	}
	return 0;
}
