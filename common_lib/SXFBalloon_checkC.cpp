/**
	All Rights Reserved,(c) JACIC 2001
	SXFBalloon_checkC.cpp								�쐬���F2000.4.4

	�P�D�N���X�T�v
	�o���[���t�B�[�`���̃��[���`�F�b�N���s���N���X

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.4			�{��(FQS)			�Ȃ��B

**/

#include "stdafx.h"
#include "SXFBalloon_checkC.h"
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
	SXFBalloon_checkC.cpp								�쐬���F2000.4.4

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void	SXFBalloon_checkC::SXFBalloon_checkC()	
		
	����	�F	�^		������				���e
		�Ȃ�


	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.4			�{��(FQS)			�Ȃ��B

**/
SXFBalloon_checkC::SXFBalloon_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFBalloon_checkC.cpp								�쐬���F2000.4.4

	�P�D�@�\�T�v
		�f�X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void	SXFBalloon_checkC::~SXFBalloon_checkC()	
		
	����	�F	�^		������				���e
		�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.4			�{��(FQS)			�Ȃ��B

**/
SXFBalloon_checkC::~SXFBalloon_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFBalloon_checkC.cpp								�쐬���F2000.4.4

	�P�D�@�\�T�v
	�o���[���t�B�[�`���̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int Feature_rule_check(Balloon_Struct IN_balloon_str,
							SXFTableManagerC* IN_TableManager,
							CString IN_InstanceID,
							SXFComInfoC* IN_Info);

	����:	�^					������				���e
			Balloon_Struct		IN_balloon_str		�o���[���\����
			SXFTableManagerC*	IN_TableManager		��`�e�[�u���v�f�Ǘ��I�u�W�F�N�g
			CString				IN_InstanceID		�C���X�^���XID
			SXFComInfoC*		IN_Info				���ʏ��	
			
	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.4			�{��(FQS)			�Ȃ��B

**/
int SXFBalloon_checkC::Feature_rule_check(Balloon_Struct* IN_balloon_str,
										  SXFTableManagerC* IN_TableManager,
										  CString IN_InstanceID,
										  SXFComInfoC* IN_Info)
{
	int ret;

	m_feature_name = DEF_BALLOON;
	m_TableManager = IN_TableManager;
	m_InstanceID = IN_InstanceID;
	m_ComInfo = IN_Info;
	/** �����̃��[���`�F�b�N **/
	ret = attr_rule_check(IN_balloon_str);
	if (ret < 0)
		return ret;
	/** �����ȊO�̃��[���`�F�b�N **/
	ret = str_rule_check(IN_balloon_str);
	if (ret < 0)
		return ret;

	return 0;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFBalloon_checkC.cpp								�쐬���F2000.4.4

	�P�D�@�\�T�v
	�o���[���t�B�[�`���̑����̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int attr_rule_check(Balloon_Struct IN_balloon_str);

	����:	�^					������				���e
			Balloon_Struct		IN_balloon_str		�o���[���\����

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.4			�{��(FQS)			�Ȃ��B

**/
int SXFBalloon_checkC::attr_rule_check(Balloon_Struct* IN_balloon_str)
{
	m_layer = IN_balloon_str->layer ;
	m_color = IN_balloon_str->color ;
	m_type = IN_balloon_str->type ;
	m_line_width = IN_balloon_str->line_width ;
	m_font = IN_balloon_str->font ;

	int ret = DimFeature_Check(IN_balloon_str->flg) ;
	return ret ;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFBalloon_checkC.cpp								�쐬���F2000.4.4

	�P�D�@�\�T�v
	�o���[���t�B�[�`���̑����ȊO�̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int str_rule_check(Balloon_Struct IN_balloon_str);

	����:	�^					������				���e
			Balloon_Struct		IN_balloon_str		�o���[���\����

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�


	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.4			�{��(FQS)			�Ȃ��B

**/
int SXFBalloon_checkC::str_rule_check(Balloon_Struct* IN_balloon_str)
{
	int ret;

//�܂��
	Polyline_Struct Polyline_str;

	Polyline_str.layer = IN_balloon_str->layer;
	Polyline_str.color = IN_balloon_str->color;
	Polyline_str.type = IN_balloon_str->type;
	Polyline_str.line_width = IN_balloon_str->line_width;
	Polyline_str.number = IN_balloon_str->vertex_number;
	if (Polyline_str.number < 1){
		SXFErrorMsgC::RecordError(SXFNOTVERTEXNUMBER,
									m_feature_name,
									3,
									m_InstanceID,
									Polyline_str.number,
									m_feature_name);
		return SXFNOTVERTEXNUMBER;
	}
	//���_�������W�̔z�񐔂����Ȃ��ꍇ�̓G���[
	if (Polyline_str.number > IN_balloon_str->vertex_x.GetSize()){
		SXFErrorMsgC::RecordError(SXFNOTVERTEXNUMBER,
									m_feature_name,
									3,
									m_InstanceID,
									Polyline_str.number,
									m_feature_name);
		return SXFNOTVERTEXNUMBER;
	}
	if (Polyline_str.number > IN_balloon_str->vertex_y.GetSize()){
		SXFErrorMsgC::RecordError(SXFNOTVERTEXNUMBER,
									m_feature_name,
									3,
									m_InstanceID,
									Polyline_str.number,
									m_feature_name);
		return SXFNOTVERTEXNUMBER;
	}

	// 2010.08
	double eps, angle_eps;
	m_ComInfo->Get_Tolerance(eps, angle_eps);

	int number = IN_balloon_str->vertex_number;
	for (int i = 0; i < number - 1; i++) {
		int j= i + 1;
		while ((j < number - 1) &&
		       (fabs(IN_balloon_str->vertex_x[i] - IN_balloon_str->vertex_x[j]) < eps) &&
			   (fabs(IN_balloon_str->vertex_y[i] - IN_balloon_str->vertex_y[j]) < eps)) {
			IN_balloon_str->vertex_x.RemoveAt(j);
			IN_balloon_str->vertex_y.RemoveAt(j);
			number--;
		}
	}

	int n1 = number - 1;
	int n2 = number - 2;
	if ((2 < number) &&
		(fabs(IN_balloon_str->vertex_x[n2] - IN_balloon_str->vertex_x[n1]) < eps) &&
		(fabs(IN_balloon_str->vertex_y[n2] - IN_balloon_str->vertex_y[n1]) < eps)) {
		IN_balloon_str->vertex_x.RemoveAt(n2);
		IN_balloon_str->vertex_y.RemoveAt(n2);
		number--;
	}
	IN_balloon_str->vertex_number = number;

	//�ׂ荇����_�i�n�_�ƏI�_�j���������W��������
	if (IN_balloon_str->vertex_number == 2) {
		if ((fabs(IN_balloon_str->vertex_x[0] - IN_balloon_str->vertex_x[1]) < eps) &&
		    (fabs(IN_balloon_str->vertex_y[0] - IN_balloon_str->vertex_y[1]) < eps)) {
			SXFErrorMsgC::RecordError(SXFSAMECOORD,
									m_feature_name,
									4,
									m_InstanceID,
									IN_balloon_str->vertex_x[0],
									IN_balloon_str->vertex_y[0],
									m_feature_name);
			return SXFSAMECOORD;
		}
	}
	//
/*
	double x;
	for (int i = 0; i < Polyline_str.number; i++){
		x = IN_balloon_str->vertex_x[i];
		Polyline_str.x.Add(x);
		x = IN_balloon_str->vertex_y[i];
		Polyline_str.y.Add(x);
	}
	ret	= polystr_rule_check(&Polyline_str);
	if (ret < 0) 
		return ret ;
*/

//�~
	Circle_Struct Circle_str;

	Circle_str.layer = IN_balloon_str->layer;
	Circle_str.color = IN_balloon_str->color;
	Circle_str.type = IN_balloon_str->type;
	Circle_str.line_width = IN_balloon_str->line_width;
	Circle_str.center_x = IN_balloon_str->center_x;
	Circle_str.center_y = IN_balloon_str->center_y;
	Circle_str.radius = IN_balloon_str->radius;
	ret	= circlestr_rule_check (&Circle_str);
	if (ret < 0)
		return ret ;

//���
	ret = arr_check(IN_balloon_str->arr_code,
					1,
					IN_balloon_str->arr_r) ;
	if (ret < 0) 
		return ret ;
//�����v�f
	Text_Struct Text_str;

	Text_str.layer = IN_balloon_str->layer ;
	Text_str.color = IN_balloon_str->color ;
	Text_str.font = IN_balloon_str->font ;
	Text_str.text_x = IN_balloon_str->text_x ;
	Text_str.text_y = IN_balloon_str->text_y ;
	Text_str.height = IN_balloon_str->height ;
	Text_str.width = IN_balloon_str->width ;
	Text_str.spc = IN_balloon_str->spc ;
	Text_str.angle = IN_balloon_str->angle ;
	Text_str.slant = IN_balloon_str->slant ;
	Text_str.b_pnt = IN_balloon_str->b_pnt ;
	Text_str.direct = IN_balloon_str->direct ;

	//������̗L���t���O��0�܂���1�ł͂Ȃ��Ƃ�
	if ((IN_balloon_str->flg < 0) || (IN_balloon_str->flg > 1)){
		SXFErrorMsgC::RecordError(SXFTEXTFLAG,
									m_feature_name,
									3,
									m_InstanceID,
									IN_balloon_str->flg,
									m_feature_name);
		return SXFTEXTFLAG;
	}
	if (IN_balloon_str->flg != 0){
		ret	= textstr_rule_check (&Text_str);
		if (ret < 0)
			return ret ;
	}
	return 0 ;
}
