#include "stdafx.h"
#include "SXFComncApi.h"

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2003
//	SXFComncApi.cpp					�쐬���F2003.07.03
//
//	�P�D�@�\�T�v
//		������񕶎�����J���}(,)���Z�p���[�g�Ƃ���
//		��������
//
//	�Q�D�C���^�[�t�F�C�X
//      GFn_SplitSEntityAttr(
//					LPCTSTR			lpszSrc,
//					CStringArray&	arDest)
//
//		����: �^			������			���e
//			LPCTSTR			lpszSrc			������񕶎���
//			CStringArray&	arDest			����������i�[�z��
//
//		���A�l	�Ȃ�
//
//	�R�D����
//		����ԍ�	���t��		�S����			�T�v
//		�쐬		2003.07.03	K.Naono
//---------------------------------------------------------
int	GFn_SplitSEntityAttr(
					LPCTSTR			lpszSrc,
					CStringArray&	arDest) {

	LPCTSTR		p = lpszSrc ;
	LPCTSTR		pS = p ;
	int			nBracket = 0 ;
	bool		fQuot = false ;

	while(true) {
		switch(p[0]) {
		case 0 :
			goto EXIT_LABEL ;

		case '(' :
			if( fQuot ) {
				break ;
			}
			++nBracket ;
			if( nBracket == 1 ) {
				pS = _tcsinc(pS) ;
			}
			break ;

		case ')' :
			if( fQuot ) {
				break ;
			}
			--nBracket ;
			if( nBracket < 1 ) {
				goto EXIT_LABEL ;
			}
			break ;

		case '\'' :
			fQuot = !fQuot ;
			break ;

		case ',' :
			if( !fQuot && nBracket == 1 ) {
				goto NEXT_LABEL ;
			}
			break ;

		default :
			break ;
		}
		p = _tcsinc(p) ;
		continue ;

	NEXT_LABEL :
		CString o(pS, (int)(p - pS)) ;
		arDest.Add(o) ;
		p = _tcsinc(p) ;
		pS = p ;
		continue ;
	}

EXIT_LABEL :
	CString o(pS, (int)(p - pS)) ;
	arDest.Add(o) ;

	return (int)arDest.GetSize() ;
}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2003
//	SXFComncApi.cpp					�쐬���F2003.07.03
//
//	�P�D�@�\�T�v
//		�����G���e�B�e�B�����񂩂�G���e�B�e�B�P�ʂ�
//		��������
//
//	�Q�D�C���^�[�t�F�C�X
//      GFn_SplitCEntityAttr(
//					LPCTSTR			lpszSrc,
//					CStringArray&	arDest)
//
//		����: �^			������			���e
//			LPCTSTR			lpszSrc			������񕶎���
//			CStringArray&	arDest			����������i�[�z��
//
//		���A�l	�Ȃ�
//
//	�R�D����
//		����ԍ�	���t��		�S����			�T�v
//		�쐬		2003.07.03	K.Naono
//---------------------------------------------------------
int	GFn_SplitCEntityAttr(
					LPCTSTR			lpszSrc,
					CStringArray&	arDest) {

	LPCTSTR		p = lpszSrc ;
	LPCTSTR		pS = p ;
	int			nBracket = 0 ;
	bool		fQuot = false ;

	while(true) {
		switch(p[0]) {
		case 0 :
			goto EXIT_LABEL ;

		case '(' :
// ADD(S)	K.Naono	04.02.27
			if( fQuot ) {
				break ;
			}
// ADD(E)	K.Naono	04.02.27
			++nBracket ;
			if( nBracket == 1 ) {
				pS = _tcsinc(pS) ;
			}
			break ;

		case ')' :
// ADD(S)	K.Naono	04.02.27
			if( fQuot ) {
				break ;
			}
// ADD(E)	K.Naono	04.02.27
			--nBracket ;
			if( nBracket == 1 ) {
				goto NEXT_LABEL ;
			}

			if( nBracket < 1 ) {
				goto EXIT_LABEL ;
			}
			break ;
// ADD(S)	K.Naono	04.02.27
		case '\'' :
			fQuot = !fQuot ;
			break ;
// ADD(E)	K.Naono	04.02.27

		default :
			break ;
		}
		p = _tcsinc(p) ;
		continue ;

	NEXT_LABEL :
		CString o(pS, (int)( p - pS + 1)) ;
		arDest.Add(o) ;
		p = _tcsinc(p) ;
		pS = p ;
		continue ;
	}

EXIT_LABEL :
	if( p != pS ) {
		CString o(pS, (int)(p - pS)) ;
		arDest.Add(o) ;
	}

	return (int)arDest.GetSize() ;
}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2003
//	SXFComncApi.cpp					�쐬���F2003.07.03
//
//	�P�D�@�\�T�v
//		�w�肳�ꂽ��؂蕶���ŕ�����𕪊�����
//
//	�Q�D�C���^�[�t�F�C�X
//      GFn_SplitString(
//					LPCTSTR			lpszSrc,
//					int				nCode,
//					CStringArray&	arDest)
//
//		����: �^			������			���e
//			LPCTSTR			lpszSrc			������񕶎���
//			int				nCode			��؂蕶���R�[�h
//			CStringArray&	arDest			����������i�[�z��
//
//		���A�l	�Ȃ�
//
//	�R�D����
//		����ԍ�	���t��		�S����			�T�v
//		�쐬		2003.07.03	K.Naono
//---------------------------------------------------------
int	GFn_SplitString(
					LPCTSTR			lpszSrc,
					int				nCode,
					CStringArray&	arDest) {

	arDest.SetSize(0) ;

	CString	str ;
	char	*dp, *p ;

	for(dp=p=(char*)lpszSrc; p; dp=p+1) {
		if( (p=strchr(dp,nCode)) ) {
			p[0] = NULL ;
		}
		str = dp ;
		arDest.Add(str) ;
	}
	return (int)arDest.GetSize() ;
}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2003
//	SXFComncApi.cpp					�쐬���F2003.07.03
//
//	�P�D�@�\�T�v
//		�w�肳�ꂽ��؂蕶���ŕ�����𕪊�����
//
//	�Q�D�C���^�[�t�F�C�X
//      GFn_SplitString(
//					LPCTSTR			lpszSrc,
//					LPCTSTR			lpszCode,
//					CStringArray&	arDest)
//
//		����: �^			������			���e
//			LPCTSTR			lpszSrc			������񕶎���
//			LPCTSTR			lpszCode		��؂蕶����
//			CStringArray&	arDest			����������i�[�z��
//
//		���A�l	�Ȃ�
//
//	�R�D����
//		����ԍ�	���t��		�S����			�T�v
//		�쐬		2003.07.03	K.Naono
//---------------------------------------------------------
int	GFn_SplitString(
					LPCTSTR			lpszSrc,
					LPCTSTR			lpszCode,
					CStringArray&	arDest) {

	arDest.SetSize(0) ;

	CString	str ;
	char	*dp, *p ;

	for(dp=p=(char*)lpszSrc; p; dp=p+1) {
		if( (p=strstr(dp,lpszCode)) ) {
			memset(p,0x00,strlen(lpszCode)) ;
			p += (strlen(lpszCode)-1) ;
		}
		else{
			break;
		}
		str = dp ;
		arDest.Add(str) ;
	}
	return (int)arDest.GetSize() ;
}
