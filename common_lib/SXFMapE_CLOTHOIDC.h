/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_CLOTHOIDC.h						ì¬úF2000.04.17

	PDNXTv
		CLOTHOIDðÇ·éNX

	QDð
		ðÔ	út¯		SÒ		Tv
		ì¬		2000.04.17	

**/
#ifndef _SXFMapE_CLOTHOIDC_CLASS_
#define _SXFMapE_CLOTHOIDC_CLASS_

#include "SXFMapEntityBaseC.h"
#include "SXFMapT_trimming_preferenceE.h"

class SXFInstanceIDC;
class SXFMapE_AXIS2_PLACEMENT_2DC;


class SXFMapE_CLOTHOIDC:public SXFMapEntityBaseC{
public :
	SXFMapE_CLOTHOIDC( );
	SXFMapE_CLOTHOIDC(
		SXFInstanceIDC* IN_InstanceIDManeger);

	~SXFMapE_CLOTHOIDC( );

	int	SetParameter( );

public:


	CString m_direction;

	int		m_axis2_Inst;
	SXFMapE_AXIS2_PLACEMENT_2DC* m_axis2_P;

	double m_parameter;
};
#endif
