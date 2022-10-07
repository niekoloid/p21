/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_CARTESIAN_POINTC.h						作成日：2000.04.17

	１．クラス概要
		CARTESIAN_POINTを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#ifndef _SXFMapE_CARTESIAN_POINTC_CLASS_
#define _SXFMapE_CARTESIAN_POINTC_CLASS_

#include <afx.h>
//#include <afxtempl.h>
#include "SXFMapEntityBaseC.h"

class SXFInstanceIDC;

class SXFMapE_CARTESIAN_POINTC : public SXFMapEntityBaseC {
public :
//
//	<デフォルトコンストラクタ>
	SXFMapE_CARTESIAN_POINTC( ) ;

//	<コンストラクタ>
//	<インスタンスＩＤへのポインタを登録し生成する>
	SXFMapE_CARTESIAN_POINTC(SXFInstanceIDC* IN_InstanceIDManeger) ;

//	<デストラクタ>
	virtual	~SXFMapE_CARTESIAN_POINTC() ;

//エンティティパラメタの登録
	int	SetParameter();

//	<メンバ変数>	//////////////////////////////////////

//	<エンティティデータ>
//#101 = CARTESIAN_POINT('cartesian_point1', (0., 0.));
//name
	CString		m_name;
//	<(x,Y)>
	double		m_x;
	double		m_y;

private :

protected :

} ;

#endif
