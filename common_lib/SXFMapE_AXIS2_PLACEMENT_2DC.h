/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_AXIS2_PLACEMENT_2DC.h						作成日：2000.04.17

	１．クラス概要
		AXIS2_PLACEMENT_2Dを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#ifndef _SXFMapE_AXIS2_PLACEMENT_2DC_CLASS_
#define _SXFMapE_AXIS2_PLACEMENT_2DC_CLASS_

#include <afx.h>
#include <afxtempl.h>

#include "SXFMapEntityBaseC.h"

class SXFInstanceIDC;
class SXFMapE_CARTESIAN_POINTC;
class SXFMapE_DIRECTIONC;

class SXFMapE_AXIS2_PLACEMENT_2DC : public SXFMapEntityBaseC {
public :
//
//	<デフォルトコンストラクタ>
	SXFMapE_AXIS2_PLACEMENT_2DC( ) ;

//	<コンストラクタ>
//	<インスタンスＩＤへのポインタを登録し生成する>
	SXFMapE_AXIS2_PLACEMENT_2DC(SXFInstanceIDC* IN_InstanceIDManeger) ;

//	<デストラクタ>
	virtual	~SXFMapE_AXIS2_PLACEMENT_2DC() ;

//エンティティパラメタの登録
	int	SetParameter();

//	<メンバ変数>	//////////////////////////////////////

//<エンティティデータ>
/*	
	ENTITY placement
	 SUPERTYPE OF (ONEOF (axis2_placement_2d))
	 SUBTYPE OF (geometric_representation_item);
	  location : cartesian_point;
	END_ENTITY; -- placement

	ENTITY axis2_placement_2d
	SUBTYPE OF (placement);
	  ref_direction : OPTIONAL direction;
	DERIVE
	  p : LIST [2:2] OF direction := build_2axes(ref_direction);
	WHERE
	  wr1: SELF\geometric_representation_item.dim = 2;
  END_ENTITY; -- axis2_placement_2d		*/
//#102 = AXIS2_PLACEMENT_2D('axis2_placement_2d1', #101, $);
//#123 = AXIS2_PLACEMENT_2D('axis2_placement_2d2', #121, #122);

	//	1.nameパラメタ
	CString		m_name;

	//	2.cartesian_point へのインスタンスID
	int		m_pnt_Inst;
	//cartesian_pointへのポインタ

	SXFMapE_CARTESIAN_POINTC*	m_pnt_P;

	//	3.DIRECTION へのインスタンスID(OPTIONAL)
	int		m_DIRECTION_Inst;
	//DIRECTIONへのポインタ
	SXFMapE_DIRECTIONC*	m_DIRECTION_P;

private :

protected :

} ;

#endif
