/**
	All Rights Reserved,(c) JACIC 2001
	SXFExSymbol_checkC.cpp								�쐬���F2000.4.3

	�P�D�N���X�T�v
	����`�V���{���t�B�[�`���̃��[���`�F�b�N���s���N���X

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/

#include "stdafx.h"
#include "SXFExSymbol_checkC.h"
#include "SXFErrorMsgC.h"
#include "SXFTableManagerC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFExSymbol_checkC.cpp								�쐬���F2000.4.3

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void	SXFExSymbol_checkC::SXFExSymbol_checkC()
		
	����	�F	�^		������				���e
		�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/
SXFExSymbol_checkC::SXFExSymbol_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFExSymbol_checkC.cpp								�쐬���F2000.4.3

	�P�D�@�\�T�v
		�f�X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void	SXFExSymbol_checkC::~SXFExSymbol_checkC()
		
	����	�F	�^		������				���e
		�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/
SXFExSymbol_checkC::~SXFExSymbol_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFExSymbol_checkC.cpp								�쐬���F2000.4.3

	�P�D�@�\�T�v
		����`�V���{���t�B�[�`���̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int Feature_rule_check(Externally_Defined_Symbol_Struct IN_exsymbol_str,
							SXFTableManagerC* IN_TableManager,
							CString IN_InstanceID);

	����:	�^									������				���e
			Externally_Defined_Symbol_Struct	IN_exsymbol_str		����`�V���{���\����
			SXFTableManagerC*					IN_TableManager		��`�e�[�u���v�f�Ǘ��I�u�W�F�N�g
			CString								IN_InstanceID		�C���X�^���XID

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/
int SXFExSymbol_checkC::Feature_rule_check(Externally_Defined_Symbol_Struct* IN_exsymbol_str,
											SXFTableManagerC* IN_TableManager,
											CString IN_InstanceID)
{
	int ret;

	m_feature_name = DEF_EXTERNALLY_DEFINED_SYMBOL;
	m_TableManager = IN_TableManager;
	m_InstanceID = IN_InstanceID;
	ret = attr_rule_check(IN_exsymbol_str);
	if (ret < 0)
		return ret;

	ret = str_rule_check(IN_exsymbol_str);
	if (ret < 0)
		return ret;

	return 0;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFExSymbol_checkC.cpp								�쐬���F2000.4.3

	�P�D�@�\�T�v
		����`�V���{���t�B�[�`���̑����̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int attr_rule_check(Externally_Defined_Symbol IN_exsymbol_str);
	
	����:	�^									������				���e
			Externally_Defined_Symbol_Struct	IN_exsymbol_str		����`�V���{���\����
			
	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/
int SXFExSymbol_checkC::attr_rule_check(Externally_Defined_Symbol_Struct* IN_exsymbol_str)
{
	//�F�R�[�h�t���O��0�܂��͂P�ł͂Ȃ��Ƃ�
	if ((IN_exsymbol_str->color_flag < 0) || (IN_exsymbol_str->color_flag > 1)){
		SXFErrorMsgC::RecordError(SXFCOLORFLAG,
								m_feature_name,
								3,
								m_InstanceID,
								IN_exsymbol_str->color_flag,
								m_feature_name);
		return SXFCOLORFLAG;
	}
	m_layer = IN_exsymbol_str->layer;
	m_color = IN_exsymbol_str->color;
	int ret = ExSymbol_Check(IN_exsymbol_str->color_flag) ;
	return ret;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFExSymbol_checkC.cpp								�쐬���F2000.4.3

	�P�D�@�\�T�v
		����`�V���{���t�B�[�`���̑����ȊO�̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int str_rule_check(Externally_Defined_Symbol_Struct IN_exsymbol_str);

	����:	�^									������				���e
			Externally_Defined_Symbol_Struct	IN_exsymbol_str		����`�V���{���\����
			
	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/
int SXFExSymbol_checkC::str_rule_check(Externally_Defined_Symbol_Struct* IN_exsymbol_str)
{
	//��]�p���O�x����360�x�łȂ��Ƃ�
	if (angle_check(IN_exsymbol_str->rotate_angle) < 0){
		SXFErrorMsgC::RecordError(SXFERRORANGLE,
									m_feature_name,
									3,
									m_InstanceID,
									IN_exsymbol_str->rotate_angle,
									m_feature_name);
		return SXFERRORANGLE;
	}
	//�ړx���O�ȉ��̂Ƃ�
	if (double_check(IN_exsymbol_str->scale) < 0){
		SXFErrorMsgC::RecordError(SXFERRORSCALE,
									m_feature_name,
									3,
									m_InstanceID,
									IN_exsymbol_str->scale,
									m_feature_name);
		return SXFERRORSCALE;
	}
	return 0;
}
