/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_DEFINED_SYMBOLC.h						�쐬���F2000.04.17

	�P�D�N���X�T�v
		DEFINED_SYMBOL���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#ifndef _SXFMapE_DEFINED_SYMBOLC_CLASS_
#define _SXFMapE_DEFINED_SYMBOLC_CLASS_

#include "SXFMapE_PRE_DEFINED_POINT_MARKER_SYMBOLC.h"
#include "SXFMapE_SYMBOL_TARGETC.h"

class SXFMapE_DEFINED_SYMBOLC:public SXFMapEntityBaseC{
public :
	SXFMapE_DEFINED_SYMBOLC( );
	SXFMapE_DEFINED_SYMBOLC(
		SXFInstanceIDC* IN_InstanceIDManeger);

	~SXFMapE_DEFINED_SYMBOLC( );

	int	SetParameter( );

public:

/*
  ENTITY defined_symbol
	SUBTYPE OF (geometric_representation_item);
	  definition : defined_symbol_select;
	  target	 : symbol_target;
  END_ENTITY; -- defined_symbol
#404 = DEFINED_SYMBOL('defined_symbol1', #403, #402);

*/

	CString m_Name;

	int m_Definition_Inst;
//	SXFMapE_PRE_DEFINED_POINT_MARKER_SYMBOLC* m_Definition_p;
	void* m_Definition_p;
	
	int m_Target_Inst;
	SXFMapE_SYMBOL_TARGETC* m_Target_p;

// defined_symbol���
	int m_DefsymKind;
/*	0:�s��
	1:PRE_DEFINED_POINT_MARKER_SYMBOL
	  wr1: SELF.name IN ['asterisk','circle','dot','plus','square',
			   'triangle','x'];
	2:PRE_DEFINED_TERMINATOR_SYMBOL
	  wr1: SELF.name IN ['blanked arrow','blanked box','blanked dot',
			   'dimension origin','filled arrow','filled box','filled dot',
			   'integral symbol','open arrow','slash','unfilled arrow'];
*/

};
#endif
////////////////////////////
