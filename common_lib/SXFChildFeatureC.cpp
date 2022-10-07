// SXFChildFeatureC.cpp: SXFChildFeatureC クラスのインプリメンテーション
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SXFChildFeatureC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//////////////////////////////////////////////////////////////////////
// 構築/消滅
//////////////////////////////////////////////////////////////////////

SXFChildFeatureC::SXFChildFeatureC()
{
	//フィーチャ構造体
	ChildStruct = NULL;
	//フィーチャ名
//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
//	strcpy(FeatureType,"");
	strcpy_s(FeatureType,_countof(FeatureType),"");
	//フィーチャのレベル
	Level = -1;
	//インスタンスID
	InstanceID = -1;
	//複合曲線の非表示フラグ
	CurveFlag = -1;
	//複合曲線の色、線種、線幅
	CurveColor = 0;
	CurveType = 0;
	CurveWidth = 0;
	//ハッチの要素(ハッチ、外形、中抜き)であることのフラグ
	HatchElemFlg = -1; 
	HatchLayer = -1;
	HatchID = -1;//ID_222_000725_ins
}

SXFChildFeatureC::~SXFChildFeatureC()
{

}

SXFChildFeatureC& SXFChildFeatureC::operator=(const SXFChildFeatureC& IN_ChildFeature){
	//フィーチャ構造体
	ChildStruct = IN_ChildFeature.ChildStruct;
	//フィーチャ名
//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
//	strcpy(FeatureType,IN_ChildFeature.FeatureType);
	strcpy_s(FeatureType,_countof(FeatureType),IN_ChildFeature.FeatureType);
	//フィーチャのレベル
	Level = IN_ChildFeature.Level;
	//配置情報
	for (int i = 0; i < IN_ChildFeature.SfigLocateTable.GetSize(); i++)
		SfigLocateTable.Add(IN_ChildFeature.SfigLocateTable.GetAt(i));
	//インスタンスID
	InstanceID = IN_ChildFeature.InstanceID;
	//複合曲線の非表示フラグ
	CurveFlag = IN_ChildFeature.CurveFlag;
	//複合曲線の色、線種、線幅
	CurveColor = IN_ChildFeature.CurveColor;
	CurveType = IN_ChildFeature.CurveType;
	CurveWidth = IN_ChildFeature.CurveWidth;
	//ハッチの要素(ハッチ、外形、中抜き)であることのフラグ
	HatchElemFlg = IN_ChildFeature.HatchElemFlg; 
	HatchLayer = IN_ChildFeature.HatchLayer; 
	HatchID = IN_ChildFeature.HatchID;//ID_222_000725_ins

	return *this;
}

SXFChildFeatureC::SXFChildFeatureC(const SXFChildFeatureC& IN_ChildFeature){
	//フィーチャ構造体
	ChildStruct = IN_ChildFeature.ChildStruct;
	//フィーチャ名
//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
//	strcpy(FeatureType,IN_ChildFeature.FeatureType);
	strcpy_s(FeatureType,_countof(FeatureType),IN_ChildFeature.FeatureType);
	//フィーチャのレベル
	Level = IN_ChildFeature.Level;
	//配置情報
	for (int i = 0; i < IN_ChildFeature.SfigLocateTable.GetSize(); i++)
		SfigLocateTable.Add(IN_ChildFeature.SfigLocateTable.GetAt(i));
	//インスタンスID
	InstanceID = IN_ChildFeature.InstanceID;
	//複合曲線の非表示フラグ
	CurveFlag = IN_ChildFeature.CurveFlag;
	//複合曲線の色、線種、線幅
	CurveColor = IN_ChildFeature.CurveColor;
	CurveType = IN_ChildFeature.CurveType;
	CurveWidth = IN_ChildFeature.CurveWidth;
	//ハッチの要素(ハッチ、外形、中抜き)であることのフラグ
	HatchElemFlg = IN_ChildFeature.HatchElemFlg; 
	HatchLayer = IN_ChildFeature.HatchLayer; 
	HatchID = IN_ChildFeature.HatchID;//ID_222_000725_ins
}
