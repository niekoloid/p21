/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapFeatureBaseC.cpp						�쐬���F2000.04.17

	�P�D�N���X�T�v
		���[�g�G���e�B�e�BID�A�t�B�[�`���̎�ʁi�A�Z���u���A��`�e�[�u���A��ʁj�A
		�t�B�[�`�������Ǘ�����

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#include "stdafx.h"
#include "SXFMapFeatureBaseC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapFeatureBaseC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapFeatureBaseC::SXFMapFeatureBaseC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapFeatureBaseC::SXFMapFeatureBaseC()
{
//
//	<������>
//
	m_TypeName.Empty();
	m_Type = NONFEATURE;
	m_StructData = NULL;
//	m_FeatureKind	 =0; 
//	m_RootEntityP	=NULL ;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapFeatureBaseC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapFeatureBaseC::SXFMapFeatureBaseC(
						SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapBaseC(IN_InstanceIDManeger)
					

	����  �F	�^				������				���e
				SXFInstanceIDC* IN_InstanceIDManeger	�ݽ�ݽID�Ǘ���޼ު��

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/

//	<�C���X�^���X�h�c�ւ̃|�C���^��o�^����������>
SXFMapFeatureBaseC::SXFMapFeatureBaseC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapBaseC(IN_InstanceIDManeger)
{
	m_TypeName.Empty();
	m_Type = NONFEATURE;
	m_StructData = NULL;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapFeatureBaseC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�f�X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapFeatureBaseC::~SXFMapFeatureBaseC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapFeatureBaseC::~SXFMapFeatureBaseC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapFeatureBaseC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�t�B�[�`�����̐ݒ�

	�Q�D�C���^�[�t�F�C�X
		int		SXFMapFeatureBaseC::SetFeatureName(CString IN_FeatureName)

	����  �F	�^			������				���e
				CString 	IN_FeatureName�@	̨�����

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
int SXFMapFeatureBaseC::SetFeatureName(
			CString IN_FeatureName)
{
	m_TypeName = IN_FeatureName;
	return 0;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapFeatureBaseC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�t�B�[�`�����̎擾

	�Q�D�C���^�[�t�F�C�X
		int		SXFMapFeatureBaseC::GetFeatureName()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�t�B�[�`����

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
CString SXFMapFeatureBaseC::GetFeatureName()
{
	return (m_TypeName) ;
}
