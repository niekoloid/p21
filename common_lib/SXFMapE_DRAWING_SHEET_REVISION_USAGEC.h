/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_DRAWING_SHEET_REVISION_USAGEC.h						�쐬���F2000.04.17

	�P�D�N���X�T�v
		DRAWING_SHEET_REVISION_USAGE���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#ifndef _SXFMapE_DRAWING_SHEET_REVISION_USAGEC_CLASS_
#define _SXFMapE_DRAWING_SHEET_REVISION_USAGEC_CLASS_

#include "SXFMapE_DRAWING_SHEET_REVISIONC.h"
#include "SXFMapE_DRAUGHTING_DRAWING_REVISIONC.h"

class SXFMapE_DRAWING_SHEET_REVISION_USAGEC:public SXFMapEntityBaseC{
public :
	SXFMapE_DRAWING_SHEET_REVISION_USAGEC( );
	SXFMapE_DRAWING_SHEET_REVISION_USAGEC(
		SXFInstanceIDC* IN_InstanceIDManeger);

	~SXFMapE_DRAWING_SHEET_REVISION_USAGEC( );

	int	SetParameter( );

public:

/*
  ENTITY drawing_sheet_revision_usage
	SUBTYPE OF (area_in_set);
	  sheet_number : identifier;
  END_ENTITY; -- drawing_sheet_revision_usage
*/
/*	
  ENTITY area_in_set;
	  area	 : presentation_area;
	  in_set : presentation_set;
  END_ENTITY; -- area_in_set
*/

	int m_Area_Inst;
	SXFMapE_DRAWING_SHEET_REVISIONC* m_Area_p;

	int m_InSet_Inst;
	SXFMapE_DRAUGHTING_DRAWING_REVISIONC* m_InSet_p;

	CString m_SheetNumber;
};
#endif
////////////////////////////
