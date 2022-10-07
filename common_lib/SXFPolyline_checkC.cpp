/**
	All Rights Reserved,(c) JACIC 2001
	SXFPolyline_checkC.cpp								�쐬���F2000.4.3

	�P�D�N���X�T�v
	�ܐ��t�B�[�`���̃��[���`�F�b�N���s���N���X

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/

#include "stdafx.h"
#include <math.h>
#include <iostream>
#include "SXFPolyline_checkC.h"
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
	SXFPolyline_checkC.cpp								�쐬���F2000.4.3

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void	SXFPolyline_checkC::SXFPolyline_checkC()
		
	����	�F	�^						������						���e
		�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/
SXFPolyline_checkC::SXFPolyline_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFPolyline_checkC.cpp								�쐬���F2000.4.3

	�P�D�@�\�T�v
		�f�X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void	SXFPolyline_checkC::~SXFPolyline_checkC()
		
	����	�F	�^						������						���e
		�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/
SXFPolyline_checkC::~SXFPolyline_checkC()
{

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFPolyline_checkC.cpp								�쐬���F2000.4.3

	�P�D�@�\�T�v
		�ܐ��t�B�[�`���̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int attr_rule_check(Polyline_Struct IN_polyline_str);

	����:	�^					������				���e
			Polyline_Struct		IN_polyline_str		�ܐ��\����

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/
int SXFPolyline_checkC::attr_rule_check(Polyline_Struct* IN_polyline_str)
{
	//�������[���`�F�b�N
	m_layer = IN_polyline_str->layer;
	m_color = IN_polyline_str->color;
	m_type = IN_polyline_str->type;
	m_line_width = IN_polyline_str->line_width;
	int ret = LineFeature_Check();
	return ret;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFPolyline_checkC.cpp								�쐬���F2000.4.3

	�P�D�@�\�T�v
		�ܐ��t�B�[�`���̑����ȊO�̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int polystr_rule_check(Polyline_Struct IN_polyline_str)

	����:	�^					������				���e
			Polyline_Struct		IN_polyline_str		�ܐ��\����

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/
int SXFPolyline_checkC::polystr_rule_check(Polyline_Struct* IN_polyline_str)
{
	///////////////////////////////////////
	//���e�덷�̎擾
	///////////////////////////////////////
	double eps,angle_eps;
	m_ComInfo->Get_Tolerance(eps,angle_eps);

	int number = IN_polyline_str->number;

	//���_�����Q�����̂Ƃ��̎�
	if (number < 2){
		SXFErrorMsgC::RecordError(SXFVERTEXERROR,
									m_feature_name,
									3,
									m_InstanceID,
									number,
									m_feature_name);
		return SXFVERTEXERROR;
	}
	//���_�������W�̔z�񐔂����Ȃ��ꍇ�̓G���[
	if (number > IN_polyline_str->x.GetSize()){
		SXFErrorMsgC::RecordError(SXFNOTVERTEXNUMBER,
									m_feature_name,
									3,
									m_InstanceID,
									number,
									m_feature_name);
		return SXFNOTVERTEXNUMBER;
	}
	if (number > IN_polyline_str->y.GetSize()){
		SXFErrorMsgC::RecordError(SXFNOTVERTEXNUMBER,
									m_feature_name,
									3,
									m_InstanceID,
									number,
									m_feature_name);
		return SXFNOTVERTEXNUMBER;
	}


	// 2010.08

	for (int i = 0; i < number - 1; i++) {
		int j= i + 1;
		while ((j < number - 1) &&
		       (fabs(IN_polyline_str->x[i] - IN_polyline_str->x[j]) < eps) &&
			   (fabs(IN_polyline_str->y[i] - IN_polyline_str->y[j]) < eps)) {
			IN_polyline_str->x.RemoveAt(j);
			IN_polyline_str->y.RemoveAt(j);
			number--;
		}
	}

	int n1 = number - 1;
	int n2 = number - 2;
	if ((2 < number) &&
		(fabs(IN_polyline_str->x[n2] - IN_polyline_str->x[n1]) < eps) &&
		(fabs(IN_polyline_str->y[n2] - IN_polyline_str->y[n1]) < eps)) {
		IN_polyline_str->x.RemoveAt(n2);
		IN_polyline_str->y.RemoveAt(n2);
		number--;
	}
	IN_polyline_str->number = number;

	//�ׂ荇����_�i�n�_�ƏI�_�j���������W��������
	if (IN_polyline_str->number == 2) {
		if ((fabs(IN_polyline_str->x[0] - IN_polyline_str->x[1]) < eps) &&
		    (fabs(IN_polyline_str->y[0] - IN_polyline_str->y[1]) < eps)) {
			SXFErrorMsgC::RecordError(SXFSAMECOORD,
									m_feature_name,
									4,
									m_InstanceID,
									IN_polyline_str->x[0],
									IN_polyline_str->y[0],
									m_feature_name);
			return SXFSAMECOORD;
		}
	}
	//

	/*
	//�ׂ荇����_���������W��������
	for (int i = 0; i < number-1; i++){
		if ((fabs(IN_polyline_str->x[i] - IN_polyline_str->x[i+1]) < eps) 
			&& (fabs(IN_polyline_str->y[i] - IN_polyline_str->y[i+1]) < eps)){
			SXFErrorMsgC::RecordError(SXFSAMECOORD,
									m_feature_name,
									4,
									m_InstanceID,
									IN_polyline_str->x[i],
									IN_polyline_str->y[i],
									m_feature_name);
			return SXFSAMECOORD;
		}
	}
	*/
	return 0;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFPolyline_checkC.cpp								�쐬���F2000.4.3

	�P�D�@�\�T�v
		�ܐ��t�B�[�`���̑����̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int Feature_rule_check(Polyline_Struct IN_polyline_str,
						   SXFTableManagerC* IN_TableManager,
						   int IN_AssemType,
						   CString IN_InstanceID,
						   SXFComInfoC* IN_Info);

	����:	�^					������			���e
			Polyline_Struct		IN_polyline_str	�ܐ��\����
		    SXFTableManagerC*	IN_TableManager	��`ð��يǗ���޼ު�Ă̱��ڽ
			int					IN_AssemType	�A�Z���u���^
			CString				IN_InstanceID	�C���X�^���XID
			SXFComInfoC*		IN_Info			���ʏ���޼ު�Ă̱��ڽ

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/
int SXFPolyline_checkC::Feature_rule_check(Polyline_Struct* IN_polyline_str,
										   SXFTableManagerC* IN_TableManager,
										   int IN_AssemType,
										   CString IN_InstanceID,
										   SXFComInfoC* IN_Info)
{
	int ret;
	m_feature_name = DEF_POLYLINE;
	m_TableManager = IN_TableManager;
	m_InstanceID = IN_InstanceID;
	m_ComInfo = IN_Info;
	/** �����Ȑ���ȊO�̗v�f�̂Ƃ� **/
	if (IN_AssemType != 3){
		/** �����̃��[���`�F�b�N **/
		ret  = attr_rule_check(IN_polyline_str) ;
		if (ret < 0)
			return ret ;
	}
	/** �����ȊO�̃��[���`�F�b�N **/
	ret  = polystr_rule_check(IN_polyline_str) ;
	if (ret < 0)
		return ret ;

	return 0 ;

}