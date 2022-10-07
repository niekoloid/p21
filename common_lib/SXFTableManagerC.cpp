//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp					作成日：2001.06.10
// 
//	１．クラス概要
//		定義テーブルデータ値と定義テーブルMapping管理
//		オブジェクトのアドレスを保持し、定義テーブル
//		Mapping管理オブジェクトを管理する
//
//	２．履歴
//		履歴番号	日付け		   担当者	 概要
//		作成		2001.06.10	   佐々木(FQS)
//
//------------------------------------------------------------
#include "stdafx.h"
#include <math.h>
#include "SXFDataStructC.h"
//#include "SXFSplitAP202C.h"
#include "SXFComncApi.h"
#include "SXFMapEntAConvC.h"
#include "SXFPreWidthTableC.h"
#include "SXFTableManagerC.h"
#include "SXFStruct.h"
#include "SXFTableMapManagerC.h"
#include "SXFPart21FileC.h"
#include "SXFErrorMsgC.h"
#include "SXF_EXT.h"
//#include "ComSplitStringC.h"
#include "SXFComncApi.h"
#include "SXFComInfoC.h"
#include "SXFPart21FileWriteC.h"
#include "SXFInstanceIDC.h"
//#include "SXFSplitFeatureC.h"
#include "SXFRGBTableC.h"
#include "SXFPreLineTypeTableC.h"
#include "SXFMapTableC.h"
#include "SXFComndef.h"
#include "SXFEntityDataC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp					作成日：2001.06.10
//
//	１．機能概要
//		クラス構築
//
//	２．インターフェース
//		void	SXFTableManagerC::SXFTableManagerC()
//	引数:	型								引数名				内容
//			なし					
//
//	３．履歴
//		履歴番号	日付け		   担当者	 概要
//		作成		2001.06.10	   佐々木(FQS)
//
//------------------------------------------------------------

SXFTableManagerC::SXFTableManagerC()
{
	m_LayerFirstFlag = TRUE;
	m_CurrentType=0;
	m_CurrentNumber=0;
	for(int i=0;i<10;i++)
		m_PreDefWidthFlagTable[i]=0;
	userdefwidthcode=11;		/* ﾕｰｻﾞ定義線幅ｺｰﾄﾞは11～ */

	// TableCodeのHASH用に追加：
	m_TableCodeElemMapInitialized = FALSE;

//	ADD(S)	チューニング対応	K.Naono	03.07.03
	m_AP202IDTable.SetSize(0, 100) ;
//	ADD(E)	チューニング対応	K.Naono	03.07.03

//	ADD(S)	Ver3.0対応	K.Naono	04.01.30
	m_Attribute_Str = NULL ;
	m_id_draug_drw_rev = -1 ;
//	ADD(E)	Ver3.0対応	K.Naono	04.01.30
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp					作成日：2001.06.10
//
//	１．機能概要
//		クラス構築
//
//	２．インターフェース
//	void SXFTableManagerC::SXFTableManagerC(SXFComInfoC* IN_CommonInfo)
//		
//	引数 ：	型				引数名			内容
//			SXFComInfoC*	IN_CommonInfo	共通情報ｵﾌﾞｼﾞｪｸﾄ
//
//	３．履歴
//		履歴番号	日付け		   担当者	 概要
//		作成		2001.06.10	   佐々木(FQS)
//
//------------------------------------------------------------
SXFTableManagerC::SXFTableManagerC(SXFComInfoC* IN_CommonInfo)
{
	m_ComInfo = IN_CommonInfo;
	m_LayerFirstFlag = TRUE;
	m_CurrentType=0;
	m_CurrentNumber=0;
	for(int i=0;i<10;i++)
		m_PreDefWidthFlagTable[i]=0;
	userdefwidthcode=11;

	// TableCodeのHASH用に追加：
	m_TableCodeElemMapInitialized = FALSE;

//	ADD(S)	チューニング対応	K.Naono	03.07.03
	m_AP202IDTable.SetSize(0, 100) ;
//	ADD(E)	チューニング対応	K.Naono	03.07.03

//	ADD(S)	Ver3.0対応	K.Naono	04.01.30
	m_Attribute_Str = NULL ;
	m_id_draug_drw_rev = -1 ;
//	ADD(E)	Ver3.0対応	K.Naono	04.01.30
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp					作成日：2001.06.10
//
//	１．機能概要
//		クラス構築
//
//	２．インターフェース
//	void SXFTableManagerC::SXFTableManagerC(SXFPart21FileC* IN_File)
//
//		
//	引数 ：	型					  引数名				内容
//			SXFPart21FileC*		  IN_File			ファイル名
//
//	３．履歴
//		履歴番号	日付け		   担当者	 概要
//		作成		2001.06.10	   佐々木(FQS)
//
//------------------------------------------------------------
SXFTableManagerC::SXFTableManagerC(SXFPart21FileC* IN_File)
{
	m_LayerFirstFlag = TRUE;
	m_File = IN_File;
	m_CurrentType=0;
	m_CurrentNumber=0;
	for(int i=0;i<10;i++)
		m_PreDefWidthFlagTable[i]=0;
	userdefwidthcode=11;		/* ﾕｰｻﾞ定義線幅ｺｰﾄﾞは11～ */

	// TableCodeのHASH用に追加：
	m_TableCodeElemMapInitialized = FALSE;

//	ADD(S)	Ver3.0対応	K.Naono	04.01.30
	m_Attribute_Str = NULL ;
	m_id_draug_drw_rev = -1 ;
//	ADD(E)	Ver3.0対応	K.Naono	04.01.30
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp					作成日：2001.06.10
//
//	１．機能概要
//		クラス構築
//
//	２．インターフェース
//	void SXFTableManagerC::SXFTableManagerC(
//								SXFPart21FileC* IN_File,	
//								SXFComInfoC* IN_CommonInfo,
//								SXFPart21FileWriteC* IN_WriteFile,
//								SXFInstanceIDC* IN_InstanceIDManager)
//
//		
//	引数 ：	型					  引数名				内容
//			SXFPart21FileC* 	  IN_File				ﾌｧｲﾙｵﾌﾞｼﾞｪｸﾄのｱﾄﾞﾚｽ
//			SXFComInfoC*		  IN_CommonInfo			共通情報ｵﾌﾞｼﾞｪｸﾄのｱﾄﾞﾚｽ
//			SXFPart21FileWriteC*  IN_WriteFile			ﾌｧｲﾙ出力ｵﾌﾞｼﾞｪｸﾄのｱﾄﾞﾚｽ
//			SXFInstanceIDC*		  IN_InstanceIDManager	ｲﾝｽﾀﾝｽIDｵﾌﾞｼﾞｪｸﾄのｱﾄﾞﾚｽ
//
//	３．履歴
//		履歴番号	日付け		   担当者	 概要
//		作成		2001.06.10	   佐々木(FQS)
//
//------------------------------------------------------------
SXFTableManagerC::SXFTableManagerC(SXFPart21FileC* IN_File,
					SXFComInfoC* IN_CommonInfo,
					SXFPart21FileWriteC* IN_WriteFile,
					SXFInstanceIDC* IN_InstanceIDManager)
{
	m_File = IN_File;
	m_WriteFile= IN_WriteFile;
	m_ComInfo=IN_CommonInfo;
	m_InstanceIDManager=IN_InstanceIDManager;
	m_LayerFirstFlag = TRUE;
	m_CurrentType=0;
	m_CurrentNumber=0;
	for(int i=0;i<10;i++)
		m_PreDefWidthFlagTable[i]=0;
	userdefwidthcode=11;		/* ﾕｰｻﾞ定義線幅ｺｰﾄﾞは11～ */

	// TableCodeのHASH用に追加：
	m_TableCodeElemMapInitialized = FALSE;

//	ADD(S)	チューニング対応	K.Naono	03.07.03
	m_AP202IDTable.SetSize(0, 100) ;
//	ADD(E)	チューニング対応	K.Naono	03.07.03

//	ADD(S)	Ver3.0対応	K.Naono	04.01.30
	m_Attribute_Str = NULL ;
	m_id_draug_drw_rev = -1 ;
//	ADD(E)	Ver3.0対応	K.Naono	04.01.30
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp					作成日：2001.06.10
//
//	１．機能概要
//		クラス構築
//
//	２．インターフェース
//SXFTableManagerC::SXFTableManagerC(SXFComInfoC* IN_CommonInfo
//									SXFInstanceIDC* IN_InstanceIDManager)
//
//		
//	引数 ：	型					  引数名				内容
//			SXFComInfoC*		  IN_CommonInfo			共通情報ｵﾌﾞｼﾞｪｸﾄのｱﾄﾞﾚｽ
//			SXFInstanceIDC*		  IN_InstanceIDManager	ｲﾝｽﾀﾝｽIDｵﾌﾞｼﾞｪｸﾄのｱﾄﾞﾚｽ
//
//	３．履歴
//		履歴番号	日付け		   担当者	 概要
//		作成		2001.06.10	   佐々木(FQS)
//
//------------------------------------------------------------
SXFTableManagerC::SXFTableManagerC(SXFComInfoC* IN_CommonInfo,SXFInstanceIDC* IN_InstanceIDManager){
	m_File = NULL;
	m_WriteFile= NULL;
	m_ComInfo=IN_CommonInfo;
	m_InstanceIDManager=IN_InstanceIDManager;
	m_LayerFirstFlag = TRUE;
	m_CurrentType=0;
	m_CurrentNumber=0;
	for(int i=0;i<10;i++)
		m_PreDefWidthFlagTable[i]=0;
	userdefwidthcode=11;		/* ﾕｰｻﾞ定義線幅ｺｰﾄﾞは11～ */

	// TableCodeのHASH用に追加：
	m_TableCodeElemMapInitialized = FALSE;

//	ADD(S)	チューニング対応	K.Naono	03.07.03
	m_AP202IDTable.SetSize(0, 100) ;
//	ADD(E)	チューニング対応	K.Naono	03.07.03

//	ADD(S)	Ver3.0対応	K.Naono	04.01.30
	m_Attribute_Str = NULL ;
	m_id_draug_drw_rev = -1 ;
//	ADD(E)	Ver3.0対応	K.Naono	04.01.30
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp					作成日：2001.06.10
//
//	１．機能概要
//		クラス消滅
//
//	２．インターフェース
//	void	SXFTableManagerC::~SXFTableManagerC()
//	引数:	型						引数名				内容
//			なし					
//
//	３．履歴
//		履歴番号	日付け		   担当者	 概要
//		作成		2001.06.10	   佐々木(FQS)
//
//------------------------------------------------------------

SXFTableManagerC::~SXFTableManagerC()
{

	//delete mapping class in layer table
	for(int i=0;i<m_LayerTable.GetSize();i++){
		if(m_LayerTable[i].m_MappingManager!=NULL)
			delete m_LayerTable[i].m_MappingManager;
	}

	//delete mapping class in predefcolor table
	for( i=0;i<16;i++){
		if(m_PreDefColorTable[i].m_MappingManager!=NULL)
			delete m_PreDefColorTable[i].m_MappingManager;
	}

	//delete mapping class in userdefcolor table
	for( i=0;i<m_UserDefColorTable.GetSize();i++){
		if(m_UserDefColorTable[i].m_MappingManager!=NULL)
			delete m_UserDefColorTable[i].m_MappingManager;
	}

	//delete mapping class in predeffont table
	for( i=0;i<16;i++){
		if(m_PreDefFontTable[i].m_MappingManager!=NULL)
			delete m_PreDefFontTable[i].m_MappingManager;
	}

	//delete mapping class in userdeffont table
	for( i=0;i<m_UserDefFontTable.GetSize();i++){
		if(m_UserDefFontTable[i].m_MappingManager!=NULL)
			delete m_UserDefFontTable[i].m_MappingManager;
	}

	//delete mapping class in width table
	for(i=0;i<16;i++){
		if(m_WidthTable[i].m_MappingManager!=NULL)
			delete m_WidthTable[i].m_MappingManager;
	}

	//delete mapping class in textfont table
	for(i=0;i<m_TextFontTable.GetSize();i++){
		if(m_TextFontTable[i].m_MappingManager!=NULL)
			delete m_TextFontTable[i].m_MappingManager;
	}

	for(i=0;i<m_PresentationSizeTable.GetSize();i++){
		if(m_PresentationSizeTable[i]!=NULL)
			delete m_PresentationSizeTable[i];
	}

	for(i=0;i<m_SheetTitleTable.GetSize();i++){
		if(m_SheetTitleTable[i]!=NULL)
			delete m_SheetTitleTable[i];
	}

//	ADD(S)	Ver3.0対応	K.Naono	04.01.30
	if( m_Attribute_Str != NULL )
		delete m_Attribute_Str ;

	for(i = 0; i < m_AttributeTable.GetSize(); i++) {
		delete m_AttributeTable[i] ;
	}
	m_AttributeTable.RemoveAll() ;

	m_id_draug_drw_rev = -1 ;
//	ADD(E)	Ver3.0対応	K.Naono	04.01.30
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp					作成日：2001.06.10
//
//	１．機能概要
//		Table 要素の構造体を登録する
//		
//	２．インターフェース
//		int RegisterStructTable( int IN_Type, LPVOID IN_Struct)
//
//		引数: 型			  引数名				内容
//			  int			  IN_Type			   構造体のType
//			  LPVOID		  IN_Struct			   構造体のアドレス
//													
//		
//		復帰値	
//			  正常時： Table 要素のCode
//			  異常時： -1
//
//	３．履歴
//		履歴番号	日付け		   担当者	 概要
//		作成		2001.06.10	   佐々木(FQS)
//
//------------------------------------------------------------
int SXFTableManagerC::RegisterStructTable( int IN_Type, LPVOID IN_Struct)
{
	int return_code;
	SXFTableMapManagerC* mappingmanager; 
	SXFLayerC layer;
	SXFPreDefColorC predefcolor;
	SXFUserDefColorC userdefcolor;
	SXFPreDefFontC predeffont;
	SXFUserDefFontC userdeffont;
	SXFWidthC width;
	double inwidth;
	int resaultcode;
	SXFTextFontC textfont;
	int i = 0;
	INT_PTR layersize;
	INT_PTR usercolorsize;
	INT_PTR userfontsize;
	INT_PTR textfontsize;
	double eps1,eps2;
	CString tmp_font_name;
	CString decent_tmp;
	CString ascent_tmp;
	double ascent = 1.0;
	double decent = 0.0;
	int find1,find2;

	switch(IN_Type)
	{
	/** レイヤ **/
	case 1:
		if (m_LayerFirstFlag){
			//複合図形配置用のレイヤ０を作成
			layer.m_Code = 0;
			layer.m_Name = "$$SXF_dummy_layer_for_subfigure";
			layer.m_LfFlag = 1;
			mappingmanager = new SXFTableMapManagerC(m_File,m_ComInfo,m_WriteFile,m_InstanceIDManager);
			layer.m_MappingManager = mappingmanager;
			m_LayerTable.Add(layer);
			m_LayerFirstFlag = FALSE;
		}
		/* ﾚｲﾔﾃｰﾌﾞﾙｻｲｽﾞ */
		layersize = m_LayerTable.GetSize();
		/* 最大ﾚｲﾔ数を超えたとき */
		if (layersize > MAXLAYER){// max layer code = 1024 
			SXFErrorMsgC::RecordError(SXFMAXLAYER,DEF_LAYER,0);
			return SXFMAXLAYER;
		}
		/* ﾚｲﾔｺｰﾄﾞ */
		layer.m_Code = (int)layersize;
		/* ﾚｲﾔ名 */
		layer.m_Name = ((Layer_Struct*)IN_Struct)->name;
		/* 表示／非表示ﾌﾗｸﾞ */
		layer.m_LfFlag = ((Layer_Struct*)IN_Struct)->lflag;
		/* 定義ﾃｰﾌﾞﾙ要素Mapping管理ｵﾌﾞｼﾞｪｸﾄ生成 */
		mappingmanager = new SXFTableMapManagerC(m_File,m_ComInfo,m_WriteFile,m_InstanceIDManager);
		/* 復帰値(ﾚｲﾔｺｰﾄﾞ) */
		return_code = layer.m_Code;
		/* 定義ﾃｰﾌﾞﾙ要素Mapping管理ｵﾌﾞｼﾞｪｸﾄｾｯﾄ */
		layer.m_MappingManager = mappingmanager;
		/* ﾚｲﾔﾃｰﾌﾞﾙに追加 */
		m_LayerTable.Add(layer);
		break;
	/** 既定義色 **/
	case 2://predefcolor 16
		//既定義でない名前はエラー
		if (!predefcolor.SetName(((Predefined_Colour_Struct*)IN_Struct)->name)){
			SXFErrorMsgC::RecordError(SXFNOTPRECOLOUR,DEF_PREDEFINED_COLOUR,1,((Predefined_Colour_Struct*)IN_Struct)->name);
			return SXFNOTPRECOLOUR;
		}
		/* 定義ﾃｰﾌﾞﾙ要素Mapping管理ｵﾌﾞｼﾞｪｸﾄ生成 */
		mappingmanager = new SXFTableMapManagerC(m_File,m_ComInfo,m_WriteFile,m_InstanceIDManager);
		/* 既定義色構造体ｾｯﾄ */
		if (mappingmanager->SetStructPrecolor(IN_Type,IN_Struct,predefcolor)){
			predefcolor.m_MappingManager=mappingmanager;
			/* 既定義色ｲﾝｽﾀﾝｽ出力 */
			return_code = predefcolor.m_Code;
			mappingmanager->WriteInstance(IN_Type);
			predefcolor.m_ID = mappingmanager->GetInstanceID(IN_Type);
			m_PreDefColorTable[predefcolor.m_Code-1] = predefcolor;
		}
		else
			/* 出力失敗 */
			return_code = -1;
		break;
	/** ユーザ定義色 **/
	case 3:
		/* ﾕｰｻﾞ定義色ﾃｰﾌﾞﾙｻｲｽﾞ */
		usercolorsize = m_UserDefColorTable.GetSize();
		///ERROR
		//ユーザ定義は240色しか定義できない。
		if (usercolorsize >= MAXUSERCOLOUR){
			SXFErrorMsgC::RecordError(SXFMAXUSERCOLOUR,DEF_USERDEFINED_COLOUR,0);
			return SXFMAXUSERCOLOUR;
		}
		else{
			/* 定義ﾃｰﾌﾞﾙ要素Mapping管理ｵﾌﾞｼﾞｪｸﾄ */
			mappingmanager = new SXFTableMapManagerC(m_File,m_ComInfo,m_WriteFile,m_InstanceIDManager);
			/* 色ｺｰﾄﾞ */
			userdefcolor.m_Code = (int)(usercolorsize+17);//17------
			userdefcolor.R =((Userdefined_Colour_Struct*)IN_Struct)->red;
			userdefcolor.G =((Userdefined_Colour_Struct*)IN_Struct)->green;
			userdefcolor.B =((Userdefined_Colour_Struct*)IN_Struct)->blue;
			/* ﾕｰｻﾞ定義色構造体ｾｯﾄ */
			if (mappingmanager->SetStructData(IN_Type,IN_Struct)){
				usercolorsize = m_UserDefColorTable.GetSize();
				userdefcolor.m_MappingManager=mappingmanager;
				/* ﾕｰｻﾞ定義色ｲﾝｽﾀﾝｽ出力 */
				return_code = userdefcolor.m_Code;
				mappingmanager->WriteInstance(IN_Type);
				userdefcolor.m_ID = mappingmanager->GetInstanceID(IN_Type);
				m_UserDefColorTable.Add(userdefcolor);
			}
			else
				/* 出力失敗 */
				return_code = -1;
		}
		break;
	/** 既定義線種 **/
	case 4://predeffont
		//既定義でない名前はエラー
		if (!predeffont.SetName(((Predefined_Linetype_Struct*)IN_Struct)->name)){
			SXFErrorMsgC::RecordError(SXFNOTPRETYPE,DEF_PREDEFINED_LINETYPE,1,((Predefined_Linetype_Struct*)IN_Struct)->name);
			return SXFNOTPRETYPE;
		}
		/* 定義ﾃｰﾌﾞﾙ要素Mapping管理ｵﾌﾞｼﾞｪｸﾄ生成 */
		mappingmanager = new SXFTableMapManagerC(m_File,m_ComInfo,m_WriteFile,m_InstanceIDManager);
		/* 既定義線種構造体ｾｯﾄ */
		if (mappingmanager->SetStructData(IN_Type,IN_Struct)){
			predeffont.m_MappingManager=mappingmanager;
			/* 既定義線種ｲﾝｽﾀﾝｽ出力 */
			return_code = predeffont.m_Code;
			mappingmanager->WriteInstance(IN_Type);
			predeffont.m_ID = mappingmanager->GetInstanceID(IN_Type);
			/* 既定義線種ﾃｰﾌﾞﾙ追加 */
			m_PreDefFontTable[predeffont.m_Code-1] = predeffont;
		}
		else
			/* 出力失敗 */
			return_code = -1;
		break;
	/** ユーザ定義線種 **/
	case 5:
		/* ﾕｰｻﾞ定義線種ﾃｰﾌﾞﾙｻｲｽﾞ */
		userfontsize = m_UserDefFontTable.GetSize();
		///ERROR
		//ユーザ定義線種は32個しか定義できない。
		if (userfontsize >= MAXUSERLINETYPE){
			SXFErrorMsgC::RecordError(SXFMAXUSERLINETYPE,DEF_USERDEFINED_LINETYPE,0);
			return SXFMAXUSERLINETYPE;
		}
		else{
			/* 線種ｺｰﾄﾞ */
			userdeffont.m_Code = (int) m_UserDefFontTable.GetSize()+17;//17---
			/* 線種名 */
			userdeffont.m_Name = ((Userdefined_Linetype_Struct*)IN_Struct)->name;
			/* ｾｸﾞﾒﾝﾄ数 */
			userdeffont.m_Segment=((Userdefined_Linetype_Struct*)IN_Struct)->segment;
			/* ﾋﾟｯﾁ */
			for(i=0;i<userdeffont.m_Segment;i++)
				userdeffont.m_Pitch.Add( ((Userdefined_Linetype_Struct*)IN_Struct)->pitch[i] );
			/* 定義ﾃｰﾌﾞﾙ要素Mapping管理ｵﾌﾞｼﾞｪｸﾄ生成 */
			mappingmanager = new SXFTableMapManagerC(m_File,m_ComInfo,m_WriteFile,m_InstanceIDManager);
			/* ﾕｰｻﾞ定義線種構造体ｾｯﾄ */
			if (mappingmanager->SetStructData(IN_Type,IN_Struct)){
				/* 定義ﾃｰﾌﾞﾙ要素Mapping管理ｵﾌﾞｼﾞｪｸﾄｾｯﾄ */
				userdeffont.m_MappingManager=mappingmanager;
				/* ﾕｰｻﾞ定義線種ｲﾝｽﾀﾝｽ出力 */
				return_code = userdeffont.m_Code;
				mappingmanager->WriteInstance(IN_Type);
				/* ｲﾝｽﾀﾝｽID */
				userdeffont.m_ID = mappingmanager->GetInstanceID(IN_Type);
				/* ﾕｰｻﾞ定義線種ﾃｰﾌﾞﾙ追加 */
				m_UserDefFontTable.Add(userdeffont);
			}
			else
				/* 出力失敗 */
				return_code = -1;
		}
		break;
	/** 線幅 **/
	case 6:
		/* 線幅 */
		inwidth = ((Line_Width_Struct*)IN_Struct)->width;
		/* 許容誤差取得 */
		m_ComInfo->Get_Tolerance(eps1,eps2);
		/* 線幅から線幅ｺｰﾄﾞを求める */
		resaultcode = width.InquireCode(inwidth,eps1);
		/* 線幅に対応する線幅ｺｰﾄﾞがある(既定義) */
		if(resaultcode != 0){
			/* 既にﾃｰﾌﾞﾙ内にある */
			if(m_PreDefWidthFlagTable[resaultcode-1] == 1){
				SXFErrorMsgC::RecordError(SXFSAMEWIDTH,DEF_LINE_WIDTH,1,inwidth);
				return TRUE;//FALSEは返さない
			}

			/* 線幅ｺｰﾄﾞ */
			width.m_Code = resaultcode;
			SXFPreWidthTableC prewidthtable;
			double prewidth = 0.0;
			/* 線幅ｺｰﾄﾞから線幅を取得 */
			prewidthtable.GetPreWidth(resaultcode, prewidth); 
			width.m_Width = prewidth;
			/* 定義済みﾌﾗｸﾞをON */
			m_PreDefWidthFlagTable[resaultcode-1]=1;
		}
		//線幅に対応するコードが０のときは既定義ではない。
		else{
			//線幅が１６以上登録されていれば
			//それ以上登録できないので、エラー
			if (userdefwidthcode > MAXLINEWIDTH){//widthcode 1---16
				SXFErrorMsgC::RecordError(SXFMAXLINEWIDTH,DEF_LINE_WIDTH,0);
				return SXFMAXLINEWIDTH;
			}
			else{
				/* 線幅ｺｰﾄﾞ */
				width.m_Code = userdefwidthcode;
				userdefwidthcode++;
			}
			/* 線幅 */
			width.m_Width=inwidth;
		}
		/* 定義ﾃｰﾌﾞﾙ要素Mapping管理ｵﾌﾞｼﾞｪｸﾄ生成 */
		mappingmanager = new SXFTableMapManagerC(m_File,m_ComInfo,m_WriteFile,m_InstanceIDManager);
		/* 線幅構造体ｾｯﾄ */
		if (mappingmanager->SetStructData(IN_Type,IN_Struct)){
			width.m_MappingManager=mappingmanager;
			/* 復帰値(線幅ｺｰﾄﾞ) */
			return_code = width.m_Code;
			/* 線幅ｲﾝｽﾀﾝｽ出力 */
			mappingmanager->WriteInstance(IN_Type);
			/* 定義ﾃｰﾌﾞﾙ要素Mapping管理ｵﾌﾞｼﾞｪｸﾄｾｯﾄ */
			width.m_ID = mappingmanager->GetInstanceID(IN_Type);
			m_WidthTable[width.m_Code-1] = width;
		}
		else
			/* 出力失敗 */
			return_code = -1;
		break;
	/** 文字フォント **/
	case 7://textfont
		//ERROR
		//文字フォントは１０２４個しか登録できない
		textfontsize = m_TextFontTable.GetSize();
		if (textfontsize >= MAXTEXTFONT){//textfont 1--1024
			SXFErrorMsgC::RecordError(SXFMAXTEXTFONT,DEF_TEXT_FONT,0);
			return SXFMAXTEXTFONT;
		}
		else{
			/* 文字ﾌｫﾝﾄ名 */
			textfont.m_Name = ((Text_Font_Struct*)IN_Struct)->name;//
			if ((find1 = textfont.m_Name.ReverseFind('-')) != -1){
				tmp_font_name = textfont.m_Name.Left(find1);
				decent_tmp = textfont.m_Name.Mid(find1+1);
				if ((find2 = tmp_font_name.ReverseFind('-')) != -1){
					ascent_tmp = tmp_font_name.Mid(find2+1);
					ascent = atof(ascent_tmp);
					decent = atof(decent_tmp);
				}
			}
			textfont.m_Ascent = ascent;
			textfont.m_Decent = decent;
			/* 文字ﾌｫﾝﾄｺｰﾄﾞ */
			textfont.m_Code = (int)m_TextFontTable.GetSize()+1;
			/* 定義ﾃｰﾌﾞﾙ要素Mapping管理ｵﾌﾞｼﾞｪｸﾄ生成 */
			mappingmanager = new SXFTableMapManagerC(m_File,m_ComInfo,m_WriteFile,m_InstanceIDManager);
			/* 文字ﾌｫﾝﾄ構造体ｾｯﾄ */
			if (mappingmanager->SetStructData(IN_Type,IN_Struct)){
				/* 定義ﾃｰﾌﾞﾙ要素Mapping管理ｵﾌﾞｼﾞｪｸﾄｾｯﾄ */
				textfont.m_MappingManager=mappingmanager;
				/* 文字ﾌｫﾝﾄｺｰﾄﾞ */
				return_code = textfont.m_Code;
				/* 文字ﾌｫﾝﾄｲﾝｽﾀﾝｽ出力 */
				mappingmanager->WriteInstance(IN_Type);
				textfont.m_ID = mappingmanager->GetInstanceID(IN_Type);
				/* 文字ﾌｫﾝﾄﾃｰﾌﾞﾙに追加 */
				m_TextFontTable.Add(textfont);
			}
			else
				return_code = -1;
		}
		break;
	default:
		return_code = -1;
		break;
	}

	return return_code;
}
//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp					作成日：2001.06.10
//
//	１．機能概要
//		指定したTable要素のCodeと対応するのInstance IDを取得する
//		
//	２．インターフェース
//		int GetID(int IN_Type, int IN_Code)
//
//		引数: 型			  引数名				内容
//			  int			  IN_Type			   Table要素のType
//			  int			  IN_Code			   Table要素のCode
//													
//		
//		復帰値	
//			  正常時： Table 要素のInstance ID
//			  異常時： -1
//
//	３．履歴
//		履歴番号	日付け		   担当者	 概要
//		作成		2001.06.10	   佐々木(FQS)
//
//------------------------------------------------------------
int SXFTableManagerC::GetID(int IN_Type, int IN_Code)
{
	if(IN_Code<1)  //code must >=1
		return -1;

	int getid=-1;
	int RW_Flag = -1;
	/* 読書きﾌﾗｸﾞ取得 */
	m_ComInfo->Get_RWFlag(RW_Flag);

	switch (IN_Type)
	{
	case 1://layer
		if(IN_Code>=m_LayerTable.GetSize())
			return -1;//layer code not register
		getid = m_LayerTable[IN_Code].m_LfFlag;//テーブルに登録されていなければ初期値-１
		break;
	case 2://predefcolor
		if(IN_Code>16)
			return -1;//predefcolor must <= 16
		getid = m_PreDefColorTable[IN_Code-1].m_ID;
		break;
	case 3://userdefcolor
		if(IN_Code<17 || IN_Code>=m_UserDefColorTable.GetSize()+17)
			return -1;//userdefcolor code must 17---256
		//or user def color not register
		getid=m_UserDefColorTable[IN_Code-17].m_ID;
		break;
	case 4://predeffont
		if(IN_Code>16)
			return -1;//predeffont code must <=16
		getid = m_PreDefFontTable[IN_Code-1].m_ID;
		break;
	case 5://userdeffont
		if(IN_Code<17 || IN_Code>=m_UserDefFontTable.GetSize()+17)
			return -1;//user def font code 17---32
		//or user def font not register
		getid = m_UserDefFontTable[IN_Code-17].m_ID;
		break;
	case 6://width
		if(IN_Code>16)
			return -1;//width code 1--16
		getid=m_WidthTable[IN_Code-1].m_ID;
		break;
	case 7://textfont
		if(IN_Code>m_TextFontTable.GetSize())
			return -1;//text font must 1--1024
		//text font not register
		getid=m_TextFontTable[IN_Code-1].m_ID;
		break;
	default:
		break;
	}
	return getid;//-1:error, ID:OK
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp					作成日：2001.06.10
//
//	１．機能概要
//		指定したTable要素のInstance IDと対応するのCodeを取得する
//		
//	２．インターフェース
//		int GetCode(int IN_Type, int IN_ID)
//
//		引数: 型			  引数名				内容
//			  int			  IN_Type			   Table要素のType
//			  int			  IN_ID				   Table要素のInstance ID
//													
//		
//		復帰値	
//			  正常時： Table 要素の Code
//			  異常時： -1
//
//	３．履歴
//		履歴番号	日付け		   担当者	 概要
//		作成		2001.06.10	   佐々木(FQS)
//
//------------------------------------------------------------

int SXFTableManagerC::GetCode(int IN_Type, int IN_ID)
{
	int getcode=-1;
	int i = 0;
	switch (IN_Type)
	{
	case 1://layer
		for(i=0;i<m_LayerTable.GetSize();i++){
			if(m_LayerTable[i].m_ID == IN_ID){
				getcode=i;
				return getcode;
			}
		}
		break;//layer ID not register
	case 2://predefcolor
		for(i=0;i<16;i++){
			if(m_PreDefColorTable[i].m_ID == IN_ID){
				getcode = i+1;
				return getcode;
			}
		}
		break;//predefcolot ID not register
	case 3://userdefcolor
		for(i=0;i<m_UserDefColorTable.GetSize();i++){ //0---(256-16)
			if(m_UserDefColorTable[i].m_ID == IN_ID){
				getcode = i+16+1;
				return getcode;
			}
		}
		break;//userdefcolor ID not register
	case 4://predeffont
		for(i=0;i<16;i++){
			if(m_PreDefFontTable[i].m_ID == IN_ID){
				getcode = i+1;
				return getcode;
			}
		}
		break;//predeffont not register
	case 5://userdeffont
		for(i=0;i<m_UserDefFontTable.GetSize();i++){//0----(32-16)
			if(m_UserDefFontTable[i].m_ID == IN_ID){
				getcode = i+16+1;
				return getcode;
			}
		}
		break;//userdeffont not register
	case 6://width
		for(i=0;i<16;i++){
			if(m_WidthTable[i].m_ID == IN_ID){
				getcode = i+1;
				return getcode;
			}
		}
		break;
	case 7://textfont
		for(i=0;i<m_TextFontTable.GetSize();i++){
			if(m_TextFontTable[i].m_ID == IN_ID){
				getcode = i+1;
				return getcode;
			}
		}
		break;
	default:
		break;
	}

	return getcode;//-1:error,Code:OK

}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp					作成日：2001.06.10
//
//	１．機能概要
//		指定したLayer要素のElementTableにElement要素を登録する
//		
//	２．インターフェース
//		BOOL SetLayerElement(int IN_LayerCode, int IN_ElementID)
//
//		引数: 型			  引数名				内容
//			  int			  IN_LayerCode		   Layer要素のCode
//			  int			  IN_ElementID		   Layer要素のElement要素の
//												   Instance ID
//													
//		
//		復帰値	
//			  正常時： TRUE
//			  異常時： FALSE
//		
//	３．履歴
//		履歴番号	日付け		   担当者	 概要
//		作成		2001.06.10	   佐々木(FQS)
//
//------------------------------------------------------------

BOOL SXFTableManagerC::SetLayerElement(int IN_LayerCode, int IN_ElementID)
{
	if(IN_LayerCode>m_LayerTable.GetSize()-1){
		//error layercode is not register
		return FALSE;
	}

	m_LayerTable[IN_LayerCode].m_Element.Add(IN_ElementID);

	return TRUE;
}
//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp					作成日：2001.06.10
//
//	１．機能概要
//		全部のLayer要素にSheet IDを登録する
//		
//	２．インターフェース
//		BOOL SetLayerSheetID( int IN_SheetID)
//
//		引数: 型			  引数名				内容
//			  int			  IN_SheetID		   Sheet要素
//												   Instance ID
//													
//		
//		復帰値	
//			  正常時： TRUE
//			  異常時： FALSE
//		
//	３．履歴
//		履歴番号	日付け		   担当者	 概要
//		作成		2001.06.10	   佐々木(FQS)
//
//------------------------------------------------------------

BOOL SXFTableManagerC::SetLayerSheetID( int IN_SheetID)
{

	for(int i=0;i<m_LayerTable.GetSize();i++){
		m_LayerTable[i].m_SheetID = IN_SheetID;
	}
	return TRUE;
}
//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp					作成日：2001.06.10
//
//	１．機能概要
//		指定したのText Fontの属性を取得する
//		
//	２．インターフェース
//		BOOL GetTextFontProperty(int IN_Code, 
//								 double& OUT_Ascent,
//								 double& OUT_Decent)
//
//		引数: 型			  引数名				内容
//			  int			  IN_Code			   Text Font要素の
//												   Code
//			  double&		  OUT_Ascent		   Ascent属性
//			  double&		  OUT_Decent		   Decent属性
//													
//		
//		復帰値	
//			  正常時： TRUE
//			  異常時： FALSE
//		
//	３．履歴
//		履歴番号	日付け		   担当者	 概要
//		作成		2001.06.10	   佐々木(FQS)
//
//------------------------------------------------------------

BOOL SXFTableManagerC::GetTextFontProperty(int IN_Code, 
											double& OUT_Ascent,
											double& OUT_Decent)
{
	if(IN_Code<1)  //code must >=1
		return FALSE;
	if(IN_Code>m_TextFontTable.GetSize()){
		//error, textfont code is not register
		return FALSE;
	}

	OUT_Ascent = m_TextFontTable[IN_Code-1].m_Ascent;
	OUT_Decent = m_TextFontTable[IN_Code-1].m_Decent;

	return TRUE;

}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp					作成日：2001.06.10
//
//	１．機能概要
//		指定したLayer Nameが定義されているかチェック
//		
//	２．インターフェース
//		BOOL CheckSameLayer( LPCTSTR IN_Name)
//
//		引数: 型			  引数名				内容
//			  LPCTSTR		 IN_Name			   Layer Name						 
//		
//		復帰値	
//			  正常時： TRUE
//			  異常時： FALSE
//		
//
//	３．履歴
//		履歴番号	日付け		   担当者	 概要
//		作成		2001.06.10	   佐々木(FQS)
//
//------------------------------------------------------------

BOOL SXFTableManagerC::CheckSameLayer( LPCTSTR IN_Name)
{
	for(int i=0;i<m_LayerTable.GetSize();i++){
		if(IN_Name == m_LayerTable[i].m_Name)
			return FALSE;
	}

	return TRUE;
}
//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp					作成日：2001.06.10
//
//	１．機能概要
//		指定したPreDefColor Nameが定義されているかチェック
//		
//	２．インターフェース
//		BOOL CheckSamePreDefColor( LPCTSTR IN_Name)
//
//		引数: 型			  引数名				内容
//			  LPCTSTR		 IN_Name			   PreDefColor Name						   
//		
//		復帰値	
//			  正常時： TRUE
//			  異常時： FALSE
//		
//	２．インターフェース
//
//	３．履歴
//		履歴番号	日付け		   担当者	 概要
//		作成		2001.06.10	   佐々木(FQS)
//
//------------------------------------------------------------
BOOL SXFTableManagerC::CheckSamePreDefColor( LPCTSTR IN_Name)
{
	for(int i=0;i<16;i++){
		if(IN_Name == m_PreDefColorTable[i].m_Name)
			return FALSE;
	}

	return TRUE;
}
//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp					作成日：2001.06.10
//
//	１．機能概要
//		指定したPreDefFont Nameが定義されているかチェック
//		
//	２．インターフェース
//		BOOL CheckSamePreDefFont( LPCTSTR IN_Name)
//
//		引数: 型			  引数名				内容
//			  LPCTSTR		 IN_Name			   PreDefFont Name						  
//		
//		復帰値	
//			  正常時： TRUE
//			  異常時： FALSE
//		
//
//	３．履歴
//		履歴番号	日付け		   担当者	 概要
//		作成		2001.06.10	   佐々木(FQS)
//
//------------------------------------------------------------
BOOL SXFTableManagerC::CheckSamePreDefFont( LPCTSTR IN_Name)
{
	for(int i=0;i<16;i++){
		if(IN_Name == m_PreDefFontTable[i].m_Name)
			return FALSE;
	}
	return TRUE;
}
//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp					作成日：2001.06.10
//
//	１．機能概要
//		指定したPreDefFont Nameが定義されているかチェック
//		
//	２．インターフェース
//		BOOL CheckSameUserDefFont( LPCTSTR IN_Name)
//
//		引数: 型			  引数名				内容
//			  LPCTSTR		 IN_Name			   UserDefFont Name						   
//		
//		復帰値	
//			  正常時： TRUE
//			  異常時： FALSE
//		
//	３．履歴
//		履歴番号	日付け		   担当者	 概要
//		作成		2001.06.10	   佐々木(FQS)
//
//------------------------------------------------------------
BOOL SXFTableManagerC::CheckSameUserDefFont( LPCTSTR IN_Name)
{
	for(int i=0;i<m_UserDefFontTable.GetSize();i++){
		if(IN_Name == m_UserDefFontTable[i].m_Name)
			return FALSE;
	}

	return TRUE;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp					作成日：2001.06.10
//
//	１．機能概要
//		指定したWidth値が定義されているかチェック
//		
//	２．インターフェース
//		BOOL CheckSameWidth( double IN_Width)
//
//		引数: 型			  引数名				内容
//			  double		 IN_Width			   Width値						  
//		
//		復帰値	
//			  正常時： TRUE
//			  異常時： FALSE
//
//	３．履歴
//		履歴番号	日付け		   担当者	 概要
//		作成		2001.06.10	   佐々木(FQS)
//
//------------------------------------------------------------
BOOL SXFTableManagerC::CheckSameWidth( double IN_Width)
{
	double eps,angle_eps;
	m_ComInfo->Get_Tolerance(eps,angle_eps);

	SXFPreWidthTableC prewidthtable;

	int code = prewidthtable.GetCode(IN_Width,eps);

	if(m_PreDefWidthFlagTable[code-1] == 1){
		return FALSE;
	}

	return TRUE;
}
//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp					作成日：2001.06.10
//
//	１．機能概要
//		指定したTextFontが定義されているかチェック
//		
//	２．インターフェース
//		BOOL CheckSameTextFont( LPCTSTR IN_Name)
//
//		引数: 型			  引数名				内容
//			  LPCTSTR		 IN_Name				TextFont Name						 
//		
//		復帰値	
//			  正常時： TRUE
//			  異常時： FALSE
//		
//	３．履歴
//		履歴番号	日付け		   担当者	 概要
//		作成		2001.06.10	   佐々木(FQS)
//
//------------------------------------------------------------

BOOL SXFTableManagerC::CheckSameTextFont( LPCTSTR IN_Name)
{
	for(int i=0;i<m_TextFontTable.GetSize();i++){
		if(IN_Name == m_TextFontTable[i].m_Name)
			return FALSE;
	}

	return TRUE;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp					作成日：2001.06.10
//
//	１．機能概要
//		登録したLayer要素をMappingする
//		
//	２．インターフェース
//		BOOL  LayerMapping()
//
//		引数: 型			  引数名				内容
//				なし
//		
//		復帰値	
//			  正常時： TRUE
//			  異常時： FALSE
//		
//		
//	３．履歴
//		履歴番号	日付け		   担当者	 概要
//		作成		2001.06.10	   佐々木(FQS)
//
//------------------------------------------------------------
BOOL  SXFTableManagerC::LayerMapping()
{
	for(int i=0;i<m_LayerTable.GetSize();i++){
		if (m_LayerTable[i].m_MappingManager->SetStructLayer(&m_LayerTable[i])){
			m_LayerTable[i].m_MappingManager->WriteInstance(1);
			if (m_LayerTable[i].m_LfFlag == 0){
				m_LayerTable[i].m_ID = m_LayerTable[i].m_MappingManager->GetInstanceID(1);
				m_InvisibilityLayerTable.Add(m_LayerTable[i].m_ID);
			}
		}
	}
	return TRUE;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp					作成日：2001.06.10
//
//	１．機能概要
//		登録したInvisibility要素をMappingする
//		
//	２．インターフェース
//		BOOL MappingInvisibility()
//
//		引数: 型			  引数名				内容
//				なし
//
//		復帰値	
//			  正常時： TRUE
//			  異常時： FALSE
//		
//	３．履歴
//		履歴番号	日付け		   担当者	 概要
//		作成		2001.06.10	   佐々木(FQS)
//
//------------------------------------------------------------
BOOL SXFTableManagerC::MappingInvisibility()
{

	if (m_InvisibilityLayerTable.GetSize() > 0){
		SXFTableMapManagerC* mappingmanager = new SXFTableMapManagerC(m_File,
													m_ComInfo,m_WriteFile,
													m_InstanceIDManager); 
		if( !mappingmanager->MappingInvisibility(&m_InvisibilityLayerTable)) {
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
//	SXFTableManagerC.cpp					作成日：2001.06.10
//
//	１．機能概要
//		管理Tableから登録したTable要素を一つを出力する
//
//	２．インターフェース
//		int GetTableElement(int IN_Type,
//							LPVOID& OUT_Struct,
//							int& OUT_EndFlg)
//
//		引数: 型			  引数名				内容
//			  int			 IN_Type			   Table要素のType
//			  LPVOID&		 OUT_Struct			   Table要素の構造体
//												   のアドレス
//			  int&			 OUT_EndFlg			   最後の要素のFlag
//													1:最後の要素
//													0:続き
//
//		復帰値	
//			  正常時： Table要素のCode
//			  異常時： -1
//
//	３．履歴
//		履歴番号	日付け		   担当者	 概要
//		作成		2001.06.10	   佐々木(FQS)
//
//------------------------------------------------------------
int SXFTableManagerC::GetTableElement(int IN_Type, LPVOID OUT_Struct, int* OUT_EndFlg)
{
	*OUT_EndFlg = 1;
	SXFTableMapManagerC* mappingmanager;
	int i = 0;
	CUIntArray predefcolor;
	CUIntArray predeffont;
	CUIntArray width;
	int return_code = -1;
	INT_PTR table_size;

	/* ﾃｰﾌﾞﾙ型が異常 */
	if (IN_Type < 1 || 7 < IN_Type){
		SXFErrorMsgC::RecordError(SXFTABLETYPEERR,"",1,IN_Type);
		return SXFTABLETYPEERR;
	}
	/* ﾃｰﾌﾞﾙｲﾝﾃﾞｯｸｽが0 */
	if(m_CurrentNumber == 0 ){
		m_CurrentType = IN_Type;
	}
	else{
		if(m_CurrentType != IN_Type){
			m_CurrentNumber = 0;
			m_CurrentType = IN_Type;
		}
	}

	switch (m_CurrentType)
	{
		/* ﾚｲﾔ */
		case 1://layer
			if(m_CurrentNumber == 0)
				m_CurrentNumber = 1;

			/* ﾚｲﾔﾃｰﾌﾞﾙのｻｲｽﾞ */
			table_size = m_LayerTable.GetSize();
			/* ｻｲｽﾞが0のとき */
			if (table_size == 0){
				/* 読み出すレイヤがありません */
//	MOD(S)	メッセージ修正	K.Naono	04.03.05
//				SXFErrorMsgC::RecordError(SXFNOLAYER,DEF_LAYER,0);
				SXFErrorMsgC::RecordError2(SXFNOLAYER,DEF_LAYER,0);
				return SXFNOLAYER;
//	MOD(E)	メッセージ修正	K.Naono	04.03.05
			}
			/* ﾚｲﾔﾃｰﾌﾞﾙｲﾝﾃﾞｯｸｽがﾃｰﾌﾞﾙの最後 */
			if(m_CurrentNumber == table_size - 1)
				*OUT_EndFlg = 1;	/* EndFlgをON */
			else if(m_CurrentNumber > table_size - 1) {
				*OUT_EndFlg = 1;	/* EndFlgをON */
				/* 読み出すレイヤがありません */
				SXFErrorMsgC::RecordError(SXFNOLAYER,DEF_LAYER,0);
				return SXFNOLAYER;
			}
			else
				*OUT_EndFlg = 0;	/* EndFlgをOFF */
			/* ﾚｲﾔ構造体 */
			*(Layer_Struct*)OUT_Struct = *(Layer_Struct*)(m_LayerTable[m_CurrentNumber].m_MappingManager->GetStructData(  ));
			/* 復帰値(ﾚｲﾔｺｰﾄﾞ) */
			return_code = m_LayerTable[m_CurrentNumber].m_Code;
			/* ﾃｰﾌﾞﾙｲﾝﾃﾞｯｸｽを＋１ */
			m_CurrentNumber++;
			break;
 		/* 既定義色 */
		case 2://predefcolor
			for(i=0; i<MAXPRECOLOUR; i++){
				/* 定義ﾃｰﾌﾞﾙ要素Mapping管理ｵﾌﾞｼﾞｪｸﾄｾｯﾄ */
				mappingmanager = m_PreDefColorTable[i].m_MappingManager;
				if(mappingmanager != NULL)
					/* 既定義色ﾃｰﾌﾞﾙに追加 */
					predefcolor.Add(i);
			}
			/* 既定義色ﾃｰﾌﾞﾙｻｲｽﾞ */
			table_size = predefcolor.GetSize();
			/* ﾃｰﾌﾞﾙｻｲｽﾞが0 */
			if (table_size == 0){
				/* 読み出す既定義色がありません */
//	MOD(S)	メッセージ修正	K.Naono	04.03.05
//				SXFErrorMsgC::RecordError(SXFNOPRECOLOUR,DEF_PREDEFINED_COLOUR,0);
				SXFErrorMsgC::RecordError2(SXFNOPRECOLOUR,DEF_PREDEFINED_COLOUR,0);
				return SXFNOPRECOLOUR;
//	MOD(E)	メッセージ修正	K.Naono	04.03.05
			}
			/* ﾃｰﾌﾞﾙｲﾝﾃﾞｯｸｽが最後 */
			if(m_CurrentNumber == table_size-1)
				*OUT_EndFlg = 1;	/* EndFlgをON */
			else if(m_CurrentNumber > table_size-1) {
				*OUT_EndFlg = 1;	/* EndFlgをON */
				/* 読み出す既定義色がありません */
				SXFErrorMsgC::RecordError(SXFNOPRECOLOUR,DEF_PREDEFINED_COLOUR,0);
				return SXFNOPRECOLOUR;
			}
			else
				*OUT_EndFlg = 0;	/* EndFlgをOFF */
			/* 既定義色構造体 */
			*(Predefined_Colour_Struct*)OUT_Struct = *(Predefined_Colour_Struct*)(m_PreDefColorTable[predefcolor[m_CurrentNumber]].m_MappingManager->GetStructData(  ));
			/* 復帰値(色ｺｰﾄﾞ) */
			return_code = m_PreDefColorTable[predefcolor[m_CurrentNumber]].m_Code;
			/* ﾃｰﾌﾞﾙｲﾝﾃﾞｯｸｽを＋１ */
			m_CurrentNumber++;
			break;
		/* ﾕｰｻﾞ定義色 */
		case 3://userdefcolor
			/* ﾕｰｻﾞ定義色ﾃｰﾌﾞﾙｻｲｽﾞ */
			table_size = m_UserDefColorTable.GetSize();
			/* ﾃｰﾌﾞﾙｻｲｽﾞが0 */
			if (table_size == 0){
				/* 読み出すﾕｰｻﾞ定義色がありません */
//	MOD(S)	メッセージ修正	K.Naono	04.03.05
//				SXFErrorMsgC::RecordError(SXFNOUSERCOLOUR,DEF_USERDEFINED_COLOUR,0);
				SXFErrorMsgC::RecordError2(SXFNOUSERCOLOUR,DEF_USERDEFINED_COLOUR,0);
				return SXFNOUSERCOLOUR;
//	MOD(E)	メッセージ修正	K.Naono	04.03.05
			}
			/* ﾃｰﾌﾞﾙｲﾝﾃﾞｯｸｽが最後 */
			if(m_CurrentNumber == table_size-1)
				*OUT_EndFlg = 1;	/* EndFlgをON */
			else if(m_CurrentNumber > table_size-1) {
				*OUT_EndFlg = 1;	/* EndFlgをON */
				/* 読み出すﾕｰｻﾞ定義色がありません */
				SXFErrorMsgC::RecordError(SXFNOUSERCOLOUR,DEF_USERDEFINED_COLOUR,0);
				return SXFNOUSERCOLOUR;
			}
			else
				*OUT_EndFlg = 0;	/* EndFlgをOFF */
			/* ﾕｰｻﾞ定義色構造体 */
			*(Userdefined_Colour_Struct*)OUT_Struct = *(Userdefined_Colour_Struct*)(m_UserDefColorTable[m_CurrentNumber].m_MappingManager->GetStructData(  ));
			/* 復帰値(色ｺｰﾄﾞ) */
			return_code = m_UserDefColorTable[m_CurrentNumber].m_Code;
			/* ﾃｰﾌﾞﾙｲﾝﾃﾞｯｸｽを＋１ */
			m_CurrentNumber++;
			break;
		/* 既定義線種 */
		case 4://predeffont
			for(i=0; i<MAXPRELINETYPE; i++){
				/* 定義ﾃｰﾌﾞﾙ要素Mapping管理ｵﾌﾞｼﾞｪｸﾄ生成 */
				mappingmanager = m_PreDefFontTable[i].m_MappingManager;
				if(mappingmanager != NULL)
					/* 既定義線種ﾃｰﾌﾞﾙに追加 */
					predeffont.Add(i);
			}
			/* 既定義線種ﾃｰﾌﾞﾙｻｲｽﾞ */
			table_size = predeffont.GetSize();
			/* ﾃｰﾌﾞﾙｻｲｽﾞが0 */
			if (table_size == 0){
				/* 読み出す既定義線種がありません */
//	MOD(S)	メッセージ修正	K.Naono	04.03.05
//				SXFErrorMsgC::RecordError(SXFNOPRELINETYPE,DEF_PREDEFINED_LINETYPE,0);
				SXFErrorMsgC::RecordError2(SXFNOPRELINETYPE,DEF_PREDEFINED_LINETYPE,0);
				return SXFNOPRELINETYPE;
//	MOD(E)	メッセージ修正	K.Naono	04.03.05
			}
			/* ﾃｰﾌﾞﾙｲﾝﾃﾞｯｸｽがﾃｰﾌﾞﾙの最後 */
			if(m_CurrentNumber == table_size-1)
				*OUT_EndFlg = 1;	/* EndFlgをON */
			else if(m_CurrentNumber > table_size-1) {
				*OUT_EndFlg = 1;	/* EndFlgをON */
				/* 読み出す既定義線種がありません */
				SXFErrorMsgC::RecordError(SXFNOPRELINETYPE,DEF_PREDEFINED_LINETYPE,0);
				return SXFNOPRELINETYPE;
			}
			else
				*OUT_EndFlg = 0;	/* EndFlgをOFF */
			/* 既定義線種構造体 */
			*(Predefined_Linetype_Struct*)OUT_Struct = *(Predefined_Linetype_Struct*)(m_PreDefFontTable[predeffont[m_CurrentNumber]].m_MappingManager->GetStructData(  ));
			/* 復帰値(線種ｺｰﾄﾞ) */
			return_code = m_PreDefFontTable[predeffont[m_CurrentNumber]].m_Code;
			/* ﾃｰﾌﾞﾙｲﾝﾃﾞｯｸｽを＋１ */
			m_CurrentNumber++;
			break;
		/* ﾕｰｻﾞ定義線種 */
		case 5://userdeffont
			/* ﾕｰｻﾞ定義線種ﾃｰﾌﾞﾙｻｲｽﾞ */
			table_size = m_UserDefFontTable.GetSize();
			/* ﾃｰﾌﾞﾙｻｲｽﾞが0 */
			if (table_size == 0){
				/* 読み出すﾕｰｻﾞ定義線種がありません */
//	MOD(S)	メッセージ修正	K.Naono	04.03.05
//				SXFErrorMsgC::RecordError(SXFNOUSERLINETYPE,DEF_USERDEFINED_LINETYPE,0);
				SXFErrorMsgC::RecordError2(SXFNOUSERLINETYPE,DEF_USERDEFINED_LINETYPE,0);
				return SXFNOUSERLINETYPE;
//	MOD(E)	メッセージ修正	K.Naono	04.03.05
			}
			/* ﾃｰﾌﾞﾙｲﾝﾃﾞｯｸｽがﾃｰﾌﾞﾙの最後 */
			if(m_CurrentNumber == table_size-1)
				*OUT_EndFlg = 1;		/* EndFlg をON */
			else if(m_CurrentNumber > table_size-1) {
				*OUT_EndFlg = 1;		/* EndFlg をON */
				/* 読み出すﾕｰｻﾞ定義線種がありません */
				SXFErrorMsgC::RecordError(SXFNOUSERLINETYPE,DEF_USERDEFINED_LINETYPE,0);
				return SXFNOUSERLINETYPE;
			}
			else
				*OUT_EndFlg = 0;		/* EndFlg をOFF */
			/* ﾕｰｻﾞ定義線種構造体 */
			*(Userdefined_Linetype_Struct*)OUT_Struct = *(Userdefined_Linetype_Struct*)(m_UserDefFontTable[m_CurrentNumber].m_MappingManager->GetStructData(  ));
			/* 復帰値(線種ｺｰﾄﾞ) */
			return_code = m_UserDefFontTable[m_CurrentNumber].m_Code;
			/* ﾃｰﾌﾞﾙｲﾝﾃﾞｯｸｽを＋１ */
			m_CurrentNumber++;
			break;
		/* 線幅 */
		case 6://width
			for(i=0; i<MAXLINEWIDTH; i++){
				/* 定義ﾃｰﾌﾞﾙ要素Mapping管理ｵﾌﾞｼﾞｪｸﾄｾｯﾄ */
				mappingmanager = m_WidthTable[i].m_MappingManager;
				if(mappingmanager != NULL)
					/* 線幅ﾃｰﾌﾞﾙに追加 */
					width.Add(i);
			}
			/* 線幅ﾃｰﾌﾞﾙｻｲｽﾞ */
			table_size = width.GetSize();
			/* ﾃｰﾌﾞﾙｻｲｽﾞが0 */
			if (table_size == 0){
				/* 読み出す線幅がありません */
//	MOD(S)	メッセージ修正	K.Naono	04.03.05
//				SXFErrorMsgC::RecordError(SXFNOLINEWIDTH,DEF_LINE_WIDTH,0);
				SXFErrorMsgC::RecordError2(SXFNOLINEWIDTH,DEF_LINE_WIDTH,0);
				return SXFNOLINEWIDTH;
//	MOD(E)	メッセージ修正	K.Naono	04.03.05
			}
			/* ﾃｰﾌﾞﾙｲﾝﾃﾞｯｸｽがﾃｰﾌﾞﾙの最後 */		   
			if(m_CurrentNumber == table_size-1)
				*OUT_EndFlg = 1;	/* EndFlgをON */
			else if(m_CurrentNumber > table_size-1) {
				*OUT_EndFlg = 1;	/* EndFlgをON */
				/* 読み出す線幅がありません */
				SXFErrorMsgC::RecordError(SXFNOLINEWIDTH,DEF_LINE_WIDTH,0);
				return SXFNOLINEWIDTH;
			}
			else
				*OUT_EndFlg = 0;	/* EndFlgをOFF */
			/* 線幅構造体 */
			*(Line_Width_Struct*)OUT_Struct = *(Line_Width_Struct*)(m_WidthTable[width[m_CurrentNumber]].m_MappingManager->GetStructData(  ));
			/* 復帰値(線幅ｺｰﾄﾞ) */
			return_code = m_WidthTable[width[m_CurrentNumber]].m_Code;
			/* ﾃｰﾌﾞﾙｲﾝﾃﾞｯｸｽを＋１ */
			m_CurrentNumber++;
			break;
		/* 文字ﾌｫﾝﾄ */
		case 7://textfont
			/* 文字ﾌｫﾝﾄﾃｰﾌﾞﾙｻｲｽﾞ */
			table_size = m_TextFontTable.GetSize();
			/* ﾃｰﾌﾞﾙｻｲｽﾞが0 */
			if (table_size == 0){
				/* 読み出す文字ﾌｫﾝﾄがありません */
//	MOD(S)	メッセージ修正	K.Naono	04.03.05
//				SXFErrorMsgC::RecordError(SXFNOTEXTFONT,DEF_TEXT_FONT,0);
				SXFErrorMsgC::RecordError2(SXFNOTEXTFONT,DEF_TEXT_FONT,0);
				return SXFNOTEXTFONT;
//	MOD(E)	メッセージ修正	K.Naono	04.03.05
			}
			/* ﾃｰﾌﾞﾙｲﾝﾃﾞｯｸｽがﾃｰﾌﾞﾙの最後 */
			if(m_CurrentNumber == table_size-1)
				*OUT_EndFlg = 1;		/* EndFlg をON */
			else if(m_CurrentNumber > table_size-1) {
				*OUT_EndFlg = 1;		/* EndFlg をON */
				/* 読み出す文字ﾌｫﾝﾄがありません */
				SXFErrorMsgC::RecordError(SXFNOTEXTFONT,DEF_TEXT_FONT,0);
				return SXFNOTEXTFONT;
			}
			else
				*OUT_EndFlg = 0;		/* EndFlg をOFF */
			/* 文字ﾌｫﾝﾄ構造体 */
			*(Text_Font_Struct*)OUT_Struct = *(Text_Font_Struct*)(m_TextFontTable[m_CurrentNumber].m_MappingManager->GetStructData(  ));
			/* 復帰値(文字ﾌｫﾝﾄｺｰﾄﾞ) */
			return_code = m_TextFontTable[m_CurrentNumber].m_Code;
			/* ﾃｰﾌﾞﾙｲﾝﾃﾞｯｸｽを＋１ */
			m_CurrentNumber++;
			break;
		default:
			return -1;
			break;
	}
	return return_code;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp					作成日：2001.06.10
//
//	１．機能概要
//		AP202 Table InstanceのIDを登録する
//
//	２．インターフェース
//		BOOL RegisterAP202IDTable(int IN_ID)
//
//		引数: 型			  引数名				内容
//			  int			 IN_ID				   InstanceID
//		
//		復帰値	
//			  正常時：TRUE
//			  異常時：FALSE
//
//	３．履歴
//		履歴番号	日付け		   担当者	 概要
//		作成		2001.06.10	   佐々木(FQS)
//
//------------------------------------------------------------
BOOL SXFTableManagerC::RegisterAP202IDTable(int IN_ID)
{
	m_AP202IDTable.Add(IN_ID);
	return TRUE;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp					作成日：2001.06.10
//
//	１．機能概要
//		AP202 Table のMappingを行う
//
//	２．インターフェース
//		BOOL SXFTableManagerC::MappingAP202Table()
//
//		引数: 型			  引数名				内容
// 					なし
//		
//		復帰値	
//			  正常時：TRUE
//			  異常時：FALSE
//
//	３．履歴
//		履歴番号	日付け		   担当者	 概要
//		作成		2001.06.10	   佐々木(FQS)
//
//------------------------------------------------------------
BOOL SXFTableManagerC::MappingAP202Table()
{
	for(int i=0;i<m_AP202IDTable.GetSize();i++)
	{
		/* 定義ﾃｰﾌﾞﾙ要素Mapping管理ｵﾌﾞｼﾞｪｸﾄ生成 */
		SXFTableMapManagerC* mappingmanager = new SXFTableMapManagerC( this, m_InstanceIDManager,m_ComInfo); 

		if( !mappingmanager->SetAP202ID(m_AP202IDTable[i]) ){
			delete mappingmanager;
			continue;
		}

		int tabletype=0;
		/*構造体取得*/
		LPVOID tablestruct = mappingmanager->GetStruct( tabletype );
		if(tablestruct == NULL ){
			delete mappingmanager;
			continue;
		}

		//AP202 テーブルの登録
		if( RegisterAP202Table( m_AP202IDTable[i],
								tabletype,
								tablestruct,
								mappingmanager) < 0) {
			delete mappingmanager;
			continue;
		}
	}

	return TRUE;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp					作成日：2001.06.10
//
//	１．機能概要
//		AP202 Table の登録
//
//	２．インターフェース
//	int SXFTableManagerC::RegisterAP202Table( int IN_ID,
//											int IN_Type,
//											LPVOID IN_Struct,
//											SXFTableMapManagerC* IN_MappingManager)
//											
//		引数: 型			  引数名				内容
//			int IN_ID							テーブル要素のID
//			int IN_Type							テーブル要素のtype
//			LPVOID IN_Struct					構造体
//			SXFTableMapManagerC* IN_MappingManager
//
//		復帰値	
//			  正常時：TRUE
//			  異常時：FALSE
//
//	３．履歴
//		履歴番号	日付け		   担当者	 概要
//		作成		2001.06.10	   佐々木(FQS)
//
//------------------------------------------------------------
int SXFTableManagerC::RegisterAP202Table( int IN_ID,
										  int IN_Type,
										  LPVOID IN_Struct,
										  SXFTableMapManagerC* IN_MappingManager)
{

	SXFLayerC layer;
	SXFPreDefColorC predefcolor;
	SXFPreDefFontC predeffont;
	SXFUserDefColorC userdefcolor;
	SXFUserDefFontC userdeffont;
	SXFWidthC width;
	SXFTextFontC textfont;
	INT_PTR textfontsize;
	INT_PTR layercode;
	INT_PTR usercolorsize;
	INT_PTR userfontsize;
	int i;
	double inwidth;
	double eps1;
	double eps2;
	int resaultcode;
	int find1;
	int find2;
	double ascent = 1.0;
	double decent = 0.0;

	switch(IN_Type)
	{
	/* ﾚｲﾔ */
	case 1://layer

		if(m_LayerTable.GetSize() == 0 ){
			SXFLayerC blanklayer;
			blanklayer.m_Name =DEF_BLANK;
			blanklayer.m_Code = 0;
			m_LayerTable.Add(blanklayer);
		}
		/* ﾚｲﾔ名 */
		layer.m_Name = ((Layer_Struct*)IN_Struct)->name;
		/* 表示・非表示フラグ*/
		layer.m_LfFlag = ((Layer_Struct*)IN_Struct)->lflag;
		/*	ﾚｲﾔID*/
		layer.m_ID=IN_ID;

		if(layer.m_Name == "$$SXF_dummy_layer_for_subfigure"){
			layercode = 0;
		}else{
			layercode = m_LayerTable.GetSize();
		}

		if (layercode>MAXLAYER){
			SXFErrorMsgC::RecordError(SXFMAXLAYER,DEF_LAYER,0);
			return SXFMAXLAYER;
		}
		layer.m_Code = (int)layercode;
		/* 定義ﾃｰﾌﾞﾙ要素Mapping管理ｵﾌﾞｼﾞｪｸﾄｾｯﾄ */
		layer.m_MappingManager = IN_MappingManager;
		layer.m_Element.Copy(IN_MappingManager->m_MapTable->m_LayerElements);
		if(layer.m_Code == 0){
			if(m_LayerTable[0].m_Name != DEF_BLANK)
				return FALSE; 
			m_LayerTable.SetAt(0,layer);
		}else{
			/* ﾚｲﾔﾃｰﾌﾞﾙに追加 */
			m_LayerTable.Add(layer);
		}
		break;

	/** 既定義色 **/
	case 2://predefcolor 16
		/* 既定義色以外の名前のとき */
		if(!predefcolor.SetName(((Predefined_Colour_Struct*)IN_Struct)->name)){
			SXFErrorMsgC::RecordError(SXFNOTPRECOLOUR,DEF_PREDEFINED_COLOUR,1,((Predefined_Colour_Struct*)IN_Struct)->name);
			return SXFNOTPRECOLOUR;
		}
		/* 色名が既にﾃｰﾌﾞﾙ内にあるとき */
		if (!CheckSamePreDefColor(predefcolor.m_Name)) {
			SXFErrorMsgC::RecordError(SXFSAMENAME,DEF_PREDEFINED_COLOUR,1,predefcolor.m_Name);
			return SXFSAMENAME;
		}
		/* ｲﾝｽﾀﾝｽIDをｾｯﾄ */
		predefcolor.m_ID = IN_ID;
		/* 定義ﾃｰﾌﾞﾙ要素Mapping管理ｵﾌﾞｼﾞｪｸﾄをｾｯﾄ */
		predefcolor.m_MappingManager = IN_MappingManager;
		/* 既定義色ﾃｰﾌﾞﾙに追加 */
		m_PreDefColorTable[predefcolor.m_Code-1] = predefcolor;
		break;

	/** ユーザ定義色 **/
	case 3://userdefcolor
		usercolorsize = m_UserDefColorTable.GetSize();
		///ERROR
		/** 最大色数を超えたときエラー処理 **/
		if (usercolorsize >= MAXUSERCOLOUR){
			SXFErrorMsgC::RecordError(SXFMAXUSERCOLOUR,DEF_USERDEFINED_COLOUR,0);
			return SXFMAXUSERCOLOUR;
		}
		userdefcolor.m_Code = (int)(usercolorsize+16+1);//17------
		userdefcolor.R =((Userdefined_Colour_Struct*)IN_Struct)->red;
		userdefcolor.G =((Userdefined_Colour_Struct*)IN_Struct)->green;
		userdefcolor.B =((Userdefined_Colour_Struct*)IN_Struct)->blue;
		userdefcolor.m_ID = IN_ID;
		/* 定義ﾃｰﾌﾞﾙ要素Mapping管理ｵﾌﾞｼﾞｪｸﾄｾｯﾄ */
		userdefcolor.m_MappingManager = IN_MappingManager;
		/* ﾕｰｻﾞ定義色ﾃｰﾌﾞﾙに追加 */
		m_UserDefColorTable.Add(userdefcolor);
		break;

	/** 既定義線種 **/
	case 4://predeffont
		/* 既定義線種名でない */
		if (!predeffont.SetName(((Predefined_Linetype_Struct*)IN_Struct)->name)){
			SXFErrorMsgC::RecordError(SXFNOTPRETYPE,DEF_PREDEFINED_LINETYPE,1,((Predefined_Linetype_Struct*)IN_Struct)->name);
			return SXFNOTPRETYPE;
		}
		/* 既定義線種名が既にﾃｰﾌﾞﾙ内にある */
		if (!CheckSamePreDefFont(predeffont.m_Name)) {
			SXFErrorMsgC::RecordError(SXFSAMENAME,DEF_PREDEFINED_LINETYPE,1,predeffont.m_Name);
			return SXFSAMENAME;
		}
		/* ｲﾝｽﾀﾝｽIDｾｯﾄ */
		predeffont.m_ID = IN_ID;
		/* 定義ﾃｰﾌﾞﾙ要素Mapping管理ｵﾌﾞｼﾞｪｸﾄｾｯﾄ */
		predeffont.m_MappingManager = IN_MappingManager;
		/* 既定義線種ﾃｰﾌﾞﾙに追加 */
		m_PreDefFontTable[predeffont.m_Code-1] = predeffont;
		break;

	/** ユーザ定義線種 **/
	case 5://userdeffont
		userfontsize = m_UserDefFontTable.GetSize();
		///ERROR
		//ユーザ定義線種は32個しか定義できない。
		if (userfontsize >= MAXUSERLINETYPE){
			SXFErrorMsgC::RecordError(SXFMAXUSERLINETYPE,DEF_USERDEFINED_LINETYPE,0);
			return SXFMAXUSERLINETYPE;
		}
		userdeffont.m_Code = (int)(userfontsize+16+1);//17---
		userdeffont.m_Name = ((Userdefined_Linetype_Struct*)IN_Struct)->name;
		userdeffont.m_Segment=((Userdefined_Linetype_Struct*)IN_Struct)->segment;
		for(i=0;i<userdeffont.m_Segment;i++)
			userdeffont.m_Pitch.Add( ((Userdefined_Linetype_Struct*)IN_Struct)->pitch[i] );
		/* ｲﾝｽﾀﾝｽID */
		userdeffont.m_ID = IN_ID;
		/* 定義ﾃｰﾌﾞﾙ要素Mapping管理ｵﾌﾞｼﾞｪｸﾄｾｯﾄ */
		userdeffont.m_MappingManager = IN_MappingManager;
		/* ﾕｰｻﾞ定義線種ﾃｰﾌﾞﾙ追加 */
		m_UserDefFontTable.Add(userdeffont);
		break;

	/** 線幅 **/
	case 6://width
		/* 線幅 */
		inwidth = ((Line_Width_Struct*)IN_Struct)->width;
		/* 線幅が異常 */
		if( inwidth <= 0 ){
			SXFErrorMsgC::RecordError(SXFERRORWIDTH,DEF_LINE_WIDTH,1,inwidth);
			return -1;
		}

		eps1 = 0.0;
		eps2 = 0.0;
		/* 許容誤差取得 */
		m_ComInfo->Get_Tolerance(eps1,eps2);
		/* 線幅から線幅ｺｰﾄﾞを求める */
		resaultcode = width.InquireCode(inwidth,eps1);
		/* 線幅に対応する線幅ｺｰﾄﾞがある(既定義) */
		if(resaultcode != 0){
			/* 既にﾃｰﾌﾞﾙ内にある */
			if(m_PreDefWidthFlagTable[resaultcode-1] == 1){
				SXFErrorMsgC::RecordError(SXFSAMEWIDTH,DEF_LINE_WIDTH,1,inwidth);
				return SXFSAMEWIDTH;
			}
			/* 線幅ｺｰﾄﾞ */
			width.m_Code = resaultcode;
			SXFPreWidthTableC prewidthtable;
			double prewidth = 0.0;
			/* 線幅ｺｰﾄﾞから線幅を取得 */
			prewidthtable.GetPreWidth(resaultcode, prewidth); 
			/* 線幅 */
			width.m_Width = prewidth;
			/* 線幅ﾃｰﾌﾞﾙに追加 */
			m_PreDefWidthFlagTable[resaultcode-1]=1;

		}
		//線幅に対応するコードが０のときは既定義ではない。
		else{
			/* 既にﾃｰﾌﾞﾙ内にある */
			for (int i = 11; i < userdefwidthcode; i++) {
				if (m_WidthTable[i-1] .m_Width == inwidth) {
					SXFErrorMsgC::RecordError(SXFSAMEWIDTH,DEF_LINE_WIDTH,1,inwidth);
					return SXFSAMEWIDTH;
				}
			}
			//線幅が１６以上登録されていれば
			//それ以上登録できないので、エラー
			if (userdefwidthcode > MAXLINEWIDTH){//widthcode 1---16
				SXFErrorMsgC::RecordError(SXFMAXLINEWIDTH,DEF_LINE_WIDTH,0);
				return SXFMAXLINEWIDTH;
			}
			else{
				/* 線幅ｺｰﾄﾞ */
				width.m_Code = userdefwidthcode;
				userdefwidthcode++;
			}
			/* 線幅 */
			width.m_Width=inwidth;
		}
		/* 定義ﾃｰﾌﾞﾙ要素Mapping管理ｵﾌﾞｼﾞｪｸﾄｾｯﾄ */
		width.m_MappingManager=IN_MappingManager;
		/* ｲﾝｽﾀﾝｽID */
		width.m_ID = IN_ID;
		/* 線幅ﾃｰﾌﾞﾙに追加 */	
		m_WidthTable[width.m_Code-1] = width;
		break;

	/** 文字フォント **/
	case 7://textfont
		//ERROR
		//文字フォントは１０２４個しか登録できない
		textfontsize = m_TextFontTable.GetSize();
		if (textfontsize >= MAXTEXTFONT){//textfont 1--1024
			SXFErrorMsgC::RecordError(SXFMAXTEXTFONT,DEF_TEXT_FONT,0);
			return SXFMAXTEXTFONT;
		}
		/* 文字ﾌｫﾝﾄ名 */
		textfont.m_Name = ((Text_Font_Struct*)IN_Struct)->name;
		/* 既にﾃｰﾌﾞﾙ内にある */
		if (!CheckSameTextFont(textfont.m_Name)) {
			SXFErrorMsgC::RecordError(SXFSAMENAME,DEF_TEXT_FONT,1,textfont.m_Name);
			return SXFSAMENAME;
		}

		ascent = 1.0;
		decent = 0.0;

		if ((find1 = textfont.m_Name.ReverseFind('-')) != -1){
			CString tmp_font_name = textfont.m_Name.Left(find1);
			CString decent_tmp = textfont.m_Name.Mid(find1+1);
			if ((find2 = tmp_font_name.ReverseFind('-')) != -1){
				CString ascent_tmp = tmp_font_name.Mid(find2+1);
				ascent = atof(ascent_tmp);
				decent = atof(decent_tmp);
			}
		}
		textfont.m_Ascent = ascent;
		textfont.m_Decent = decent;
		/* 文字ﾌｫﾝﾄｺｰﾄﾞ */
		textfont.m_Code = (int) m_TextFontTable.GetSize()+1;
		/* ｲﾝｽﾀﾝｽID */
		textfont.m_ID = IN_ID;
		/* 定義ﾃｰﾌﾞﾙ要素Mapping管理ｵﾌﾞｼﾞｪｸﾄｾｯﾄ */
		textfont.m_MappingManager = IN_MappingManager;
		/* 文字ﾌｫﾝﾄﾃｰﾌﾞﾙに追加 */
		m_TextFontTable.Add(textfont);
		break;

	default:
		// struct type error
		return -1;
		break;
	}

	return 1;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp					作成日：2001.06.10
//
//	１．機能概要
//		指定したTable要素のInstance IDと対応するのCodeを取得する
//		(READ AP202)
//		 Layerの時は、Layer Element IDと対応するのLayer Codeを返す
//
//	２．インターフェース
//		int GetTableCode( int IN_ID , int& OUT_Type)
//
//		引数: 型			  引数名				内容
//			  int			  IN_ID				   Table要素のInstance ID
//													
//		
//		復帰値	
//			  正常時： Table 要素の Code
//			  異常時： -1
//
//	３．履歴
//		履歴番号	日付け		   担当者	 概要
//		作成		2001.06.10	   佐々木(FQS)
//
//------------------------------------------------------------
int SXFTableManagerC::GetTableCode( int IN_ID, int& OUT_Type)
{
	int i = 0;
	int j = 0;

	if (m_TableCodeElemMapInitialized == FALSE) {
		// 初期化されていない場合は初期化する
		m_TableCodeElemMapInitialized = TRUE;
		m_TableCodeElemMap.InitHashTable( 109 );
		for(i=0;i<m_LayerTable.GetSize();i++){
			for(j=0;j<m_LayerTable[i].m_Element.GetSize();j++){
				SXFTableCodeElem	e;
				e.id = m_LayerTable[i].m_Element[j];
				e.getcode = i;
				e.codetype = 1;//layer
				m_TableCodeElemMap.SetAt(e.id, e);
			}
		}
		for(i=0;i<16;i++){
				SXFTableCodeElem	e;
				e.id = m_PreDefColorTable[i].m_ID;
				e.getcode = i+1;
				e.codetype = 2;//predefcolor
				m_TableCodeElemMap.SetAt(e.id, e);
		}
		for(i=0;i<m_UserDefColorTable.GetSize();i++){ //0---(256-16)
				SXFTableCodeElem	e;
				e.id = m_UserDefColorTable[i].m_ID;
				e.getcode = i+16+1;
				e.codetype = 3;//userdefcolor
				m_TableCodeElemMap.SetAt(e.id, e);
		}
		for(i=0;i<16;i++){
				SXFTableCodeElem	e;
				e.id = m_PreDefFontTable[i].m_ID;
				e.getcode = i+1;
				e.codetype = 4;//predeffont
				m_TableCodeElemMap.SetAt(e.id, e);
		}
		for(i=0;i<m_UserDefFontTable.GetSize();i++){//0----(32-16)
				SXFTableCodeElem	e;
				e.id = m_UserDefFontTable[i].m_ID;
				e.getcode = i+16+1;
				e.codetype = 5;//userdeffont
				m_TableCodeElemMap.SetAt(e.id, e);
		}
		for(i=0;i<16;i++){
				SXFTableCodeElem	e;
				e.id = m_WidthTable[i].m_ID;
				e.getcode = i+1;
				e.codetype = 6;//width
				m_TableCodeElemMap.SetAt(e.id, e);
		}
		for(i=0;i<m_TextFontTable.GetSize();i++){
				SXFTableCodeElem	e;
				e.id = m_TextFontTable[i].m_ID;
				e.getcode = i+1;
				e.codetype = 7;//textfont
				m_TableCodeElemMap.SetAt(e.id, e);
		}

	}
	SXFTableCodeElem	e;
	if (m_TableCodeElemMap.Lookup(IN_ID,e)) {
		OUT_Type = e.codetype;
		return e.getcode;
	}
	else {
		return -1;
	}
}
//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp					作成日：2001.06.10
//
//	１．機能概要
//		表示・非表示フラグの登録
//
//	２．インターフェース
//		void	SXFTableManagerC::RegisterInvisibility
//		
//	引数	：	型		　　　　引数名				内容
//		　　　　INSTANCEDATA	*IN_Instance	
//
//	３．履歴
//		履歴番号	日付け		   担当者	 概要
//		作成		2001.06.10	   佐々木(FQS)
//
//------------------------------------------------------------

BOOL SXFTableManagerC::RegisterInvisibility(INSTANCEDATA *IN_Instance)
{

	CUIntArray	idarray;
	if( SXFListToIntID( IN_Instance->EntityData,idarray ) == FALSE)
		return FALSE;

	m_InvisibilityLayerTable.Append( idarray );

	return TRUE;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp					作成日：2001.06.10
//
//	１．機能概要
//		表示・非表示フラグの取得
//
//	２．インターフェース
//		void	SXFTableManagerC::GetInvisibilityFlag()
//		
//	引数	：	型		引数名				内容
//		int		IN_ID	レイヤInstance ID	
//
//	３．履歴
//		履歴番号	日付け		   担当者	 概要
//		作成		2001.06.10	   佐々木(FQS)
//
//------------------------------------------------------------
BOOL SXFTableManagerC::GetInvisibilityFlag(int IN_ID)
{
	for(int i=0;i<m_InvisibilityLayerTable.GetSize();i++){
		if((UINT)IN_ID == m_InvisibilityLayerTable[i])
			return TRUE;
	}

	return FALSE;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp				作成日：2001.06.24
//
//	１．機能概要
//		Instance ID List から Int Arrayに変換する
//		Char String:"(ID1,ID2,ID3,...IDn)" 
//				   ====>
//		IntArray:[ID1,ID2,ID3,...IDn]
//		
//	２．インターフェース
//		BOOL SXFListToIntID(CString& IN_List, CUIntArray& OUT_IDArray)
//
//		引数: 型			  引数名				内容
//			  CString&		 IN_List			   Instance ID List
//												   char string型
//			  CUIntArray&	 OUT_IDArrayint		   Instance ID Array
//												   IntArray型
//		
//		復帰値	
//			  正常時：TRUE
//			  異常時：FALSE
//
//	３．履歴
//		履歴番号	日付け		   担当者	 概要
//		作成		2001.06.24	   佐々木(FQS)
//
//------------------------------------------------------------
BOOL SXFTableManagerC::SXFListToIntID(CString& IN_List, CUIntArray& OUT_IDArray)
{

	if(IN_List[0] != '(' || IN_List.Right(1) != ')' )
		return FALSE;

	IN_List.TrimLeft('(');
	IN_List.TrimRight(')');

	if (IN_List.IsEmpty()) {
		return TRUE;
	}
//	MOD(S)	チューニング対応	K.Naono	03.07.03
/*
	ComSplitStringC split(IN_List);
	CStringArray* array;
	array = split.Split(',');

	for(int i=0;i<array->GetSize();i++){
		(*array)[i].TrimLeft();
		(*array)[i].TrimRight();
		if ((*array)[i].IsEmpty()) {
			return FALSE;
		}
		if((*array)[i][0] != '#')
			return FALSE;
		(*array)[i].TrimLeft('#');
		OUT_IDArray.Add( atoi( (*array)[i] ) );
	}
*/
	CStringArray	array ;
	int	nCount = GFn_SplitString(IN_List, ',' , array) ;
	for(int i = 0; i < nCount; i++) {
		array[i].TrimLeft() ;
		array[i].TrimRight() ;
		if(array[i][0] != '#')
			return FALSE ;
		array[i].TrimLeft('#') ;
		OUT_IDArray.Add(atoi(array[i])) ;
	}
//	MOD(E)	チューニング対応	K.Naono	03.07.03
	return TRUE;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp					作成日：2001.06.10
//
//	１．機能概要
//		PresentationSizeの登録
//
//	２．インターフェース
//		void	SXFTableManagerC::RegisterPresentationSize()
//		
//	引数	：	型		引数名				内容
//			INSTANCEDATA  IN_Instance  ｲﾝｽﾀﾝｽﾃﾞｰﾀｵﾌﾞｼﾞｪｸﾄのｱﾄﾞﾚｽ
//
//	３．履歴
//		履歴番号	日付け		   担当者	 概要
//		作成		2001.06.10	   佐々木(FQS)
//
//------------------------------------------------------------
BOOL SXFTableManagerC::RegisterPresentationSize(INSTANCEDATA *IN_Instance)
{
//	MOD(S)	チューニング対応	K.Naono	03.07.03
/*
	CStringArray* array;

	SXFSplitAP202C splitap202( 2,IN_Instance->EntityData );
	
	array = splitap202.Split();

	if(array==NULL)
		return FALSE;

	if(array->GetSize() !=2 )
		return FALSE;

	SXFMapEntAConvC convent(array);
*/
	CStringArray	array ;
	if( GFn_SplitSEntityAttr(IN_Instance->EntityData, array) != 2 )
		return FALSE ;

	SXFMapEntAConvC convent(&array) ;
//	MOD(E)	チューニング対応	K.Naono	03.07.03

	int sheetid;
	int planarboxid;

	if( convent.GetInst(0,sheetid) < 0 )
		return FALSE;

	if( convent.GetInst(1,planarboxid) < 0 )
		return FALSE;
	/*PresentationSize管理ｵﾌﾞｼﾞｪｸﾄ生成*/
	SXFPresentationSizeC* presentationsize = 
		new SXFPresentationSizeC();
	/*用紙IDセット*/
	presentationsize->sheetid = sheetid;
	/*planarbox IDセット*/
	presentationsize->planarboxid = planarboxid;
	/*PresentationSizeﾃｰﾌﾞﾙに追加*/
	m_PresentationSizeTable.Add(presentationsize);

	return TRUE;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp					作成日：2001.06.10
//
//	１．機能概要
//		Sheet Titleを登録する
//		
//	２．インターフェース
//		BOOL RegisterSheetTitle( INSTANCEDATA *IN_Instance )
//
//		引数: 型			  引数名			内容
//			  INSTANCEDATA*   IN_Instance		Instanceの
//												構造体のアドレス 
//		
//		復帰値	
//			  正常時：TRUE
//			  異常時：FALSE
//
//	３．履歴
//		履歴番号	日付け		   担当者	 概要
//		作成		2001.06.10	   佐々木(FQS)
//
//------------------------------------------------------------
BOOL SXFTableManagerC::RegisterSheetTitle(INSTANCEDATA *IN_Instance)
{
//	MOD(S)	チューニング対応	K.Naono	03.07.03
/*
	CStringArray* array;

	SXFSplitAP202C splitap202( 2,IN_Instance->EntityData );

	array = splitap202.Split();

	if(array==NULL)
		return FALSE;

	if(array->GetSize() !=3 )
		return FALSE;

	SXFMapEntAConvC convent(array);
*/
	CStringArray	array ;
	if( GFn_SplitSEntityAttr(IN_Instance->EntityData, array) != 3 )
		return FALSE ;

	SXFMapEntAConvC convent(&array) ;
//	MOD(E)	チューニング対応	K.Naono	03.07.03

	CArray<int,int> sheetidarray;
	int count;
	if( convent.GetSetInst(0,count,sheetidarray) < 0 )
		return FALSE;

	CString sheettitle;
	if ( convent.GetCString(2,sheettitle) < 0 )
		return FALSE;
	/*DranghtingTitle管理ｵﾌﾞｼﾞｪｸﾄ生成*/
	SXFDranghtingTitleC* dranghtingtitle =
		new SXFDranghtingTitleC();
	for(int i=0;i<sheetidarray.GetSize();i++){
		dranghtingtitle->sheetidlist.Add(sheetidarray[i]);
	}
	/*用紙ﾀｲﾄﾙｾｯﾄ*/
	dranghtingtitle->sheettitle = sheettitle;
	/*用紙ﾀｲﾄﾙﾃｰﾌﾞﾙに追加*/
	m_SheetTitleTable.Add(dranghtingtitle);

//	ADD(S)	Ver3.0対応	K.Naono	04.01.30
	RegisterAttribute(IN_Instance) ;
//	ADD(E)	Ver3.0対応	K.Naono	04.01.30

	return TRUE;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp					作成日：2001.06.10
//
//	１．機能概要
//		PlanarBox IDの取得
//		
//	２．インターフェース
//		BOOL GetPlanarBoxID(int IN_SheetID)
//
//		引数: 型			  引数名			内容
//			int			IN_SheetID		用紙ID
//		
//		復帰値	
//			  正常時：planarboxid
//
//	３．履歴
//		履歴番号	日付け		   担当者	 概要
//		作成		2001.06.10	   佐々木(FQS)
//
//------------------------------------------------------------
int SXFTableManagerC::GetPlanarBoxID(int IN_SheetID)
{
	int planarboxid = -1;

	for(int i=0;i<m_PresentationSizeTable.GetSize();i++){
		if(m_PresentationSizeTable[i]->sheetid == IN_SheetID ){
			planarboxid = m_PresentationSizeTable[i]->planarboxid;
			break;
		}
	}

	return planarboxid;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp					作成日：2001.06.10
//
//	１．機能概要
//		用紙タイトルの取得
//		
//	２．インターフェース
//	  BOOL SXFTableManagerC::GetSheetTitle(int IN_SheetID, CString& INOUT_SheetTitle)
//
//		引数: 型			  引数名			内容
//		int			 IN_SheetID			用紙ID
//		CString		 INOUT_SheetTitle	用紙タイトル   
//
//		復帰値	
//			  正常時：TRUE
//			  異常時：FALSE
//
//	３．履歴
//		履歴番号	日付け		   担当者	 概要
//		作成		2001.06.10	   佐々木(FQS)
//
//------------------------------------------------------------
BOOL SXFTableManagerC::GetSheetTitle(int IN_SheetID, CString& INOUT_SheetTitle)
{
	BOOL find = FALSE;
	for(int i=0;i<m_SheetTitleTable.GetSize();i++){
		for(int j=0;j<m_SheetTitleTable[i]->sheetidlist.GetSize();j++){
			if(m_SheetTitleTable[i]->sheetidlist[j] == IN_SheetID){
				INOUT_SheetTitle = (m_SheetTitleTable[i]->sheettitle);
				find = TRUE;
				break;
			}
		}
		if(find)
			break;
	}
	return find;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp                    作成日：2001.06.10
//
//	１．機能概要
//		図面表題欄の情報を設定する(WRITE時)
//
//	２．インターフェース
//		BOOL SXFTableManagerC::SetAttributeStruct(
//										LPVOID	IN_Struct)
//
//		引数:	型				引数名			内容
//			LPVOID		IN_Struct		図面表題欄構造体
//
//		復帰値	
//			正常時：TRUE
//			異常時：FALSE
//
//	３．履歴
//		履歴番号	日付け			担当者		概要
//		作成		2004.01.30		K.Naono		Ver3.0対応
//
//------------------------------------------------------------
BOOL SXFTableManagerC::SetAttributeStruct(
								LPVOID	IN_Struct)
{
	if( IN_Struct == NULL ) {
		return FALSE ;
	}

	//	既に図面表題欄情報が存在すれば、登録しない
	if( m_Attribute_Str != NULL ) {
		return TRUE ;
	}
	m_Attribute_Str = new Attribute_Struct ;
//	MOD(S)	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
//	strcpy(m_Attribute_Str->p_name,		((Attribute_Struct*)IN_Struct)->p_name) ;
//	strcpy(m_Attribute_Str->c_name,		((Attribute_Struct*)IN_Struct)->c_name) ;
//	strcpy(m_Attribute_Str->c_type,		((Attribute_Struct*)IN_Struct)->c_type) ;
//	strcpy(m_Attribute_Str->d_title,	((Attribute_Struct*)IN_Struct)->d_title) ;
//	strcpy(m_Attribute_Str->d_number,	((Attribute_Struct*)IN_Struct)->d_number) ;
//	strcpy(m_Attribute_Str->d_type,		((Attribute_Struct*)IN_Struct)->d_type) ;
//	strcpy(m_Attribute_Str->d_scale,	((Attribute_Struct*)IN_Struct)->d_scale) ;
	strcpy_s(m_Attribute_Str->p_name,	_countof(m_Attribute_Str->p_name),		((Attribute_Struct*)IN_Struct)->p_name) ;
	strcpy_s(m_Attribute_Str->c_name,	_countof(m_Attribute_Str->c_name),		((Attribute_Struct*)IN_Struct)->c_name) ;
	strcpy_s(m_Attribute_Str->c_type,	_countof(m_Attribute_Str->c_type),		((Attribute_Struct*)IN_Struct)->c_type) ;
	strcpy_s(m_Attribute_Str->d_title,	_countof(m_Attribute_Str->d_title),		((Attribute_Struct*)IN_Struct)->d_title) ;
	strcpy_s(m_Attribute_Str->d_number,	_countof(m_Attribute_Str->d_number),	((Attribute_Struct*)IN_Struct)->d_number) ;
	strcpy_s(m_Attribute_Str->d_type,	_countof(m_Attribute_Str->d_type),		((Attribute_Struct*)IN_Struct)->d_type) ;
	strcpy_s(m_Attribute_Str->d_scale,	_countof(m_Attribute_Str->d_scale),		((Attribute_Struct*)IN_Struct)->d_scale) ;
//	MOD(E)	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
	m_Attribute_Str->d_year	= 			((Attribute_Struct*)IN_Struct)->d_year ;
	m_Attribute_Str->d_month= 			((Attribute_Struct*)IN_Struct)->d_month ;
	m_Attribute_Str->d_day	= 			((Attribute_Struct*)IN_Struct)->d_day ;
//	MOD(S)	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
//	strcpy(m_Attribute_Str->c_contractor,	((Attribute_Struct*)IN_Struct)->c_contractor) ;
//	strcpy(m_Attribute_Str->c_owner,		((Attribute_Struct*)IN_Struct)->c_owner) ;
	strcpy_s(m_Attribute_Str->c_contractor,	_countof(m_Attribute_Str->c_contractor),	((Attribute_Struct*)IN_Struct)->c_contractor) ;
	strcpy_s(m_Attribute_Str->c_owner,		_countof(m_Attribute_Str->c_owner),			((Attribute_Struct*)IN_Struct)->c_owner) ;
//	MOD(E)	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
	return TRUE ;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp                    作成日：2001.06.10
//
//	１．機能概要
//		図面表題欄の情報を返却する(WRITE時)
//
//	２．インターフェース
//		Attribute_Struct* SXFTableManagerC::GetAttributeStruct()
//
//		引数:	型				引数名			内容
//			なし
//
//		復帰値	
//			正常時：図面表題欄情報
//			異常時：NULL
//
//	３．履歴
//		履歴番号	日付け			担当者		概要
//		作成		2004.01.30		K.Naono		Ver3.0対応
//
//------------------------------------------------------------
Attribute_Struct* SXFTableManagerC::GetAttributeStruct()
{
	return m_Attribute_Str ;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp                    作成日：2001.06.10
//
//	１．機能概要
//		図面表題欄の情報を返却する(READ時)
//
//	２．インターフェース
//		void SXFTableManagerC::GetAttributeData(
//										Attribute_Struct*	OUT_Attr)
//
//		引数:	型				引数名			内容
//			Attribute_Struct*	OUT_Attr		図面表題欄情報の格納領域
//
//		復帰値	
//			なし
//
//	３．履歴
//		履歴番号	日付け			担当者		概要
//		作成		2004.01.30		K.Naono		Ver3.0対応
//
//------------------------------------------------------------
void SXFTableManagerC::GetAttributeData(
								Attribute_Struct*	OUT_Attr)
{
	if( OUT_Attr == NULL ) {
		return ;
	}

	//	初期化
	ZeroMemory(OUT_Attr->p_name,		sizeof(OUT_Attr->p_name)) ;
	ZeroMemory(OUT_Attr->c_name,		sizeof(OUT_Attr->c_name)) ;
	ZeroMemory(OUT_Attr->c_type,		sizeof(OUT_Attr->c_type)) ;
	ZeroMemory(OUT_Attr->d_title,		sizeof(OUT_Attr->d_title)) ;
	ZeroMemory(OUT_Attr->d_number,		sizeof(OUT_Attr->d_number)) ;
	ZeroMemory(OUT_Attr->d_type,		sizeof(OUT_Attr->d_type)) ;
	ZeroMemory(OUT_Attr->d_scale,		sizeof(OUT_Attr->d_scale)) ;
	ZeroMemory(OUT_Attr->c_contractor,	sizeof(OUT_Attr->c_contractor)) ;
	ZeroMemory(OUT_Attr->c_owner,		sizeof(OUT_Attr->c_owner)) ;
	OUT_Attr->d_year = OUT_Attr->d_month = OUT_Attr->d_day = 0 ;

	if( m_id_draug_drw_rev == -1 ) {
		return ;
	}

	//	図面表題欄情報の取得
	ATTRIBUTEINFO*	attr_info = GetAttributeInfo(m_id_draug_drw_rev) ;
	if( attr_info == NULL ) {
		return ;
	}

	//	図面表題欄情報をコピー
//	MOD(S)	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
//	strcpy(OUT_Attr->p_name,	attr_info->attr_body.p_name) ;
//	strcpy(OUT_Attr->c_name,	attr_info->attr_body.c_name) ;
//	strcpy(OUT_Attr->c_type,	attr_info->attr_body.c_type) ;
//	strcpy(OUT_Attr->d_title,	attr_info->attr_body.d_title) ;
//	strcpy(OUT_Attr->d_number,	attr_info->attr_body.d_number) ;
//	strcpy(OUT_Attr->d_type,	attr_info->attr_body.d_type) ;
//	strcpy(OUT_Attr->d_scale,	attr_info->attr_body.d_scale) ;
	strcpy_s(OUT_Attr->p_name,	_countof(OUT_Attr->p_name),		attr_info->attr_body.p_name) ;
	strcpy_s(OUT_Attr->c_name,	_countof(OUT_Attr->c_name),		attr_info->attr_body.c_name) ;
	strcpy_s(OUT_Attr->c_type,	_countof(OUT_Attr->c_type),		attr_info->attr_body.c_type) ;
	strcpy_s(OUT_Attr->d_title,	_countof(OUT_Attr->d_title),	attr_info->attr_body.d_title) ;
	strcpy_s(OUT_Attr->d_number,_countof(OUT_Attr->d_number),	attr_info->attr_body.d_number) ;
	strcpy_s(OUT_Attr->d_type,	_countof(OUT_Attr->d_type),		attr_info->attr_body.d_type) ;
	strcpy_s(OUT_Attr->d_scale,	_countof(OUT_Attr->d_scale),	attr_info->attr_body.d_scale) ;
//	MOD(E)	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
	OUT_Attr->d_year	= 		attr_info->attr_body.d_year ;
	OUT_Attr->d_month	= 		attr_info->attr_body.d_month ;
	OUT_Attr->d_day		= 		attr_info->attr_body.d_day ;
//	MOD(S)	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
//	strcpy(OUT_Attr->c_contractor,	attr_info->attr_body.c_contractor) ;
//	strcpy(OUT_Attr->c_owner,		attr_info->attr_body.c_owner) ;
	strcpy_s(OUT_Attr->c_contractor,_countof(OUT_Attr->c_contractor),	attr_info->attr_body.c_contractor) ;
	strcpy_s(OUT_Attr->c_owner,		_countof(OUT_Attr->c_owner),		attr_info->attr_body.c_owner) ;
//	MOD(E)	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp                    作成日：2001.06.10
//
//	１．機能概要
//		インスタンスデータより、図面表題欄の情報を取得する(READ時)
//
//	２．インターフェース
//		BOOL SXFTableManagerC::RegisterAttribute(
//										INSTANCEDATA*	IN_Instance)
//
//		引数:	型				引数名			内容
//			INSTANCEDATA*		IN_Instance		ｲﾝｽﾀﾝｽﾃﾞｰﾀｵﾌﾞｼﾞｪｸﾄのｱﾄﾞﾚｽ
//
//		復帰値	
//			正常時：TRUE
//			異常時：FALSE
//
//	３．履歴
//		履歴番号	日付け			担当者		概要
//		作成		2004.01.30		K.Naono		Ver3.0対応
//
//------------------------------------------------------------
BOOL SXFTableManagerC::RegisterAttribute(
								INSTANCEDATA*	IN_Instance)
{
	if( m_InstanceIDManager == NULL ) {
		return FALSE ;
	}

	char	szInstanceId[256] ;

	//	#5170=DRAWING_DEFINITION('\X2\56F39762756A53F7\X0\4','\X2\56F397627A2E5225\X0\4');
	//	#5180=DRAUGHTING_DRAWING_REVISION('01',#5170,'\X2\5C3A5EA6\X0\4');
	//	#5190=DRAUGHTING_TITLE((#5180),'JAPANESE','\X2\56F39762540D\X0\4');
	if( IN_Instance->EntityName == DEF_DRAUGHTING_TITLE ) {

		CStringArray	array1 ;
		if( GFn_SplitSEntityAttr(IN_Instance->EntityData, array1) != 3 )
			return FALSE ;

		SXFMapEntAConvC	convent1(&array1) ;
		CString	d_title ;
		if( convent1.GetCString(2, d_title) < 0 )
			return FALSE ;

		CArray<int,int>	idarray ;
		int	count = 0 ;
		if( convent1.GetSetInst(0, count,idarray) < 0 )
			return FALSE;

		SXFEntityDataC*	draw_rev_ent = NULL ;
		for(int i = 0; i < idarray.GetSize(); i++) {
			draw_rev_ent = m_InstanceIDManager->GetEntityDataPtr(idarray[i]) ;
			if( draw_rev_ent != NULL ) {
				ATTRIBUTEINFO*	attr_info = new ATTRIBUTEINFO ;
				attr_info->id_draug_drw_rev = idarray[i] ;
				//	図面名の取得
				if( lstrlen(d_title) <= 256 ) {
					lstrcpy(attr_info->attr_body.d_title, (LPCTSTR)d_title) ;
				} else {
					//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
					//sprintf(szInstanceId, "#%d", IN_Instance->InstanceID) ;
					sprintf_s(szInstanceId,_countof(szInstanceId), "#%d", IN_Instance->InstanceID) ;
					SXFErrorMsgC::RecordError(SXFNAMELENGTH,
												DEF_DRAUGHTING_TITLE,
												2,
												szInstanceId,
												DEF_DRAUGHTING_TITLE) ;
					// 先頭から256バイト切り取る
					lstrcpyn(attr_info->attr_body.d_title, (LPCTSTR)d_title, 256) ;
				}
				CString	draw_rev_data ;
				if( !draw_rev_ent->GetEntityData(draw_rev_data) ) {
					return FALSE ;
				}

				CStringArray	array2 ;
				if( GFn_SplitSEntityAttr(draw_rev_data, array2) != 3 )
					return FALSE ;

				SXFMapEntAConvC	convent2(&array2) ;
				CString	scale ;
				if( convent2.GetCString(2, scale) < 0 )
					return FALSE ;
				//	尺度の取得
				if( lstrlen(scale) <= 256 ) {
					lstrcpy(attr_info->attr_body.d_scale, (LPCTSTR)scale) ;
				} else {
					//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
					//sprintf(szInstanceId, "#%d", idarray[i]) ;
					sprintf_s(szInstanceId,_countof(szInstanceId), "#%d", idarray[i]) ;
					SXFErrorMsgC::RecordError(SXFNAMELENGTH,
												DEF_DRAUGHTING_DRAWING_REVISION,
												2,
												szInstanceId,
												DEF_DRAUGHTING_DRAWING_REVISION) ;
					// 先頭から256バイト切り取る
					lstrcpyn(attr_info->attr_body.d_scale, (LPCTSTR)scale, 256) ;
				}

				int	def_id = 0 ;
				if( convent2.GetInst(1, def_id) < 0 )
					return FALSE ;
				SXFEntityDataC*	def_ent = m_InstanceIDManager->GetEntityDataPtr(def_id) ;
				if( def_ent == NULL )
					return FALSE ;

				CString	def_data ;
				if( !def_ent->GetEntityData(def_data) ) {
					return FALSE ;
				}

				CStringArray	array3 ;
				if( GFn_SplitSEntityAttr(def_data, array3) != 2 )
					return FALSE ;

				SXFMapEntAConvC	convent3(&array3) ;
				CString	d_number, d_type ;
				//	図面番号の取得
				if( convent3.GetCString(0, d_number) < 0 )
					return FALSE ;
				if( lstrlen(d_number) <= 256 ) {
					lstrcpy(attr_info->attr_body.d_number, (LPCTSTR)d_number) ;
				} else {
					// 先頭から256バイト切り取る
					lstrcpyn(attr_info->attr_body.d_number, (LPCTSTR)d_number, 256) ;
				}
				//	図面種別の取得
				if( convent3.GetCString(1, d_type) < 0 )
					return FALSE ;
				if( lstrlen(d_type) <= 256 ) {
					lstrcpy(attr_info->attr_body.d_type, (LPCTSTR)d_type) ;
				} else {
					//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
					//sprintf(szInstanceId, "#%d", def_id) ;
					sprintf_s(szInstanceId,_countof(szInstanceId), "#%d", def_id) ;
					SXFErrorMsgC::RecordError(SXFNAMELENGTH,
												DEF_DRAWING_DEFINITION,
												2,
												szInstanceId,
												DEF_DRAWING_DEFINITION) ;
					// 先頭から256バイト切り取る
					lstrcpyn(attr_info->attr_body.d_type, (LPCTSTR)d_type, 256) ;
				}

				m_AttributeTable.Add(attr_info) ;
			}
		}
		return TRUE ;
	}

	//	#5300=CONTRACT_TYPE('\X2\59517D04533A5206\X0\4');
	//	#5310=CONTRACT('\X2\5DE54E8B540D\X0\4','\X2\4E8B696D540D\X0\4',#5300);
	//	#5320=DRAUGHTING_CONTRACT_ASSIGNMENT(#5310,(#5180));
	if( IN_Instance->EntityName == DEF_DRAUGHTING_CONTRACT_ASSIGNMENT ) {

		CStringArray	array1 ;
		if( GFn_SplitSEntityAttr(IN_Instance->EntityData, array1) != 2 )
			return FALSE ;

		SXFMapEntAConvC	convent1(&array1) ;
		int	con_id = 0 ;
		if( convent1.GetInst(0, con_id) < 0 )
			return FALSE ;

		CArray<int,int>	idarray ;
		int	count = 0 ;
		if( convent1.GetSetInst(1, count, idarray) < 0 )
			return FALSE;

		SXFEntityDataC*	con_ent = m_InstanceIDManager->GetEntityDataPtr(con_id) ;
		if( con_ent == NULL )
			return FALSE ;

		CString	con_data ;
		if( !con_ent->GetEntityData(con_data) ) {
			return FALSE ;
		}

		CStringArray	array2 ;
		if( GFn_SplitSEntityAttr(con_data, array2) != 3 )
			return FALSE ;

		SXFMapEntAConvC	convent2(&array2) ;
		CString	c_name, p_name ;
		if( convent2.GetCString(0, c_name) < 0 )
			return FALSE ;
		if( convent2.GetCString(1, p_name) < 0 )
			return FALSE ;

		int	con_type_id = 0 ;
		if( convent2.GetInst(2, con_type_id) < 0 )
			return FALSE ;

		SXFEntityDataC*	con_type_ent = m_InstanceIDManager->GetEntityDataPtr(con_type_id) ;
		if( con_type_ent == NULL )
			return FALSE ;

		CString	con_type_data ;
		if( !con_type_ent->GetEntityData(con_type_data) ) {
			return FALSE ;
		}

		CStringArray	array3 ;
		if( GFn_SplitSEntityAttr(con_type_data, array3) != 1 )
			return FALSE ;

		SXFMapEntAConvC	convent3(&array3) ;
		CString	c_type ;
		if( convent3.GetCString(0, c_type) < 0 )
			return FALSE ;

		for(int i = 0; i < idarray.GetSize(); i++) {
			ATTRIBUTEINFO*	attr_info = GetAttributeInfo(idarray[i]) ;
			if( attr_info != NULL ) {
				//	DRAUGHTING_CONTRACT_ASSIGNMENTのインスタンスID設定
				attr_info->id_draug_con_ass = IN_Instance->InstanceID ;
				//	工事名の取得
				if( lstrlen(c_name) <= 256 ) {
					lstrcpy(attr_info->attr_body.c_name, (LPCTSTR)c_name) ;
				} else {
					//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
					//sprintf(szInstanceId, "#%d", con_id) ;
					sprintf_s(szInstanceId,_countof(szInstanceId), "#%d", con_id) ;
					SXFErrorMsgC::RecordError(SXFNAMELENGTH,
												DEF_CONTRACT,
												2,
												szInstanceId,
												DEF_CONTRACT) ;
					// 先頭から256バイト切り取る
					lstrcpyn(attr_info->attr_body.c_name, (LPCTSTR)c_name, 256) ;
				}
				//	事業名の取得
				if( lstrlen(p_name) <= 256 ) {
					lstrcpy(attr_info->attr_body.p_name, (LPCTSTR)p_name) ;
				} else {
					//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
					//sprintf(szInstanceId, "#%d", con_id) ;
					sprintf_s(szInstanceId,_countof(szInstanceId), "#%d", con_id) ;
					SXFErrorMsgC::RecordError(SXFNAMELENGTH,
												DEF_CONTRACT,
												2,
												szInstanceId,
												DEF_CONTRACT) ;
					// 先頭から256バイト切り取る
					lstrcpyn(attr_info->attr_body.p_name, (LPCTSTR)p_name, 256) ;
				}
				//	契約区分の取得
				if( lstrlen(c_type) <= 256 ) {
					lstrcpy(attr_info->attr_body.c_type, (LPCTSTR)c_type) ;
				} else {
					//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
					//sprintf(szInstanceId, "#%d", con_type_id) ;
					sprintf_s(szInstanceId,_countof(szInstanceId), "#%d", con_type_id) ;
					SXFErrorMsgC::RecordError(SXFNAMELENGTH,
												DEF_CONTRACT_TYPE,
												2,
												szInstanceId,
												DEF_CONTRACT_TYPE) ;
					// 先頭から256バイト切り取る
					lstrcpyn(attr_info->attr_body.c_type, (LPCTSTR)c_type, 256) ;
				}
			}
		}

	//	#5340=APPROVAL_STATUS(' ');
	//	#5350=APPROVAL(#5340,' ');
	//	#5330=CALENDAR_DATE(2002,4,12);
	//	#5360=APPROVAL_DATE_TIME(#5330,#5350);
	} else if( IN_Instance->EntityName == DEF_APPROVAL_DATE_TIME ) {

		CStringArray	array1 ;
		if( GFn_SplitSEntityAttr(IN_Instance->EntityData, array1) != 2 )
			return FALSE ;

		SXFMapEntAConvC	convent1(&array1) ;
		int	cal_id = 0, app_id = 0 ;
		if( convent1.GetInst(0, cal_id) < 0 )
			return FALSE ;
		if( convent1.GetInst(1, app_id) < 0 )
			return FALSE ;

		APPDATETIMEINFO	app_info ;
		app_info.id_cal_date = cal_id ;
		app_info.id_approval = app_id ;
		m_AppTimeTable.Add(app_info) ;

	//	#5370=DRAUGHTING_APPROVAL_ASSIGNMENT(#5350,(#5180));
	} else if( IN_Instance->EntityName == "DRAUGHTING_APPROVAL_ASSIGNMENT" ) {

		CStringArray	array1 ;
		if( GFn_SplitSEntityAttr(IN_Instance->EntityData, array1) != 2 )
			return FALSE ;

		SXFMapEntAConvC	convent1(&array1) ;
		int	app_id = 0 ;
		if( convent1.GetInst(0, app_id) < 0 )
			return FALSE ;

		int	cal_id = -1 ;
		for(int i = 0; i < m_AppTimeTable.GetSize(); i++) {
			if( app_id == m_AppTimeTable[i].id_approval ) {
				cal_id = m_AppTimeTable[i].id_cal_date ;
				break ;
			}
		}
		if( cal_id == -1 ) {
			return FALSE ;
		}

		CArray<int,int>	idarray ;
		int	count = 0 ;
		if( convent1.GetSetInst(1, count, idarray) < 0 )
			return FALSE ;

		SXFEntityDataC*	cal_ent = m_InstanceIDManager->GetEntityDataPtr(cal_id) ;
		if( cal_ent == NULL )
			return FALSE ;

		CString	cal_data ;
		if( !cal_ent->GetEntityData(cal_data) ) {
			return FALSE ;
		}

		CStringArray	array2 ;
		if( GFn_SplitSEntityAttr(cal_data, array2) != 3 )
			return FALSE ;

		SXFMapEntAConvC	convent2(&array2) ;
		int	year, day, month ;
		if( convent2.GetInt(0, year) < 0 )
			return FALSE ;
		if( convent2.GetInt(1, day) < 0 )
			return FALSE ;
		if( convent2.GetInt(2, month) < 0 )
			return FALSE ;

		for(i = 0; i < idarray.GetSize(); i++) {
			ATTRIBUTEINFO*	attr_info = GetAttributeInfo(idarray[i]) ;
			if( attr_info != NULL ) {
				//	図面作成年(西暦)の取得
				attr_info->attr_body.d_year	= 	year ;
				//	図面作成月(西暦)の取得
				attr_info->attr_body.d_day	= 	day ;
				//	図面作成日(西暦)の取得
				attr_info->attr_body.d_month= 	month ;
			}
		}

	//	#5390=ORGANIZATION_ROLE('creator');
	//	#5380=ORGANIZATION($,'\X2\8A2D8A084F1A793E540D\X0\4',' ');
	//	#5400=DRAUGHTING_ORGANIZATION_ASSIGNMENT(#5380,#5390,(#5180));
	} else if( IN_Instance->EntityName == DEF_DRAUGHTING_ORGANIZATION_ASSIGNMENT ) {

		CStringArray	array1 ;
		if( GFn_SplitSEntityAttr(IN_Instance->EntityData, array1) != 3 )
			return FALSE ;

		SXFMapEntAConvC	convent1(&array1) ;
		int	org_id = 0, rol_id = 0 ;
		if( convent1.GetInst(0, org_id) < 0 )
			return FALSE ;
		if( convent1.GetInst(1, rol_id) < 0 )
			return FALSE ;
		CArray<int,int>	idarray ;
		int	count = 0 ;
		if( convent1.GetSetInst(2, count, idarray) < 0 )
			return FALSE ;

		SXFEntityDataC*	org_ent = m_InstanceIDManager->GetEntityDataPtr(org_id) ;
		if( org_ent == NULL )
			return FALSE ;

		CString	org_data ;
		if( !org_ent->GetEntityData(org_data) ) {
			return FALSE ;
		}

		CStringArray	array2 ;
		int	nCnt = GFn_SplitSEntityAttr(org_data, array2) ;
		if( nCnt > 3 || nCnt < 2 ) {
			return FALSE ;
		}
		SXFMapEntAConvC	convent2(&array2) ;

		SXFEntityDataC*	rol_ent = m_InstanceIDManager->GetEntityDataPtr(rol_id) ;
		if( rol_ent == NULL )
			return FALSE ;

		CString	rol_data ;
		if( !rol_ent->GetEntityData(rol_data) ) {
			return FALSE ;
		}

		CStringArray	array3 ;
		if( GFn_SplitSEntityAttr(rol_data, array3) != 1 )
			return FALSE ;

		SXFMapEntAConvC	convent3(&array3) ;
		CString	rol_name ;
		if( convent3.GetCString(0, rol_name) < 0 )
			return FALSE ;

		CString	name ;
		if( array2.GetSize() == 2 ) {
			if( convent2.GetCString(0, name) < 0 )
				return FALSE ;
		} else {
			if( convent2.GetCString(1, name) < 0 )
				return FALSE ;
		}

		for(int i = 0; i < idarray.GetSize(); i++) {
			ATTRIBUTEINFO*	attr_info = GetAttributeInfo(idarray[i]) ;
			if( attr_info != NULL ) {
				if( !rol_name.CompareNoCase("creator") ) {
					//	受注会社名の取得
					if( lstrlen(name) <= 256 ) {
						lstrcpy(attr_info->attr_body.c_contractor, (LPCTSTR)name) ;
					} else {
						//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
						//sprintf(szInstanceId, "#%d", org_id) ;
						sprintf_s(szInstanceId,_countof(szInstanceId), "#%d", org_id) ;
						SXFErrorMsgC::RecordError(SXFNAMELENGTH,
													DEF_ORGANIZATION,
													2,
													szInstanceId,
													DEF_ORGANIZATION) ;
						// 先頭から256バイト切り取る
						lstrcpyn(attr_info->attr_body.c_contractor, (LPCTSTR)name, 256) ;
					}
				} else if( !rol_name.CompareNoCase("owner") ) {
					//	発注事業者名の取得
					if( lstrlen(name) <= 256 ) {
						lstrcpy(attr_info->attr_body.c_owner, (LPCTSTR)name) ;
					} else {
						//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
						//sprintf(szInstanceId, "#%d", org_id) ;
						sprintf_s(szInstanceId,_countof(szInstanceId), "#%d", org_id) ;
						SXFErrorMsgC::RecordError(SXFNAMELENGTH,
													DEF_ORGANIZATION,
													2,
													szInstanceId,
													DEF_ORGANIZATION) ;
						// 先頭から256バイト切り取る
						lstrcpyn(attr_info->attr_body.c_owner, (LPCTSTR)name, 256) ;
					}
				}
			}
		}
	}

	return TRUE ;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp                    作成日：2001.06.10
//
//	１．機能概要
//		DRAUGHTING_CONTRACT_ASSIGNMENTのインスタンスIDを返却する
//
//	２．インターフェース
//		int SXFTableManagerC::GetAttributeID()
//
//		引数:	型				引数名			内容
//			なし
//
//		復帰値	
//			正常時：インスタンスID
//			異常時：-1
//
//	３．履歴
//		履歴番号	日付け			担当者		概要
//		作成		2004.01.30		K.Naono		Ver3.0対応
//
//------------------------------------------------------------
int SXFTableManagerC::GetAttributeID()
{
	if( m_id_draug_drw_rev == -1 ) {
		return -1 ;
	}

	//	カレントのDRAUGHTING_DRAWING_REVISIONに対応する
	//	DRAUGHTING_CONTRACT_ASSIGNMENTのインスタンスIDを検索する
	for(int i = 0; i < m_AttributeTable.GetSize(); i++) {
		if( m_AttributeTable[i]->id_draug_drw_rev == m_id_draug_drw_rev ) {
			return m_AttributeTable[i]->id_draug_con_ass ;
		}
	}

	return -1 ;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableManagerC.cpp                    作成日：2001.06.10
//
//	１．機能概要
//		指定したDRAUGHTING_DRAWING_REVISIONの図面表題欄情報を
//		返却する
//
//	２．インターフェース
//		ATTRIBUTEINFO* SXFTableManagerC::GetAttributeInfo(int inID)
//
//		引数:	型				引数名			内容
//				int				inID		インスタンスID
//
//		復帰値	
//			正常時：図面表題欄情報
//			異常時：NULL
//
//	３．履歴
//		履歴番号	日付け			担当者		概要
//		作成		2004.01.30		K.Naono		Ver3.0対応
//
//------------------------------------------------------------
ATTRIBUTEINFO* SXFTableManagerC::GetAttributeInfo(int inID) {

	//	DRAUGHTING_DRAWING_REVISIONに対応する図面表題欄情報を検索
	for(int i = 0; i < m_AttributeTable.GetSize(); i++) {
		if( m_AttributeTable[i]->id_draug_drw_rev == inID ) {
			return m_AttributeTable[i] ;
		}
	}
	return NULL ;
}
