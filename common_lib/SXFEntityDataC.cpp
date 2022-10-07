//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFEntityDataC.cpp	                  作成日：2001.06.07
//
//	１．クラス概要
//      エンティティデータを保持するオブジェクト     
//      
//	２．履歴
//	    履歴番号    日付け         担当者    概要
//      作成		2001.06.07     佐々木(FQS)
//
//------------------------------------------------------------
#include "stdafx.h"
#include "SXFDataStructC.h"
//#include "SXFSplitAP202C.h"
#include "SXFComncApi.h"
#include "SXFEntityDataC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//  SXFEntityDataC.cpp	                  作成日：2001.06.07
//
//  １．機能概要
//      クラス構築
//
//  ２．インターフェース
//		SXFEntityDataC::SXFEntityDataC()
//
//	    引数: 型			  引数名			    内容
//					なし   
//
//  ３．履歴
//	    履歴番号    日付け         担当者    概要
//      作成		2001.06.07     佐々木(FQS)
//
//------------------------------------------------------------
SXFEntityDataC::SXFEntityDataC()
{

	//初期化
	m_InstanceMode = -1;
	m_InstanceID = -1;
	m_EntityName.Empty();
	m_EntityDataPtr = NULL;

}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFEntityDataC.cpp	                  作成日：2001.06.07
//
//  １．機能概要
//      クラス消滅
//
//  ２．インターフェース
//		SXFEntityDataC::~SXFEntityDataC()
//
//	    引数: 型			  引数名			    内容
//					なし   
//
//  ３．履歴
//	    履歴番号    日付け         担当者    概要
//      作成		2001.06.07     佐々木(FQS)
//
//------------------------------------------------------------
SXFEntityDataC::~SXFEntityDataC()
{
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFEntityDataC.cpp	                  作成日：2001.06.07
//
//  １．機能概要
//      Entity Data の設定
//      
//  ２．インターフェース
//      BOOL SetEntityData(LPVOID& IO_DataInFilePtr,
//                         INSTANCEDATA *IN_Instance)
//	    引数: 型				引数名				内容
//				LPVOID&			IO_DataInFilePtr	MappingFileの
//													当面のアドレス
//				size_t			AvailableSize		IO_DataInFilePtr が使える残りサイズ
//				INSTANCEDATA*	IN_Instance			Instance Data
//													構造体のアドレス
//		復帰値
//			  size_t	今回使用したサイズ
//
//  ３．履歴
//	    履歴番号    日付け			担当者			概要
//      作成		2001.06.07		佐々木(FQS)
//		更新		2015.04.27		T.Matsushima	JPCERT/CC 指摘 脆弱性対応
//
//------------------------------------------------------------
//BOOL SXFEntityDataC::SetEntityData(LPVOID& IO_DataInFilePtr,INSTANCEDATA *IN_Instance)
size_t SXFEntityDataC::SetEntityData(LPVOID& IO_DataInFilePtr,size_t AvailableSize,INSTANCEDATA *IN_Instance)
{

	m_EntityName = IN_Instance->EntityName;
	m_InstanceID = IN_Instance->InstanceID;
	m_InstanceMode = IN_Instance->InstanceMode;
	m_EntityDataPtr = ( LPTSTR )IO_DataInFilePtr;
//	MOD(S)	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
	//strcpy(m_EntityDataPtr,IN_Instance->EntityData);
	//IO_DataInFilePtr = ( LPTSTR )IO_DataInFilePtr + 
	//							strlen(m_EntityDataPtr) + 1;
	//return TRUE;

	strcpy_s(m_EntityDataPtr,AvailableSize,IN_Instance->EntityData);
	size_t len = strlen(m_EntityDataPtr) + 1;
	IO_DataInFilePtr = ( LPTSTR )IO_DataInFilePtr + len;

	return len;	// 戻り値は今回使用したサイズを返す
//	MOD(E)	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFEntityDataC.cpp	                  作成日：2001.06.07
//
//  １．機能概要
//      InstanceのEntity Data部の取得
//      
//  ２．インターフェース
//      BOOL GetEntityData(CString& OUT_EntityData)
//	    引数: 型			  引数名			    内容
//            CString&        OUT_EntityData       Instanceの
//                                                 Entity Data部 
//      
//	    復帰値	
//            正常時：TRUE
//			  異常時：FALSE
//
//  ３．履歴
//	    履歴番号    日付け         担当者    概要
//      作成		2001.06.07     佐々木(FQS)
//
//------------------------------------------------------------

BOOL SXFEntityDataC::GetEntityData(CString& OUT_EntityData)
{
	//データがNullの場合
	if(m_EntityDataPtr == NULL)
		return FALSE; 

	OUT_EntityData = m_EntityDataPtr;

	return TRUE;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFEntityDataC.cpp	                  作成日：2001.06.07
//
//  １．機能概要
//      InstanceのEntity Data部の取得（分割したStringArray）
//      
//  ２．インターフェース
//      BOOL GetEntityDataArray(CStringArray& OUT_EntityDataArray)
//	    引数: 型			  引数名			    内容
//            CStringArray&   OUT_EntityDataArray  分割したの
//                                                 Entity Data部 
//      
//	    復帰値	
//            正常時：TRUE
//			  異常時：FALSE
//
//  ３．履歴
//	    履歴番号    日付け         担当者    概要
//      作成		2001.06.07     佐々木(FQS)
//
//------------------------------------------------------------
BOOL SXFEntityDataC::GetEntityDataArray(CStringArray& OUT_EntityDataArray)
{
	CString entitydata;

	int mode = 0;

	//データがNULL
	if( ! GetEntityData(entitydata) )
		return FALSE; 

//	MOD(S)	チューニング対応	K.Naono	03.07.03
/*
	//complex AP202 instance
	if(m_EntityName == "SXF_COMPLEX_INSTANCE"){
		mode = 1;
	//common instance
	}else{
		mode = 2;
	}

	CStringArray* array;

	SXFSplitAP202C splitap202(mode,entitydata);
    
	array = splitap202.Split();

	if(array==NULL)
		return FALSE;

	OUT_EntityDataArray.Copy( *array );
*/
	int				nCount = 0 ;
	CStringArray	array ;

	//	複合エンティティの場合
	if(m_EntityName == DEF_SXF_COMPLEX_INSTANCE){
		nCount = GFn_SplitCEntityAttr(entitydata, array) ;

	//	単純エンティティの場合
	} else {
		nCount = GFn_SplitSEntityAttr(entitydata, array) ;
	}

	if( nCount )
		OUT_EntityDataArray.Copy(array) ;
//	MOD(E)	チューニング対応	K.Naono	03.07.03

	return TRUE;
}
