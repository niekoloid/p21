/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_ellipseC.cpp								�쐬���F2000.4.18

	�P�D�N���X�T�v
	�G���e�B�e�B�f�[�^�Ǘ�

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/

#include "stdafx.h"
#include "SXFD_StrC.h"
#include "SXFD_RealC.h"
#include "SXFE_ellipseC.h"
#include "SXF_EXT.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_ellipseC.cpp								�쐬���F2000.4.18

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
	void	SXFE_ellipseC(SXFD_StrC *str,SXFD_InstC *inst1,SXFD_RealC *rea1,SXFD_RealC *rea2)
	����:	�^								������				���e
			SXFD_StrC						*str				��èè�ް�
			SXFD_InstC						*inst1				��èè�ް�
			SXFD_RealC						*rea1				��èè�ް�
			SXFD_RealC						*rea2				��èè�ް�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/
SXFE_ellipseC :: SXFE_ellipseC(SXFD_StrC *str,SXFD_InstC *inst1,SXFD_RealC *rea1,SXFD_RealC *rea2){

	m_Flg = 1;

	m_InstanceID = gl_InstanceID;
	gl_InstanceID += 10;

	m_Entity = DEF_ELLIPSE;

	m_Data.AddTail(str);
	m_Data.AddTail(inst1);
	m_Data.AddTail(rea1);
	m_Data.AddTail(rea2);
}
