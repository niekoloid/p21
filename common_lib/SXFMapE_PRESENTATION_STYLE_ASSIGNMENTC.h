/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_PRESENTATION_STYLE_ASSIGNMENTC.h						作成日：2000.04.17

	１．クラス概要
		PRESENTATION_STYLE_ASSIGNMENTを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

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
//	<デフォルトコンストラクタ>
	SXFMapE_PRESENTATION_STYLE_ASSIGNMENTC( ) ;

//	<コンストラクタ>
//	<インスタンスＩＤへのポインタを登録し生成する>
	SXFMapE_PRESENTATION_STYLE_ASSIGNMENTC(SXFInstanceIDC* IN_InstanceIDManeger) ;

//	<デストラクタ>
	virtual	~SXFMapE_PRESENTATION_STYLE_ASSIGNMENTC() ;

//エンティティパラメタの登録
	int	SetParameter();

//	<メンバ変数>	//////////////////////////////////////

//<エンティティデータ>
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
	//	1.stylesへのインスタンスＩＤ
	
	//m_STYLE_InsへのインスタンスID
	int		m_styles_Inst;
//	CArray<int,int>		m_styles_Inst;

	//セグメント数	※エンティティパラメタには存在しない。
	int	m_Segment;
	
	//stylesへのポインタ
	void*	m_styles_P;
//	CArray<void*,void*>	m_styles_P;
		
	//stylesの種類
	int m_stylesKind;
		//	NONSTYLE,		//0:不明
		//	CURVESTYLE,		//1:
		//	SYMBOLSTYLE,	//2:
		//	FILLSTYLE,		//3:
		//	TEXTSTYLE,		//4:
		//	NULLSTYLE		//5:

private :

protected :

} ;

#endif
