/**
	All Rights Reserved,(c)JACIC 2001
	SXFLinearDim_checkC.cpp					�쐬���F2000.03.29

	�P�D�N���X�T�v
	�������@�t�B�[�`���̃��[���`�F�b�N���s���N���X
	
	�Q�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.03.29	�ЎR(FQS)	�Ȃ��B
**/
#include "stdafx.h"
#include "SXFLinearDim_checkC.h"
#include "SXFErrorMsgC.h"
#include "SXFTableManagerC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFLinearDim_checkC.cpp				 	�쐬���F2000.03.29

	�P�D�@�\�T�v 
		�R���X�g���N�^
		
	�Q�D�C���^�[�t�F�C�X
		void 	SXFLinearDim_checkC::SXFLinearDim_checkC()
		
	����	�F	�^		������				���e
		�Ȃ�

	���A�l	�F	�Ȃ�

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.03.29	�ЎR(FQS)	�Ȃ��B
**/
SXFLinearDim_checkC::SXFLinearDim_checkC()
{
}
/**
	All Rights Reserved,(c)JACIC 2001
	SXFLinearDim_checkC.cpp				 	�쐬���F2000.03.29

	�P�D�@�\�T�v 
		�f�X�g���N�^
		
	�Q�D�C���^�[�t�F�C�X
		void 	SXFLinearDim_checkC::~SXFLinearDim_checkC ()
			
	����	�F	�^						������					���e
		�Ȃ�

	���A�l	�F	�Ȃ�

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.03.29	�ЎR(FQS)	�Ȃ��B
**/
SXFLinearDim_checkC::~SXFLinearDim_checkC ()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFLinearDim_checkC.cpp				 	�쐬���F2000.03.29

	�P�D�@�\�T�v 
		�������@�t�B�[�`���̃��[���`�F�b�N
		
	�Q�D�C���^�[�t�F�C�X
		int		SXFLinearDim_checkC::Feature_rule_check(
								LinearDim_Struct IN_LinearDim_str,
								SXFTableManagerC* IN_TableManager,
								CString IN_InstanceID,
								SXFComInfoC* IN_Info)
		
	����	�F	�^						������		���e
			LinearDim_Struct	IN_LinearDim_str	�������@�t�B�[�`���̍\����		
			SXFTableManagerC*	IN_TableManager		��`ð��يǗ���޼ު�Ă̱��ڽ
			CString				IN_InstanceID		�C���X�^���XID
			SXFComInfoC*		IN_Info				���ʏ���޼ު�Ă̱��ڽ

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.03.29	�ЎR(FQS)	�Ȃ��B
**/
int SXFLinearDim_checkC::Feature_rule_check(LinearDim_Struct* IN_LinearDim_str,
											SXFTableManagerC* IN_TableManager,
											CString IN_InstanceID,
											SXFComInfoC* IN_Info)
{
	int ret ;

	m_feature_name = DEF_LINEAR_DIM;
	m_TableManager = IN_TableManager;
	m_InstanceID = IN_InstanceID;
	m_ComInfo = IN_Info;
	/** �����̃��[���`�F�b�N **/
	ret  = attr_rule_check(IN_LinearDim_str) ;
	if (ret < 0)
		return ret ;
	/** �����ȊO�̃��[���`�F�b�N **/
	ret = lineardim_check(IN_LinearDim_str);
	if (ret < 0)
		return ret;

	return 0 ;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFLinearDim_checkC.cpp				 	�쐬���F2000.03.29

	�P�D�@�\�T�v 
		�������@�t�B�[�`���̑����̃��[���`�F�b�N
		
	�Q�D�C���^�[�t�F�C�X
		int	 SXFLinearDim_checkC::attr_rule_check (
					LinearDim_Struct IN_LinearDim_str)
		
	����	�F	�^				������				���e
			LinearDim_Struct	IN_LinearDim_str	�\����

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.03.29	�ЎR(FQS)	�Ȃ��B
**/
int SXFLinearDim_checkC::attr_rule_check (LinearDim_Struct* IN_LinearDim_str)
{
	m_layer = IN_LinearDim_str->layer ;
	m_color = IN_LinearDim_str->color ;
	m_type = IN_LinearDim_str->type ;
	m_line_width = IN_LinearDim_str->line_width ;
	m_font = IN_LinearDim_str->font ;
	
	int ret = DimFeature_Check(IN_LinearDim_str->flg4) ;
	return ret ;
}
/**
	All Rights Reserved,(c)JACIC 2001
	SXFLinearDim_checkC.cpp				 	�쐬���F2000.03.29

	�P�D�@�\�T�v 
		�������@�t�B�[�`���̑����ȊO�̃��[���`�F�b�N
		
	�Q�D�C���^�[�t�F�C�X
		int 	SXFLinearDim_checkC::lineardim_check (
					LinearDim_Struct IN_LinearDim_str)

	����	�F	�^				������				���e
			LinearDim_Struct	IN_LinearDim_str	�\����
	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.03.29	�ЎR(FQS)	�Ȃ��B
**/
int SXFLinearDim_checkC::lineardim_check (LinearDim_Struct* IN_LinearDim_str)
{
	int ret = 0 ;
//���@��
	Line_Struct Line_str ;

	Line_str.layer = IN_LinearDim_str->layer ;
	Line_str.color = IN_LinearDim_str->color ;
	Line_str.type = IN_LinearDim_str->type ;
	Line_str.line_width = IN_LinearDim_str->line_width ;
	Line_str.start_x = IN_LinearDim_str->sun_x1 ;
	Line_str.start_y = IN_LinearDim_str->sun_y1 ;
	Line_str.end_x = IN_LinearDim_str->sun_x2 ;
	Line_str.end_y = IN_LinearDim_str->sun_y2 ;
	ret = linestr_rule_check(&Line_str) ;
	if (ret < 0)
		return ret ;
//�⏕���P
	ret = proj_check(IN_LinearDim_str->flg2,
					IN_LinearDim_str->ho1_x0,
					IN_LinearDim_str->ho1_y0,
					IN_LinearDim_str->ho1_x1,
					IN_LinearDim_str->ho1_y1,
					IN_LinearDim_str->ho1_x2,
					IN_LinearDim_str->ho1_y2) ;
	if (ret < 0) 
		return ret ;

//�⏕���Q
	ret = proj_check(IN_LinearDim_str->flg3,
					IN_LinearDim_str->ho2_x0,
					IN_LinearDim_str->ho2_y0,
					IN_LinearDim_str->ho2_x1,
					IN_LinearDim_str->ho2_y1,
					IN_LinearDim_str->ho2_x2,
					IN_LinearDim_str->ho2_y2) ;
	if (ret < 0) 
		return ret ;
//���P
	ret = arr_check(IN_LinearDim_str->arr1_code1,
					IN_LinearDim_str->arr1_code2,
					IN_LinearDim_str->arr1_r) ;
	if (ret < 0) 
		return ret ;

//���Q
	ret = arr_check(IN_LinearDim_str->arr2_code1,
					IN_LinearDim_str->arr2_code2,
					IN_LinearDim_str->arr2_r) ;
	if (ret < 0) 
		return ret ;

//�����v�f
	//���@�l�̗L���t���O��0�܂���1�ł͂Ȃ��Ƃ�
	if ((IN_LinearDim_str->flg4 < 0) 
			|| (IN_LinearDim_str->flg4 > 1)){
		SXFErrorMsgC::RecordError(SXFTEXTFLAG,
									m_feature_name,
									3,
									m_InstanceID,
									IN_LinearDim_str->flg4,
									m_feature_name);
		return SXFTEXTFLAG;
	}
	if (IN_LinearDim_str->flg4 != 0){
		Text_Struct Text_str ;
		Text_str.layer = IN_LinearDim_str->layer ;
		Text_str.color = IN_LinearDim_str->color ;
		Text_str.font = IN_LinearDim_str->font ;
		Text_str.text_x = IN_LinearDim_str->text_x ;
		Text_str.text_y = IN_LinearDim_str->text_y ;
		Text_str.height = IN_LinearDim_str->height ;
		Text_str.width = IN_LinearDim_str->width ;
		Text_str.spc = IN_LinearDim_str->spc ;
		Text_str.angle = IN_LinearDim_str->angle ;
		Text_str.slant = IN_LinearDim_str->slant ;
		Text_str.b_pnt = IN_LinearDim_str->b_pnt ;
		Text_str.direct = IN_LinearDim_str->direct ;
		ret	= textstr_rule_check (&Text_str) ;
		if (ret < 0)
			return ret ;
	}
	return 0 ;
}
