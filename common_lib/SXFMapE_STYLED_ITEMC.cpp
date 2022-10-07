/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_STYLED_ITEMC.cpp						作成日：2000.04.17

	１．クラス概要
		STYLED_ITEMを管理する

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#include "stdafx.h"
#include "SXFMapE_STYLED_ITEMC.h"
#include "SXFMapEntAConvC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_STYLED_ITEMC.cpp						作成日：2000.04.17

	１．機能概要
		デフォルトコンストラクタ

	２．インターフェイス
		void	SXFMapE_STYLED_ITEMC::SXFMapE_STYLED_ITEMC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_STYLED_ITEMC::SXFMapE_STYLED_ITEMC()
{
//	<エンティティデータ>
//#101 = STYLED_ITEM((#508), #505);
//	<図形見え方,インスタンス部へのＩＤ>
	m_AppeID =  m_InstID = 0;
//	<図形見え方インスタンス部へのポインタ>
//	m_AppeP = m_InstP = NULL;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_STYLED_ITEMC.cpp						作成日：2000.04.17

	１．機能概要
		エンティティデータを指定して生成する場合
		(コンストラクタ)

	２．インターフェイス
		void	SXFMapE_STYLED_ITEMC::SXFMapE_STYLED_ITEMC(
						SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	引数  ：	型				引数名				内容
				SXFInstanceIDC* IN_InstanceIDManeger	ｲﾝｽﾀﾝｽID管理ｵﾌﾞｼﾞｪｸﾄ

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_STYLED_ITEMC::SXFMapE_STYLED_ITEMC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
{
//	<エンティティデータ>
//#101 = STYLED_ITEM((#508), #505);
//	<図形見え方,インスタンス部へのＩＤ>
	m_AppeID =  m_InstID = 0;
//	<図形見え方インスタンス部へのポインタ>
//	m_AppeP = m_InstP = NULL;
}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_STYLED_ITEMC.cpp						作成日：2000.04.17

	１．機能概要
		(デストラクタ)

	２．インターフェイス
		void	SXFMapE_STYLED_ITEMC::~SXFMapE_STYLED_ITEMC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_STYLED_ITEMC::~SXFMapE_STYLED_ITEMC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_STYLED_ITEMC.cpp						作成日：2000.04.17

	１．機能概要
		エンティティデータの登録

	２．インターフェイス
		int		SXFMapE_STYLED_ITEMC::SetParameter()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
int SXFMapE_STYLED_ITEMC::SetParameter()

{

//	<エンティティデータ>
//#101 = STYLED_ITEM( '' , (#508), #505);
//	<図形見え方,インスタンス部へのＩＤ>
	m_AppeID =  m_InstID = 0;
	int num;
	CArray<int,int> OUT_array;

	SXFMapEntAConvC convent(m_EntityArray);

//	styled_item 単独の時はnameパラメタが必要 /////////////////////
 //	1. nameパラメタ>
	convent.GetCString(0,m_name);

//	<見え方へのＩＤ>
	convent.GetSetInst(1,num, OUT_array);
	m_AppeID = OUT_array[0];

//	<インスタンス部へのＩＤ>
	convent.GetInst(2,m_InstID);

//////////////////////////////////////////////////////////////////
//	<見え方へのＩＤ>
//	convent.GetSetInst(0,num, OUT_array);
//	m_AppeID = OUT_array[0];
//	<インスタンス部へのＩＤ>
//	convent.GetInst(1,m_InstID);

	return 0;
}
