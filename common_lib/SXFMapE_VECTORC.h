/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_VECTORC.h						作成日：2000.04.17

	１．クラス概要
		VECTORを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#ifndef _SXFMapE_VECTORC_CLASS_
#define _SXFMapE_VECTORC_CLASS_

#include <afx.h>
#include <afxtempl.h>

#include "SXFMapEntityBaseC.h"

class SXFInstanceIDC;
class SXFMapE_DIRECTIONC;

class SXFMapE_VECTORC : public SXFMapEntityBaseC {
public :
//
//	<デフォルトコンストラクタ>
	SXFMapE_VECTORC( ) ;

//	<コンストラクタ>
//	<インスタンスＩＤへのポインタを登録し生成する>
	SXFMapE_VECTORC(SXFInstanceIDC* IN_InstanceIDManeger) ;

//	<デストラクタ>
	virtual	~SXFMapE_VECTORC() ;

//エンティティパラメタの登録
	int	SetParameter();

//	<メンバ変数>	//////////////////////////////////////

//<エンティティデータ>
/*  ENTITY vector
    SUBTYPE OF (geometric_representation_item);
      orientation : direction;
      magnitude   : length_measure;
    WHERE
      wr1: magnitude >= 0;
  END_ENTITY; -- vector*/

//#424 = VECTOR('vector1', #423, 30.);
	//nameパラメタ
	CString		m_name;

	//DIRECTION へのインスタンスID
	int		m_DIRECTION_Inst;
	//DIRECTIONへのポインタ
	SXFMapE_DIRECTIONC*	m_DIRECTION_P;

	//ベクトルの大きさ
	double	m_magni;

private :

protected :

} ;

#endif
