/**
	All Rights Reserved,(c)JACIC 2001
	SXFReadAP202MapManagerC.cpp						作成日：2001.06.12

	１．クラス概要
		SXFReadAP202MapManagerC クラスのインプリメンテーション

	２．履歴
		履歴番号	日付		担当者		概要
		作成		2001.06.12	佐々木(FQS)(FQS)	なし。
**/

#include "stdafx.h"
#include "SXFReadAP202ManagerC.h"
#include "SXFReadAP202MapManagerC.h"
#include "SXFMapGeometryC.h"
#include "SXFInstanceIDC.h"
#include "SXFTableManagerC.h"
#include "SXFComInfoC.h"
#include "SXFMapAssemblyC.h"
//	DEL(S)	チューニング対応	K.Naono	03.07.03
//#include "SXFFeatureC.h"
//	DEL(E)	チューニング対応	K.Naono	03.07.03

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFReadAP202MapManagerC.cpp                   作成日：2001.03.21

  １．機能概要
      コンストラクタ
      
  ２．インターフェース
      void SXFReadAP202MapManagerC::SXFReadAP202MapManagerC()

	    引数: 型		引数名		内容
			  なし

  ３．履歴
	    履歴番号    日付け         担当者    概要
      作成		2001.03.21     佐々木(FQS)

**/
SXFReadAP202MapManagerC::SXFReadAP202MapManagerC()
{
	m_InstanceIDManager = NULL;
	m_TableManager = NULL;
	m_ComInfo = NULL;
	m_MapAssembly = NULL;
	m_MapGeometry = NULL;
	m_ReadManager = NULL;
//	DEL(S)	チューニング対応	K.Naono	03.07.03
//	m_Feature = NULL;
//	DEL(E)	チューニング対応	K.Naono	03.07.03
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFReadAP202MapManagerC.cpp                   作成日：2001.03.21

  １．機能概要
      コンストラクタ
      
  ２．インターフェース
      void SXFReadAP202MapManagerC(SXFInstanceIDC* IN_InstanceIDManager,
                                   SXFTableManagerC* IN_TableManager,
                                   SXFComInfoC* IN_ComInfo,
                                   SXFReadAP202ManagerC* IN_ReadManager)

	    引数: 型					引数名					内容
			  SXFInstanceIDC* 		IN_InstanceIDManager	ｲﾝｽﾀﾝｽID管理ｵﾌﾞｼﾞｪｸﾄ
			  SXFTableManagerC* 	IN_TableManager			定義ﾃｰﾌﾞﾙ管理ｵﾌﾞｼﾞｪｸﾄ
			  SXFComInfoC* 			IN_ComInfo				共通情報管理ｵﾌﾞｼﾞｪｸﾄ
			  SXFReadAP202ManagerC* IN_ReadManager			Read管理ｵﾌﾞｼﾞｪｸﾄ

  ３．履歴
	    履歴番号    日付け         担当者    概要
      作成		2001.03.21     佐々木(FQS)

**/
SXFReadAP202MapManagerC::SXFReadAP202MapManagerC(SXFInstanceIDC* IN_InstanceIDManager,
												SXFTableManagerC* IN_TableManager,
												SXFComInfoC* IN_ComInfo,
												SXFReadAP202ManagerC* IN_ReadManager)
{
	m_InstanceIDManager = IN_InstanceIDManager;
	m_TableManager = IN_TableManager;
	m_ComInfo = IN_ComInfo;
	m_MapAssembly = NULL;
	m_MapGeometry = NULL;
	m_ReadManager = IN_ReadManager;
//	DEL(S)	チューニング対応	K.Naono	03.07.03
//	m_Feature = NULL;
//	DEL(E)	チューニング対応	K.Naono	03.07.03
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFReadAP202MapManagerC.cpp                   作成日：2001.03.21

  １．機能概要
      デストラクタ
      
  ２．インターフェース
      SXFReadAP202MapManagerC::~SXFReadAP202MapManagerC()

	    引数: 型		引数名		内容
			  なし

	    復帰値	
			  なし

  ３．履歴
	    履歴番号    日付け         担当者    概要
      作成		2001.03.21     佐々木(FQS)

**/
SXFReadAP202MapManagerC::~SXFReadAP202MapManagerC()
{
	if (m_MapAssembly != NULL)
		delete m_MapAssembly;
	if (m_MapGeometry != NULL)
		delete m_MapGeometry;
//	DEL(S)	チューニング対応	K.Naono	03.07.03
//	if (m_Feature != NULL)
//		delete m_Feature;
//	DEL(E)	チューニング対応	K.Naono	03.07.03
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFReadAP202MapManagerC.cpp                   作成日：2001.03.21

  １．機能概要
      Assembly InstanceIDのセット
      
  ２．インターフェース
      BOOL SetAssemblyInstanceID(int IN_ChildID)

	    引数: 型		引数名		内容
			  int		IN_ChildID	Child ID

  ３．履歴
	    履歴番号    日付け         担当者    概要
      作成		2001.03.21     佐々木(FQS)

**/
BOOL SXFReadAP202MapManagerC::SetAssemblyInstanceID(int IN_ChildID)
{
	m_MapAssembly = new SXFMapAssemblyC(m_InstanceIDManager,m_TableManager,m_ComInfo);
	if (m_MapAssembly->SetRootID(IN_ChildID) < 0)
		return FALSE;

	return TRUE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFReadAP202MapManagerC.cpp                   作成日：2001.03.21

  １．機能概要
   Instance IDのセット   
      
  ２．インターフェース
      BOOL SetInstanceID(int IN_ChildID)

	    引数: 型		引数名		内容
			  int		IN_ChildID		Child ID

  ３．履歴
	    履歴番号    日付け         担当者    概要
      作成		2001.03.21     佐々木(FQS)

**/
BOOL SXFReadAP202MapManagerC::SetInstanceID(int IN_ChildID)
{   
	m_MapGeometry = new SXFMapGeometryC(m_InstanceIDManager,m_TableManager,m_ComInfo,m_ReadManager);
	if (m_MapGeometry->SetRootID(IN_ChildID) < 0)
		return FALSE;

	return TRUE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFReadAP202MapManagerC.cpp								作成日：2001.06.25

	１．機能概要
	一般要素フィーチャの構造体取得

	２．インターフェース
	LPVOID GetStructData(char *OUT_TypeName,size_t TypeNameSize)

	引数:	型			引数名				内容
			char*		OUT_TypeName		フィーチャ型
			size_t		TypeNameSize		バッファサイズ

	復帰値	構造体

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.25			佐々木(FQS)(FQS)	なし。
	更新			2015.04.27			T.Matsushima		JPCERT/CC 指摘 脆弱性対応
**/
//LPVOID SXFReadAP202MapManagerC::GetStructData(char *OUT_TypeName)
LPVOID SXFReadAP202MapManagerC::GetStructData(char *OUT_TypeName,size_t TypeNameSize)
{
	int FeatureType=0;
	LPVOID FeatureClass = NULL;
	LPVOID OUT_Struct = NULL;
	m_MapGeometry->SetFeatureParameter(FeatureType,FeatureClass);
//	MOD(S)	Ver3.0対応	K.Naono	04.01.30
//	if (FeatureClass == NULL){
	if( FeatureType == 0 && FeatureClass == NULL ) {
//	MOD(E)	Ver3.0対応	K.Naono	04.01.30
		//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
		//strcpy(OUT_TypeName,"");
		strcpy_s(OUT_TypeName,TypeNameSize,"");
		return OUT_Struct;
	}
	m_MapGeometry->SetStructData(FeatureType,FeatureClass);
	//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
	//m_MapGeometry->GetStructData(OUT_TypeName,OUT_Struct);
	m_MapGeometry->GetStructData(OUT_TypeName,TypeNameSize,OUT_Struct);
	return OUT_Struct;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFFeatureC.cpp                        作成日：2001.06.17
//
//  １．機能概要
//      Assembly構造体アドレスの取得(READ)
//      
//  ２．インターフェース
//      LPVOID GetAssemblyStructData()
//
//	    引数: 型			  引数名			    内容
//			  なし
//
//	    復帰値	
//            正常時：Assembly構造体のアドレス
//			  異常時：NULL
//
//  ３．履歴
//	    履歴番号    日付け         担当者    概要
//      作成		2001.06.17     佐々木(FQS)
//
//------------------------------------------------------------
LPVOID SXFReadAP202MapManagerC::GetAssemblyStructData()
{
	int AssemblyType=0;
	LPVOID AssemblyClass = NULL;
	LPVOID OUT_Struct = NULL;
	m_MapAssembly->SetFeatureParameter(AssemblyType,AssemblyClass);
	if (AssemblyClass == NULL){
		return OUT_Struct;
	}
	m_MapAssembly->SetStructData(AssemblyType,AssemblyClass);
	m_MapAssembly->GetStructData(OUT_Struct);
	return OUT_Struct;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFReadMapManagerC.cpp                   作成日：2001.03.21

  １．機能概要
      フィーチャ構造体返却済みフラグをONにする(READ)
      
  ２．インターフェース
      void SetReturnFlag()

	    引数: 型		引数名		内容
			  なし

	    復帰値	
			  なし

  ３．履歴
	    履歴番号    日付け         担当者    概要
      作成		2001.03.21     佐々木(FQS)

**/
void SXFReadAP202MapManagerC::SetReturnFlag()
{
}
