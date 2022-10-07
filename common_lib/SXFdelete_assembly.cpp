/**
	All Rights Reserved,(c) JACIC 2001
	SXFdelete_assembly.cpp								�쐬���F2001.2.23

	�P�D�@�\�T�v
		�A�Z���u���\���̗̂̈���

	�Q�D�C���^�[�t�F�[�X
	int SXFdelete_assembly_AP202(int assem_type,void*& f_struct);

	����:	�^			������			���e
			int			assem_type		�A�Z���u���^
											�P�F�p��
											�Q�F�����}�`
											�R�F�����Ȑ�
			void*&		f_struct		�t�B�[�`���\���̂̃A�h���X

	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.3.28			�{��(FQS)			�Ȃ��B

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

__declspec(dllexport) int WINAPI SXFdelete_assembly_AP202(int assem_type,void*& f_struct)
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
	gl_Man->Delete_assembly(assem_type,f_struct);
	return 0;
}
