/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_EnumC.cpp						�쐬���F2000.04.12

	�P�D�N���X�T�v
		�񋓌^�̗v�f��ێ����o�͂���N���X

	�Q�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.04.12	�{��(FQS)	�Ȃ��B
**/
#include "stdafx.h"
#include "SXFD_EnumC.h"
#include "SXFPart21FileC.h"

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
	SXFD_EnumC( )
	����:	�^				������				���e
			char*			data			char�^�f�[�^	
	���A�l	�Ȃ�
		

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.04.12	�{��(FQS)	�Ȃ��B
**/
SXFD_EnumC::SXFD_EnumC(char *data) {
	m_Data = data ;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_EnumC.cpp						�쐬���F2000.04.12

	�P�D�@�\�T�v
		�f�[�^�̃Z�b�g
		
	�Q�D�C���^�[�t�F�C�X
	SXFD_EnumC( )
	����:	�^				������				���e
			char*			data				char�^�f�[�^
	���A�l	�Ȃ�
		
	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.04.12	�{��(FQS)	�Ȃ��B
**/
void	SXFD_EnumC::SetData( char* data ) {
	m_Data = data ;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_BoolC.cpp						�쐬���F2000.04.12

	�P�D�@�\�T�v
		�f�[�^���擾
		
	�Q�D�C���^�[�t�F�C�X
	SXFD_EnumC()
	����:	�^				������				���e
			�Ȃ�				
	���A�l	�v�f
		
	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.04.12	�{��(FQS)	�Ȃ��B
**/
LPCTSTR	SXFD_EnumC::GetData( ) {
	return (LPCTSTR)m_Data ;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_BoolC.cpp						�쐬���F2000.04.12

	�P�D�@�\�T�v
		�v�f���o��

	�Q�D�C���^�[�t�F�C�X
	SXFD_EnumC( )
	����:	�^					������				���e
			SXFPart21FileC*		IN_file				̧�ٵ�޼ު��
	���A�l	�Ȃ�
		
	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.04.12	�{��(FQS)	�Ȃ��B
**/
void	SXFD_EnumC::WriteAttr(SXFPart21FileC *IN_file){
	CString data_str;
	data_str.Format(".%s.",m_Data);
	IN_file->WriteString(data_str);
}