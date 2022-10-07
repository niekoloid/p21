/**
	All Rights Reserved,(c) JACIC 2001
	SXFText_String_checkC.cpp								�쐬���F2000.3.27

	�P�D�N���X�T�v
	�����v�f�t�B�[�`���̃��[���`�F�b�N���s���N���X

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.3.27			�{��(FQS)			�Ȃ��B

**/

#include "stdafx.h"
#include "SXFText_String_checkC.h"
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
	SXFText_String_checkC.cpp								�쐬���F2000.3.27

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void SXFText_String_checkC::SXFText_String_checkC()
		
	����	�F	�^		������				���e
		�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.3.27			�{��(FQS)			�Ȃ��B

**/
SXFText_String_checkC::SXFText_String_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFText_String_checkC.cpp								�쐬���F2000.3.27

	�P�D�@�\�T�v
		�f�X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void SXFText_String_checkC::~SXFText_String_checkC()
		
	����	�F	�^		������				���e
		�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.3.27			�{��(FQS)			�Ȃ��B

**/
SXFText_String_checkC::~SXFText_String_checkC()
{

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFText_String_checkC.cpp								�쐬���F2000.3.27

	�P�D�@�\�T�v
		�����v�f�t�B�[�`���̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int Feature_rule_check(Text_Struct IN_text_str,
						  SXFTableManagerC* IN_TableManager,
						  CString IN_InstanceID)

	����:	�^					������			���e
			Text_Struct			IN_text_str		�����v�f�\����
		    SXFTableManagerC*	IN_TableManager	��`ð��يǗ���޼ު�Ă̱��ڽ
			CString				IN_InstanceID	�C���X�^���XID
	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.3.27			�{��(FQS)			�Ȃ��B

**/
int SXFText_String_checkC::Feature_rule_check(Text_Struct* in_text_str,
											  SXFTableManagerC* IN_TableManager,
											  CString IN_InstanceID)
{
	int ret;

	m_feature_name = DEF_TEXT;
	m_TableManager = IN_TableManager;
	m_InstanceID = IN_InstanceID;
	ret = attr_rule_check(in_text_str);
	if (ret < 0)
		return ret;

	ret = textstr_rule_check(in_text_str);
	if (ret < 0)
		return ret;

	return 0;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFText_String_checkC.cpp								�쐬���F2000.3.27

	�P�D�@�\�T�v
		�����v�f�t�B�[�`���̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int attr_rule_check(Text_Struct IN_text_str);

	����:	�^					������				���e
			Text_Struct	IN_text_str			�����v�f�\����

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.3.27			�{��(FQS)			�Ȃ��B

**/
int SXFText_String_checkC::attr_rule_check(Text_Struct* in_text_str)
{
	//�e�[�u���̃��[���`�F�b�N
	m_layer = in_text_str->layer;
	m_color = in_text_str->color;
	m_font = in_text_str->font;
	int ret = TextFeature_Check();
	return ret;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFText_String_checkC.cpp								�쐬���F2000.3.27

	�P�D�@�\�T�v
		�����v�f�t�B�[�`���̑����ȊO�̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int textstr_rule_check(Text_Struct IN_text_str)

	����:	�^			������				���e
			Text_Struct	IN_text_str			�����v�f�\����

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.3.27			�{��(FQS)			�Ȃ��B

**/
int SXFText_String_checkC::textstr_rule_check(Text_Struct* in_text_str)
{
	//�����͈͍����K��͈͊O�̂Ƃ�
	if (double_check(in_text_str->height) < 0){
		SXFErrorMsgC::RecordError(
			SXFTEXTHEIGHT,//�G���[���b�Z�[�WNo
			m_feature_name,//�t�B�[�`����
			3,//���b�Z�[�W�̈����̌�
			m_InstanceID,//�C���X�^���XID
			in_text_str->height,//�����͈͍�
			m_feature_name//�G���[���b�Z�[�W�p�t�B�[�`����
			);
		return SXFTEXTHEIGHT;
	}
	//�����͈͕����K��͈͊O�̂Ƃ�
	if (double_check(in_text_str->width) < 0){
		SXFErrorMsgC::RecordError(
			SXFTEXTWIDTH,//�G���[���b�Z�[�WNo
			m_feature_name,//�t�B�[�`����
			3,//�G���[���b�Z�[�W�����̌�
			m_InstanceID,//�C���X�^���XID
			in_text_str->width,//�����͈͕�
			m_feature_name//�G���[���b�Z�[�W�p�t�B�[�`����
			);
		return SXFTEXTWIDTH;
	}
	//�����Ԋu���K��͈͊O�̂Ƃ�
	if (max_double_check(in_text_str->spc) < 0){
		SXFErrorMsgC::RecordError(
			SXFTEXTSPACE,//�G���[���b�Z�[�WNo
			m_feature_name,//�t�B�[�`����
			3,//�G���[���b�Z�[�W�̈����̌�
			m_InstanceID,//�C���X�^���XID
			in_text_str->spc,//�����Ԋu
			m_feature_name//�G���[���b�Z�[�W�p�t�B�[�`����
			);
		return SXFTEXTSPACE;
	}
	//��]�p��0�x����360�x�łȂ��Ƃ�
	if (angle_check(in_text_str->angle) < 0){
		SXFErrorMsgC::RecordError(
			SXFERRORANGLE,//�G���[���b�Z�[�WNo
			m_feature_name,//�t�B�[�`����
			3,//�G���[���b�Z�[�W�̈����̌�
			m_InstanceID,//�C���X�^���XID
			in_text_str->angle,//��]�p
			m_feature_name//�G���[���b�Z�[�W�p�t�B�[�`����
			);
		return SXFERRORANGLE;
	}
	//�X�����g�p�x��-85�x����85�x�łȂ��Ƃ�
	if (slant_check(in_text_str->slant) < 0){
		SXFErrorMsgC::RecordError(
			SXFERRORANGLE,//�G���[���b�Z�[�WNo
			m_feature_name,//�t�B�[�`����
			3,//�G���[���b�Z�[�W�̈����̌�
			m_InstanceID,//�C���X�^���XID
			in_text_str->slant,//�X�����g�p
			m_feature_name//�G���[���b�Z�[�W�p�t�B�[�`����
			);
		return SXFERRORANGLE;
	}
	//�����z�u��_���P����X�łȂ��Ƃ�
	if ((in_text_str->b_pnt < 1) || (in_text_str->b_pnt > 9)){
		SXFErrorMsgC::RecordError(
			SXFBPNTERROR,//�G���[���b�Z�[�WNO
			m_feature_name,//�t�B�[�`����
			3,//�G���[���b�Z�[�W�̈����̌�
			m_InstanceID,//�C���X�^���XID
			in_text_str->b_pnt,//�����z�u��_
			m_feature_name//�G���[���b�Z�[�W�p�t�B�[�`����
			);
		return SXFBPNTERROR;
	}
	//���������o���������P����Q�łȂ��Ƃ�
	if ((in_text_str->direct < 1) || (in_text_str->direct > 2)){
		SXFErrorMsgC::RecordError(
			SXFDIRECTERROR,//�G���[���b�Z�[�WNo
			m_feature_name,//�t�B�[�`����
			3,//�G���[���b�Z�[�W�̈����̌�
			m_InstanceID,//�C���X�^���XID
			in_text_str->direct,//���������o������
			m_feature_name//�G���[���b�Z�[�W�p�t�B�[�`����
			);
		return SXFDIRECTERROR;
	}
	return 0;

}
