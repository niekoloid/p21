/**
	All Rights Reserved,(c) JACIC 2001
	SXFComFunctionC.cpp								作成日：2000.3.27

	１．クラス概要
	ルールチェック共通関数クラス

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.3.27			宮園(FQS)			なし。

**/

#include "stdafx.h"
#include <math.h>
#include "SXFComFunctionC.h"
#include "max.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFComFunctionC.cpp								作成日：2000.3.27

	１．機能概要
		コンストラクタ

	２．インターフェース
		void	 SXFComFunctionC::SXFComFunctionC()
		
	引数	：	型		引数名				内容
		なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.3.27			宮園(FQS)			なし。

**/
SXFComFunctionC::SXFComFunctionC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFComFunctionC.cpp								作成日：2000.3.27

	１．機能概要
		デストラクタ

	２．インターフェース
		void	 SXFComFunctionC::~SXFComFunctionC()
		
	引数	：	型		引数名				内容
		なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.3.27			宮園(FQS)			なし。

**/
SXFComFunctionC::~SXFComFunctionC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFComFunctionC.cpp								作成日：2000.3.27

	１．機能概要
		doubleの範囲チェック

	２．インターフェース
	int double_check(double IN_double);

	引数:	型			引数名		内容
			double		IN_double	チェック対象の数値

	復帰値	正常時：０
			異常時：－１

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.3.27			宮園(FQS)			なし。
	更新			2002.03.06			K.Naono				バグ修正
**/
int SXFComFunctionC::double_check(double IN_double)
{
//	MOD(S)	障害修正	K.Naono	02.03.06
//	if ((IN_double <= 0.0) || (IN_double >= MAXDOUBLE))
//		return -1;
//	else
//		return 0;

	// 0.000000000000004以下または、999999999999999.5以上
	if ((IN_double <= MIN_CHK_DOUBLE) || (IN_double >= MAX_CHK_DOUBLE)) {
		return -1 ;
	}

	// 0.000000000000004 < IN_double < 0.000000000000005
	if ((IN_double > MIN_CHK_DOUBLE) && (IN_double < LMT_CHK_DOUBLE)) {
		return -1 ;
	}

	return 0 ;
//	MOD(E)	障害修正	K.Naono	02.03.06
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFComFunctionC.cpp								作成日：2000.3.27

	１．機能概要
		角度の範囲チェック

	２．インターフェース
	int angle_check(double IN_angle);

	引数:	型			引数名		内容
			double		IN_angle	角度

	復帰値	正常時：０
			異常時：－１

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.3.27			宮園(FQS)			なし。

**/
int SXFComFunctionC::angle_check(double &IN_angle)
{
	if ((IN_angle < MINANGLE) || (IN_angle > MAXANGLE)) {				// 2010.08
		return -1;
	} else {
		if (359.999999999999999 < IN_angle && IN_angle <= MAXANGLE) {	// 2010.08
			IN_angle = 359.999999999999999;
		}
		return 0;
	}
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFComFunctionC.cpp								作成日：2000.3.27

	１．機能概要
		２点間の距離を求める

	２．インターフェース
	double calc_length(double IN_x1,double IN_y1,
						double IN_x2,double IN_y2);

	引数:	型			引数名		内容
			double		IN_x1		始点X座標
			double		IN_y1		始点Y座標
			double		IN_x1		終点X座標
			double		IN_y2		終点Y座標

	復帰値	正常時：二点間の距離

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.3.27			宮園(FQS)			なし。

**/
double SXFComFunctionC::calc_length(double IN_x1, 
									double IN_y1,
									double IN_x2, 
									double IN_y2)
{
	double ret = sqrt( (IN_x2 - IN_x1) * (IN_x2 - IN_x1) 
							+ (IN_y2 - IN_y1) * (IN_y2 - IN_y1) );
	return ret;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFComFunctionC.cpp								作成日：2000.3.27

	１．機能概要
		doubleの範囲チェック

	２．インターフェース
	int max_double_check(double IN_double);

	引数:	型			引数名		内容
			double		IN_double	チェック対象の数値

	復帰値	正常時：０
			異常時：－１

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.3.27			宮園(FQS)			なし。

**/
int SXFComFunctionC::max_double_check(double IN_double)
{
	if ((IN_double < 0.0) || (IN_double >= MAXDOUBLE))
		return -1;
	else
		return 0;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFComFunctionC.cpp								作成日：2000.3.27

	１．機能概要
		スラント角の範囲チェック

	２．インターフェース
	int slant_check(double IN_slant);

	引数:	型			引数名		内容
			double		IN_slant	スラント角度

	復帰値	正常時：０
			異常時：－１

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.3.27			宮園(FQS)			なし。

**/
int SXFComFunctionC::slant_check(double IN_slant)
{
	if ((IN_slant < MINSLANT) || (IN_slant > MAXSLANT))
		return -1;
	else
		return 0;
}
