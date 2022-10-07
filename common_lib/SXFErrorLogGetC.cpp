/**
	All Rights Reserved,(c) JACIC 2001
	�t�@�C����				�쐬���F2000.04.27
	SXFErrorLogGetC.cpp

	�P�D�N���X�T�v
	�G���[���O����G���[���X�^�b�N���ԋp����

	�Q�D����
	����ԍ�		���t��		�S����		�T�v
	�쐬		2000.04.27	�@���{(FQS)	�@�@�Ȃ��B

**/
#include "stdafx.h"
#include <afx.h>
#include <fstream>
#include "SXFErrorLogGetC.h"

#define MAXCHR 16384
#define DELIMITER ":"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	�t�@�C����				�쐬���F2000.04.27
	SXFErrorLogGetC.cpp

  �@�P�D�@�\�T�v
	    �f�t�H���g�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
	SXFErrorLogGetC::SXFErrorLogGetC()
	�����F	�^	������		���e
			�Ȃ��B

  �@���A�l�F�Ȃ��B

	�R�D����
	����ԍ�		���t��		�S����		�T�v
	�쐬		2000.04.27	�@�@���{(FQS)	�Ȃ��B
**/
SXFErrorLogGetC::SXFErrorLogGetC()
{
}
/**
	All Rights Reserved,(c) JACIC 2001
	�t�@�C����				�쐬���F2000.04.27
�@�@SXFErrorLogGetC.cpp

	�P�D�@�\�T�v
	�@�@�f�t�H���g�f�X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		SXFErrorLogGetC::~SXFErrorLogGetC()
	�����F	�^	������		���e
	�@�@�@�Ȃ��B

	���A�l�F�Ȃ��B

	�R�D����
	����ԍ�		���t��		�S����		�T�v
	�쐬		2000.04.28	�@�@���{(FQS)	�Ȃ��B
**/
SXFErrorLogGetC::~SXFErrorLogGetC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	�t�@�C����				�쐬���F2000.04.27
�@�@SXFErrorLogGetC.cpp

	�P�D�@�\�T�v
	�G���[���O����G���[���X�^�b�N���ԋp����

	�Q�D�C���^�[�t�F�C�X
�@�@�@�@BOOL SXFErrorLogGetC::GetLogFile(int &OUT_msgnum,	
										 CStringArray *OUT_name, 
										 CUIntArray *OUT_msgno, 
										 CStringArray *OUT_message1, 
								   		 CStringArray *OUT_message2)	

	�����F�^		������			���e
	int 			&OUT_msgnum		�G���[��
	CStringArray 	*OUT_name		�G���e�B�e�B�i�t�B�[�`���j��
	CUIntArray 		*OUT_msgno		���b�Z�[�W�ԍ�
	CStringArray 	*OUT_message1	���b�Z�[�W�P
	CStringArray 	*OUT_message2	���b�Z�[�W�Q

	���A�l�F���O�t�@�C���𐳏�ɊJ�������o������TRUE��Ԃ��B
	�@�@�@�@�J���Ȃ�������AFALSE��ԋp����B

	�R�D����
	����ԍ�		���t��		�S����		�T�v
	�쐬		2000.04.27�@	���{(FQS)	�Ȃ��B
**/
BOOL SXFErrorLogGetC::GetLogFile(int &OUT_msgnum,	
				CStringArray *OUT_name, 
				CUIntArray *OUT_msgno, 
				CStringArray *OUT_message1, 
				CStringArray *OUT_message2)
{

	FILE *Logfile = NULL;
	char 	*name, *msgno_string, *message1, *message2, buf[256];
	int		msgno;

//	MOD(S)	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
//	if (( Logfile =fopen("outAP202.log","r"))==NULL){
//		return FALSE;
//	};

	//���O�t�@�C���I�[�v��
	errno_t	err = fopen_s(&Logfile, "outAP202.log" , "r" );
	if( (err != 0) || (Logfile == NULL) ) {
		return FALSE;
	}
//	MOD(E)	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
	fgets(buf,256,Logfile);

	while ((fgets(buf,256,Logfile) != NULL)){

	//	MOD(S)	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
		//name = strtok(buf,DELIMITER);
		//msgno_string    = strtok(NULL,DELIMITER);
		//message1 = strtok(NULL,DELIMITER);
		//message2 = strtok(NULL,DELIMITER);

		char *context = NULL;
		name = strtok_s(buf,DELIMITER, &context);
		msgno_string    = strtok_s(NULL,DELIMITER, &context);
		message1 = strtok_s(NULL,DELIMITER, &context);
		message2 = strtok_s(NULL,DELIMITER, &context);
	//	MOD(E)	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27

		OUT_name->Add(name);
		//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
		//OUT_msgno->Add(sscanf(msgno_string, "%x", &msgno));
		OUT_msgno->Add(sscanf_s(msgno_string, "%x", &msgno));
		OUT_message1->Add(message1);
		OUT_message2->Add(message2);
		OUT_msgnum++;
	}
	fclose(Logfile);
	return TRUE;
}
