/**
	All Rights Reserved,(c) JACIC 2001
	SXFFillHatching_checkC.cpp								�쐬���F2001.06.3

	�P�D�N���X�T�v
	�n�b�`���O�i���[�U��`�j�t�B�[�`���̃��[���`�F�b�N���s���N���X

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.3			���X��(FQS)			�Ȃ��B

**/
#include "stdafx.h"
#include "SXFFillHatching_checkC.h"
#include "SXFErrorMsgC.h"
#include "SXFTableManagerC.h"
#include "SXFWriteManagerC.h"
#include "SXFReadAP202ManagerC.h"
#include "SXFComInfoC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFFillHatching_checkC.cpp								�쐬���F2001.06.3

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void	SXFFillHatching_checkC::SXFFillHatching_checkC()
		
	����	�F	�^		������				���e
		�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.3			���X��(FQS)			�Ȃ��B

**/
SXFFillHatching_checkC::SXFFillHatching_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFFillHatching_checkC.cpp								�쐬���F2001.06.3

	�P�D�@�\�T�v
		�f�X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void	SXFFillHatching_checkC::~SXFFillHatching_checkC()
		
	����	�F	�^		������				���e
		�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.3			���X��(FQS)			�Ȃ��B

**/
SXFFillHatching_checkC::~SXFFillHatching_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFFillHatching_checkC.cpp								�쐬���F2001.06.3

	�P�D�@�\�T�v
		�n�b�`���O(���[�U��`)�t�B�[�`���̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int Feature_rule_check(FillHatching_Struct IN_fillhatching_str,
							SXFTableManagerC* IN_TableManager,
							SXFReadFeatureManagerC* IN_ReadFeatureManager,
							SXFWriteManagerC* IN_WriteManager,
							CString IN_InstanceID,
							SXFComInfoC* IN_Info);

	����:�^						������					���e
		FillHatching_Struct		IN_fillhatching_str	���[�U�n�b�`�\����
		SXFTableManagerC*		IN_TableManager		��`ð��ٗv�f�Ǘ���޼ު��
		SXFReadFeatureManagerC* IN_ReadFeatureManager	Read�Ǘ���޼ު��
		SXFWriteManagerC* 		IN_WriteManager		Write�Ǘ���޼ު��
		CString					IN_InstanceID		�C���X�^���XID
		SXFComInfoC*			IN_Info				���ʏ���޼ު��

  ���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.3			���X��(FQS)			�Ȃ��B

**/
int SXFFillHatching_checkC::Feature_rule_check(Fill_area_style_hatching_Struct* IN_fillhatching_str,
											   	SXFTableManagerC* IN_TableManager,
												SXFReadAP202ManagerC* IN_ReadAP202Manager,
												SXFWriteManagerC* IN_WriteManager,
											  	CString IN_InstanceID,
											  	SXFComInfoC* IN_Info)
{
	int ret;

	m_feature_name = DEF_FILL_AREA_STYLE_HATCHING;
	m_TableManager = IN_TableManager;
	m_ReadAP202Manager = IN_ReadAP202Manager;
	m_WriteManager = IN_WriteManager;
	m_InstanceID = IN_InstanceID;
	m_ComInfo = IN_Info;

	/** �����̃��[���`�F�b�N **/
	ret = attr_rule_check(IN_fillhatching_str);
	if (ret < 0)
		return ret;

	/** �����ȊO�̃��[���`�F�b�N **/
	ret = StructCheck(IN_fillhatching_str);
	if (ret < 0)
		return ret;

	int RW_Flag = -1;
	m_ComInfo->Get_RWFlag(RW_Flag);
	//READ
	if (RW_Flag == 0){
		ret = ReadAP202_Check(IN_fillhatching_str);
	}
	//WRITE
	else if (RW_Flag == 1){
		ret = str_rule_check(IN_fillhatching_str);
	}
	if (ret < 0)
		return ret;

	return 0;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFFillHatching_checkC.cpp								�쐬���F2001.06.3

	�P�D�@�\�T�v
		�n�b�`���O(���[�U��`)�t�B�[�`���̑����̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int attr_rule_check(FillHatching_Struct IN_fillhatching_str)
	
	����:	�^					������				���e
			FillHatching_Struct	IN_fillhatching_str	���[�U�n�b�`�\����
			
	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.3			���X��(FQS)			�Ȃ��B

**/
int SXFFillHatching_checkC::attr_rule_check(Fill_area_style_hatching_Struct* IN_fillhatching_str)
{
	int ret,num;
	m_layer = IN_fillhatching_str->layer;
	/* ʯ�ݸ�����ݐ� */
	/* ����ݐ���5���傫���ꍇ�A*/
	/* ���̐������������������s���̂ł����������� */
	num = IN_fillhatching_str->hatch_number;
	if (num > 4)
		num = 4;
	for (int i = 0; i < num ; i++){
		m_color = IN_fillhatching_str->hatch_color[i];
		m_type = IN_fillhatching_str->hatch_type[i];
		m_line_width = IN_fillhatching_str->hatch_line_width[i];
		ret = LineFeature_Check();
		if (ret < 0)
			return ret;
	}
	return 0;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFFillHatching_checkC.cpp								�쐬���F2001.06.3

	�P�D�@�\�T�v
		�n�b�`���O(���[�U��`)�t�B�[�`���̑����ȊO�̃��[���`�F�b�N(write)

	�Q�D�C���^�[�t�F�[�X
	int str_rule_check(FillHatching_Struct IN_fillhatching_str);
	
	����:	�^					������				���e
			FillHatching_Struct	IN_fillhatching_str	���[�U�n�b�`�\����
			
	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.3			���X��(FQS)			�Ȃ��B

**/
int SXFFillHatching_checkC::str_rule_check(Fill_area_style_hatching_Struct* IN_fillhatching_str)
{
	if (IN_fillhatching_str->number > IN_fillhatching_str->in_id.GetSize()){
		SXFErrorMsgC::RecordError(SXFNOTINIDNUMBER,
									m_feature_name,
									3,
									m_InstanceID,
									IN_fillhatching_str->number,
									m_feature_name);
		return SXFNOTINIDNUMBER;
	}
	//�O�`�̃t�B�[�`���R�[�h����`����Ă��Ȃ��l�̂Ƃ�
	if (!m_WriteManager->CheckHatchID(IN_fillhatching_str->out_id)){
		SXFErrorMsgC::RecordError(SXFERROROUTID,
									m_feature_name,
									3,
									m_InstanceID,
									IN_fillhatching_str->out_id,
									m_feature_name);
		return SXFERROROUTID;
	}
	//�������̕̈搔��0�����̂Ƃ�
	if (IN_fillhatching_str->number < 0){
		SXFErrorMsgC::RecordError(SXFERRORNUMBER,
									m_feature_name,
									3,
									m_InstanceID,
									IN_fillhatching_str->number,
									m_feature_name);
		return SXFERRORNUMBER;
	}
	//�������̃t�B�[�`���R�[�h����`����Ă��Ȃ��l�̂Ƃ�
	for (int i = 0; i < IN_fillhatching_str->number; i++){
		if (IN_fillhatching_str->in_id[i] == IN_fillhatching_str->out_id){
			SXFErrorMsgC::RecordError(SXFHATCHIDERROR,
										m_feature_name,
										3,
										m_InstanceID,
										IN_fillhatching_str->in_id[i],
										m_feature_name);
			return SXFHATCHIDERROR;
		}
		if (!m_WriteManager->CheckHatchID(IN_fillhatching_str->in_id[i])){
			SXFErrorMsgC::RecordError(SXFERRORINID,
										m_feature_name,
										3,
										m_InstanceID,
										IN_fillhatching_str->in_id[i],
										m_feature_name);
			return SXFERRORINID;
		}
	}
	return 0;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFFillHatching_checkC.cpp								�쐬���F2001.06.3

	�P�D�@�\�T�v
		�n�b�`���O(���[�U��`)�t�B�[�`���̑����ȊO�̃��[���`�F�b�N(read)

	�Q�D�C���^�[�t�F�[�X
	int ReadFeature_Check(FillHatching_Struct* IN_Struct);
	
	����:	�^						������		���e
			FillHatching_Struct*	IN_Struct	���[�U�n�b�`�\����
			
	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.3			���X��(FQS)			�Ȃ��B

**/
int SXFFillHatching_checkC::ReadAP202_Check(Fill_area_style_hatching_Struct *IN_Struct)
{
	//�O�`�̃t�B�[�`���R�[�h����`����Ă��Ȃ��l�̂Ƃ�
	if (!m_ReadAP202Manager->SymbolCodeCheck(IN_Struct->out_id)){
		SXFErrorMsgC::RecordError(SXFERROROUTID,
									m_feature_name,
									3,
									m_InstanceID,
									IN_Struct->out_id,
									m_feature_name);
		return SXFERROROUTID;
	}
	//�������̕̈搔��0�����̂Ƃ�
	if (IN_Struct->number < 0){
		SXFErrorMsgC::RecordError(SXFERRORNUMBER,
									m_feature_name,
									3,
									m_InstanceID,
									IN_Struct->number,
									m_feature_name);
		return SXFERRORNUMBER;
	}
	for (int i = 0; i < IN_Struct->number; i++){
		/* �O�`�ƒ�������ID�������� */
		if (IN_Struct->in_id[i] == IN_Struct->out_id){
			SXFErrorMsgC::RecordError(SXFHATCHIDERROR,
										m_feature_name,
										3,
										m_InstanceID,
										IN_Struct->in_id[i],
										m_feature_name);
			return SXFHATCHIDERROR;
		}
		//�������̃t�B�[�`���R�[�h����`����Ă��Ȃ��l�̂Ƃ�
		if (!m_ReadAP202Manager->SymbolCodeCheck(IN_Struct->in_id[i])){
			SXFErrorMsgC::RecordError(SXFERRORINID,
									m_feature_name,
									3,
									m_InstanceID,
									IN_Struct->in_id[i],
									m_feature_name);
			return SXFERRORINID;
		}
	}

	return 0;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFFillHatching_checkC.cpp								�쐬���F2001.06.3

	�P�D�@�\�T�v
		�n�b�`���O(���[�U��`)�t�B�[�`���̑����ȊO�̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int StructCheck(FillHatching_Struct* IN_Struct);
	
	����:	�^						������				���e
			FillHatching_Struct*	IN_Struct	���[�U�n�b�`�\����
			
	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.3			���X��(FQS)			�Ȃ��B

**/
int SXFFillHatching_checkC::StructCheck(Fill_area_style_hatching_Struct *IN_Struct) 
{
	/* �n�b�`���O���̃p�^�[�������͈͊O�̒l�̂Ƃ� 1 <= �� <= 4*/
	if (IN_Struct->hatch_number < 1 
		|| IN_Struct->hatch_number > 4){
		SXFErrorMsgC::RecordError(SXFERRORPATTERN,
								m_feature_name,
								3,
								m_InstanceID,
								IN_Struct->hatch_number,
								m_feature_name);
		return SXFERRORPATTERN;
	}

	for (int i = 0; i < IN_Struct->hatch_number; i++){
		if (double_check(IN_Struct->hatch_spacing[i]) < 0){
			SXFErrorMsgC::RecordError(SXFSPACING,
										m_feature_name,
										3,
										m_InstanceID,
										IN_Struct->hatch_spacing[i],
										m_feature_name) ;
			return SXFSPACING ;
		}
		if (angle_check(IN_Struct->hatch_angle[i]) < 0){
			SXFErrorMsgC::RecordError(SXFERRORANGLE,
										m_feature_name,
										3,
										m_InstanceID,
										IN_Struct->hatch_angle[i],
										m_feature_name);
			return SXFERRORANGLE;
		}
	}
	return 0;

}
