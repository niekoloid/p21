/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapInstIDC.cpp						作成日：2000.04.21

	１．クラス概要
		InstanceIDクラスへのアクセスを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.21	

**/
#include "stdafx.h"
#include <afx.h>
#include "SXFDataStructC.h"
#include "SXFEntityDataC.h"
#include "SXFInstanceIDC.h"
#include "SXFPart21FileC.h"
#include "SXFPart21FileReadC.h"
#include "SXFMapInstIDC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapInstIDC.cpp						作成日：2000.04.21

	１．機能概要
		(デフォルトコンストラクタ)

	２．インターフェイス
		void	SXFMapInstIDC::SXFMapInstIDC()
			

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.21	
**/
SXFMapInstIDC::SXFMapInstIDC()
{
//	<初期化>
	m_InstanceIDManager = NULL ;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapInstIDC.cpp						作成日：2000.04.21

	１．機能概要
		インスタンスＩＤへのポインタを登録し生成する
		(コンストラクタ)

	２．インターフェイス
		void	SXFMapInstIDC::SXFMapInstIDC(
				SXFInstanceIDC*	IN_InstanceIDManeger)
			

	引数 ：	型				引数名				内容
			SXFInstanceIDC*	IN_InstanceIDManeger	ｲﾝｽﾀﾝｽID管理ｵﾌﾞｼﾞｪｸﾄ

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.21	
**/
SXFMapInstIDC::SXFMapInstIDC(
			SXFInstanceIDC*	IN_InstanceIDManeger) 
{
//	<初期化>

	m_InstanceIDManager = IN_InstanceIDManeger ;
}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapInstIDC.cpp						作成日：2000.04.21

	１．機能概要
		(デストラクタ)

	２．インターフェイス
		void	SXFMapInstIDC::~SXFMapInstIDC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.21	
**/
SXFMapInstIDC::~SXFMapInstIDC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapInstIDC.cpp						作成日：2000.04.21

	１．機能概要
		インスタンスＩＤを指定し、エンティティ名を取得する

	２．インターフェイス
		CString		SXFMapInstIDC::GetEntityName(
					int		IN_InstID)
					

	引数  ：	型			引数名				内容
				int			IN_InstID		 Instance ID

	復帰値：定義テーブル種別

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.21	
**/
CString	SXFMapInstIDC::	GetEntityName(
			int	IN_InstID)		
{
	CString entityname;
	entityname.Empty();
	//インスタンスIDに対応したエンティティデータを取得
	SXFEntityDataC* entityptr;
	entityptr = m_InstanceIDManager->GetEntityDataPtr(  IN_InstID  );
	if ( entityptr != NULL ){
		//エンティティ名の取得    
		entityname = entityptr->m_EntityName;		
	}
	else{
		//インスタンＩＤに対応したエンティティデータが存在しない
	}

	return entityname;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapInstIDC.cpp						作成日：2000.04.21

	１．機能概要
		インスタンスＩＤを指定し、エンティティデータを取得する

	２．インターフェイス
		CString		SXFMapInstIDC::GetEntityData(
					int		IN_InstID)
					

	引数  ：	型			引数名				内容
				int			IN_InstID		 Instance ID

	復帰値：定義テーブル種別

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.21	
**/
CString	SXFMapInstIDC::	GetEntityData(
			int	IN_InstID)	
{
	//インスタンスIDに対応したエンティティデータを取得
	SXFEntityDataC* entityptr;
	entityptr = m_InstanceIDManager->GetEntityDataPtr(  IN_InstID  );

	//エンティティデータの取得
	CString entitydata;
	entityptr->GetEntityData(entitydata);

	return entitydata;
}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapInstIDC.cpp						作成日：2000.04.21

	１．機能概要
		インスタンスＩＤを指定し、エンティティデータ(Split)を取得する

	２．インターフェイス
		CString		SXFMapInstIDC::GetEntityDataArray(
					int		IN_InstID,
					CStringArray	&OUT_EntityDataArray)
					

	引数  ：	型				引数名					内容
				int				IN_InstID				Instance ID
				CStringArray	&OUT_EntityDataArray

	復帰値：定義テーブル種別

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.21	
**/
BOOL	SXFMapInstIDC::	GetMyArray(
			int				IN_InstID,
			CStringArray	&OUT_EntityDataArray)		
{
	//インスタンスIDに対応したエンティティデータを取得
	SXFEntityDataC* entityptr;
	entityptr = m_InstanceIDManager->GetEntityDataPtr(  IN_InstID  );

	//エンティティデータの取得
	entityptr->GetEntityDataArray(OUT_EntityDataArray);

	return TRUE;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapInstIDC.cpp						作成日：2000.04.21

	１．機能概要
		エンティティ名を指定し、そのエンティティ名をインスタンスに
		もつＩＤ群を取得する

	２．インターフェイス
		CString		SXFMapInstIDC::GetIDArray(
					CString IN_InstanceName) 


	引数  ：	型			引数名				内容
			CString		IN_InstanceName		 エンティティ名

	復帰値：定義テーブル種別

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.21	
**/
//	<エンティティ名を指定し、そのエンティティ名をインスタンスにもつＩＤ群を取得する>
//CArray<int,int>*  SXFMapInstIDC::GetIDArray(CString IN_InstanceName) 
CList<int,int>*  SXFMapInstIDC::GetIDArray(CString IN_InstanceName) 

{
//	CArray<int,int>* IDarray;
	if (m_InstanceIDManager->GetIDArray(IN_InstanceName)==NULL){
		return NULL;
	}
	else{
		return m_InstanceIDManager->GetIDArray(IN_InstanceName);
	}

//	return IDarray;
}
