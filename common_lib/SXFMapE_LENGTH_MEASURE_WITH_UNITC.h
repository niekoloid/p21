/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_LENGTH_MEASURE_WITH_UNITC.h						ì¬úF2000.04.17

	PDNXTv
		LENGTH_MEASURE_WITH_UNITðÇ·éNX

	QDð
		ðÔ	út¯		SÒ		Tv
		ì¬		2000.04.17	

**/
#ifndef _SXFMapE_LENGTH_MEASURE_WITH_UNITC_CLASS_
#define _SXFMapE_LENGTH_MEASURE_WITH_UNITC_CLASS_

class SXFMapE_LENGTH_MEASURE_WITH_UNITC:public SXFMapEntityBaseC{
public :
	SXFMapE_LENGTH_MEASURE_WITH_UNITC( );
	SXFMapE_LENGTH_MEASURE_WITH_UNITC(
		SXFInstanceIDC* IN_InstanceIDManeger);

	~SXFMapE_LENGTH_MEASURE_WITH_UNITC( );

	int	SetParameter( );

public:

	double m_Width;

	int m_UnitComponent_Inst;

};
#endif
