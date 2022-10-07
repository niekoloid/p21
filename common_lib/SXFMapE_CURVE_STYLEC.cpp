/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_CURVE_STYLEC.cpp						�쐬���F2000.04.17

	�P�D�N���X�T�v
		CURVE_STYLE���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#include "stdafx.h"
#include "SXFMapE_CURVE_STYLEC.h"
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
	SXFMapE_CURVE_STYLEC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�f�t�H���g�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_CURVE_STYLEC::SXFMapE_CURVE_STYLEC()

	����  �F	�^			������				���e
			�Ȃ�
	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_CURVE_STYLEC::SXFMapE_CURVE_STYLEC()
{
//	<������>
	m_EntityName = DEF_CURVE_STYLE;
//<�G���e�B�e�B�f�[�^>

//#100 = CURVE_STYLE('curve_style3', #20, #60, #40);
	//	1.name�p�����^
	m_name.Empty();

	//	2.font �ւ̃C���X�^���XID
	m_font_Inst= 0;

	//	3.width �ւ̃C���X�^���XID
	m_width_Inst=0;

	//	4.colour �ւ̃C���X�^���XID
	m_colour_Inst=0;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_CURVE_STYLEC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�C���X�^���X�h�c�ւ̃|�C���^���w�肵�Đ�������ꍇ
		(�R���X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_CURVE_STYLEC::SXFMapE_CURVE_STYLEC(
						SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	�����F	�^					������				���e
			SXFInstanceIDC* 	IN_InstanceIDManeger	�ݽ�ݽID�Ǘ���޼ު��

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_CURVE_STYLEC::SXFMapE_CURVE_STYLEC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
{
//	<������>
	m_EntityName = DEF_CURVE_STYLE;
//<�G���e�B�e�B�f�[�^>
//#100 = CURVE_STYLE('curve_style3', #20, #60, #40);
	//	1.name�p�����^
	m_name.Empty();

	//	2.font �ւ̃C���X�^���XID
	m_font_Inst= 0;

	//	3.width �ւ̃C���X�^���XID
	m_width_Inst=0;

	//	4.colour �ւ̃C���X�^���XID
	m_colour_Inst=0;
	
}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_CURVE_STYLEC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		(�f�X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_CURVE_STYLEC::~SXFMapE_CURVE_STYLEC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_CURVE_STYLEC::~SXFMapE_CURVE_STYLEC()
{
}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_CURVE_STYLEC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�G���e�B�e�B�̃p�����^�ݒ�

	�Q�D�C���^�[�t�F�C�X
		int		SXFMapE_CURVE_STYLEC::SetParameter()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/

int SXFMapE_CURVE_STYLEC::SetParameter()

{
//	<1. �G���e�B�e�B�p�����^�̐ݒ�>

//<�G���e�B�e�B�f�[�^>

//#100 = CURVE_STYLE('curve_style3', #20, #60, #40);
	SXFMapEntAConvC convent(m_EntityArray);

	//	1.name�p�����^
	convent.GetCString(0,m_name);

//�C���X�^���XID���`�e�[�u���I�u�W�F�N�g�ɓn���A
//�Y�������`�e�[�u���̃R�[�h���󂯎��B
//���̂��ߎQ�Ɛ�̃G���e�B�e�B�C���X�^���X�͍쐬���Ȃ��B

	//	2.font �ւ̃C���X�^���XID
	convent.GetInst(1,m_font_Inst);

	//	3.width �ւ̃C���X�^���XID
	convent.GetInst(2,m_width_Inst);

	//	4.colour �ւ̃C���X�^���XID
	convent.GetInst(3,m_colour_Inst);

	return 0;
}
