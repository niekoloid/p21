/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_CIRCLEC.h						�쐬���F2000.04.17

	�P�D�N���X�T�v
		CIRCLE���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#ifndef _SXFMapE_CIRCLEC_CLASS_
#define _SXFMapE_CIRCLEC_CLASS_

//#include <afx.h>
//#include <afxtempl.h>

#include "SXFMapEntityBaseC.h"

class SXFInstanceIDC;
class SXFMapE_AXIS2_PLACEMENT_2DC;

class SXFMapE_CIRCLEC : public SXFMapEntityBaseC {
public :
//
//	<�f�t�H���g�R���X�g���N�^>
	SXFMapE_CIRCLEC( ) ;

//	<�R���X�g���N�^>
//	<�C���X�^���X�h�c�ւ̃|�C���^��o�^����������>
	SXFMapE_CIRCLEC(SXFInstanceIDC* IN_InstanceIDManeger) ;

//	<�f�X�g���N�^>
	virtual	~SXFMapE_CIRCLEC() ;

//�G���e�B�e�B�p�����^�̓o�^
	int	SetParameter();

//	<�����o�ϐ�>	//////////////////////////////////////

//<�G���e�B�e�B�f�[�^>
/*
  ENTITY conic
	SUPERTYPE OF (ONEOF (circle,ellipse))
	SUBTYPE OF (curve);
	  position : axis2_placement;
  END_ENTITY; -- conic

  ENTITY circle
	SUBTYPE OF (conic);
	  radius : positive_length_measure;
  END_ENTITY; -- circle
*/

//#103 = CIRCLE('circle1', #102, 12.5);

	//	1.name�p�����^
	CString		m_name;
	
	//	2.AXIS2_PLACEMENT_2D �ւ̃C���X�^���XID
	int		m_axis2_Inst;
	//AXIS2_PLACEMENT_2D�ւ̃|�C���^
	SXFMapE_AXIS2_PLACEMENT_2DC*	m_axis2_P;

	//	3.���a�̑傫��
	double	m_radius;

private :

protected :

} ;

#endif
