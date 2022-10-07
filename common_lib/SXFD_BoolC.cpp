/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_BoolC.cpp						�쐬���F2000.04.12

	�P�D�N���X�T�v
		Bool�^�̗v�f��ێ����o�͂���N���X

	�Q�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.04.12	�{��(FQS)	�Ȃ��B
**/

#include "stdafx.h"
#include "SXFD_BoolC.h"
#include "SXFPart21FileC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_BoolC.cpp						�쐬���F2000.04.12

	�P�D�@�\�T�v
		�R���X�g���N�^
		
	�Q�D�C���^�[�t�F�C�X
	SXFD_BoolC(CString data)
	����:	�^				������				���e
			CString			data				BOOL�^�v�f
	���A�l	�Ȃ�
		

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.04.12	�{��(FQS)	�Ȃ��B
**/
SXFD_BoolC::SXFD_BoolC(CString data) {
	s_Data = data ;
	if(s_Data == DEF_TRUE)	m_Data = TRUE;
	else					m_Data = FALSE;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_BoolC.cpp						�쐬���F2000.04.12

	�P�D�@�\�T�v
		�R���X�g���N�^
		
	�Q�D�C���^�[�t�F�C�X
	SXFD_BoolC( )
	����:	�^				������				���e
			Bool			data				
	���A�l	�Ȃ�
		

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.04.12	�{��(FQS)	�Ȃ��B
**/
SXFD_BoolC::SXFD_BoolC(BOOL data) {
	m_Data = data ;
	if(m_Data)	s_Data = DEF_TRUE;
	else		s_Data = DEF_FALSE;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_BoolC.cpp						�쐬���F2000.04.12

	�P�D�@�\�T�v
		�f�[�^�̃Z�b�g
		
	�Q�D�C���^�[�t�F�C�X
	SXFD_BoolC( BOOL data  )
	����:	�^				������				���e
			BOOL			data		BOOL�^�v�f		
	���A�l	�Ȃ�
		

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.04.12	�{��(FQS)	�Ȃ��B
**/
void	SXFD_BoolC::SetData( BOOL data ) {
	m_Data = data ;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_BoolC.cpp						�쐬���F2000.04.12

	�P�D�@�\�T�v
		�f�[�^���擾
		
	�Q�D�C���^�[�t�F�C�X
	Bool SXFD_BoolC( )
	����:	�^				������				���e
			�Ȃ��B
			
	���A�l	�f�[�^
		

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.04.12	�{��(FQS)	�Ȃ��B
**/
BOOL	SXFD_BoolC::GetData( ) {
	return m_Data ;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_BoolC.cpp						�쐬���F2000.04.12

	�P�D�@�\�T�v
		�v�f���o��
		
	�Q�D�C���^�[�t�F�C�X
	SXFD_BoolC( )
	����:	�^					������				���e
			SXFPart21FileC*		IN_file				̧�ٵ�޼ު��
	
	���A�l	�Ȃ�
		
	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.04.12	�{��(FQS)	�Ȃ��B
**/
void	SXFD_BoolC::WriteAttr(SXFPart21FileC *IN_file){
	if(s_Data == DEF_UNKNOWN){
		IN_file->WriteString(DEF_D_U);
	}
	else if(s_Data == DEF_UNSPECIFIED){
		IN_file->WriteString(DEF_D_UNSPECIFIED);
	}
	else if (s_Data == DEF_NULL){
		IN_file->WriteString(DEF_D_NULL);
	}
	else if(m_Data){
		IN_file->WriteString(DEF_D_T);
	}
	else {
		IN_file->WriteString(DEF_D_F);
	}
}

