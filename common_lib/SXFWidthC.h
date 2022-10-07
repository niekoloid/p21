//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFWidthC.h                           作成日：2000.04.16
//
//	１．クラス概要
//		線幅の構造体、コード、インスタンスＩＤなどを保持するクラス
//
//	２．履歴
//	    履歴番号    日付け         担当者    概要
//      作成		2000.04.16     周
//
//------------------------------------------------------------
#ifndef _SXFWIDTHC_H_
#define _SXFWIDTHC_H_

class SXFTableMapManagerC;

class SXFWidthC  
{
public:
	SXFWidthC(	);
	virtual ~SXFWidthC();
	int InquireCode(double IN_Width, double IN_Eps);

public:
	int m_Code;
	int m_ID;

	double m_Width;

	SXFTableMapManagerC* m_MappingManager;

};

#endif
