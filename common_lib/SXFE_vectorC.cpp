/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_vectorC.cpp								�쐬���F2000.4.18

	�P�D�N���X�T�v
	�G���e�B�e�B�f�[�^�Ǘ�

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/

#include "stdafx.h"
#include "SXFD_StrC.h"
#include "SXFD_RealC.h"
#include "SXFE_vectorC.h"
#include "SXF_EXT.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_vectorC.cpp								�쐬���F2000.4.18

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
	void	SXFE_vectorC(SXFD_StrC *str,SXFD_InstC *inst,SXFD_RealC *real)
	����:	�^				������				���e
			SXFD_StrC 		*str		��èè�ް�
			SXFD_InstC 		*inst		��èè�ް�
			SXFD_RealC 		*real		��èè�ް�		

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/
SXFE_vectorC::SXFE_vectorC(SXFD_StrC *str,SXFD_InstC *inst,SXFD_RealC *real){

	m_Flg = 1;

	m_InstanceID = gl_InstanceID;
	gl_InstanceID += 10;

	m_Entity = DEF_VECTOR;

	m_Data.AddTail(str);
	m_Data.AddTail(inst);
	m_Data.AddTail(real);
}
