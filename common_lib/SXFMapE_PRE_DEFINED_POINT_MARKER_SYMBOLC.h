/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_PRE_DEFINED_POINT_MARKER_SYMBOLC.h						�쐬���F2000.04.17

	�P�D�N���X�T�v
		PRE_DEFINED_POINT_MARKER_SYMBOL���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#ifndef _SXFMapE_PRE_DEFINED_POINT_MARKER_SYMBOLC_CLASS_
#define _SXFMapE_PRE_DEFINED_POINT_MARKER_SYMBOLC_CLASS_

class SXFMapE_PRE_DEFINED_POINT_MARKER_SYMBOLC:public SXFMapEntityBaseC{
public :
	SXFMapE_PRE_DEFINED_POINT_MARKER_SYMBOLC( );
	SXFMapE_PRE_DEFINED_POINT_MARKER_SYMBOLC(
		SXFInstanceIDC* IN_InstanceIDManeger);

	~SXFMapE_PRE_DEFINED_POINT_MARKER_SYMBOLC( );

	int	SetParameter( );

public:

/*
  ENTITY pre_defined_point_marker_symbol
	SUBTYPE OF (pre_defined_symbol, pre_defined_marker);
	WHERE
	  wr1: SELF.name IN ['asterisk','circle','dot','plus','square',
			   'triangle','x'];
  END_ENTITY; -- pre_defined_point_marker_symbol
*/

	CString m_Name;

	// pointmarker code
	int		m_code;

};
#endif
////////////////////////////
