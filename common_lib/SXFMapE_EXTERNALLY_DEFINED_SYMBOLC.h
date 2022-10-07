/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_EXTERNALLY_DEFINED_SYMBOLC.h						作成日：2000.04.17

	１．クラス概要
		EXTERNALLY_DEFINED_SYMBOLを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#ifndef _SXFMapE_EXTERNALLY_DEFINED_SYMBOLC_CLASS_
#define _SXFMapE_EXTERNALLY_DEFINED_SYMBOLC_CLASS_

#include "SXFMapE_EXTERNAL_SOURCEC.h"

class SXFMapE_EXTERNALLY_DEFINED_SYMBOLC:public SXFMapEntityBaseC{
public :
	SXFMapE_EXTERNALLY_DEFINED_SYMBOLC( );
	SXFMapE_EXTERNALLY_DEFINED_SYMBOLC(
		SXFInstanceIDC* IN_InstanceIDManeger);

	~SXFMapE_EXTERNALLY_DEFINED_SYMBOLC( );

	int	SetParameter( );

public:
/*
//#1346 = EXTERNALLY_DEFINED_SYMBOL(IDENTIFIER('asterisk'), #1345);
  ENTITY externally_defined_symbol
	SUBTYPE OF (externally_defined_item);
  END_ENTITY; -- externally_defined_symbol
*/

	CString m_Name;

	int m_Source_Inst;
	SXFMapE_EXTERNAL_SOURCEC* m_Source_p;

};
#endif
