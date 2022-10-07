/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_organization_roleC.h								作成日：2000.4.18

	１．クラス概要
	organization_roleのエンティティデータ管理

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/

#if !defined(AFX_SXFE_ORGANIZATION_ROLEC_H__EED5E0AC_83AD_41D4_AE6F_D5CF5D14CC32__INCLUDED_)
#define AFX_SXFE_ORGANIZATION_ROLEC_H__EED5E0AC_83AD_41D4_AE6F_D5CF5D14CC32__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SXFD_InstC.h"
class SXFD_StrC;

class SXFE_organization_roleC : public SXFD_InstC  
{
public:
	SXFE_organization_roleC(SXFD_StrC* str);
	virtual ~SXFE_organization_roleC();

};

#endif // !defined(AFX_SXFE_ORGANIZATION_ROLEC_H__EED5E0AC_83AD_41D4_AE6F_D5CF5D14CC32__INCLUDED_)
