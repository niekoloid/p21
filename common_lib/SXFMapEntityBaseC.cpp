/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapEntityBaseC.cpp						作成日：2000.04.17

	１．クラス概要
		Entityデータを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#include "stdafx.h"
#include "SXFMapEntityBaseC.h"
//#include "ComSplitStringC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntityBaseC.cpp						作成日：2000.04.17

	１．機能概要
		デフォルトコンストラクタ

	２．インターフェイス
		void	SXFMapEntityBaseC::SXFMapEntityBaseC()

	引数  ：	型			引数名				内容
			なし
	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapEntityBaseC::SXFMapEntityBaseC()
{
//
//	<初期化>
//
//	<エンティティ名>
	m_EntityName.Empty();
//
//	<エンティティデータ>
	m_EntityData.Empty();
//
//	<分割したエンティティデータ>
	m_EntityArray = &m_MyArray;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntityBaseC.cpp						作成日：2000.04.17

	１．機能概要
		エンティティデータを指定して生成する場合
		(コンストラクタ)

	２．インターフェイス
		void	SXFMapEntityBaseC::SXFMapEntityBaseC(
						SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapBaseC(IN_InstanceIDManeger)
					

	引数  ：	型				引数名				内容
				SXFInstanceIDC* IN_InstanceIDManeger	ｲﾝｽﾀﾝｽID管理ｵﾌﾞｼﾞｪｸﾄ

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
//	<インスタンスＩＤへのポインタを登録し生成する>
SXFMapEntityBaseC::SXFMapEntityBaseC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapBaseC(IN_InstanceIDManeger)
{
//	<エンティティ名>
	m_EntityName.Empty();
//	<エンティティデータ>
	m_EntityData.Empty();
//	<分割したエンティティデータ>
	m_EntityArray = &m_MyArray;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntityBaseC.cpp						作成日：2000.04.17

	１．機能概要
		(デストラクタ)

	２．インターフェイス
		void	SXFMapEntityBaseC::~SXFMapEntityBaseC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapEntityBaseC::~SXFMapEntityBaseC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntityBaseC.cpp						作成日：2000.04.17

	１．機能概要
		エンティティデータの登録

	２．インターフェイス
		int		SXFMapEntityBaseC::SetEntitydata(
			int		IN_RootID,		//	<ルートＩＤ>
			CString IN_EntityName,	//	<エンティティ名>
			CString IN_EntityData)	//	<エンティティデータ>

	引数  ：	型			引数名				内容
				int			IN_RootID			ルートＩＤ
				CString 	IN_EntityName		エンティティ名
				CString 	IN_EntityData		エンティティデータ

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
int SXFMapEntityBaseC::SetEntitydata(
		int		IN_RootID,		//	<ルートＩＤ>
		CString IN_EntityName,	//	<エンティティ名>
		CString IN_EntityData	//	<エンティティデータ>
		)
{
//	//エンティティ名のチェック
//	if (Checkm_EntityName(IN_EntityName)==FALSE) {
//		// エンティティ名が異なる
//		return -10000;
//	}
	m_RootID	= IN_RootID;
	m_EntityName = IN_EntityName;
	m_EntityData = IN_EntityData;

	return 0;
}

int SXFMapEntityBaseC::SetEntityArraydata(
		int		IN_RootID,		//	<ルートＩＤ>
		CString IN_EntityName,		//	<エンティティ名>
		CStringArray* IN_EntityArray	//	<分割したエンティティデータ>
		)
{
	m_RootID	= IN_RootID;
	m_EntityName = IN_EntityName;
	m_MyArray.Copy(*IN_EntityArray);

	return 0;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntityBaseC.cpp						作成日：2000.04.17

	１．機能概要
		エンティティデータの取得

	２．インターフェイス
	CStringArray*	SXFMapEntityBaseC::GetEntityArraydata(
		int& OUT_Num,		//配列の大きさ

	引数  ：	型			引数名				内容
				int& 		OUT_Num

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/

//エンティティ名とエンティティデータ(Split)の取得
CStringArray*	SXFMapEntityBaseC::GetEntityArraydata(
		int& OUT_Num		//配列の大きさ
		 )

{
	OUT_Num = (int)m_EntityArray->GetSize();
	return m_EntityArray;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntityBaseC.cpp						作成日：2000.04.17

	１．機能概要
		インスタンスIDからエンティティ名とエンティティデータを登録する
		

	２．インターフェイス
	int	SXFMapEntityBaseC::SetRootID(int	IN_RootID);

	引数  ：	型			引数名				内容
				int			IN_RootID

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
int		SXFMapEntityBaseC::SetRootID(int	IN_RootID)
{
	if ( IN_RootID == 0 ){
		//エンティティインスタンスが存在しません。
			SXFErrorMsgC::RecordError(
				SXFNOENTITY,			//errメッセージ番号
				m_EntityName,		//エンティティ名
				2,					//パラメタの個数
				m_RootID,			//パラメタ
				m_EntityName
				);
		return SXFNOENTITY;	//-55005

	}
//	<エンティティデータの設定>
//
	m_RootID		= IN_RootID;

//	<エンティティ名,エンティティデータの設定>
	if ( SetEntity() < 0 ) {
		// err インスタンスＩＤに対応したエンティティデータが存在しない
		// エンティティインスタンスが存在しません
			SXFErrorMsgC::RecordError(
				SXFNOENTITY,			//errメッセージ番号
				m_EntityName,		//エンティティ名
				2,					//パラメタの個数
				m_RootID,			//パラメタ
				m_EntityName
				);
		return SXFNOENTITY;	//-55005 
	}

	return 0;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntityBaseC.cpp						作成日：2000.04.17

	１．機能概要
		エンティティ名とエンティティデータを取得し登録する

	２．インターフェイス
	int	SXFMapEntityBaseC::SetEntity()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
int		SXFMapEntityBaseC::SetEntity()

{
	if ( m_RootID == 0 ){
		//err
		return -10000;
	}
	
//	<エンティティ名>
	m_EntityName = SXFMapInstIDC::GetEntityName(m_RootID);
	if ( m_EntityName.IsEmpty()) {
		//err インスタンスＩＤに対応したエンティティデータが存在しない
		return -12000;
	}
//	<エンティティデータ>
	m_EntityData = SXFMapInstIDC::GetEntityData(m_RootID);
//	<分割したエンティティデータ>
	SXFMapInstIDC::GetMyArray(m_RootID,m_MyArray);

	return 0;
}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntityBaseC.cpp						作成日：2000.04.17

	１．機能概要
		//取得したエンティティ名とm_EntityNameのチェック

	２．インターフェイス
BOOL	SXFMapEntityBaseC::Checkm_EntityName(CString IN_EntityName)

	引数  ：	型			引数名				内容
		CString IN_EntityName	エンティティ名

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/

//エンティティ名のチェック
BOOL	SXFMapEntityBaseC::Checkm_EntityName(
				CString IN_EntityName	//エンティティ名
				)
{
	if ( m_EntityName.IsEmpty() ) return TRUE;

	if ( m_EntityName != IN_EntityName){
		//エンティティ名の誤り
		return FALSE;
	}
	return TRUE;
}
