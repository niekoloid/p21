/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_EXSYMBOLC.h						作成日：2000.04.17

	１．クラス概要
		既定義シンボルフィーチャを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/

#ifndef _SXFMapF_EXSYMBOLC_CLASS_
#define _SXFMapF_EXSYMBOLC_CLASS_

class SXFMapF_EXSYMBOLC : 
	public SXFMapFeatureBaseC,
	public SXFMapF_ColorBaseC {
public :
	SXFMapF_EXSYMBOLC( );
	~SXFMapF_EXSYMBOLC( );

	BOOL GetStructData( Externally_Defined_Symbol_Struct* INOUT_Struct );

public:
/*
typedef struct Externally_Defined_Symbol_StructDF{
	int layer;						//レイヤコード
	int color_flag;					//色コードフラグ
	int color;						//色コード
	char name[MAXSYMBOLNAME];		//シンボル名
	double start_x;					//配置位置X座標
	double start_y;					//配置位置Y座標
	double rotate_angle;			//回転角
	double scale;					//倍率
} Externally_Defined_Symbol_Struct;
*/
//	外部定義シンボル固有
	int m_color_flag;					//色コードフラグ
	CString m_name;				  	//シンボル名
	
//	マーカシンボル、外部定義シンボル共通
	double m_rotate_angle;			//回転角

//	マーカシンボル、外部定義シンボル、寸法端点シンボル共通
	double m_start_x;				//配置位置X座標
	double m_start_y;				//配置位置Y座標
	double m_scale;					//倍率（スケールX)
	double m_scale_y;				//スケールY

};
#endif
