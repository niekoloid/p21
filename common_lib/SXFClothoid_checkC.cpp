/**
	All Rights Reserved,(c) JACIC 2001
	SXFClothoid_checkC.cpp								�쐬���F2007.1.29

	�P�D�N���X�T�v
	�N���\�C�h�t�B�[�`���̃��[���`�F�b�N���s���N���X

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2007.1.29			����				�Ȃ��B

**/

#include "stdafx.h"
#include <math.h>
#include "SXFClothoid_checkC.h"
#include "SXFErrorMsgC.h"
#include "SXFTableManagerC.h"
#include "SXF_EXT.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFClothoid_checkC.cpp								�쐬���F2007.1.29

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void	SXFClothoid_checkC::SXFClothoid_checkC()
		
	����	�F	�^		������				���e
		�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2007.1.29			����				�Ȃ��B

**/
SXFClothoid_checkC::SXFClothoid_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFClothoid_checkC.cpp								�쐬���F2007.1.29

	�P�D�@�\�T�v
		�f�X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void	SXFClothoid_checkC::~SXFClothoid_checkC()
		
	����	�F	�^		������				���e
		�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2007.1.29			����				�Ȃ��B

**/
SXFClothoid_checkC::~SXFClothoid_checkC()
{

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFClothoid_checkC.cpp								�쐬���F2007.1.29

	�P�D�@�\�T�v
		�N���\�C�h�t�B�[�`���̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int Feature_rule_check(Clothoid_Struct IN_clothoid_str,
										 SXFTableManagerC* IN_TableManager,
										 int IN_AssemType,
										 CString IN_InstanceID)

	����:	�^					������				���e
			Clothoid_Struct		IN_clothoid_str		�X�v���C���\����
			SXFTableManagerC*	IN_TableManager		��`ð��يǗ���޼ު�Ă̱��ڽ
			int					IN_AssemType		�A�Z���u���^
			CString				IN_InstanceID		�C���X�^���XID

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2007.1.29			����				�Ȃ��B

**/
int SXFClothoid_checkC::Feature_rule_check(Clothoid_Struct* IN_clothoid_str,
										 SXFTableManagerC* IN_TableManager,
										 int IN_AssemType,
										 CString IN_InstanceID,
										 SXFComInfoC* IN_Info)
{
	int ret;
	m_feature_name = DEF_CLOTHOID;
	m_TableManager = IN_TableManager;
	m_InstanceID = IN_InstanceID;
	m_ComInfo = IN_Info;
	/** �����̃��[���`�F�b�N **/
	ret = attr_rule_check(IN_clothoid_str);
	if (ret < 0)
		return ret;
	/** �����ȊO�̃��[���`�F�b�N **/
	ret = clothoidstr_rule_check(IN_clothoid_str);
	if (ret < 0)
		return ret;
	return 0;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFClothoid_checkC.cpp								�쐬���F2007.1.29

	�P�D�@�\�T�v
		�N���\�C�h�t�B�[�`���̑����̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int attr_rule_check(Clothoid_Struct IN_clothoid_str);

	����:	�^				������				���e
			Clothoid_Struct	IN_clothoid_str		�N���\�C�h�\����
	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2007.1.29			����				�Ȃ��B

**/
int SXFClothoid_checkC::attr_rule_check(Clothoid_Struct* IN_clothoid_str)
{
	m_layer = IN_clothoid_str->layer ;
	m_color = IN_clothoid_str->color ;
	m_type = IN_clothoid_str->type ;
	m_line_width = IN_clothoid_str->line_width ;
	int ret = LineFeature_Check();
	return ret ;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFClothoid_checkC.cpp								�쐬���F2007.1.29

	�P�D�@�\�T�v
		�N���\�C�h�t�B�[�`���̑����ȊO�̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int clothoidstr_rule_check(Clothoid_Struct IN_clothoid_str)

	����:	�^						������				���e
			Clothoid_Struct			IN_clothoid_str		�N���\�C�h�\����

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2007.1.29			����				�Ȃ��B

**/
int SXFClothoid_checkC::clothoidstr_rule_check(Clothoid_Struct *IN_clothoid_str)
{
	///////////////////////////////////////
	//���e�덷�̎擾
	///////////////////////////////////////
	double eps,angle_eps;
	m_ComInfo->Get_Tolerance(eps,angle_eps);

	//�N���\�C�h�p�����[�^���K��͈͊O�̎�
	if (double_check(IN_clothoid_str->parameter) < 0){
		SXFErrorMsgC::RecordError(SXFCLOTHOIDPARA,
									m_feature_name,
									3,
									m_InstanceID,
									IN_clothoid_str->parameter,
									m_feature_name) ;
		return SXFCLOTHOIDPARA ;
	}

	//�����t���O���O�܂��͂P�ȊO�̂Ƃ�
	if ((IN_clothoid_str->direction < 0) || (IN_clothoid_str->direction > 1)){
		SXFErrorMsgC::RecordError(SXFDIRECTIONERROR,
									m_feature_name,
									3,
									m_InstanceID,
									IN_clothoid_str->direction,
									m_feature_name);
		return SXFDIRECTIONERROR;
	}

	//��]�p���O�x����360�x�łȂ��Ƃ�
	if (angle_check(IN_clothoid_str->angle) < 0){
		SXFErrorMsgC::RecordError(SXFERRORANGLE,
									m_feature_name,
									3,
									m_InstanceID,
									IN_clothoid_str->angle,
									m_feature_name);
		return SXFERRORANGLE;
	}

	//�J�n�Ȑ����ƏI���Ȑ������������Ƃ�
	double	length = fabs(IN_clothoid_str->end_length - IN_clothoid_str->start_length);
	if (length < eps){
		SXFErrorMsgC::RecordError(SXFLENGTHZERO,
									m_feature_name,
									3,
									m_InstanceID,
									length,
									m_feature_name);
		return SXFLENGTHZERO;
	}

	//�J�n�Ȑ������O�����̂Ƃ�
	if (IN_clothoid_str->start_length < 0){
		SXFErrorMsgC::RecordError(SXFCLOTHOIDLEN,
									m_feature_name,
									3,
									m_InstanceID,
									IN_clothoid_str->start_length,
									m_feature_name);
		return SXFCLOTHOIDLEN;
	}
	//�I���Ȑ������O�����̂Ƃ�
	if (IN_clothoid_str->end_length < 0){
		SXFErrorMsgC::RecordError(SXFCLOTHOIDLEN,
									m_feature_name,
									3,
									m_InstanceID,
									IN_clothoid_str->end_length,
									m_feature_name);
		return SXFCLOTHOIDLEN;
	}

	return 0 ;
}
