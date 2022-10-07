/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_draughting_approval_assignmentC.h								作成日：2000.4.18

	１．クラス概要
	draughting_approval_assignmentのエンティティデータ管理

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/


#if !defined(AFX_SXFE_DRAUGHTING_APPROVAL_ASSIGNMENTC_H__13188A53_344B_43AD_8358_9E0D7F7CF9BB__INCLUDED_)
#define AFX_SXFE_DRAUGHTING_APPROVAL_ASSIGNMENTC_H__13188A53_344B_43AD_8358_9E0D7F7CF9BB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SXFD_InstC.h"
class SXFD_InstC;
class SXFD_AggrC;

class SXFE_draughting_approval_assignmentC : public SXFD_InstC  
{
public:
	SXFE_draughting_approval_assignmentC(SXFD_InstC* inst,SXFD_AggrC* aggr);
	virtual ~SXFE_draughting_approval_assignmentC();

};

#endif // !defined(AFX_SXFE_DRAUGHTING_APPROVAL_ASSIGNMENTC_H__13188A53_344B_43AD_8358_9E0D7F7CF9BB__INCLUDED_)
