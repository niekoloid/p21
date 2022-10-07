/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_COLOUR_RGBC.h						作成日：2000.04.17

	１．クラス概要
		COLOUR_RGBを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#ifndef _SXFMapE_COLOUR_RGBC_CLASS_
#define _SXFMapE_COLOUR_RGBC_CLASS_

#include <afx.h>
#include <afxtempl.h>
#include "SXFMapEntityBaseC.h"

class SXFInstanceIDC;

class SXFMapE_COLOUR_RGBC : public SXFMapEntityBaseC {
public :
//
//	<デフォルトコンストラクタ>
	SXFMapE_COLOUR_RGBC( ) ;

//	<コンストラクタ>
//	<インスタンスＩＤへのポインタを登録し生成する>
	SXFMapE_COLOUR_RGBC(SXFInstanceIDC* IN_InstanceIDManeger) ;

//	<デストラクタ>
	virtual	~SXFMapE_COLOUR_RGBC() ;


//エンティティパラメタの登録
	int	SetParameter();

//	<メンバ変数>	//////////////////////////////////////

//	<エンティティデータ>
//	ENTITY colour_rgb
//	  SUBTYPE OF (colour_specification);
//		red   : REAL;
//		green : REAL;
//		blue  : REAL;
//	  WHERE
//		wr1: (0 <= red) AND (red <= 1);
//		wr2: (0 <= green) AND (green <= 1);
//		wr3: (0 <= blue) AND (blue <= 1);
//	END_ENTITY; -- colour_rgb

//#140 = COLOUR_RGB('colour_rgb1', 0.12, 0.56, 1.);
//#140 = COLOUR_RGB('$$SXF_', 0.12, 0.56, 1.);
//	<name(色名）>
	CString		m_name;
	
//	<RGB値>	
	double		m_R;	// 0=< m_R =< 1.0
	double		m_G;
	double		m_B;

private :

protected :

} ;

#endif
