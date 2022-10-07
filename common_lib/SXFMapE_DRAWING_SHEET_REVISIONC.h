/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_DRAWING_SHEET_REVISIONC.h						作成日：2000.04.17

	１．クラス概要
		DRAWING_SHEET_REVISIONを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#ifndef _SXFMapE_DRAWING_SHEET_REVISIONC_CLASS_
#define _SXFMapE_DRAWING_SHEET_REVISIONC_CLASS_

class SXFMapE_DRAWING_SHEET_REVISIONC:public SXFMapEntityBaseC{
public :
	SXFMapE_DRAWING_SHEET_REVISIONC( );
	SXFMapE_DRAWING_SHEET_REVISIONC(
		SXFInstanceIDC* IN_InstanceIDManeger);

	~SXFMapE_DRAWING_SHEET_REVISIONC( );

	int	SetParameter( );

	BOOL GetPlanarBoxSize(int IN_ID, double &OUT_X, double&OUT_Y);

public:

/*
  ENTITY drawing_sheet_revision
	SUBTYPE OF (presentation_area);
	  revision_identifier : identifier;
	WHERE
	  ......
  END_ENTITY; -- drawing_sheet_revision
*/
/*
  ENTITY representation;
	  name			   : label;
	  items			   : SET [1:?] OF representation_item;
	  context_of_items : representation_context;
  END_ENTITY; -- representation
*/

	CString m_Name;

	int m_ItemCount;
	CArray<int,int> m_ItemArray_Inst;

	int m_ContextOfItem_Inst;

	CString m_RevisionIdentifier;

};
#endif
////////////////////////////
