/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_STYLED_ITEMC.h						作成日：2000.04.17

	１．クラス概要
		STYLED_ITEMを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#ifndef _SXFMapE_STYLED_ITEMC_CLASS_
#define _SXFMapE_STYLED_ITEMC_CLASS_

#include <afx.h>
#include <afxtempl.h>
#include "SXFMapEntityBaseC.h"

class SXFInstanceIDC;

class SXFMapE_STYLED_ITEMC : public SXFMapEntityBaseC {
public :
//
//	<デフォルトコンストラクタ>
	SXFMapE_STYLED_ITEMC( ) ;

//	<コンストラクタ>
//	<インスタンスＩＤへのポインタを登録し生成する>
	SXFMapE_STYLED_ITEMC(SXFInstanceIDC* IN_InstanceIDManeger) ;

//	<デストラクタ>
	virtual	~SXFMapE_STYLED_ITEMC() ;

//エンティティパラメタの登録
	int	SetParameter();

//	<メンバ変数>	//////////////////////////////////////

//	<エンティティデータ>
//#101 = STYLED_ITEM('',(#508), #505);

//	styled_item 単独の時はnameパラメタが必要 /////////////////////
//	1. nameパラメタ>
	CString m_name;

//	<図形見え方へのＩＤ>
	int		m_AppeID ;
//	<図形インスタンス部へのＩＤ>
	int		m_InstID ;
//	<図形見え方へのポインタ>
//	void*		m_AppeP ;
//	<図形インスタンス部へのポインタ>
//	void*		m_InstP ;
private :

protected :

} ;

#endif
