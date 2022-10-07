//---------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFPart21FileC.cpp					作成日：2001.09.17
//
//	１．クラス概要
//		ファイルの入力を管理する
//
//	２．履歴
//		履歴番号	日付け		 担当者			概要
//		作成		2001.09.17	K.Naono(FQS)	ヘッダ解析処理の改善対応
//
//---------------------------------------------------------

#if !defined(AFX_SXFPART21FILEEXC_H__40E65DD5_E579_4BD7_9F20_F22034443495__INCLUDED_)
#define AFX_SXFPART21FILEEXC_H__40E65DD5_E579_4BD7_9F20_F22034443495__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SXFPart21FileC.h"

#define	ID_ENDSEC			"ENDSEC"
#define	ID_SCADEC			"SCADEC"
#define	ID_LEVEL1			"level1"
#define	ID_LEVEL2			"level2"
#define	ID_AMBI_MODE		"ambi_mode"
#define	ID_FEATURE_MODE		"feature_mode"
#define	ID_AP202_MODE		"AP202_mode"

class CSXFHeaderLex ;

class SXFPart21FileExC : public SXFPart21FileC  
{
public:
	//	コンストラクタ
	SXFPart21FileExC( LPCTSTR IN_lpszFileName, UINT IN_nOpenFlags);

	//	デストラクタ
	virtual ~SXFPart21FileExC();

	virtual int  ReadHeadSection(HEADSECTION* IO_Head);
//	ADD(S)	チューニング対応	K.Naono	03.07.04
	virtual int  ReadInstance(INSTANCEDATA *IO_Instance);
//	ADD(E)	チューニング対応	K.Naono	03.07.04

protected:
	CSXFHeaderLex*	m_pDataLex ;
	CString*		m_pDataRecord ;

private:
	void	getAttribute(
						CSXFHeaderLex*	pLex,
						CStringArray&	array) ;
	int		analyzeDescription(
						CStringArray&	array,
						HEADSECTION*	IO_Head) ;
	int		analyzeName(
						CStringArray&	array,
						HEADSECTION*	IO_Head) ;
	void	skippedComment(CString& recordline) ;
	BOOL	isQuoteString(
						CString&	strRecord,
						int			nIndex) ;
};

#endif // !defined(AFX_SXFPART21FILEEXC_H__40E65DD5_E579_4BD7_9F20_F22034443495__INCLUDED_)
