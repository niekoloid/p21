/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapBaseC.cpp						�쐬���F2000.04.17

	�P�D�N���X�T�v
		���[�g�G���e�B�e�BID���Ǘ�����

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/

#include "stdafx.h"
#include "SXFMapBaseC.h"
#include "SXFComInfoC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapBaseC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapBaseC::SXFMapBaseC()

	����  �F	�^			������				���e
			�Ȃ�
	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapBaseC::SXFMapBaseC()
{
//
//	<������>
//
	m_RootID	= 0; 
	m_Eps_lenth = 0.;
	m_Eps_angle = 0.;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapBaseC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapBaseC::SXFMapBaseC(
					SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapInstIDC(IN_InstanceIDManeger)
					

	�����F	�^				������					���e
			SXFInstanceIDC* IN_InstanceIDManeger	�ݽ�ݽID�Ǘ���޼ު��

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/

//	<�C���X�^���X�h�c�ւ̃|�C���^��o�^����������>
SXFMapBaseC::SXFMapBaseC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapInstIDC(IN_InstanceIDManeger)
{
	m_RootID	= 0;
	m_Eps_lenth = 0.;
	m_Eps_angle = 0.;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapBaseC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapBaseC::SXFMapBaseC(
					SXFInstanceIDC* IN_InstanceIDManeger,
					SXFComInfoC* IN_ComInfoC )
		:SXFMapInstIDC(IN_InstanceIDManeger)
					

	�����F	�^				������					���e
			SXFInstanceIDC* IN_InstanceIDManeger	�ݽ�ݽID�Ǘ���޼ު��
			SXFComInfoC* 	IN_ComInfoC				���ʏ��Ǘ���޼ު��

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
//	<�C���X�^���X�h�c�Ƌ��ʏ��Ǘ��ւ̃|�C���^��o�^����������>
SXFMapBaseC::SXFMapBaseC(
		SXFInstanceIDC* IN_InstanceIDManeger,
		SXFComInfoC* IN_ComInfoC )
		:SXFMapInstIDC(IN_InstanceIDManeger)
{
	m_RootID	= 0;
	m_Eps_lenth = 0.;
	m_Eps_angle = 0.;
	m_ComInfoC = IN_ComInfoC;
	m_ComInfoC->Get_Tolerance(m_Eps_lenth, m_Eps_angle) ;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapBaseC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapBaseC::SXFMapBaseC(int  IN_RootID )
					

	�����F	�^				������					���e
			int  			IN_RootID				���[�gID

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
//	<���[�g�h�c���w�肵�Đ�������ꍇ>
SXFMapBaseC::SXFMapBaseC(
			int	IN_RootID )
{
//	<������>
    m_RootID	= IN_RootID;
	m_Eps_lenth = 0.;
	m_Eps_angle = 0.;
}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapBaseC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�f�X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapBaseC::~SXFMapBaseC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapBaseC::~SXFMapBaseC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapBaseC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		���[�gID�̐ݒ�

	�Q�D�C���^�[�t�F�C�X
		int		SXFMapBaseC::SetRootID(int IN_RootID)

	����  �F	�^			������				���e
				int 		IN_RootID			���[�gID

	���A�l�F���[�g�h�c

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
int SXFMapBaseC::SetRootID(int IN_RootID)
{
	m_RootID = IN_RootID;
	return (0) ;
}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapBaseC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		���[�gID�̎擾

	�Q�D�C���^�[�t�F�C�X
		int		SXFMapBaseC::GetRootID()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F���[�g�h�c

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/

int SXFMapBaseC::GetRootID()
{
	return (m_RootID) ;
}
