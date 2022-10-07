/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_PRESENTATION_LAYER_ASSIGNMENTC.h						作成日：2000.04.17

	１．クラス概要
		PRESENTATION_LAYER_ASSIGNMENTを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#ifndef _SXFMapE_PRESENTATION_LAYER_ASSIGNMENTC_CLASS_
#define _SXFMapE_PRESENTATION_LAYER_ASSIGNMENTC_CLASS_

class SXFMapE_PRESENTATION_LAYER_ASSIGNMENTC:public SXFMapEntityBaseC{
public :
	SXFMapE_PRESENTATION_LAYER_ASSIGNMENTC( );
	SXFMapE_PRESENTATION_LAYER_ASSIGNMENTC(
		SXFInstanceIDC* IN_InstanceIDManeger);

	~SXFMapE_PRESENTATION_LAYER_ASSIGNMENTC( );

	int	SetParameter( );

/*
  ENTITY presentation_layer_assignment;
	  name			 : label;
	  description	 : text;
	  assigned_items : SET [1:?] OF layered_item;
  END_ENTITY; -- presentation_layer_assignment
*/

	CString m_Name;

	CString m_Description;

	CArray<int, int> m_AssignedItems;
	int m_AssignedItemsCount;

private:


};
#endif
