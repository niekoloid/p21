/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapEntityBaseC.cpp						�쐬���F2000.04.17

	�P�D�N���X�T�v
		Entity�f�[�^���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#include "stdafx.h"
#include "SXFMapEntityBaseC.h"
//#include "ComSplitStringC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntityBaseC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�f�t�H���g�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapEntityBaseC::SXFMapEntityBaseC()

	����  �F	�^			������				���e
			�Ȃ�
	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapEntityBaseC::SXFMapEntityBaseC()
{
//
//	<������>
//
//	<�G���e�B�e�B��>
	m_EntityName.Empty();
//
//	<�G���e�B�e�B�f�[�^>
	m_EntityData.Empty();
//
//	<���������G���e�B�e�B�f�[�^>
	m_EntityArray = &m_MyArray;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntityBaseC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�G���e�B�e�B�f�[�^���w�肵�Đ�������ꍇ
		(�R���X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapEntityBaseC::SXFMapEntityBaseC(
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
SXFMapEntityBaseC::SXFMapEntityBaseC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapBaseC(IN_InstanceIDManeger)
{
//	<�G���e�B�e�B��>
	m_EntityName.Empty();
//	<�G���e�B�e�B�f�[�^>
	m_EntityData.Empty();
//	<���������G���e�B�e�B�f�[�^>
	m_EntityArray = &m_MyArray;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntityBaseC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		(�f�X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapEntityBaseC::~SXFMapEntityBaseC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapEntityBaseC::~SXFMapEntityBaseC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntityBaseC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�G���e�B�e�B�f�[�^�̓o�^

	�Q�D�C���^�[�t�F�C�X
		int		SXFMapEntityBaseC::SetEntitydata(
			int		IN_RootID,		//	<���[�g�h�c>
			CString IN_EntityName,	//	<�G���e�B�e�B��>
			CString IN_EntityData)	//	<�G���e�B�e�B�f�[�^>

	����  �F	�^			������				���e
				int			IN_RootID			���[�g�h�c
				CString 	IN_EntityName		�G���e�B�e�B��
				CString 	IN_EntityData		�G���e�B�e�B�f�[�^

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
int SXFMapEntityBaseC::SetEntitydata(
		int		IN_RootID,		//	<���[�g�h�c>
		CString IN_EntityName,	//	<�G���e�B�e�B��>
		CString IN_EntityData	//	<�G���e�B�e�B�f�[�^>
		)
{
//	//�G���e�B�e�B���̃`�F�b�N
//	if (Checkm_EntityName(IN_EntityName)==FALSE) {
//		// �G���e�B�e�B�����قȂ�
//		return -10000;
//	}
	m_RootID	= IN_RootID;
	m_EntityName = IN_EntityName;
	m_EntityData = IN_EntityData;

	return 0;
}

int SXFMapEntityBaseC::SetEntityArraydata(
		int		IN_RootID,		//	<���[�g�h�c>
		CString IN_EntityName,		//	<�G���e�B�e�B��>
		CStringArray* IN_EntityArray	//	<���������G���e�B�e�B�f�[�^>
		)
{
	m_RootID	= IN_RootID;
	m_EntityName = IN_EntityName;
	m_MyArray.Copy(*IN_EntityArray);

	return 0;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntityBaseC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�G���e�B�e�B�f�[�^�̎擾

	�Q�D�C���^�[�t�F�C�X
	CStringArray*	SXFMapEntityBaseC::GetEntityArraydata(
		int& OUT_Num,		//�z��̑傫��

	����  �F	�^			������				���e
				int& 		OUT_Num

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/

//�G���e�B�e�B���ƃG���e�B�e�B�f�[�^(Split)�̎擾
CStringArray*	SXFMapEntityBaseC::GetEntityArraydata(
		int& OUT_Num		//�z��̑傫��
		 )

{
	OUT_Num = (int)m_EntityArray->GetSize();
	return m_EntityArray;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntityBaseC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�C���X�^���XID����G���e�B�e�B���ƃG���e�B�e�B�f�[�^��o�^����
		

	�Q�D�C���^�[�t�F�C�X
	int	SXFMapEntityBaseC::SetRootID(int	IN_RootID);

	����  �F	�^			������				���e
				int			IN_RootID

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
int		SXFMapEntityBaseC::SetRootID(int	IN_RootID)
{
	if ( IN_RootID == 0 ){
		//�G���e�B�e�B�C���X�^���X�����݂��܂���B
			SXFErrorMsgC::RecordError(
				SXFNOENTITY,			//err���b�Z�[�W�ԍ�
				m_EntityName,		//�G���e�B�e�B��
				2,					//�p�����^�̌�
				m_RootID,			//�p�����^
				m_EntityName
				);
		return SXFNOENTITY;	//-55005

	}
//	<�G���e�B�e�B�f�[�^�̐ݒ�>
//
	m_RootID		= IN_RootID;

//	<�G���e�B�e�B��,�G���e�B�e�B�f�[�^�̐ݒ�>
	if ( SetEntity() < 0 ) {
		// err �C���X�^���X�h�c�ɑΉ������G���e�B�e�B�f�[�^�����݂��Ȃ�
		// �G���e�B�e�B�C���X�^���X�����݂��܂���
			SXFErrorMsgC::RecordError(
				SXFNOENTITY,			//err���b�Z�[�W�ԍ�
				m_EntityName,		//�G���e�B�e�B��
				2,					//�p�����^�̌�
				m_RootID,			//�p�����^
				m_EntityName
				);
		return SXFNOENTITY;	//-55005 
	}

	return 0;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntityBaseC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�G���e�B�e�B���ƃG���e�B�e�B�f�[�^���擾���o�^����

	�Q�D�C���^�[�t�F�C�X
	int	SXFMapEntityBaseC::SetEntity()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
int		SXFMapEntityBaseC::SetEntity()

{
	if ( m_RootID == 0 ){
		//err
		return -10000;
	}
	
//	<�G���e�B�e�B��>
	m_EntityName = SXFMapInstIDC::GetEntityName(m_RootID);
	if ( m_EntityName.IsEmpty()) {
		//err �C���X�^���X�h�c�ɑΉ������G���e�B�e�B�f�[�^�����݂��Ȃ�
		return -12000;
	}
//	<�G���e�B�e�B�f�[�^>
	m_EntityData = SXFMapInstIDC::GetEntityData(m_RootID);
//	<���������G���e�B�e�B�f�[�^>
	SXFMapInstIDC::GetMyArray(m_RootID,m_MyArray);

	return 0;
}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntityBaseC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		//�擾�����G���e�B�e�B����m_EntityName�̃`�F�b�N

	�Q�D�C���^�[�t�F�C�X
BOOL	SXFMapEntityBaseC::Checkm_EntityName(CString IN_EntityName)

	����  �F	�^			������				���e
		CString IN_EntityName	�G���e�B�e�B��

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/

//�G���e�B�e�B���̃`�F�b�N
BOOL	SXFMapEntityBaseC::Checkm_EntityName(
				CString IN_EntityName	//�G���e�B�e�B��
				)
{
	if ( m_EntityName.IsEmpty() ) return TRUE;

	if ( m_EntityName != IN_EntityName){
		//�G���e�B�e�B���̌��
		return FALSE;
	}
	return TRUE;
}
