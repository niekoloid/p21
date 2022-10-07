/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_cartesian_pointC.h								作成日：2000.4.18

	１．クラス概要
	cartesian_pointのエンティティデータ管理

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/
#ifndef _E_CARTESIAN_POINT_H_
#define _E_CARTESIAN_POINT_H_

#include "SXFD_InstC.h"

class SXFD_StrC;
class SXFD_AggrC;
//
//
//
class SXFE_cartesian_pointC : public SXFD_InstC {
protected :
public :
//
//	Constructor
//
	SXFE_cartesian_pointC(SXFD_StrC*,SXFD_AggrC*);
} ;

#endif	// _E_CARTESIAN_POINT_H_
