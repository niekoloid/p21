/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_EnumC.h						作成日：2000.04.12

	１．クラス概要
		列挙型の要素を保持し出力するクラス

	２．履歴
		履歴番号	日付		担当者		概要
		作成		2000.04.12	宮園(FQS)	なし。
**/
#ifndef _SXFD_ENUMC_H_
#define _SXFD_ENUMC_H_

#include "SXFInstanceC.h"

class SXFPart21FileC;
//
//	ENUMETATION DEFINITION
//
class SXFD_EnumC : public SXFInstanceC {
protected :
	CString		m_Data ;
public :
//
//	Default Constructor
//
	SXFD_EnumC( ) { }
//
//	Constructor with Data
//
	SXFD_EnumC(char*) ;
//
//	Destructor
//
	~SXFD_EnumC( ) { }
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

#endif	// _D_ENUM_H_
