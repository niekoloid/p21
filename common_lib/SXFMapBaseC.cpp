/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapBaseC.cpp						作成日：2000.04.17

	１．クラス概要
		ルートエンティティIDを管理する

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/

#include "stdafx.h"
#include "SXFMapBaseC.h"
#include "SXFComInfoC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapBaseC.cpp						作成日：2000.04.17

	１．機能概要
		コンストラクタ

	２．インターフェイス
		void	SXFMapBaseC::SXFMapBaseC()

	引数  ：	型			引数名				内容
			なし
	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapBaseC::SXFMapBaseC()
{
//
//	<初期化>
//
	m_RootID	= 0; 
	m_Eps_lenth = 0.;
	m_Eps_angle = 0.;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapBaseC.cpp						作成日：2000.04.17

	１．機能概要
		
		コンストラクタ

	２．インターフェイス
		void	SXFMapBaseC::SXFMapBaseC(
					SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapInstIDC(IN_InstanceIDManeger)
					

	引数：	型				引数名					内容
			SXFInstanceIDC* IN_InstanceIDManeger	ｲﾝｽﾀﾝｽID管理ｵﾌﾞｼﾞｪｸﾄ

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/

//	<インスタンスＩＤへのポインタを登録し生成する>
SXFMapBaseC::SXFMapBaseC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapInstIDC(IN_InstanceIDManeger)
{
	m_RootID	= 0;
	m_Eps_lenth = 0.;
	m_Eps_angle = 0.;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapBaseC.cpp						作成日：2000.04.17

	１．機能概要
		
		コンストラクタ

	２．インターフェイス
		void	SXFMapBaseC::SXFMapBaseC(
					SXFInstanceIDC* IN_InstanceIDManeger,
					SXFComInfoC* IN_ComInfoC )
		:SXFMapInstIDC(IN_InstanceIDManeger)
					

	引数：	型				引数名					内容
			SXFInstanceIDC* IN_InstanceIDManeger	ｲﾝｽﾀﾝｽID管理ｵﾌﾞｼﾞｪｸﾄ
			SXFComInfoC* 	IN_ComInfoC				共通情報管理ｵﾌﾞｼﾞｪｸﾄ

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
//	<インスタンスＩＤと共通情報管理へのポインタを登録し生成する>
SXFMapBaseC::SXFMapBaseC(
		SXFInstanceIDC* IN_InstanceIDManeger,
		SXFComInfoC* IN_ComInfoC )
		:SXFMapInstIDC(IN_InstanceIDManeger)
{
	m_RootID	= 0;
	m_Eps_lenth = 0.;
	m_Eps_angle = 0.;
	m_ComInfoC = IN_ComInfoC;
	m_ComInfoC->Get_Tolerance(m_Eps_lenth, m_Eps_angle) ;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapBaseC.cpp						作成日：2000.04.17

	１．機能概要
		コンストラクタ

	２．インターフェイス
		void	SXFMapBaseC::SXFMapBaseC(int  IN_RootID )
					

	引数：	型				引数名					内容
			int  			IN_RootID				ルートID

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
//	<ルートＩＤを指定して生成する場合>
SXFMapBaseC::SXFMapBaseC(
			int	IN_RootID )
{
//	<初期化>
    m_RootID	= IN_RootID;
	m_Eps_lenth = 0.;
	m_Eps_angle = 0.;
}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapBaseC.cpp						作成日：2000.04.17

	１．機能概要
		デストラクタ

	２．インターフェイス
		void	SXFMapBaseC::~SXFMapBaseC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapBaseC::~SXFMapBaseC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapBaseC.cpp						作成日：2000.04.17

	１．機能概要
		ルートIDの設定

	２．インターフェイス
		int		SXFMapBaseC::SetRootID(int IN_RootID)

	引数  ：	型			引数名				内容
				int 		IN_RootID			ルートID

	復帰値：ルートＩＤ

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
int SXFMapBaseC::SetRootID(int IN_RootID)
{
	m_RootID = IN_RootID;
	return (0) ;
}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapBaseC.cpp						作成日：2000.04.17

	１．機能概要
		ルートIDの取得

	２．インターフェイス
		int		SXFMapBaseC::GetRootID()

	引数  ：	型			引数名				内容
			なし

	復帰値：ルートＩＤ

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/

int SXFMapBaseC::GetRootID()
{
	return (m_RootID) ;
}
