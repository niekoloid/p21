/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_POLYLINEC.h						�쐬���F2000.04.17

	�P�D�N���X�T�v
		POLYLINE���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#ifndef _SXFMapE_POLYLINEC_CLASS_
#define _SXFMapE_POLYLINEC_CLASS_

#include "SXFMapE_CARTESIAN_POINTC.h"

class SXFMapE_POLYLINEC:public SXFMapEntityBaseC{
public :
	SXFMapE_POLYLINEC( );
	SXFMapE_POLYLINEC(
		SXFInstanceIDC* IN_InstanceIDManeger);

	~SXFMapE_POLYLINEC( );

	int	SetParameter( );

public:

	CString m_PolylineName;

	int m_PointCount;

	CArray<int,int>	m_PointArray_Inst;
	CArray<SXFMapE_CARTESIAN_POINTC*, SXFMapE_CARTESIAN_POINTC*>
		m_PointArray_p;

};
#endif
