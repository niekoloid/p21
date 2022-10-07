//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFWidthCC.cpp                           �쐬���F2000.04.16
//
//	�P�D�N���X�T�v
//		�����̍\���́A�R�[�h�A�C���X�^���X�h�c�Ȃǂ�ێ�����N���X
//
//	�Q�D����
//	    ����ԍ�    ���t��         �S����    �T�v
//      �쐬		2000.04.16     ��
//
//------------------------------------------------------------

#include "stdafx.h"
#include <afx.h>
#include <math.h>
#include "SXFPreWidthTableC.h"
#include "SXFWidthC.h"
#include "SXFTableMapManagerC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFWidthCC.cpp                           �쐬���F2000.04.16
//
//  �P�D�@�\�T�v
//		�R���X�g���N�^
//
//  �Q�D�C���^�[�t�F�[�X
//		void	SXFWidthC::SXFWidthC( )
//		
//	����	�F	�^		������				���e
//		�Ȃ�
//
//  �R�D����
//	    ����ԍ�    ���t��         �S����    �T�v
//      �쐬		2000.04.16     ��
//
//------------------------------------------------------------
SXFWidthC::SXFWidthC( )
{
	//initialization 
	m_Code = -1;
	m_ID = -1;
	m_Width = -1.0;
	m_MappingManager = NULL;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFWidthCC.cpp                           �쐬���F2000.04.16
//
//  �P�D�@�\�T�v
//		�f�X�g���N�^
//
//  �Q�D�C���^�[�t�F�[�X
//		void	SXFWidthC::~SXFWidthC( )
//		
//	����	�F	�^		������				���e
//		�Ȃ�
//
//  �R�D����
//	    ����ԍ�    ���t��         �S����    �T�v
//      �쐬		2000.04.16     ��
//
//------------------------------------------------------------
SXFWidthC::~SXFWidthC()
{
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFWidthCC.cpp                           �쐬���F2000.04.16
//
//  �P�D�@�\�T�v
//		�����ɑΉ�����R�[�h�����߂�
//      
//  �Q�D�C���^�[�t�F�[�X
//	int InquireCode(double IN_Width,double IN_Eps)
//	����:	�^			������			���e
//			double		IN_Width		����
//			double		IN_Eps			���e�덷	
//
//	���A�l  
//          ���펞�FCode	:��������
//		    �ُ펞�F0		:�Ή�����������ނȂ�
//
//  �R�D����
//	    ����ԍ�    ���t��         �S����    �T�v
//      �쐬		2000.04.16     ��
//
//------------------------------------------------------------
int SXFWidthC::InquireCode(double IN_Width,double IN_Eps)
{
	SXFPreWidthTableC prewidthtable;
	return prewidthtable.GetCode(IN_Width, IN_Eps);
}
