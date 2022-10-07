/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_StrC.h						作成日：2000.04.12

	１．クラス概要
		文字型要素を保持し出力するクラス

	２．履歴
		履歴番号	日付		担当者		概要
		作成		2000.04.12	宮園(FQS)	なし。
**/
#ifndef _SXFD_STRC_H_
#define _SXFD_STRC_H_

#include "SXFInstanceC.h"
#include <afx.h>

class SXFPart21FileC;
//
//	STRING DEFINITION
//
class SXFD_StrC : public SXFInstanceC {
protected :
	CString		m_Data ;
public :
//
//	Default Constructor
//
	SXFD_StrC( ) { }
//
//	Constructor with Data
//
	SXFD_StrC(char*) ;
//
//	Destructor
//
	~SXFD_StrC( ) { }
//
//	Data Set
//
	void	SetData( char* ) ;
//
//	Data Get
//
	LPCTSTR	GetData( ) ;
//
//
//
	void WriteP21(SXFPart21FileC *IN_file){}
	void WriteAttr(SXFPart21FileC *IN_file);
} ;

#endif	// _D_STRING_H_
