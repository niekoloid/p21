/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_composite_curveC.cpp								�쐬���F2000.4.18

	�P�D�N���X�T�v
	�G���e�B�e�B�f�[�^�Ǘ�

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/

#include "stdafx.h"
#include "SXFD_StrC.h"
#include "SXFD_AggrC.h"
#include "SXFD_BoolC.h"
#include "SXFE_composite_curveC.h"
#include "SXF_EXT.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_composite_curveC.cpp								�쐬���F2000.4.18

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
	void	SXFE_composite_curveC(SXFD_StrC *str,SXFD_AggrC *aggr,SXFD_BoolC *bool1)
	����:	�^								������				���e
			SXFD_StrC						*str					��èè�ް�
			SXFD_AggrC						*aggr					��èè�ް�
			SXFD_BoolC						*bool1					��èè�ް�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/
SXFE_composite_curveC
	:: SXFE_composite_curveC(SXFD_StrC *str,SXFD_AggrC *aggr,SXFD_BoolC *bool1){

	m_Flg = 1;

	m_InstanceID = gl_InstanceID;
	gl_InstanceID += 10;

	m_Entity = DEF_COMPOSITE_CURVE;

	m_Data.AddTail(str);
	m_Data.AddTail(aggr);
	m_Data.AddTail(bool1);
}
