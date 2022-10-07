/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_approvalC.h								作成日：2000.4.18

	１．クラス概要
	approvalのエンティティデータ管理

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/

#if !defined(AFX_SXFE_APPROVALC_H__8A334C74_43C1_4221_98A3_B71CC392106E__INCLUDED_)
#define AFX_SXFE_APPROVALC_H__8A334C74_43C1_4221_98A3_B71CC392106E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SXFD_InstC.h"
class SXFD_InstC;
class SXFD_StrC;

class SXFE_approvalC : public SXFD_InstC  
{
public:
	SXFE_approvalC(SXFD_InstC* inst,SXFD_StrC* str);
	virtual ~SXFE_approvalC();

};

#endif // !defined(AFX_SXFE_APPROVALC_H__8A334C74_43C1_4221_98A3_B71CC392106E__INCLUDED_)
