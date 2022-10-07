/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_TypeC.cpp						�쐬���F2000.04.12

	�P�D�N���X�T�v
		Type�^�v�f��ێ����o�͂���N���X

	�Q�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.04.12	�{��(FQS)	�Ȃ��B
**/

#include "stdafx.h"
#include "SXFD_TypeC.h"
#include "SXFPart21FileC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_TypeC.cpp						�쐬���F2000.04.12

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void	SXFD_TypeC(char *data)
	����:	�^						������				���e
			char					*data		type�^�v�f

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.04.12	�{��(FQS)	�Ȃ��B
**/
SXFD_TypeC::SXFD_TypeC(char *data) {
	m_Data = data ;
	m_Next = NULL;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_TypeC.cpp						�쐬���F2000.04.12

	�P�D�@�\�T�v
		�f�[�^�̃Z�b�g

	�Q�D�C���^�[�t�F�[�X
	void	SXFD_TypeC::SetNext( SXFInstanceC* next )
	����:	�^								������				���e
			SXFInstanceC*					next			�ݽ�ݽ

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.04.12	�{��(FQS)	�Ȃ��B
**/
void	SXFD_TypeC::SetNext( SXFInstanceC* next ) {
	m_Next = next ;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_TypeC.cpp						�쐬���F2000.04.12

	�P�D�@�\�T�v
		�f�[�^���擾

	�Q�D�C���^�[�t�F�[�X
	LPCTSTR	SXFD_TypeC::GetData( )
	����:	�^								������				���e
			�Ȃ�					

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.04.12	�{��(FQS)	�Ȃ��B
**/
LPCTSTR	SXFD_TypeC::GetData( ) {
	return (LPCTSTR)m_Data ;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_TypeC.cpp						�쐬���F2000.04.12

	�P�D�@�\�T�v
		�f�[�^���擾

	�Q�D�C���^�[�t�F�[�X
		SXFInstanceC*	SXFD_TypeC::GetNext( )	
	����:	�^								������				���e
			�Ȃ�					

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.04.12	�{��(FQS)	�Ȃ��B
**/
SXFInstanceC* SXFD_TypeC::GetNext( ){
	return m_Next;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_TypeC.cpp						�쐬���F2000.04.12

	�P�D�@�\�T�v
		�v�f���o��

	�Q�D�C���^�[�t�F�[�X
		void	WriteAttr(SXFPart21FileC *IN_file)
	����:	�^								������				���e
			SXFPart21FileC					*IN_file	̧�ٵ�޼ު��

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.04.12	�{��(FQS)	�Ȃ��B
**/
void SXFD_TypeC::WriteAttr(SXFPart21FileC *IN_file){
	IN_file->WriteString(m_Data);
	IN_file->WriteString("(");
	if(m_Next != NULL) 
		m_Next->WriteAttr(IN_file);
	IN_file->WriteString(")");
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_TypeC.cpp						�쐬���F2000.04.12

	�P�D�@�\�T�v
		�C���X�^���X���o��

	�Q�D�C���^�[�t�F�[�X
		void	WriteP21(SXFPart21FileC *IN_file)
	����:	�^								������				���e
			SXFPart21FileC					*IN_file	̧�ٵ�޼ު��

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.04.12	�{��(FQS)	�Ȃ��B
**/
void SXFD_TypeC::WriteP21(SXFPart21FileC *IN_file){
	if(m_Next != NULL)
		m_Next->WriteP21(IN_file);
}
