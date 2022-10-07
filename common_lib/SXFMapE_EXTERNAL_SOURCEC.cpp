/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_EXTERNAL_SOURCEC.cpp						作成日：2000.04.17

	１．クラス概要
		EXTERNAL_SOURCEを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#include "stdafx.h"
#include "SXFMapEntAConvC.h"
#include "SXFMapEntityBaseC.h"
#include "SXFInstanceIDC.h"
#include "SXFMapE_EXTERNAL_SOURCEC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_EXTERNAL_SOURCEC.cpp						作成日：2000.04.17

	１．機能概要
		デフォルトコンストラクタ

	２．インターフェイス
		void	SXFMapE_EXTERNAL_SOURCEC::SXFMapE_EXTERNAL_SOURCEC()

	引数  ：	型			引数名				内容
			なし
	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_EXTERNAL_SOURCEC::SXFMapE_EXTERNAL_SOURCEC()
{
	m_EntityName = DEF_EXTERNAL_SOURCE;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_EXTERNAL_SOURCEC.cpp						作成日：2000.04.17

	１．機能概要
		インスタンスＩＤへのポインタを指定して生成する場合
		(コンストラクタ)

	２．インターフェイス
		void	SXFMapE_EXTERNAL_SOURCEC::SXFMapE_EXTERNAL_SOURCEC(
						SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	引数 ：	型				引数名				内容
			SXFInstanceIDC* IN_InstanceIDManeger	ｲﾝｽﾀﾝｽID管理ｵﾌﾞｼﾞｪｸﾄ

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_EXTERNAL_SOURCEC::SXFMapE_EXTERNAL_SOURCEC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)

{
	m_EntityName = DEF_EXTERNAL_SOURCE;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_EXTERNAL_DEFINED_TEXT_FONTC.cpp						作成日：2000.04.17

	１．機能概要
		(デストラクタ)

	２．インターフェイス
		void	SXFMapE_EXTERNAL_SOURCEC::~SXFMapE_EXTERNAL_SOURCEC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_EXTERNAL_SOURCEC::~SXFMapE_EXTERNAL_SOURCEC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_EXTERNAL_SOURCEC.cpp						作成日：2000.04.17

	１．機能概要
		エンティティのパラメタ設定

	２．インターフェイス
		int		SXFMapE_EXTERNAL_SOURCEC::SetParameter()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
int SXFMapE_EXTERNAL_SOURCEC::SetParameter( )
{
//#261 = EXTERNAL_SOURCE(IDENTIFIER('\X2\30B430B730C330AF\X0\-15-3'));


	SXFMapEntAConvC convent(m_EntityArray);

	CString tempstring;
	//引数エラー
	if ( convent.GetSelectCString(0, "IDENTIFIER", tempstring )<0) {
		SXFErrorMsgC::RecordError( SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

  
/*	int left = tempstring.Find('\'');
	int right = tempstring.Find('\'',left);
	m_Name = tempstring.Mid(left+1,right-left-1);
	m_Name.TrimLeft();
	m_Name.TrimRight();*/

	m_Name = tempstring;

	//引数エラー
	if(m_Name.IsEmpty()){
		SXFErrorMsgC::RecordError( SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	return 0;
}
