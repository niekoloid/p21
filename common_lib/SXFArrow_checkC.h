/**
	All Rights Reserved,(c)JACIC 2001
	SXFArrow_checkC.h						作成日：2000.03.30

	１．クラス概要
	矢印のルールチェックを行うクラス

	２．履歴
		履歴番号	日付		担当者		概要
		作成		2000.03.30	諌山(FQS)	なし。
**/

#ifndef _SXFARROW_CHECK_CLASS_
#define _SXFARROW_CHECK_CLASS_

#include <afx.h>
#include "SXFComFunctionC.h"
#include "SXFCheckInfoC.h"

class SXFArrow_checkC:public SXFComFunctionC,virtual public SXFCheckInfoC
{
public :
//------------------------------------------------
//	コンストラクタ
//------------------------------------------------
	SXFArrow_checkC() ;
//------------------------------------------------
//	デストラクタ
//------------------------------------------------
	~SXFArrow_checkC() ;
//------------------------------------------------
//	ルールチェック
//------------------------------------------------
	int arr_check(int IN_arr_code1,int IN_arr_code2,double IN_arr_r) ;

} ;
#endif