/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_ellipseC.h								作成日：2000.4.18

	１．クラス概要
	ellipseのエンティティデータ管理

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/
#ifndef _E_ELLIPSE_H_
#define _E_ELLIPSE_H_

#include "SXFD_InstC.h"

class SXFD_StrC;
class SXFD_RealC;
//
//
//
class SXFE_ellipseC : public SXFD_InstC {
protected :
public :
//
//	Constructor
//
	SXFE_ellipseC(SXFD_StrC*,SXFD_InstC*,SXFD_RealC*,SXFD_RealC*);
} ;

#endif	// _E_ELLPSE_H_
