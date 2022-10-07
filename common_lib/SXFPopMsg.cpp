/**
	All Rights Reserved,(c) JACIC 2001
	SXFPopMsg.cpp								�쐬���F2000.4.29

	�P�D�@�\�T�v
		�G���[����ԋp����

	�Q�D�C���^�[�t�F�[�X
	static int SXFPopMsg_AP202(char *&OUT_name, int *OUT_msgno, char *&OUT_text);

	����:	�^				������			���e
			char			OUT_name		�t�B�[�`����
			int				OUT_msgno		���b�Z�[�W�ԍ�
			char			OUT_text		���b�Z�[�W

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.29			�{��(FQS)			�Ȃ��B
	�X�V			2015.04.27			T.Matsushima		SXFPopMsg_AP202()���d�l���ʂ�ɓ��삵�Ă��Ȃ��̂ŏC��

**/

#include "stdafx.h"
#include "SXFErrorRecC.h"
#include "SXFErrorMsgC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

__declspec(dllexport) int WINAPI SXFPopMsg_AP202(char *&OUT_name, int *OUT_msgno, char *&OUT_text)
{
	SXFErrorRecC *erec;
	//�G���[���b�Z�[�W���|�b�v
	erec = SXFErrorMsgC::PeekError();
	if(erec==NULL)
		return 1;

// SXFPopMsg_AP202()�C��	2015.04.27	T.Matsushima
	//�t�B�[�`�����擾
//	OUT_name = erec->GetName();
	static char name[64];
	strncpy_s(name,_countof(name), erec->GetName(),_TRUNCATE);
	OUT_name = name;
	//�G���[���b�Z�[�WNo�擾
	*OUT_msgno = - erec->GetCode();
	//�G���[���b�Z�[�W�擾
//	OUT_text = erec->GetText();
	static char strmsg[5000];	// From to SXFErrorMsgC::RecordError()
	strncpy_s(strmsg,_countof(strmsg), erec->GetText(),_TRUNCATE);
	OUT_text = strmsg;

	//	SXFErrorMsgC.cpp ��51�s�ڂ�new�ō쐬�����I�u�W�F�N�g��delete
	delete erec ;
	return *OUT_msgno;

}
