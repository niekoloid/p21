/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_SYMBOL_COLOURC.cpp						�쐬���F2000.04.17

	�P�D�N���X�T�v
		SYMBOL_COLOUR���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#include "stdafx.h"
#include "SXFMapE_SYMBOL_COLOURC.h"
#include "SXFMapEntAConvC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_SYMBOL_COLOURC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�f�t�H���g�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_SYMBOL_COLOURC::SXFMapE_SYMBOL_COLOURC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_SYMBOL_COLOURC::SXFMapE_SYMBOL_COLOURC()
{
//	<������>
	m_EntityName = DEF_SYMBOL_COLOUR;
//<�G���e�B�e�B�f�[�^>

//#100 = SYMBOL_COLOUR(#40);

//�C���X�^���XID���`�e�[�u���I�u�W�F�N�g�ɓn���A
//�Y�������`�e�[�u���̃R�[�h���󂯎��B
//���̂��ߎQ�Ɛ�̃G���e�B�e�B�C���X�^���X�͍쐬���Ȃ��B

	//	1. colour �ւ̃C���X�^���XID
	m_colour_Inst =0;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_SYMBOL_COLOURC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�C���X�^���X�h�c�ւ̃|�C���^���w�肵�Đ�������ꍇ
		(�R���X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_SYMBOL_COLOURC::SXFMapE_SYMBOL_COLOURC(
						SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	����  �F	�^				������				���e
				SXFInstanceIDC* IN_InstanceIDManeger	�ݽ�ݽID�Ǘ���޼ު��

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_SYMBOL_COLOURC::SXFMapE_SYMBOL_COLOURC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
{
//	<������>
	m_EntityName = DEF_SYMBOL_COLOUR;
//<�G���e�B�e�B�f�[�^>
//#100 = SYMBOL_COLOUR(#40);

//�C���X�^���XID���`�e�[�u���I�u�W�F�N�g�ɓn���A
//�Y�������`�e�[�u���̃R�[�h���󂯎��B
//���̂��ߎQ�Ɛ�̃G���e�B�e�B�C���X�^���X�͍쐬���Ȃ��B

	//	1. colour �ւ̃C���X�^���XID
	m_colour_Inst =0;
}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_SYMBOL_COLOURC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		(�f�X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_SYMBOL_COLOURC::~SXFMapE_SYMBOL_COLOURC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_SYMBOL_COLOURC::~SXFMapE_SYMBOL_COLOURC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_SYMBOL_COLOURC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�G���e�B�e�B�̃p�����^�ݒ�

	�Q�D�C���^�[�t�F�C�X
		int		SXFMapE_SYMBOL_COLOURC::SetParameter()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
int SXFMapE_SYMBOL_COLOURC::SetParameter()
{
//	<1. �G���e�B�e�B�p�����^�̐ݒ�>

//<�G���e�B�e�B�f�[�^>

//#100 = SYMBOL_COLOUR(#40);

	SXFMapEntAConvC convent(m_EntityArray);

//�C���X�^���XID���`�e�[�u���I�u�W�F�N�g�ɓn���A
//�Y�������`�e�[�u���̃R�[�h���󂯎��B
//���̂��ߎQ�Ɛ�̃G���e�B�e�B�C���X�^���X�͍쐬���Ȃ��B

	//	2.colour �ւ̃C���X�^���XID
	convent.GetInst(0,m_colour_Inst);

	return 0;
}
