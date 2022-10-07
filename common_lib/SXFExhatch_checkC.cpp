/**
	All Rights Reserved,(c) JACIC 2001
	SXFExHatch_checkC.cpp								�쐬���F2001.06.3

	�P�D�N���X�T�v
	�n�b�`���O(����`)�t�B�[�`���̃��[���`�F�b�N���s���N���X

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.3			���X��(FQS)			�Ȃ��B

**/
#include "stdafx.h"
#include "SXFExhatch_checkC.h"
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
	SXFExHatch_checkC.cpp								�쐬���F2001.06.3

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void	SXFExhatch_checkC::SXFExhatch_checkC()
		
	����	�F	�^		������				���e
		�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.3			���X��(FQS)			�Ȃ��B

**/
SXFExhatch_checkC::SXFExhatch_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFExHatch_checkC.cpp								�쐬���F2001.06.3

	�P�D�@�\�T�v
		�f�X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void	SXFExhatch_checkC::~SXFExhatch_checkC()
		
	����	�F	�^		������				���e
		�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.3			���X��(FQS)			�Ȃ��B

**/
SXFExhatch_checkC::~SXFExhatch_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFExHatch_checkC.cpp								�쐬���F2001.06.3

	�P�D�@�\�T�v
		�n�b�`���O(����`)�t�B�[�`���̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int Feature_rule_check(Externally_Defined_Hatch_Struct IN_exhatch_str,
							SXFTableManagerC* IN_TableManager,
							SXFReadFeatureManagerC* IN_ReadFeatureManager,
							SXFWriteManagerC* IN_WriteManager,
							CString IN_InstanceID,
							SXFComInfoC* IN_Info);

	����:	�^									������					���e
			Externally_Defined_Hatch_Struct		IN_exhatch_str			�O���n�b�`�\����
			SXFTableManagerC*					IN_TableManager			��`ð��ٗv�f�Ǘ���޼ު��
			SXFReadFeatureManagerC* 			IN_ReadFeatureManager	Read�Ǘ���޼ު��
			SXFWriteManagerC* 					IN_WriteManager			Write�Ǘ���޼ު��
			CString								IN_InstanceID			�C���X�^���XID
			SXFComInfoC*						IN_Info					���ʏ���޼ު��
	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.3			���X��(FQS)			�Ȃ��B

**/
int SXFExhatch_checkC::Feature_rule_check(Externally_Defined_Hatch_Struct* IN_exhatch_str,
										  	SXFTableManagerC* IN_TableManager,
											SXFReadAP202ManagerC* IN_ReadAP202Manager,
											SXFWriteManagerC* IN_WriteManager,
										  	CString IN_InstanceID,
										  	SXFComInfoC* IN_Info)
{
	int ret;

	m_feature_name = DEF_EXTERNALLY_DEFINED_HATCH;
	m_TableManager = IN_TableManager;
	m_ReadAP202Manager = IN_ReadAP202Manager,
	m_WriteManager = IN_WriteManager;
	m_InstanceID = IN_InstanceID;
	m_ComInfo = IN_Info;
	/** �����̃��[���`�F�b�N **/
	ret = attr_rule_check(IN_exhatch_str);
	if (ret < 0)
		return ret;

	int RW_Flag = -1;
	m_ComInfo->Get_RWFlag(RW_Flag);
	//READ
	if (RW_Flag == 0){
		ret = ReadAP202_Check(IN_exhatch_str);
	}
	//WRITE
	else if (RW_Flag == 1){
		ret = str_rule_check(IN_exhatch_str);
	}
	if (ret < 0)
		return ret;

	return 0;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFExHatch_checkC.cpp								�쐬���F2001.06.3

	�P�D�@�\�T�v
		�n�b�`���O(����`)�t�B�[�`���̑����ȊO�̃��[���`�F�b�N(write)

	�Q�D�C���^�[�t�F�[�X
	int str_rule_check(Externally_Defined_Hatch_Struct IN_exhatch_str)
	
	����:	�^									������			���e
			Externally_Defined_Hatch_Struct		IN_exhatch_str	�O���n�b�`�\����
			
	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.3			���X��(FQS)			�Ȃ��B

**/
int SXFExhatch_checkC::str_rule_check(Externally_Defined_Hatch_Struct* IN_exhatch_str)
{
	if (IN_exhatch_str->number > IN_exhatch_str->in_id.GetSize()){
		SXFErrorMsgC::RecordError(SXFNOTINIDNUMBER,
									m_feature_name,
									3,
									m_InstanceID,
									IN_exhatch_str->number,
									m_feature_name);
		return SXFNOTINIDNUMBER;
	}
	//�O�`�̃t�B�[�`���R�[�h����`����Ă��Ȃ��l�̂Ƃ�
	if (!m_WriteManager->CheckHatchID(IN_exhatch_str->out_id)){
		SXFErrorMsgC::RecordError(SXFERROROUTID,
									m_feature_name,
									3,
									m_InstanceID,
									IN_exhatch_str->out_id,
									m_feature_name);
		return SXFERROROUTID;
	}
	//�������̕̈搔��0�����̂Ƃ�
	if (IN_exhatch_str->number < 0){
		SXFErrorMsgC::RecordError(SXFERRORNUMBER,
									m_feature_name,
									3,
									m_InstanceID,
									IN_exhatch_str->number,
									m_feature_name);
		return SXFERRORNUMBER;
	}
	//�������̃t�B�[�`���R�[�h����`����Ă��Ȃ��l�̂Ƃ�
	for (int i = 0; i < IN_exhatch_str->number; i++){
		if (IN_exhatch_str->in_id[i] == IN_exhatch_str->out_id){
			SXFErrorMsgC::RecordError(SXFHATCHIDERROR,
										m_feature_name,
										3,
										m_InstanceID,
										IN_exhatch_str->in_id[i],
										m_feature_name);
			return SXFHATCHIDERROR;
		}
		if (!m_WriteManager->CheckHatchID(IN_exhatch_str->in_id[i])){
			SXFErrorMsgC::RecordError(SXFERRORINID,
										m_feature_name,
										3,
										m_InstanceID,
										IN_exhatch_str->in_id[i],
										m_feature_name);
			return SXFERRORINID;
		}
	}
	return 0;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFExHatch_checkC.cpp								�쐬���F2001.06.3

	�P�D�@�\�T�v
		�n�b�`���O(����`)�t�B�[�`���̑����̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int attr_rule_check(Externally_Defined_Hatch IN_exhatch_str);

	����:	�^									������				���e
			Externally_Defined_Hatch_Struct*	IN_exhatch_str		�O���n�b�`�\����
			
	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.3			���X��(FQS)			�Ȃ��B

**/
int SXFExhatch_checkC::attr_rule_check(Externally_Defined_Hatch_Struct* IN_exhatch_str)
{
	m_layer = IN_exhatch_str->layer;
	int ret = ExHatchFeature_Check();
	return ret;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFExHatch_checkC.cpp								�쐬���F2001.06.3

	�P�D�@�\�T�v
		�n�b�`���O(����`)�t�B�[�`���̑����ȊO�̃��[���`�F�b�N(read)

	�Q�D�C���^�[�t�F�[�X
		void	SXFExhatch_checkC::ReadFeature_Check(Externally_Defined_Hatch_Struct *IN_Struct)
		
	����	�F	�^									������				���e
				Externally_Defined_Hatch_Struct*	IN_Struct			�\����

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.3			���X��(FQS)			�Ȃ��B

**/
int SXFExhatch_checkC::ReadAP202_Check(Externally_Defined_Hatch_Struct *IN_Struct)
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
		/* �������ƊO�`��ID�������� */
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
