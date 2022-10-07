/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_contract_typeC.h								作成日：2000.4.18

	１．クラス概要
	contract_typeのエンティティデータ管理

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/


#if !defined(AFX_SXFE_CONTRACT_TYPEC_H__02A37295_B748_433B_971D_DF0310D444F4__INCLUDED_)
#define AFX_SXFE_CONTRACT_TYPEC_H__02A37295_B748_433B_971D_DF0310D444F4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SXFD_InstC.h"
class SXFD_StrC;

class SXFE_contract_typeC : public SXFD_InstC  
{
public:
	SXFE_contract_typeC(SXFD_StrC* str);
	virtual ~SXFE_contract_typeC();

};

#endif // !defined(AFX_SXFE_CONTRACT_TYPEC_H__02A37295_B748_433B_971D_DF0310D444F4__INCLUDED_)
