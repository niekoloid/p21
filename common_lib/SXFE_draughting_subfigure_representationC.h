/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_draughting_subfigure_representationC.h								作成日：2000.4.18

	１．クラス概要
	draughting_subfigure_representationのエンティティデータ管理

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/
#ifndef _E_DRAUGHTING_SUBFIGURE_REPRESENTATION_H_
#define _E_DRAUGHTING_SUBFIGURE_REPRESENTATION_H_

#include "SXFD_InstC.h"
class SXFD_StrC;
class SXFD_AggrC;
//
//
//
class SXFE_draughting_subfigure_representationC : public SXFD_InstC {
protected :
public :
//
//	Constructor
//
	SXFE_draughting_subfigure_representationC(SXFD_StrC*,SXFD_AggrC*,SXFD_InstC*);
} ;

#endif	// _E_DRAUGHTING_SUBFIGURE_REPRESENTATION_H_
