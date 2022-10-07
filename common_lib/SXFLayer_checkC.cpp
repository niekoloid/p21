/**
	All Rights Reserved,(c) JACIC 2001
	SXFLayer_checkC.cpp								�쐬���F2000.4.3

	�P�D�N���X�T�v
	���C���t�B�[�`���̃��[���`�F�b�N���s���N���X

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/
#include "stdafx.h"
#include "SXFLayer_checkC.h"
#include "SXFErrorMsgC.h"
#include "SXFComInfoC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFLayer_checkC.cpp								�쐬���F2000.4.3

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void	SXFLayer_checkC::SXFLayer_checkC()
		
	����	�F	�^		������				���e
		�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/
SXFLayer_checkC::SXFLayer_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFLayer_checkC.cpp								�쐬���F2000.4.3

	�P�D�@�\�T�v
		�f�X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void	SXFLayer_checkC::~SXFLayer_checkC()
		
	����	�F	�^		������				���e
		�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/
SXFLayer_checkC::~SXFLayer_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFLayer_checkC.cpp								�쐬���F2000.4.3

	�P�D�@�\�T�v
		���C���t�B�[�`���̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int Feature_rule_check(Layer_Struct IN_layer_str,
							SXFTableManagerC* IN_TableManager,
							SXFComInfoC* IN_ComInfo)

	����:	�^					������				���e
			Layer_Struct		IN_layer_str		�p���\����
			SXFTableManagerC*	IN_TableManager		��`ð��يǗ���޼ު�Ă̱��ڽ
			SXFComInfoC*		IN_ComInfo			���ʏ���޼ު�Ă̱��ڽ

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/
int SXFLayer_checkC::Feature_rule_check(Layer_Struct* IN_layer_str,
										SXFTableManagerC* IN_TableManager,
										SXFComInfoC* IN_ComInfo)
{
	int ret;
	m_feature_name = DEF_LAYER;
	m_TableManager = IN_TableManager;
	m_ComInfo = IN_ComInfo;
	//Read or Write �t���O
	int RW_Flag = -1;
	m_ComInfo->Get_RWFlag(RW_Flag);
	//WRITE(Read�ł͂��ł������ς�)
	if (RW_Flag == 1){
		m_UniqueName = IN_layer_str->name;
		ret = NameUniqueCheck(1);
		if (ret < 0)
			return ret;
	}

	ret = str_rule_check(IN_layer_str);
	if (ret < 0)
		return ret;
	return ret;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFLayer_checkC.cpp								�쐬���F2000.4.3

	�P�D�@�\�T�v
		���C���t�B�[�`���̑����ȊO�̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int str_rule_check(Layer_Struct IN_layer_str);

	����:	�^					������				���e
			Layer_Struct		IN_layer_str		�p���\����

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/
int SXFLayer_checkC::str_rule_check(Layer_Struct* IN_layer_str)
{
	//���C�������w�肳��Ă��Ȃ��Ƃ�
	if (strlen(IN_layer_str->name) == 0){
		SXFErrorMsgC::RecordError(SXFNOTSETLNAME,m_feature_name,0);
		return SXFNOTSETLNAME;
	}
	//�\��/��\���t���O���O�܂��͂P�łȂ��Ƃ�
	if ((IN_layer_str->lflag < 0) || (IN_layer_str->lflag > 1)){
		SXFErrorMsgC::RecordError(SXFLAYERFLAG,
									m_feature_name,
									1,
									IN_layer_str->lflag);
		return SXFLAYERFLAG;
	}
	return 0;
}
