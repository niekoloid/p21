/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_LINEC.cpp						�쐬���F2000.04.17

	�P�D�N���X�T�v
		LINE���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/

#include "stdafx.h"
#include "SXFStruct.h"
#include "SXFMapFeatureBaseC.h"
#include "SXFMapF_CurveStyleBaseC.h"
#include "SXFMapE_LINEC.h"
#include "SXFMapE_CARTESIAN_POINTC.h"
#include "SXFMapE_VECTORC.h"
#include "SXFMapEntAConvC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_LINEC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�f�t�H���g�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_LINEC::SXFMapE_LINEC()

	����  �F	�^			������				���e
			�Ȃ�
	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_LINEC::SXFMapE_LINEC()
{
//	<������>
	m_EntityName = DEF_LINE;
//<�G���e�B�e�B�f�[�^>
//#426 = LINE('line1', #425, #424);
	//name�p�����^
	m_name.Empty();

	//VECTOR,CARTESIAN_POINT�ւ̃C���X�^���XID
	m_pnt_Inst = m_vector_Inst = 0;
	
	//VECTOR,CARTESIAN_POINT�ւ̃|�C���^
	m_pnt_P = NULL;
	m_vector_P = NULL;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_LINEC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�C���X�^���X�h�c�ւ̃|�C���^���w�肵�Đ�������ꍇ
		(�R���X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_LINEC::SXFMapE_LINEC(
						SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)


	���� �F	�^				������				���e
			SXFInstanceIDC* IN_InstanceIDManeger	�ݽ�ݽID�Ǘ���޼ު��

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_LINEC::SXFMapE_LINEC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
{
//	<������>
	m_EntityName = DEF_LINE;
//<�G���e�B�e�B�f�[�^>
//#426 = LINE('line1', #425, #424);
	//name�p�����^
	m_name.Empty();

	//VECTOR,CARTESIAN_POINT�ւ̃C���X�^���XID
	m_pnt_Inst = m_vector_Inst = 0;

	//VECTOR,CARTESIAN_POINT�ւ̃|�C���^
	m_pnt_P = NULL;
	m_vector_P = NULL;

}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_LINEC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		(�f�X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_LINEC::~SXFMapE_LINEC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_LINEC::~SXFMapE_LINEC()
{
	if(m_pnt_P != NULL)
	{
		delete m_pnt_P;
	}
	if(m_vector_P != NULL)
	{
		delete m_vector_P;
	}
}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_LINEC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�G���e�B�e�B�̃p�����^�ݒ�

	�Q�D�C���^�[�t�F�C�X
		int		SXFMapE_LINEC::SetParameter()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/


int SXFMapE_LINEC::SetParameter()

{
int ircode;
//	<1. �G���e�B�e�B�p�����^�̐ݒ�>

//<�G���e�B�e�B�f�[�^>
//#426 = LINE('line1', #425, #424);
	SXFMapEntAConvC convent(m_EntityArray);
	//	<name�p�����^>
	convent.GetCString(0,m_name);

	//CARTESIAN_POINT�ւ̃C���X�^���XID�̐ݒ�
	convent.GetInst(1,m_pnt_Inst);

	//VECTOR�ւ̃C���X�^���XID�̐ݒ�
	convent.GetInst(2,m_vector_Inst);

//	<2. �Q�Ɛ�̃G���e�B�e�B�p�����^�̐ݒ�>

	//CARTESIAN_POINT
	//�G���e�B�e�B�C���X�^���X���쐬
//	SXFMapE_CARTESIAN_POINTC m_pnt_P(m_InstanceIDManager);
	m_pnt_P = new SXFMapE_CARTESIAN_POINTC(m_InstanceIDManager);
	ircode = m_pnt_P->SetRootID(m_pnt_Inst);
	if ( ircode < 0 )	return ircode ;
	//�G���e�B�e�B�p�����^�̐ݒ�
	ircode = m_pnt_P->SetParameter();
	if ( ircode < 0 )	return ircode ;

	//VECTOR
//	SXFMapE_VECTORC m_vector_P(m_InstanceIDManager);
	m_vector_P = new SXFMapE_VECTORC(m_InstanceIDManager);
	ircode = m_vector_P->SetRootID(m_vector_Inst);
	if ( ircode < 0 )	return ircode ;
	//�G���e�B�e�B�p�����^�̐ݒ�
	ircode = m_vector_P->SetParameter();
	if ( ircode < 0 )	return ircode ;
	return 0;
}
