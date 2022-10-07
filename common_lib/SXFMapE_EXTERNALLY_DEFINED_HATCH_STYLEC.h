/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_EXTERNALLY_DEFINED_HATCH_STYLEC.h						作成日：2000.04.17

	１．クラス概要
		EXTERNALLY_DEFINED_HATCH_STYLEを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#ifndef _SXFMapE_EXTERNALLY_DEFINED_HATCH_STYLEC_CLASS_
#define _SXFMapE_EXTERNALLY_DEFINED_HATCH_STYLEC_CLASS_

#include "SXFMapE_EXTERNAL_SOURCEC.h"

class SXFMapE_EXTERNALLY_DEFINED_HATCH_STYLEC:public SXFMapEntityBaseC{
public :
	SXFMapE_EXTERNALLY_DEFINED_HATCH_STYLEC( );
	SXFMapE_EXTERNALLY_DEFINED_HATCH_STYLEC(
		SXFInstanceIDC* IN_InstanceIDManeger);

	~SXFMapE_EXTERNALLY_DEFINED_HATCH_STYLEC( );

	int	SetParameter( );

public:
/*
//#1203 = EXTERNALLY_DEFINED_HATCH_STYLE(IDENTIFIER('circle'), #1202, 'externally_defined_hatch_style1');
  ENTITY externally_defined_item;
	  item_id : source_item;
	  source  : external_source;
  END_ENTITY; -- externally_defined_item
  TYPE source_item = SELECT
	(identifier);
  END_TYPE; -- source_item
  ENTITY externally_defined_hatch_style
	SUBTYPE OF (externally_defined_item, geometric_representation_item);
  END_ENTITY; -- externally_defined_hatch_style
*/

	CString m_Name;

	int m_Source_Inst;
	SXFMapE_EXTERNAL_SOURCEC* m_Source_p;

};
#endif
