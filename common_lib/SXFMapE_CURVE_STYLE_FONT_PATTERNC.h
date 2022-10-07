/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_CURVE_STYLE_FONT_PATTERNC.h						作成日：2000.04.17

	１．クラス概要
		CURVE_STYLE_FONT_PATTERNを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#ifndef _SXFMapE_CURVE_STYLE_FONT_PATTERNC_CLASS_
#define _SXFMapE_CURVE_STYLE_FONT_PATTERNC_CLASS_

#include <afx.h>
#include <afxtempl.h>
#include "SXFMapEntityBaseC.h"

class SXFInstanceIDC;

class SXFMapE_CURVE_STYLE_FONT_PATTERNC : public SXFMapEntityBaseC {
public :
//
//	<デフォルトコンストラクタ>
	SXFMapE_CURVE_STYLE_FONT_PATTERNC( ) ;

//	<コンストラクタ>
//	<インスタンスＩＤへのポインタを登録し生成する>
	SXFMapE_CURVE_STYLE_FONT_PATTERNC(SXFInstanceIDC* IN_InstanceIDManeger) ;

//	<デストラクタ>
	virtual	~SXFMapE_CURVE_STYLE_FONT_PATTERNC() ;

//エンティティパラメタの登録
	int	SetParameter();

//	<メンバ変数>	//////////////////////////////////////
//  ENTITY curve_style_font_pattern;
//      visible_segment_length   : positive_length_measure;
//      invisible_segment_length : positive_length_measure;
//  END_ENTITY; -- curve_style_font_pattern

//<エンティティデータ>
//#81 = CURVE_STYLE_FONT_PATTERN(4., 2.);
///	CString		m_name;		//nameパラメタ
	double		m_visi;		//表示部分の長さ
	double		m_invisi;	//非表示部分の長さ

private :

protected :

} ;

#endif
