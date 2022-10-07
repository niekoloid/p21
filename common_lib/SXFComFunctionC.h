/**
	All Rights Reserved,(c) JACIC 2001
	SXFComFunctionC.h								作成日：2000.3.27

	１．クラス概要
	ルールチェック共通関数クラス

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.3.27			宮園(FQS)			なし。

**/

#if !defined(AFX_OMFUNCTION_H__A630F625_FC31_11D3_A76E_00000EB03267__INCLUDED_)
#define AFX_OMFUNCTION_H__A630F625_FC31_11D3_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class SXFComFunctionC 
{
public:
	int slant_check(double IN_slant);
	int max_double_check(double IN_double);
	double calc_length(double IN_x1,double IN_y1,double IN_x2,double IN_y2);
	int angle_check(double &IN_angle);
	int double_check(double IN_double);
	SXFComFunctionC();
	virtual ~SXFComFunctionC();

};

#endif // !defined(AFX_OMFUNCTION_H__A630F625_FC31_11D3_A76E_00000EB03267__INCLUDED_)
