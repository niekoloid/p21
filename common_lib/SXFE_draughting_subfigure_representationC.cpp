/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_draughting_subfigure_representationC.cpp								�쐬���F2000.4.18

	�P�D�N���X�T�v
	�G���e�B�e�B�f�[�^�Ǘ�

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/

#include "stdafx.h"
#include "SXFD_StrC.h"
#include "SXFD_AggrC.h"
#include "SXFE_draughting_subfigure_representationC.h"
#include "SXF_EXT.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_draughting_subfigure_representationC.cpp								�쐬���F2000.4.18

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
	void	SXFE_draughting_subfigure_representationC(SXFD_StrC *str,
													  SXFD_AggrC *aggr,
													  SXFD_InstC *inst)
	����:	�^								������				���e
			SXFD_StrC						*str				��èè�ް�
			SXFD_AggrC						*aggr				��èè�ް�
			SXFD_InstC						*inst				��èè�ް�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/
SXFE_draughting_subfigure_representationC
	:: SXFE_draughting_subfigure_representationC(SXFD_StrC *str,SXFD_AggrC *aggr,SXFD_InstC *inst){

	m_Flg = 1;

	m_InstanceID = gl_InstanceID;
	gl_InstanceID += 10;

	m_Entity = DEF_DRAUGHTING_SUBFIGURE_REPRESENTATION;

	m_Data.AddTail(str);
	m_Data.AddTail(aggr);
	m_Data.AddTail(inst);
}
