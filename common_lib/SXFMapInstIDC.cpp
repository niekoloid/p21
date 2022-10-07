/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapInstIDC.cpp						�쐬���F2000.04.21

	�P�D�N���X�T�v
		InstanceID�N���X�ւ̃A�N�Z�X���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.21	

**/
#include "stdafx.h"
#include <afx.h>
#include "SXFDataStructC.h"
#include "SXFEntityDataC.h"
#include "SXFInstanceIDC.h"
#include "SXFPart21FileC.h"
#include "SXFPart21FileReadC.h"
#include "SXFMapInstIDC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapInstIDC.cpp						�쐬���F2000.04.21

	�P�D�@�\�T�v
		(�f�t�H���g�R���X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapInstIDC::SXFMapInstIDC()
			

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.21	
**/
SXFMapInstIDC::SXFMapInstIDC()
{
//	<������>
	m_InstanceIDManager = NULL ;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapInstIDC.cpp						�쐬���F2000.04.21

	�P�D�@�\�T�v
		�C���X�^���X�h�c�ւ̃|�C���^��o�^����������
		(�R���X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapInstIDC::SXFMapInstIDC(
				SXFInstanceIDC*	IN_InstanceIDManeger)
			

	���� �F	�^				������				���e
			SXFInstanceIDC*	IN_InstanceIDManeger	�ݽ�ݽID�Ǘ���޼ު��

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.21	
**/
SXFMapInstIDC::SXFMapInstIDC(
			SXFInstanceIDC*	IN_InstanceIDManeger) 
{
//	<������>

	m_InstanceIDManager = IN_InstanceIDManeger ;
}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapInstIDC.cpp						�쐬���F2000.04.21

	�P�D�@�\�T�v
		(�f�X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapInstIDC::~SXFMapInstIDC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.21	
**/
SXFMapInstIDC::~SXFMapInstIDC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapInstIDC.cpp						�쐬���F2000.04.21

	�P�D�@�\�T�v
		�C���X�^���X�h�c���w�肵�A�G���e�B�e�B�����擾����

	�Q�D�C���^�[�t�F�C�X
		CString		SXFMapInstIDC::GetEntityName(
					int		IN_InstID)
					

	����  �F	�^			������				���e
				int			IN_InstID		 Instance ID

	���A�l�F��`�e�[�u�����

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.21	
**/
CString	SXFMapInstIDC::	GetEntityName(
			int	IN_InstID)		
{
	CString entityname;
	entityname.Empty();
	//�C���X�^���XID�ɑΉ������G���e�B�e�B�f�[�^���擾
	SXFEntityDataC* entityptr;
	entityptr = m_InstanceIDManager->GetEntityDataPtr(  IN_InstID  );
	if ( entityptr != NULL ){
		//�G���e�B�e�B���̎擾    
		entityname = entityptr->m_EntityName;		
	}
	else{
		//�C���X�^���h�c�ɑΉ������G���e�B�e�B�f�[�^�����݂��Ȃ�
	}

	return entityname;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapInstIDC.cpp						�쐬���F2000.04.21

	�P�D�@�\�T�v
		�C���X�^���X�h�c���w�肵�A�G���e�B�e�B�f�[�^���擾����

	�Q�D�C���^�[�t�F�C�X
		CString		SXFMapInstIDC::GetEntityData(
					int		IN_InstID)
					

	����  �F	�^			������				���e
				int			IN_InstID		 Instance ID

	���A�l�F��`�e�[�u�����

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.21	
**/
CString	SXFMapInstIDC::	GetEntityData(
			int	IN_InstID)	
{
	//�C���X�^���XID�ɑΉ������G���e�B�e�B�f�[�^���擾
	SXFEntityDataC* entityptr;
	entityptr = m_InstanceIDManager->GetEntityDataPtr(  IN_InstID  );

	//�G���e�B�e�B�f�[�^�̎擾
	CString entitydata;
	entityptr->GetEntityData(entitydata);

	return entitydata;
}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapInstIDC.cpp						�쐬���F2000.04.21

	�P�D�@�\�T�v
		�C���X�^���X�h�c���w�肵�A�G���e�B�e�B�f�[�^(Split)���擾����

	�Q�D�C���^�[�t�F�C�X
		CString		SXFMapInstIDC::GetEntityDataArray(
					int		IN_InstID,
					CStringArray	&OUT_EntityDataArray)
					

	����  �F	�^				������					���e
				int				IN_InstID				Instance ID
				CStringArray	&OUT_EntityDataArray

	���A�l�F��`�e�[�u�����

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.21	
**/
BOOL	SXFMapInstIDC::	GetMyArray(
			int				IN_InstID,
			CStringArray	&OUT_EntityDataArray)		
{
	//�C���X�^���XID�ɑΉ������G���e�B�e�B�f�[�^���擾
	SXFEntityDataC* entityptr;
	entityptr = m_InstanceIDManager->GetEntityDataPtr(  IN_InstID  );

	//�G���e�B�e�B�f�[�^�̎擾
	entityptr->GetEntityDataArray(OUT_EntityDataArray);

	return TRUE;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapInstIDC.cpp						�쐬���F2000.04.21

	�P�D�@�\�T�v
		�G���e�B�e�B�����w�肵�A���̃G���e�B�e�B�����C���X�^���X��
		���h�c�Q���擾����

	�Q�D�C���^�[�t�F�C�X
		CString		SXFMapInstIDC::GetIDArray(
					CString IN_InstanceName) 


	����  �F	�^			������				���e
			CString		IN_InstanceName		 �G���e�B�e�B��

	���A�l�F��`�e�[�u�����

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.21	
**/
//	<�G���e�B�e�B�����w�肵�A���̃G���e�B�e�B�����C���X�^���X�ɂ��h�c�Q���擾����>
//CArray<int,int>*  SXFMapInstIDC::GetIDArray(CString IN_InstanceName) 
CList<int,int>*  SXFMapInstIDC::GetIDArray(CString IN_InstanceName) 

{
//	CArray<int,int>* IDarray;
	if (m_InstanceIDManager->GetIDArray(IN_InstanceName)==NULL){
		return NULL;
	}
	else{
		return m_InstanceIDManager->GetIDArray(IN_InstanceName);
	}

//	return IDarray;
}
