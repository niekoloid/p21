/**
	All Rights Reserved,(c) JACIC 2001
	SXFclose_part21.cpp								�쐬���F2000.4.29

	�P�D�@�\�T�v
		�t�@�C���̃N���[�Y

	�Q�D�C���^�[�t�F�[�X
	int SXFclose_AP202();
	����:	�^				������			���e
			�Ȃ��B
	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.29			�{��(FQS)			�Ȃ��B

**/

#include "stdafx.h"
#include "SXF_EXT.h"
#include "SXFManageC.h"
#include "SXFErrorMsgC.h"
#include "SXFErrorRecC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

__declspec(dllexport) int WINAPI SXFclose_AP202()
{
	//�t�@�C�����I�[�v������Ă��Ȃ���΃G���[
	if (gl_Man == NULL){
		if (gl_log_file == NULL){
			gl_log_file = new ofstream("outAP202.log",ios::out);
			if(gl_log_file->fail()){
				delete gl_log_file;
				gl_log_file = NULL;
				cerr << "Error opening outAP202.log" << endl;
				return -1;
			}
		}
		SXFErrorMsgC::RecordError(SXFSTEPFILENOTOPEN,"",0);
		gl_log_file->close();
		delete gl_log_file;
		gl_log_file = NULL;
		return SXFOPENSTEPFILE;
	}
	int ret;
	if ((ret = gl_Man->Close()) < 0)
		return ret;
	//�ϊ��Ǘ��I�u�W�F�N�g�̈���
	if (gl_Man){
		delete gl_Man;
		gl_Man = NULL;
	}
	//	SXFErrorMsgC.cpp ��51�s�ڂ�new�ō쐬�����I�u�W�F�N�g��delete
	SXFErrorRecC *erec;
	while( erec = SXFErrorMsgC::PeekError() )
	{
		delete erec ;
	}
	return 0;
}
