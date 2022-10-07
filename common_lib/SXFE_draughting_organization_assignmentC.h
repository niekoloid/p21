/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_draughting_organization_assignmentC.h								作成日：2000.4.18

	１．クラス概要
	draughting_organization_assignmentのエンティティデータ管理

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/


#if !defined(AFX_SXFE_DRAUGHTING_ORGANIZATION_ASSIGNMENTC_H__4D75C71F_9813_4566_93E3_365BCB24DFCE__INCLUDED_)
#define AFX_SXFE_DRAUGHTING_ORGANIZATION_ASSIGNMENTC_H__4D75C71F_9813_4566_93E3_365BCB24DFCE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SXFD_InstC.h"

class SXFD_InstC;
class SXFD_AggrC;

class SXFE_draughting_organization_assignmentC : public SXFD_InstC  
{
public:
	SXFE_draughting_organization_assignmentC(SXFD_InstC* inst1, SXFD_InstC* inst2, SXFD_AggrC* aggr);
	virtual ~SXFE_draughting_organization_assignmentC();

};

#endif // !defined(AFX_SXFE_DRAUGHTING_ORGANIZATION_ASSIGNMENTC_H__4D75C71F_9813_4566_93E3_365BCB24DFCE__INCLUDED_)
