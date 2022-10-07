/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_text_style_with_box_characteristicsC.h								作成日：2000.4.18

	１．クラス概要
	text_style_with_box_characteristicsのエンティティデータ管理

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/
#ifndef _E_TEXT_STYLE_WITH_BOX_CHARACTERISTICS_H_
#define _E_TEXT_STYLE_WITH_BOX_CHARACTERISTICS_H_

#include "SXFD_InstC.h"

class SXFD_StrC;
class SXFD_TypeC;
class SXFD_RealC;
class SXFD_AggrC;
class SXFPart21FileC;
//
//
//
class SXFE_text_style_with_box_characteristicsC : public SXFD_InstC {
protected :
public :
//
//	Constructor
//
	SXFE_text_style_with_box_characteristicsC(SXFD_StrC*,SXFD_InstC*,SXFD_AggrC*,SXFD_TypeC*);
//
//
//
	void WriteP21(SXFPart21FileC *IN_file);
} ;

#endif	// _E_TEXT_STYLE_WITH_BOX_CHARACTERISTICS_H_
