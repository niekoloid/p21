//---------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFPart21FileWriteC.cpp              作成日：2000.03.26
//
//	１．クラス概要
//      ファイルの出力を管理する
//
//	２．履歴
//		履歴番号	日付け		 担当者	    概要
//		作成		2000.03.26   周
//		更新		2002.02.20	K.Naono		改修対応
//
//---------------------------------------------------------
#include "stdafx.h"
#include <afx.h>
#include "SXFDataStructC.h"
#include "SXFPart21FileC.h"
#include "SXFPart21FileWriteC.h"
#include "SXFErrorMsgC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFPart21FileWriteC.cpp              作成日：2000.03.26
//
//  １．機能概要
//      コンストラクタ
//
//  ２．インターフェース
//
//
//	３．履歴
//		履歴番号	日付け		 担当者	    概要
//		作成		2000.03.26   周
//---------------------------------------------------------
SXFPart21FileWriteC::SXFPart21FileWriteC()
{
	//initialization
	m_HeadSection.Level = -1;
	m_HeadSection.Mode = -1;
	m_HeadSection.FileName.Empty();
	m_HeadSection.Author.Empty();
	m_HeadSection.Organization.Empty();
	m_HeadSection.Version.Empty();
	m_HeadSection.OriginatingSystem.Empty();
	m_File = NULL;

}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFPart21FileWriteC.cpp              作成日：2000.03.26
//
//  １．機能概要
//      デストラクタ
//
//  ２．インターフェース
//
//	３．履歴
//		履歴番号	日付け		 担当者	    概要
//		作成		2000.03.26   周
//---------------------------------------------------------
SXFPart21FileWriteC::~SXFPart21FileWriteC()
{
	if(m_File!=NULL)
		delete m_File;
}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFPart21FileWriteC.cpp              作成日：2000.03.26
//
//  １．機能概要
//      ファイルのオープン
//
//  ２．インターフェース
//      int OpenPart21WriteFile(LPCTSTR IN_FileName )
//
//	    引数: 型			  引数名			    内容
//            LPCTSTR         IN_FileNamer         File Name
//
//	    復帰値	
//            正常時： 0
//			  異常時：その他
//
//	３．履歴
//		履歴番号	日付け		 担当者	    概要
//		作成		2000.03.26   周
//---------------------------------------------------------
int SXFPart21FileWriteC::OpenPart21WriteFile(LPCTSTR IN_FileName )
{
	CString infilename=IN_FileName;
	CString pathname;
//	DEL(S)	改修対応	K.Naono	02.02.20
/*
    ULARGE_INTEGER freebytestocaller;
    ULARGE_INTEGER totalbytes;
    ULARGE_INTEGER totalfreebytes;

    int findbackslash = infilename.ReverseFind('\\');
    if( findbackslash != -1 ){ //filename with a path
        pathname = infilename.Left(findbackslash+1);
		//空き容量のチェック
		GetDiskFreeSpaceEx( pathname,  // pointer to the directory name
							&freebytestocaller, // receives the number of bytes on
												// disk available to the caller
							&totalbytes,        // receives the number of bytes on disk
							&totalfreebytes     // receives the free bytes on disk
							);
    }else{ //file name without a path
        //check the free disk space
		GetDiskFreeSpaceEx( NULL,  // pointer to the current directory
							&freebytestocaller, // receives the number of bytes on
												// disk available to the caller
							&totalbytes,        // receives the number of bytes on disk
							&totalfreebytes     // receives the free bytes on disk
							);
    }
*/
//	DEL(E)	改修対応	K.Naono	02.02.20

	TRY
	{
		m_File = new SXFPart21FileC(IN_FileName,CFile::modeCreate |
			CFile::modeWrite | CFile::shareExclusive);
	}
	CATCH( CFileException, e )
	{
		/* ディスクに書き込めません */
		if (e->m_cause == CFileException::diskFull){
			SXFErrorMsgC::RecordError(SXFDISC,"",0);
			return SXFDISC;
		}
		else if (e->m_cause == CFileException::fileNotFound){
			/* 指定されたファイルまたはディレクトリが見つかりません */
			SXFErrorMsgC::RecordError(SXFFILEDIRECTORY,"",1,IN_FileName);
			return SXFFILEDIRECTORY;
		}
		else{
			/* STEPファイルのオープンに失敗しました */
			SXFErrorMsgC::RecordError(SXFNOTOPENSTEPFILE,"",1,IN_FileName);
			return SXFNOTOPENSTEPFILE;
		}
	}
	END_CATCH

	return 0;
}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFPart21FileWriteC.cpp              作成日：2000.03.26
//
//  １．機能概要
//      Head Section Dataの設定
//
//  ２．インターフェース
//      BOOL SetHeadSection( int  *IN_Level,
//                           int  *IN_Mode,
//                           char *IN_FileName,
//                           char *IN_Author,
//                           char *IN_Organization,
//                           char *IN_Version,
//                           char *IN_OriginatingSystem )
//
//	    引数: 型			  引数名			    内容
//            int  *          IN_Level
//            int  *          IN_Mode
//            char *          IN_FileName
//            char *          IN_Author
//            char *          IN_Organization
//            char *          IN_Version
//            char *          IN_OriginatingSystem
//
//	    復帰値	
//            正常時： TRUE
//			  異常時： FALSE
//
//	３．履歴
//		履歴番号	日付け		 担当者	    概要
//		作成		2000.03.26   周
//---------------------------------------------------------

BOOL SXFPart21FileWriteC::SetHeadSection(	int  *IN_Level,
											int  *IN_Mode,
											char *IN_FileName,
											char *IN_Author,
											char *IN_Organization,
											char *IN_Version,
											char *IN_OriginatingSystem )
{
	m_HeadSection.Level = *IN_Level ;
	m_HeadSection.Mode = *IN_Mode;
	m_HeadSection.FileName = IN_FileName;  
	m_HeadSection.Author = IN_Author;
	m_HeadSection.Organization = IN_Organization;
	m_HeadSection.Version = IN_Version;
	m_HeadSection.OriginatingSystem = IN_OriginatingSystem;

	return TRUE;
}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFPart21FileWriteC.cpp              作成日：2000.03.26
//
//  １．機能概要
//      Head Section Dataの出力
//
//  ２．インターフェース
//      int WriteHeadSection( )
//
//	    引数: 型			  引数名			    内容
//				なし
//
//	    復帰値	
//            正常時： 0
//			  異常時： その他
//
//	３．履歴
//		履歴番号	日付け		 担当者	    概要
//		作成		2000.03.26   周
//---------------------------------------------------------
int SXFPart21FileWriteC::WriteHeadSection( )
{
    if (m_File == NULL){
		/* ファイルがオープンされていません */
		SXFErrorMsgC::RecordError(SXFSTEPFILENOTOPEN,"",0);		
		return SXFSTEPFILENOTOPEN;
	}
	TRY{
		m_File->WriteHeadSection(&m_HeadSection);
	}
	CATCH( CFileException, e ){
		/* ディスクに書き込めません */
		SXFErrorMsgC::RecordError(SXFDISC,"",0);
		return SXFDISC;
	}
	END_CATCH

	return 0;
}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFPart21FileWriteC.cpp              作成日：2000.03.26
//
//  １．機能概要
//      Feature Comment Instanceの出力
//
//  ２．インターフェース
//      BOOL WriteFeatureInstance(INSTANCEDATA* feature)
//
//	    引数: 型			  引数名			    内容
//            INSTANCEDATA*   feature              Instance Dataの
//                                                 構造体のアドレス
//
//	    復帰値	
//            正常時： TRUE
//			  異常時： FALSE
//
//	３．履歴
//		履歴番号	日付け		 担当者	    概要
//		作成		2000.03.26   周
//---------------------------------------------------------
BOOL SXFPart21FileWriteC::WriteFeatureInstance(INSTANCEDATA* feature)
{
	/* STEPファイルがオープンされていません */
	if ( m_File == NULL )//have not a file to write
		return FALSE;

	if(m_HeadSection.Mode == 2){	// if not 0:ambilateral mode
									// or not 1:Feature mode or
		return FALSE;
	}

	if( feature->InstanceMode != SXF_IM_FT_ENTITY &&
		feature->InstanceMode != SXF_IM_FT_TABLE  &&
		feature->InstanceMode != SXF_IM_FT_ASSEMBLY)
	{
		return FALSE;
	}

	TRY{
		m_File->WriteInstance( feature );
	}
	/* ディスクに書き込めません */
	CATCH( CFileException, e ){
		//ディスクがいっぱいです
		if( e->m_cause == CFileException::diskFull){
			return FALSE;
		//ファイルが見つかりません
		}else if (e->m_cause == CFileException::fileNotFound ){
			return FALSE;
		// その他のエラー
		}else{
			return FALSE;
		}
	}
	END_CATCH

	return TRUE;
}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFPart21FileWriteC.cpp              作成日：2000.03.26
//
//  １．機能概要
//      ファイルのクローズ
//
//  ２．インターフェース
//      BOOL ClosePart21WriteFile(  )
//
//	    引数: 型			  引数名			    内容
//					なし
//
//	    復帰値	
//            正常時： TRUE
//			  異常時： FALSE
//
//	３．履歴
//		履歴番号	日付け		 担当者	    概要
//		作成		2000.03.26   周
//---------------------------------------------------------
BOOL SXFPart21FileWriteC::ClosePart21WriteFile(  )
{
	/*閉じるファイルがありません*/
	if (m_File == NULL)
		return FALSE;
	CString endsec;
	CString endline("\n");
	endsec="ENDSEC;";
	endsec+=endline;
	endsec+="END-ISO-10303-21;";
	endsec+=endline;
	m_File->WriteString(endsec);
	m_File->Close();

	return TRUE;
}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFPart21FileWriteC.cpp              作成日：2000.03.26
//
//  １．機能概要
//      変換管理からファイルのハンドルを取得
//
//  ２．インターフェース
//      SXFPart21FileC* GetFileHandle()
//
//	    引数: 型			  引数名			    内容
//						なし
//	    復帰値	
//            正常時： SXFPart21FileCのアドレス
//			  異常時： 
//
//	３．履歴
//		履歴番号	日付け		 担当者	    概要
//		作成		2000.03.26   周
//---------------------------------------------------------
SXFPart21FileC* SXFPart21FileWriteC::GetFileHandle()
{
	return m_File;
}
