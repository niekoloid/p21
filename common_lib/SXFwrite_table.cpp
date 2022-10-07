/**
	All Rights Reserved,(c) JACIC 2001
	SXFwrite_table.cpp								�쐬���F2000.4.29

	�P�D�@�\�T�v
	��`�e�[�u���t�B�[�`���̃t�@�C���o��

	�Q�D�C���^�[�t�F�[�X
	int SXFwrite_table_AP202(int IN_table_type, void *IN_str)
	����:	�^				������				���e
			int				IN_table_type		��`�e�[�u���^
			void*			IN_str				�\����

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

__declspec(dllexport) int WINAPI SXFwrite_table_AP202(int IN_table_type, void *IN_str)
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
	int code = gl_Man->Write_table(IN_table_type,IN_str);
	return code;
}
