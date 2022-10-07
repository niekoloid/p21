/**
	All Rights Reserved,(c) JACIC 2001
	SXFErrorRecC.cpp									�쐬���F2000.3.27

	�P�D�N���X�T�v
	�G���[���b�Z�[�W���t�@�C���ɏo�͂���N���X

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.3.27			�{��(FQS)			�Ȃ��B
	�X�V			2015.04.27			T.Matsushima		SXFPopMsg_AP202()���d�l���ʂ�ɓ��삵�Ă��Ȃ��̂ŏC��

**/
#include "stdafx.h"
#include <string.h>
#include "SXFErrorRecC.h"
#include "SXFErrorMsgStruct.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFErrorRecC.cpp									�쐬���F2000.3.27

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
	SXFErrorRecC(SXFErrorCode IN_ecode, CString IN_Name);

	����:	�^				������			���e
			SXFErrorCode	IN_ecode		�G���[���b�Z�[�W�ԍ�
			char*			IN_Name			�t�B�[�`����

	���A�l	�Ȃ��B
	

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.3.27			�{��(FQS)			�Ȃ��B

**/
SXFErrorRecC::SXFErrorRecC(SXFErrorCode IN_ecode,const char* IN_Name)	// Add const
{
	m_Name = IN_Name;
	m_Code = IN_ecode;

// GetErrorText()�̓G���[���쐬���鎞�ɌĂяo���B	SXFPopMsg_AP202()�C��
//	m_Text = GetErrorText(IN_ecode);
	m_Text = NULL;
}

// SXFPopMsg_AP202()�C��	2015.04.27	T.Matsushima
// m_Text �� new�Ŋm�ۂ���悤�ɕύX�������� �f�X�g���N�^�ǉ�
SXFErrorRecC::~SXFErrorRecC()
{
	if(m_Text){
		delete[] m_Text;
	}
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFErrorRecC.cpp									�쐬���F2000.3.27

	�P�D�@�\�T�v
		�G���[���b�Z�[�W�̐ݒ�

	�Q�D�C���^�[�t�F�[�X	
	void SetText(char *IN_text);

	����:	�^				������			���e
			char*			IN_Text			�G���[���b�Z�[�W

	���A�l	�Ȃ��B

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.3.27			�{��(FQS)			�Ȃ��B

**/
/*	�폜	SXFPopMsg_AP202()�C��	2015.04.27	T.Matsushima
void SXFErrorRecC::SetText(char *IN_text){
	m_Text = IN_text;
}
*/
/**
	All Rights Reserved,(c) JACIC 2001
	SXFErrorRecC.cpp									�쐬���F2000.3.27

	�P�D�@�\�T�v
	�G���[���b�Z�[�W�����O�t�@�C���֏o�͂���

	�Q�D�C���^�[�t�F�[�X
	void WriteLog(ofstream *IN_log_file);

	����:	�^				������			���e
			ofstream		IN_log_file		�G���[���O�t�@�C��

	���A�l	�Ȃ��B

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.3.27			�{��(FQS)			�Ȃ��B

**/
void SXFErrorRecC::WriteLog(ofstream *IN_log_file){
	*IN_log_file << m_Name << " : " << -m_Code << " : " << m_Text << endl;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFErrorRecC.cpp									�쐬���F2000.3.27

	�P�D�@�\�T�v
	�G���[���b�Z�[�W�̎擾

	�Q�D�C���^�[�t�F�[�X
	char* GetText();

	����:	�^				������			���e
			�Ȃ��B

	���A�l	�����om_Text��ԋp����B

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.3.27			�{��(FQS)			�Ȃ��B

**/
const char* SXFErrorRecC::GetText(){
	return m_Text;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFErrorRecC.cpp									�쐬���F2000.3.27

	�P�D�@�\�T�v
	�G���[�R�[�h�̎擾

	�Q�D�C���^�[�t�F�[�X
	int GetCode();

	����:	�^				������			���e
			�Ȃ��B

	���A�l	�����om_Code��ԋp����B

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.3.27			�{��(FQS)			�Ȃ��B

**/
int SXFErrorRecC::GetCode(){
	return (int)m_Code;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFErrorRecC.cpp									�쐬���F2000.3.27

	�P�D�@�\�T�v
	�G���[�t�B�[�`�����̎擾

	�Q�D�C���^�[�t�F�[�X
	char* GetName();

	����:	�^				������			���e
			�Ȃ��B

	���A�l	�����om_Name��ԋp����B

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.3.27			�{��(FQS)			�Ȃ��B

**/
const char* SXFErrorRecC::GetName(){
	return m_Name;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFErrorRecC.cpp									�쐬���F2000.3.27

	�P�D�@�\�T�v
	�G���[���b�Z�[�W�̍쐬

	�Q�D�C���^�[�t�F�[�X
	char*	GetErrorText(SXFErrorCode IN_Code);

	����:	�^				������			���e
			SXFErrorCode	IN_Code			�G���[���b�Z�[�W�ԍ�

	���A�l	�G���[���b�Z�[�W�ԍ��ɑΉ����郁�b�Z�[�W��ԋp�B

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.3.27			�{��(FQS)			�Ȃ��B

**/
char* SXFErrorRecC::GetErrorText(SXFErrorCode IN_Code) {
	char	*ret_Str ;
	ret_Str = "" ;

	for(int num=0 ; ErrorMsg[num].m_Text ; num++ ) {
		if( ErrorMsg[num].m_Code == IN_Code ) {
			ret_Str = ErrorMsg[num].m_Text ;
			break ;
		}
	}
	return ret_Str ;
}

// SXFPopMsg_AP202()�C��	2015.04.27	T.Matsushima
// �������X�g�ւ̃|�C���^����G���[���b�Z�[�W�쐬
void SXFErrorRecC::MakeErrorMessage(va_list args)
{
	if(m_Text){
		delete[] m_Text;
	}
	const char *fmt = GetErrorText(m_Code);
//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
	const int TextBufSize = _vscprintf(fmt, args) + 1;
	m_Text = new char[TextBufSize];
	vsprintf_s(m_Text, TextBufSize, fmt, args);
}
