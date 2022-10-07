//---------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFPart21FileReadC.cpp	              作成日：2001.05.26
//
//	１．クラス概要
//      ファイルの入力を管理する
//
//	２．履歴
//		履歴番号	日付け		 担当者	    概要
//		作成		2001.05.26   佐々木(FQS)
//		更新		2001.09.17	K.Naono		ヘッダ解析処理の改善対応
//
//---------------------------------------------------------
#include "stdafx.h"
#include "SXFDataStructC.h"
#include "SXFEntityDataC.h"
#include "SXFInstanceIDC.h"
//	MOD(S)	ヘッダ解析処理の改善対応	K.Naono		01.09.17
//#include "SXFPart21FileC.h"
#include "SXFPart21FileExC.h"
//	MOD(E)	ヘッダ解析処理の改善対応	K.Naono		01.09.17
#include "SXFPart21FileReadC.h"
#include "SXFTableManagerC.h"
#include "SXFReadAp202ManagerC.h"
#include "SXFErrorMsgC.h"
#include "SXFComInfoC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFPart21FileReadC.cpp	              作成日：2001.05.26
//
//	１．機能概要
//		(コンストラクタ)
//
//	２．インターフェイス
//		void	SXFPart21FileReadC::SXFPart21FileReadC()
//		
//	引数	：	型		引数名				内容
//		なし
//      
//	復帰値：なし
//
//	３．履歴
//		履歴番号	日付け		 担当者	    概要
//		作成		2001.05.26   佐々木(FQS)
//---------------------------------------------------------
SXFPart21FileReadC::SXFPart21FileReadC()
{
	//initialization
	m_HeadSection.Level=-1;
	m_HeadSection.Mode=-1;
	m_HeadSection.Author.Empty();
	m_HeadSection.FileName.Empty();
	m_HeadSection.Organization.Empty();
	m_HeadSection.Version.Empty();
	m_HeadSection.OriginatingSystem.Empty();
	ClearInstanceData();
	m_File = NULL;
	m_TableManager = NULL;
	m_ComInfo = NULL;
	m_ReadAP202Manager = NULL;
	m_FileSize=5000000;
}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFPart21FileReadC.cpp	              作成日：2001.05.26
//
//	１．機能概要
//		(コンストラクタ)
//
//	２．インターフェイス
//		void	SXFPart21FileReadC::SXFPart21FileReadC(
//								SXFTableManagerC* IN_TableManager,
//								SXFReadAP202ManagerC* IN_ReadAP202Manager,
//								SXFComInfoC* IN_ComInfo)
//
//	引数：型				引数名				内容
//		SXFTableManagerC*	IN_TableManager		定義ﾃｰﾌﾞﾙ管理ｵﾌﾞｼﾞｪｸﾄのｱﾄﾞﾚｽ
//		SXFReadAP202ManagerC* SXFReadAP202ManagerC	Read管理ｵﾌﾞｼﾞｪｸﾄのｱﾄﾞﾚｽ
//		SXFComInfoC*		IN_ComInfo			共通情報ｵﾌﾞｼﾞｪｸﾄのｱﾄﾞﾚｽ
//      
//	復帰値：なし
//
//	３．履歴
//		履歴番号	日付け		 担当者	    概要
//		作成		2001.05.26   佐々木(FQS)
//---------------------------------------------------------
SXFPart21FileReadC::SXFPart21FileReadC(SXFTableManagerC* IN_TableManager,
										SXFReadAP202ManagerC*  IN_ReadAP202Manager,
										SXFComInfoC* IN_ComInfo,SXFInstanceIDC* IN_InstanceIDManager)
{
	//initialization
	m_HeadSection.Level=-1;
	m_HeadSection.Mode=-1;
	m_HeadSection.Author.Empty();
	m_HeadSection.FileName.Empty();
	m_HeadSection.Organization.Empty();
	m_HeadSection.Version.Empty();
	m_HeadSection.OriginatingSystem.Empty();
	ClearInstanceData();
	m_File = NULL;
	m_TableManager = IN_TableManager; 
	m_ComInfo = IN_ComInfo;
	m_InstanceIDManager = IN_InstanceIDManager;
	m_ReadAP202Manager = IN_ReadAP202Manager;
	m_FileSize=5000000;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFPart21FileReadC.cpp	              作成日：2001.05.26
//
//  １．機能概要
//      クラス消滅
//
//  ２．インターフェース
//
//  ３．履歴
//		履歴番号	日付け		 担当者	    概要
//		作成		2001.05.26   佐々木(FQS)
//
//------------------------------------------------------------
SXFPart21FileReadC::~SXFPart21FileReadC()
{
	if(m_File != NULL)
		delete m_File;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFPart21FileReadC.cpp	              作成日：2001.05.26
//
//  １．機能概要
//      ファイルのオープン
//
//  ２．インターフェース
//      int OpenPart21ReadFile( LPCTSTR IN_FileName )
//	    引数: 型			  引数名			    内容
//            LPCTSTR         IN_FileName          FileName
//      
//	    復帰値	
//            正常時： 1: OK
//			  異常時： その他: error
//
//  ３．履歴
//		履歴番号	日付け		 担当者	    概要
//		作成		2001.05.26   佐々木(FQS)
//		更新		2001.09.17	K.Naono		ヘッダ解析処理の改善対応
//
//------------------------------------------------------------
int SXFPart21FileReadC::OpenPart21ReadFile( LPCTSTR IN_FileName )
{
	TRY {
//	MOD(S)	ヘッダ解析処理の改善対応	K.Naono		01.09.17
//		m_File = new SXFPart21FileC(IN_FileName,CFile::modeRead | CFile::shareExclusive);
		m_File = new SXFPart21FileExC(IN_FileName,
					CFile::modeRead | CFile::shareExclusive);
//	MOD(E)	ヘッダ解析処理の改善対応	K.Naono		01.09.17
	} CATCH( CFileException, e ) {
		if (e->m_cause == CFileException::fileNotFound ){
			/* 指定されたファイルまたはディレクトリが見つかりません */
			SXFErrorMsgC::RecordError(SXFFILEDIRECTORY,"",1,IN_FileName);
			return SXFFILEDIRECTORY;
		}
		else{
			/* ファイルのオープンに失敗しました */
			SXFErrorMsgC::RecordError(SXFNOTOPENSTEPFILE,"",1,IN_FileName);
			return SXFNOTOPENSTEPFILE;
		}
	}
	END_CATCH

	//ファイルサイズの取得
	m_FileSize = (int) m_File->GetLength();

	if( !m_InstanceIDManager->InitFileMapping(m_FileSize) )
		return -1;

	int result_readhead = m_File->ReadHeadSection(&m_HeadSection);
	if (result_readhead < 0 ){
		/*ヘッダが見つかりません*/
		SXFErrorMsgC::RecordError(SXFNOTHEADER,"",1,IN_FileName);
		return SXFNOTHEADER;
	}
	/* SCADEC以外のファイル */
	if (result_readhead == 0){
		m_HeadSection.Author="";
		m_HeadSection.FileName="";
		m_HeadSection.Level = 2;
		m_HeadSection.Mode = 2;
		m_HeadSection.Organization="";
		m_HeadSection.OriginatingSystem="";
		m_HeadSection.Version="";
		m_HeadSection.scadec_flg = -1;
	}

	//** ファイルの情報を登録 **/
	int ret = m_ComInfo->SetFileInfo(m_HeadSection);
	if (ret < 0)
		return ret;
	while(1){

		int result_readinstance = m_File->ReadInstance(&m_InstanceData);
		if ( result_readinstance !=1 ){
			if(result_readinstance == -2){
				continue; //next line 
			}
			if( result_readinstance == -3 ){
				return -1;
			}
			if(result_readinstance == -1){
				//if end of file then break while(1) and return TRUE                 
				break;//break wile(1)
			}
			break;
		}

		if ( result_readinstance == 1 ) {
			switch (m_InstanceData.InstanceMode){
			case SXF_IM_COMMENT:
			case SXF_IM_SECTIONMARK:
			case SXF_IM_HEADSECTION:
				break;//not a entity then break switch
			case SXF_IM_AP_ENTITY://AP202 entity data register
				RegisterAPEntity(&m_InstanceData);
				break;//break switch
			case SXF_IM_AP_TABLE://AP202 table data register
				RegisterAPTable(&m_InstanceData);
				break;//break switch
			case SXF_IM_AP_ASSEMBLY://AP202 assembly data register
				RegisterAPAssembly(&m_InstanceData);
				break;//break switch
			case SXF_IM_FT_ENTITY:
			case SXF_IM_FT_TABLE:
			case SXF_IM_FT_ASSEMBLY:
				break;//if feature instance then break switch 

//	ADD(S)	チューニング対応	K.Naono	03.07.04
			case SXF_IM_AP_INVISIBILITY :
				{
					m_InstanceIDManager->RegisterInstance(&m_InstanceData) ;
					m_TableManager->RegisterInvisibility(&m_InstanceData) ;
				}
				break ;
			case SXF_IM_AP_PRESENTATION_SIZE :
				{
					m_InstanceIDManager->RegisterInstance(&m_InstanceData) ;
					m_TableManager->RegisterPresentationSize(&m_InstanceData) ;
				}
				break ;
			case SXF_IM_AP_DRAUGHTING_TITLE :
				{
					m_InstanceIDManager->RegisterInstance(&m_InstanceData) ;
					m_TableManager->RegisterSheetTitle(&m_InstanceData) ;
				}
				break ;
//	ADD(E)	チューニング対応	K.Naono	03.07.04
//	ADD(S)	Ver3.0対応	K.Naono	04.01.30
			case SXF_IM_AP_ATTRIBUTE :
				{
					m_InstanceIDManager->RegisterInstance(&m_InstanceData) ;
					m_TableManager->RegisterAttribute(&m_InstanceData) ;
				}
				break ;
//	ADD(E)	Ver3.0対応	K.Naono	04.01.30

			default:
				break;//unknowable instance than break switch
			}
		}
		ClearInstanceData();//init instance data z
	}

	return 1;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFPart21FileReadC.cpp	              作成日：2001.05.26
//
//  １．機能概要
//      ファイルのクローズ
//
//  ２．インターフェース
//      BOOL ClosePart21ReadFile(  )
//	    引数: 型			  引数名			    内容
//      
//	    復帰値	
//            正常時： TRUE
//			  異常時： 
//
//  ３．履歴
//		履歴番号	日付け		 担当者	    概要
//		作成		2001.05.26   佐々木(FQS)
//
//------------------------------------------------------------

BOOL SXFPart21FileReadC::ClosePart21ReadFile(  )
{
	m_File->Close();
	return TRUE;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFPart21FileReadC.cpp	              作成日：2001.05.26
//
//  １．機能概要
//      AP202 Instance Entity の登録
//
//  ２．インターフェース
//      BOOL RegisterAPEntity(INSTANCEDATA *IN_Instance)
//	    引数: 型			  引数名			    内容
//            INSTANCEDATA*   IN_Instance          Instanceの
//                                                 構造体のアドレス 
//	    復帰値	
//            正常時： TRUE
//			  異常時： FALSE
//
//  ３．履歴
//		履歴番号	日付け		 担当者	    概要
//		作成		2001.05.26   佐々木(FQS)
//
//------------------------------------------------------------

BOOL SXFPart21FileReadC::RegisterAPEntity(INSTANCEDATA *IN_Instance)
{
	if(! m_InstanceIDManager->RegisterInstance(IN_Instance))
		return FALSE;

//	DEL(S)	チューニング対応	K.Naono	03.07.04
/*
	if(IN_Instance->EntityName == "INVISIBILITY"){
		if(! m_TableManager->RegisterInvisibility(IN_Instance))
			return FALSE;
	}
	if(IN_Instance->EntityName == "PRESENTATION_SIZE"){
		if(! m_TableManager->RegisterPresentationSize(IN_Instance))
			return FALSE;
	}
	if(IN_Instance->EntityName == "DRAUGHTING_TITLE"){
		if(! m_TableManager->RegisterSheetTitle(IN_Instance))
			return FALSE;
	}
*/
//	DEL(E)	チューニング対応	K.Naono	03.07.04
	return TRUE;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFPart21FileReadC.cpp	              作成日：2001.05.26
//
//  １．機能概要
//      AP202 Table Instanceの登録
//
//  ２．インターフェース
//      BOOL RegisterAPTable(INSTANCEDATA *IN_Instance)
//
//	    引数: 型			  引数名			    内容
//            INSTANCEDATA*   IN_Instance          Instanceの
//                                                 構造体のアドレス 
//	    復帰値	
//            正常時： TRUE
//			  異常時： FALSE
//
//  ３．履歴
//		履歴番号	日付け		 担当者	    概要
//		作成		2001.05.26   佐々木(FQS)
//
//------------------------------------------------------------
BOOL SXFPart21FileReadC::RegisterAPTable(INSTANCEDATA *IN_Instance)
{
	if(! m_TableManager->RegisterAP202IDTable(IN_Instance->InstanceID))
		return FALSE;
	if(! m_InstanceIDManager->RegisterInstance(IN_Instance))
		return FALSE;
	return TRUE;

}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFPart21FileReadC.cpp	              作成日：2001.05.26
//
//  １．機能概要
//      AP202 Assembly Instanceの登録
//
//  ２．インターフェース
//      BOOL RegisterAPAssembly(INSTANCEDATA *IN_Instance)
//
//	    引数: 型			  引数名			    内容
//            INSTANCEDATA*   IN_Instance          Instanceの
//                                                 構造体のアドレス 
//	    復帰値	
//            正常時： TRUE
//			  異常時： FALSE
//
//  ３．履歴
//		履歴番号	日付け		 担当者	    概要
//		作成		2001.05.26   佐々木(FQS)
//
//------------------------------------------------------------
BOOL SXFPart21FileReadC::RegisterAPAssembly(INSTANCEDATA *IN_Instance)
{
	if(! m_ReadAP202Manager->RegisterAPAssembly(IN_Instance))
		return FALSE;
	if(! m_InstanceIDManager->RegisterInstance(IN_Instance))
		return FALSE;

	return TRUE;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFPart21FileReadC.cpp	              作成日：2001.05.26
//
//  １．機能概要
//      Head Section Dataの取得
//
//  ２．インターフェース
//      BOOL GetHeadData(int *OUT_Level,
//                       int *OUT_Mode,
//                       char *OUT_FileName,
//                       char *OUT_Author,
//                       char *OUT_Organization,
//                       char *OUT_Version,
//                       char *OUT_OriginatingSystem )
//
//	    引数: 型			  引数名			    内容
//            int*            OUT_Level
//            int*            OUT_Mode
//            char*           OUT_FileName
//            char*           OUT_Author
//            char*           OUT_Organization
//            char*           OUT_Version
//            char*           OUT_OriginatingSystem
//
//	    復帰値	
//            正常時： TRUE
//			  異常時： FALSE
//
//  ３．履歴
//		履歴番号	日付け		 担当者	    概要
//		作成		2001.05.26   佐々木(FQS)
//
//------------------------------------------------------------
BOOL SXFPart21FileReadC::GetHeadData(int *OUT_Level,
									int *OUT_Mode,
									char *OUT_FileName,
									char *OUT_Author,
									char *OUT_Organization,
									char *OUT_Version,
									char *OUT_OriginatingSystem )
{
	*OUT_Level = m_HeadSection.Level;
	*OUT_Mode = m_HeadSection.Mode;

//	MOD(S)	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
	//strcpy(OUT_FileName,m_HeadSection.FileName);
	//strcpy(OUT_Author,m_HeadSection.Author);
	//strcpy(OUT_Organization,m_HeadSection.Organization);
	//strcpy(OUT_Version,m_HeadSection.Version);
	//strcpy(OUT_OriginatingSystem,m_HeadSection.OriginatingSystem);

	// 各項目のバッファサイズは仕様書より取得
	strcpy_s(OUT_FileName, 257, m_HeadSection.FileName);
	strcpy_s(OUT_Author, 257, m_HeadSection.Author);
	strcpy_s(OUT_Organization, 257, m_HeadSection.Organization);
	strcpy_s(OUT_Version, 257, m_HeadSection.Version);
	strcpy_s(OUT_OriginatingSystem, 257, m_HeadSection.OriginatingSystem);	// = translator_name
//	MOD(E)	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27

	return TRUE;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFPart21FileReadC.cpp	              作成日：2001.05.26
//
//  １．機能概要
//      Clear current instance data struct
//
//  ２．インターフェース
//       void ClearInstanceData()
//
//	    引数: 型			  引数名			    内容
//
//	    復帰値	
//            正常時： 
//			  異常時： 
//
//  ３．履歴
//		履歴番号	日付け		 担当者	    概要
//		作成		2001.05.26   佐々木(FQS)
//
//------------------------------------------------------------
void SXFPart21FileReadC::ClearInstanceData()
{
	//インスタンスデータの初期化;
	m_InstanceData.InstanceMode = 0;
	m_InstanceData.InstanceID = 0;
	m_InstanceData.EntityName.Empty();
	m_InstanceData.EntityData.Empty();

	return;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFPart21FileReadC.cpp	              作成日：2001.05.26
//
//  １．機能概要
//      Get handle of current file
//
//  ２．インターフェース
//      SXFPart21FileC* GetFileHandle()
//
//	    引数: 型			  引数名			    内容
//
//	    復帰値	
//            正常時： SXFPart21FileCのアドレス
//			  異常時： 
//
//  ３．履歴
//		履歴番号	日付け		 担当者	    概要
//		作成		2001.05.26   佐々木(FQS)
//
//------------------------------------------------------------
SXFPart21FileC* SXFPart21FileReadC::GetFileHandle()
{
	return m_File;
}
