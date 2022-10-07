/**
	All Rights Reserved,(c) JACIC 2001
	SXFCheckInfoC.h  								作成日：2001.2.15

	１．クラス概要
		ルールチェック情報を管理するクラス

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.2.15			宮園(FQS)			なし。

**/

#if !defined(AFX_SXFCHECKINFOC_H__91910F21_02D7_11D5_A3BC_009027565E9B__INCLUDED_)
#define AFX_SXFCHECKINFOC_H__91910F21_02D7_11D5_A3BC_009027565E9B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>

class SXFTableManagerC;
class SXFComInfoC;

class SXFCheckInfoC  
{
public:
	SXFCheckInfoC();
	virtual ~SXFCheckInfoC();
protected:
	CString				m_InstanceID;		/* ｲﾝｽﾀﾝｽID */
	char*				m_feature_name;		/* ﾌｨｰﾁｬ名 */
	SXFTableManagerC*	m_TableManager;		/* 定義ﾃｰﾌﾞﾙ管理ｵﾌﾞｼﾞｪｸﾄ */
	SXFComInfoC*		m_ComInfo;			/* 共通情報ｵﾌﾞｼﾞｪｸﾄ */
	int					m_font;				/* 文字ﾌｫﾝﾄｺｰﾄﾞ */
	int					m_type;				/* 線種ｺｰﾄﾞ */
	int					m_line_width;		/* 線分ｺｰﾄﾞ */
	int					m_color;			/* 色ｺｰﾄﾞ */
	int					m_layer;			/* ﾚｲﾔｺｰﾄﾞ */
private:
	void initialize();
};

#endif // !defined(AFX_SXFCHECKINFOC_H__91910F21_02D7_11D5_A3BC_009027565E9B__INCLUDED_)
