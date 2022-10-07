//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFWriteManagerC.cpp                    作成日：2001.06.18
//
//	１．クラス概要
//      出力時のアセンブリ間の参照関係を管理する
//
//	２．履歴
//	    履歴番号    日付け         担当者    概要
//      作成		2001.06.18    佐々木(FQS)
//
//------------------------------------------------------------

#include "stdafx.h"
#include "SXFWriteManagerC.h"
#include "SXFPart21FileC.h"
#include "SXFTableManagerC.h"
#include "SXFErrorMsgC.h"
#include "SXFPart21FileWriteC.h"
#include "SXFComInfoC.h"
#include "SXFInstanceIDC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFWriteManagerC.cpp                    作成日：2001.06.18
//
//  １．機能概要
//      クラス構築
//
//  ２．インターフェース
//	void	SXFWriteManagerC::SXFWriteManagerC()
//	引数:	型								引数名				内容
//			なし					
//
//  ３．履歴
//	    履歴番号    日付け         担当者    概要
//      作成		2001.06.18    佐々木(FQS)
//
//------------------------------------------------------------
SXFWriteManagerC::SXFWriteManagerC()
{
	//initialization
	m_ChildrenArray = NULL;
	m_CurrentAssembly = NULL;
	m_SheetAssemblyFlag=FALSE;
	m_CurrentChild = NULL;
	m_FirstAssemblyFlag=TRUE;
	m_AssemType = -1;
	m_CurveViewFlag = -1;
	m_SfigFlag = -1;
	m_SfigTableIndex = 0;
	m_PointX = 0.0;
	m_PointY = 0.0;
	m_PointN = 0;
	m_ErrorFlag = FALSE;
	m_CurveFlag = 0;
	m_AssemblyCode = 1;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFWriteManagerC.cpp                    作成日：2001.06.18
//
//  １．機能概要
//      クラス構築
//
//  ２．インターフェース
//		void	SXFWriteManagerC::SXFWriteManagerC(
//								SXFPart21FileWriteC* IN_WriteFile,
//								SXFInstanceIDC* IN_InstanceIDManager)
//
//		
//	引数：型					引数名					内容
//		  SXFPart21FileWriteC*	IN_WriteFile			ﾌｧｲﾙ出力ｵﾌﾞｼﾞｪｸﾄ
//		  SXFInstanceIDC*		IN_InstanceIDManager	ｲﾝｽﾀﾝｽIDｵﾌﾞｼﾞｪｸﾄ
//
//  ３．履歴
//	    履歴番号    日付け         担当者    概要
//      作成		2001.06.18    佐々木(FQS)
//
//------------------------------------------------------------
SXFWriteManagerC::SXFWriteManagerC(
						SXFPart21FileC*			IN_File,
						SXFTableManagerC*		IN_TableManager,
						SXFComInfoC*			IN_ComInfo,
						SXFPart21FileWriteC*	IN_WriteFile,
						SXFInstanceIDC*			IN_InstanceIDManager)
{
	//initialization
	m_ChildrenArray = NULL;
	m_CurrentAssembly = NULL;
	m_SheetAssemblyFlag=FALSE;
	m_CurrentChild = NULL;
	m_FirstAssemblyFlag=TRUE;
	m_Part21File = IN_File;
	m_TableManager = IN_TableManager;
	m_ComInfo = IN_ComInfo;
	m_WriteFile = IN_WriteFile;
	m_InstanceIDManager = IN_InstanceIDManager;
	m_AssemType = -1;
	m_CurveViewFlag = -1;
	m_SfigFlag = -1;
	m_SfigTableIndex = 0;
	m_PointX = 0.0;
	m_PointY = 0.0;
	m_PointN = 0;
	m_ErrorFlag = FALSE;
	m_CurveFlag = 0;
	m_AssemblyCode = 1;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFWriteManagerC.cpp                    作成日：2001.06.18
//
//  １．機能概要
//      クラス消滅
//
//  ２．インターフェース
//	void	SXFWriteManagerC::~SXFWriteManagerC()
//	引数:	型								引数名				内容
//			なし					
//
//  ３．履歴
//	    履歴番号    日付け         担当者    概要
//      作成		2001.06.18    佐々木(FQS)
//
//------------------------------------------------------------
SXFWriteManagerC::~SXFWriteManagerC()
{
	if (m_CurrentAssembly != NULL)
		delete m_CurrentAssembly;
	if (m_ChildrenArray != NULL)
		delete m_ChildrenArray;
	if (m_CurrentChild != NULL)
		delete m_CurrentChild;

//	MOD(S)	チューニング対応	K.Naono	03.07.08
	for( POSITION pos = m_SfigorgTable.GetHeadPosition(); pos; ) {
		SXFSFIGORGCHECK*	pSfigOrg = m_SfigorgTable.GetNext(pos) ;
		delete pSfigOrg ;
	}
//	MOD(E)	チューニング対応	K.Naono	03.07.08
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFWriteManagerC.cpp                    作成日：2001.06.18
//
//  １．機能概要
//      Assembly要素の登録
//
//  ２．インターフェース
//      int RegisterAssembly(int IN_AssemblyType,LPVOID IN_Struct)
//
//	    引数: 型			  引数名			    内容
//            int             IN_AssemblyType      Assembly Type
//            LPVOID          IN_Struct            Assembly要素の
//                                                 構造体のアドレス
//      
//	    復帰値	
//            正常時：Assembly要素のCode
//			  異常時：-1
//
//  ３．履歴
//	    履歴番号    日付け         担当者    概要
//      作成		2001.06.18    佐々木(FQS)
//		更新		2001.09.18		K.Naono		ハッチング障害対応
//
//------------------------------------------------------------
int SXFWriteManagerC::RegisterAssembly(int IN_AssemblyType,LPVOID IN_Struct)
{
	/** すでに用紙がある場合 **/
	if( m_SheetAssemblyFlag == TRUE){
		m_AssemType = -1;	/* アセンブリは開かれていない */
		/* 用紙 */
		if (IN_AssemblyType == 1){
			/* 用紙は１つしか設定できない */
			SXFErrorMsgC::RecordError(SXFSHEETONE,
										DEF_SHEET,
										0);
			return SXFSHEETONE;
		}
		else if (IN_AssemblyType == 2){
			/* 複合図形上に用紙は配置できない */
			SXFErrorMsgC::RecordError(SXFSFIGLOCERR,
										DEF_SFIG_ORG,
										0);
			return SXFSFIGLOCERR;
		}
		else if (IN_AssemblyType == 3){
			/* 複合曲線上には用紙は配置できない */
			SXFErrorMsgC::RecordError(SXFCURVELOCERR,
										DEF_COMPOSITE_CURVE_ORG,
										0);
			return SXFCURVELOCERR;
		}
	}
	/** 用紙 **/
	if(IN_AssemblyType == 1)
		m_SheetAssemblyFlag=TRUE;
	/** 複合図形 **/
	if(IN_AssemblyType == 2){
//	MOD(S)	チューニング対応	K.Naono	03.07.08
/*
		SXFSFIGORGCHECK sfigorgcheck;
		sfigorgcheck.name = ((Sfigorg_Struct*)IN_Struct)->name;
		sfigorgcheck.type = ((Sfigorg_Struct*)IN_Struct)->flag;
		sfigorgcheck.flag = -1;
		sfigorgcheck.ID = -1;
		sfigorgcheck.locate_flag = -1;
		sfigorgcheck.error = -1;
		m_SfigorgTable.Add(sfigorgcheck );
*/
		SXFSFIGORGCHECK*	pSfigOrg = new SXFSFIGORGCHECK ;
		pSfigOrg->name = ((Sfigorg_Struct*)IN_Struct)->name ;
		pSfigOrg->type = ((Sfigorg_Struct*)IN_Struct)->flag ;
		m_SfigorgTable.AddTail(pSfigOrg) ;
		m_mapSfigOrg.SetAt(pSfigOrg->name, pSfigOrg) ;
//	MOD(E)	チューニング対応	K.Naono	03.07.08
	}

	//AssemblyType set
	m_AssemType = IN_AssemblyType;
	//最初のアセンブリ
	if(m_FirstAssemblyFlag){
		/** WriteMapping管理オブジェクト生成 **/
		m_CurrentAssembly = new SXFWriteMappingManagerC(m_Part21File,m_TableManager,
									m_AssemType,&m_AssemblyTable,&m_PointTable,
//	MOD(S)	チューニング対応	K.Naono	03.07.08
//									&m_SfigorgTable,m_ComInfo,m_WriteFile,
									&m_mapSfigOrg,m_ComInfo,m_WriteFile,
//	MOD(E)	チューニング対応	K.Naono	03.07.08
									m_InstanceIDManager);
		/**構造体ｾｯﾄ**/
		m_CurrentAssembly->SetStructData(IN_AssemblyType,IN_Struct);
		/** FirstAssemblyFlag をOFF **/
		m_FirstAssemblyFlag=!m_FirstAssemblyFlag;
		/** ChildrenArrayを生成 **/
		m_ChildrenArray = new CUIntArray();
		if(IN_AssemblyType == 3 &&
			((Ccurve_Org_Struct*)IN_Struct)->flag == 0 ){
			m_CurveViewFlag = 0;
		}else{
			m_CurveViewFlag = 1;
		}

		if (IN_AssemblyType == 2)
			m_SfigFlag = 1;
		else
			m_SfigFlag = 0;
	}else{ //not the first assembly
		//assembly must have children
		if (m_ChildrenArray->GetSize() <= 0){
			/* 前回ｾｯﾄしたｱｾﾝﾌﾞﾘ要素がｴﾗｰ */
			if (m_ErrorFlag)
				m_ErrorFlag = FALSE;
			else{
				if (m_SfigFlag == 1){
					/** 複合図形定義がエラー **/
//	MOD(S)	チューニング対応	K.Naono	03.07.08
/*
					m_SfigorgTable[m_SfigTableIndex].error = -1;
*/
					POSITION	pos = m_SfigorgTable.FindIndex(m_SfigTableIndex) ;
					if( pos != NULL ) {
						SXFSFIGORGCHECK*	pSfigOrg = m_SfigorgTable.GetAt(pos) ;
						pSfigOrg->error = -1 ;
					}
//	MOD(E)	チューニング対応	K.Naono	03.07.08
					m_SfigTableIndex++;
				}
				/* 複合曲線 */
				if (m_CurveFlag == 1)
					/* 複合曲線テーブルからエラーのアセンブリコードを削除 */
//	MOD(S)	チューニング対応	K.Naono	03.07.09
//					m_CurveTable.RemoveAt(m_CurveTable.GetSize()-1);
					m_CurveTable.RemoveTail() ;
//	MOD(E)	チューニング対応	K.Naono	03.07.09
					/* アセンブリ要素上に要素がない */
					SXFErrorMsgC::RecordError(SXFNOTFEATURE,"",0);
			}
		}
		else{
			int assemblyid1 = 0;
			int assemblyid2 = 0;
			int pointid = 0;

			double pointx = 0.0;
			double pointy = 0.0;

			if( m_PointN && m_PointX )
				pointx=m_PointX/m_PointN;
			if( m_PointN && m_PointY )
				pointy=m_PointY/m_PointN;
			/** アセンブリ要素のMapping **/
			if(! m_CurrentAssembly->MappingAssembly(m_ChildrenArray,
						assemblyid1, assemblyid2, pointid, pointx, pointy )) {
				/* Mappingに失敗 */

				/** 複合図形定義 **/
				if (m_SfigFlag == 1){
					/* 複合図形テーブルのエラーフラグをON */
//	MOD(S)	チューニング対応	K.Naono	03.07.08
/*
					m_SfigorgTable[m_SfigTableIndex].error = -1;
*/
					POSITION	pos = m_SfigorgTable.FindIndex(m_SfigTableIndex) ;
					if( pos != NULL ) {
						SXFSFIGORGCHECK*	pSfigOrg = m_SfigorgTable.GetAt(pos) ;
						pSfigOrg->error = -1 ;
					}
//	MOD(E)	チューニング対応	K.Naono	03.07.08
					m_SfigTableIndex++;
				}
				/* 複合曲線 */
				if (m_CurveFlag == 1)
					/* 複合曲線テーブルからエラーのアセンブリコードを削除 */
//	MOD(S)	チューニング対応	K.Naono	03.07.09
//					m_CurveTable.RemoveAt(m_CurveTable.GetSize()-1);
					m_CurveTable.RemoveTail() ;
//	MOD(E)	チューニング対応	K.Naono	03.07.09
			}
			else{
				if (m_SfigFlag == 1){
					/* 複合図形テーブルのエラーフラグをOFF */
//	MOD(S)	チューニング対応	K.Naono	03.07.08
/*
					m_SfigorgTable[m_SfigTableIndex].error = 1;
					m_SfigorgTable[m_SfigTableIndex].ID = assemblyid1;
*/
					POSITION	pos = m_SfigorgTable.FindIndex(m_SfigTableIndex) ;
					if( pos != NULL ) {
						SXFSFIGORGCHECK*	pSfigOrg = m_SfigorgTable.GetAt(pos) ;
						pSfigOrg->error	= 1 ;
						pSfigOrg->ID	= assemblyid1 ;
					}
//	MOD(S)	チューニング対応	K.Naono	03.07.08
					m_SfigTableIndex++;
				}
				/** アセンブリコードを＋１ **/
				m_AssemblyCode++;
			}
			/* データのクリア */
			m_ChildrenArray->RemoveAll();	
			m_CurrentAssembly->ClearData();

			m_PointX = 0.0;
			m_PointY = 0.0;
			m_PointN = 0;

			//CARTESIAN_POINT_TABLE
//	MOD(S)	ハッチング障害対応	K.Naono		01.09.18
//			m_PointTable.Add(pointid);
			SXF_POINT	point ;
			point.x = pointx ; point.y = pointy ;
			m_PointTable.Add(point) ;
//	MOD(E)	ハッチング障害対応	K.Naono		01.09.18

			if(m_CurveViewFlag == 0){
				m_InvisibilityCurveTable.Add(assemblyid1);
			}

			m_AssemblyTable.Add(assemblyid2);
		}
	}

	/** 複合曲線定義 **/
	if(IN_AssemblyType == 3){
		/* 複合曲線フラグON */
		m_CurveFlag = 1;
		/* 複合曲線テーブルにアセンブリコード追加 */
//	MOD(S)	チューニング対応	K.Naono	03.07.09
//		m_CurveTable.Add(m_AssemblyCode);
		m_CurveTable.AddTail(m_AssemblyCode) ;
//	MOD(E)	チューニング対応	K.Naono	03.07.09
	}else{
		m_CurveFlag = 0 ;
	}
	/** 複合図形 **/
	if (IN_AssemblyType == 2)
		m_SfigFlag = 1;	/* SfigFlag をON */
	else
		m_SfigFlag = -1;	/* SfigFlag をOFF */

	if(IN_AssemblyType == 3 &&
		((Ccurve_Org_Struct*)IN_Struct)->flag == 0 ){
		m_CurveViewFlag = 0;	/* CurveViewFlag をON */
	}else{
		m_CurveViewFlag = 1;	/* CurveViewFlag をOFF */
	}
	/** アセンブリ構造体をセット **/
	m_CurrentAssembly->SetStructData(IN_AssemblyType,IN_Struct);

	return m_AssemblyCode;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFWriteManagerC.cpp                    作成日：2001.06.18
//
//  １．機能概要
//      Feature要素構造体の登録
//
//  ２．インターフェース
//      int RegisterFeature(char* IN_FeatureType,LPVOID IN_Struct)
//
//	    引数: 型			  引数名			    内容
//            char*          IN_FeatureType        Feature要素の
//                                                 TypeName
//            LPVOID          IN_Struct            Feature要素の
//                                                 構造体のアドレス
//      
//	    復帰値	
//            正常時：要素のID
//			  異常時：その他-1
//      
//  ３．履歴
//	    履歴番号    日付け         担当者    概要
//      作成		2001.06.18    佐々木(FQS)
//
//------------------------------------------------------------

int SXFWriteManagerC::RegisterFeature(char* IN_FeatureType,LPVOID IN_Struct)
{
	/* アセンブリ要素が開かれていない */
	if (m_AssemType == -1){
		SXFErrorMsgC::RecordError(SXFNOTASSEMBLY,IN_FeatureType,0);
		return SXFNOTASSEMBLY;
	}
	/* Mapping管理ｵﾌﾞｼﾞｪｸﾄを生成 */
	m_CurrentChild = new SXFWriteMappingManagerC(m_Part21File,m_TableManager,
								m_AssemType,&m_AssemblyTable,&m_PointTable,
//	MOD(S)	チューニング対応	K.Naono	03.07.08
//								&m_SfigorgTable,m_ComInfo,m_WriteFile,m_InstanceIDManager);
								&m_mapSfigOrg,m_ComInfo,m_WriteFile,m_InstanceIDManager);
//	MOD(E)	チューニング対応	K.Naono	03.07.08

	int childid1=-1;
	int childid2=-1;
	if (!m_CurrentChild->MappingFeature(IN_FeatureType,IN_Struct,childid1,
								childid2,m_PointX,m_PointY,m_PointN))
		return childid1;

//	MOD(S)	Ver3.0対応	K.Naono	04.01.30
//	if (childid1 != -1)
	if (childid1 != -1 && childid1 != 0 )
//	MOD(E)	Ver3.0対応	K.Naono	04.01.30
		m_ChildrenArray->Add(childid1);
	if (childid2 != -1)
		m_ChildrenArray->Add(childid2);

	delete	m_CurrentChild;
	m_CurrentChild = NULL;

	return childid1;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFWriteManagerC.cpp                    作成日：2001.06.18
//
//  １．機能概要
//      Sheet Assembly 要素の出力
//
//  ２．インターフェース
//      BOOL CloseAssembly()
//
//	    引数: 型			  引数名			    内容
//      		なし
//
//	    復帰値	
//            正常時：TRUE
//			  異常時：FALSE
//      
//  ３．履歴
//	    履歴番号    日付け         担当者    概要
//      作成		2001.06.18    佐々木(FQS)
//
//------------------------------------------------------------

BOOL SXFWriteManagerC::CloseAssembly()
{
	/* 用紙が設定されていない */
	if( m_SheetAssemblyFlag != TRUE){
		SXFErrorMsgC::RecordError(SXFNOTSETSHEET,DEF_SHEET,0);
		return FALSE;//no sheet assembly
	}

	//assembly have not child error
	if (m_ChildrenArray->GetSize() <= 0){
		SXFErrorMsgC::RecordError(SXFNOTFEATURE,"",0);
		return FALSE;
	}

	int assemblyid1 = 0;
	int assemblyid2 = 0;
	int pointid = 0;
	double pointx = 0.0;
	double pointy = 0.0;
	/* アセンブリ要素のMapping */
	if(! m_CurrentAssembly->MappingAssembly(m_ChildrenArray,
			assemblyid1, assemblyid2, pointid, pointx, pointy ))
		return FALSE;

	return TRUE;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFWriteManagerC.cpp                    作成日：2001.06.18
//
//  １．機能概要
//      Assembly Typeの取得
//
//  ２．インターフェース
//      int GetAssemType()
//
//	    引数: 型			  引数名			    内容
//      		なし
//
//	    復帰値	
//            正常時：Assembly Type
//			  異常時：
//      
//  ３．履歴
//	    履歴番号    日付け         担当者    概要
//      作成		2001.06.18    佐々木(FQS)
//
//------------------------------------------------------------
int SXFWriteManagerC::GetAssemType()
{
	return m_AssemType;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFWriteManagerC.cpp                    作成日：2001.06.18
//
//  １．機能概要
//      同じSfig Assembly登録することがあるかどかのCheck
//
//  ２．インターフェース
//      BOOL CheckSameSfig( LPCTSTR IN_Name)
//
//	    引数: 型			  引数名			    内容
//            LPCTSTR         IN_Name              Sfig Name
//
//	    復帰値	
//            正常時：TRUE
//			  異常時：FALSE
//      
//  ３．履歴
//	    履歴番号    日付け         担当者    概要
//      作成		2001.06.18    佐々木(FQS)
//
//------------------------------------------------------------
BOOL SXFWriteManagerC::CheckSameSfig( LPCTSTR IN_Name)
{
//	MOD(S)	チューニング対応	K.Naono	03.07.08
/*
	for(int i=0;i<m_SfigorgTable.GetSize();i++){
		if(IN_Name == m_SfigorgTable[i].name)
			return FALSE;
	}
*/
	SXFSFIGORGCHECK*	pSfigOrg = NULL ;
	if( m_mapSfigOrg.Lookup(IN_Name, (void*&)pSfigOrg) ) {
		return FALSE;
	}
//	MOD(S)	チューニング対応	K.Naono	03.07.08

	return TRUE;
}

//	DEL(S)	チューニング対応	K.Naono	03.07.08
/*
//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFWriteManagerC.cpp                    作成日：2001.06.18
//
//  １．機能概要
//      同じSfig Assembly登録することがあるかどかのCheck
//
//  ２．インターフェース
//      BOOL CheckSameSfig( LPCTSTR IN_Name)
//
//	    引数: 型			  引数名			    内容
//            LPCTSTR         IN_Name              Sfig Name
//
//	    復帰値	
//            正常時：TRUE
//			  異常時：FALSE
//      
//  ３．履歴
//	    履歴番号    日付け         担当者    概要
//      作成		2001.06.18    佐々木(FQS)
//
//------------------------------------------------------------
BOOL SXFWriteManagerC::SfigNameCheck( LPCTSTR IN_Name)
{
	for(int i=0;i<m_SfigorgTable.GetSize();i++){
		if ( m_SfigorgTable[i].name == IN_Name && m_SfigorgTable[i].error == 1){ 
			return TRUE;
		}
	}
	return FALSE;

}
*/
//	DEL(E)	チューニング対応	K.Naono	03.07.08

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFWriteManagerC.cpp                    作成日：2001.06.18
//
//  １．機能概要
//      Invisibility要素のMapping
//
//  ２．インターフェース
//      BOOL MappingInvisibility()
//
//	    引数: 型			  引数名			    内容
//				なし
//
//	    復帰値	
//            正常時：TRUE
//			  異常時：FALSE
//      
//  ３．履歴
//	    履歴番号    日付け         担当者    概要
//      作成		2001.06.18    佐々木(FQS)
//
//------------------------------------------------------------
BOOL SXFWriteManagerC::MappingInvisibility()
{

	if (m_InvisibilityCurveTable.GetSize() > 0){
		SXFWriteMappingManagerC* mappingmanager = new SXFWriteMappingManagerC(m_Part21File); 
		if( !mappingmanager->MappingInvisibility(&m_InvisibilityCurveTable)) {
			delete mappingmanager;
			return FALSE;
		}
		delete mappingmanager;
		return TRUE;
	}
	else
		return FALSE;

}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFWriteManagerC.cpp                    作成日：2001.06.18
//
//  １．機能概要
//      アセンブリ要素の構造体がエラーだった場合の処理
//      setされているアセンブリをMappingする
//
//  ２．インターフェース
//      int ErrorAssembly()
//
//	    引数: 型			  引数名			    内容
//				なし
//
//	    復帰値	
//            正常時：1
//			  異常時：-1
//      
//  ３．履歴
//	    履歴番号    日付け         担当者    概要
//      作成		2001.06.18    佐々木(FQS)
//		更新		2001.09.18		K.Naono		ハッチング障害対応
//
//------------------------------------------------------------
int SXFWriteManagerC::ErrorAssembly()
{
	//アセンブリは開かない
	m_AssemType = -1;
	//assembly must have children
	if ( m_ChildrenArray !=NULL && m_ChildrenArray->GetSize() > 0){
		int assemblyid1 = 0;
		int assemblyid2 = 0;
		int pointid = 0;

		double pointx = 0.0;
		double pointy = 0.0;

		if( m_PointN && m_PointX )
			pointx=m_PointX/m_PointN;
		if( m_PointN && m_PointY )
			pointy=m_PointY/m_PointN;
		/* Mapping */
		if(! m_CurrentAssembly->MappingAssembly(m_ChildrenArray,
							assemblyid1, assemblyid2, pointid, pointx, pointy ))
			return -1;

		m_PointX = 0.0;
		m_PointY = 0.0;
		m_PointN = 0;

//	MOD(S)	ハッチング障害対応	K.Naono		01.09.18
//		m_PointTable.Add(pointid);
		SXF_POINT	point ;
		point.x = pointx ; point.y = pointy ;
		m_PointTable.Add(point) ;
//	MOD(E)	ハッチング障害対応	K.Naono		01.09.18
		if(m_CurveViewFlag == 0){
			m_InvisibilityCurveTable.Add(assemblyid1);
		}
		/*ｱｾﾝﾌﾞﾘﾃｰﾌﾞﾙに追加*/
		m_AssemblyTable.Add(assemblyid2);
		/*ﾃﾞｰﾀのｸﾘｱ*/
		m_ChildrenArray->RemoveAll();
	}
	else{
		if (!m_FirstAssemblyFlag && !m_ErrorFlag)
			/* アセンブリ要素上に要素がない */
			SXFErrorMsgC::RecordError(SXFNOTFEATURE,"",0);
	}

	/*ｱｾﾝﾌﾞﾘﾃﾞｰﾀをｸﾘｱ*/
	if(m_CurrentAssembly != NULL)
		m_CurrentAssembly->ClearData();

	/* ErrorFlagをON */
	m_ErrorFlag = TRUE;

	return 1;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFWriteManagerC.cpp                    作成日：2001.07.08
//
//  １．機能概要
//      既に配置されたかチェック
//
//  ２．インターフェース
//      BOOL SfigLocateCheck( LPCTSTR IN_Name)
//
//	    引数: 型			  引数名			    内容
//            LPCTSTR         IN_Name              Sfig Name
//
//	    復帰値	
//            正常時：TRUE
//			  異常時：FALSE
//      
//  ３．履歴
//	    履歴番号    日付け         担当者    概要
//      作成		2001.07.08     佐々木(FQS)
//
//------------------------------------------------------------
BOOL SXFWriteManagerC::SfigLocateCheck(LPCTSTR IN_Name)
{
//	MOD(S)	チューニング対応	K.Naono	03.07.08
/*
	for(int i=0;i<m_SfigorgTable.GetSize();i++){
		if ( m_SfigorgTable[i].name == IN_Name){
			if (m_SfigorgTable[i].locate_flag == -1){
				m_SfigorgTable[i].locate_flag = 1;
				return TRUE;
			}
		}
	}
*/
	SXFSFIGORGCHECK*	pSfigOrg = NULL ;
	if( m_mapSfigOrg.Lookup(IN_Name, (void*&)pSfigOrg) ) {
		if( pSfigOrg->locate_flag == -1 ) {
			pSfigOrg->locate_flag = 1 ;
			return TRUE ;
		}
	}
//	MOD(E)	チューニング対応	K.Naono	03.07.08
	return FALSE;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFWriteManagerC.cpp                    作成日：2001.2.23
//
//  １．機能概要
//      複合図形名に対応する複合図形種別を取得する
//
//  ２．インターフェース
//      BOOL GetSfigFlg( LPCTSTR IN_Name,
//							int* OUT_Type,
//							int* OUT_LocFlg)
//
//	    引数: 型			  引数名	    内容
//            LPCTSTR         IN_Name       Sfig Name
//			  int*			  OUT_Type		複合図形種別
//			  int*			  OUT_LocFlg	配置フラグ
//											(0：未配置 1:配置済)
//
//	    復帰値	
//            正常時：TRUE		対応する種別あり
//			  異常時：FALSE		対応する種別なし
//      
//  ３．履歴
//	    履歴番号    日付け         担当者    概要
//      作成		2001.2.23	   佐々木(FQS)(FQS)
//
//------------------------------------------------------------
BOOL SXFWriteManagerC::GetSfigFlg( LPCTSTR IN_Name,
									int* OUT_Type,
									int* OUT_LocFlg)
{
	*OUT_Type = -1;
	*OUT_LocFlg = -1;

//	MOD(S)	チューニング対応	K.Naono	03.07.08
/*
	for(int i=0;i<m_SfigorgTable.GetSize();i++){
		if ( m_SfigorgTable[i].name == IN_Name 
					&& m_SfigorgTable[i].error == 1){ 
			*OUT_Type = m_SfigorgTable[i].type;
			*OUT_LocFlg = m_SfigorgTable[i].locate_flag;
			return TRUE;
		}
	}
*/
	SXFSFIGORGCHECK*	pSfigOrg = NULL ;
	if( m_mapSfigOrg.Lookup(IN_Name, (void*&)pSfigOrg) ) {
		if( pSfigOrg->error == 1 ) {
			*OUT_Type	= pSfigOrg->type ;
			*OUT_LocFlg	= pSfigOrg->locate_flag ;
			return TRUE ;
		}
	}
//	MOD(E)	チューニング対応	K.Naono	03.07.08
	return FALSE;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFWriteManagerC.cpp                    作成日：2001.2.23
//
//  １．機能概要
//      複合図形名に対応する複合図形種別を取得する
//
//  ２．インターフェース
//      BOOL SetLocFlg( LPCTSTR IN_Name)
//
//	    引数: 型			  引数名	    内容
//            LPCTSTR         IN_Name       Sfig Name
//
//	    復帰値	
//            正常時：TRUE		対応するフラグあり
//			  異常時：FALSE		対応するフラグなし
//      
//  ３．履歴
//	    履歴番号    日付け         担当者		概要
//      作成		2001.2.23		佐々木(FQS)(FQS)
//
//------------------------------------------------------------
BOOL SXFWriteManagerC::SetLocFlg( LPCTSTR IN_Name)
{
//	MOD(S)	チューニング対応	K.Naono	03.07.08
/*
	for(int i=0;i<m_SfigorgTable.GetSize();i++){
		if ( m_SfigorgTable[i].name == IN_Name 
			&& m_SfigorgTable[i].error == 1){ 
			m_SfigorgTable[i].locate_flag = 1;
			return TRUE;
		}
	}
*/
	SXFSFIGORGCHECK*	pSfigOrg = NULL ;
	if( m_mapSfigOrg.Lookup(IN_Name, (void*&)pSfigOrg) ) {
		if( pSfigOrg->error == 1 ) {
			pSfigOrg->locate_flag = 1 ;
			return TRUE ;
		}
	}
//	MOD(E)	チューニング対応	K.Naono	03.07.08
	return FALSE;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFWriteManagerC.cpp                    作成日：2001.2.23
//
//  １．機能概要
//      ﾊｯﾁﾝｸﾞ外形・中抜きIDが定義されているかチェックする
//
//  ２．インターフェース
//      BOOL CheckHatchID( int IN_ID)
//
//	    引数: 型	引数名	    内容
//            int   IN_ID       ﾊｯﾁﾝｸﾞの外形中抜きのID
//								(複合曲線のｱｾﾝﾌﾞﾘｺｰﾄﾞ)
//
//	    復帰値	
//            正常時：TRUE		ﾊｯﾁﾝｸﾞの外形が定義されている
//			  異常時：FALSE		ﾊｯﾁﾝｸﾞの外形が定義されていない
//      
//  ３．履歴
//	    履歴番号    日付け         担当者		概要
//      作成		2001.2.23		佐々木(FQS)(FQS)
//
//------------------------------------------------------------
BOOL SXFWriteManagerC::CheckHatchID( unsigned int IN_ID){
//	MOD(S)	チューニング対応	K.Naono	03.07.09
/*
	for (int i = 0; i < m_CurveTable.GetSize(); i++){
		if (m_CurveTable[i] == IN_ID)
			return TRUE;
	}
*/
	for(POSITION pos = m_CurveTable.GetHeadPosition(); pos; ) {
		if( m_CurveTable.GetNext(pos) == (int)IN_ID ) {
			return TRUE ;
		}
	}
//	MOD(E)	チューニング対応	K.Naono	03.07.09
	return FALSE;
}
