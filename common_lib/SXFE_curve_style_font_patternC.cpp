/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_curve_style_font_patternC.cpp								�쐬���F2000.4.18

	�P�D�N���X�T�v
	�G���e�B�e�B�f�[�^�Ǘ�

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/

#include "stdafx.h"
#include "SXFD_RealC.h"
#include "SXFE_curve_style_font_patternC.h"
#include "SXF_EXT.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_curve_style_font_patternC.cpp								�쐬���F2000.4.18

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
	void	SXFE_curve_style_font_patternC(SXFD_RealC *real1,SXFD_RealC *real2)
	����:	�^								������				���e
			SXFD_RealC						*real1				��èè�ް�
			SXFD_RealC						*real2				��èè�ް�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/
SXFE_curve_style_font_patternC
::SXFE_curve_style_font_patternC(SXFD_RealC *real1,SXFD_RealC *real2){

	m_Flg = 1;

	m_InstanceID = gl_InstanceID;
	gl_InstanceID += 10;

	m_Entity = DEF_CURVE_STYLE_FONT_PATTERN;

	m_Data.AddTail(real1);
	m_Data.AddTail(real2);

}
