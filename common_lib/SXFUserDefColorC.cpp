//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFUserDefColorC.cpp                   �쐬���F2000.04.10
//
//	�P�D�N���X�T�v
//      UserDefColor Instance Table Data���Ǘ�����
//
//	�Q�D����
//	    ����ԍ�    ���t��         �S����    �T�v
//      �쐬		2000.04.10     ��
//
//------------------------------------------------------------
#include "stdafx.h"
#include "SXFUserDefColorC.h"
#include "SXFTableMapManagerC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFUserDefColorC.cpp                   �쐬���F2000.04.10
//
//  �P�D�@�\�T�v
//      �N���X�\�z
//
//  �Q�D�C���^�[�t�F�[�X
// 	void	SXFUserDefColorC::SXFUserDefColorC( )
//	����:	�^								������				���e
//			�Ȃ�					
//
//  �R�D����
//	    ����ԍ�    ���t��         �S����    �T�v
//      �쐬		2000.04.10     ��
//
//------------------------------------------------------------
SXFUserDefColorC::SXFUserDefColorC( )
{
	//initialization 
	m_Code = -1;
	m_ID = -1;
	m_Name.Empty();
	R=-1;
	G=-1;
	B=-1;
	m_MappingManager = NULL;
	m_Level1Code = -1;
}
//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFUserDefColorC.cpp                   �쐬���F2000.04.10
//
//  �P�D�@�\�T�v
//      �N���X����
//
//  �Q�D�C���^�[�t�F�[�X
//	void	SXFUserDefColorC::~SXFUserDefColorC()
//	����:	�^								������				���e
//			�Ȃ�					
//
//  �R�D����
//	    ����ԍ�    ���t��         �S����    �T�v
//      �쐬		2000.04.10     ��
//
//------------------------------------------------------------
SXFUserDefColorC::~SXFUserDefColorC()
{
}
