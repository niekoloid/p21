/**
	All Rights Reserved,(c) JACIC 2001
	SXFEllipse_Arc_checkC.cpp								�쐬���F2000.4.3

	�P�D�N���X�T�v
	�ȉ~�ʃt�B�[�`���̃��[���`�F�b�N���s���N���X

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/

#include "stdafx.h"
#include <math.h>
#include "SXFEllipse_Arc_checkC.h"
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
	SXFEllipse_Arc_checkC.cpp								�쐬���F2000.4.3

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void	SXFEllipse_Arc_checkC::SXFEllipse_Arc_checkC()
		
	����	�F	�^		������				���e
		�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/
SXFEllipse_Arc_checkC::SXFEllipse_Arc_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFEllipse_Arc_checkC.cpp								�쐬���F2000.4.3

	�P�D�@�\�T�v
		�f�X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void	SXFEllipse_Arc_checkC::~SXFEllipse_Arc_checkC()
		
	����	�F	�^		������				���e
		�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/
SXFEllipse_Arc_checkC::~SXFEllipse_Arc_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFEllipse_Arc_checkC.cpp								�쐬���F2000.4.3

	�P�D�@�\�T�v
		�ȉ~�ʃt�B�[�`���̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int Feature_rule_check(Ellipse_Arc_Struct IN_ellipse_arc_str,
							SXFTableManagerC* IN_TableManager,
							int IN_AssemType,
							CString IN_InstanceID,
							SXFComInfoC* IN_Info);

	����:	�^				������			���e
			Ellipse_Arc_Struct	IN_ellipse_arc_str	�ȉ~�ʍ\����
			SXFTableManagerC*	IN_TableManager		��`�e�[�u���v�f�Ǘ��I�u�W�F�N�g
			int					IN_AssemType		�A�Z���u���^
			CString				IN_InstanceID		�C���X�^���XID
			SXFComInfoC*		IN_Info				���ʏ��

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/
int SXFEllipse_Arc_checkC::Feature_rule_check(Ellipse_Arc_Struct* IN_ellipse_arc_str,
											  SXFTableManagerC* IN_TableManager,
											  int IN_AssemType,
											  CString IN_InstanceID,
											  SXFComInfoC* IN_Info)
{
	int ret ;

	m_feature_name = DEF_ELLIPSE_ARC;
	m_TableManager = IN_TableManager;
	m_InstanceID = IN_InstanceID;
	m_ComInfo = IN_Info;
	/** �����Ȑ���ȊO�̗v�f�̂Ƃ� **/
	if (IN_AssemType != 3){
		/** �����̃��[���`�F�b�N **/
		ret  = attr_rule_check(IN_ellipse_arc_str) ;
		if (ret < 0)
			return ret ;
	}
	/** �����ȊO�̃��[���`�F�b�N **/
	ret  = str_rule_check(IN_ellipse_arc_str) ;
	if (ret < 0)
		return ret ;

	return 0 ;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFEllipse_Arc_checkC.cpp								�쐬���F2000.4.3

	�P�D�@�\�T�v
		�ȉ~�ʃt�B�[�`���̑����̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int attr_rule_check(Ellipse_Arc_Struct IN_ellipse_arc_str);
	
	����:	�^					������				���e
			Ellipse_Arc_Struct	IN_ellipse_arc_str	�ȉ~�ʍ\����
			
	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/
int SXFEllipse_Arc_checkC::attr_rule_check(Ellipse_Arc_Struct* IN_ellipse_arc_str)
{
	m_layer = IN_ellipse_arc_str->layer ;
	m_color = IN_ellipse_arc_str->color ;
	m_type = IN_ellipse_arc_str->type ;
	m_line_width = IN_ellipse_arc_str->line_width ;

	int ret = LineFeature_Check() ;
	return ret ;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFEllipse_Arc_checkC.cpp								�쐬���F2000.4.3

	�P�D�@�\�T�v
		�ȉ~�ʃt�B�[�`���̑����ȊO�̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int str_rule_check(Ellipse_Arc_Struct IN_ellipse_arc_str)

	����:	�^					������				���e
			Ellipse_Arc_Struct	IN_ellipse_arc_str	�ȉ~�ʍ\����

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/
int SXFEllipse_Arc_checkC::str_rule_check(Ellipse_Arc_Struct* IN_ellipse_arc_str)
{
	///////////////////////////////////////
	//���e�덷�̎擾
	///////////////////////////////////////
	double eps, angle_eps;
	m_ComInfo->Get_Tolerance(eps,angle_eps);

	//X�������a���O�ȉ��̎�
	if (double_check(IN_ellipse_arc_str->radius_x) < 0){
		SXFErrorMsgC::RecordError(SXFRADIUSZERO,
									m_feature_name,
									3,
									m_InstanceID,
									IN_ellipse_arc_str->radius_x,
									m_feature_name) ;
		return SXFRADIUSZERO ;
	}
	//Y�������a���O�ȉ��̎�
	if (double_check(IN_ellipse_arc_str->radius_y) < 0){
		SXFErrorMsgC::RecordError(SXFRADIUSZERO,
									m_feature_name,
									3,
									m_InstanceID,
									IN_ellipse_arc_str->radius_y,
									m_feature_name) ;
		return SXFRADIUSZERO ;
	}
	//�����t���O���O�܂��͂P�ȊO�̂Ƃ�
	if ((IN_ellipse_arc_str->direction < 0) || (IN_ellipse_arc_str->direction > 1)){
		SXFErrorMsgC::RecordError(SXFDIRECTIONERROR,
									m_feature_name,
									3,
									m_InstanceID,
									IN_ellipse_arc_str->direction,
									m_feature_name);
		return SXFDIRECTIONERROR;
	}
	//��]�p���O�x����360�x�łȂ��Ƃ�
	if (angle_check(IN_ellipse_arc_str->rotation_angle) < 0){
		SXFErrorMsgC::RecordError(SXFERRORANGLE,
									m_feature_name,
									3,
									m_InstanceID,
									IN_ellipse_arc_str->rotation_angle,
									m_feature_name);
		return SXFERRORANGLE;
	}
	//�n�p�ƏI�p���������Ƃ�
	if (fabs(IN_ellipse_arc_str->end_angle - IN_ellipse_arc_str->start_angle) < angle_eps){
		SXFErrorMsgC::RecordError(SXFSAMEANGLE,
									m_feature_name,
									4,
									m_InstanceID,
									IN_ellipse_arc_str->start_angle,
									IN_ellipse_arc_str->end_angle,
									m_feature_name);
		return SXFSAMEANGLE;
	}
	//�n�p���O�x����360�x�łȂ��Ƃ�
	if (angle_check(IN_ellipse_arc_str->start_angle) < 0){
		SXFErrorMsgC::RecordError(SXFERRORANGLE,
									m_feature_name,
									3,
									m_InstanceID,
									IN_ellipse_arc_str->start_angle,
									m_feature_name);
		return SXFERRORANGLE;
	}
	//�I�p��0�x����360�x�łȂ��Ƃ�
	if (angle_check(IN_ellipse_arc_str->end_angle) < 0){
		SXFErrorMsgC::RecordError(SXFERRORANGLE,
									m_feature_name,
									3,
									m_InstanceID,
									IN_ellipse_arc_str->end_angle,
									m_feature_name);
		return SXFERRORANGLE;
	}
	return 0 ;
}
