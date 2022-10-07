/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_CIRCLEC.cpp						�쐬���F2000.04.17

	�P�D�N���X�T�v
		CIRCLE���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#include "stdafx.h"
#include "SXFMapE_CIRCLEC.h"
#include "SXFMapE_AXIS2_PLACEMENT_2DC.h"
#include "SXFMapEntAConvC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_CIRCLEC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�f�t�H���g�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_CIRCLEC::SXFMapE_CIRCLEC()

	����  �F	�^			������				���e
			�Ȃ�
	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_CIRCLEC::SXFMapE_CIRCLEC()
{
//	<������>
	m_EntityName = DEF_CIRCLE;

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
	m_name.Empty();

	//	2.AXIS2_PLACEMENT_2D �ւ̃C���X�^���XID
	m_axis2_Inst = 0;
	//AXIS2_PLACEMENT_2D�ւ̃|�C���^
	m_axis2_P = NULL;

	//	3.���a�̑傫��
	m_radius = 0.;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_CIRCLEC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�C���X�^���X�h�c�ւ̃|�C���^���w�肵�Đ�������ꍇ
		(�R���X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_CIRCLEC::SXFMapE_CIRCLEC(
						SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	���� �F	�^				������					���e
			SXFInstanceIDC* IN_InstanceIDManeger	�ݽ�ݽID�Ǘ���޼ު��

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_CIRCLEC::SXFMapE_CIRCLEC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
{
//	<������>
	m_EntityName = DEF_CIRCLE;
//<�G���e�B�e�B�f�[�^>

//#103 = CIRCLE('circle1', #102, 12.5);
	//	1.name�p�����^
	m_name.Empty();

	//	2.AXIS2_PLACEMENT_2D �ւ̃C���X�^���XID
	m_axis2_Inst = 0;
	//AXIS2_PLACEMENT_2D�ւ̃|�C���^
	m_axis2_P = NULL;

	//	3.���a�̑傫��
	m_radius = 0.;
}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_CIRCLEC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		(�f�X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_CIRCLEC::~SXFMapE_CIRCLEC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_CIRCLEC::~SXFMapE_CIRCLEC()
{
	if(m_axis2_P != NULL)
	{
		delete m_axis2_P;
	}
}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_CIRCLEC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�G���e�B�e�B�̃p�����^�ݒ�

	�Q�D�C���^�[�t�F�C�X
		int		SXFMapE_CIRCLEC::SetParameter()

	����  �F	�^			������				���e
					�Ȃ�
	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/


int SXFMapE_CIRCLEC::SetParameter()

{
int ircode;

//	<1. �G���e�B�e�B�p�����^�̐ݒ�>/////////////////////////////////////


//<�G���e�B�e�B�f�[�^>
//#103 = CIRCLE('circle1', #102, 12.5);

	SXFMapEntAConvC convent(m_EntityArray);

	//	1. name�p�����^>
	convent.GetCString(0,m_name);

	//	2.AXIS2_PLACEMENT_2D�ւ̃C���X�^���XID�̐ݒ�
	convent.GetInst(1,m_axis2_Inst);

	//	3.���a�̑傫��
	convent.GetDouble(2,m_radius);

	//	2. �Q�Ɛ��AXIS2_PLACEMENT_2D�G���e�B�e�B�p�����^�̐ݒ�

	//�G���e�B�e�B�C���X�^���X���쐬
	m_axis2_P = new SXFMapE_AXIS2_PLACEMENT_2DC(m_InstanceIDManager);
	ircode = m_axis2_P->SetRootID(m_axis2_Inst);
	if ( ircode < 0 )	return ircode ;
	//�G���e�B�e�B�p�����^�̐ݒ�
	ircode = m_axis2_P->SetParameter();
	if ( ircode < 0 )	return ircode ;
	return 0;
}
