//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFPreDefFontC.cpp                    �쐬���F2000.04.16
//
//	�P�D�N���X�T�v
//      PreDefFont Instance Table Data���Ǘ�����    
//
//	�Q�D����
//	    ����ԍ�    ���t��         �S����    �T�v
//      �쐬		2000.04.16     ��
//
//------------------------------------------------------------
#include "stdafx.h"
#include "SXFPreLineTypeTableC.h"
#include "SXFPreDefFontC.h"
#include "SXFTableMapManagerC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFPreDefFontC.cpp                    �쐬���F2000.04.16
//
//  �P�D�@�\�T�v
//      �N���X�\�z
//
//  �Q�D�C���^�[�t�F�[�X
//	void	SXFPreDefFontC::SXFPreDefFontC()
//	����:	�^						������				���e
//			�Ȃ�					
//
//  �R�D����
//	    ����ԍ�    ���t��         �S����    �T�v
//      �쐬		2000.04.16     ��
//
//------------------------------------------------------------
SXFPreDefFontC::SXFPreDefFontC()
{
	//initialization 
	m_Code = -1;
	m_ID = -1;
	m_Name.Empty();
	m_MappingManager = NULL;
}
//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFPreDefFontC.cpp                    �쐬���F2000.04.16
//
//  �P�D�@�\�T�v
//      �N���X����
//
//  �Q�D�C���^�[�t�F�[�X
//	void	SXFPreDefFontC::~SXFPreDefFontC()
//	����:	�^								������				���e
//			�Ȃ�					
//
//  �R�D����
//	    ����ԍ�    ���t��         �S����    �T�v
//      �쐬		2000.04.16     ��
//
//------------------------------------------------------------
SXFPreDefFontC::~SXFPreDefFontC()
{
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFPreDefFontC.cpp                    �쐬���F2000.04.16
//
//  �P�D�@�\�T�v
//      PreDefFont Name�̐ݒ�iCode�����߂܂��j
//  �Q�D�C���^�[�t�F�[�X
//      BOOL SetName(LPCTSTR IN_Name)
//	    ����: �^			  ������			    ���e
//            LPCTSTR        IN_Name               ����`���햼
//			
//	    ���A�l	
//            ���펞�FTRUE
//			  �ُ펞�FFALSE
//
//
//  �R�D����
//	    ����ԍ�    ���t��         �S����    �T�v
//      �쐬		2000.04.16     ��
//
//------------------------------------------------------------
BOOL SXFPreDefFontC::SetName(LPCTSTR IN_Name)
{
	SXFPreLineTypeTableC prelinetypetable;
	m_Code = prelinetypetable.GetPreCode(IN_Name);
	if(m_Code <= 0)
		return FALSE;
	m_Name=IN_Name;
	return TRUE;
}