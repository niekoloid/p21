/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_EXTERNALLY_DEFINED_SYMBOLC.h						ì¬úF2000.04.17

	PDNXTv
		EXTERNALLY_DEFINED_SYMBOLðÇ·éNX

	QDð
		ðÔ	út¯		SÒ		Tv
		ì¬		2000.04.17	

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
