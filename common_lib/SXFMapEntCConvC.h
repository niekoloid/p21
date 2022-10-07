/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntCConvC.h						作成日：2000.04.17

	１．クラス概要
		Complex型EntityArrayDataを型変換する

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#ifndef _SXFMapEntCConvC_CLASS_
#define _SXFMapEntCConvC_CLASS_

//#include <afx.h>
//#include <afxtempl.h>

//#include "SXFSplitAP202C.h"
#include "SXFMapEntAConvC.h"

class SXFMapEntCConvC : public SXFMapEntAConvC{
public :
//
//	<デフォルトコンストラクタ>
	SXFMapEntCConvC( ) ;

//	<コンストラクタ>
	SXFMapEntCConvC(CStringArray* IN_ComplexArray ) ;
//	SXFMapEntCConvC(CStringArray&) ;

//	<デストラクタ>
//
	virtual	~SXFMapEntCConvC() ;

//エンティティ名とエンティティデータの登録
	int	SetCompelexArray(CStringArray* IN_ComplexArray);

//
//	<Complex型Entityの指定されたエンティティのデーダを分割する>
//	CStringArray*		ConvCStringArray(CString&);
	BOOL	SplitComplex(CString& IN_EntityName);
	BOOL	SplitComplex(char* IN_EntityName);
/*
	SXFMapEntDConvC(CString*) ;
	SXFMapEntDConvC(CString&) ;
	SXFMapEntDConvC(char*) ;
*/

private :


protected :

//
//	<エンティティ名>
	CString		m_EntityName;
//
//	<ComplexEntityの全データ>
	CStringArray*	m_ComplexArray;

//	<SXFMapEntAConvCへのポインタ>
//	SXFMapEntAConvC*  m_convertP; 

	CStringArray m_EntityArrayTempEntC;

} ;

#endif

////////////////////////////
