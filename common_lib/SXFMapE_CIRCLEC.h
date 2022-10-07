/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_CIRCLEC.h						作成日：2000.04.17

	１．クラス概要
		CIRCLEを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#ifndef _SXFMapE_CIRCLEC_CLASS_
#define _SXFMapE_CIRCLEC_CLASS_

//#include <afx.h>
//#include <afxtempl.h>

#include "SXFMapEntityBaseC.h"

class SXFInstanceIDC;
class SXFMapE_AXIS2_PLACEMENT_2DC;

class SXFMapE_CIRCLEC : public SXFMapEntityBaseC {
public :
//
//	<デフォルトコンストラクタ>
	SXFMapE_CIRCLEC( ) ;

//	<コンストラクタ>
//	<インスタンスＩＤへのポインタを登録し生成する>
	SXFMapE_CIRCLEC(SXFInstanceIDC* IN_InstanceIDManeger) ;

//	<デストラクタ>
	virtual	~SXFMapE_CIRCLEC() ;

//エンティティパラメタの登録
	int	SetParameter();

//	<メンバ変数>	//////////////////////////////////////

//<エンティティデータ>
/*
  ENTITY conic
	SUPERTYPE OF (ONEOF (circle,ellipse))
	SUBTYPE OF (curve);
	  position : axis2_placement;
  END_ENTITY; -- conic

  ENTITY circle
	SUBTYPE OF (conic);
	  radius : positive_length_measure;
  END_ENTITY; -- circle
*/

//#103 = CIRCLE('circle1', #102, 12.5);

	//	1.nameパラメタ
	CString		m_name;
	
	//	2.AXIS2_PLACEMENT_2D へのインスタンスID
	int		m_axis2_Inst;
	//AXIS2_PLACEMENT_2Dへのポインタ
	SXFMapE_AXIS2_PLACEMENT_2DC*	m_axis2_P;

	//	3.半径の大きさ
	double	m_radius;

private :

protected :

} ;

#endif
