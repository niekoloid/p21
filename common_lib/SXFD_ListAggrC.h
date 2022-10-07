/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_ListAggrC.cpp						作成日：2000.04.12

	１．クラス概要
		集合体型の要素を保持し出力するクラス

	２．履歴
		履歴番号	日付		担当者		概要
		作成		2000.04.12	宮園(FQS)	なし。
**/
#ifndef _SXFD_LISTAGGRC_H_
#define _SXFD_LISTAGGRC_H_

#include "SXFInstanceC.h"

#include <afx.h>

class SXFPart21FileC;

//
//	AGGR TYPE DEFINITION
//
class SXFD_ListAggrC : public SXFInstanceC {
protected :
	CObList		m_Data ;
public :
//
//	Default Constructor
//
	SXFD_ListAggrC() { }
//
//	Destructor
//
	~SXFD_ListAggrC( ) ;
//
//	Data Set Method
//
	void	AddElem( CObject* ) ;
//
//
//
	void	RemoveTail() ;

//
//
//
	void Remove();
//
//
//
	CObList& GetData();
//
//
//
	void WriteP21(SXFPart21FileC *IN_file) ;
//
//	
//	
	void WriteAttr(SXFPart21FileC *IN_file);

	BOOL Is_Empty();
} ;

#endif	// _D_AGGR_H_
