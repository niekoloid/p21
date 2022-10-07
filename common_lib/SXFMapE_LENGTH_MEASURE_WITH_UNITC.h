/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_LENGTH_MEASURE_WITH_UNITC.h						作成日：2000.04.17

	１．クラス概要
		LENGTH_MEASURE_WITH_UNITを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

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
