/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_composite_curve_segmentC.cpp								�쐬���F2000.4.18

	�P�D�N���X�T�v
	�G���e�B�e�B�f�[�^�Ǘ�

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/

#include "stdafx.h"
#include "SXFD_EnumC.h"
#include "SXFD_BoolC.h"
#include "SXFE_composite_curve_segmentC.h"
#include "SXF_EXT.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_composite_curve_segmentC.cpp								�쐬���F2000.4.18

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
	void	SXFE_composite_curve_segmentC(SXFD_EnumC *enum1,SXFD_BoolC *bool1,SXFD_InstC *inst1)
	����:	�^								������				���e
			SXFD_EnumC						*enum1					��èè�ް�
			SXFD_BoolC						*bool1					��èè�ް�
			SXFD_InstC						*inst1					��èè�ް�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/
SXFE_composite_curve_segmentC
	:: SXFE_composite_curve_segmentC(SXFD_EnumC *enum1,SXFD_BoolC *bool1,SXFD_InstC *inst1){

	m_Flg = 1;

	m_InstanceID = gl_InstanceID;
	gl_InstanceID += 10;

	m_Entity = DEF_COMPOSITE_CURVE_SEGMENT;

	m_Data.AddTail(enum1);
	m_Data.AddTail(bool1);
	m_Data.AddTail(inst1);
}
