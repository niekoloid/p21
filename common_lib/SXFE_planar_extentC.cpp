/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_planar_extentC.cpp								�쐬���F2000.4.18

	�P�D�N���X�T�v
	�G���e�B�e�B�f�[�^�Ǘ�

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/

#include "stdafx.h"
#include "SXFD_StrC.h"
#include "SXFD_RealC.h"
#include "SXFE_planar_extentC.h"
#include "SXF_EXT.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_planar_extentC.cpp								�쐬���F2000.4.18

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
	void	SXFE_planar_extentC(SXFD_StrC *str,SXFD_RealC *real1,SXFD_RealC *real2)
	����:	�^				������			���e
			SXFD_StrC 		*str				��èè�ް�
			SXFD_RealC 		*real1				��èè�ް�
			SXFD_RealC		*real2				��èè�ް�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/
//text_string use
SXFE_planar_extentC
::SXFE_planar_extentC(SXFD_StrC *str,SXFD_RealC *real1,SXFD_RealC *real2){

	m_Flg = 1;

	m_InstanceID = gl_InstanceID;
	gl_InstanceID += 10;

	m_Entity = DEF_PLANAR_EXTENT;

	m_Data.AddTail(str);
	m_Data.AddTail(real1);
	m_Data.AddTail(real2);

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_planar_extentC.cpp								�쐬���F2000.4.18

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
	void	SXFE_planar_extentC(SXFD_RealC *real1,SXFD_RealC *real2)
	����:	�^				������			���e
			SXFD_RealC 		*real1				��èè�ް�
			SXFD_RealC 		*real2				��èè�ް�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/
SXFE_planar_extentC
::SXFE_planar_extentC(SXFD_RealC *real1,SXFD_RealC *real2){

	m_Flg = 1;

	m_InstanceID = gl_InstanceID;
	gl_InstanceID += 10;

	m_Entity = DEF_PLANAR_EXTENT;

	m_Data.AddTail(real1);
	m_Data.AddTail(real2);

}

