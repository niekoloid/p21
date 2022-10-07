/**
	All Rights Reserved,(c)JACIC 2001
	SXFUserdefined_color_checkC.cpp					�쐬���F2000.03.29

	�P�D�N���X�T�v
	���[�U��`�F�t�B�[�`���̃��[���`�F�b�N���s���N���X
	
	�Q�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.03.29	�ЎR(FQS)	�Ȃ��B
**/

#include "stdafx.h"
#include "SXFUserdefined_color_checkC.h"
#include "SXFErrorMsgC.h"
#include "max.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFUserdefined_color_checkC.cpp				 	�쐬���F2000.03.29

	�P�D�@�\�T�v 
		�R���X�g���N�^
		
	�Q�D�C���^�[�t�F�C�X
		void	SXFUserdefined_color_checkC::SXFUserdefined_color_checkC()
		
	����	�F	�^		������				���e
		�Ȃ�

	���A�l	�F	�Ȃ�

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.03.29	�ЎR(FQS)	�Ȃ��B
**/
SXFUserdefined_color_checkC::SXFUserdefined_color_checkC()
{
}
/**
	All Rights Reserved,(c)JACIC 2001
	SXFUserdefined_color_checkC.cpp				 	�쐬���F2000.03.29

	�P�D�@�\�T�v 
		�f�X�g���N�^
		
	�Q�D�C���^�[�t�F�C�X
		void	SXFUserdefined_color_checkC::~SXFUserdefined_color_checkC ()
			
	����	�F	�^						������					���e
		�Ȃ�

	���A�l	�F	�Ȃ�

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.03.29	�ЎR(FQS)	�Ȃ��B
**/
SXFUserdefined_color_checkC::~SXFUserdefined_color_checkC ()
{
}
/**
	All Rights Reserved,(c)JACIC 2001
	SXFUserdefined_color_checkC.cpp				 	�쐬���F2000.03.29

	�P�D�@�\�T�v 
		���[�U��`�F�t�B�[�`���̑����ȊO�̃��[���`�F�b�N
		
	�Q�D�C���^�[�t�F�C�X
		int		SXFUserdefined_color_checkC::str_rule_check (
					Userdefined_Colour_Struct IN_Userdefined_color_str)

	����	�F	�^						������						���e
			Userdefined_Colour_Struct	IN_Userdefined_color_str	�\����

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.03.29	�ЎR(FQS)	�Ȃ��B
**/
int SXFUserdefined_color_checkC::str_rule_check (Userdefined_Colour_Struct* IN_Userdefined_color_str) 
{
	//R�l��0����255�łȂ��Ƃ�
	if ((IN_Userdefined_color_str->red < 0) 
		|| (IN_Userdefined_color_str->red > MAXRGB)){
		SXFErrorMsgC::RecordError(SXFRGBERROR,
									m_feature_name,
									1,
									IN_Userdefined_color_str->red);
		return SXFRGBERROR;
	}
	//G�l��0����255�łȂ��Ƃ�
	if ((IN_Userdefined_color_str->green < 0) 
		|| (IN_Userdefined_color_str->green > MAXRGB)){
		SXFErrorMsgC::RecordError(SXFRGBERROR,
									m_feature_name,
									1,
									IN_Userdefined_color_str->green);
		return SXFRGBERROR;
	}
	//B�l��0����255�łȂ��Ƃ�
	if ((IN_Userdefined_color_str->blue < 0) 
		|| (IN_Userdefined_color_str->blue > MAXRGB)){
		SXFErrorMsgC::RecordError(SXFRGBERROR,
									m_feature_name,
									1,
									IN_Userdefined_color_str->blue);
		return SXFRGBERROR;
	}

	return 0 ;
}
/**
	All Rights Reserved,(c)JACIC 2001
	SXFUserdefined_color_checkC.cpp				 	�쐬���F2000.03.29

	�P�D�@�\�T�v 
		���[�U��`�F�t�B�[�`���̃��[���`�F�b�N
		
	�Q�D�C���^�[�t�F�C�X
		int		SXFUserdefined_color_checkC::Feature_rule_check(
					Userdefined_Colour_Struct IN_Userdefined_color_str)
		
	����	�F	�^						������						���e
			Userdefined_Colour_Struct	IN_Userdefined_color_str

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.03.29	�ЎR(FQS)	�Ȃ��B
**/
int SXFUserdefined_color_checkC::Feature_rule_check(Userdefined_Colour_Struct* IN_Userdefined_color_str)
{
	int ret ;

	m_feature_name = DEF_USERDEFINED_COLOR;

	ret  = str_rule_check(IN_Userdefined_color_str) ;
	return ret ;
}
