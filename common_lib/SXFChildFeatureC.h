// SXFChildFeatureC.h: SXFChildFeatureC クラスのインターフェイス
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SXFCHILDFEATUREC_H__790053E1_2A42_11D4_A3A9_009027565E9B__INCLUDED_)
#define AFX_SXFCHILDFEATUREC_H__790053E1_2A42_11D4_A3A9_009027565E9B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include <afxtempl.h>
//#include "SXFDNFeatureChildC.h"

/*typedef struct SfigLocateInfo{
	double m_Locate_x;
	double m_Locate_y;
	double m_Angle;
	double m_Ratio_x;
	double m_Ratio_y;
}SXFSFIGLOCATEINFO;

typedef CArray<SXFSFIGLOCATEINFO,SXFSFIGLOCATEINFO&> SXFSFIGLOCATETABLE;*/
typedef struct SfigLocateInfo{
	double m_Locate_x;
	double m_Locate_y;
	double m_Angle;
	double m_Ratio_x;
	double m_Ratio_y;
}SXFSFIGLOCATEINFO;

typedef CArray<SXFSFIGLOCATEINFO,const SXFSFIGLOCATEINFO&> SXFSFIGLOCATETABLE;

class SXFChildFeatureC  
{
public:
	SXFChildFeatureC& operator=(const SXFChildFeatureC& IN_ChildFeature);
	SXFChildFeatureC(const SXFChildFeatureC& IN_ChildFeature);

	SXFChildFeatureC();
	virtual ~SXFChildFeatureC();

	//フィーチャ構造体
	LPVOID ChildStruct;
	//フィーチャ名
	char FeatureType[64];
	//フィーチャのレベル
	int Level;
	//配置情報
	SXFSFIGLOCATETABLE SfigLocateTable;
	//インスタンスID
	int InstanceID;

	//複合曲線の非表示フラグ
	//要素がハッチングのときのみ使用
	int CurveFlag;
	//複合曲線の色、線種、線幅
	//要素がハッチングの外形、中抜きのときのみ使用
	int CurveColor;
	int CurveType;
	int CurveWidth;
	//ハッチの要素(ハッチ、外形、中抜き)であることのフラグ
	int HatchElemFlg;

	int HatchLayer;

	//外形、中抜きのID
	int HatchID;//ID_222_000725_ins
};

#endif // !defined(AFX_SXFCHILDFEATUREC_H__790053E1_2A42_11D4_A3A9_009027565E9B__INCLUDED_)
