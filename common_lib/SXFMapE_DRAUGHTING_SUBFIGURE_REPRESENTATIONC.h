/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_DRAUGHTING_SUBFIGURE_REPRESENTATIONC.h						�쐬���F2000.04.17

	�P�D�N���X�T�v
		DRAUGHTING_SUBFIGURE_REPRESENTATION���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#ifndef _SXFMapE_DRAUGHTING_SUBFIGURE_REPRESENTATIONC_CLASS_
#define _SXFMapE_DRAUGHTING_SUBFIGURE_REPRESENTATIONC_CLASS_

class SXFMapE_DRAUGHTING_SUBFIGURE_REPRESENTATIONC:public SXFMapEntityBaseC{
public :
	SXFMapE_DRAUGHTING_SUBFIGURE_REPRESENTATIONC( );
	SXFMapE_DRAUGHTING_SUBFIGURE_REPRESENTATIONC(
		SXFInstanceIDC* IN_InstanceIDManeger);

	~SXFMapE_DRAUGHTING_SUBFIGURE_REPRESENTATIONC( );

	int	SetParameter( );

public:

/*
  ENTITY draughting_subfigure_representation
	SUBTYPE OF (symbol_representation);
	WHERE
	.......
  END_ENTITY; -- draughting_subfigure_representation
*/
/*
  ENTITY symbol_representation
	SUBTYPE OF (representation);
  END_ENTITY; -- symbol_representation

  ENTITY representation;
	  name			   : label;
	  items			   : SET [1:?] OF representation_item;
	  context_of_items : representation_context;
  END_ENTITY; -- representation
*/
//#227 = DRAUGHTING_SUBFIGURE_REPRESENTATION
//	('$$FM_SubFigTransform', (#140, #180, #200, #226), #225);

	CString m_Name;

	int m_ItemCount;
	CArray<int,int> m_ItemArray_Inst;

	int m_ContextOfItem_Inst;

	CString m_RevisionIdentifier;

};
#endif
////////////////////////////
