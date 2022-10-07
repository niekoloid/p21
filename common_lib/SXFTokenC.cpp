/**
	All Rights Reserved,(c) JACIC 2001
	�t�@�C����				�쐬���F2000.04.27
	SXFTokenC.cpp

	�P�D�@�\�T�v
	  �����񑀍�N���X

	�Q.�����o�[�֐��ꗗ
	  SXFTokenC()
	  ~SXFTokenC()
	  void Set(LPCSTR IN_Lps)
	  CString CurText()
	  BOOL GetToken()


	�R�D����
	����ԍ�	���t		�S����		�T�v
	�쐬		2000.04.27	���{(FQS)	�Ȃ��B

**/
#include "stdafx.h"
#include "SXFTokenC.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	�t�@�C����				�쐬���F2000.04.27
	SXFTokenC.cpp

	�P�D�@�\�T�v
		SXFTokenC �N���X�̃R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		SXFTokenC::SXFTokenC()
		��  ���F�^			������		���e
				�Ȃ��B

		���A�l�F�Ȃ��B

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.04.27	���{(FQS)	�Ȃ��B
**/
SXFTokenC::SXFTokenC()
{
	m_eof = FALSE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	�t�@�C����				�쐬���F2000.04.27
	SXFTokenC.cpp

	�P�D�@�\�T�v
		SXFTokenC �N���X�̃f�X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		SXFTokenC::~SXFTokenC()

		��  ���F�^			������		���e
				�Ȃ��B

		���A�l�F�Ȃ��B

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.04.27	���{(FQS)	�Ȃ��B
**/
SXFTokenC::~SXFTokenC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	�t�@�C����				�쐬���F2000.04.27
	SXFTokenC.cpp

	�P�D�@�\�T�v
		��������Z�b�g����

	�Q�D�C���^�[�t�F�C�X
		void SXFTokenC::Set(LPCSTR IN_Lps)

		��  ���F�^			������		���e
			  LPCSTR		IN_Lps		������

		���A�l�F�Ȃ��B

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.04.27	���{(FQS)	�Ȃ��B
**/ 
void SXFTokenC::Set(LPCSTR IN_Lps)
{
	m_source = IN_Lps;	// ������
	m_lps = m_source;	// ������|�C���^�p
	getc();
}

/**
	All Rights Reserved,(c) JACIC 2001
	�t�@�C����				�쐬���F2000.04.27
	SXFTokenC.cpp

	�P�D�@�\�T�v
		���݁A���g�p

	�Q�D�C���^�[�t�F�C�X
		CString SXFTokenC::CurText()

		��  ���F�^			������		���e
				�Ȃ��B

		���A�l�F������

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.04.27	���{(FQS)	�Ȃ��B
**/
CString SXFTokenC::CurText()
{
	CString	s = m_string;
	s += static_cast<CHAR>(m_cur);
	const char *p = strchr(m_lps, '\n');
	if (p) p = strchr(p, '\n');
	if (p) {
		s += ((CString)m_lps).Left((int)( p - m_lps ));
	}
	else {
		s += m_lps;
	}
	return s;
}

/**
	All Rights Reserved,(c) JACIC 2001
	�t�@�C����				�쐬���F2000.04.27
	SXFTokenC.cpp

	�P�D�@�\�T�v
		�����񂩂�g�[�N�����擾����

	�Q�D�C���^�[�t�F�C�X
		BOOL SXFTokenC::GetToken()

		��  ���F�^			������		���e
				�Ȃ��B

		���A�l�F�g�[�N���擾���ꂽ�ꍇ��TRUE�A����ȊO��FALSE

	�R�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.27	���{(FQS)	�Ȃ��B
**/
BOOL SXFTokenC::GetToken()
{
	// ��͂��镶���񂪑��݂��邩�`�F�b�N����
	if (m_cur == 0) {
		m_eof = TRUE;
		m_Type = T_EOF;
		return FALSE;
	}

	//
	char buf[10240];//zyx 0523 1024->10240
	char *bp = buf;
	*bp = 0;
	
	//START:
	// �X�y�[�X�A���s��ǂݔ�΂�
	while (m_cur == ' ' || m_cur == '\n') getc();

	// ��͂��镶���񂪑��݂��邩�`�F�b�N����
	if (m_cur == 0) {
		m_eof = TRUE;
		m_Type = T_EOF;
		return FALSE;
	}

	// 
	if (isalpha(m_cur) || m_cur == '_') {
		// �p������'_'�ō\������镶����
		while (isalnum(m_cur) || m_cur == '_') {
			*bp++ = m_cur;
			getc();
		}
		*bp = 0;
		m_Type = T_STRING;
	}
	// 
	else if (isdigit(m_cur)) {
DIGIT:
		// ������'.'�ō\������镶����
		BOOL	bReal = FALSE;
		BOOL	bInvalid = FALSE;
		while (isdigit(m_cur)) {
			*bp++ = m_cur;
			getc();
		}
		if (m_cur == '.') {
			// �����_
			bReal = TRUE;
			*bp++ = m_cur;
			getc();
			// �����_�ȉ��̐���
			while (isdigit(m_cur)) {
				*bp++ = m_cur;
				getc();
			}
		}
		if (m_cur == 'E' || m_cur == 'e') {
			// �w����
			bReal = TRUE;
			*bp++ = m_cur;
			getc();
			if (m_cur == '+' || m_cur == '-') {
				// ����
				*bp++ = m_cur;
				getc();
			}
			if (isdigit(m_cur)) {
				// �w�����̐���
				while (isdigit(m_cur)) {
					*bp++ = m_cur;
					getc();
				}
			}
			else {
				// �F���s�\
				*bp++ = m_cur;
				getc();
				bInvalid = TRUE;
			}
		}
		if (isalnum(m_cur)) {
			// �F���s�\
			bInvalid = TRUE;
			while (isalnum(m_cur)) {
				*bp++ = m_cur;
				getc();
			}
		}

		*bp = 0;
		if (bInvalid) {
			m_Type = T_STRING;
		}
		else if (bReal) {
			m_Type = T_REAL;
		}
		else {
			m_Type = T_INTEGER;
		}
	}
// MOD(S)	K.Naono	04.02.09
//	else if (m_cur == '\'' || m_cur == '"') {
	else if (m_cur == '\'') {
		// �N�I�[�g������
		int ch = m_cur;
		*bp++ = m_cur;
		getc();

		// �N�H�[�g�������ꍇ('')�͎擾����
		while( m_cur ) {
			if( m_cur == '\'' ) {
				if( m_lps[0] == '\'' ) {
					*bp++ = m_cur ;
					getc() ;
					getc() ;
					continue ;
				}
				break ;
			}
			*bp++ = m_cur ;
			getc() ;
		}
		*bp++ = m_cur;
		getc();
		*bp = 0;
		m_Type = T_STRING;
	}
	else if (m_cur == '"' ) {
// MOD(E)	K.Naono	04.02.09
		// �N�I�[�g������
		int ch = m_cur;
		*bp++ = m_cur;
		getc();
		while (m_cur && m_cur != ch) {
			*bp++ = m_cur;
			getc();
		}
		*bp++ = m_cur;
		getc();
		*bp = 0;
		m_Type = T_STRING;
	}
	else if (m_cur == '#') {
		// �C���X�^���XID
		*bp++ = m_cur;
		getc();
		while (isdigit(m_cur)) {
			*bp++ = m_cur;
			getc();
		}
		*bp = 0;
		m_Type = T_ID;
	}
	else if (m_cur == '-' || m_cur == '+') {
		// �}�C�i�X�H
		*bp++ = m_cur;
		getc();
		if (isdigit(m_cur)) {
			goto DIGIT;
		}
		else {
			*bp = 0;
			m_Type = T_PUNCT;
		}
	}
	else if (ispunct(m_cur)) {
		// ��؂蕶��
//		while (ispunct(m_cur)) {
			*bp++ = m_cur;
			getc();
//		}
		*bp = 0;
		m_Type = T_PUNCT;
	}
	else if (m_cur == '\n') {
		// ���s�R�[�h
		getc();
		m_Type = T_EOL;
	}
	else {
		// ������
		while (m_cur && m_cur != ' ') {
			*bp++ = m_cur;
			getc();
		}
		*bp = 0;
		m_Type = T_STRING;
	}
	m_string = buf;

	return TRUE;
}
