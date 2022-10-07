/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_contractC.h								作成日：2000.4.18

	１．クラス概要
	contractのエンティティデータ管理

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/


#if !defined(AFX_SXFE_CONTRACTC_H__A3FCB504_E58B_4149_B828_913B719B2D51__INCLUDED_)
#define AFX_SXFE_CONTRACTC_H__A3FCB504_E58B_4149_B828_913B719B2D51__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SXFD_InstC.h"
class SXFD_StrC;
class SXFD_InstC;

class SXFE_contractC : public SXFD_InstC  
{
public:
	SXFE_contractC(SXFD_StrC* str1,SXFD_StrC* str2,SXFD_InstC* inst);
	virtual ~SXFE_contractC();

};

#endif // !defined(AFX_SXFE_CONTRACTC_H__A3FCB504_E58B_4149_B828_913B719B2D51__INCLUDED_)
