/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_STYLED_ITEMC.cpp						�쐬���F2000.04.17

	�P�D�N���X�T�v
		STYLED_ITEM���Ǘ�����

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#include "stdafx.h"
#include "SXFMapE_STYLED_ITEMC.h"
#include "SXFMapEntAConvC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_STYLED_ITEMC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�f�t�H���g�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_STYLED_ITEMC::SXFMapE_STYLED_ITEMC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_STYLED_ITEMC::SXFMapE_STYLED_ITEMC()
{
//	<�G���e�B�e�B�f�[�^>
//#101 = STYLED_ITEM((#508), #505);
//	<�}�`������,�C���X�^���X���ւ̂h�c>
	m_AppeID =  m_InstID = 0;
//	<�}�`�������C���X�^���X���ւ̃|�C���^>
//	m_AppeP = m_InstP = NULL;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_STYLED_ITEMC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�G���e�B�e�B�f�[�^���w�肵�Đ�������ꍇ
		(�R���X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_STYLED_ITEMC::SXFMapE_STYLED_ITEMC(
						SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	����  �F	�^				������				���e
				SXFInstanceIDC* IN_InstanceIDManeger	�ݽ�ݽID�Ǘ���޼ު��

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_STYLED_ITEMC::SXFMapE_STYLED_ITEMC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
{
//	<�G���e�B�e�B�f�[�^>
//#101 = STYLED_ITEM((#508), #505);
//	<�}�`������,�C���X�^���X���ւ̂h�c>
	m_AppeID =  m_InstID = 0;
//	<�}�`�������C���X�^���X���ւ̃|�C���^>
//	m_AppeP = m_InstP = NULL;
}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_STYLED_ITEMC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		(�f�X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_STYLED_ITEMC::~SXFMapE_STYLED_ITEMC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_STYLED_ITEMC::~SXFMapE_STYLED_ITEMC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_STYLED_ITEMC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�G���e�B�e�B�f�[�^�̓o�^

	�Q�D�C���^�[�t�F�C�X
		int		SXFMapE_STYLED_ITEMC::SetParameter()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
int SXFMapE_STYLED_ITEMC::SetParameter()

{

//	<�G���e�B�e�B�f�[�^>
//#101 = STYLED_ITEM( '' , (#508), #505);
//	<�}�`������,�C���X�^���X���ւ̂h�c>
	m_AppeID =  m_InstID = 0;
	int num;
	CArray<int,int> OUT_array;

	SXFMapEntAConvC convent(m_EntityArray);

//	styled_item �P�Ƃ̎���name�p�����^���K�v /////////////////////
 //	1. name�p�����^>
	convent.GetCString(0,m_name);

//	<�������ւ̂h�c>
	convent.GetSetInst(1,num, OUT_array);
	m_AppeID = OUT_array[0];

//	<�C���X�^���X���ւ̂h�c>
	convent.GetInst(2,m_InstID);

//////////////////////////////////////////////////////////////////
//	<�������ւ̂h�c>
//	convent.GetSetInst(0,num, OUT_array);
//	m_AppeID = OUT_array[0];
//	<�C���X�^���X���ւ̂h�c>
//	convent.GetInst(1,m_InstID);

	return 0;
}
