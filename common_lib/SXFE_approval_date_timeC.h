/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_approval_date_timeC.h								作成日：2000.4.18

	１．クラス概要
	approval_date_timeのエンティティデータ管理

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/

#if !defined(AFX_SXFE_APPROVAL_DATE_TIMEC_H__7F793246_4FD6_4D00_8EC7_B8C86FD59EAC__INCLUDED_)
#define AFX_SXFE_APPROVAL_DATE_TIMEC_H__7F793246_4FD6_4D00_8EC7_B8C86FD59EAC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SXFD_InstC.h"
class SXFD_InstC;

class SXFE_approval_date_timeC : public SXFD_InstC  
{
public:
	SXFE_approval_date_timeC(SXFD_InstC *inst1,SXFD_InstC *inst2);
	virtual ~SXFE_approval_date_timeC();

};

#endif // !defined(AFX_SXFE_APPROVAL_DATE_TIMEC_H__7F793246_4FD6_4D00_8EC7_B8C86FD59EAC__INCLUDED_)
