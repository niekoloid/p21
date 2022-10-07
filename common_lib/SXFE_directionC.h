/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_directionC.h							作成日：2000.4.18

	１．クラス概要
	directionのエンティティデータ管理

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/
#ifndef _E_DIRECTION_H_
#define _E_DIRECTION_H_

#include "SXFD_InstC.h"

class SXFD_StrC;
class SXFD_AggrC;
//
//
//
class SXFE_directionC : public SXFD_InstC {
protected :
public :
//
//	Constructor
//
	SXFE_directionC(SXFD_StrC*,SXFD_AggrC*);
} ;

#endif	// _E_DIRECTION_H_
