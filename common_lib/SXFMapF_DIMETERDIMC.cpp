/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_DIMETERDIMC.h						作成日：2000.04.17

	１．クラス概要
		直径寸法フィーチャを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#include "stdafx.h"
#include <math.h>
#include "SXFStruct.h"
#include "SXFMapFeatureBaseC.h"
#include "SXFMapF_CurveStyleBaseC.h"
#include "SXFMapF_DIMETERDIMC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_DIMETERDIMC.cpp						作成日：2000.04.17

	１．機能概要
		デフォルトコンストラクタ

	２．インターフェイス
		void	SXFMapF_DIMETERDIMC::SXFMapF_DIMETERDIMC()

	引数  ：	型			引数名				内容
			なし
	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapF_DIMETERDIMC::SXFMapF_DIMETERDIMC()
{
	m_sun_x1 = 0.0;
	m_sun_y1 = 0.0;
	m_sun_x2 = 0.0;
	m_sun_y2 = 0.0;
//
	m_arr1_code1 = 0;
	m_arr1_code2 = 0;
	m_arr1_x = 0.0;
	m_arr1_y = 0.0;
	m_arr1_r = 0.0;
//
	m_arr2_code1 = 0;
	m_arr2_code2 = 0;
	m_arr2_x = 0.0;
	m_arr2_y = 0.0;
	m_arr2_r = 0.0;

	m_flg = 0;
	m_font = 0;
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
	SXFMapF_DIMETERDIMC.cpp						作成日：2000.04.17

	１．機能概要
		(デストラクタ)

	２．インターフェイス
		void	SXFMapF_DIMETERDIMC::~SXFMapF_DIMETERDIMC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapF_DIMETERDIMC::~SXFMapF_DIMETERDIMC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_DIMETERDIMC.cpp						作成日：2000.04.17

	１．機能概要
		フィーチャ構造体の取得

	２．インターフェイス
		void	SXFMapF_DIMETERDIMC::GetStructData()

	引数 ：	型					引数名			内容
			DiameterDim_Struct	INOUT_Struct    構造体

	復帰値：正常時：TRUE

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
BOOL SXFMapF_DIMETERDIMC::GetStructData( DiameterDim_Struct* INOUT_Struct )
{

	INOUT_Struct->layer       = m_layer ;			//レイヤコード
	INOUT_Struct->color       = m_color ;			//色コード
	INOUT_Struct->type        = m_type ;			//線種コード
	INOUT_Struct->line_width  = m_line_width ;		//線幅コード

	INOUT_Struct->sun_x1 = m_sun_x1;
	INOUT_Struct->sun_y1 = m_sun_y1;
	INOUT_Struct->sun_x2 = m_sun_x2;
	INOUT_Struct->sun_y2 = m_sun_y2;
////
	INOUT_Struct->arr1_code1	= m_arr1_code1;
	INOUT_Struct->arr1_code2	= m_arr1_code2;
	INOUT_Struct->arr1_x 	    = m_arr1_x;
	INOUT_Struct->arr1_y	    = m_arr1_y;
	INOUT_Struct->arr1_r 	    = m_arr1_r;
////
	INOUT_Struct->arr2_code1	= m_arr2_code1;
	INOUT_Struct->arr2_code2	= m_arr2_code2;
	INOUT_Struct->arr2_x 	    = m_arr2_x;
	INOUT_Struct->arr2_y        = m_arr2_y;
	INOUT_Struct->arr2_r	    = m_arr2_r;

	INOUT_Struct->flg    = m_flg;
	INOUT_Struct->font   = m_font;

//	MOD(S)	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
	//strcpy(INOUT_Struct->str,  m_str);

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

	INOUT_Struct->text_x   = m_text_x;
	INOUT_Struct->text_y   = m_text_y;
	INOUT_Struct->height   = m_height;
	INOUT_Struct->width    = m_width;
	INOUT_Struct->spc      = m_spc;
	INOUT_Struct->angle    = m_angle;
	INOUT_Struct->slant    = m_slant;
	INOUT_Struct->b_pnt	   = m_b_pnt;
	INOUT_Struct->direct   = m_direct;

	return TRUE;
}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_DIMETERDIMC.cpp						作成日：2000.04.17

	１．機能概要
		向きフラグの設定

	２．インターフェイス
		void	SXFMapF_DIMETERDIMC::SetArrFlag()

	引数 ：	型		引数名				内容
			int		IN_term1	矢印１の有り無しフラグ
			int		IN_term2	矢印２の有り無しフラグ
			double	IN_sun_x1	寸法線の始点
			double	IN_sun_y1	寸法線の始点
			double	IN_sun_x2	寸法線の終点
			double	IN_sun_y2	寸法線の終点
			double	IN_tmvec_x1	矢印１のベクトルX
			double	IN_tmvec_y1	矢印１のベクトルY
			double	IN_tmvec_x2	矢印２のベクトルX
			double	IN_tmvec_y2	矢印２のベクトルY
	
	  復帰値：正常時：TRUE

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
BOOL SXFMapF_DIMETERDIMC::SetArrFlag(  
				int IN_term1,	//矢印１の有り無しフラグ
				int IN_term2,	//矢印２の有り無しフラグ
				double IN_sun_x1,	//寸法線の始点
				double IN_sun_y1,	//寸法線の始点
				double IN_sun_x2,	//寸法線の終点
				double IN_sun_y2,	//寸法線の終点
				double IN_tmvec_x1,	//矢印１のベクトルX
				double IN_tmvec_y1,	//矢印１のベクトルY
				double IN_tmvec_x2,	//矢印２のベクトルX
				double IN_tmvec_y2	//矢印２のベクトルY				
			)

{

	double eps;
	double L1;
	double Dim_x,Dim_y;
	double tmvec_x1,tmvec_y1,tmvec_x2,tmvec_y2;
	double tm1_L,tm2_L;

	eps = 0.000001;
	m_arr1_code2 = 0;
	m_arr2_code2 = 0;

	//矢印が２つの場合
	if ((IN_term1 != 0)&&(IN_term2 != 0)){
		//矢印１、２の方向ベクトルから内外コードを計算する
		//寸法線の方向ベクトルを計算する
		//寸法線の始点から終点までの長さ
		L1 = fabs(sqrt(pow(IN_sun_x2 - IN_sun_x1, 2)+pow(IN_sun_y2 - IN_sun_y1, 2)));
		Dim_x = (IN_sun_x2 - IN_sun_x1) / L1;
		Dim_y = (IN_sun_y2 - IN_sun_y1) / L1;
		//矢印ベクトルの単位ベクトルを求める。
		tm1_L = fabs(sqrt(pow(IN_tmvec_x1, 2)+pow(IN_tmvec_y1, 2)));
		tmvec_x1 = IN_tmvec_x1 / tm1_L;
		tmvec_y1 = IN_tmvec_y1 / tm1_L;
		tm2_L = fabs(sqrt(pow(IN_tmvec_x2, 2)+pow(IN_tmvec_y2, 2)));
		tmvec_x2 = IN_tmvec_x2 / tm2_L;
		tmvec_y2 = IN_tmvec_y2 / tm2_L;
		//矢印１の内外コードを設定する
		//矢印１の方向ベクトルが寸法線の方向ベクトルと同方向のとき、２（内向き）に設定する
		if((fabs(tmvec_x1 - Dim_x) < eps )&&( fabs(tmvec_y1 - Dim_y) < eps)){
			m_arr1_code2 = 2;
		}
		//矢印１の方向ベクトルが寸法線の方向ベクトルと反対方向のとき、１（外向き）に設定する
		else if((fabs(tmvec_x1 + Dim_x) < eps) && (fabs(tmvec_y1 + Dim_y) < eps)){
			m_arr1_code2 = 1;
		}

		//矢印２の内外コードを設定する
		//矢印２の方向ベクトルが寸法線の方向ベクトルと反対方向のとき、２（内向き）に設定する
		if((fabs(tmvec_x2 + Dim_x) < eps) && (fabs(tmvec_y2 + Dim_y) < eps)){
			m_arr2_code2 = 2;
		}
		//矢印２の方向ベクトルが寸法線の方向ベクトルと同方向のとき、１（外向き）に設定する
		else if((fabs(tmvec_x2 - Dim_x) < eps) && (fabs(tmvec_y2 - Dim_y) < eps)){
			m_arr2_code2 = 1;
		}
	}
	//矢印がひとつの場合
	else if ((IN_term1 != 0)&&(IN_term2 == 0)){
		//矢印１の方向ベクトルから内外コードを計算する
		//寸法線の方向ベクトルを計算する
		//寸法線の始点から終点までの長さ
		L1 = fabs(sqrt(pow(IN_sun_x2 - IN_sun_x1, 2)+pow(IN_sun_y2 - IN_sun_y1, 2)));
		Dim_x = (IN_sun_x2 - IN_sun_x1) / L1;
		Dim_y = (IN_sun_y2 - IN_sun_y1) / L1;
		//矢印ベクトルの単位ベクトルを求める。
		tm1_L = fabs(sqrt(pow(IN_tmvec_x1, 2)+pow(IN_tmvec_y1, 2)));
		tmvec_x1 = IN_tmvec_x1 / tm1_L;
		tmvec_y1 = IN_tmvec_y1 / tm1_L;
		//矢印１の内外コードを設定する
		//矢印１の方向ベクトルが寸法線の方向ベクトルと同方向のとき、２（内向き）に設定する
		if((fabs(tmvec_x1 - Dim_x) < eps) && (fabs(tmvec_y1 - Dim_y) < eps)){
			m_arr1_code2 = 2;
		}
		//矢印１の方向ベクトルが寸法線の方向ベクトルと反対方向のとき、１（外向き）に設定する
		else if((fabs(tmvec_x1 + Dim_x) < eps) && (fabs(tmvec_y1 + Dim_y) < eps)){
			m_arr1_code2 = 1;
		}
	}
	else if ((IN_term1 == 0)&&(IN_term2 != 0)){
		//矢印１、２の方向ベクトルから内外コードを計算する
		//寸法線の方向ベクトルを計算する
		//寸法線の始点から終点までの長さ
		L1 = fabs(sqrt(pow(IN_sun_x2 - IN_sun_x1, 2)+pow(IN_sun_y2 - IN_sun_y1, 2)));
		Dim_x = (IN_sun_x2 - IN_sun_x1) / L1;
		Dim_y = (IN_sun_y2 - IN_sun_y1) / L1;
		//矢印ベクトルの単位ベクトルを求める。
		tm2_L = fabs(sqrt(pow(IN_tmvec_x2, 2)+pow(IN_tmvec_y2, 2)));
		tmvec_x2 = IN_tmvec_x2 / tm2_L;
		tmvec_y2 = IN_tmvec_y2 / tm2_L;
		//矢印２の内外コードを設定する
		//矢印２の方向ベクトルが寸法線の方向ベクトルと反対方向のとき、２（内向き）に設定する
		if((fabs(tmvec_x2 + Dim_x) < eps) && (fabs(tmvec_y2 + Dim_y) < eps)){
			m_arr2_code2 = 2;
		}
		//矢印２の方向ベクトルが寸法線の方向ベクトルと同方向のとき、１（外向き）に設定する
		else if((fabs(tmvec_x2 - Dim_x) < eps) && (fabs(tmvec_y2 - Dim_y) < eps)){
			m_arr2_code2 = 1;
		}
	}

	return TRUE;
}
