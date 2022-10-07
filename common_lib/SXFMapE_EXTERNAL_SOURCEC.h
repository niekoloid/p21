/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_EXTERNAL_SOURCEC.h						作成日：2000.04.17

	１．クラス概要
		EXTERNAL_SOURCEを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#ifndef _SXFMapE_EXTERNAL_SOURCEC_CLASS_
#define _SXFMapE_EXTERNAL_SOURCEC_CLASS_

class SXFMapE_EXTERNAL_SOURCEC:public SXFMapEntityBaseC{
public :
	SXFMapE_EXTERNAL_SOURCEC( );
	SXFMapE_EXTERNAL_SOURCEC(
		SXFInstanceIDC* IN_InstanceIDManeger);

	~SXFMapE_EXTERNAL_SOURCEC( );

	int	SetParameter( );

public:

	CString m_Name;
};
#endif
