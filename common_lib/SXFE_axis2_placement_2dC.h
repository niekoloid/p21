/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_axis2_placement_2dC.h								作成日：2000.4.18

	１．クラス概要
	axis2_placement_2dのエンティティデータ管理

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/
#ifndef _E_AXIS2_PLACEMENT_2D_H_
#define _E_AXIS2_PLACEMENT_2D_H_

#include "SXFD_InstC.h"

class SXFD_StrC;
//
//
//
class SXFE_axis2_placement_2dC : public SXFD_InstC {
protected :
public :
//
//	Constructor
//
	SXFE_axis2_placement_2dC(SXFD_StrC*,SXFD_InstC*,SXFD_InstC*);
	SXFE_axis2_placement_2dC(SXFD_StrC*,SXFD_InstC*,SXFD_StrC*);

} ;

#endif	// _E_AXIS2_PLACEMENT_2D_H_
