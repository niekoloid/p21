/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_dimension_callout_relationshipC.cpp								�쐬���F2000.4.18

	�P�D�N���X�T�v
	�G���e�B�e�B�f�[�^�Ǘ�

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/

#include "stdafx.h"
#include "SXFD_StrC.h"
#include "SXFE_dimension_callout_relationshipC.h"
#include "SXF_EXT.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_dimension_callout_relationshipC.cpp								�쐬���F2000.4.18

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
	void	SXFE_dimension_callout_relationshipC(SXFD_StrC *str1,
												 SXFD_StrC *str2,
												 SXFD_InstC *inst1,
												 SXFD_InstC *inst2)
	����:	�^						������				���e
			SXFD_StrC				*str1				��èè�ް�
			SXFD_StrC				*str2				��èè�ް�
			SXFD_InstC				*inst1				��èè�ް�
			SXFD_InstC				*inst2				��èè�ް�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/
SXFE_dimension_callout_relationshipC
	:: SXFE_dimension_callout_relationshipC(SXFD_StrC *str1,SXFD_StrC *str2,SXFD_InstC *inst1,SXFD_InstC *inst2){

	m_Flg = 1;

	m_InstanceID = gl_InstanceID;
	gl_InstanceID += 10;

	m_Entity = DEF_DIMENSION_CALLOUT_RELATIONSHIP;

	m_Data.AddTail(str1);
	m_Data.AddTail(str2);
	m_Data.AddTail(inst1);
	m_Data.AddTail(inst2);
}
