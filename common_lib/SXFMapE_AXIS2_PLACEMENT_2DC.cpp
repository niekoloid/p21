/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_AXIS2_PLACEMENT_2DC.cpp						�쐬���F2000.04.17

	�P�D�N���X�T�v
		AXIS2_PLACEMENT_2D���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#include "stdafx.h"
#include "SXFMapE_AXIS2_PLACEMENT_2DC.h"
#include "SXFMapE_CARTESIAN_POINTC.h"
#include "SXFMapE_DIRECTIONC.h"
#include "SXFMapEntAConvC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_AXIS2_PLACEMENT_2DC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�f�t�H���g�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_AXIS2_PLACEMENT_2DC::SXFMapE_AXIS2_PLACEMENT_2DC()

	����  �F	�^			������				���e
			�Ȃ�
	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_AXIS2_PLACEMENT_2DC::SXFMapE_AXIS2_PLACEMENT_2DC()
{
//	<������>
	m_EntityName = DEF_AXIS2_PLACEMENT_2D;
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
  END_ENTITY; -- axis2_placement_2d     */
//#102 = AXIS2_PLACEMENT_2D('axis2_placement_2d1', #101, $);
//#123 = AXIS2_PLACEMENT_2D('axis2_placement_2d2', #121, #122);

	//	1.name�p�����^
	m_name.Empty();

	//	2.cartesian_point �ւ̃C���X�^���XID
	m_pnt_Inst = 0;
	//cartesian_point�ւ̃|�C���^
	m_pnt_P = NULL;

	//	3.DIRECTION �ւ̃C���X�^���XID(OPTIONAL)
	m_DIRECTION_Inst = 0;
	//DIRECTION�ւ̃|�C���^
	m_DIRECTION_P = NULL;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_AXIS2_PLACEMENT_2DC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�C���X�^���X�h�c�ւ̃|�C���^���w�肵�Đ�������ꍇ
		(�R���X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_AXIS2_PLACEMENT_2DC::SXFMapE_AXIS2_PLACEMENT_2DC(
						SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)

	�����F	�^				������				���e
			SXFInstanceIDC* IN_InstanceIDManeger�@�ݽ�ݽID�Ǘ���޼ު��

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_AXIS2_PLACEMENT_2DC::SXFMapE_AXIS2_PLACEMENT_2DC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
{
//	<������>
	m_EntityName = DEF_AXIS2_PLACEMENT_2D;
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
  END_ENTITY; -- axis2_placement_2d     */
//#102 = AXIS2_PLACEMENT_2D('axis2_placement_2d1', #101, $);
//#123 = AXIS2_PLACEMENT_2D('axis2_placement_2d2', #121, #122);

	//	1.name�p�����^
	m_name.Empty();

	//	2.cartesian_point �ւ̃C���X�^���XID
	m_pnt_Inst = 0;
	//cartesian_point�ւ̃|�C���^
	m_pnt_P = NULL;

	//	3.DIRECTION �ւ̃C���X�^���XID(OPTIONAL)
	m_DIRECTION_Inst = 0;
	//DIRECTION�ւ̃|�C���^
	m_DIRECTION_P = NULL;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_AXIS2_PLACEMENT_2DC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		(�f�X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_AXIS2_PLACEMENT_2DC::~SXFMapE_AXIS2_PLACEMENT_2DC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_AXIS2_PLACEMENT_2DC::~SXFMapE_AXIS2_PLACEMENT_2DC()
{
	if (m_pnt_P != NULL)
	{
		delete m_pnt_P;
	}
	if (m_DIRECTION_P != NULL)
	{
		delete m_DIRECTION_P;
	}
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_AXIS2_PLACEMENT_2DC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�G���e�B�e�B�̃p�����^�ݒ�

	�Q�D�C���^�[�t�F�C�X
		int		SXFMapE_AXIS2_PLACEMENT_2DC::SetParameter()

	����  �F	�^			������				���e
				�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
int SXFMapE_AXIS2_PLACEMENT_2DC::SetParameter()

{
int ircode;
//	<1. �G���e�B�e�B�p�����^�̐ݒ�>

//<�G���e�B�e�B�f�[�^>
//#102 = AXIS2_PLACEMENT_2D('axis2_placement_2d1', #101, $);
//#123 = AXIS2_PLACEMENT_2D('axis2_placement_2d2', #121, #122);

	SXFMapEntAConvC convent(m_EntityArray);
	//	1.name�p�����^
	convent.GetCString(0,m_name);

	//	2.cartesian_point �ւ̃C���X�^���XID
	convent.GetInst(1,m_pnt_Inst);

	//	3.DIRECTION �ւ̃C���X�^���XID(OPTIONAL)
	convent.GetInst(2,m_DIRECTION_Inst);

//	<2. �Q�Ɛ�̃G���e�B�e�B�p�����^�̐ݒ�>

	//CARTESIAN_POINT
	//�G���e�B�e�B�C���X�^���X���쐬
	m_pnt_P = new SXFMapE_CARTESIAN_POINTC(m_InstanceIDManager);
	ircode = m_pnt_P->SetRootID(m_pnt_Inst);
	if ( ircode < 0 )	return ircode ;
	//�G���e�B�e�B�p�����^�̐ݒ�
	ircode = m_pnt_P->SetParameter();
	if ( ircode < 0 )	return ircode ;

	//DIRECTION
	if ( m_DIRECTION_Inst >0 ) {	//optional �ȊO�̎��ɐݒ�
		m_DIRECTION_P = new SXFMapE_DIRECTIONC(m_InstanceIDManager);
		ircode = m_DIRECTION_P->SetRootID(m_DIRECTION_Inst);
			if ( ircode < 0 )	return ircode ;
		//�G���e�B�e�B�p�����^�̐ݒ�
		ircode = m_DIRECTION_P->SetParameter();
		if ( ircode < 0 )	return ircode ;
	}
	return 0;
}
