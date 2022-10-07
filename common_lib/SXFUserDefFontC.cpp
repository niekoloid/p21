//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFUserDefFontC.h                    �쐬���F2000.04.16
//
//	�P�D�N���X�T�v
//      UserDefFont Instance Table Data���Ǘ�����  
//
//	�Q�D����
//	    ����ԍ�    ���t��         �S����    �T�v
//      �쐬		2000.04.16     ��  
//
//------------------------------------------------------------
#include "stdafx.h"
#include "SXFUserDefFontC.h"
#include "SXFTableMapManagerC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFUserDefFontC.h                    �쐬���F2000.04.16
//
//  �P�D�@�\�T�v
//      �N���X�\�z
//
//  �Q�D�C���^�[�t�F�[�X
//	void	SXFUserDefFontC::SXFUserDefFontC( )
//	����:	�^						������				���e
//			�Ȃ�					
//
//  �R�D����
//	    ����ԍ�    ���t��         �S����    �T�v
//      �쐬		2000.04.16     ��  
//
//------------------------------------------------------------
SXFUserDefFontC::SXFUserDefFontC( )
{
	//initialization
	m_Code = -1;
	m_ID = -1;
	m_Name.Empty();
	m_Segment = -1;
	m_Pitch.RemoveAll();
	m_MappingManager = NULL;
	m_Level1Code = -1;
}
//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFUserDefFontC.h                    �쐬���F2000.04.16
//
//  �P�D�@�\�T�v
//      �N���X����
//
//  �Q�D�C���^�[�t�F�[�X
//	void	SXFUserDefFontC::~SXFUserDefFontC()
//	����:	�^								������				���e
//			�Ȃ�					
//
//  �R�D����
//	    ����ԍ�    ���t��         �S����    �T�v
//      �쐬		2000.04.16     ��  
//
//------------------------------------------------------------
SXFUserDefFontC::~SXFUserDefFontC()
{
}
//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFUserDefFontC.h                    �쐬���F2000.04.16
//
//  �P�D�@�\�T�v
//      Overload the preprocessor symbol "="
//      
//  �Q�D�C���^�[�t�F�[�X
//	SXFUserDefFontC&	SXFUserDefFontC::operator=(const SXFUserDefFontC& IN_Userfont)
//	����:	�^								������				���e
//			SXFUserDefFontC&				IN_Userfont			���[�U��`����
//
//  �R�D����
//	    ����ԍ�    ���t��         �S����    �T�v
//      �쐬		2000.04.16     ��  
//
//------------------------------------------------------------

SXFUserDefFontC& SXFUserDefFontC::operator=(const SXFUserDefFontC& IN_Userfont){
	m_Code = IN_Userfont.m_Code;
	m_ID = IN_Userfont.m_ID;
	m_Name = IN_Userfont.m_Name;
	m_Segment = IN_Userfont.m_Segment;

//	MOD(S)	�`���[�j���O�Ή�	K.Naono	03.07.03
//	for (int i = 0; i < m_Segment; i++){
//		m_Pitch.Add(IN_Userfont.m_Pitch[i]);
//	}
	m_Pitch.Append(IN_Userfont.m_Pitch) ;
//	MOD(E)	�`���[�j���O�Ή�	K.Naono	03.07.03

	m_MappingManager = IN_Userfont.m_MappingManager;
	m_Level1Code = IN_Userfont.m_Level1Code;

	return *this;
}
