/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapA_SYMBOL_STYLEC.cpp						�쐬���F2000.04.21

	�P�D�N���X�T�v
		SYMBOL_STYLE���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.21	

**/
#include "stdafx.h"
#include "SXFMapA_SYMBOL_STYLEC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapA_SYMBOL_STYLEC.cpp						�쐬���F2000.04.21

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapA_SYMBOL_STYLEC::SXFMapA_SYMBOL_STYLEC()

	����  �F	�^			������				���e
			�Ȃ�
	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.21	
**/
SXFMapA_SYMBOL_STYLEC::SXFMapA_SYMBOL_STYLEC()
{
//
//	<������>
//

	//styles�̎��
	m_stylesKind = CURVESTYLE;
		//	NONSTYLE,		//0:�s��
		//	CURVESTYLE,		//1:
		//	SYMBOLSTYLE,	//2:
		//	FILLSTYLE,		//3:
		//	TEXTSTYLE,		//4:
		//	NULLSTYLE		//5:

//	<��`�e�[�u���₢���킹�p�̃C���X�^���XID>
	//	Colour�ւ̃C���X�^���X�h�c
	m_colorID=0;

//	<��`�e�[�u���v�f�̃R�[�hD>
	//	Colour�R�[�h
	m_color=-1;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapA_SYMBOL_STYLEC.cpp						�쐬���F2000.04.21

	�P�D�@�\�T�v
		�f�X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapA_SYMBOL_STYLEC::~SXFMapA_SYMBOL_STYLEC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.21	
**/
SXFMapA_SYMBOL_STYLEC::~SXFMapA_SYMBOL_STYLEC()
{
}
