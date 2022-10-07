/**
	All Rights Reserved,(c)JACIC 2001
	SXFProj_checkC.h						作成日：2000.03.30

	１．クラス概要
	補助線のルールチェックを行うクラス

	２．履歴
		履歴番号	日付		担当者		概要
		作成		2000.03.30	諌山(FQS)	なし。
**/

#ifndef _SXFPROJ_CHECK_CLASS_
#define _SXFPROJ_CHECK_CLASS_

#include <afx.h>
#include "SXFCheckInfoC.h"
#include "SXFComFunctionC.h"

class SXFComInfoC;

class SXFProj_checkC:virtual public SXFCheckInfoC, public SXFComFunctionC
{
public :
//------------------------------------------------
//	コンストラクタ
//------------------------------------------------
	SXFProj_checkC() ;
//------------------------------------------------
//	デストラクタ
//------------------------------------------------
	~SXFProj_checkC() ;
//------------------------------------------------
//	ルールチェック
//------------------------------------------------
	int proj_check(int IN_flg,			//補助線の有無フラグ(０：無、１：有)
					double	IN_ho_x0,	//補助線基点Ｘ座標
					double	IN_ho_y0,	//補助線基点Ｙ座標
					double	IN_ho_x1,	//補助線始点Ｘ座標
					double	IN_ho_y1,	//補助線始点Ｙ座標
					double	IN_ho_x2,	//補助線終点Ｘ座標
					double	IN_ho_y2) ;	//補助線終点Ｙ座標

} ;
#endif