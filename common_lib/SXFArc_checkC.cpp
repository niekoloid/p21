/**
	All Rights Reserved,(c) JACIC 2001
	SXFArc_checkC.cpp								�쐬���F2000.4.3

	�P�D�N���X�T�v
	�~�ʃt�B�[�`���̃��[���`�F�b�N���s���N���X


	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/

#include "stdafx.h"
#include <math.h>
#include "SXFArc_checkC.h"
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
	SXFArc_checkC.cpp								�쐬���F2000.4.3

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void	SXFArc_checkC::SXFArc_checkC()
		
	����	�F	�^		������				���e
		�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/
SXFArc_checkC::SXFArc_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFArc_checkC.cpp								�쐬���F2000.4.3

	�P�D�@�\�T�v
		�f�X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void	SXFArc_checkC::~SXFArc_checkC()
		
	����	�F	�^		������				���e
		�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/
SXFArc_checkC::~SXFArc_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFArc_checkC.cpp								�쐬���F2000.4.3

	�P�D�@�\�T�v
		�~�ʃt�B�[�`���̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int Feature_rule_check(Arc_Struct IN_arc_str,
						  SXFTableManagerC* IN_TableManager,
						  int IN_AssemType,
						  CString IN_InstanceID,
						  SXFComInfoC* IN_Info);

	����:	�^					������			���e
			Arc_Struct			IN_arc_str		�~�ʍ\����
			SXFTableManagerC*	IN_TableManager	��`�e�[�u���v�f�Ǘ��I�u�W�F�N�g
			int					IN_AssemType	�A�Z���u���^
			CString				IN_InstanceID	�C���X�^���XID
			SXFComInfoC*		IN_Info			���ʏ��

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/
int SXFArc_checkC::Feature_rule_check(Arc_Struct* IN_arc_str,
									  SXFTableManagerC* IN_TableManager,
									  int IN_AssemType,
									  CString IN_InstanceID,
									  SXFComInfoC* IN_Info)
{
	int ret ;
	m_feature_name = DEF_ARC;
	m_TableManager = IN_TableManager;
	m_InstanceID = IN_InstanceID;
	m_ComInfo = IN_Info;
	/** �����Ȑ���̗v�f�łȂ��Ƃ� **/
	if (IN_AssemType != 3){
		/** �����̃��[���`�F�b�N **/
		ret  = attr_rule_check(IN_arc_str) ;
		if (ret < 0)
			return ret ;
	}
	/** �����ȊO�̃��[���`�F�b�N **/
	ret  = arcstr_rule_check(IN_arc_str) ;
	if (ret < 0)
		return ret ;
	return 0 ;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFArc_checkC.cpp								�쐬���F2000.4.3

	�P�D�@�\�T�v
		�~�ʃt�B�[�`���̑����̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int attr_rule_check(Arc_Struct IN_arc_str);

	����:	�^			������				���e
			Arc_Struct	IN_arc_str			�~�ʍ\����

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/
int SXFArc_checkC::attr_rule_check(Arc_Struct* IN_arc_str)
{
	m_layer = IN_arc_str->layer ;
	m_color = IN_arc_str->color ;
	m_type = IN_arc_str->type ;
	m_line_width = IN_arc_str->line_width ;
	int ret = LineFeature_Check();
	return ret ;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFArc_checkC.cpp								�쐬���F2000.4.3

	�P�D�@�\�T�v
		�~�ʃt�B�[�`���̑����ȊO�̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int arcstr_rule_check(Arc_Struct IN_arc_str)

	����:	�^						������				���e
			Arc_Struct				IN_arc_str			�~�ʍ\����

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/
int SXFArc_checkC::arcstr_rule_check(Arc_Struct *IN_arc_str, bool check_same_angle/* = true*/)
{
	///////////////////////////////////////
	//���e�덷�̎擾
	///////////////////////////////////////
	double eps,angle_eps;
	m_ComInfo->Get_Tolerance(eps,angle_eps);

	//���a���K��͈͊O�̎�
	if (double_check(IN_arc_str->radius) < 0){
		SXFErrorMsgC::RecordError(SXFRADIUSZERO,
									m_feature_name,
									3,
									m_InstanceID,
									IN_arc_str->radius,
									m_feature_name) ;
		return SXFRADIUSZERO ;
	}
	//�����t���O���O�܂��͂P�ȊO�̂Ƃ�
	if ((IN_arc_str->direction < 0) || (IN_arc_str->direction > 1)){
		SXFErrorMsgC::RecordError(SXFDIRECTIONERROR,
									m_feature_name,
									3,
									m_InstanceID,
									IN_arc_str->direction,
									m_feature_name);
		return SXFDIRECTIONERROR;
	}
	//�n�p�ƏI�p���������Ƃ�
	if (check_same_angle && fabs(IN_arc_str->end_angle - IN_arc_str->start_angle) < angle_eps){
		SXFErrorMsgC::RecordError(SXFSAMEANGLE,
									m_feature_name,
									4,
									m_InstanceID,
									IN_arc_str->start_angle,
									IN_arc_str->end_angle,
									m_feature_name);
		return SXFSAMEANGLE;
	}
	//�n�p���O�x����360�x�łȂ��Ƃ�
	if (angle_check(IN_arc_str->start_angle) < 0){
		SXFErrorMsgC::RecordError(SXFERRORANGLE,
									m_feature_name,
									3,
									m_InstanceID,
									IN_arc_str->start_angle,
									m_feature_name);
		return SXFERRORANGLE;
	}
	//�I�p��0�x����360�x�łȂ��Ƃ�
	if (angle_check(IN_arc_str->end_angle) < 0){
		SXFErrorMsgC::RecordError(SXFERRORANGLE,
									m_feature_name,
									3,
									m_InstanceID,
									IN_arc_str->end_angle,
									m_feature_name);
		return SXFERRORANGLE;
	}

	return 0 ;
}
