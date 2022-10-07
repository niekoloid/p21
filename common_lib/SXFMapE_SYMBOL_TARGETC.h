/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_SYMBOL_TARGETC.h						�쐬���F2000.04.17

	�P�D�N���X�T�v
		SYMBOL_TARGET���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#ifndef _SXFMapE_SYMBOL_TARGETC_CLASS_
#define _SXFMapE_SYMBOL_TARGETC_CLASS_

#include "SXFMapE_AXIS2_PLACEMENT_2DC.h"

class SXFMapE_SYMBOL_TARGETC:public SXFMapEntityBaseC{
public :
	SXFMapE_SYMBOL_TARGETC( );
	SXFMapE_SYMBOL_TARGETC(
		SXFInstanceIDC* IN_InstanceIDManeger);

	~SXFMapE_SYMBOL_TARGETC( );

	int	SetParameter( );

public:

/*
  ENTITY symbol_target
	SUBTYPE OF (geometric_representation_item);
	  placement : axis2_placement;
	  x_scale	: positive_ratio_measure;
	  y_scale	: positive_ratio_measure;
  END_ENTITY; -- symbol_target
*/

	CString m_Name;

	int m_Placement_Inst;
	SXFMapE_AXIS2_PLACEMENT_2DC* m_Placement_p;

	double m_Scale_x;
	double m_Scale_y;

};
#endif
////////////////////////////
