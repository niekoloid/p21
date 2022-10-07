//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFTableFeatureC.h					  作成日：2000.04.10
//
//	１．クラス概要
//		定義テーブルフィーチャデータを保持する
//
//	２．履歴
//		履歴番号	日付け		   担当者	 概要
//		作成		2000.04.10	   周
//
//------------------------------------------------------------
#ifndef _SXFTABLEFEATUREC_H_
#define _SXFTABLEFEATUREC_H_

class SXFInstanceIDC;
class SXFLayerC;

class SXFTableFeatureC	
{
public:
	BOOL SetLayerFeature(SXFLayerC* IN_Layer);
	SXFTableFeatureC();
	SXFTableFeatureC(SXFInstanceIDC* IN_InstanceIDManager);
	virtual ~SXFTableFeatureC();

	// when read feature comment:  class->struct
	BOOL SetStructData(int IN_Type, LPVOID IN_Class);

	// when want to write feature commentor or
	// after read AP202 instance && (mapping AP202->Struct):
	// struct->feature comment
	BOOL SetFeatureData(int IN_Type,LPVOID IN_Struct);
	

	INSTANCEDATA* GetFeatureData( );
	LPVOID GetStructData(int& OUT_Type);

private:
	INSTANCEDATA m_FeatureData;

	int    m_Type;
	LPVOID m_StructData;
	SXFInstanceIDC* m_InstanceIDManager;

};

#endif
