/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_EXTERNALLY_DEFINED_HATCHC.h						�쐬���F2000.04.17

	�P�D�N���X�T�v
		EXTERNALLY_DEFINED_HATCH���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

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
