/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_drawing_definitionC.cpp								�쐬���F2001.06.18

	�P�D�N���X�T�v
	�G���e�B�e�B�f�[�^�Ǘ�

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.18			���X��(FQS)			�Ȃ��B
	�X�V			2004.01.30			K.Naono				Ver3.0�Ή�

**/

#include "stdafx.h"
#include "SXFD_StrC.h"
#include "SXFE_drawing_definitionC.h"
#include "SXF_EXT.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_drawing_definitionC.cpp								�쐬���F2001.06.18

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
	void	SXFE_drawing_definitionC(SXFD_StrC* str)
	����:	�^								������				���e
			SXFD_StrC*						str				��èè�ް�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.18			���X��(FQS)			�Ȃ��B
	�X�V			2004.01.30			K.Naono				Ver3.0�Ή�

**/
SXFE_drawing_definitionC
::SXFE_drawing_definitionC(SXFD_StrC* str){

	m_Flg = 1;

	m_InstanceID = gl_InstanceID;
	gl_InstanceID += 10;

	m_Entity = DEF_DRAWING_DEFINITION;

	m_Data.AddTail(str);
	m_str = new SXFD_StrC(DEF_DOLLAR);
	m_Data.AddTail(m_str);
}

//	ADD(S)	Ver3.0�Ή�	K.Naono	04.01.30
SXFE_drawing_definitionC::SXFE_drawing_definitionC(
									SXFD_StrC*		IN_Str1,
									SXFD_StrC*		IN_Str2) {

	m_Flg = 1 ;

	m_InstanceID = gl_InstanceID ;
	gl_InstanceID += 10 ;

	m_Entity = DEF_DRAWING_DEFINITION ;

	m_Data.AddTail(IN_Str1) ;
	m_Data.AddTail(IN_Str2) ;
}
//	ADD(E)	Ver3.0�Ή�	K.Naono	04.01.30

/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_drawing_definitionC.cpp								�쐬���F2001.06.18

	�P�D�@�\�T�v
		�f�X�g���N�^

	�Q�D�C���^�[�t�F�[�X
	void	SXFE_drawing_definitionC::~SXFE_drawing_definitionC()
	����:	�^								������				���e
			�Ȃ�					

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.18			���X��(FQS)			�Ȃ��B

**/
SXFE_drawing_definitionC
::~SXFE_drawing_definitionC(){
}
