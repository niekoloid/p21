/**
	All Rights Reserved,(c) JACIC 2001
	SXFFillColour_checkC.cpp								�쐬���F2001.06.3

	�P�D�N���X�T�v
	�n�b�`���O�i�h��j�t�B�[�`���̃��[���`�F�b�N���s���N���X

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.3			���X��(FQS)			�Ȃ��B

**/

#include "stdafx.h"
#include "SXFFillColour_checkC.h"
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
	SXFFillColour_checkC.cpp								�쐬���F2001.06.3

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void	SXFFillColour_checkC::SXFFillColour_checkC()
		
	����	�F	�^		������				���e
		�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.3			���X��(FQS)			�Ȃ��B

**/
SXFFillColour_checkC::SXFFillColour_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFFillColour_checkC.cpp								�쐬���F2001.06.3

	�P�D�@�\�T�v
		�f�X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void	SXFFillColour_checkC::~SXFFillColour_checkC()
		
	����	�F	�^		������				���e
		�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.3			���X��(FQS)			�Ȃ��B

**/
SXFFillColour_checkC::~SXFFillColour_checkC()
{

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFFillColour_checkC.cpp								�쐬���F2001.06.3

	�P�D�@�\�T�v
		�n�b�`���O(�h��)�t�B�[�`���̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int Feature_rule_check(FillColour_Struct IN_fillcolour_str);
								SXFTableManagerC* IN_TableManager,
								SXFReadFeatureManagerC* IN_ReadFeatureManager,
								SXFWriteManagerC* IN_WriteManager,
								CString IN_InstanceID,
								SXFComInfoC* IN_Info);

	����:	�^						������					���e
			FillColour_Struct		IN_fillcolour_str		�n�b�`�i�h��j�\����
			SXFTableManagerC*		IN_TableManager			��`ð��يǗ���޼ު�Ă̱��ڽ
			SXFReadFeatureManagerC* IN_ReadFeatureManager	Read�Ǘ���޼ު�Ă̱��ڽ
			SXFWriteManagerC* 		IN_WriteManager			Write�Ǘ���޼ު�Ă̱��ڽ
			CString					IN_InstanceID			�C���X�^���XID
			SXFComInfoC*			IN_Info					���ʏ���޼ު�Ă̱��ڽ

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.3			���X��(FQS)			�Ȃ��B

**/
int SXFFillColour_checkC::Feature_rule_check(Fill_area_style_colour_Struct* IN_fillcolour_str,
											SXFTableManagerC* IN_TableManager,
											SXFReadAP202ManagerC* IN_ReadAP202Manager,
											SXFWriteManagerC* IN_WriteManager,
										  	CString IN_InstanceID,
										  	SXFComInfoC* IN_Info)
{
	int ret;

	m_feature_name = DEF_FILL_AREA_STYLE_COLOUR;
	m_TableManager = IN_TableManager;
	m_ReadAP202Manager = IN_ReadAP202Manager;
	m_WriteManager = IN_WriteManager;
	m_InstanceID = IN_InstanceID;
	m_ComInfo = IN_Info;
	/** �����̃��[���`�F�b�N **/
	ret = attr_rule_check(IN_fillcolour_str);
	if (ret < 0)
		return ret;
	int RW_Flag = -1;
	m_ComInfo->Get_RWFlag(RW_Flag);
	//READ
	if (RW_Flag == 0){
		/** �����ȊO�̃��[���`�F�b�N **/
		ret = ReadAP202_Check(IN_fillcolour_str);
	}
	//WRITE
	else if (RW_Flag == 1){
		/** �����ȊO�̃��[���`�F�b�N **/
		ret = str_rule_check(IN_fillcolour_str);
	}
	if (ret < 0)
		return ret;

	return 0;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFFillColour_checkC.cpp								�쐬���F2001.06.3

	�P�D�@�\�T�v
		�n�b�`���O(�h��)�t�B�[�`���̑����̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int attr_rule_check(FillColour_Struct IN_fillcolour_str)
	
	����:	�^					������				���e
			FillColour_Struct	IN_fillcolour_str	�n�b�`���O�i�h��j�\����
			
	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.3			���X��(FQS)			�Ȃ��B

**/
int SXFFillColour_checkC::attr_rule_check(Fill_area_style_colour_Struct* IN_fillcolour_str)
{
	m_color = IN_fillcolour_str->color;
	m_layer = IN_fillcolour_str->layer;
	int ret = PointMarkerFeature_CheckC();
	return ret;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFFillColour_checkC.cpp								�쐬���F2001.06.3

	�P�D�@�\�T�v
		�n�b�`���O(�h��)�t�B�[�`���̑����ȊO�̃��[���`�F�b�N(write)

	�Q�D�C���^�[�t�F�[�X
	int str_rule_check(FillColour_Struct IN_fillcolour_str)
	
	����:	�^					������				���e
			FillColour_Struct	IN_fillcolour_str	�n�b�`���O�i�h��j�\����
			
	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.3			���X��(FQS)			�Ȃ��B

**/
int SXFFillColour_checkC::str_rule_check(Fill_area_style_colour_Struct* IN_fillcolour_str)
{
	if (IN_fillcolour_str->number > IN_fillcolour_str->in_id.GetSize()){
		SXFErrorMsgC::RecordError(SXFNOTINIDNUMBER,
									m_feature_name,
									3,
									m_InstanceID,
									IN_fillcolour_str->number,
									m_feature_name);
		return SXFNOTINIDNUMBER;
	}
	//�O�`�̃t�B�[�`���R�[�h����`����Ă��Ȃ��l�̂Ƃ�
	if (!m_WriteManager->CheckHatchID(IN_fillcolour_str->out_id)){
		SXFErrorMsgC::RecordError(SXFERROROUTID,
									m_feature_name,
									3,
									m_InstanceID,
									IN_fillcolour_str->out_id,
									m_feature_name);
		return SXFERROROUTID;
	}
	//�������̕̈搔��0�����̂Ƃ�
	if (IN_fillcolour_str->number < 0){
		SXFErrorMsgC::RecordError(SXFERRORNUMBER,
									m_feature_name,
									3,
									m_InstanceID,
									IN_fillcolour_str->number,
									m_feature_name);
		return SXFERRORNUMBER;
	}
	//�������̃t�B�[�`���R�[�h����`����Ă��Ȃ��l�̂Ƃ�
	for (int i = 0; i < IN_fillcolour_str->number; i++){
		if (IN_fillcolour_str->in_id[i] == IN_fillcolour_str->out_id){
			SXFErrorMsgC::RecordError(SXFHATCHIDERROR,
										m_feature_name,
										3,
										m_InstanceID,
										IN_fillcolour_str->in_id[i],
										m_feature_name);
			return SXFHATCHIDERROR;
		}
		if (!m_WriteManager->CheckHatchID(IN_fillcolour_str->in_id[i])){
			SXFErrorMsgC::RecordError(SXFERRORINID,
										m_feature_name,
										3,
										m_InstanceID,
										IN_fillcolour_str->in_id[i],
										m_feature_name);
			return SXFERRORINID;
		}
	}
	return 0;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFFillColour_checkC.cpp								�쐬���F2001.06.3

	�P�D�@�\�T�v
		�n�b�`���O(�h��)�t�B�[�`���̑����ȊO�̃��[���`�F�b�N(read)

	�Q�D�C���^�[�t�F�[�X
	int ReadFeature_Check(FillColour_Struct* IN_Struct)
	
	����:	�^					������		���e
			FillColour_Struct*	IN_Struct	�n�b�`���O�i�h��j�\����
			
	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.3			���X��(FQS)			�Ȃ��B

**/
int SXFFillColour_checkC::ReadAP202_Check(Fill_area_style_colour_Struct *IN_Struct)
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
		/* �������ƊO�`��ID������ */
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
