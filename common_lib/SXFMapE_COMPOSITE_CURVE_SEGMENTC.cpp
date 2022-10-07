/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_COMPOSITE_CURVE_SEGMENTC.cpp						作成日：2000.04.17

	１．クラス概要
		COMPOSITE_CURVE_SEGMENTを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#include "stdafx.h"
#include "SXFMapE_COMPOSITE_CURVE_SEGMENTC.h"
#include "SXFMapE_CARTESIAN_POINTC.h"
#include "SXFMapE_LINEC.h"
#include "SXFMapE_CIRCLEC.h"
#include "SXFMapEntAConvC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_COMPOSITE_CURVE_SEGMENTC.cpp						作成日：2000.04.17

	１．機能概要
		デフォルトコンストラクタ

	２．インターフェイス
		void	SXFMapE_COMPOSITE_CURVE_SEGMENTC::SXFMapE_COMPOSITE_CURVE_SEGMENTC()

	引数  ：	型			引数名				内容
			なし
	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_COMPOSITE_CURVE_SEGMENTC::SXFMapE_COMPOSITE_CURVE_SEGMENTC()
{
//	<初期化>
	m_EntityName = DEF_COMPOSITE_CURVE_SEGMENT;

//<エンティティデータ>
//#1201 = ANNOTATION_FILL_AREA('annotation_fill_area2', (#1121, #1181));
//#1181 = COMPOSITE_CURVE('composite_curve4', (#1140, #1160), .F.);
//#1160 = COMPOSITE_CURVE_SEGMENT(.CONTINUOUS., .T., #1165);

	//1.transition_code
	m_tran_code =0;
//		1:discontinuous,
//		2:continuous,//
//		3:cont_same_gradient,
//		4:cont_same_gradient_same_curvature

	//2.parent_curve へのインスタンスID
	m_parent_curve_Inst=0;

	//parent_curveへのポインタ
	m_parent_curve_P =NULL;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_COMPOSITE_CURVE_SEGMENTC.cpp						作成日：2000.04.17

	１．機能概要
		インスタンスＩＤへのポインタを指定して生成する場合
		(コンストラクタ)

	２．インターフェイス
		void	SXFMapE_COMPOSITE_CURVE_SEGMENTC::SXFMapE_COMPOSITE_CURVE_SEGMENTC(
						SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	引数：	型				引数名				内容
			SXFInstanceIDC* IN_InstanceIDManeger	ｲﾝｽﾀﾝｽID管理ｵﾌﾞｼﾞｪｸﾄ

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_COMPOSITE_CURVE_SEGMENTC::SXFMapE_COMPOSITE_CURVE_SEGMENTC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
{
//	<初期化>
	m_EntityName = DEF_COMPOSITE_CURVE_SEGMENT;
//<エンティティデータ>
//#1201 = ANNOTATION_FILL_AREA('annotation_fill_area2', (#1121, #1181));
//#1181 = COMPOSITE_CURVE('composite_curve4', (#1140, #1160), .F.);
//#1160 = COMPOSITE_CURVE_SEGMENT(.CONTINUOUS., .T., #1165);

	//1.transition_code
	m_tran_code =0;
//		1:discontinuous,
//		2:continuous,//
//		3:cont_same_gradient,
//		4:cont_same_gradient_same_curvature

	//2.parent_curve へのインスタンスID
	m_parent_curve_Inst=0;

	//parent_curveへのポインタ
	m_parent_curve_P =NULL;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_COMPOSITE_CURVE_SEGMENTC.cpp						作成日：2000.04.17

	１．機能概要
		(デストラクタ)

	２．インターフェイス
		void	SXFMapE_COMPOSITE_CURVE_SEGMENTC::~SXFMapE_COMPOSITE_CURVE_SEGMENTC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_COMPOSITE_CURVE_SEGMENTC::~SXFMapE_COMPOSITE_CURVE_SEGMENTC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_COMPOSITE_CURVE_SEGMENTC.cpp						作成日：2000.04.17

	１．機能概要
		エンティティのパラメタ設定

	２．インターフェイス
		int		SXFMapE_COMPOSITE_CURVE_SEGMENTC::SetParameter()

	引数  ：	型			引数名				内容

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/

int SXFMapE_COMPOSITE_CURVE_SEGMENTC::SetParameter()

{
//	<1. エンティティパラメタの設定> ////////////////////////////////////////

//<エンティティデータ>
//#1201 = ANNOTATION_FILL_AREA('annotation_fill_area2', (#1121, #1181));
//#1181 = COMPOSITE_CURVE('composite_curve4', (#1140, #1160), .F.);
//#1160 = COMPOSITE_CURVE_SEGMENT(.CONTINUOUS., .T., #1165);

	SXFMapEntAConvC convert(m_EntityArray);
	//1.transition_code
//	m_tran_code =0;           ///////////////////////保留
//		1:discontinuous,
//		2:continuous,//
//		3:cont_same_gradient,
//		4:cont_same_gradient_same_curvature	convent.GetCString(0,m_name);

	//2.sense_agreement
	convert.GetBOOL(1,m_sense);	

	//	2.parent_curve へのインスタンスID
	convert.GetInst(2,m_parent_curve_Inst);

//	<3. parent_curve //////////////////////////////////////////////////////////

	return 0;
}
