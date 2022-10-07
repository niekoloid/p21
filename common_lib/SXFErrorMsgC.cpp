/**
	All Rights Reserved,(c) JACIC 2001
	SXFErrorMsgC.cpp								�쐬���F2000.3.27

	�P�D�N���X�T�v
	�G���[���b�Z�[�W���X�g�Ǘ�

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.3.27			�{��(FQS)			�Ȃ��B

**/
#include "stdafx.h"
#include "SXFErrorMsgC.h"
#include "SXF_EXT.h"
#include "SXFErrorRecC.h"
#include <stdio.h>
#include <stdarg.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFErrorMsgC.cpp								�쐬���F2000.3.27

	�P�D�@�\�T�v
		�G���[���b�Z�[�W�����X�g�ɒǉ�

	�Q�D�C���^�[�t�F�[�X
	static void	RecordError(SXFErrorCode IN_Code, 
							CString IN_Name,
							int IN_param, ...)

	����:	�^				������			���e
			SXFErrorCode	IN_Code			�G���[���b�Z�[�W�ԍ�
			char*			IN_Name			�t�B�[�`����
			int				IN_param		�����̌�

	���A�l	�Ȃ��B

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.3.27			�{��(FQS)			�Ȃ��B
	�X�V			2015.04.27			T.Matsushima		SXFPopMsg_AP202()���d�l���ʂ�ɓ��삵�Ă��Ȃ��̂ŏC��

**/
void	SXFErrorMsgC::RecordError(SXFErrorCode IN_Code, const char* IN_Name, int IN_param, ...)
{
//	char strmsg[5000];	Move to SXFPopMsg_AP202.cpp		SXFPopMsg_AP202()�C��
	va_list args;
	/* �������X�g�ւ̃|�C���^ */
	va_start (args, IN_param);
	/* �G���[���̐ݒ� */
	SXFErrorRecC *erec = new SXFErrorRecC(IN_Code,IN_Name);

	/* �������X�g�ւ̃|�C���^����G���[���b�Z�[�W�쐬 */
//	MOD(S)	SXFPopMsg_AP202()�C��	T.Matsushima	2015.04.27
	//vsprintf(strmsg, erec->GetText(), args);
	//erec->SetText(strmsg);
	erec->MakeErrorMessage(args);
//	MOD(E)	SXFPopMsg_AP202()�C��	T.Matsushima	2015.04.27

	va_end (args);
	/* �G���[���O�t�@�C���ւ̏������� */
	erec->WriteLog(gl_log_file);
	/* �G���[���X�g�ɃG���[���ǉ� */
	gl_ErrorList.AddTail(erec);
};

/**
	All Rights Reserved,(c) JACIC 2001
	SXFErrorMsgC.cpp								�쐬���F2000.3.27

	�P�D�@�\�T�v
		�G���[���b�Z�[�W�����X�g�ɒǉ�(���O�o�͂Ȃ����[�h)

	�Q�D�C���^�[�t�F�[�X
	static void	RecordError2(SXFErrorCode IN_Code, 
							CString IN_Name,
							int IN_param, ...)

	����:	�^				������			���e
			SXFErrorCode	IN_Code			�G���[���b�Z�[�W�ԍ�
			char*			IN_Name			�t�B�[�`����
			int				IN_param		�����̌�

	���A�l	�Ȃ��B

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2004.3.05			K.Naono(FQS)		�Ȃ��B
	�X�V			2015.04.27			T.Matsushima		SXFPopMsg_AP202()���d�l���ʂ�ɓ��삵�Ă��Ȃ��̂ŏC��

**/
void	SXFErrorMsgC::RecordError2(SXFErrorCode IN_Code, const char* IN_Name, int IN_param, ...)
{
//	char strmsg[5000];	Move to SXFPopMsg_AP202.cpp		SXFPopMsg_AP202()�C��
	va_list args;
	/* �������X�g�ւ̃|�C���^ */
	va_start (args, IN_param);
	/* �G���[���̐ݒ� */
	SXFErrorRecC *erec = new SXFErrorRecC(IN_Code,IN_Name);

	/* �������X�g�ւ̃|�C���^����G���[���b�Z�[�W�쐬 */
//	MOD(S)	SXFPopMsg_AP202()�C��	T.Matsushima	2015.04.27
	//vsprintf(strmsg, erec->GetText(), args);
	//erec->SetText(strmsg);
	erec->MakeErrorMessage(args);
//	MOD(E)	SXFPopMsg_AP202()�C��	T.Matsushima	2015.04.27

	va_end (args);
	/* �G���[���X�g�ɃG���[���ǉ� */
	gl_ErrorList.AddTail(erec);
};

/**
	All Rights Reserved,(c) JACIC 2001
	SXFErrorMsgC.cpp								�쐬���F2000.3.27

	�P�D�@�\�T�v
		�G���[���b�Z�[�W���X�g���烁�b�Z�[�W��POP����

	�Q�D�C���^�[�t�F�[�X
	static SXFErrorRecC*	PeekError()

	����:	�^				������			���e
			�Ȃ��B

	���A�l	SXFErrorRecC*(�G���[���b�Z�[�W�ԍ��A�t�B�[�`�����A�G���[���b�Z�[�W�j��ԋp

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.3.27			�{��(FQS)			�Ȃ��B

**/
SXFErrorRecC*	SXFErrorMsgC::PeekError(){
	SXFErrorRecC *erec;
	if(gl_ErrorList.IsEmpty())
		return NULL;
	erec = (SXFErrorRecC*)gl_ErrorList.GetTail();
	gl_ErrorList.RemoveTail();
	return erec;
}

