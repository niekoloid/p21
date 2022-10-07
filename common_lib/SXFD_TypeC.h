/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_TypeC.h						作成日：2000.04.12

	１．クラス概要
		Type型要素を保持し出力するクラス

	２．履歴
		履歴番号	日付		担当者		概要
		作成		2000.04.12	宮園(FQS)	なし。
**/
#ifndef _SXFD_TYPEC_H_
#define _SXFD_TYPEC_H_

#include "SXFInstanceC.h"
#include <afx.h>

class SXFPart21FileC;
//
//	TYPE DEFINITION
//
class SXFD_TypeC : public SXFInstanceC {
protected :
	CString		m_Data ;
	SXFInstanceC*	m_Next ;
public :
//
//	Default Constructor
//
	SXFD_TypeC( ) { }
//
//	Constructor with Name
//
	SXFD_TypeC( char* ) ;
//
//	Destructor
//
	~SXFD_TypeC( ) { }
//
//	Next Data Set Method
//
	void	SetNext( SXFInstanceC* ) ;
//
//	Data Get
//
	LPCTSTR	GetData( ) ;
//
//
//
	SXFInstanceC* GetNext( ) ;
//
//
//
	void WriteP21(SXFPart21FileC *IN_file);
	void WriteAttr(SXFPart21FileC *IN_file);
} ;

#endif	// _D_TYPE_H_
