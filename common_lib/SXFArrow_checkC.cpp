/**
	All Rights Reserved,(c)JACIC 2001
	SXFArrow_checkC.cpp						作成日：2000.4.3

	１．クラス概要
	矢印のルールチェックを行うクラス

	２．履歴
		履歴番号	日付		担当者		概要
		作成		2000.4.3	諌山(FQS)	なし。
**/

#include "stdafx.h"
#include "SXFArrow_checkC.h"
#include "SXFErrorMsgC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFArrow_checkC.cpp					 	作成日：2000.03.30

	１．機能概要 
		コンストラクタ
		
	２．インターフェイス
		void	SXFArrow_checkC::SXFArrow_checkC()		
		
	引数	：	型		引数名				内容
		なし

	復帰値	：	なし

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2000.03.30	諌山(FQS)	なし。
**/
SXFArrow_checkC::SXFArrow_checkC() 	
{
}
/**
	All Rights Reserved,(c)JACIC 2001
	SXFArrow_checkC.cpp					 	作成日：2000.03.30

	１．機能概要 
		デストラクタ
		
	２．インターフェイス
		void	SXFArrow_checkC::~SXFArrow_checkC()		
		
	引数	：	型		引数名				内容
		なし

	復帰値	：	なし

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2000.03.30	諌山(FQS)	なし。
**/
SXFArrow_checkC::~SXFArrow_checkC()
{
}
/**
	All Rights Reserved,(c)JACIC 2001
	SXFArrow_checkC.cpp					 	作成日：2000.03.30

	１．機能概要 
		矢印のルールチェック
		
	２．インターフェイス
		int		 SXFArrow_checkC::arr_check(int IN_arr_code1,
											int IN_arr_code2,
											double IN_arr_r)
		
	引数	：	型		引数名				内容
				int		IN_arr_code1		矢印コード
				int		IN_arr_code2		矢印内外コード
				double	IN_arr_r			矢印倍率

	復帰値	正常時：０
			異常時：エラー番号

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2000.03.30	諌山(FQS)	なし。
**/
int SXFArrow_checkC::arr_check(int IN_arr_code1,int IN_arr_code2,double IN_arr_r)
{

	//矢印内外コードが0から2以外のとき
	if ((IN_arr_code2 < 0) || (IN_arr_code2 > 2)){
		SXFErrorMsgC::RecordError(SXFARRINOUTCODE,
									m_feature_name,
									3,
									m_InstanceID,
									IN_arr_code2,
									m_feature_name);
		return SXFARRINOUTCODE;
	}
	if (IN_arr_code2 != 0){
		//矢印コードが1から11以外のとき
		if ((IN_arr_code1 < 1) || (IN_arr_code1 >11)){
			SXFErrorMsgC::RecordError(SXFARRCODE,
										m_feature_name,
										3,
										m_InstanceID,
										IN_arr_code1,
										m_feature_name);
			return SXFARRCODE;
		}
		//矢印配置倍率が規定範囲外のとき
		if (double_check(IN_arr_r) < 0){
			SXFErrorMsgC::RecordError(SXFERRORSCALE,
										m_feature_name,
										3,
										m_InstanceID,
										IN_arr_r,
										m_feature_name);
			return SXFERRORSCALE;
		}
	}
	return 0 ;
}
