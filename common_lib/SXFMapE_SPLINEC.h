/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_SPLINEC.h						作成日：2000.04.17

	１．クラス概要
		SPLINEを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#ifndef _SXFMapE_SPLINEC_CLASS_
#define _SXFMapE_SPLINEC_CLASS_

#include "SXFMapEntityBaseC.h"
#include "SXFMapT_trimming_preferenceE.h"

class SXFInstanceIDC;
class SXFMapE_CARTESIAN_POINTC;


class SXFMapE_SPLINEC:public SXFMapEntityBaseC{
public :
	SXFMapE_SPLINEC( );
	SXFMapE_SPLINEC(
		SXFInstanceIDC* IN_InstanceIDManeger);

	~SXFMapE_SPLINEC( );

	int	SetParameter( );

public:


	CString m_SplineName;

	int m_Degree;
	int m_PointCount;
	CArray<int,int>	m_PointArray_Inst;
	CArray<SXFMapE_CARTESIAN_POINTC* ,SXFMapE_CARTESIAN_POINTC*>
		m_PointArray_P;
	CString m_CurveForm;
	CString m_ClosedCurve;
	BOOL	m_ClosedCurveFlg;
	CString m_SelfIntersect;

};
#endif
