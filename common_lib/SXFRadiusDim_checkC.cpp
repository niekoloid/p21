/**
	All Rights Reserved,(c) JACIC 2001
	SXFRadiusDim_checkC.cpp								�쐬���F2000.4.3

	�P�D�N���X�T�v
	���a���@�t�B�[�`���̃��[���`�F�b�N���s���N���X

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/

#include "stdafx.h"
#include "SXFRadiusDim_checkC.h"
#include "SXFErrorMsgC.h"
#include "SXFTableManagerC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFRadiusDim_checkC.cpp								�쐬���F2000.4.3

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void	SXFRadiusDim_checkC::SXFRadiusDim_checkC()		
		
	����	�F	�^		������				���e
		�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/
SXFRadiusDim_checkC::SXFRadiusDim_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFRadiusDim_checkC.cpp								�쐬���F2000.4.3

	�P�D�@�\�T�v
		�f�X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void	SXFRadiusDim_checkC::~SXFRadiusDim_checkC()		
		
	����	�F	�^		������				���e
		�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/
SXFRadiusDim_checkC::~SXFRadiusDim_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFRadiusDim_checkC.cpp								�쐬���F2000.4.3

	�P�D�@�\�T�v
		���a���@�t�B�[�`���̑����̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int attr_rule_check(RadiusDim_Struct IN_radiusdim_str)

	����:	�^					������				���e
			RadiusDim_Struct	IN_radiusdim_str	���a���@�\����

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/
int SXFRadiusDim_checkC::attr_rule_check(RadiusDim_Struct* IN_radiusdim_str)
{
	m_layer = IN_radiusdim_str->layer ;
	m_color = IN_radiusdim_str->color ;
	m_type = IN_radiusdim_str->type ;
	m_line_width = IN_radiusdim_str->line_width ;
	m_font = IN_radiusdim_str->font ;

	int ret = DimFeature_Check(IN_radiusdim_str->flg) ;
	return ret ;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFRadiusDim_checkC.cpp								�쐬���F2000.4.3

	�P�D�@�\�T�v
		���a���@�t�B�[�`���̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int Feature_rule_check(RadiusDim_Struct IN_radiusdim_str,
							SXFTableManagerC* IN_TableManager,
							CString IN_InstanceID,
							SXFComInfoC* IN_Info);
	����:	�^				������			���e
			RadiusDim_Struct	IN_radiusdim_str	���a���@�\����
			SXFTableManagerC*	IN_TableManager		��`ð��يǗ���޼ު�Ă̱��ڽ
			CString				IN_InstanceID		�C���X�^���XID
			SXFComInfoC*		IN_Info				���ʏ���޼ު�Ă̱��ڽ
	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/
int SXFRadiusDim_checkC::Feature_rule_check(RadiusDim_Struct* IN_radiusdim_str,
											SXFTableManagerC* IN_TableManager,
											CString IN_InstanceID,
											SXFComInfoC* IN_Info)
{
	int ret ;

	m_feature_name = "RADIUS_DIM";
	m_TableManager = IN_TableManager;
	m_InstanceID = IN_InstanceID;
	m_ComInfo = IN_Info;
	/** �����̃��[���`�F�b�N **/
	ret  = attr_rule_check(IN_radiusdim_str) ;
	if (ret < 0)
		return ret ;
	/** �����ȊO�̃��[���`�F�b�N **/
	ret = str_rule_check(IN_radiusdim_str);
	if (ret < 0)
		return ret;

	return 0 ;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFRadiusDim_checkC.cpp								�쐬���F2000.4.3

	�P�D�@�\�T�v
		���a���@�t�B�[�`���̑����ȊO�̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int str_rule_check(RadiusDim_Struct IN_radiusdim_str);

	����:	�^					������				���e
			RadiusDim_Struct	IN_radiusdim_str	���a���@�\����

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/
int SXFRadiusDim_checkC::str_rule_check(RadiusDim_Struct* IN_radiusdim_str)
{
	int ret = 0 ;
//���@��
	Line_Struct Line_str;

	Line_str.color = IN_radiusdim_str->color ;
	Line_str.end_x = IN_radiusdim_str->sun_x1 ;
	Line_str.end_y = IN_radiusdim_str->sun_y1 ;
	Line_str.layer = IN_radiusdim_str->layer ;
	Line_str.line_width = IN_radiusdim_str->line_width ;
	Line_str.start_x = IN_radiusdim_str->sun_x2 ;
	Line_str.start_y = IN_radiusdim_str->sun_y2 ;
	Line_str.type = IN_radiusdim_str->type ;

	ret = linestr_rule_check(&Line_str);
	if (ret < 0)
		return ret ;
//���
	ret = arr_check(IN_radiusdim_str->arr_code1,
					IN_radiusdim_str->arr_code2,
					IN_radiusdim_str->arr_r) ;
	if (ret < 0) 
		return ret ;

//�����v�f
	Text_Struct Text_str;

	Text_str.layer = IN_radiusdim_str->layer ;
	Text_str.color = IN_radiusdim_str->color ;
	Text_str.font = IN_radiusdim_str->font ;
	Text_str.text_x = IN_radiusdim_str->text_x ;
	Text_str.text_y = IN_radiusdim_str->text_y ;
	Text_str.height = IN_radiusdim_str->height ;
	Text_str.width = IN_radiusdim_str->width ;
	Text_str.spc = IN_radiusdim_str->spc ;
	Text_str.angle = IN_radiusdim_str->angle ;
	Text_str.slant = IN_radiusdim_str->slant ;
	Text_str.b_pnt = IN_radiusdim_str->b_pnt ;
	Text_str.direct = IN_radiusdim_str->direct ;

	//���@�l�̗L���t���O��0�܂���1�ł͂Ȃ��Ƃ�
	if ((IN_radiusdim_str->flg < 0) || (IN_radiusdim_str->flg > 1)){
		SXFErrorMsgC::RecordError(SXFTEXTFLAG,
									m_feature_name,
									3,
									m_InstanceID,
									IN_radiusdim_str->flg,
									m_feature_name);
		return SXFTEXTFLAG;
	}
	if (IN_radiusdim_str->flg != 0){
		ret	= textstr_rule_check (&Text_str);
		if (ret < 0)
			return ret ;
	}
	return 0 ;

}
