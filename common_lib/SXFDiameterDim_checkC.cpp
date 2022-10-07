/**
	All Rights Reserved,(c) JACIC 2001
	SXFDiameterDim_checkC.cpp								�쐬���F2000.4.3

	�P�D�N���X�T�v
	���a���@�t�B�[�`���̃��[���`�F�b�N���s���N���X

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/

#include "stdafx.h"
#include "SXFDiameterDim_checkC.h"
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
	SXFDiameterDim_checkC.cpp								�쐬���F2000.4.3

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void	SXFDiameterDim_checkC::SXFDiameterDim_checkC()
		
	����	�F	�^		������				���e
		�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/
SXFDiameterDim_checkC::SXFDiameterDim_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFDiameterDim_checkC.cpp								�쐬���F2000.4.3

	�P�D�@�\�T�v
		�f�X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void	SXFDiameterDim_checkC::~SXFDiameterDim_checkC()
		
	����	�F	�^		������				���e
		�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/
SXFDiameterDim_checkC::~SXFDiameterDim_checkC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFDiameterDim_checkC.cpp								�쐬���F2000.4.3

	�P�D�@�\�T�v
		���a���@�t�B�[�`���̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int Feature_rule_check(DiameterDim_Struct IN_diameterdim_str,
							SXFTableManagerC* IN_TableManager,
							CString IN_InstanceID,
							SXFComInfoC* IN_Info);

	����:	�^					������			���e
			DiameterDim_Struct	IN_diameterdim_str	���a���@�\����
			SXFTableManagerC*	IN_TableManager		��`�e�[�u���v�f�Ǘ��I�u�W�F�N�g		
			CString				IN_InstanceID		�C���X�^���XID
			SXFComInfoC*		IN_Info				���ʏ��

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/
int SXFDiameterDim_checkC::Feature_rule_check(DiameterDim_Struct* IN_diameterdim_str,
											  SXFTableManagerC* IN_TableManager,
											  CString IN_InstanceID,
											  SXFComInfoC* IN_Info)
{
	int ret ;

	m_feature_name = DEF_DIAMETER_DIM;
	m_TableManager = IN_TableManager;
	m_InstanceID = IN_InstanceID;
	m_ComInfo = IN_Info;
	/** �����̃��[���`�F�b�N **/
	ret  = attr_rule_check(IN_diameterdim_str) ;
	if (ret < 0)
		return ret ;
	/** �����ȊO�̃��[���`�F�b�N **/
	ret = str_rule_check(IN_diameterdim_str);
	if (ret < 0)
		return ret;

	return 0 ;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFDiameterDim_checkC.cpp								�쐬���F2000.4.3

	�P�D�@�\�T�v
		���a���@�t�B�[�`���̑����̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int attr_rule_check(DiameterDim_Struct IN_diameterdim_str);

	����:	�^					������				���e
			DiameterDim_Struct	IN_diameterdim_str	���a���@�\����

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/
int SXFDiameterDim_checkC::attr_rule_check(DiameterDim_Struct* IN_diameterdim_str)
{
	m_layer = IN_diameterdim_str->layer ;
	m_color = IN_diameterdim_str->color ;
	m_type = IN_diameterdim_str->type ;
	m_line_width = IN_diameterdim_str->line_width ;
	m_font = IN_diameterdim_str->font ;
	
	int ret = DimFeature_Check(IN_diameterdim_str->flg) ;
	return ret ;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFDiameterDim_checkC.cpp								�쐬���F2000.4.3

	�P�D�@�\�T�v
		���a���@�t�B�[�`���̑����ȊO�̃��[���`�F�b�N

	�Q�D�C���^�[�t�F�[�X
	int str_rule_check(DiameterDim_Struct IN_diameterdim_str)

	����:	�^					������				���e
			DiameterDim_Struct	IN_diameterdim_str	���a���@�\����

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/
int SXFDiameterDim_checkC::str_rule_check(DiameterDim_Struct* IN_diameterdim_str)
{
	int ret = 0 ;
//���@��
	Line_Struct Line_str;

	Line_str.color = IN_diameterdim_str->color ;
	Line_str.end_x = IN_diameterdim_str->sun_x1 ;
	Line_str.end_y = IN_diameterdim_str->sun_y1 ;
	Line_str.layer = IN_diameterdim_str->layer ;
	Line_str.line_width = IN_diameterdim_str->line_width ;
	Line_str.start_x = IN_diameterdim_str->sun_x2 ;
	Line_str.start_y = IN_diameterdim_str->sun_y2 ;
	Line_str.type = IN_diameterdim_str->type ;

	ret = linestr_rule_check(&Line_str) ;
	if (ret < 0)
		return ret ;

//���P
	ret = arr_check(IN_diameterdim_str->arr1_code1,
					IN_diameterdim_str->arr1_code2,
					IN_diameterdim_str->arr1_r) ;
	if (ret < 0) 
		return ret ;

//���Q
	ret = arr_check(IN_diameterdim_str->arr2_code1,
					IN_diameterdim_str->arr2_code2,
					IN_diameterdim_str->arr2_r) ;
	if (ret < 0) 
		return ret ;

//�����v�f
	Text_Struct Text_str;
	int flg;

	flg = IN_diameterdim_str->flg ;
	Text_str.layer = IN_diameterdim_str->layer ;
	Text_str.color = IN_diameterdim_str->color ;
	Text_str.font = IN_diameterdim_str->font ;
	Text_str.text_x = IN_diameterdim_str->text_x ;
	Text_str.text_y = IN_diameterdim_str->text_y ;
	Text_str.height = IN_diameterdim_str->height ;
	Text_str.width = IN_diameterdim_str->width ;
	Text_str.spc = IN_diameterdim_str->spc ;
	Text_str.angle = IN_diameterdim_str->angle ;
	Text_str.slant = IN_diameterdim_str->slant ;
	Text_str.b_pnt = IN_diameterdim_str->b_pnt ;
	Text_str.direct = IN_diameterdim_str->direct ;

	//���@�l�̗L���t���O��0�܂���1�ł͂Ȃ��Ƃ�
	if ((flg < 0) || (flg > 1)){
		SXFErrorMsgC::RecordError(SXFTEXTFLAG,
									m_feature_name,
									3,
									m_InstanceID,
									flg,
									m_feature_name);
		return SXFTEXTFLAG;
	}
	if (flg != 0){
		ret	= textstr_rule_check (&Text_str) ;
		if (ret < 0)
			return ret ;
	}
	return 0 ;

}
