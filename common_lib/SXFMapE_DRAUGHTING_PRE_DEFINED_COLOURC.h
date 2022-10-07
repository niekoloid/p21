/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_DRAUGHTING_PRE_DEFINED_COLOURC.h						作成日：2000.04.17

	１．クラス概要
		DRAUGHTING_PRE_DEFINED_COLOURを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#ifndef _SXFMapE_DRAUGHTING_PRE_DEFINED_COLOURC_CLASS_
#define _SXFMapE_DRAUGHTING_PRE_DEFINED_COLOURC_CLASS_

#include <afx.h>
#include <afxtempl.h>
#include "SXFMapEntityBaseC.h"

class SXFInstanceIDC;

class SXFMapE_DRAUGHTING_PRE_DEFINED_COLOURC : public SXFMapEntityBaseC {
public :
//
//	<デフォルトコンストラクタ>
	SXFMapE_DRAUGHTING_PRE_DEFINED_COLOURC( ) ;

//	<コンストラクタ>
//	<インスタンスＩＤへのポインタを登録し生成する>
	SXFMapE_DRAUGHTING_PRE_DEFINED_COLOURC(SXFInstanceIDC* IN_InstanceIDManeger) ;

//	<デストラクタ>
	virtual	~SXFMapE_DRAUGHTING_PRE_DEFINED_COLOURC() ;

//エンティティパラメタの登録
	int	SetParameter();

//	<メンバ変数>	//////////////////////////////////////

//<エンティティデータ>
//  ENTITY draughting_pre_defined_colour
//    SUBTYPE OF (pre_defined_colour);
//    WHERE
//      wr1: SELF.name IN ['black','red','green','blue','yellow','magenta',
//               'cyan','white'];
//  END_ENTITY; -- draughting_pre_defined_colour

//#40 = DRAUGHTING_PRE_DEFINED_COLOUR('black');
//nameパラメタ
	CString		m_name;	

private :

protected :

} ;

#endif
