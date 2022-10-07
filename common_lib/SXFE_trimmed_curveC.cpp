/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_trimmed_curveC.cpp								�쐬���F2000.4.18

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
#include "SXFD_EnumC.h"
#include "SXFE_trimmed_curveC.h"
#include "SXF_EXT.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_trimmed_curveC.cpp								�쐬���F2000.4.18

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
	void	SXFE_trimmed_curveC(SXFD_StrC *str,
								 SXFD_InstC *inst,
								 SXFD_AggrC *aggr1,
								 SXFD_AggrC *aggr2,
								 SXFD_BoolC *bo,
								 SXFD_EnumC *enu)
	����:	�^				������			���e
			SXFD_StrC 		*str		��èè�ް�
			SXFD_InstC 		*inst		��èè�ް�
			SXFD_AggrC 		*aggr1		��èè�ް�
			SXFD_AggrC 		*aggr2		��èè�ް�
			SXFD_BoolC 		*bo			��èè�ް�
			SXFD_EnumC 		*enu		��èè�ް�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/
SXFE_trimmed_curveC::SXFE_trimmed_curveC(SXFD_StrC *str,
								 SXFD_InstC *inst,
								 SXFD_AggrC *aggr1,
								 SXFD_AggrC *aggr2,
								 SXFD_BoolC *bo,
								 SXFD_EnumC *enu){

	m_Flg = 1;

	m_InstanceID = gl_InstanceID;
	gl_InstanceID += 10;

	m_Entity = DEF_TRIMMED_CURVE;

	m_Data.AddTail(str);
	m_Data.AddTail(inst);
	m_Data.AddTail(aggr1);
	m_Data.AddTail(aggr2);
	m_Data.AddTail(bo);
	m_Data.AddTail(enu);

}
