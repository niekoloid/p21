/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_SYMBOL_REPRESENTATION_MAPC.h						作成日：2000.04.17

	１．クラス概要
		SYMBOL_REPRESENTATION_MAPを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#ifndef _SXFMapE_SYMBOL_REPRESENTATION_MAPC_CLASS_
#define _SXFMapE_SYMBOL_REPRESENTATION_MAPC_CLASS_

#include "SXFMapEntityBaseC.h"

class SXFInstanceIDC;
class SXFMapE_AXIS2_PLACEMENT_2DC;
class SXFMapE_DRAUGHTING_SUBFIGURE_REPRESENTATIONC;

class SXFMapE_SYMBOL_REPRESENTATION_MAPC:public SXFMapEntityBaseC{
public :
	SXFMapE_SYMBOL_REPRESENTATION_MAPC( );
	SXFMapE_SYMBOL_REPRESENTATION_MAPC(
		SXFInstanceIDC* IN_InstanceIDManeger);

	~SXFMapE_SYMBOL_REPRESENTATION_MAPC( );

	int	SetParameter( );

public:
/*
//#220 = SYMBOL_REPRESENTATION_MAP(#226, #227);
//#227 = DRAUGHTING_SUBFIGURE_REPRESENTATION
//('$$FM_SubFigTransform', (#140, #180, #200, #226), #225);

  ENTITY symbol_representation_map
	SUBTYPE OF (representation_map);
	WHERE
	  wr1: 'ASSOCIATIVE_DRAUGHTING.SYMBOL_REPRESENTATION' IN TYPEOF(SELF\
			   representation_map.mapped_representation);
	  wr2: 'ASSOCIATIVE_DRAUGHTING.AXIS2_PLACEMENT' IN TYPEOF(SELF\
			   representation_map.mapping_origin);
  END_ENTITY; -- symbol_representation_map
	ENTITY representation_map;
	  mapping_origin		: representation_item;
	  mapped_representation : representation;
	INVERSE
	  map_usage : SET [1:?] OF mapped_item FOR mapping_source;
	WHERE
	  wr1: item_in_context(SELF.mapping_origin,SELF.mapped_representation.
			   context_of_items);
  END_ENTITY; -- representation_map

*/

	int		m_axis2_Inst;
	SXFMapE_AXIS2_PLACEMENT_2DC* m_axis2_P;

	int		m_subfig_rep_Inst;
	SXFMapE_DRAUGHTING_SUBFIGURE_REPRESENTATIONC* m_subfig_rep_P;
};
#endif
