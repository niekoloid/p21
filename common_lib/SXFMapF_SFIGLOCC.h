/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_SFIGLOCC.h						作成日：2000.04.17

	１．クラス概要
		複合図形配置フィーチャを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/

#ifndef _SXFMapF_SFIGLOCC_CLASS_
#define _SXFMapF_SFIGLOCC_CLASS_

class SXFMapF_SFIGLOCC : 
	public SXFMapFeatureBaseC,
	public SXFMapF_LayerBaseC {
public :
	SXFMapF_SFIGLOCC( );
	~SXFMapF_SFIGLOCC( );

	BOOL GetStructData( Sfigloc_StructDF* INOUT_Struct );


public:
/*
//------------------------------------------------
//	複合図形配置
//------------------------------------------------
typedef struct Sfigloc_StructDF{
	int layer;						//レイヤコード
	char name[MAXFIGURENAME];		//複合図形名
	double x;						//配置位置X座標
	double y;						//配置位置Y座標
	double angle;					//回転角
	double ratio_x;					//X方向尺度
	double ratio_y;					//Y方向尺度
} Sfigloc_Struct;
*/

	CString m_name;				  	//複合図形名
	double m_angle;					//回転角
	double m_ratio_x;				//X方向尺度
	double m_ratio_y;				//Y方向尺度
//	マーカシンボル、外部定義シンボル、寸法端点シンボル共通
	double m_start_x;				//配置位置X座標
	double m_start_y;				//配置位置Y座標

};
#endif
