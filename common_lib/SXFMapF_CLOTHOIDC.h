/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_ARCC.h						作成日：2000.04.17

	１．クラス概要
		クロソイドフィーチャを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/

#ifndef _SXFMapF_CLOTHOIDC_CLASS_
#define _SXFMapF_CLOTHOIDC_CLASS_

class SXFMapF_CLOTHOIDC : 
	public SXFMapFeatureBaseC,
	public SXFMapF_CurveStyleBaseC {
public :
	SXFMapF_CLOTHOIDC( );
	~SXFMapF_CLOTHOIDC( );

	BOOL GetStructData( Clothoid_Struct* INOUT_Struct );

public:
	double	base_x ;			/* 配置基点Ｘ座標 */
	double	base_y ;			/* 配置基点Ｙ座標 */
	double	parameter ;			/* クロソイドパラメータ */
	int direction;				/* 向きフラグ */
	double angle;				/* 回転角 */
	double start_length;		/* 開始曲線長 */
	double end_length;			/* 終了曲線長 */
};
#endif
