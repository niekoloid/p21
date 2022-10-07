/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntityBaseC.h						�쐬���F2000.04.17

	�P�D�N���X�T�v
		Entity�f�[�^���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#ifndef _SXFMapEntityBaseC_CLASS_
#define _SXFMapEntityBaseC_CLASS_

#include <afx.h>
#include <afxtempl.h>
#include "SXFMapBaseC.h"

class SXFInstanceIDC;

class SXFMapEntityBaseC : public SXFMapBaseC {
public :
//
//	<�f�t�H���g�R���X�g���N�^>
	SXFMapEntityBaseC( ) ;

//	<�R���X�g���N�^>
//	<�C���X�^���X�h�c�ւ̃|�C���^��o�^����������>
	SXFMapEntityBaseC(SXFInstanceIDC* IN_InstanceIDManeger) ;

//	<�f�X�g���N�^>
	virtual	~SXFMapEntityBaseC() ;

//���[�g�h�c�A�G���e�B�e�B���A�G���e�B�e�B�f�[�^�̓o�^
	int	SetEntitydata(int IN_RootID ,CString IN_EntityName, CString IN_EntityData);

//���[�g�h�c�A�G���e�B�e�B���A�G���e�B�e�B�f�[�^(Split)�̓o�^
	int	SetEntityArraydata(int IN_RootID , CString IN_EntityName ,CStringArray* IN_EntityArray);

//�G���e�B�e�B���ƃG���e�B�e�B�f�[�^(Split)�̎擾
	CStringArray*	GetEntityArraydata(int&);

//�C���X�^���X�h�c�̓o�^
	int	SetRootID(int	IN_RootID);

//m_RootID�����ƂɃG���e�B�e�B���ƃG���e�B�e�B�f�[�^(Split)���擾���o�^����
	int	SetEntity();

//
//	<�G���e�B�e�B�f�[�^>
	CString		m_EntityName;
//
//	<�G���e�B�e�B�f�[�^>
	CString		m_EntityData;
//
//	<���������G���e�B�e�B�f�[�^>
	CStringArray*	m_EntityArray;
	CStringArray	m_MyArray;

private :

protected :

//�擾�����G���e�B�e�B����m_EntityName�̃`�F�b�N
	BOOL	Checkm_EntityName(CString IN_EntityName);
} ;

#endif
