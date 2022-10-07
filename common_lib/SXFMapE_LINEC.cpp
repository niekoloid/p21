/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_LINEC.cpp						作成日：2000.04.17

	１．クラス概要
		LINEを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/

#include "stdafx.h"
#include "SXFStruct.h"
#include "SXFMapFeatureBaseC.h"
#include "SXFMapF_CurveStyleBaseC.h"
#include "SXFMapE_LINEC.h"
#include "SXFMapE_CARTESIAN_POINTC.h"
#include "SXFMapE_VECTORC.h"
#include "SXFMapEntAConvC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_LINEC.cpp						作成日：2000.04.17

	１．機能概要
		デフォルトコンストラクタ

	２．インターフェイス
		void	SXFMapE_LINEC::SXFMapE_LINEC()

	引数  ：	型			引数名				内容
			なし
	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_LINEC::SXFMapE_LINEC()
{
//	<初期化>
	m_EntityName = DEF_LINE;
//<エンティティデータ>
//#426 = LINE('line1', #425, #424);
	//nameパラメタ
	m_name.Empty();

	//VECTOR,CARTESIAN_POINTへのインスタンスID
	m_pnt_Inst = m_vector_Inst = 0;
	
	//VECTOR,CARTESIAN_POINTへのポインタ
	m_pnt_P = NULL;
	m_vector_P = NULL;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_LINEC.cpp						作成日：2000.04.17

	１．機能概要
		インスタンスＩＤへのポインタを指定して生成する場合
		(コンストラクタ)

	２．インターフェイス
		void	SXFMapE_LINEC::SXFMapE_LINEC(
						SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)


	引数 ：	型				引数名				内容
			SXFInstanceIDC* IN_InstanceIDManeger	ｲﾝｽﾀﾝｽID管理ｵﾌﾞｼﾞｪｸﾄ

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_LINEC::SXFMapE_LINEC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
{
//	<初期化>
	m_EntityName = DEF_LINE;
//<エンティティデータ>
//#426 = LINE('line1', #425, #424);
	//nameパラメタ
	m_name.Empty();

	//VECTOR,CARTESIAN_POINTへのインスタンスID
	m_pnt_Inst = m_vector_Inst = 0;

	//VECTOR,CARTESIAN_POINTへのポインタ
	m_pnt_P = NULL;
	m_vector_P = NULL;

}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_LINEC.cpp						作成日：2000.04.17

	１．機能概要
		(デストラクタ)

	２．インターフェイス
		void	SXFMapE_LINEC::~SXFMapE_LINEC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_LINEC::~SXFMapE_LINEC()
{
	if(m_pnt_P != NULL)
	{
		delete m_pnt_P;
	}
	if(m_vector_P != NULL)
	{
		delete m_vector_P;
	}
}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_LINEC.cpp						作成日：2000.04.17

	１．機能概要
		エンティティのパラメタ設定

	２．インターフェイス
		int		SXFMapE_LINEC::SetParameter()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/


int SXFMapE_LINEC::SetParameter()

{
int ircode;
//	<1. エンティティパラメタの設定>

//<エンティティデータ>
//#426 = LINE('line1', #425, #424);
	SXFMapEntAConvC convent(m_EntityArray);
	//	<nameパラメタ>
	convent.GetCString(0,m_name);

	//CARTESIAN_POINTへのインスタンスIDの設定
	convent.GetInst(1,m_pnt_Inst);

	//VECTORへのインスタンスIDの設定
	convent.GetInst(2,m_vector_Inst);

//	<2. 参照先のエンティティパラメタの設定>

	//CARTESIAN_POINT
	//エンティティインスタンスを作成
//	SXFMapE_CARTESIAN_POINTC m_pnt_P(m_InstanceIDManager);
	m_pnt_P = new SXFMapE_CARTESIAN_POINTC(m_InstanceIDManager);
	ircode = m_pnt_P->SetRootID(m_pnt_Inst);
	if ( ircode < 0 )	return ircode ;
	//エンティティパラメタの設定
	ircode = m_pnt_P->SetParameter();
	if ( ircode < 0 )	return ircode ;

	//VECTOR
//	SXFMapE_VECTORC m_vector_P(m_InstanceIDManager);
	m_vector_P = new SXFMapE_VECTORC(m_InstanceIDManager);
	ircode = m_vector_P->SetRootID(m_vector_Inst);
	if ( ircode < 0 )	return ircode ;
	//エンティティパラメタの設定
	ircode = m_vector_P->SetParameter();
	if ( ircode < 0 )	return ircode ;
	return 0;
}
