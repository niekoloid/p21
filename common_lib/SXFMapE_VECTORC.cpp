/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_VECTORC.cpp						作成日：2000.04.17

	１．クラス概要
		VECTORを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#include "stdafx.h"
#include "SXFMapE_VECTORC.h"
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
	SXFMapE_VECTORC.cpp						作成日：2000.04.17

	１．機能概要
		デフォルトコンストラクタ

	２．インターフェイス
		void	SXFMapE_VECTORC::SXFMapE_VECTORC()

	引数  ：	型			引数名				内容
			なし
	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_VECTORC::SXFMapE_VECTORC()
{
//	<初期化>
	m_EntityName = DEF_VECTOR;
//<エンティティデータ>
//#424 = VECTOR('vector1', #423, 30.);
	//nameパラメタ
	m_name.Empty();

	//DIRECTIONへのインスタンスID
	m_DIRECTION_Inst = 0;
	
	//DIRECTIONへのポインタ
	m_DIRECTION_P = NULL;

	//ベクトルの大きさ
	m_magni = 0.;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_VECTORC.cpp						作成日：2000.04.17

	１．機能概要
		インスタンスＩＤへのポインタを指定して生成する場合
		(コンストラクタ)

	２．インターフェイス
		void	SXFMapE_VECTORC::SXFMapE_VECTORC(
					SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	引数  ：	型				引数名				内容
				SXFInstanceIDC* IN_InstanceIDManeger	ｲﾝｽﾀﾝｽID管理ｵﾌﾞｼﾞｪｸﾄ

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_VECTORC::SXFMapE_VECTORC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
{
//	<初期化>
	m_EntityName = DEF_VECTOR;
//<エンティティデータ>
//#424 = VECTOR('vector1', #423, 30.);
	//nameパラメタ
	m_name.Empty();

	//DIRECTIONへのインスタンスID
	m_DIRECTION_Inst = 0;
	
	//DIRECTIONへのポインタ
	m_DIRECTION_P = NULL;

	//ベクトルの大きさ
	m_magni = 0.;

}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_VECTORC.cpp						作成日：2000.04.17

	１．機能概要
		(デストラクタ)

	２．インターフェイス
		void	SXFMapE_VECTORC::~SXFMapE_VECTORC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_VECTORC::~SXFMapE_VECTORC()
{
	if(m_DIRECTION_P != NULL)
	{
		delete m_DIRECTION_P;
	}
}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_VECTORC.cpp						作成日：2000.04.17

	１．機能概要
		エンティティのパラメタ設定

	２．インターフェイス
		int		SXFMapE_VECTORC::SetParameter()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/


int SXFMapE_VECTORC::SetParameter()

{
int ircode;

//	<1. エンティティパラメタの設定>/////////////////////////////////////

//<エンティティデータ>
//#424 = VECTOR('vector1', #423, 30.);
	SXFMapEntAConvC convent(m_EntityArray);
//	<1. nameパラメタ>
	convent.GetCString(0,m_name);

	//m_VECTOR_PATTERN_InsへのインスタンスIDの設定
	convent.GetInst(1,m_DIRECTION_Inst);
	

//	<2. 参照先のDIRECTIONエンティティパラメタの設定>
	//#940 = DIRECTION('direction49', (1., 1.));

	//エンティティインスタンスを作成
//	SXFMapE_DIRECTIONC m_DIRECTION_P(m_InstanceIDManager);
	m_DIRECTION_P = new SXFMapE_DIRECTIONC(m_InstanceIDManager);
	ircode = m_DIRECTION_P->SetRootID(m_DIRECTION_Inst);
		if ( ircode < 0 )	return ircode ;
	//エンティティパラメタの設定
	ircode = m_DIRECTION_P->SetParameter();
		if ( ircode < 0 )	return ircode ;

//	<3.ベクトルの大きさ>
	convent.GetDouble(2,m_magni);

	return 0;
}
