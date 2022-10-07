/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_PRESENTATION_LAYER_USAGEC.h						作成日：2000.04.17

	１．クラス概要
		PRESENTATION_LAYER_USAGEを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#ifndef _SXFMapE_PRESENTATION_LAYER_USAGEC_CLASS_
#define _SXFMapE_PRESENTATION_LAYER_USAGEC_CLASS_

#include "SXFMapE_PRESENTATION_LAYER_ASSIGNMENTC.h"

class SXFMapE_PRESENTATION_LAYER_USAGEC:public SXFMapEntityBaseC{
public :
	SXFMapE_PRESENTATION_LAYER_USAGEC( );
	SXFMapE_PRESENTATION_LAYER_USAGEC(
		SXFInstanceIDC* IN_InstanceIDManeger);

	~SXFMapE_PRESENTATION_LAYER_USAGEC( );

	int	SetParameter( );

public:
/*
  ENTITY presentation_layer_usage;
	  assignment   : presentation_layer_assignment;
	  presentation : presentation_representation;
	UNIQUE
	  ur1 : assignment, presentation;
  END_ENTITY; -- presentation_layer_usage
*/
	int m_Assignment_Inst;
	SXFMapE_PRESENTATION_LAYER_ASSIGNMENTC* 
		m_Assignment_p;

	int m_Presentation_Inst;

};
#endif
