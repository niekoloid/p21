/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_IntC.cpp						�쐬���F2000.04.12

	�P�D�N���X�T�v
		�����^�v�f��ێ����o�͂���N���X

	�Q�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.04.12	�{��(FQS)	�Ȃ��B
**/

#include "stdafx.h"
#include "SXFD_IntC.h"
#include "SXFPart21FileC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_InstC.cpp						�쐬���F2000.04.12

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void	SXFD_IntC::SXFD_IntC(int data)
	
	����:	�^					������				���e
			int					data				int�^�v�f

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.04.12	�{��(FQS)	�Ȃ��B
**/
SXFD_IntC::SXFD_IntC(int data) {
	m_Data = data ;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_InstC.cpp						�쐬���F2000.04.12

	�P�D�@�\�T�v
		�f�[�^�̃Z�b�g

	�Q�D�C���^�[�t�F�[�X
		void	SXFD_IntC::SetData( int data )
		
	����:	�^					������				���e
			int					data				int�^�v�f	

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.04.12	�{��(FQS)	�Ȃ��B
**/
void	SXFD_IntC::SetData( int data ) {
	m_Data = data ;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_InstC.cpp						�쐬���F2000.04.12

	�P�D�@�\�T�v
		�f�[�^���擾

	�Q�D�C���^�[�t�F�[�X
		int	SXFD_IntC::GetData( )
	����	:	�^					������				���e
		�Ȃ�								

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.04.12	�{��(FQS)	�Ȃ��B
**/
int	SXFD_IntC::GetData( ) {
	return m_Data ;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_InstC.cpp						�쐬���F2000.04.12

	�P�D�@�\�T�v
		�v�f���o��

	�Q�D�C���^�[�t�F�[�X
		void	WriteAttr(SXFPart21FileC *IN_file)
	����:	�^					������				���e
			SXFPart21FileC		*IN_file			̧�ٵ�޼ު��		

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.04.12	�{��(FQS)	�Ȃ��B
**/
void	SXFD_IntC::WriteAttr(SXFPart21FileC *IN_file) {
	CString int_str;
	int_str.Format("%d",m_Data);
	IN_file->WriteString(int_str);
}

