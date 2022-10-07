/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_PRESENTATION_SIZEC.h						�쐬���F2000.04.17

	�P�D�N���X�T�v
		PRESENTATION_SIZE���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#ifndef _SXFMapE_PRESENTATION_SIZEC_CLASS_
#define _SXFMapE_PRESENTATION_SIZEC_CLASS_

#include "SXFMapE_DRAWING_SHEET_REVISIONC.h"
#include "SXFMapE_PLANAR_BOXC.h"

class SXFMapE_PRESENTATION_SIZEC:public SXFMapEntityBaseC{
public :
	SXFMapE_PRESENTATION_SIZEC( );
	SXFMapE_PRESENTATION_SIZEC(
		SXFInstanceIDC* IN_InstanceIDManeger);

	~SXFMapE_PRESENTATION_SIZEC( );

	int	SetParameter( );

public:

/*
  ENTITY presentation_size;
	  unit : presentation_size_assignment_select;
	  size : planar_box;
	WHERE
	  ......
  END_ENTITY; -- presentation_size
*/

	int m_Unit_Inst;
	SXFMapE_DRAWING_SHEET_REVISIONC* m_Unit_p;

	int m_Size_Inst;
	SXFMapE_PLANAR_BOXC* m_Size_p;

};
#endif
////////////////////////////
