/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_FILL_AREA_STYLEC.h						�쐬���F2000.04.17

	�P�D�N���X�T�v
		FILL_AREA_STYLE���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#ifndef _SXFMapE_FILL_AREA_STYLEC_CLASS_
#define _SXFMapE_FILL_AREA_STYLEC_CLASS_

#include "SXFMapE_FILL_AREA_STYLE_TILEC.h"

class SXFMapE_FILL_AREA_STYLEC:public SXFMapEntityBaseC{
public :
	SXFMapE_FILL_AREA_STYLEC( );
	SXFMapE_FILL_AREA_STYLEC(
		SXFInstanceIDC* IN_InstanceIDManeger);

	~SXFMapE_FILL_AREA_STYLEC( );

	int	SetParameter( );

public:

/*
  ENTITY fill_area_style;
	  name		  : label;
	  fill_styles : SET [1:?] OF fill_style_select;
	WHERE
	  wr1: SIZEOF(QUERY ( fill_style <* SELF.fill_styles | ((
			   'ASSOCIATIVE_DRAUGHTING.' + 'FILL_AREA_STYLE_COLOUR') IN 
			   TYPEOF(fill_style)) )) <= 1;
  END_ENTITY; -- fill_area_style
*/
//#1204 = FILL_AREA_STYLE('fill_area_style2', (#1203));

	CString m_Name;

	CArray<int,int> m_FillStyleArray_Inst;
	int m_FillStyle_Count;

 /* CArray<SXFMapE_FILL_AREA_STYLE_TILEC*,
		   SXFMapE_FILL_AREA_STYLE_TILEC*>
		   m_FillStyleArray_p;*/
	// 
	CArray<void*,void*> m_FillStyleArray_p;

//	void* m_FillStyle1;
//	void* m_FillStyle2;
//	void* m_FillStyle3;
//	void* m_FillStyle4;

	// FILL_AREA�̖��O
	CStringArray	m_FillStyle_Name;
};

#endif
////////////////////////////
