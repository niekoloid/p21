/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_circleC.cpp								�쐬���F2000.4.18

	�P�D�N���X�T�v
	�G���e�B�e�B�f�[�^�Ǘ�

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/

#include "stdafx.h"
#include "SXFD_RealC.h"
#include "SXFD_StrC.h"
#include "SXFE_circleC.h"
#include "SXF_EXT.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_circleC.cpp								�쐬���F2000.4.18

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
	void	SXFE_circleC(SXFD_StrC *str,SXFD_InstC *inst1,SXFD_RealC *rea)
	����:	�^							������				���e
			SXFD_StrC					*str			��èè�ް�
			SXFD_InstC					*inst1			��èè�ް�
			SXFD_RealC					*rea			��èè�ް�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/
SXFE_circleC :: SXFE_circleC(SXFD_StrC *str,SXFD_InstC *inst1,SXFD_RealC *rea){

	m_Flg = 1;

	m_InstanceID = gl_InstanceID;
	gl_InstanceID += 10;

	m_Entity = DEF_CIRCLE;

	m_Data.AddTail(str);
	m_Data.AddTail(inst1);
	m_Data.AddTail(rea);
}
