/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_EXTERNALLY_DEFINED_HATCHC.h						作成日：2000.04.17

	１．クラス概要
		EXTERNALLY_DEFINED_HATCHを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#ifndef _SXFMapE_EXTERNALLY_DEFINED_HATCHC_CLASS_
#define _SXFMapE_EXTERNALLY_DEFINED_HATCHC_CLASS_

#include "SXFMapE_EXTERNAL_SOURCEC.h"

class SXFMapE_EXTERNALLY_DEFINED_HATCHC:public SXFMapEntityBaseC{
public :
	SXFMapE_EXTERNALLY_DEFINED_HATCHC( );
	SXFMapE_EXTERNALLY_DEFINED_HATCHC(
		SXFInstanceIDC* IN_InstanceIDManeger);

	~SXFMapE_EXTERNALLY_DEFINED_HATCHC( );

	int	SetParameter( );

public:
/*
//#1346 = EXTERNALLY_DEFINED_HATCH(IDENTIFIER('asterisk'), #1345);
  ENTITY externally_DEFINED_HATCH
	SUBTYPE OF (externally_defined_item);
  END_ENTITY; -- externally_DEFINED_HATCH
*/

	CString m_Name;

	int m_Source_Inst;
	SXFMapE_EXTERNAL_SOURCEC* m_Source_p;

};
#endif
