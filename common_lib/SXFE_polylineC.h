/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_polylineC.h								作成日：2000.4.18

	１．クラス概要
	polylineのエンティティデータ管理

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/
#ifndef _E_POLYLINE_H_
#define _E_POLYLINE_H_

#include "SXFD_InstC.h"

class SXFD_StrC;
class SXFD_AggrC;
class SXFD_ListAggrC;

//
//
//
class SXFE_polylineC : public SXFD_InstC {
protected :
public :
//
//	Constructor
//
	SXFE_polylineC(SXFD_StrC*,SXFD_AggrC*);
	SXFE_polylineC(SXFD_StrC*,SXFD_ListAggrC*);//ID_153_000607_ins
} ;

#endif	// _E_POLYLINE_H_
