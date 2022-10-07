/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_drawing_definitionC.h								作成日：2000.4.18

	１．クラス概要
	drawing_definitionのエンティティデータ管理

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。
	更新			2004.01.30			K.Naono				Ver3.0対応

**/
#ifndef _E_DRAWING_DEFINITION_H_
#define _E_DRAWING_DEFINITION_H_

#include "SXFD_InstC.h"

class SXFD_StrC;
//
//
//
class SXFE_drawing_definitionC : public SXFD_InstC {
protected :
	SXFD_StrC* m_str;
public :
//
//	Constructor
//
	~SXFE_drawing_definitionC();
	SXFE_drawing_definitionC(SXFD_StrC*);

//	ADD(S)	Ver3.0対応	K.Naono	04.01.30
	SXFE_drawing_definitionC(SXFD_StrC*, SXFD_StrC*) ;
//	ADD(E)	Ver3.0対応	K.Naono	04.01.30
} ;

#endif	// _E_DRAWING_DEFINITION_H_
