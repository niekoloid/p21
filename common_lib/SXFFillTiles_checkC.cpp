/**
	All Rights Reserved,(c) JACIC 2001
	SXFFillTiles_checkC.cpp								�쐬���F2001.06.3

	�P�D�N���X�T�v
	�n�b�`���O�i�p�^�[���j�t�B�[�`���̃��[���`�F�b�N���s���N���X

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.3			���X��(FQS)			�Ȃ��B

**/
#include "stdafx.h"
#include "SXFFillTiles_checkC.h"
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
	SXFFillTiles_checkC.cpp								�쐬���F2001.06.3

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void	SXFFillTiles_checkC::SXFFillTiles_checkC()
		
	����	�F	�^		������				���e
		�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.3			���X��(FQS)			�Ȃ��B

**/
SXFFillTiles_checkC::SXFFillTiles_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFFillTiles_checkC.cpp								�쐬���F2001.06.3

	�P�D�@�\�T�v
		�f�X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void	SXFFillTiles_checkC::~SXFFillTiles_checkC()
		
	����	�F	�^		������				���e
		�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.3			���X��(FQS)			�Ȃ��B

**/
SXFFillTiles_checkC::~SXFFillTiles_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFFillTiles_checkC.cpp								�쐬���F2001.06.3

	�P�D�@�\�T�v
		�n�b�`���O(���[�U��`)�t�B�[�`���̑����ȊO�̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int Feature_rule_check(FillTiles_Struct IN_filltiles_str,
							SXFTableManagerC* IN_TableManager,
							SXFReadFeatureManagerC* IN_ReadFeatureManager,
							SXFWriteManagerC* IN_WriteManager,
							CString IN_InstanceID,
							SXFComInfoC* IN_Info);
							
	����:	�^						������					���e
			FillTiles_Struct		IN_filltiles_str		�n�b�`���O�i�p�^�[���j�\����
			SXFTableManagerC*		IN_TableManager			��`ð��ٗv�f�Ǘ���޼ު��
			SXFReadFeatureManagerC* IN_ReadFeatureManager	Read�Ǘ���޼ު��
			SXFWriteManagerC* 		IN_WriteManager			Write�Ǘ���޼ު��
			CString					IN_InstanceID			�C���X�^���XID
			SXFComInfoC*			IN_Info					���ʏ���޼ު��

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.3			���X��(FQS)			�Ȃ��B

**/
int SXFFillTiles_checkC::Feature_rule_check(Fill_area_style_tiles_Struct* IN_filltiles_str,
											   	SXFTableManagerC* IN_TableManager,
												SXFReadAP202ManagerC* IN_ReadAP202Manager,
												SXFWriteManagerC* IN_WriteManager,
											  	CString IN_InstanceID,
											  	SXFComInfoC* IN_Info)
{
	int ret;

	m_feature_name = DEF_FILL_AREA_STYLE_TILES;
	m_TableManager = IN_TableManager;
	m_ReadAP202Manager = IN_ReadAP202Manager;
	m_WriteManager = IN_WriteManager;
	m_InstanceID = IN_InstanceID;
	m_ComInfo = IN_Info;
	/** �����̃��[���`�F�b�N **/
	ret = attr_rule_check(IN_filltiles_str);
	if (ret < 0)
		return ret;
	int RW_Flag = -1;
	m_ComInfo->Get_RWFlag(RW_Flag);
	//READ
	if (RW_Flag == 0){
		/** �����ȊO�̃��[���`�F�b�N **/
		ret = ReadAP202_Check(IN_filltiles_str);
	}
	//WRITE
	else if (RW_Flag == 1){
		/** �����ȊO�̃��[���`�F�b�N **/
		ret = str_rule_check(IN_filltiles_str);
	}
	if (ret < 0)
		return ret;

	return 0;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFFillTiles_checkC.cpp								�쐬���F2001.06.3

	�P�D�@�\�T�v
		�n�b�`���O(�p�^�[��)�t�B�[�`���̑����̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int attr_rule_check(FillTiles_Struct IN_filltiles_str);
	
	����:	�^					������				���e
			FillTiles_Struct	IN_filltiles_str	�n�b�`�p�^�[���\����
			
	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.3			���X��(FQS)			�Ȃ��B

**/
int SXFFillTiles_checkC::attr_rule_check(Fill_area_style_tiles_Struct* IN_filltiles_str)
{
	m_layer = IN_filltiles_str->layer;
	m_color = IN_filltiles_str->hatch_color;
	int ret = PointMarkerFeature_CheckC();
	return ret;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFFillTiles_checkC.cpp								�쐬���F2001.06.3

	�P�D�@�\�T�v
		�n�b�`���O(�p�^�[��)�t�B�[�`���̑����ȊO�̃��[���`�F�b�N(write)

	�Q�D�C���^�[�t�F�[�X
	int str_rule_check(FillTiles_Struct IN_filltiles_str);
	
	����:	�^					������				���e
			FillTiles_Struct	IN_filltiles_str	�n�b�`���O�i�p�^�[���j�\����
			
	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.3			���X��(FQS)			�Ȃ��B

**/
int SXFFillTiles_checkC::str_rule_check(Fill_area_style_tiles_Struct* IN_filltiles_str)
{
	//�n�b�`�p�^�[���̌J��Ԃ��x�N�g��1�̑傫�����͈͊O�̒l�̂Ƃ�
	if (double_check(IN_filltiles_str->hatch_pattern_vector1) < 0){
		SXFErrorMsgC::RecordError(SXFERRORVECTOR,
									m_feature_name,
									3,
									m_InstanceID,
									IN_filltiles_str->hatch_pattern_vector1,
									m_feature_name);
		return SXFERRORVECTOR;
	}
	//�n�b�`�p�^�[���̌J��Ԃ��x�N�g���P�̊p�x��0�`360�łȂ��Ƃ�
	if (angle_check(IN_filltiles_str->hatch_pattern_vector1_angle) < 0){
		SXFErrorMsgC::RecordError(SXFERRORANGLE,
									m_feature_name,
									3,
									m_InstanceID,
									IN_filltiles_str->hatch_pattern_vector1_angle,
									m_feature_name);
		return SXFERRORANGLE;
	}
	//�n�b�`�p�^�[���̌J��Ԃ��x�N�g���Q�̑傫�����͈͊O�̒l�̂Ƃ�
	if (double_check(IN_filltiles_str->hatch_pattern_vector2) < 0){
		SXFErrorMsgC::RecordError(SXFERRORVECTOR,
									m_feature_name,
									3,
									m_InstanceID,
									IN_filltiles_str->hatch_pattern_vector2,
									m_feature_name);
		return SXFERRORVECTOR;
	}
	//�n�b�`�p�^�[���̌J��Ԃ��x�N�g���P�̊p�x��0�`360�łȂ��Ƃ�
	if (angle_check(IN_filltiles_str->hatch_pattern_vector2_angle) < 0){
		SXFErrorMsgC::RecordError(SXFERRORANGLE,
									m_feature_name,
									3,
									m_InstanceID,
									IN_filltiles_str->hatch_pattern_vector2_angle,
									m_feature_name);
		return SXFERRORANGLE;
	}
	//�n�b�`�p�^�[���̔{�����͈͊O�̒l�̂Ƃ�
	if (double_check(IN_filltiles_str->hatch_pattern_scale_x) < 0){
		SXFErrorMsgC::RecordError(SXFERRORSCALE,
									m_feature_name,
									3,
									m_InstanceID,
									IN_filltiles_str->hatch_pattern_scale_x,
									m_feature_name);
		return SXFERRORSCALE;
	}
	//�n�b�`�p�^�[���̔{�����͈͊O�̒l�̂Ƃ�
	if (double_check(IN_filltiles_str->hatch_pattern_scale_y) < 0){
		SXFErrorMsgC::RecordError(SXFERRORSCALE,
									m_feature_name,
									3,
									m_InstanceID,
									IN_filltiles_str->hatch_pattern_scale_y,
									m_feature_name);
		return SXFERRORSCALE;
	}
	//�n�b�`�p�^�[���̌����̊p�x��0�`360�łȂ��Ƃ�
	if (angle_check(IN_filltiles_str->hatch_pattern_angle) < 0) {
		SXFErrorMsgC::RecordError(SXFERRORANGLE,
									m_feature_name,
									3,
									m_InstanceID,
									IN_filltiles_str->hatch_pattern_angle,
									m_feature_name);
		return SXFERRORANGLE;
	}
	//�O�`�̃t�B�[�`���R�[�h����`����Ă��Ȃ��l�̂Ƃ�
	if (!m_WriteManager->CheckHatchID(IN_filltiles_str->out_id)){
		SXFErrorMsgC::RecordError(SXFERROROUTID,
									m_feature_name,
									3,
									m_InstanceID,
									IN_filltiles_str->out_id,
									m_feature_name);
		return SXFERROROUTID;
	}
	//�������̕̈搔��0�����̂Ƃ�
	if (IN_filltiles_str->number < 0){
		SXFErrorMsgC::RecordError(SXFERRORNUMBER,
									m_feature_name,
									3,
									m_InstanceID,
									IN_filltiles_str->number,
									m_feature_name);
		return SXFERRORNUMBER;
	}
	if (IN_filltiles_str->number > IN_filltiles_str->in_id.GetSize()){
		SXFErrorMsgC::RecordError(SXFNOTINIDNUMBER,
									m_feature_name,
									3,
									m_InstanceID,
									IN_filltiles_str->number,
									m_feature_name);
		return SXFNOTINIDNUMBER;
	}

	//�������̃t�B�[�`���R�[�h����`����Ă��Ȃ��l�̂Ƃ�
	for (int i = 0; i < IN_filltiles_str->number; i++){
		if (IN_filltiles_str->in_id[i] == IN_filltiles_str->out_id){
			SXFErrorMsgC::RecordError(SXFHATCHIDERROR,
										m_feature_name,
										3,
										m_InstanceID,
										IN_filltiles_str->in_id[i],
										m_feature_name);
			return SXFHATCHIDERROR;
		}
		if (!m_WriteManager->CheckHatchID(IN_filltiles_str->in_id[i])){
			SXFErrorMsgC::RecordError(SXFERRORINID,
										m_feature_name,
										3,
										m_InstanceID,
										IN_filltiles_str->in_id[i],
										m_feature_name);
			return SXFERRORINID;
		}
	}
	return 0;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFFillTiles_checkC.cpp								�쐬���F2001.06.3

	�P�D�@�\�T�v
		�n�b�`���O(�p�^�[��)�t�B�[�`���̑����ȊO�̃��[���`�F�b�N(read)

	�Q�D�C���^�[�t�F�[�X
	int ReadFeature_Check(FillTiles_Struct IN_filltiles_str);
	
	����:	�^					������				���e
			FillTiles_Struct	IN_filltiles_str	�n�b�`�p�^�[���\����
			
	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.3			���X��(FQS)			�Ȃ��B

**/
int SXFFillTiles_checkC::ReadAP202_Check(Fill_area_style_tiles_Struct *IN_filltiles_str)
{
	//�n�b�`�p�^�[���̌J��Ԃ��x�N�g��1�̑傫�����͈͊O�̒l�̂Ƃ�
	if (double_check(IN_filltiles_str->hatch_pattern_vector1) < 0){
		SXFErrorMsgC::RecordError(SXFERRORVECTOR,
									m_feature_name,
									3,
									m_InstanceID,
									IN_filltiles_str->hatch_pattern_vector1,
									m_feature_name);
		return SXFERRORVECTOR;
	}
	//�n�b�`�p�^�[���̌J��Ԃ��x�N�g���P�̊p�x��0�`360�łȂ��Ƃ�
	if (angle_check(IN_filltiles_str->hatch_pattern_vector1_angle) < 0){
		SXFErrorMsgC::RecordError(SXFERRORANGLE,
									m_feature_name,
									3,
									m_InstanceID,
									IN_filltiles_str->hatch_pattern_vector1_angle,
									m_feature_name);
		return SXFERRORANGLE;
	}
	//�n�b�`�p�^�[���̌J��Ԃ��x�N�g���Q�̑傫�����͈͊O�̒l�̂Ƃ�
	if (double_check(IN_filltiles_str->hatch_pattern_vector2) < 0){
		SXFErrorMsgC::RecordError(SXFERRORVECTOR,
									m_feature_name,
									3,
									m_InstanceID,
									IN_filltiles_str->hatch_pattern_vector2,
									m_feature_name);
		return SXFERRORVECTOR;
	}
	//�n�b�`�p�^�[���̌J��Ԃ��x�N�g���P�̊p�x��0�`360�łȂ��Ƃ�
	if (angle_check(IN_filltiles_str->hatch_pattern_vector2_angle) < 0){
		SXFErrorMsgC::RecordError(SXFERRORANGLE,
									m_feature_name,
									3,
									m_InstanceID,
									IN_filltiles_str->hatch_pattern_vector2_angle,
									m_feature_name);
		return SXFERRORANGLE;
	}
	//�n�b�`�p�^�[���̔{�����͈͊O�̒l�̂Ƃ�
	if (double_check(IN_filltiles_str->hatch_pattern_scale_x) < 0){
		SXFErrorMsgC::RecordError(SXFERRORSCALE,
									m_feature_name,
									3,
									m_InstanceID,
									IN_filltiles_str->hatch_pattern_scale_x,
									m_feature_name);
		return SXFERRORSCALE;
	}
	//�n�b�`�p�^�[���̔{�����͈͊O�̒l�̂Ƃ�
	if (double_check(IN_filltiles_str->hatch_pattern_scale_y) < 0){
		SXFErrorMsgC::RecordError(SXFERRORSCALE,
									m_feature_name,
									3,
									m_InstanceID,
									IN_filltiles_str->hatch_pattern_scale_y,
									m_feature_name);
		return SXFERRORSCALE;
	}
	//�n�b�`�p�^�[���̌����̊p�x��0�`360�łȂ��Ƃ�
	if (angle_check(IN_filltiles_str->hatch_pattern_angle) < 0) {
		SXFErrorMsgC::RecordError(SXFERRORANGLE,
									m_feature_name,
									3,
									m_InstanceID,
									IN_filltiles_str->hatch_pattern_angle,
									m_feature_name);
		return SXFERRORANGLE;
	}

	//�O�`�̃t�B�[�`���R�[�h����`����Ă��Ȃ��l�̂Ƃ�
	if (!m_ReadAP202Manager->SymbolCodeCheck(IN_filltiles_str->out_id)){
		SXFErrorMsgC::RecordError(SXFERROROUTID,
									m_feature_name,
									3,
									m_InstanceID,
									IN_filltiles_str->out_id,
									m_feature_name);
		return SXFERROROUTID;
	}
	//�������̕̈搔��0�����̂Ƃ�
	if (IN_filltiles_str->number < 0){
		SXFErrorMsgC::RecordError(SXFERRORNUMBER,
									m_feature_name,
									3,
									m_InstanceID,
									IN_filltiles_str->number,
									m_feature_name);
		return SXFERRORNUMBER;
	}
	for (int i = 0; i < IN_filltiles_str->number; i++){
		/* �O�`�ƒ�������ID�������� */
		if (IN_filltiles_str->in_id[i] == IN_filltiles_str->out_id){
			SXFErrorMsgC::RecordError(SXFHATCHIDERROR,
										m_feature_name,
										3,
										m_InstanceID,
										IN_filltiles_str->in_id[i],
										m_feature_name);
			return SXFHATCHIDERROR;
		}
		//�������̃t�B�[�`���R�[�h����`����Ă��Ȃ��l�̂Ƃ�
		if (!m_ReadAP202Manager->SymbolCodeCheck(IN_filltiles_str->in_id[i])){
			SXFErrorMsgC::RecordError(SXFERRORINID,
										m_feature_name,
										3,
										m_InstanceID,
										IN_filltiles_str->in_id[i],
										m_feature_name);
			return SXFERRORINID;
		}
	}

	return 0;
}
