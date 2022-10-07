/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableMapManagerC.h								作成日：2000.4.14

	１．クラス概要
	定義テーブルフィーチャオブジェクトとMappingオブジェクトを管理するクラス

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.14			宮園(FQS)			なし。

**/

#if !defined(AFX_SXFTABLEMAPMANAGERC_H__16B30B22_0BAC_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFTABLEMAPMANAGERC_H__16B30B22_0BAC_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFDataStructC.h"
#include "SXFStruct.h"

class SXFPreColourMappingC;
class SXFPreTypeMappingC;
class SXFUserColourMappingC;
class SXFUserTypeMappingC;
class SXFLayerMappingC;
class SXFLineWidthMappingC;
class SXFTextFontMappingC;
class SXFTableFeatureC;
class SXFPart21FileC;
class SXFPreDefColorC;
class SXFLayerC;
class SXFInvisibilityMappingC;
class SXFComInfoC;
class SXFPart21FileWriteC;
class SXFInstanceIDC;
class SXFTableManagerC;
class SXFMapTableC;

class SXFTableMapManagerC  
{
public:
	LPVOID GetStructData();
	void SetFeatureData(int IN_Type,LPVOID IN_Class);
	BOOL MappingInvisibility(CUIntArray* IN_InvisibilityTable);
	BOOL SetStructLayer(SXFLayerC* IN_Layer);
	BOOL SetStructPrecolor(int IN_Type,LPVOID IN_Struct,SXFPreDefColorC IN_Precolor);
	BOOL WriteInstance(int IN_Type);
	int GetInstanceID(int IN_table_type);
	BOOL SetStructData(int IN_type,LPVOID IN_Struct);

	BOOL SetAP202ID(int IN_InstanceID);
	LPVOID GetStruct(int& OUT_TableType);

	SXFTableMapManagerC();
	SXFTableMapManagerC(SXFPart21FileC* IN_File,SXFComInfoC* IN_ComInfo,SXFPart21FileWriteC* IN_WriteFile,SXFInstanceIDC* m_InstanceIDManager);
	SXFTableMapManagerC(SXFPart21FileC* IN_File);

	SXFTableMapManagerC(SXFTableManagerC* IN_TableManager,
						SXFInstanceIDC* IN_InstanceIDManager);
	SXFTableMapManagerC(
					 SXFTableManagerC* IN_TableManager,
					 SXFInstanceIDC* IN_InstanceIDManager,
					 SXFComInfoC* IN_ComInfo);

	virtual ~SXFTableMapManagerC();

public:

	SXFTableManagerC* m_TableManager;
	SXFMapTableC* m_MapTable;

private:
	///////////////////////////////////
	//定義テーブルフィーチャオブジェクト
	///////////////////////////////////
	SXFTableFeatureC* m_LayerFeature;
	///////////////////////////////////
	//インスタンスIDオブジェクト
	///////////////////////////////////
	SXFInstanceIDC* m_InstanceIDManager;
	///////////////////////////////////
	//出力ファイルオブジェクト
	///////////////////////////////////
	SXFPart21FileWriteC* m_WriteFile;
	///////////////////////////////////
	//ファイルオブジェクト
	///////////////////////////////////
	SXFPart21FileC* m_File;
	///////////////////////////////////
	//文字フォントオブジェクト
	///////////////////////////////////
	SXFTextFontMappingC* m_TextFontMapping;
	///////////////////////////////////
	//線幅Mappingオブジェクト
	///////////////////////////////////
	SXFLineWidthMappingC* m_LineWidthMapping;
	///////////////////////////////////
	//ユーザ定義線種Mappingオブジェクト
	///////////////////////////////////
	SXFUserTypeMappingC* m_UserTypeMapping;
	///////////////////////////////////
	//ユーザ定義色Mappingオブジェクト
	///////////////////////////////////
	SXFUserColourMappingC* m_UserColourMapping;
	///////////////////////////////////
	//レイヤMappingオブジェクト
	///////////////////////////////////
	SXFLayerMappingC* m_LayerMapping;
	///////////////////////////////////
	//既定義色Mappingオブジェクト
	///////////////////////////////////
	SXFPreColourMappingC* m_PreColourMapping;
	///////////////////////////////////
	//既定義線種Mappingオブジェクト
	///////////////////////////////////
	SXFPreTypeMappingC* m_PreTypeMapping;
	///////////////////////////////////
	//定義テーブルフィーチャオブジェクト
	///////////////////////////////////
	SXFTableFeatureC* m_TableFeature;
	///////////////////////////////////
	//InvisibilityMappingオブジェクト
	///////////////////////////////////
	SXFInvisibilityMappingC* m_InvisibilityMapping;
	///////////////////////////////////
	//共通情報管理オブジェクト
	///////////////////////////////////
	SXFComInfoC* m_ComInfo;

};

#endif // !defined(AFX_SXFTABLEMAPMANAGERC_H__16B30B22_0BAC_11D4_A76E_00000EB03267__INCLUDED_)
