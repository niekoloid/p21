/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapInstIDC.h						�쐬���F2000.04.21

	�P�D�N���X�T�v
		InstanceID�N���X�ւ̃A�N�Z�X���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.21	

**/
#ifndef _SXFMAPINSTIDC_CLASS_
#define _SXFMAPINSTIDC_CLASS_

#include <afx.h>
#include <afxtempl.h>
#include "SXFErrorMsgC.h"

class SXFInstanceIDC;

class SXFMapInstIDC{

public :
//
//	<�f�t�H���g�R���X�g���N�^>
	SXFMapInstIDC() ;
	
//	<�R���X�g���N�^>
//	�C���X�^���X�h�c�ւ̃|�C���^��o�^����������
	SXFMapInstIDC(SXFInstanceIDC* IN_InstanceIDManeger) ;

//	<�f�X�g���N�^>
//
	virtual	~SXFMapInstIDC() ;


private :

protected :


//	<�C���X�^���X�h�c���w�肵�G���e�B�e�B�����擾����>
	CString		GetEntityName(int);
	
//	<�C���X�^���X�h�c���w�肵�G���e�B�e�B���ƃG���e�B�e�B�f�[�^���擾����>
	CString		GetEntityData(int) ;

//	<�G���e�B�e�B�����w�肵�A���̃G���e�B�e�B�����C���X�^���X�ɂ��h�c�Q���擾����>
//	CArray<int,int>*  GetIDArray(CString IN_InstanceName) ;	
	CList<int,int>*  GetIDArray(CString IN_InstanceName) ;	
//	<�C���X�^���X�h�c���w�肵�G���e�B�e�B���ƃG���e�B�e�B�f�[�^(Split)���擾����>
//	<�C���X�^���X�h�c���w�肵�G���e�B�e�B���ƃG���e�B�e�B�f�[�^(Split)���擾����>
	BOOL	GetMyArray(int IN_InstID, CStringArray &OUT_EntityDataArray);
	
//	<�C���X�^���X�h�c�ւ̃|�C���^>
	SXFInstanceIDC* m_InstanceIDManager;

//	<�G���e�B�e�B�f�[�^>
    
} ;

#endif
