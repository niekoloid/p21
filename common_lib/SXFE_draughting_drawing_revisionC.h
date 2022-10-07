/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_draughting_drawing_revisionC.h								作成日：2000.4.18

	１．クラス概要
	draughting_drawing_revisionのエンティティデータ管理

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。
	更新			2004.01.30			K.Naono				Ver3.0対応

**/
#ifndef _E_DRAUGHTING_DRAWING_REVISION_H_
#define _E_DRAUGHTING_DRAWING_REVISION_H_

#include "SXFD_InstC.h"

class SXFD_StrC;
//
//
//
class SXFE_draughting_drawing_revisionC : public SXFD_InstC {
protected :
public :
//
//	Constructor
//
	SXFE_draughting_drawing_revisionC(SXFD_StrC*,SXFD_InstC*);
	~SXFE_draughting_drawing_revisionC();

//	ADD(S)	Ver3.0対応	K.Naono	04.01.30
	SXFE_draughting_drawing_revisionC(SXFD_StrC*,SXFD_InstC*,SXFD_StrC*);
//	ADD(S)	Ver3.0対応	K.Naono	04.01.30

private:
	SXFD_StrC* m_str;
} ;

#endif	// _E_DRAUGHTING_DRAWING_REVISION_H_
