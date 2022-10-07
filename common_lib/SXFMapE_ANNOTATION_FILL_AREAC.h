/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_CARTESIAN_POINTC.h						�쐬���F2000.04.17

	�P�D�N���X�T�v
		CARTESIAN_POINT���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#ifndef _SXFMapE_ANNOTATION_FILL_AREAC_CLASS_
#define _SXFMapE_ANNOTATION_FILL_AREAC_CLASS_

class SXFInstanceIDC;
class SXFMapE_COMPOSITE_CURVEC;

class SXFMapE_ANNOTATION_FILL_AREAC:public SXFMapEntityBaseC{
public :
	SXFMapE_ANNOTATION_FILL_AREAC( );
	SXFMapE_ANNOTATION_FILL_AREAC(
		SXFInstanceIDC* IN_InstanceIDManeger);

	~SXFMapE_ANNOTATION_FILL_AREAC( );

	int	SetParameter( );

public:
//#1201 = ANNOTATION_FILL_AREA('annotation_fill_area2', (#1121, #1181));
//#1181 = COMPOSITE_CURVE('composite_curve4', (#1140, #1160), .F.);
//#1160 = COMPOSITE_CURVE_SEGMENT(.CONTINUOUS., .T., #1165);
/*
  ENTITY annotation_fill_area
	SUBTYPE OF (geometric_representation_item);
	  boundaries : SET [1:?] OF curve;
  END_ENTITY; -- annotation_fill_area
*/
	CString m_Name;

	int m_BoundaryCont;

	CArray<int,int>	m_Boundary_Inst;

	CArray<SXFMapE_COMPOSITE_CURVEC*, SXFMapE_COMPOSITE_CURVEC*>
		m_Boundary_P;

};
#endif
