/**
	All Rights Reserved,(c) JACIC 2001
	SXFopen_part21.cpp								�쐬���F2000.4.28

	�P�D�@�\�T�v
		�t�@�C���̃I�[�v��

	�Q�D�C���^�[�t�F�[�X
	int SXFopen_AP202(char IN_file_name[257],int IN_rw_flg, double IN_tolerance1,double IN_tolerance2,double IN_divide, int IN_level, int IN_mode, char IN_author[257], char IN_org[257],char IN_translator_name[257],char OUT_version[257]);
	����:	�^				������				���e
			char			IN_file_name		�t�@�C����
			int				IN_rw_flg			�ǂݏ����t���O
			double			IN_tolerance1		���e�덷
			double			IN_tolerance2		�p�x�p���e�덷
			double			IN_divide			�_�E���R���o�[�g�p���e�덷
			int				IN_level			���x��(1or2)
			int				IN_mode				���[�h (0:���p
														1:�t�B�[�`���R�����g
														2:AP202�j
			char			IN_author			�t�@�C���쐬��
			char			IN_org				�쐬�ҏ���
			char			IN_translator_name	�g�����X���[�^��
			char			OUT_version			���ʃ��C�u�����o�[�W����
	���A�l	���펞�F�O
			�ُ펞�F�G���[�ԍ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.28			�{��(FQS)			�Ȃ��B

**/

#include "stdafx.h"
#include "SXFManageC.h"
#define EXT_BODY
#include "SXF_EXT.h"
#include "SXFErrorMsgC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

__declspec(dllexport) int WINAPI SXFopen_AP202(char IN_file_name[], int IN_rw_flg, double IN_tolerance1, double IN_tolerance2, double IN_divide, int IN_level, int IN_mode, char IN_author[], char IN_org[], char IN_translator_name[], char OUT_version[])
{
	//�ϊ��Ǘ��I�u�W�F�N�g����
	gl_Man = new SXFManageC();
	int ret = gl_Man->Open(IN_file_name,IN_rw_flg,IN_tolerance1,IN_tolerance2,IN_divide,IN_level,IN_mode,IN_author,IN_org,IN_translator_name,OUT_version);
	if (ret < 0){
		delete gl_Man;
		gl_Man = NULL;
	}
	return ret;
}

__declspec(dllexport) int WINAPI SXFset_file_version_AP202(char IN_file_version[])
{
	gl_FileVersion = IN_file_version;
	return 0;
}

__declspec(dllexport) int WINAPI SXFget_file_version_AP202(char OUT_file_version[])
{
//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
//	strcpy(OUT_file_version, (LPCTSTR)gl_FileVersion);
	// �o�b�t�@�T�C�Y�͎d�l�����擾
	strcpy_s(OUT_file_version, 257, (LPCTSTR)gl_FileVersion);
	return 0;
}
