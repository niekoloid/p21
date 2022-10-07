/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_DRAUGHTING_DRAWING_REVISIONC.h						�쐬���F2000.04.17

	�P�D�N���X�T�v
		DRAUGHTING_DRAWING_REVISION���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#ifndef _SXFMapE_DRAUGHTING_DRAWING_REVISIONC_CLASS_
#define _SXFMapE_DRAUGHTING_DRAWING_REVISIONC_CLASS_

#include "SXFMapE_DRAWING_DEFINITIONC.h"

class SXFMapE_DRAUGHTING_DRAWING_REVISIONC:public SXFMapEntityBaseC{
public :
	SXFMapE_DRAUGHTING_DRAWING_REVISIONC( );
	SXFMapE_DRAUGHTING_DRAWING_REVISIONC(
		SXFInstanceIDC* IN_InstanceIDManeger);

	~SXFMapE_DRAUGHTING_DRAWING_REVISIONC( );

	int	SetParameter( );

public:

/*
  ENTITY draughting_drawing_revision
	SUBTYPE OF (drawing_revision);
	WHERE
	......
  END_ENTITY; -- draughting_drawing_revision
*/
/*
  ENTITY drawing_revision
	SUBTYPE OF (presentation_set);
	  revision_identifier : identifier;
	  drawing_identifier  : drawing_definition;
	  intended_scale	  : OPTIONAL text;
	UNIQUE
	  ur1 : revision_identifier, drawing_identifier;
  END_ENTITY; -- drawing_revision

*/

	CString m_RevisionIdentifier;

	int m_DrawingIdentifier_Inst;
	SXFMapE_DRAWING_DEFINITIONC* m_DrawingIdentifier_p;

	CString m_IntendedScale;

};
#endif
////////////////////////////
