/**
	All Rights Reserved,(c) JACIC 2001
	SXFPoint_Marker_checkC.cpp								�쐬���F2000.3.27

	�P�D�N���X�T�v
	�_�}�[�J�t�B�[�`���̃��[���`�F�b�N���s���N���X

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.3.27			�{��(FQS)			�Ȃ��B

**/

#include "stdafx.h"
#include "SXFPoint_Marker_checkC.h"
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
	SXFPoint_Marker_checkC.cpp								�쐬���F2000.3.27

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void	SXFPoint_Marker_checkC::SXFPoint_Marker_checkC()
		
	����	�F	�^						������						���e
		�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.3.27			�{��(FQS)			�Ȃ��B

**/
SXFPoint_Marker_checkC::SXFPoint_Marker_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFPoint_Marker_checkC.cpp								�쐬���F2000.3.27

	�P�D�@�\�T�v
		�f�X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void	SXFPoint_Marker_checkC::~SXFPoint_Marker_checkC()
		
	����	�F	�^						������						���e
		�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.3.27			�{��(FQS)			�Ȃ��B

**/
SXFPoint_Marker_checkC::~SXFPoint_Marker_checkC()
{

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFPoint_Marker_checkC.cpp								�쐬���F2000.3.27

	�P�D�@�\�T�v
		�_�}�[�J�t�B�[�`���̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int Feature_rule_check(Point_Marker_Struct IN_point_marker_str,
						   SXFTableManagerC* IN_TableManager,
						   CString IN_InstanceID)

	����:	�^					������				���e
			Point_Marker_Struct	IN_point_marker_str	�_�}�[�J�\����
  		    SXFTableManagerC*	IN_TableManager		��`ð��يǗ���޼ު�Ă̱��ڽ
		    CString				IN_InstanceID		�C���X�^���XID

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.3.27			�{��(FQS)			�Ȃ��B

**/
int SXFPoint_Marker_checkC::Feature_rule_check(Point_Marker_Struct* IN_point_marker_str,
											   SXFTableManagerC* IN_TableManager,
											   CString IN_InstanceID)
{
	int ret;

	m_feature_name = DEF_POINT_MARKER;
	m_TableManager = IN_TableManager;
	m_InstanceID = IN_InstanceID;
	/** �����̃��[���`�F�b�N **/
	ret = attr_rule_check(IN_point_marker_str);
	if (ret < 0)
		return ret;
	/** �����ȊO�̃��[���`�F�b�N **/
	ret = str_rule_check(IN_point_marker_str);
	if (ret < 0)
		return ret;

	return 0;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFPoint_Marker_checkC.cpp								�쐬���F2000.3.27

	�P�D�@�\�T�v
		�_�}�[�J�t�B�[�`���̑����ȊO�̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int str_rule_check(Point_Marker_Struct IN_point_marker_str)

	����:	�^					������				���e
			Point_Marker_Struct	IN_point_marker_str	�_�}�[�J�\����

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.3.27			�{��(FQS)			�Ȃ��B

**/
int SXFPoint_Marker_checkC::str_rule_check(Point_Marker_Struct* IN_point_marker_str)
{
	//�}�[�J�R�[�h���P����V�łȂ��Ƃ�
	if ((IN_point_marker_str->marker_code < 1) 
		|| (IN_point_marker_str->marker_code > 7)){
		SXFErrorMsgC::RecordError(SXFMARKERERROR,
									m_feature_name,
									3,
									m_InstanceID,
									IN_point_marker_str->marker_code,
									m_feature_name);
		return SXFMARKERERROR;
	}
	//��]�p��0�x����360�x�łȂ��Ƃ�
	if (angle_check(IN_point_marker_str->rotate_angle) < 0){
		SXFErrorMsgC::RecordError(SXFERRORANGLE,
									m_feature_name,
									3,
									m_InstanceID,
									IN_point_marker_str->rotate_angle,
									m_feature_name);
		return SXFERRORANGLE;
	}
	//�ړx���O�ȉ��̂Ƃ�
	if (double_check(IN_point_marker_str->scale) < 0){
		SXFErrorMsgC::RecordError(SXFERRORSCALE,
									m_feature_name,
									3,
									m_InstanceID,
									IN_point_marker_str->scale,
									m_feature_name);
		return SXFERRORSCALE;
	}

	return 0;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFPoint_Marker_checkC.cpp								�쐬���F2000.3.27

	�P�D�@�\�T�v
		�_�}�[�J�t�B�[�`���̑����̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int attr_rule_check(Point_Marker_Struct IN_point_marker_str);

	����:	�^					������				���e
			Point_Marker_Struct	IN_point_marker_str	�_�}�[�J�\����

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.3.27			�{��(FQS)			�Ȃ��B

**/
int SXFPoint_Marker_checkC::attr_rule_check(Point_Marker_Struct* IN_point_marker_str)
{
	//�������[���`�F�b�N
	m_layer = IN_point_marker_str->layer;
	m_color = IN_point_marker_str->color;
	int ret = PointMarkerFeature_CheckC();
	return ret;
}
