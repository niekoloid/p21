/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableMapManagerC.cpp								作成日：2001.06.14

	１．クラス概要
	定義テーブルフィーチャオブジェクトとMappingオブジェクトを管理するクラス

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.14			佐々木(FQS)			なし。

**/
#include "stdafx.h"
#include "SXFTableManagerC.h"
#include "SXFMapTableC.h"
#include "SXFTableMapManagerC.h"
#include "SXFPreColourMappingC.h"
#include "SXFPreTypeMappingC.h"
#include "SXFUserColourMappingC.h"
#include "SXFUserTypeMappingC.h"
#include "SXFLayerMappingC.h"
#include "SXFLineWidthMappingC.h"
#include "SXFTextFontMappingC.h"
#include "SXFTableFeatureC.h"
#include "SXFPart21FileC.h"
#include "SXFPreDefColorC.h"
#include "SXFLayerC.h"
#include "SXFInvisibilityMappingC.h"
#include "SXFComInfoC.h"
#include "SXFPart21FileWriteC.h"
#include "SXFInstanceIDC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableMapManagerC.cpp								作成日：2001.06.14

	１．機能概要
	コンストラクタ

	２．インターフェース
	void	SXFTableMapManagerC::SXFTableMapManagerC()
	引数:	型								引数名				内容
			なし					

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.14			佐々木(FQS)			なし。

**/
SXFTableMapManagerC::SXFTableMapManagerC()
{
	m_PreColourMapping = NULL;
	m_PreTypeMapping = NULL;
	m_UserColourMapping = NULL;
	m_UserTypeMapping = NULL;
	m_LayerMapping = NULL;
	m_LineWidthMapping = NULL;
	m_TextFontMapping = NULL;
	m_TableFeature = NULL;
	m_LayerFeature = NULL;
	m_InvisibilityMapping = NULL;
	m_ComInfo = NULL;
	m_WriteFile = NULL;
	m_InstanceIDManager = NULL;
	m_MapTable = NULL;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableMapManagerC.cpp								作成日：2001.06.14

	１．機能概要
	コンストラクタ

	２．インターフェース
	void	SXFTableMapManagerC(SXFPart21FileC* IN_File)
	引数:	型								引数名				内容
			SXFPart21FileC*					IN_File		ﾌｧｲﾙｵﾌﾞｼﾞｪｸﾄ

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.14			佐々木(FQS)			なし。

**/
SXFTableMapManagerC::SXFTableMapManagerC(SXFPart21FileC* IN_File)
{
	m_File = IN_File;
	m_PreColourMapping = NULL;
	m_PreTypeMapping = NULL;
	m_UserColourMapping = NULL;
	m_UserTypeMapping = NULL;
	m_LayerMapping = NULL;
	m_LineWidthMapping = NULL;
	m_TextFontMapping = NULL;
	m_TableFeature = NULL;
	m_LayerFeature = NULL;
	m_InvisibilityMapping = NULL;
	m_ComInfo = NULL;
	m_WriteFile = NULL;
	m_InstanceIDManager = NULL;
	m_MapTable = NULL;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableMapManagerC.cpp								作成日：2001.06.14

	１．機能概要
	コンストラクタ

	２．インターフェース
	void	SXFTableMapManagerC(SXFPart21FileC* IN_File,
								SXFComInfoC* IN_ComInfo,
								SXFPart21FileWriteC* IN_WriteFile,
								SXFInstanceIDC* IN_InstanceIDManager)
	引数:	型								引数名				内容
			SXFPart21FileC*					IN_File					ﾌｧｲﾙｵﾌﾞｼﾞｪｸﾄ
			SXFComInfoC* 					IN_ComInfo				共通情報管理ｵﾌﾞｼﾞｪｸﾄ
			SXFPart21FileWriteC* 			IN_WriteFile			ﾌｧｲﾙ出力ｵﾌﾞｼﾞｪｸﾄ
			SXFInstanceIDC* 				IN_InstanceIDManager	ｲﾝｽﾀﾝｽID管理ｵﾌﾞｼﾞｪｸﾄ

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.14			佐々木(FQS)			なし。

**/
SXFTableMapManagerC::SXFTableMapManagerC(SXFPart21FileC* IN_File,SXFComInfoC* IN_ComInfo,SXFPart21FileWriteC* IN_WriteFile,SXFInstanceIDC* IN_InstanceIDManager)
{
	m_PreColourMapping = NULL;
	m_PreTypeMapping = NULL;
	m_UserColourMapping = NULL;
	m_UserTypeMapping = NULL;
	m_LayerMapping = NULL;
	m_LineWidthMapping = NULL;
	m_TextFontMapping = NULL;
	m_TableFeature = NULL;
	m_LayerFeature = NULL;
	m_File = IN_File;
	m_ComInfo = IN_ComInfo;
	m_WriteFile = IN_WriteFile;
	m_InstanceIDManager = IN_InstanceIDManager;
	m_InvisibilityMapping = NULL;
	m_MapTable = NULL;

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableMapManagerC.cpp								作成日：2001.06.14

	１．機能概要
	デストラクタ

	２．インターフェース
	void	SXFTableMapManagerC::~SXFTableMapManagerC()
	引数:	型								引数名				内容
			なし					

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.14			佐々木(FQS)			なし。

**/
SXFTableMapManagerC::~SXFTableMapManagerC()
{
	if (m_PreColourMapping != NULL)
		delete m_PreColourMapping;
	if (m_PreTypeMapping != NULL)
		delete m_PreTypeMapping;
	if (m_UserColourMapping != NULL)
		delete m_UserColourMapping;
	if (m_UserTypeMapping != NULL)
		delete m_UserTypeMapping;
	if (m_LayerMapping != NULL)
		delete m_LayerMapping;
	if (m_LineWidthMapping != NULL)
		delete m_LineWidthMapping;
	if (m_TextFontMapping != NULL)
		delete m_TextFontMapping;
	if (m_TableFeature != NULL)
		delete m_TableFeature;
	if (m_LayerFeature != NULL)
		delete m_LayerFeature;
	if (m_InvisibilityMapping != NULL)
		delete m_InvisibilityMapping;

	if(m_MapTable != NULL)
		delete m_MapTable;

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableMapManagerC.cpp								作成日：2001.06.14

	１．機能概要
	構造体の生成

	２．インターフェース
	BOOL SetStructData(int IN_type, LPVOID IN_Struct)
	引数:	型				引数名				内容
			int				IN_type				テーブル型
			LPVOID			IN_Struct			構造体
	復帰値	正常時：TRUE
			異常時：FALSE

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.14			佐々木(FQS)			なし。

**/
BOOL SXFTableMapManagerC::SetStructData(int IN_type, LPVOID IN_Struct)
{
	switch(IN_type)
	{
	case 1://layer
		return FALSE;
		break;
	case 2://既定義色
		return FALSE;
		break;
	case 3://ユーザ色
		m_UserColourMapping = new SXFUserColourMappingC();
		if (m_UserColourMapping->MappingStruct((Userdefined_Colour_Struct*)IN_Struct)){
			return TRUE;
		}
		else
			return FALSE;
		break;
	case 4://既定義線種
		m_PreTypeMapping = new SXFPreTypeMappingC();
		if (m_PreTypeMapping->MappingStruct((Predefined_Linetype_Struct*)IN_Struct)){
			return TRUE;
		}
		else
			return FALSE;
		break;
	case 5://ユーザ線種
		m_UserTypeMapping = new SXFUserTypeMappingC();
		if (m_UserTypeMapping->MappingStruct((Userdefined_Linetype_Struct*)IN_Struct)){
			return TRUE;
		}
		else
			return FALSE;
		break;
	case 6://線幅
		m_LineWidthMapping = new SXFLineWidthMappingC();
		if (m_LineWidthMapping->MappingStruct((Line_Width_Struct*)IN_Struct)){
			return TRUE;
		}
		else
			return FALSE;
		break;
	case 7://文字フォント
		m_TextFontMapping = new SXFTextFontMappingC();
		if (m_TextFontMapping->MappingStruct((Text_Font_Struct*)IN_Struct)){
			return TRUE;
		}
		else
			return FALSE;
		break;
	default:
		return FALSE;
		break;
	}
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableMapManagerC.cpp								作成日：2001.06.14

	１．機能概要
	インスタンスIDの取得

	２．インターフェース
	int GetInstanceID(int IN_table_type)
	引数:	型				引数名				内容
			int				IN_type		テーブル型

	復帰値	正常時：インスタンスID
			異常時：0

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.14			佐々木(FQS)			なし。

**/
int SXFTableMapManagerC::GetInstanceID(int IN_table_type)
{
	int ID = 0;
	switch(IN_table_type)
	{
	case 1://layer
		ID = m_LayerMapping->GetID();
		break;
	case 2://既定義色
		ID = m_PreColourMapping->GetID();
		break;
	case 3://ユーザ色
		ID = m_UserColourMapping->GetID();
		break;
	case 4://既定義線種
		ID = m_PreTypeMapping->GetID();
		break;
	case 5://ユーザ線種
		ID = m_UserTypeMapping->GetID();
		break;
	case 6://線幅
		ID = m_LineWidthMapping->GetID();
		break;
	case 7://文字フォント
		ID = m_TextFontMapping->GetID();
		break;
	default:
		return -1;
		break;
	}
	return ID;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableMapManagerC.cpp								作成日：2001.06.14

	１．機能概要
	インスタンスをファイルへ出力する

	２．インターフェース
	BOOL WriteInstance(int IN_Type)
	引数:	型				引数名			内容
			int				IN_Type			テーブル型

	復帰値	正常時：TRUE
			異常時：FALSE

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.14			佐々木(FQS)			なし。

**/
BOOL SXFTableMapManagerC::WriteInstance(int IN_Type)
{
	switch(IN_Type)
	{
	case 1://layer
		m_LayerMapping->WriteAP202(m_File);
		break;
	case 2://既定義色
		m_PreColourMapping->WriteAP202(m_File);
		break;
	case 3://ユーザ色
		m_UserColourMapping->WriteAP202(m_File);
		break;
	case 4://既定義線種
		m_PreTypeMapping->WriteAP202(m_File);
		break;
	case 5://ユーザ線種
		m_UserTypeMapping->WriteAP202(m_File);
		break;
	case 6://線幅
		m_LineWidthMapping->WriteAP202(m_File);
		break;
	case 7://文字フォント
		m_TextFontMapping->WriteAP202(m_File);
		break;
	default:
		return FALSE;
		break;
	}
	return TRUE;

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableMapManagerC.cpp								作成日：2001.06.14

	１．機能概要
	既定義色の構造体の生成(READ)

	２．インターフェース
	BOOL SetStructPrecolor(int IN_Type, LPVOID IN_Struct, SXFPreDefColorC IN_Precolor)
	引数:	型				引数名			内容
			int				IN_Type			テーブル型
			LPVOID			IN_Struct		構造体
			SXFPreDefColorC IN_Precolor		既定義色クラス

	復帰値	正常時：TRUE
			異常時：FALSE

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.14			佐々木(FQS)			なし。

**/
BOOL SXFTableMapManagerC::SetStructPrecolor(int IN_Type, LPVOID IN_Struct, SXFPreDefColorC IN_Precolor)
{
	m_PreColourMapping = new SXFPreColourMappingC();
	if (m_PreColourMapping->MappingStruct(IN_Precolor)){
		return TRUE;
	}
	else 
		return FALSE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableMapManagerC.cpp								作成日：2001.06.14

	１．機能概要
	レイヤフィーチャの構造体の生成(WRITE)

	２．インターフェース
	BOOL SXFTableMapManagerC::SetStructLayer(SXFLayerC *IN_Layer)
	引数:	型				引数名			内容
			SXFLayerC*		IN_Layer		レイヤクラス

	復帰値	正常時：TRUE
			異常時：FALSE

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.14			佐々木(FQS)			なし。

**/
BOOL SXFTableMapManagerC::SetStructLayer(SXFLayerC *IN_Layer){

	if (IN_Layer->m_SheetID < 0)
		return FALSE;
	if (IN_Layer->m_Element.GetSize() > 0){
		m_LayerMapping = new SXFLayerMappingC();
		if (m_LayerMapping->MappingStruct(IN_Layer)){
			return TRUE;
		}
		else
			return FALSE;
	}
	else
		FALSE;
	return FALSE;
}


/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableMapManagerC.cpp								作成日：2001.06.14

	１．機能概要
	InvisibilityインスタンスのMapping

	２．インターフェース
	BOOL MappingInvisibility(CUIntArray* IN_InvisibilityTable)
	引数:	型				引数名					内容
			CUIntArray*		IN_InvisibilityTable	InvisiblityインスタンスがもつインスタンスIDの配列

	復帰値	正常時：TRUE
			異常時：FALSE

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.14			佐々木(FQS)			なし。

**/
BOOL SXFTableMapManagerC::MappingInvisibility(CUIntArray* IN_InvisibilityTable)
{
	m_InvisibilityMapping = new SXFInvisibilityMappingC();
	if (m_InvisibilityMapping->MappingStruct(IN_InvisibilityTable)){
		m_InvisibilityMapping->WriteAP202(m_File);
		return TRUE;
	}
	else
		return FALSE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableMapManagerC.cpp								作成日：2001.06.14

	１．機能概要
	構造体の生成(READ)

	２．インターフェース
	void SetFeatureData(int IN_Type, LPVOID IN_Class)
	引数:	型				引数名		内容
			int				IN_Type		定義テーブル型
			LPVOID			IN_Class	構造体

	復帰値	正常時：TRUE
			異常時：FALSE

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.14			佐々木(FQS)			なし。

**/
void SXFTableMapManagerC::SetFeatureData(int IN_Type, LPVOID IN_Class)
{
	m_TableFeature = new SXFTableFeatureC();
	m_TableFeature->SetStructData(IN_Type,IN_Class);
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableMapManagerC.cpp								作成日：2001.06.14

	１．機能概要
	構造体の取得(READ)

	２．インターフェース
	LPVOID GetStructData()
	引数:	型				引数名		内容
			なし

	復帰値	構造体

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.14			佐々木(FQS)			なし。

**/
LPVOID SXFTableMapManagerC::GetStructData()
{
	int type;
	return m_TableFeature->GetStructData(type);

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableMapManagerC.cpp								作成日：2001.06.14

	１．機能概要
	IDの生成

	２．インターフェース
	void SetAP202ID(int IN_Type)

	引数:	型				引数名		内容
			int				IN_Type		定義テーブル型

	復帰値	正常時：TRUE
			異常時：FALSE

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.14			佐々木(FQS)			なし。

**/
BOOL SXFTableMapManagerC::SetAP202ID(int IN_InstanceID)
{
	/*マッピングを管理ｵﾌﾞｼﾞｪｸﾄ生成*/
	m_MapTable = new SXFMapTableC(m_InstanceIDManager,m_ComInfo,m_TableManager);
	/*ルートＩＤの設定*/
	m_MapTable->SetRootID(IN_InstanceID);

	return TRUE;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_ANGULARDIMC.cpp						作成日：2001.06.17

	１．機能概要
		構造体の取得

	２．インターフェイス
		LPVOID SXFTableMapManagerC::GetStruct(int& OUT_TableType)

	引数 ：	型					引数名			内容
			int			OUT_TableType		ﾃｰﾌﾞﾙ型

	復帰値：正常時：OUT_Struct

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2001.06.17	
**/
LPVOID SXFTableMapManagerC::GetStruct(int& OUT_TableType)
{
	int TableType = 0;
	LPVOID TableClass = NULL;
	LPVOID OUT_Struct = NULL;
	m_MapTable->SetFeatureParameter(TableType,TableClass);
	if (TableClass == NULL)
		return OUT_Struct;
	m_TableFeature = new SXFTableFeatureC();
	m_TableFeature->SetStructData(TableType,TableClass);
	OUT_Struct = m_TableFeature->GetStructData(OUT_TableType);

	return OUT_Struct;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableMapManagerC.cpp								作成日：2001.06.14

	１．機能概要
	コンストラクタ

	２．インターフェース
	SXFTableMapManagerC::SXFTableMapManagerC(
                     SXFTableManagerC* IN_TableManager,
                     SXFInstanceIDC* IN_InstanceIDManager)
	
	引数:	型				引数名				内容
         SXFTableManagerC	 IN_TableManager		定義ﾃｰﾌﾞﾙ管理ｵﾌﾞｼﾞｪｸﾄ
         SXFInstanceIDC		 IN_InstanceIDManager	ｲﾝｽﾀﾝｽID管理ｵﾌﾞｼﾞｪｸﾄ
	復帰値:
			なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.14			佐々木(FQS)			なし。

**/
SXFTableMapManagerC::SXFTableMapManagerC(
						SXFTableManagerC* IN_TableManager,
						SXFInstanceIDC* IN_InstanceIDManager)
{
	m_PreColourMapping = NULL;
	m_PreTypeMapping = NULL;
	m_UserColourMapping = NULL;
	m_UserTypeMapping = NULL;
	m_LayerMapping = NULL;
	m_LineWidthMapping = NULL;
	m_TextFontMapping = NULL;
	m_TableFeature = NULL;
	m_LayerFeature = NULL;
	m_File = NULL;

	m_InstanceIDManager = IN_InstanceIDManager;

	m_TableManager = IN_TableManager;

	m_InvisibilityMapping = NULL;

	m_MapTable = NULL;

	m_ComInfo = NULL;
	m_WriteFile = NULL;

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableMapManagerC.cpp								作成日：2001.06.14

	１．機能概要
	コンストラクタ

	２．インターフェース
	SXFTableMapManagerC::SXFTableMapManagerC(
                     SXFTableManagerC* IN_TableManager,
                     SXFInstanceIDC* IN_InstanceIDManager,
					 SXFComInfoC* IN_ComInfo)
	
	引数:	型				引数名				内容
         SXFTableManagerC	 IN_TableManager		定義ﾃｰﾌﾞﾙ管理ｵﾌﾞｼﾞｪｸﾄ
         SXFInstanceIDC		 IN_InstanceIDManager	ｲﾝｽﾀﾝｽID管理ｵﾌﾞｼﾞｪｸﾄ
　       SXFComInfoC		 IN_ComInfo				共通情報管理ｵﾌﾞｼﾞｪｸﾄ
  
	復帰値:
			なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.14			佐々木(FQS)			なし。

**/
SXFTableMapManagerC::SXFTableMapManagerC(
						SXFTableManagerC* IN_TableManager,
						SXFInstanceIDC* IN_InstanceIDManager,
						SXFComInfoC* IN_ComInfo)
{
	m_PreColourMapping = NULL;
	m_PreTypeMapping = NULL;
	m_UserColourMapping = NULL;
	m_UserTypeMapping = NULL;
	m_LayerMapping = NULL;
	m_LineWidthMapping = NULL;
	m_TextFontMapping = NULL;
	m_TableFeature = NULL;
	m_LayerFeature = NULL;
	m_File = NULL;
	m_InstanceIDManager = IN_InstanceIDManager;
	m_TableManager = IN_TableManager;
	m_InvisibilityMapping = NULL;
	m_MapTable = NULL;
	m_ComInfo = IN_ComInfo;
	m_WriteFile = NULL;
}
