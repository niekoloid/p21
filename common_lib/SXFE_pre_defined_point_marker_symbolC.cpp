/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_pre_defined_point_marker_symbolC.cpp								�쐬���F2000.4.18

	�P�D�N���X�T�v
	�G���e�B�e�B�f�[�^�Ǘ�

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/

#include "stdafx.h"
#include "SXFD_StrC.h"
#include "SXFE_pre_defined_point_marker_symbolC.h"
#include "SXF_EXT.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_pre_defined_point_marker_symbolC.cpp								�쐬���F2000.4.18

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
	void	SXFE_pre_defined_point_marker_symbolC(SXFD_StrC* str1)
	����:	�^				������			���e
			SXFD_StrC* 		str1				��èè�ް�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/
SXFE_pre_defined_point_marker_symbolC
::SXFE_pre_defined_point_marker_symbolC(SXFD_StrC* str1){

	m_Flg = 1;

	m_InstanceID = gl_InstanceID;
	gl_InstanceID += 10;

	m_Entity = DEF_PRE_DEFINED_POINT_MARKER_SYMBOL;

	m_Data.AddTail(str1);

}
