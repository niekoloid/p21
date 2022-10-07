/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_LINEC.h						作成日：2000.04.17

	１．クラス概要
		線分フィーチャを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#ifndef _SXFMapF_LINEC_CLASS_
#define _SXFMapF_LINEC_CLASS_


//class SXFInstanceIDC;
//class SXFMapE_CARTESIAN_POINTC;
//class SXFMapE_VECTORC;

//#include "SXFMapFeatureBaseC.h"

class SXFMapF_LINEC : 
	public SXFMapFeatureBaseC,
	public SXFMapF_CurveStyleBaseC  {
public :
//
//	<デフォルトコンストラクタ>
	SXFMapF_LINEC( ) ;

//	<コンストラクタ>
//	<インスタンスＩＤへのポインタを登録し生成する>
//	SXFMapF_LINEC(SXFInstanceIDC* IN_InstanceIDManeger) ;

//	<デストラクタ>
	virtual	~SXFMapF_LINEC() ;

//	<フィーチャ構造体の取得>
    BOOL GetStructData( Line_Struct* INOUT_Struct );

//	<補助線の端点１，２どちらか？を表わすフラグ設定>
	BOOL Set12flg(CString& IN_name);

//	<メンバ変数>	//////////////////////////////////////

//<フィーチャデータ>
/*
//------------------------------------------------
//	線分
//------------------------------------------------
typedef struct Line_StructDF{
	int layer;				//レイヤコード
	int color;				//色コード
	int type;				//線種コード
	int line_width;			//線幅コード
	
	double start_x;			//始点Ｘ座標
	double start_y;			//始点Ｙ座標
	double end_x;			//終点Ｘ座標
	double end_y;			//終点Ｙ座標
} Line_Struct;
*/

	double m_start_x;			//始点Ｘ座標
	double m_start_y;			//始点Ｙ座標
	double m_end_x;			//終点Ｘ座標
	double m_end_y;			//終点Ｙ座標


//------------------------------------------------
//	PROJECTION LINE 固有
//------------------------------------------------

	int    m_flag;			//端点１２フラグ（0:初期値,1:端点１側, 2:端点２側)
	double m_org_x;			//基点Ｘ座標
	double m_org_y;			//基点Ｙ座標

private :

protected :

} ;
#endif
