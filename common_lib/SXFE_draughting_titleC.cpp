/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_draughting_titleC.cpp								�쐬���F2000.4.18

	�P�D�N���X�T�v
	�G���e�B�e�B�f�[�^�Ǘ�

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/

#include "stdafx.h"
#include "SXFD_AggrC.h"
#include "SXFD_StrC.h"
#include "SXFE_draughting_titleC.h"
#include "SXF_EXT.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_draughting_titleC.cpp								�쐬���F2000.4.18

	�P�D�N���X�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
	void	SXFE_draughting_titleC(SXFD_AggrC *aggr,SXFD_StrC *str1,SXFD_StrC *str2)
	����:	�^								������				���e
			SXFD_AggrC						*aggr				��èè�ް�
			SXFD_StrC						*str1				��èè�ް�
			SXFD_StrC						*str2				��èè�ް�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/
SXFE_draughting_titleC
::SXFE_draughting_titleC(SXFD_AggrC *aggr,SXFD_StrC *str1,SXFD_StrC *str2){

	m_Flg = 1;

	m_InstanceID = gl_InstanceID;
	gl_InstanceID += 10;

	m_Entity = DEF_DRAUGHTING_TITLE;

	m_Data.AddTail(aggr);
	m_Data.AddTail(str1);
	m_Data.AddTail(str2);

}
