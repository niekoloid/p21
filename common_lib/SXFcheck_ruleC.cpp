/**
	All Rights Reserved,(c) JACIC 2001
	�t�@�C����				�쐬���F2000.04.27
	SXFcheck_ruleC.cpp

	�P�D�N���X�T�v
	SXFErrorLogGetC�N���X�Ƃ̃C���^�[�t�F�[�X��񋟂���B

	�Q�D����
	����ԍ�		���t��		�S����		�T�v
	�쐬		2000.04.27	�@���{(FQS)	�@�@�Ȃ��B

**/
#include "stdafx.h"
#include "SXFcheck_ruleC.h"
#include "SXFErrorLogGetC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	�t�@�C����				�쐬���F2000.04.27
	SXFcheck_ruleC.cpp

  �@�P�D�@�\�T�v
	    �f�t�H���g�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
	SXFcheck_ruleC::SXFcheck_ruleC()

	�����F	�^	������		���e
			�Ȃ��B

  �@���A�l�F�Ȃ��B

	�R�D����
	����ԍ�		���t��		�S����		�T�v
	�쐬		2000.04.27	�@�@���{(FQS)	�Ȃ��B
**/
SXFcheck_ruleC::SXFcheck_ruleC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	�t�@�C����				�쐬���F2000.04.27
	SXFcheck_ruleC.cpp

	�P�D�@�\�T�v
	�@�@�f�t�H���g�f�X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		SXFcheck_ruleC::~SXFcheck_ruleC()

	�����F	�^	������		���e
	�@�@�@�@�Ȃ��B

	���A�l�F�Ȃ��B

	�R�D����
	����ԍ�		���t��		�S����		�T�v
	�쐬		2000.04.28	�@�@���{(FQS)	�Ȃ��B
**/
SXFcheck_ruleC::~SXFcheck_ruleC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	�t�@�C����				�쐬���F2000.04.27
�@�@SXFcheck_ruleC.cpp

	�P�D�@�\�T�v
	SXFErrorLogGetC�N���X�Ƃ̃C���^�[�t�F�[�X��񋟂���B

	�Q�D�C���^�[�t�F�C�X
		void SXFcheck_ruleC::Get(int &OUT_msgnum,	
								 CStringArray *OUT_name, 
								 CUIntArray *OUT_msgno, 
								 CStringArray *OUT_message1, 
								 CStringArray *OUT_message2)

	�����F�^	������				���e
	int 			&OUT_msgnum		�G���[��
	CStringArray 	*OUT_name 		�G���e�B�e�B�i�t�B�[�`���j��
	CUIntArray 		*OUT_msgno		���b�Z�[�W�ԍ�
	CStringArray 	*OUT_message1 	���b�Z�[�W�P
	CStringArray 	*OUT_message2	���b�Z�[�W�Q

	���A�l�F�Ȃ��B

	�R�D����
	����ԍ�		���t��		�S����		�T�v
	�쐬		2000.04.27�@	���{(FQS)	�Ȃ��B
**/
void SXFcheck_ruleC::Get(int &OUT_msgnum,	
							 CStringArray *OUT_name, 
							 CUIntArray *OUT_msgno, 
							 CStringArray *OUT_message1, 
							 CStringArray *OUT_message2)
{
	SXFErrorLogGetC	exec;
	exec.GetLogFile(OUT_msgnum, OUT_name, OUT_msgno, OUT_message1, OUT_message2);
}