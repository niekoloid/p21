/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_splineC.cpp								�쐬���F2000.4.18

	�P�D�N���X�T�v
	�G���e�B�e�B�f�[�^�Ǘ�

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/

#include "stdafx.h"
#include "SXFD_StrC.h"
#include "SXFD_IntC.h"
#include "SXFD_AggrC.h"
#include "SXFD_BoolC.h"
#include "SXFE_splineC.h"
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
	SXFE_splineC.cpp								�쐬���F2000.4.18

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
	void	SXFE_splineC(SXFD_StrC *str,
						 SXFD_IntC *in,
						 SXFD_AggrC *aggr,
						 SXFD_BoolC *str2,
						 SXFD_BoolC *bool1,
						 SXFD_BoolC *str3)
	����:	�^				������			���e
			SXFD_StrC 		*str				��èè�ް�
			SXFD_IntC 		*in					��èè�ް�
			SXFD_AggrC 		*aggr				��èè�ް�
			SXFD_BoolC 		*str2				��èè�ް�
			SXFD_BoolC 		*bool1				��èè�ް�
			SXFD_BoolC 		*str3				��èè�ް�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/
SXFE_splineC :: SXFE_splineC(SXFD_StrC *str,SXFD_IntC *in,SXFD_AggrC *aggr,SXFD_BoolC *str2,SXFD_BoolC *bool1,SXFD_BoolC *str3){

	m_Flg = 1;

	m_InstanceID = gl_InstanceID;
	gl_InstanceID += 10;

	m_Entity = DEF_BEZIER_CURVE;

	m_Data.AddTail(str);
	m_Data.AddTail(in);
	m_Data.AddTail(aggr);
	m_Data.AddTail(str2);
	m_Data.AddTail(bool1);
	m_Data.AddTail(str3);
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_splineC.cpp								�쐬���F2000.4.18

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
	void	SXFE_splineC(SXFD_StrC *str,
						 SXFD_IntC *in,
						 SXFD_ListAggrC *aggr,
						 SXFD_BoolC *str2,
						 SXFD_BoolC *bool1,
						 SXFD_BoolC *str3)
	����:	�^				������			���e
			SXFD_StrC 		*str				��èè�ް�
			SXFD_IntC 		*in					��èè�ް�
			SXFD_ListAggrC 	*aggr				��èè�ް�
			SXFD_BoolC 		*str2				��èè�ް�
			SXFD_BoolC 		*bool1				��èè�ް�
			SXFD_BoolC 		*str3				��èè�ް�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/
SXFE_splineC :: SXFE_splineC(SXFD_StrC *str,SXFD_IntC *in,SXFD_ListAggrC *aggr,SXFD_BoolC *str2,SXFD_BoolC *bool1,SXFD_BoolC *str3){

	m_Flg = 1;

	m_InstanceID = gl_InstanceID;
	gl_InstanceID += 10;

	m_Entity = DEF_BEZIER_CURVE;

	m_Data.AddTail(str);
	m_Data.AddTail(in);
	m_Data.AddTail(aggr);
	m_Data.AddTail(str2);
	m_Data.AddTail(bool1);
	m_Data.AddTail(str3);
}
