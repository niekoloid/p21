/**
	All Rights Reserved,(c) JACIC 2001
	SXFutyFunctionC.cpp								�쐬���F2000.4.13

	�P�D�N���X�T�v
		���ʊ֐��N���X

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.13			�{��(FQS)			�Ȃ��B

**/
#if !defined(AFX_SXFutyFunctionC_H__9B34E032_CF91_11D3_A393_009027565E9B__INCLUDED_)
#define AFX_SXFutyFunctionC_H__9B34E032_CF91_11D3_A393_009027565E9B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


//#include "picMFC.h"
#include <afx.h>

class SXFutyFunctionC  
{
public:
	static double angle_over(double IN_angle);
	SXFutyFunctionC();
	virtual ~SXFutyFunctionC();
	static double calc_angle(double y, double x);
	static void make_angle(double start_x,double start_y,double end_x,double end_y,double* angle);
	static CString out_ctl(double IN_angle);
};

#endif // !defined(AFX_SXFutyFunctionC_H__9B34E032_CF91_11D3_A393_009027565E9B__INCLUDED_)
