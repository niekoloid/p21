/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_EXTERNAL_DEFINED_TEXT_FONTC.h						作成日：2000.04.17

	１．クラス概要
		EXTERNAL_DEFINED_TEXT_FONTを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#ifndef _SXFMapE_EXTERNAL_DEFINED_TEXT_FONTC_CLASS_
#define _SXFMapE_EXTERNAL_DEFINED_TEXT_FONTC_CLASS_

#include "SXFMapE_EXTERNAL_SOURCEC.h"

class SXFMapE_EXTERNAL_DEFINED_TEXT_FONTC:public SXFMapEntityBaseC{
public :
	SXFMapE_EXTERNAL_DEFINED_TEXT_FONTC( );
	SXFMapE_EXTERNAL_DEFINED_TEXT_FONTC(
		SXFInstanceIDC* IN_InstanceIDManeger);

	~SXFMapE_EXTERNAL_DEFINED_TEXT_FONTC( );

	int	SetParameter( );

public:

	CString m_Name;

	int m_Source_Inst;
	SXFMapE_EXTERNAL_SOURCEC* m_Source_p;

};
#endif
