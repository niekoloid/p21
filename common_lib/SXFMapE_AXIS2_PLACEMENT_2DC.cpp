/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_AXIS2_PLACEMENT_2DC.cpp						作成日：2000.04.17

	１．クラス概要
		AXIS2_PLACEMENT_2Dを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#include "stdafx.h"
#include "SXFMapE_AXIS2_PLACEMENT_2DC.h"
#include "SXFMapE_CARTESIAN_POINTC.h"
#include "SXFMapE_DIRECTIONC.h"
#include "SXFMapEntAConvC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_AXIS2_PLACEMENT_2DC.cpp						作成日：2000.04.17

	１．機能概要
		デフォルトコンストラクタ

	２．インターフェイス
		void	SXFMapE_AXIS2_PLACEMENT_2DC::SXFMapE_AXIS2_PLACEMENT_2DC()

	引数  ：	型			引数名				内容
			なし
	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_AXIS2_PLACEMENT_2DC::SXFMapE_AXIS2_PLACEMENT_2DC()
{
//	<初期化>
	m_EntityName = DEF_AXIS2_PLACEMENT_2D;
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
  END_ENTITY; -- axis2_placement_2d     */
//#102 = AXIS2_PLACEMENT_2D('axis2_placement_2d1', #101, $);
//#123 = AXIS2_PLACEMENT_2D('axis2_placement_2d2', #121, #122);

	//	1.nameパラメタ
	m_name.Empty();

	//	2.cartesian_point へのインスタンスID
	m_pnt_Inst = 0;
	//cartesian_pointへのポインタ
	m_pnt_P = NULL;

	//	3.DIRECTION へのインスタンスID(OPTIONAL)
	m_DIRECTION_Inst = 0;
	//DIRECTIONへのポインタ
	m_DIRECTION_P = NULL;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_AXIS2_PLACEMENT_2DC.cpp						作成日：2000.04.17

	１．機能概要
		インスタンスＩＤへのポインタを指定して生成する場合
		(コンストラクタ)

	２．インターフェイス
		void	SXFMapE_AXIS2_PLACEMENT_2DC::SXFMapE_AXIS2_PLACEMENT_2DC(
						SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)

	引数：	型				引数名				内容
			SXFInstanceIDC* IN_InstanceIDManeger　ｲﾝｽﾀﾝｽID管理ｵﾌﾞｼﾞｪｸﾄ

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_AXIS2_PLACEMENT_2DC::SXFMapE_AXIS2_PLACEMENT_2DC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
{
//	<初期化>
	m_EntityName = DEF_AXIS2_PLACEMENT_2D;
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
  END_ENTITY; -- axis2_placement_2d     */
//#102 = AXIS2_PLACEMENT_2D('axis2_placement_2d1', #101, $);
//#123 = AXIS2_PLACEMENT_2D('axis2_placement_2d2', #121, #122);

	//	1.nameパラメタ
	m_name.Empty();

	//	2.cartesian_point へのインスタンスID
	m_pnt_Inst = 0;
	//cartesian_pointへのポインタ
	m_pnt_P = NULL;

	//	3.DIRECTION へのインスタンスID(OPTIONAL)
	m_DIRECTION_Inst = 0;
	//DIRECTIONへのポインタ
	m_DIRECTION_P = NULL;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_AXIS2_PLACEMENT_2DC.cpp						作成日：2000.04.17

	１．機能概要
		(デストラクタ)

	２．インターフェイス
		void	SXFMapE_AXIS2_PLACEMENT_2DC::~SXFMapE_AXIS2_PLACEMENT_2DC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_AXIS2_PLACEMENT_2DC::~SXFMapE_AXIS2_PLACEMENT_2DC()
{
	if (m_pnt_P != NULL)
	{
		delete m_pnt_P;
	}
	if (m_DIRECTION_P != NULL)
	{
		delete m_DIRECTION_P;
	}
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_AXIS2_PLACEMENT_2DC.cpp						作成日：2000.04.17

	１．機能概要
		エンティティのパラメタ設定

	２．インターフェイス
		int		SXFMapE_AXIS2_PLACEMENT_2DC::SetParameter()

	引数  ：	型			引数名				内容
				なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
int SXFMapE_AXIS2_PLACEMENT_2DC::SetParameter()

{
int ircode;
//	<1. エンティティパラメタの設定>

//<エンティティデータ>
//#102 = AXIS2_PLACEMENT_2D('axis2_placement_2d1', #101, $);
//#123 = AXIS2_PLACEMENT_2D('axis2_placement_2d2', #121, #122);

	SXFMapEntAConvC convent(m_EntityArray);
	//	1.nameパラメタ
	convent.GetCString(0,m_name);

	//	2.cartesian_point へのインスタンスID
	convent.GetInst(1,m_pnt_Inst);

	//	3.DIRECTION へのインスタンスID(OPTIONAL)
	convent.GetInst(2,m_DIRECTION_Inst);

//	<2. 参照先のエンティティパラメタの設定>

	//CARTESIAN_POINT
	//エンティティインスタンスを作成
	m_pnt_P = new SXFMapE_CARTESIAN_POINTC(m_InstanceIDManager);
	ircode = m_pnt_P->SetRootID(m_pnt_Inst);
	if ( ircode < 0 )	return ircode ;
	//エンティティパラメタの設定
	ircode = m_pnt_P->SetParameter();
	if ( ircode < 0 )	return ircode ;

	//DIRECTION
	if ( m_DIRECTION_Inst >0 ) {	//optional 以外の時に設定
		m_DIRECTION_P = new SXFMapE_DIRECTIONC(m_InstanceIDManager);
		ircode = m_DIRECTION_P->SetRootID(m_DIRECTION_Inst);
			if ( ircode < 0 )	return ircode ;
		//エンティティパラメタの設定
		ircode = m_DIRECTION_P->SetParameter();
		if ( ircode < 0 )	return ircode ;
	}
	return 0;
}
