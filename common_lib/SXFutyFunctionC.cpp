/**
	All Rights Reserved,(c) JACIC 2001
	SXFutyFunctionC.cpp								作成日：2001.06.13

	１．クラス概要
		共通関数クラス

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.13			佐々木(FQS)			なし。

**/
#include "stdafx.h"
#include <math.h>
#include "SXFutyFunctionC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFutyFunctionC.cpp								作成日：2001.06.13

	１．機能概要
		コンストラクタ

	２．インターフェース
		void	SXFutyFunctionC::SXFutyFunctionC()
		
	引数	：	型		引数名				内容
		なし

  　３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.13			佐々木(FQS)			なし。

**/
SXFutyFunctionC::SXFutyFunctionC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFutyFunctionC.cpp								作成日：2001.06.13

	１．機能概要
		デストラクタ

	２．インターフェース
		void	SXFutyFunctionC::~SXFutyFunctionC()
		
	引数	：	型		引数名				内容
		なし

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.13			佐々木(FQS)			なし。

**/
SXFutyFunctionC::~SXFutyFunctionC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFutyFunctionC.cpp								作成日：2001.06.13

	１．機能概要
		角度を求める

	２．インターフェース
		void	SXFutyFunctionC::make_angle(double start_x, double start_y, double end_x, double end_y, double *angle)
		
	引数	：	型		引数名				内容
	double start_x			 始点Ｘ座標 
	double start_y			 始点Ｙ座標 
	double end_x			 終点Ｘ座標 
	double end_y			 終点Ｙ座標 
	double angle			 角度

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.13			佐々木(FQS)			なし。

**/
void SXFutyFunctionC::make_angle(double start_x, double start_y, double end_x, double end_y, double *angle)
{
	double LA;
	double Ax,Ay;

	//寸法線原点と矢印配置座標との長さ
	LA = fabs(sqrt(pow(end_x - start_x, 2)+pow(end_y - start_y, 2)));
	//ベクトル
	Ax = (end_x - start_x) / LA;
	Ay = (end_y - start_y) / LA;

	//	角度を求める
	if (Ay >= 0){
		//第１象限
			*angle = atan2(Ay,Ax);
		//第２象限
	}
	else if (Ay < 0){
		*angle = 2 * acos(-1.) + atan2(Ay,Ax);
		//第4象限
		//第3象限
	}
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFutyFunctionC.cpp								作成日：2001.06.13

	１．機能概要
		ベクトルから角度を求める

	２．インターフェース
		void	SXFutyFunctionC::calc_angle(double y, double x)
		
	引数	：	型		引数名				内容
			double		 y		ベクトルX成分
			double		 x		ベクトルY成分

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.13			佐々木(FQS)			なし。

**/
double SXFutyFunctionC::calc_angle(double y, double x)
{
	double ret;

	ret = (atan2(y,x))*180.0/ acos(-1.);
	if (ret < 0)
		ret = 360.0 + ret;

	return ret;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFutyFunctionC.cpp								作成日：2001.06.13

	１．機能概要
		角度の正規化

	２．インターフェース
		void	SXFutyFunctionC::angle_over()
		
	引数	：	型		引数名				内容


	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.06.13			佐々木(FQS)			なし。

**/
double SXFutyFunctionC::angle_over(double IN_angle)
{
	double ret_angle;
	if (IN_angle >=360.){
		ret_angle = IN_angle - ((int)(IN_angle/360))*360;
	}
	else if (IN_angle < 0.0){
		ret_angle = IN_angle - ((int)(IN_angle/360-1))*360;
	}
	else 
		ret_angle = IN_angle ;
	return ret_angle;

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFutyFunctionC.cpp								作成日：2001.2.23

	１．機能概要
		角度を有効桁15桁の文字列に変換

	２．インターフェース
		CString	SXFutyFunctionC::out_ctl(double IN_angle)
		
	引数	：	型		引数名		内容
				double	IN_angle	角度

	復帰値：
				CString		out		有効桁15桁の文字列

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.2.23			佐々木(FQS)			なし。
	更新			2002.03.06			K.Naono				バグ修正

    ４．補足説明
			double の型数値を文字列に変換します。

			char *_ecvt( double value, int count, int *dec, int *sign )

				戻り値

					_ecvt は数値文字列へのポインタを返します。

				引数

					value   変換する数値

					count   格納する桁数

					dec		格納された小数点位置

					sign   変換された数値の符号

			例：
				value	count	dec		sign
				1.0		15		1		100000000000000
				0.1		15		0		100000000000000
				0.01	15		-1		100000000000000

**/
CString SXFutyFunctionC::out_ctl(double IN_angle)
{
	// 小数点の位置
	int		decimal;
	// 正の値か負の値か？
	int		sign;
	// 文字
//	char	*buffer;
	// サイズ
	int		precision = 15;

//	ADD(S)	障害修正	K.Naono	02.03.06
	if( IN_angle <= 1.0e-014 ) {
		IN_angle += 5.0e-015 ;
	}
//	ADD(E)	障害修正	K.Naono	02.03.06

//	MOD(S)	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
//	buffer = _ecvt(	IN_angle, 
//					precision,
//					&decimal,
//					&sign );
	char buffer[_CVTBUFSIZE] = "";
	_ecvt_s(	buffer,
				_countof(buffer),
				IN_angle, 
				precision,
				&decimal,
				&sign );
//	MOD(E)	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27

	//小数点の位置が0または負の場合はbufferの前に0.00･･が必要
	/* 例えば0.0001のときdecimal=-3*/
	/* 0.0のときdeciaml=0 */
	CString tmp_out,out ;
	if (decimal <= 0){
		CString tmp_str("0.00000000000000");
		tmp_out = CString(buffer);
		out = tmp_str.Left(abs(decimal)+2) + tmp_out.Left(precision - (abs(decimal)+1));
	}
	//小数点を入れる
	else{
		out = CString(buffer);
		out.Insert(decimal,'.');
	}

	//符号をつける
	if (sign)
		out = "-" + out;

	return out;
}
