/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_polylineC.cpp								�쐬���F2000.4.18

	�P�D�N���X�T�v
	�G���e�B�e�B�f�[�^�Ǘ�

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/

#include "stdafx.h"
#include "SXFD_StrC.h"
#include "SXFD_AggrC.h"
#include "SXFE_polylineC.h"
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
	SXFE_polylineC.cpp								�쐬���F2000.4.18

	�P�D�@�\�T�v
		�R���X�g���N�^
	
	�Q�D�C���^�[�t�F�[�X
	void	 SXFE_polylineC(SXFD_StrC *str,SXFD_AggrC *aggr)
	����:	�^				������			���e
			SXFD_StrC 		*str				��èè�ް�
			SXFD_AggrC 		*aggr				��èè�ް�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/
SXFE_polylineC :: SXFE_polylineC(SXFD_StrC *str,SXFD_AggrC *aggr){

	m_Flg = 1;

	m_InstanceID = gl_InstanceID;
	gl_InstanceID += 10;

	m_Entity = DEF_POLYLINE;

	m_Data.AddTail(str);
	m_Data.AddTail(aggr);
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_polylineC.cpp								�쐬���F2000.4.18

	�P�D�@�\�T�v
		�R���X�g���N�^
	
	�Q�D�C���^�[�t�F�[�X
	void	SXFE_polylineC(SXFD_StrC *str,SXFD_ListAggrC *aggr)
	����:	�^				������			���e
			SXFD_StrC 		*str				��èè�ް�
			SXFD_ListAggrC 	*aggr				��èè�ް�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/
SXFE_polylineC :: SXFE_polylineC(SXFD_StrC *str,SXFD_ListAggrC *aggr){

	m_Flg = 1;

	m_InstanceID = gl_InstanceID;
	gl_InstanceID += 10;

	m_Entity = DEF_POLYLINE;

	m_Data.AddTail(str);
	m_Data.AddTail(aggr);
}
