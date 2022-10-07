/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_CIRCLEC.cpp						作成日：2000.04.17

	１．クラス概要
		CIRCLEを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#include "stdafx.h"
#include "SXFMapE_CIRCLEC.h"
#include "SXFMapE_AXIS2_PLACEMENT_2DC.h"
#include "SXFMapEntAConvC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_CIRCLEC.cpp						作成日：2000.04.17

	１．機能概要
		デフォルトコンストラクタ

	２．インターフェイス
		void	SXFMapE_CIRCLEC::SXFMapE_CIRCLEC()

	引数  ：	型			引数名				内容
			なし
	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_CIRCLEC::SXFMapE_CIRCLEC()
{
//	<初期化>
	m_EntityName = DEF_CIRCLE;

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
	m_name.Empty();

	//	2.AXIS2_PLACEMENT_2D へのインスタンスID
	m_axis2_Inst = 0;
	//AXIS2_PLACEMENT_2Dへのポインタ
	m_axis2_P = NULL;

	//	3.半径の大きさ
	m_radius = 0.;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_CIRCLEC.cpp						作成日：2000.04.17

	１．機能概要
		インスタンスＩＤへのポインタを指定して生成する場合
		(コンストラクタ)

	２．インターフェイス
		void	SXFMapE_CIRCLEC::SXFMapE_CIRCLEC(
						SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	引数 ：	型				引数名					内容
			SXFInstanceIDC* IN_InstanceIDManeger	ｲﾝｽﾀﾝｽID管理ｵﾌﾞｼﾞｪｸﾄ

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_CIRCLEC::SXFMapE_CIRCLEC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
{
//	<初期化>
	m_EntityName = DEF_CIRCLE;
//<エンティティデータ>

//#103 = CIRCLE('circle1', #102, 12.5);
	//	1.nameパラメタ
	m_name.Empty();

	//	2.AXIS2_PLACEMENT_2D へのインスタンスID
	m_axis2_Inst = 0;
	//AXIS2_PLACEMENT_2Dへのポインタ
	m_axis2_P = NULL;

	//	3.半径の大きさ
	m_radius = 0.;
}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_CIRCLEC.cpp						作成日：2000.04.17

	１．機能概要
		(デストラクタ)

	２．インターフェイス
		void	SXFMapE_CIRCLEC::~SXFMapE_CIRCLEC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_CIRCLEC::~SXFMapE_CIRCLEC()
{
	if(m_axis2_P != NULL)
	{
		delete m_axis2_P;
	}
}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_CIRCLEC.cpp						作成日：2000.04.17

	１．機能概要
		エンティティのパラメタ設定

	２．インターフェイス
		int		SXFMapE_CIRCLEC::SetParameter()

	引数  ：	型			引数名				内容
					なし
	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/


int SXFMapE_CIRCLEC::SetParameter()

{
int ircode;

//	<1. エンティティパラメタの設定>/////////////////////////////////////


//<エンティティデータ>
//#103 = CIRCLE('circle1', #102, 12.5);

	SXFMapEntAConvC convent(m_EntityArray);

	//	1. nameパラメタ>
	convent.GetCString(0,m_name);

	//	2.AXIS2_PLACEMENT_2DへのインスタンスIDの設定
	convent.GetInst(1,m_axis2_Inst);

	//	3.半径の大きさ
	convent.GetDouble(2,m_radius);

	//	2. 参照先のAXIS2_PLACEMENT_2Dエンティティパラメタの設定

	//エンティティインスタンスを作成
	m_axis2_P = new SXFMapE_AXIS2_PLACEMENT_2DC(m_InstanceIDManager);
	ircode = m_axis2_P->SetRootID(m_axis2_Inst);
	if ( ircode < 0 )	return ircode ;
	//エンティティパラメタの設定
	ircode = m_axis2_P->SetParameter();
	if ( ircode < 0 )	return ircode ;
	return 0;
}
