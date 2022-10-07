/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_VECTORC.cpp						�쐬���F2000.04.17

	�P�D�N���X�T�v
		VECTOR���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#include "stdafx.h"
#include "SXFMapE_VECTORC.h"
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
	SXFMapE_VECTORC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�f�t�H���g�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_VECTORC::SXFMapE_VECTORC()

	����  �F	�^			������				���e
			�Ȃ�
	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_VECTORC::SXFMapE_VECTORC()
{
//	<������>
	m_EntityName = DEF_VECTOR;
//<�G���e�B�e�B�f�[�^>
//#424 = VECTOR('vector1', #423, 30.);
	//name�p�����^
	m_name.Empty();

	//DIRECTION�ւ̃C���X�^���XID
	m_DIRECTION_Inst = 0;
	
	//DIRECTION�ւ̃|�C���^
	m_DIRECTION_P = NULL;

	//�x�N�g���̑傫��
	m_magni = 0.;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_VECTORC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�C���X�^���X�h�c�ւ̃|�C���^���w�肵�Đ�������ꍇ
		(�R���X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_VECTORC::SXFMapE_VECTORC(
					SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	����  �F	�^				������				���e
				SXFInstanceIDC* IN_InstanceIDManeger	�ݽ�ݽID�Ǘ���޼ު��

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_VECTORC::SXFMapE_VECTORC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
{
//	<������>
	m_EntityName = DEF_VECTOR;
//<�G���e�B�e�B�f�[�^>
//#424 = VECTOR('vector1', #423, 30.);
	//name�p�����^
	m_name.Empty();

	//DIRECTION�ւ̃C���X�^���XID
	m_DIRECTION_Inst = 0;
	
	//DIRECTION�ւ̃|�C���^
	m_DIRECTION_P = NULL;

	//�x�N�g���̑傫��
	m_magni = 0.;

}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_VECTORC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		(�f�X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_VECTORC::~SXFMapE_VECTORC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_VECTORC::~SXFMapE_VECTORC()
{
	if(m_DIRECTION_P != NULL)
	{
		delete m_DIRECTION_P;
	}
}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_VECTORC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�G���e�B�e�B�̃p�����^�ݒ�

	�Q�D�C���^�[�t�F�C�X
		int		SXFMapE_VECTORC::SetParameter()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/


int SXFMapE_VECTORC::SetParameter()

{
int ircode;

//	<1. �G���e�B�e�B�p�����^�̐ݒ�>/////////////////////////////////////

//<�G���e�B�e�B�f�[�^>
//#424 = VECTOR('vector1', #423, 30.);
	SXFMapEntAConvC convent(m_EntityArray);
//	<1. name�p�����^>
	convent.GetCString(0,m_name);

	//m_VECTOR_PATTERN_Ins�ւ̃C���X�^���XID�̐ݒ�
	convent.GetInst(1,m_DIRECTION_Inst);
	

//	<2. �Q�Ɛ��DIRECTION�G���e�B�e�B�p�����^�̐ݒ�>
	//#940 = DIRECTION('direction49', (1., 1.));

	//�G���e�B�e�B�C���X�^���X���쐬
//	SXFMapE_DIRECTIONC m_DIRECTION_P(m_InstanceIDManager);
	m_DIRECTION_P = new SXFMapE_DIRECTIONC(m_InstanceIDManager);
	ircode = m_DIRECTION_P->SetRootID(m_DIRECTION_Inst);
		if ( ircode < 0 )	return ircode ;
	//�G���e�B�e�B�p�����^�̐ݒ�
	ircode = m_DIRECTION_P->SetParameter();
		if ( ircode < 0 )	return ircode ;

//	<3.�x�N�g���̑傫��>
	convent.GetDouble(2,m_magni);

	return 0;
}
