/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_StrC.cpp						�쐬���F2000.04.12

	�P�D�N���X�T�v
		�����^�v�f��ێ����o�͂���N���X

	�Q�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.04.12	�{��(FQS)	�Ȃ��B
**/

#include "stdafx.h"
#include "SXFD_StrC.h"
#include "SXFutyConvKanjiC.h"
#include "SXFPart21FileC.h"
#include "max.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_StrC.cpp						�쐬���F2000.04.12

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void	SXFD_StrC::SXFD_StrC( char *data )
	����:	�^						������				���e
			char*					data			char�^�v�f

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.04.12	�{��(FQS)	�Ȃ��B
**/
SXFD_StrC::SXFD_StrC( char *data ) {
	m_Data = data ;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_StrC.cpp						�쐬���F2000.04.12

	�P�D�@�\�T�v
		�f�[�^�̃Z�b�g

	�Q�D�C���^�[�t�F�[�X
		void	SXFD_StrC::SetData( char* data )
	����:	�^						������				���e
			char*					data			char�^�v�f

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.04.12	�{��(FQS)	�Ȃ��B
**/
void	SXFD_StrC::SetData( char* data ) {
	m_Data = data ;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_StrC.cpp						�쐬���F2000.04.12

	�P�D�@�\�T�v
		�f�[�^���擾

	�Q�D�C���^�[�t�F�[�X
		void	LPCTSTR	SXFD_StrC::GetData( )
	����:	�^						������				���e
			�Ȃ�							

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.04.12	�{��(FQS)	�Ȃ��B
**/
LPCTSTR	SXFD_StrC::GetData( ) {
	return (LPCTSTR)m_Data ;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_StrC.cpp						�쐬���F2000.04.12

	�P�D�@�\�T�v
		�v�f�̏o��

	�Q�D�C���^�[�t�F�[�X
	void	WriteAttr(SXFPart21FileC *IN_file)
	����:	�^						������				���e
			SXFPart21FileC			*IN_file			̧�ٵ�޼ު��

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.04.12	�{��(FQS)	�Ȃ��B
**/
void SXFD_StrC::WriteAttr(SXFPart21FileC *IN_file){
	if (m_Data == DEF_DOLLAR){
		CString str;
		str.Format("%s",m_Data);
		IN_file->WriteString(str);
	}
	else{
		char name[MAXUNICODETEXT];
//		SXFutyConvKanjiC::ConvKanji(DEF_FROMJIS,(char*)(LPCTSTR)m_Data,name);
		//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
		//SXFutyConvKanjiC::FromJIS((char*)(LPCTSTR)m_Data,name);
		SXFutyConvKanjiC::FromJIS((char*)(LPCTSTR)m_Data,name,_countof(name));
		IN_file->WriteString(DEF_S_QUOTE);
		IN_file->WriteString(name);
		IN_file->WriteString(DEF_S_QUOTE);
	}
}

