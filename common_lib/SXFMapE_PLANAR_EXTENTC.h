/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_PLANAR_EXTENTC.h						�쐬���F2000.04.17

	�P�D�N���X�T�v
		PLANAR_EXTENT���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#ifndef _SXFMapE_PLANAR_EXTENTC_CLASS_
#define _SXFMapE_PLANAR_EXTENTC_CLASS_

class SXFMapE_PLANAR_EXTENTC:public SXFMapEntityBaseC{
public :
	SXFMapE_PLANAR_EXTENTC( );
	SXFMapE_PLANAR_EXTENTC(
		SXFInstanceIDC* IN_InstanceIDManeger);

	~SXFMapE_PLANAR_EXTENTC( );

	int	SetParameter( );

public:

/*
  ENTITY planar_extent
	SUBTYPE OF (geometric_representation_item);
	  size_in_x : length_measure;
	  size_in_y : length_measure;
  END_ENTITY; -- planar_extent
*/

	CString m_Name;

	double m_Size_x;
	double m_Size_y;

};
#endif
