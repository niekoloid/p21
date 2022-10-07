/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_calendar_dateC.h								作成日：2000.4.18

	１．クラス概要
	calendar_dateのエンティティデータ管理

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/

#if !defined(AFX_SXFE_CALENDAR_DATEC_H__A801C3B8_4027_43B1_A92A_B1AD3240466B__INCLUDED_)
#define AFX_SXFE_CALENDAR_DATEC_H__A801C3B8_4027_43B1_A92A_B1AD3240466B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SXFD_InstC.h"
class SXFD_IntC;

class SXFE_calendar_dateC : public SXFD_InstC  
{
public:
	SXFE_calendar_dateC(SXFD_IntC* yy,SXFD_IntC* dd,SXFD_IntC* mm);
	virtual ~SXFE_calendar_dateC();

};

#endif // !defined(AFX_SXFE_CALENDAR_DATEC_H__A801C3B8_4027_43B1_A92A_B1AD3240466B__INCLUDED_)
