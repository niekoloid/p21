/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_clothoidC.h								作成日：2007.1.30

	１．クラス概要
	clothoidのエンティティデータ管理

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2007.1.30			下林				なし。

**/
#ifndef _E_CLOTHOID_H_
#define _E_CLOTHOID_H_

#include "SXFD_InstC.h"

class SXFD_StrC;
class SXFD_RealC;
//
//
//
class SXFE_clothoidC : public SXFD_InstC {
protected :
public :
//
//	Constructor
//
	SXFE_clothoidC(SXFD_StrC *str,SXFD_InstC *inst,SXFD_RealC *real);
} ;

#endif	// _E_CLOTHOID_H_
