/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_PRESENTATION_STYLE_ASSIGNMENTC.h						�쐬���F2000.04.17

	�P�D�N���X�T�v
		PRESENTATION_STYLE_ASSIGNMENT���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#ifndef _SXFMapE_PRESENTATION_STYLE_ASSIGNMENTC_CLASS_
#define _SXFMapE_PRESENTATION_STYLE_ASSIGNMENTC_CLASS_

#include <afx.h>
#include <afxtempl.h>

#include "SXFMapEntityBaseC.h"

class SXFInstanceIDC;

class SXFMapE_PRESENTATION_STYLE_ASSIGNMENTC : public SXFMapEntityBaseC {
public :
//
//	<�f�t�H���g�R���X�g���N�^>
	SXFMapE_PRESENTATION_STYLE_ASSIGNMENTC( ) ;

//	<�R���X�g���N�^>
//	<�C���X�^���X�h�c�ւ̃|�C���^��o�^����������>
	SXFMapE_PRESENTATION_STYLE_ASSIGNMENTC(SXFInstanceIDC* IN_InstanceIDManeger) ;

//	<�f�X�g���N�^>
	virtual	~SXFMapE_PRESENTATION_STYLE_ASSIGNMENTC() ;

//�G���e�B�e�B�p�����^�̓o�^
	int	SetParameter();

//	<�����o�ϐ�>	//////////////////////////////////////

//<�G���e�B�e�B�f�[�^>
/*
  ENTITY presentation_style_assignment;
      styles : SET [1:?] OF presentation_style_select;
    WHERE
      wr1: SIZEOF(QUERY ( style1 <* SELF.styles | (NOT (SIZEOF(
               QUERY ( style2 <* (SELF.styles - style1) | (NOT ((TYPEOF(
               style1) <> TYPEOF(style2)) OR (SIZEOF([
               'ASSOCIATIVE_DRAUGHTING.' + 'SURFACE_STYLE_USAGE',
               'ASSOCIATIVE_DRAUGHTING.' + 'EXTERNALLY_DEFINED_STYLE'] * 
               TYPEOF(style1)) = 1))) )) = 0)) )) = 0;
      wr2: SIZEOF(QUERY ( style1 <* SELF.styles | (
               'ASSOCIATIVE_DRAUGHTING.SURFACE_STYLE_USAGE' IN TYPEOF(
               style1)) )) <= 2;
  END_ENTITY; -- presentation_style_assignment

  TYPE presentation_style_select = SELECT
    (curve_style,
     symbol_style,
     fill_area_style,
     text_style,
     null_style);
  END_TYPE; -- presentation_style_select

*/
//#143 = PRESENTATION_STYLE_ASSIGNMENT((#142));
	//	1.styles�ւ̃C���X�^���X�h�c
	
	//m_STYLE_Ins�ւ̃C���X�^���XID
	int		m_styles_Inst;
//	CArray<int,int>		m_styles_Inst;

	//�Z�O�����g��	���G���e�B�e�B�p�����^�ɂ͑��݂��Ȃ��B
	int	m_Segment;
	
	//styles�ւ̃|�C���^
	void*	m_styles_P;
//	CArray<void*,void*>	m_styles_P;
		
	//styles�̎��
	int m_stylesKind;
		//	NONSTYLE,		//0:�s��
		//	CURVESTYLE,		//1:
		//	SYMBOLSTYLE,	//2:
		//	FILLSTYLE,		//3:
		//	TEXTSTYLE,		//4:
		//	NULLSTYLE		//5:

private :

protected :

} ;

#endif
