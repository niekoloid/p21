/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_InstC.h						作成日：2000.04.12

	１．クラス概要
		整数型要素を保持し出力するクラス

	２．履歴
		履歴番号	日付		担当者		概要
		作成		2000.04.12	宮園(FQS)	なし。
**/
#ifndef _SXFD_INTC_H_
#define _SXFD_INTC_H_

#include "SXFInstanceC.h"

class SXFPart21FileC;
//
//	INT DEFINITION
//
class SXFD_IntC : public SXFInstanceC {
protected :
	int	m_Data ;
public :
//
//	Default Constructor
//
	SXFD_IntC( ) { }
//
//	Constructor with Data
//
	SXFD_IntC(int) ;
//
//	Destructor
//
	~SXFD_IntC( ) { }
//
//	Data Set
//
	void	SetData( int data ) ;
//
//	Data Get
//
	int	GetData( ) ;
//
//
//
	void WriteP21(SXFPart21FileC *IN_file){}
	void WriteAttr(SXFPart21FileC *IN_file);
} ;

#endif	// _SXFD_INTC_H_
