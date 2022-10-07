/**
	All Rights Reserved,(c) JACIC 2001
	SXFUsertype_checkC.cpp								�쐬���F2000.4.3

	�P�D�N���X�T�v
	���[�U��`����t�B�[�`���̃��[���`�F�b�N���s���N���X

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/

#include "stdafx.h"
#include "SXFUsertype_checkC.h"
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
	SXFUsertype_checkC.cpp								�쐬���F2000.4.3

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void SXFUsertype_checkC::SXFUsertype_checkC()
		
	����	�F	�^		������				���e
		�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/
SXFUsertype_checkC::SXFUsertype_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFUsertype_checkC.cpp								�쐬���F2000.4.3

	�P�D�@�\�T�v
		�f�X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void SXFUsertype_checkC::~SXFUsertype_checkC()
		
	����	�F	�^		������				���e
		�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/
SXFUsertype_checkC::~SXFUsertype_checkC()
{

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFUsertype_checkC.cpp								�쐬���F2000.4.3

	�P�D�@�\�T�v
		���[�U��`����t�B�[�`���̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int Feature_rule_check(Userdefined_Linetype_Struct IN_usertype_str,
						   SXFTableManagerC* IN_TableManager,
						   SXFComInfoC* IN_ComInfo)

	����:	�^							������			���e
			Userdefined_Linetype_Struct	IN_usertype_str	���[�U��`����\����
		    SXFTableManagerC*			IN_TableManager	��`ð��يǗ���޼ު�Ă̱��ڽ
			SXFComInfoC*				IN_ComInfo		���ʏ���޼ު�Ă̱��ڽ

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/
int SXFUsertype_checkC::Feature_rule_check(Userdefined_Linetype_Struct* IN_usertype_str,
										   SXFTableManagerC* IN_TableManager,
										   SXFComInfoC* IN_ComInfo)
{
	int ret;
	m_feature_name = DEF_USERDEFINED_LINETYPE;
	m_TableManager = IN_TableManager;
	m_ComInfo = IN_ComInfo;
	//RW_FLAG
	int RW_Flag = -1;
	m_ComInfo->Get_RWFlag(RW_Flag);
	//WRITE(Read�ł͂��ł������ς�)
	if (RW_Flag == 1){
		m_UniqueName = IN_usertype_str->name;
		ret = NameUniqueCheck(5);
		if (ret < 0)
			return ret;
	}
	ret = str_rule_check(IN_usertype_str);
	return ret;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFUsertype_checkC.cpp								�쐬���F2000.4.3

	�P�D�@�\�T�v
		���[�U��`����t�B�[�`���̑����ȊO�̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int str_rule_check(Userdefined_Linetype_Struct IN_usertype_str)

	����:	�^								������				���e
			Userdefined_Linetype_Struct		IN_usertype_str		���[�U��`����\����

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/
int SXFUsertype_checkC::str_rule_check(Userdefined_Linetype_Struct* IN_usertype_str)
{
	//�Z�O�����g�����Q�̔{���łȂ��Ƃ�
	if ((IN_usertype_str->segment % 2) != 0){
		SXFErrorMsgC::RecordError(SXFSEGMENTERROR,
									m_feature_name,
									1,
									IN_usertype_str->segment);
		return SXFSEGMENTERROR;
	}
	//�Z�O�����g�����Q����W�łȂ��Ƃ�
	if ((IN_usertype_str->segment < MINSEGMENT) 
		|| (IN_usertype_str->segment > MAXSEGMENT)){
		SXFErrorMsgC::RecordError(SXFSEGMENTERROR,
									m_feature_name,
									1,
									IN_usertype_str->segment);
		return SXFSEGMENTERROR;
	}
	for (int i = 0; i < IN_usertype_str->segment ; i++){
		//�s�b�`���O�ȉ��̏ꍇ�B
		if (double_check(IN_usertype_str->pitch[i]) < 0){
			SXFErrorMsgC::RecordError(SXFPITCHERROR,
										m_feature_name,
										1,
										IN_usertype_str->pitch[i]);
			return SXFPITCHERROR;
		}
	}
	return 0;
}
