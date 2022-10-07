/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_AXIS2_PLACEMENT_2DC.h						�쐬���F2000.04.17

	�P�D�N���X�T�v
		AXIS2_PLACEMENT_2D���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#ifndef _SXFMapE_AXIS2_PLACEMENT_2DC_CLASS_
#define _SXFMapE_AXIS2_PLACEMENT_2DC_CLASS_

#include <afx.h>
#include <afxtempl.h>

#include "SXFMapEntityBaseC.h"

class SXFInstanceIDC;
class SXFMapE_CARTESIAN_POINTC;
class SXFMapE_DIRECTIONC;

class SXFMapE_AXIS2_PLACEMENT_2DC : public SXFMapEntityBaseC {
public :
//
//	<�f�t�H���g�R���X�g���N�^>
	SXFMapE_AXIS2_PLACEMENT_2DC( ) ;

//	<�R���X�g���N�^>
//	<�C���X�^���X�h�c�ւ̃|�C���^��o�^����������>
	SXFMapE_AXIS2_PLACEMENT_2DC(SXFInstanceIDC* IN_InstanceIDManeger) ;

//	<�f�X�g���N�^>
	virtual	~SXFMapE_AXIS2_PLACEMENT_2DC() ;

//�G���e�B�e�B�p�����^�̓o�^
	int	SetParameter();

//	<�����o�ϐ�>	//////////////////////////////////////

//<�G���e�B�e�B�f�[�^>
/*	
	ENTITY placement
	 SUPERTYPE OF (ONEOF (axis2_placement_2d))
	 SUBTYPE OF (geometric_representation_item);
	  location : cartesian_point;
	END_ENTITY; -- placement

	ENTITY axis2_placement_2d
	SUBTYPE OF (placement);
	  ref_direction : OPTIONAL direction;
	DERIVE
	  p : LIST [2:2] OF direction := build_2axes(ref_direction);
	WHERE
	  wr1: SELF\geometric_representation_item.dim = 2;
  END_ENTITY; -- axis2_placement_2d		*/
//#102 = AXIS2_PLACEMENT_2D('axis2_placement_2d1', #101, $);
//#123 = AXIS2_PLACEMENT_2D('axis2_placement_2d2', #121, #122);

	//	1.name�p�����^
	CString		m_name;

	//	2.cartesian_point �ւ̃C���X�^���XID
	int		m_pnt_Inst;
	//cartesian_point�ւ̃|�C���^

	SXFMapE_CARTESIAN_POINTC*	m_pnt_P;

	//	3.DIRECTION �ւ̃C���X�^���XID(OPTIONAL)
	int		m_DIRECTION_Inst;
	//DIRECTION�ւ̃|�C���^
	SXFMapE_DIRECTIONC*	m_DIRECTION_P;

private :

protected :

} ;

#endif
