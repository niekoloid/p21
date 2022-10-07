/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_DIRECTIONC.h						作成日：2000.04.17

	１．クラス概要
		DIRECTIONを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#ifndef _SXFMapE_DIRECTIONC_CLASS_
#define _SXFMapE_DIRECTIONC_CLASS_

#include <afx.h>
#include <afxtempl.h>
#include "SXFMapEntityBaseC.h"

class SXFInstanceIDC;

class SXFMapE_DIRECTIONC : public SXFMapEntityBaseC {
public :
//
//	<デフォルトコンストラクタ>
	SXFMapE_DIRECTIONC( ) ;

//	<コンストラクタ>
//	<インスタンスＩＤへのポインタを登録し生成する>
	SXFMapE_DIRECTIONC(SXFInstanceIDC* IN_InstanceIDManeger) ;

//	<デストラクタ>
	virtual	~SXFMapE_DIRECTIONC() ;


//エンティティパラメタの登録
	int	SetParameter();

//	<メンバ変数>	//////////////////////////////////////

//	<エンティティデータ>
//#940 = DIRECTION('direction49', (1., 1.));
//name
	CString		m_name;
//	<(x,Y)>
	double		m_x;
	double		m_y;

private :

protected :

} ;

#endif
