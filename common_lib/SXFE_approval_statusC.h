/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_approval_statusC.h								作成日：2000.4.18

	１．クラス概要
	approval_statusのエンティティデータ管理

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/


#if !defined(AFX_SXFE_APPROVAL_STATUSC_H__E2630FE4_EE89_4E85_9F61_CA1604FA1EED__INCLUDED_)
#define AFX_SXFE_APPROVAL_STATUSC_H__E2630FE4_EE89_4E85_9F61_CA1604FA1EED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SXFD_InstC.h"
class SXFD_StrC;

class SXFE_approval_statusC : public SXFD_InstC  
{
public:
	SXFE_approval_statusC(SXFD_StrC* str);
	virtual ~SXFE_approval_statusC();

};

#endif // !defined(AFX_SXFE_APPROVAL_STATUSC_H__E2630FE4_EE89_4E85_9F61_CA1604FA1EED__INCLUDED_)
