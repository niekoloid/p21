/**
	All Rights Reserved,(c) JACIC 2001
	SXFErrorRecC.h									�쐬���F2000.3.27

	�P�D�N���X�T�v
	�G���[���b�Z�[�W���t�@�C���ɏo�͂���N���X

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.3.27			�{��(FQS)			�Ȃ��B
	�X�V			2015.04.27			T.Matsushima		SXFPopMsg_AP202()���d�l���ʂ�ɓ��삵�Ă��Ȃ��̂ŏC��

**/
#ifndef _ERRORRECC_H_
#define	_ERRORRECC_H_

#include <afx.h>
#include <fstream>
#include "SXFErrorCode.h"

class SXFErrorRecC : public CObject {
protected:
	SXFErrorCode		m_Code ;	//�G���[���b�Z�[�W�ԍ�
	char				*m_Text ;	//�G���[���b�Z�[�W
// SXFPopMsg_AP202()�C��	2015.04.27	T.Matsushima
//	char				*m_Name;	//�t�B�[�`����
	CString				m_Name;		//�t�B�[�`����
private:
	SXFErrorRecC(){}
public:
	SXFErrorRecC(SXFErrorCode IN_ecode,const char* IN_Name);	// Add const
	virtual ~SXFErrorRecC();

	void WriteLog(ofstream *IN_log_file);
	char*	GetErrorText(SXFErrorCode IN_Code);

// SXFPopMsg_AP202()�C��	2015.04.27	T.Matsushima
	void MakeErrorMessage(va_list args);	// �������X�g�ւ̃|�C���^����G���[���b�Z�[�W�쐬
//	void SetText(char *IN_text);	�폜
	int GetCode();
	const char* GetName();	// �߂�l const �ǉ�
	const char* GetText();	// �߂�l const �ǉ�
};

#endif	// _ERRORRECC_H_ 
