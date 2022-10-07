/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapF_CURVEDIMC.cpp						作成日：2007.01.29

	１．クラス概要
		CURVEDIMを管理する

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2007.01.29	

**/
#include "stdafx.h"
#include <math.h>
#include "SXFStruct.h"
#include "SXFMapFeatureBaseC.h"
#include "SXFMapF_CurveStyleBaseC.h"
#include "SXFutyFunctionC.h"
#include "SXFMapF_CURVEDIMC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_CURVEDIMC.cpp						作成日：2007.01.29

	１．機能概要
		デフォルトコンストラクタ

	２．インターフェイス
		void	SXFMapF_CURVEDIMC::SXFMapF_CURVEDIMC()

	引数  ：	型			引数名				内容
			なし
	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2007.01.29	
**/
SXFMapF_CURVEDIMC::SXFMapF_CURVEDIMC()
{
	m_sun_x = 0.0;
	m_sun_y = 0.0;
	m_sun_radius = 0.0;
	m_sun_angle0 = 0.0;
	m_sun_angle1 = 0.0;
//
	m_flg2 =0;
	m_ho1_x0 = 0.0;
	m_ho1_y0 = 0.0;
	m_ho1_x1 = 0.0;
	m_ho1_y1 = 0.0;
	m_ho1_x2 = 0.0;
	m_ho1_y2 = 0.0;
//
	m_flg3  = 0;
	m_ho2_x0 = 0.0;
	m_ho2_y0 = 0.0;
	m_ho2_x1 = 0.0;
	m_ho2_y1 = 0.0;
	m_ho2_x2 = 0.0;
	m_ho2_y2 = 0.0;
//
	m_arr1_code1 = 0;
	m_arr1_code2  = 0;
	m_arr1_x = 0.0;
	m_arr1_y = 0.0;
	m_arr1_r = 0.0;
//
	m_arr2_code1 = 0;
	m_arr2_code2 = 0;
	m_arr2_x  = 0.0;
	m_arr2_y = 0.0;
	m_arr2_r = 0.0;
//
	m_flg4  = 0;
	m_font = 0;
	//CString m_str;
	m_text_x = 0.0;
	m_text_y = 0.0;
	m_height = 0.0;
	m_width = 0.0;
	m_spc = 0.0;
	m_angle = 0.0;
	m_slant = 0.0;
	m_b_pnt = 0;
	m_direct = 0;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_CURVEDIMC.cpp						作成日：2007.01.29

	１．機能概要
		(デストラクタ)

	２．インターフェイス
		void	SXFMapF_CURVEDIMC::~SXFMapF_CURVEDIMC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2007.01.29	
**/
SXFMapF_CURVEDIMC::~SXFMapF_CURVEDIMC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_CURVEDIMC.cpp						作成日：2007.01.29

	１．機能概要
		構造体Dataの取得

	２．インターフェイス
		void	SXFMapF_CURVEDIMC::GetStructData()

	引数 ：	型					引数名			内容
			CURVEDim_Struct* 	INOUT_Struct    構造体

	復帰値：正常時：TRUE

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2007.01.29	
**/
BOOL SXFMapF_CURVEDIMC::GetStructData( CurveDim_Struct* INOUT_Struct )
{

	INOUT_Struct->layer       = m_layer ;			//レイヤコード
	INOUT_Struct->color       = m_color ;			//色コード
	INOUT_Struct->type        = m_type ;			//線種コード
	INOUT_Struct->line_width  = m_line_width ;		//線幅コード

	INOUT_Struct->sun_x        = m_sun_x;
	INOUT_Struct->sun_y        = m_sun_y;
	INOUT_Struct->sun_radius   = m_sun_radius;
	INOUT_Struct->sun_angle0   = m_sun_angle0;
	INOUT_Struct->sun_angle1   = m_sun_angle1;

	INOUT_Struct->flg2         = m_flg2;
	INOUT_Struct->ho1_x0       = m_ho1_x0;
	INOUT_Struct->ho1_y0       = m_ho1_y0;
	INOUT_Struct->ho1_x1       = m_ho1_x1;
	INOUT_Struct->ho1_y1       = m_ho1_y1;
	INOUT_Struct->ho1_x2       = m_ho1_x2;
	INOUT_Struct->ho1_y2       = m_ho1_y2;

	INOUT_Struct->flg3         = m_flg3;
	INOUT_Struct->ho2_x0       = m_ho2_x0;
	INOUT_Struct->ho2_y0       = m_ho2_y0;
	INOUT_Struct->ho2_x1       = m_ho2_x1;
	INOUT_Struct->ho2_y1       = m_ho2_y1;
	INOUT_Struct->ho2_x2       = m_ho2_x2;
	INOUT_Struct->ho2_y2       = m_ho2_y2;

	INOUT_Struct->arr1_code1   = m_arr1_code1;
	INOUT_Struct->arr1_code2   = m_arr1_code2;
	INOUT_Struct->arr1_x       = m_arr1_x;
	INOUT_Struct->arr1_y       = m_arr1_y;
	INOUT_Struct->arr1_r       = m_arr1_r;

	INOUT_Struct->arr2_code1   = m_arr2_code1;
	INOUT_Struct->arr2_code2   = m_arr2_code2;
	INOUT_Struct->arr2_x	   = m_arr2_x;
	INOUT_Struct->arr2_y	   = m_arr2_y;
	INOUT_Struct->arr2_r	   = m_arr2_r;

	INOUT_Struct->flg4         = m_flg4;
	INOUT_Struct->font         = m_font;

//	MOD(S)	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
	//strcpy(INOUT_Struct->str, m_str);

	// 文字要素と同じく257バイト以上の文字列は256に切り詰める
	size_t ilen = strlen(m_str);
	if (ilen <= 256) {
		strcpy_s( INOUT_Struct->str,_countof(INOUT_Struct->str), m_str );
	}
	else {
		/* メッセージを出力 */
		// ここも m_RootID = 0,m_TypeName == "" だけど文字要素と同じ処理にしておく
		SXFErrorMsgC::RecordError(SXFNAMELENGTH,m_TypeName,	2, m_RootID, m_TypeName);
		/* 先頭から256バイト切り取る */
		strcpy_s( INOUT_Struct->str,_countof(INOUT_Struct->str), m_str.Left(256) );
	}
//	MOD(E)	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27

	INOUT_Struct->text_x       = m_text_x;
	INOUT_Struct->text_y       = m_text_y;
	INOUT_Struct->height       = m_height;
	INOUT_Struct->width        = m_width;
	INOUT_Struct->spc          = m_spc;
	INOUT_Struct->angle        = m_angle;
	INOUT_Struct->slant        = m_slant;
	INOUT_Struct->b_pnt        = m_b_pnt;
	INOUT_Struct->direct       = m_direct;

	return TRUE;
}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_CURVEDIMC.cpp						作成日：2007.01.29

	１．機能概要
		向きフラグを設定する

	２．インターフェイス
		void	SXFMapF_CURVEDIMC::SetArrFlag()

	引数 ：	型			引数名				内容
			int 		IN_term1		矢印１の有り無しフラグ
			int 		IN_term2		矢印２の有り無しフラグ
			double 		IN_sun_x		寸法線の原点（円弧中心X)
			double 		IN_sun_y		寸法線の原点（円弧中心Y）
			double 		IN_arr1_x		矢印１配置点X
			double 		IN_arr1_y		矢印１配置点Y
			double 		IN_arr2_x		矢印２配置点X
			double 		IN_arr2_y		矢印２配置点Y				
			double 		IN_tmvec_x1		矢印１のベクトルX
			double 		IN_tmvec_y1		矢印１のベクトルY
			double 		IN_tmvec_x2		矢印２のベクトルX
			double 		IN_tmvec_y2		矢印２のベクトルY	

	復帰値：正常時：TRUE

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2007.01.29	
**/
BOOL SXFMapF_CURVEDIMC::SetArrFlag(  
				int IN_term1,	//矢印１の有り無しフラグ
				int IN_term2,	//矢印２の有り無しフラグ
				double IN_sun_x,	//寸法線の原点（円弧中心X)
				double IN_sun_y,	//寸法線の原点（円弧中心Y）
				double IN_arr1_x,	//矢印１配置点X
				double IN_arr1_y,	//矢印１配置点Y
				double IN_arr2_x,	//矢印２配置点X
				double IN_arr2_y,	//矢印２配置点Y				
				double IN_tmvec_x1,	//矢印１のベクトルX
				double IN_tmvec_y1,	//矢印１のベクトルY
				double IN_tmvec_x2,	//矢印２のベクトルX
				double IN_tmvec_y2	//矢印２のベクトルY	
				)

{
	double eps;
	eps = 0.0001;
	m_arr1_code2 = 0;
	m_arr2_code2 = 0;
	
	////矢印１、２の方向ベクトルを計算
	double vector1_x,vector1_y,vector2_x,vector2_y;
	//矢印１，２と寸法線原点との距離
	double L1,L2;

	double angle1_in,angle1_out,angle2_in,angle2_out,tm1_angle,tm2_angle;
	//矢印がふたつの場合。
	if ((IN_term1 != 0)&&(IN_term2 != 0)){

		//矢印１，２と寸法線原点との距離
		L1 = fabs(sqrt(pow(IN_arr1_x - IN_sun_x, 2)+pow(IN_arr1_y - IN_sun_y, 2)));
		L2 = fabs(sqrt(pow(IN_arr2_x - IN_sun_x, 2)+pow(IN_arr2_y - IN_sun_y, 2)));
		//寸法線原点と矢印１配置位置のベクトル
		vector1_x = (IN_arr1_x - IN_sun_x) / L1;
		vector1_y = (IN_arr1_y - IN_sun_y) / L1;
		//寸法線原点と矢印２配置位置のベクトル
		vector2_x = (IN_arr2_x - IN_sun_x) / L2;
		vector2_y = (IN_arr2_y - IN_sun_y) / L2;

		//寸法線原点と矢印１配置位置のベクトルのなす角
		angle1_in = SXFutyFunctionC::calc_angle(vector1_x,-vector1_y);
		angle1_out = SXFutyFunctionC::calc_angle(-vector1_x,vector1_y);
		//寸法線原点と矢印２配置位置のベクトルのなす角
		angle2_out = SXFutyFunctionC::calc_angle(vector2_x,-vector2_y);
		angle2_in = SXFutyFunctionC::calc_angle(-vector2_x,vector2_y);
		//矢印１ベクトルのなす角
		tm1_angle = SXFutyFunctionC::calc_angle(IN_tmvec_y1,IN_tmvec_x1);
		//矢印２ベクトルのなす角
		tm2_angle = SXFutyFunctionC::calc_angle(IN_tmvec_y2,IN_tmvec_x2);

		//矢印１の内外コードが２(内向き)の場合(-90)
		if (fabs(tm1_angle - angle1_in) < eps)
			m_arr1_code2 = 2;
		//矢印１の内外コードが１(外向き）の場合(+90)
		else if (fabs(tm1_angle - angle1_out) < eps)
			m_arr1_code2 = 1;
		//矢印２の内外コードが２（内向き）の場合(90)
		if (fabs(tm2_angle - angle2_in) < eps)
			m_arr2_code2 = 2;
		//矢印２の内外コードが１（外向き）の場合(-90)
		else if (fabs(tm2_angle - angle2_out) < eps)
			m_arr2_code2 = 1;
	}
	//矢印が一つの場合
	////
	else if ((IN_term1 != 0)&&(IN_term2 == 0)){
		//矢印１と寸法線原点との距離
		L1 = fabs(sqrt(pow(IN_arr1_x - IN_sun_x, 2)+pow(IN_arr1_x - IN_sun_y, 2)));
		//寸法線原点と矢印１配置位置のベクトル
		vector1_x = (IN_arr1_x - IN_sun_x) / L1;
		vector1_y = (IN_arr1_y - IN_sun_y) / L1;
		//寸法線原点と矢印１配置位置のベクトルのなす角
		angle1_in = SXFutyFunctionC::calc_angle(vector1_x,-vector1_y);
		angle1_out = SXFutyFunctionC::calc_angle(-vector1_x,vector1_y);
		//矢印１ベクトルのなす角
		tm1_angle = SXFutyFunctionC::calc_angle(IN_tmvec_y1,IN_tmvec_x1);
		//矢印１の内外コードが２(内向き)の場合(-90)
		if (fabs(tm1_angle - angle1_in) < eps)
			m_arr1_code2 = 2;
		//矢印１の内外コードが１(外向き）の場合(+90)
		else if (fabs(tm1_angle - angle1_out) < eps)
			m_arr1_code2 = 1;
	}

	////矢印がひとつの場合
	else if ((IN_term1 == 0)&&(IN_term2 != 0)){
		//矢印２と寸法線原点との距離
		L2 = fabs(sqrt(pow(IN_arr2_x - IN_sun_x, 2)+pow(IN_arr2_x - IN_sun_y, 2)));
		//寸法線原点と矢印２配置位置のベクトル
		vector2_x = (IN_arr2_x - IN_sun_x) / L2;
		vector2_y = (IN_arr2_y - IN_sun_y) / L2;
		//寸法線原点と矢印２配置位置のベクトルのなす角
		angle2_out = SXFutyFunctionC::calc_angle(vector2_x,-vector2_y);
		angle2_in = SXFutyFunctionC::calc_angle(-vector2_x,vector2_y);
		//矢印２ベクトルのなす角
		tm2_angle = SXFutyFunctionC::calc_angle(IN_tmvec_y2,IN_tmvec_x2);
		//矢印２の内外コードが２（内向き）の場合(90)
		if (fabs(tm2_angle - angle2_in) < eps)
			m_arr2_code2 = 2;
		//矢印２の内外コードが１（外向き）の場合(-90)
		else if (fabs(tm2_angle - angle2_out) < eps)
			m_arr2_code2 = 1;
	}
	return TRUE;
}
