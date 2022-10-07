/**
	All Rights Reserved,(c)JACIC 2001
	SXFProj_checkC.cpp						作成日：2000.03.30

	１．クラス概要
	補助線のルールチェックを行うクラス

	２．履歴
		履歴番号	日付		担当者		概要
		作成		2000.03.30	諌山(FQS)	なし。
**/
#include "stdafx.h"
#include <math.h>
#include "SXFProj_checkC.h"
#include "SXFErrorMsgC.h"
#include "SXF_EXT.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFProj_checkC.cpp					 	作成日：2000.03.30

	１．機能概要 
		コンストラクタ
		
	２．インターフェイス
		void	SXFProj_checkC::SXFProj_checkC()		
		
	引数	：	型		引数名				内容
		なし

	復帰値	：	なし

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2000.03.30	諌山(FQS)	なし。
**/
SXFProj_checkC::SXFProj_checkC()
{
}
/**
	All Rights Reserved,(c)JACIC 2001
	SXFProj_checkC.cpp					 	作成日：2000.03.30

	１．機能概要 
		デストラクタ
		
	２．インターフェイス
		void	SXFProj_checkC::~SXFProj_checkC()		
		
	引数	：	型		引数名				内容
		なし

	復帰値	：	なし

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2000.03.30	諌山(FQS)	なし。
**/
SXFProj_checkC::~SXFProj_checkC()
{
}
/**
	All Rights Reserved,(c)JACIC 2001
	SXFProj_checkC.cpp					 	作成日：2000.03.30

	１．機能概要 
		補助線のルールチェック
		
	２．インターフェイス
		int proj_check(int IN_flg,
						double	IN_ho_x0,
						double	IN_ho_y0,
						double	IN_ho_x1,
						double	IN_ho_y1,
						double	IN_ho_x2,
						double	IN_ho_y2) ;

		
	引数	：	型			引数名		内容
				int			IN_flg		補助線の有無フラグ(０：無、１：有)
				double		IN_ho_x0	補助線基点Ｘ座標
				double		IN_ho_y0	補助線基点Ｙ座標
				double		IN_ho_x1	補助線始点Ｘ座標
				double		IN_ho_y1	補助線始点Ｙ座標
				double		IN_ho_x2	補助線終点Ｘ座標
				double		IN_ho_y2	補助線終点Ｙ座標


	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2000.03.30	諌山(FQS)	なし。
**/
int SXFProj_checkC::proj_check(int IN_flg,
								double	IN_ho_x0,
								double	IN_ho_y0,
								double	IN_ho_x1,
								double	IN_ho_y1,
								double	IN_ho_x2,
								double	IN_ho_y2)
{
	double L1,L2;
	double xv1,yv1,xv2,yv2;
	double eps,eps2;
	m_ComInfo->Get_Tolerance(eps,eps2);

	//補助線の有無フラグが0または1以外のとき
	if ((IN_flg < 0) || (IN_flg > 1)){
		SXFErrorMsgC::RecordError(SXFPRJFLAG,
									m_feature_name,
									3,
									m_InstanceID,
									IN_flg,
									m_feature_name);
		return SXFPRJFLAG;
	}
	if (IN_flg != 0){
		//補助線の始点から終点までの長さが0のとき（許容誤差epsより小さいとき）
		L1= calc_length(IN_ho_x1,IN_ho_y1,IN_ho_x2,IN_ho_y2);
		if (L1 < eps){
			SXFErrorMsgC::RecordError(SXFLENGTHZERO,
										m_feature_name,
										3,
										m_InstanceID,
										L1,
										m_feature_name);
			return SXFLENGTHZERO;
		}
		//補助線の基点から終点までの長さ
		L2= calc_length(IN_ho_x0,IN_ho_y0,IN_ho_x2,IN_ho_y2);
		//補助線の始点と終点のベクトル
		xv1 = (IN_ho_x2 - IN_ho_x1) / L1;
		yv1 = (IN_ho_y2 - IN_ho_y1) / L1;
		//補助線の基点と終点のベクトル
		xv2 = (IN_ho_x2 - IN_ho_x0) / L2;
		yv2 = (IN_ho_y2 - IN_ho_y0) / L2;
		//補助線の基点、始点、終点の座標が一直線上にないとき
		if (((fabs(xv2 - xv1)) >= eps) && ((fabs(yv2 - yv1)) >= eps)){
			SXFErrorMsgC::RecordError(SXFERRORCOORDINATE,
										m_feature_name,
										4,
										m_InstanceID,
										IN_ho_x1,
										IN_ho_y1,
										m_feature_name);
			return SXFERRORCOORDINATE;
		}
	}
	return 0;
}
