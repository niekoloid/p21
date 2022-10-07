/**
	All Rights Reserved,(c) JACIC 2001
	SXFread_table.cpp								�쐬���F2000.4.29

	�P�D�@�\�T�v
	��`�e�[�u���t�B�[�`���̓Ǎ�

	�Q�D�C���^�[�t�F�[�X
	int SXFread_table_AP202(int IN_TableType, void *&OUT_Struct, int &OUT_EndFlag)
	����:	�^				������				���e
			int&			IN_TableType		��`�e�[�u���^
			void*&			OUT_Struct			�\����
			int&			OUT_EndFlag			�I���t���O�i�O�F�p���@�P�F�㑱�Ȃ��j

	���A�l	���펞�F�R�[�h
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.29			�{��(FQS)			�Ȃ��B

**/

#include "stdafx.h"
#include "SXF_EXT.h"
#include "SXFManageC.h"
#include "SXFErrorMsgC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

__declspec(dllexport) int WINAPI SXFread_table_AP202(int IN_TableType, void *OUT_Struct, int *OUT_EndFlag)
{
	//�t�@�C�����I�[�v������Ă��Ȃ���΃G���[
	if (gl_Man == NULL){
		if (gl_log_file == NULL){
			gl_log_file = new ofstream("outAP202.log",ios::out);
			if(gl_log_file->fail()){
				delete gl_log_file;
				gl_log_file = NULL;
				cerr << "Error opening outAP202.log" << endl;
				*OUT_EndFlag = 1;
				return -1;
			}
		}
		SXFErrorMsgC::RecordError(SXFSTEPFILENOTOPEN,"",0);
		gl_log_file->close();
		delete gl_log_file;
		gl_log_file = NULL;
		*OUT_EndFlag = 1;
		return SXFOPENSTEPFILE;
	}
	int code = gl_Man->Read_table(IN_TableType,OUT_Struct,OUT_EndFlag);
	return code;
}
