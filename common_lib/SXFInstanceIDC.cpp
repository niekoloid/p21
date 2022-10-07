//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFInstanceIDC.cpp                    作成日：2001.06.07
//
//	１．クラス概要
//		インスタンスIDの取得を行う
//      
//	２．履歴
//	    履歴番号    日付け         担当者    概要
//      作成		2001.06.07    佐々木(FQS)
//		更新		2002.02.20	K.Naono		改修対応
//
//------------------------------------------------------------
#include "stdafx.h"
#include "SXFDataStructC.h"
#include "SXFEntityDataC.h"
#include "SXFInstanceIDC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFInstanceIDC.cpp                    作成日：2001.06.07
//
//  １．機能概要
//      クラス構築
//
//  ２．インターフェース
//	SXFInstanceIDC::SXFInstanceIDC()
//
//	    引数: 型			  引数名			    内容
//				なし
//
//  ３．履歴
//	    履歴番号    日付け         担当者    概要
//      作成		2001.06.07    佐々木(FQS)
//
//------------------------------------------------------------
SXFInstanceIDC::SXFInstanceIDC()
{
	//initialization
	m_FileName.Empty();
	m_MapViewPtr = NULL;    
	m_MapFile = NULL;
	m_TempFile = NULL;
	m_TempFileSize = 5000000;
	m_DataPtrInMapFile = NULL;
	/*	==>	Commented by S.Kakizawa(KLS) on 2006/01/12	//
	m_EntityMap.InitHashTable( 2999 );
	/*	<==	Commented by S.Kakizawa(KLS) on 2006/01/12	*/
	m_ComplexInstanceTable.RemoveAll();
	m_StyledItemTable.RemoveAll();
//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
	m_AvailableSize = m_TempFileSize;

}
//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFInstanceIDC.cpp                    作成日：2001.06.07
//
//  １．機能概要
//      クラス消滅
//  ２．インターフェース
//		SXFInstanceIDC::~SXFInstanceIDC()
//
//	    引数: 型			  引数名			    内容
//			なし
//  ３．履歴
//	    履歴番号    日付け         担当者    概要
//      作成		2001.06.07    佐々木(FQS)
//
//------------------------------------------------------------
SXFInstanceIDC::~SXFInstanceIDC()
{

	//entitydata クラスを削除
//	for(int i=0;i<m_EntityArray.GetSize();i++){
//		if(m_EntityArray[i]!=NULL)
//		delete m_EntityArray[i];
//	}
	for(POSITION pos = m_EntityArray.GetHeadPosition(); pos; ) {
		delete m_EntityArray.GetNext(pos) ;
	}

	//テンポラリファイルの削除
	//unmapview
	if (m_MapViewPtr != NULL)
		// address where mapped view begins
		UnmapViewOfFile( m_MapViewPtr ); 

	//close handle of filemapping
	if(m_MapFile!=NULL)
		// handle to object to close
		CloseHandle(m_MapFile);
	//close handle of file
	if(m_TempFile!=NULL)
		// handle to object to close
		CloseHandle(m_TempFile);
 
	//ﾃﾝﾎﾟﾗﾘﾌｧｲﾙの削除
	if(! m_FileName.IsEmpty() ){
		if(! DeleteFile(m_FileName) ){ // pointer to name of file to delete
			int errresult= GetLastError();
			if (errresult == ERROR_FILE_NOT_FOUND){ 
			}else{
			}
		}
	}

}
//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFInstanceIDC.cpp                    作成日：2001.06.07
//
//  １．機能概要
//      Temp Fileの初期化
//      (FileMapping: \\system temp dircetory\SXF?????.TMP)
//
//  ２．インターフェース
//      BOOL InitFileMapping(int IN_FileSize)
//	    引数: 型			  引数名			    内容
//				int				 IN_FileSize		ﾌｧｲﾙｻｲｽﾞ
//	    復帰値	
//            正常時：TRUE
//			  異常時：FALSE
//
//  ３．履歴
//	    履歴番号    日付け         担当者    概要
//      作成		2001.06.07    佐々木(FQS)
//
//------------------------------------------------------------
BOOL SXFInstanceIDC::InitFileMapping(int IN_FileSize)
{

/* 2006.03.13 メモリ取得サイズの変更（大容量ファイル対応） ===> */
//	m_TempFileSize = 2 * IN_FileSize;
	m_TempFileSize = IN_FileSize;
//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
	m_AvailableSize = m_TempFileSize;
/* 2006.03.13 メモリ取得サイズの変更（大容量ファイル対応） <=== */

	//パスの取得
	TCHAR temppath [MAX_PATH]; 
	DWORD temppathresult = GetTempPath (MAX_PATH, temppath); 
	if ( temppathresult == 0){
		int errresult= GetLastError();
		return FALSE;
	}

//	DEL(S)	改修対応	K.Naono	02.02.20
/*
	//ディスクの空き容量のチェック
	ULARGE_INTEGER freebytestocaller;
	ULARGE_INTEGER totalbytes;
	ULARGE_INTEGER totalfreebytes;

	GetDiskFreeSpaceEx( temppath,  // pointer to the directory name
					&freebytestocaller, // receives the number of bytes on
										// disk available to the caller
					&totalbytes,        // receives the number of bytes on disk
					&totalfreebytes     // receives the free bytes on disk
					);
*/
//	DEL(E)	改修対応	K.Naono	02.02.20

	//ファイル名の取得
	TCHAR tempfile[MAX_PATH]; 

	UINT tempfileresult = GetTempFileName (temppath, DEF_SXF, 0, tempfile);
							//tempfile name format : temppath\SXF*****.TMP
	if ( temppathresult == 0){
		int errresult= GetLastError();
		return FALSE;
	}

	//テンポラリファイルの作成
	m_TempFile = CreateFile(tempfile, //file name
							GENERIC_WRITE|GENERIC_READ,
							0,0,OPEN_ALWAYS,0,0);
    
	if(m_TempFile == INVALID_HANDLE_VALUE){
		int errresult= GetLastError();
		if (errresult == ERROR_FILE_NOT_FOUND){ 
			/*ファイルが見つかりません*/
		}else if(errresult == ERROR_PATH_NOT_FOUND ){
			/*パスが見つかりません*/
		}else if(errresult == ERROR_TOO_MANY_OPEN_FILES ){
			/*ファイルが多すぎます*/
		}else if(errresult == ERROR_DISK_FULL ){
			/*ディスクがいっぱいです*/
		}else{
		}

		return FALSE;
	}

	m_FileName = tempfile;//save file for delete process

	m_MapFile  = CreateFileMapping(m_TempFile,NULL,PAGE_READWRITE,0,
									m_TempFileSize, //file size
									NULL);
	if(m_MapFile == NULL ){
		int errresult= GetLastError();

		if(errresult == ERROR_DISK_FULL ){
			/*ディスクがいっぱいです*/
		}else{
		}
		return FALSE;
	}

	m_MapViewPtr = MapViewOfFile(m_MapFile,FILE_MAP_WRITE,0,0,0);
	m_DataPtrInMapFile = m_MapViewPtr;    

	if(m_MapViewPtr == NULL ){
		int errresult= GetLastError();
		if(errresult == ERROR_DISK_FULL ){
			/*ディスクがいっぱいです*/
		}else{
		}
		return FALSE;
	}

	return TRUE;

}
//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFInstanceIDC.cpp                    作成日：2001.06.07
//
//  １．機能概要
//      Instance dataの登録
//
//  ２．インターフェース
//      BOOL RegisterInstance(INSTANCEDATA *IN_Instance)
//	    引数: 型			  引数名			    内容
//            INSTANCEDATA*   IN_Instance	       Instance Data
//                                                 構造体のアドレス
//	    復帰値	
//            正常時：TRUE
//			  異常時：FALSE
//
//  ３．履歴
//	    履歴番号    日付け         担当者    概要
//      作成		2001.06.07    佐々木(FQS)
//
//------------------------------------------------------------
BOOL SXFInstanceIDC::RegisterInstance(INSTANCEDATA *IN_Instance)
{

	//インスタンスIDテーブルの作成
	if(IN_Instance->EntityName == DEF_SXF_COMPLEX_INSTANCE){
//		m_ComplexInstanceTable.Add(IN_Instance->InstanceID);
		m_ComplexInstanceTable.AddTail(IN_Instance->InstanceID);
	}else if(IN_Instance->EntityName == DEF_STYLED_ITEM){
//		m_StyledItemTable.Add(IN_Instance->InstanceID);
		m_StyledItemTable.AddTail(IN_Instance->InstanceID);
	}

	SXFEntityDataC *entitydata;

	if( m_EntityMap.Lookup(IN_Instance->InstanceID, entitydata) != 0)
		//すでに同じIDがテーブルに存在した場合
		return FALSE;

	entitydata = new SXFEntityDataC();

//	MOD(S)	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
	//entitydata->SetEntityData(m_DataPtrInMapFile,IN_Instance);

	size_t len = entitydata->SetEntityData(m_DataPtrInMapFile, m_AvailableSize,IN_Instance);
	m_AvailableSize -= len;
//	MOD(E)	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27

	m_EntityMap.SetAt( IN_Instance->InstanceID, entitydata);

//	m_EntityArray.Add(entitydata);
	m_EntityArray.AddTail(entitydata);

	return TRUE;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFInstanceIDC.cpp                    作成日：2001.06.07
//
//  １．機能概要
//      指定Instance IDの Entity data CLASSのアドレスの取得
//
//  ２．インターフェース
//      SXFEntityDataC* GetEntityDataPtr(int IN_InstanceID)
//	    引数: 型			  引数名			    内容
//            int            IN_Instance	       Instance ID
//
//	    復帰値	
//            正常時：Entity data CLASSのアドレス
//			  異常時：NULL
//      
//
//  ３．履歴
//	    履歴番号    日付け         担当者    概要
//      作成		2001.06.07    佐々木(FQS)
//
//------------------------------------------------------------
SXFEntityDataC* SXFInstanceIDC::GetEntityDataPtr(int IN_InstanceID)
{

	SXFEntityDataC *entitydata;
	entitydata = NULL;

	if( m_EntityMap.Lookup(IN_InstanceID, entitydata) == 0)
		//テーブルにIDが存在しません
		return NULL;
	return entitydata;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFInstanceIDC.cpp                    作成日：2001.06.07
//
//  １．機能概要
//      新しいInstance IDを返す
//  ２．インターフェース
//	    引数: 型			  引数名			    内容
//            int            IN_Instance	       Instance ID
//
//	    復帰値	
//            正常時：A New Entity ID
//			  異常時：
//
//  ３．履歴
//	    履歴番号    日付け         担当者    概要
//      作成		2001.06.07    佐々木(FQS)
//
//------------------------------------------------------------
int SXFInstanceIDC::GetNewInstanceID()
{
	int NewID=-1;

	NewID = m_FeatureIDManager.Get_ID();

	return NewID;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFInstanceIDC.cpp                    作成日：2001.06.07
//
//  １．機能概要
//      Instance IDのArrayを返す
//  ２．インターフェース
//	    引数: 型			  引数名			    内容
//            CString            IN_InstanceName	   Instance name
//
//	    復帰値	
//            正常時：CArray
//			  異常時：
//
//  ３．履歴
//	    履歴番号    日付け         担当者    概要
//      作成		2001.06.07    佐々木(FQS)
//
//------------------------------------------------------------
//	MOD(S)	チューニング対応	K.Naono	03.07.03
//CArray<int,int>* SXFInstanceIDC::GetIDArray(CString IN_InstanceName) 
CList<int,int>* SXFInstanceIDC::GetIDArray(CString IN_InstanceName) 
//	MOD(E)	チューニング対応	K.Naono	03.07.03
{
	if(IN_InstanceName == DEF_SXF_COMPLEX_INSTANCE){
		return &m_ComplexInstanceTable;
	}else if(IN_InstanceName == DEF_STYLED_ITEM){
		return &m_StyledItemTable;
	}

	return NULL;
}

/*	==>	Added by S.Kakizawa(KLS) on 2006/01/12	*/
//------------------------------------------------------------------------------------------------
//	Method Name:
//		SXFTableInstanceC::SXFTableInstanceC
//	Exposition:
//		Default Constructor.
//	Protective:
//		public
//	Return Value:
//		None.
//	Parameters:
//		None.
//	History:
//		Created by S.Kakizawa(KLS) on 2006/01/12.
//	Notes:
//		All Rights Reserved,(c) JACIC 2006
//------------------------------------------------------------------------------------------------
SXFTableInstanceC::SXFTableInstanceC( )
{
	m_dwCount		= 0;
	m_dwTableCount	= 1;
	m_dwMaxCount	= ARRAY_GROWSIZE;
	m_pData			= (SXFEntityDataC***) new BYTE[m_dwTableCount * sizeof( SXFEntityDataC** )];
	m_pData[0]		= (SXFEntityDataC**) new BYTE[ARRAY_GROWSIZE * sizeof( SXFEntityDataC* )];

	memset( m_pData[0], NULL, m_dwMaxCount * sizeof( SXFEntityDataC* ) );
}

//------------------------------------------------------------------------------------------------
//	Method Name:
//		SXFTableInstanceC::~SXFTableInstanceC
//	Exposition:
//		Destructor.
//	Protective:
//		public
//	Return Value:
//		None.
//	Parameters:
//		None.
//	History:
//		Created by S.Kakizawa(KLS) on 2006/01/12.
//	Notes:
//		All Rights Reserved,(c) JACIC 2006
//------------------------------------------------------------------------------------------------
SXFTableInstanceC::~SXFTableInstanceC( )
{
	for( DWORD dwLoop=0; dwLoop<m_dwTableCount; dwLoop++ )
	{
		delete[] (BYTE*)m_pData[dwLoop];
	}
	delete[] (BYTE*)m_pData;
}

//------------------------------------------------------------------------------------------------
//	Method Name:
//		SXFTableInstanceC::Add
//	Exposition:
//		Add the Pointer to the 'SXFEntityDataC' Object into the List.
//	Protective:
//		public
//	Return Value:
//		None.
//	Parameters:
//		SXFEntityDataC* poEntity : Added Pointer to the 'SXFEntityDataC' Object.
//	History:
//		Created by S.Kakizawa(KLS) on 2006/01/12.
//	Notes:
//		All Rights Reserved,(c) JACIC 2006
//------------------------------------------------------------------------------------------------
void SXFTableInstanceC::Add( SXFEntityDataC* poEntity )
{
	DWORD	dwEntityNumber	= poEntity->m_InstanceID / 10;
	if( m_dwMaxCount <= dwEntityNumber )
	{
		DWORD	dwTableCount	= dwEntityNumber / ARRAY_GROWSIZE + 1;

		SXFEntityDataC*** pNewData	= (SXFEntityDataC***) new BYTE[dwTableCount * sizeof( SXFEntityDataC** )];

		memcpy( pNewData, m_pData, m_dwTableCount * sizeof(SXFEntityDataC**) );
		for( ; m_dwTableCount < dwTableCount; m_dwTableCount++ )
		{
			pNewData[m_dwTableCount]	= (SXFEntityDataC**) new BYTE[ARRAY_GROWSIZE * sizeof( SXFEntityDataC* )];
			memset( pNewData[m_dwTableCount], NULL, ARRAY_GROWSIZE * sizeof( SXFEntityDataC* ) );
		}

		delete[] (BYTE*)m_pData;
		m_pData			= pNewData;
		m_dwMaxCount	+= ARRAY_GROWSIZE;
	}

	m_pData[dwEntityNumber/ARRAY_GROWSIZE][dwEntityNumber%ARRAY_GROWSIZE]	= poEntity;

	if( m_dwCount <= dwEntityNumber )
	{
		m_dwCount	= dwEntityNumber + 1;
	}
}
/*	<==	Added by S.Kakizawa(KLS) on 2006/01/12	*/
