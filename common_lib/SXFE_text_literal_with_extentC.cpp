/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_text_literal_with_extentC.cpp								�쐬���F2000.4.18

	�P�D�N���X�T�v
	�G���e�B�e�B�f�[�^�Ǘ�

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/

#include "stdafx.h"
#include "SXFD_StrC.h"
#include "SXFD_EnumC.h"
#include "SXFE_text_literal_with_extentC.h"
#include "SXF_EXT.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_text_literal_with_extentC.cpp								�쐬���F2000.4.18

	�P�D�@�\�T�v
		�R���X�g���N�^
	
	�Q�D�C���^�[�t�F�[�X
	void	SXFE_text_literal_with_extentC(SXFD_StrC *str1,
										   SXFD_StrC *str2 ,
										   SXFD_InstC *ins1,
										   SXFD_StrC *str,
										   SXFD_EnumC *enu,
										   SXFD_InstC *ins2,
										   SXFD_InstC *ins3)

	����:	�^				������			���e
			SXFD_StrC 		*str1				��èè�ް�
			SXFD_StrC 		*str2				��èè�ް�
			SXFD_InstC 		*ins1				��èè�ް�
			SXFD_StrC 		*str				��èè�ް�
			SXFD_EnumC 		*enu				��èè�ް�
			SXFD_InstC 		*ins2				��èè�ް�
			SXFD_InstC 		*ins3				��èè�ް�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/
SXFE_text_literal_with_extentC
::SXFE_text_literal_with_extentC
(SXFD_StrC *str1,SXFD_StrC *str2 ,SXFD_InstC *ins1,SXFD_StrC *str,SXFD_EnumC *enu,SXFD_InstC *ins2,SXFD_InstC *ins3){

	m_Flg = 1;

	extern int InstanceID;
	m_InstanceID = gl_InstanceID;
	gl_InstanceID += 10;

	m_Entity = DEF_TEXT_LITERAL_WITH_EXTENT;

	m_Data.AddTail(str1);
	m_Data.AddTail(str2);
	m_Data.AddTail(ins1);
	m_Data.AddTail(str);
	m_Data.AddTail(enu);
	m_Data.AddTail(ins2);
	m_Data.AddTail(ins3);
}

