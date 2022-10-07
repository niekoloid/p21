/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_CURVE_STYLE_FONTC.h						作成日：2000.04.17

	１．クラス概要
		CURVE_STYLE_FONTを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#ifndef _SXFMapE_CURVE_STYLE_FONTC_CLASS_
#define _SXFMapE_CURVE_STYLE_FONTC_CLASS_

#include <afx.h>
#include <afxtempl.h>

#include "SXFMapEntityBaseC.h"

class SXFInstanceIDC;
class SXFMapE_CURVE_STYLE_FONT_PATTERNC;

class SXFMapE_CURVE_STYLE_FONTC : public SXFMapEntityBaseC {
public :
//
//	<デフォルトコンストラクタ>
	SXFMapE_CURVE_STYLE_FONTC( ) ;

//	<コンストラクタ>
//	<インスタンスＩＤへのポインタを登録し生成する>
	SXFMapE_CURVE_STYLE_FONTC(SXFInstanceIDC* IN_InstanceIDManeger) ;

//	<デストラクタ>
	virtual	~SXFMapE_CURVE_STYLE_FONTC() ;


//エンティティパラメタの登録
	int	SetParameter();

//	<メンバ変数>	//////////////////////////////////////

//<エンティティデータ>
//#80 = CURVE_STYLE_FONT('chain_4212', (#81, #82));
	//nameパラメタ
	CString		m_name;	
	//m_CURVE_STYLE_FONT_PATTERN_InsへのインスタンスID
	CArray<int,int>		m_CURVE_STYLE_FONT_PATTERN_Inst;

	//セグメント数	※エンティティパラメタには存在しない。					
	int	m_Segment;
	//m_CURVE_STYLE_FONT_PATTERN_Insへのポインタ
	CArray<SXFMapE_CURVE_STYLE_FONT_PATTERNC*,SXFMapE_CURVE_STYLE_FONT_PATTERNC*>	m_CURVE_STYLE_FONT_PATTERN_P;

private :

protected :

} ;

#endif
