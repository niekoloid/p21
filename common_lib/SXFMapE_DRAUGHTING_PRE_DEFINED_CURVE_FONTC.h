/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_DRAUGHTING_PRE_DEFINED_CURVE_FONTC.h						作成日：2000.04.17

	１．クラス概要
		DRAUGHTING_PRE_DEFINED_CURVE_FONTを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#ifndef _SXFMapE_DRAUGHTING_PRE_DEFINED_CURVE_FONTC_CLASS_
#define _SXFMapE_DRAUGHTING_PRE_DEFINED_CURVE_FONTC_CLASS_

#include <afx.h>
#include <afxtempl.h>
#include "SXFMapEntityBaseC.h"

class SXFInstanceIDC;

class SXFMapE_DRAUGHTING_PRE_DEFINED_CURVE_FONTC : public SXFMapEntityBaseC {
public :
//
//	<デフォルトコンストラクタ>
	SXFMapE_DRAUGHTING_PRE_DEFINED_CURVE_FONTC( ) ;

//	<コンストラクタ>
//	<インスタンスＩＤへのポインタを登録し生成する>
	SXFMapE_DRAUGHTING_PRE_DEFINED_CURVE_FONTC(SXFInstanceIDC* IN_InstanceIDManeger) ;

//	<デストラクタ>
	virtual	~SXFMapE_DRAUGHTING_PRE_DEFINED_CURVE_FONTC() ;

//エンティティパラメタの登録
	int	SetParameter();

//	<メンバ変数>	//////////////////////////////////////

//<エンティティデータ>
//  ENTITY draughting_pre_defined_curve_font
//    SUBTYPE OF (pre_defined_curve_font);
//    WHERE
//      wr1: SELF.name IN ['continuous','chain','chain double dash','dashed',
//               'dotted'];
//  END_ENTITY; -- draughting_pre_defined_curve_font

//#20 = DRAUGHTING_PRE_DEFINED_CURVE_FONT('continuous');
	//nameパラメタ
	CString		m_name;	

private :

protected :

} ;

#endif
