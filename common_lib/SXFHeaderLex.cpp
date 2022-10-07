//---------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFHeaderLex.cpp					�쐬���F2001.09.17
//
//	�P�D�N���X�T�v
//		�����͂��s���N���X
//
//	�Q�D����
//		����ԍ�	���t��		 �S����			�T�v
//		�쐬		2001.09.17	K.Naono(FQS)	�w�b�_��͏����̉��P�Ή�
//
//---------------------------------------------------------

#include "stdafx.h"
#include "SXFHeaderLex.h"

//////////////////////////////////////////////////////////////////////
// �\�z/����
//////////////////////////////////////////////////////////////////////

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFHeaderLex.cpp					�쐬���F2001.09.17
//
//	�P�D�@�\�T�v
//		�R���X�g���N�^
//
//	�Q�D�C���^�[�t�F�C�X
//      CSXFHeaderLex::CSXFHeaderLex(CString& string)
//
//		����: �^			������			���e
//			CString&		string			�����͑ΏƂ̕�����
//
//		���A�l	�Ȃ�
//
//	�R�D����
//		����ԍ�	���t��		 �S����			�T�v
//		�쐬		2001.09.17	K.Naono(FQS)
//---------------------------------------------------------
CSXFHeaderLex::CSXFHeaderLex(CString& string)
{
	m_Pointer = 0 ;
	m_LineCount = 1 ;
	m_sString = string;
	m_sString += static_cast<TCHAR>(TT_EOF);
}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFHeaderLex.cpp					�쐬���F2001.09.17
//
//	�P�D�@�\�T�v
//		�f�X�g���N�^
//
//	�Q�D�C���^�[�t�F�C�X
//		CSXFHeaderLex::~CSXFHeaderLex()
//
//		����:	�Ȃ�
//
//		���A�l	�Ȃ�
//
//	�R�D����
//		����ԍ�	���t��		 �S����			�T�v
//		�쐬		2001.09.17	K.Naono(FQS)
//---------------------------------------------------------
CSXFHeaderLex::~CSXFHeaderLex()
{

}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFHeaderLex.cpp					�쐬���F2001.09.17
//
//	�P�D�@�\�T�v
//		�s�ԍ��擾
//
//	�Q�D�C���^�[�t�F�C�X
//		int CSXFHeaderLex::GetLineNo() {
//
//		����:	�Ȃ�
//
//		���A�l	�s�ԍ�
//
//	�R�D����
//		����ԍ�	���t��		 �S����			�T�v
//		�쐬		2001.09.17	K.Naono(FQS)
//---------------------------------------------------------
int CSXFHeaderLex::GetLineNo()
{
	return	m_LineCount ;
}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFHeaderLex.cpp					�쐬���F2001.09.17
//
//	�P�D�@�\�T�v
//		�g�[�N���擾
//
//	�Q�D�C���^�[�t�F�C�X
//		CString& CSXFHeaderLex::GetTokenImage()
//
//		����:	�Ȃ�
//
//		���A�l	�g�[�N��������
//
//	�R�D����
//		����ԍ�	���t��		 �S����			�T�v
//		�쐬		2001.09.17	K.Naono(FQS)
//---------------------------------------------------------
CString& CSXFHeaderLex::GetTokenImage()
{
	return m_Token ;
}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFHeaderLex.cpp					�쐬���F2001.09.17
//
//	�P�D�@�\�T�v
//		������
//
//	�Q�D�C���^�[�t�F�C�X
//		int CSXFHeaderLex::Lex()
//
//		����:	�Ȃ�
//
//		���A�l	�I��/�g�[�N��
//
//	�R�D����
//		����ԍ�	���t��		 �S����			�T�v
//		�쐬		2001.09.17	K.Naono(FQS)
//---------------------------------------------------------
int CSXFHeaderLex::Lex()
{
	TCHAR	me_c = getc() ;

	if( me_c == ' ' || me_c=='\t' ) {
		setTokenImage(me_c) ;
		return	(int)me_c ;
	}

	// EOF
	if (me_c == TT_EOF)	return TT_EOF ;


	// STRING
	if( me_c == '\'' ) {
		CString TokenImage ;
		consumeQuote(TokenImage) ;
		setTokenImage(TokenImage) ;
		return	TT_STRING ;
	}

	// COMMENT
	if( me_c == '/' ) {
		if( (me_c = getc()) == '/' ) {
			setTokenImage("//") ;
			return	TT_LINE_COMMENT ;
		} else if(me_c == '*') {
			setTokenImage("/*") ;
			return	TT_BLOCK_COMMENT_START ;
		} else {
			ungetc() ;
			me_c = '/' ;
		}
	}
	if( me_c == '*' ) {
		if( (me_c = getc()) == '/' ) {
			setTokenImage("*/") ;
			return	TT_BLOCK_COMMENT_END ;
		} else {
			ungetc() ;
			me_c = '*' ;
		}
	}

	//Alpha Start
	if ( me_c=='_' || isAlpha(me_c) || me_c == '$' || me_c == '/' || isDigit((char)me_c) ) {
		CString	TokenImage ;
		do {
			TokenImage += (TCHAR)me_c ;
		} while ( (me_c=getc()) != TT_EOF && (me_c=='_' || me_c == '$' || me_c=='.'|| isDigit((char)me_c) || isAlpha(me_c)) ) ;

		ungetc() ;
		setTokenImage(TokenImage) ;

		for(int i = 0; TB_TOKEN_TABLE[i].lpszIdName; i++) {
			if( GetTokenImage() == TB_TOKEN_TABLE[i].lpszIdName ) {
				return TB_TOKEN_TABLE[i].nTokenId ;
			}
		}

		return TT_IDENTIFIER ;
	}

	switch (me_c) {
	case '\n':
		m_LineCount ++ ;
		setTokenImage(me_c) ;
		return TT_EOL ;
	default:
		setTokenImage(me_c) ;
		return me_c;
	}
}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFHeaderLex.cpp					�쐬���F2001.09.17
//
//	�P�D�@�\�T�v
//		"'"�`"'"�̊Ԃ̕�����𒊏o����
//
//	�Q�D�C���^�[�t�F�C�X
//		void CSXFHeaderLex::consumeQuote(CString& str)
//
//		����: �^				������			    ���e
//			CString&		str			������i�[�pCString
//
//		���A�l	�Ȃ�
//
//	�R�D����
//		����ԍ�	���t��		 �S����			�T�v
//		�쐬		2001.09.17	K.Naono(FQS)
//---------------------------------------------------------
void CSXFHeaderLex::consumeQuote(CString& str)
{
	if( !str.IsEmpty() ) {
		str.Empty() ;
	}

	int	token ;
	while( (token = getc()) != TT_EOF ) {
		if( token == TT_EOL ) {
			return ;
		}

		if( token == '\'' ) {
			if( getc() == '\'') {
				str += (TCHAR)token ;
			} else {
				ungetc() ;
				return ;
			}
		}
		str += (TCHAR)token ;
	}
}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFHeaderLex.cpp					�쐬���F2001.09.17
//
//	�P�D�@�\�T�v
//		�p�����ǂ����𔻒肷��
//
//	�Q�D�C���^�[�t�F�C�X
//		BOOL CSXFHeaderLex::isAlpha(TCHAR ch)
//
//		����: �^			������		���e
//			TCHAR			ch			����
//
//		���A�l
//			TRUE :�p��
//			FALSE:�p���ȊO
//
//	�R�D����
//		����ԍ�	���t��		 �S����			�T�v
//		�쐬		2001.09.17	K.Naono(FQS)
//---------------------------------------------------------
BOOL CSXFHeaderLex::isAlpha(TCHAR ch)
{
	return	( 'A' <= ch && ch <= 'z') ;
}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFHeaderLex.cpp					�쐬���F2001.09.17
//
//	�P�D�@�\�T�v
//		�������ǂ����𔻒肷��
//
//	�Q�D�C���^�[�t�F�C�X
//		BOOL CSXFHeaderLex::isDigit(TCHAR ch)
//
//		����: �^			������		���e
//			TCHAR			ch			����
//
//		���A�l
//			TRUE :����
//			FALSE:�����ȊO
//
//	�R�D����
//		����ԍ�	���t��		 �S����			�T�v
//		�쐬		2001.09.17	K.Naono(FQS)
//---------------------------------------------------------
BOOL CSXFHeaderLex::isDigit(TCHAR ch)
{
	return	( '0' <= ch && ch <= '9') ;
}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFHeaderLex.cpp					�쐬���F2001.09.17
//
//	�P�D�@�\�T�v
//		�J�����g1�����擾
//
//	�Q�D�C���^�[�t�F�C�X
//		TCHAR CSXFHeaderLex::getc()
//
//		����:�Ȃ�
//
//		���A�l
//			����
//
//	�R�D����
//		����ԍ�	���t��		 �S����			�T�v
//		�쐬		2001.09.17	K.Naono(FQS)
//---------------------------------------------------------
TCHAR CSXFHeaderLex::getc()
{
	//
	// <�I�[>
	if( m_sString.GetLength() <= m_Pointer ) {
		return TT_EOF ;
	}
	TCHAR	ret = m_sString[m_Pointer] ;
	m_Pointer ++ ;
	return	ret ;
}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFHeaderLex.cpp					�쐬���F2001.09.17
//
//	�P�D�@�\�T�v
//		�J�����g�|�C���^��1�O�ɖ߂�
//
//	�Q�D�C���^�[�t�F�C�X
//		TCHAR CSXFHeaderLex::ungetc()
//
//		����:�Ȃ�
//
//		���A�l	�Ȃ�
//
//	�R�D����
//		����ԍ�	���t��		 �S����			�T�v
//		�쐬		2001.09.17	K.Naono(FQS)
//---------------------------------------------------------
void CSXFHeaderLex::ungetc()
{
	if( m_Pointer > 0 ) {
		m_Pointer -- ;
	}
}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFHeaderLex.cpp					�쐬���F2001.09.17
//
//	�P�D�@�\�T�v
//		�g�[�N����ݒ肷��
//
//	�Q�D�C���^�[�t�F�C�X
//		void CSXFHeaderLex::setTokenImage(CString str)
//
//		����: �^			������		���e
//			CString			str			������
//
//		���A�l	�Ȃ�
//
//	�R�D����
//		����ԍ�	���t��		 �S����			�T�v
//		�쐬		2001.09.17	K.Naono(FQS)
//---------------------------------------------------------
void CSXFHeaderLex::setTokenImage(CString str)
{
	m_Token = str ;
}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFHeaderLex.cpp					�쐬���F2001.09.17
//
//	�P�D�@�\�T�v
//		�g�[�N����ݒ肷��
//
//	�Q�D�C���^�[�t�F�C�X
//		void CSXFHeaderLex::setTokenImage(TCHAR str)
//
//		����: �^			������		���e
//			TCHAR			str			������
//
//		���A�l	�Ȃ�
//
//	�R�D����
//		����ԍ�	���t��		 �S����			�T�v
//		�쐬		2001.09.17	K.Naono(FQS)
//---------------------------------------------------------
void CSXFHeaderLex::setTokenImage(TCHAR str)
{
	m_Token = str ;
}
