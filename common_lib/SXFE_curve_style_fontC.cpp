/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_curve_style_fontC.cpp								�쐬���F2000.4.18

	�P�D�N���X�T�v
	�G���e�B�e�B�f�[�^�Ǘ�

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/

#include "stdafx.h"
#include "SXFD_StrC.h"
#include "SXFD_AggrC.h"
#include "SXFE_curve_style_fontC.h"
#include "SXF_EXT.h"
#include "SXFD_ListAggrC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_curve_style_fontC.cpp								�쐬���F2000.4.18

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
	void	SXFE_curve_style_fontC(SXFD_StrC *str,SXFD_AggrC *aggr1)
	����:	�^								������				���e
			SXFD_StrC						*str				��èè�ް�
			SXFD_AggrC						*aggr1				��èè�ް�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/
SXFE_curve_style_fontC
	::SXFE_curve_style_fontC(SXFD_StrC *str,SXFD_AggrC *aggr1){

	m_Flg = 1;

	m_InstanceID = gl_InstanceID;
	gl_InstanceID += 10;

	m_Entity = DEF_CURVE_STYLE_FONT;

	m_Data.AddTail(str);
	m_Data.AddTail(aggr1);
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_curve_style_fontC.cpp								�쐬���F2000.4.18

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
	void	SXFE_curve_style_fontC(SXFD_StrC *str,SXFD_ListAggrC *aggr1)
	����:	�^								������				���e
			SXFD_StrC						*str				��èè�ް�
			SXFD_ListAggrC					*aggr1				��èè�ް�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/
SXFE_curve_style_fontC
::SXFE_curve_style_fontC(SXFD_StrC *str,SXFD_ListAggrC *aggr1){

	m_Flg = 1;

	m_InstanceID = gl_InstanceID;
	gl_InstanceID += 10;

	m_Entity = DEF_CURVE_STYLE_FONT;

	m_Data.AddTail(str);
	m_Data.AddTail(aggr1);
}
