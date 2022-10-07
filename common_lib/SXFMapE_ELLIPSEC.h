/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_ELLIPSEC.h						作成日：2000.04.17

	１．クラス概要
		ELLIPSEを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#ifndef _SXFMapE_ELLIPSEC_CLASS_
#define _SXFMapE_ELLIPSEC_CLASS_

#include "SXFMapEntityBaseC.h"

class SXFInstanceIDC;
class SXFMapE_AXIS2_PLACEMENT_2DC;

class SXFMapE_ELLIPSEC:public SXFMapEntityBaseC{
public :
	SXFMapE_ELLIPSEC( );
	SXFMapE_ELLIPSEC(
		SXFInstanceIDC* IN_InstanceIDManeger);

	~SXFMapE_ELLIPSEC( );

	int	SetParameter( );

public:

	CString m_EllipseName;

	int		m_axis2_Inst;
	SXFMapE_AXIS2_PLACEMENT_2DC* m_axis2_P;

	double	m_semi_axis_1;
	double	m_semi_axis_2;
};
#endif
