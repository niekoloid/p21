/**
	All Rights Reserved,(c) JACIC 2001
	SXFWidthTableC.cpp                �쐬���F2000.04.29

	�P�D�N���X�T�v
		�����e�[�u�������Ǘ�����

	�Q�D����
	    ����ԍ�    ���t��         �S����		�T�v
		�쐬		2000.4.29     �{��(FQS)
**/
#include "stdafx.h"
#include <math.h>
#include "SXFPreWidthTableC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFWidthTableC.cpp                �쐬���F2000.04.29

  �P�D�@�\�T�v
      �R���X�g���N�^

  �Q�D�C���^�[�t�F�[�X
		void	SXFPreWidthTableC::SXFPreWidthTableC()
		
	����	�F	�^		������				���e
		�Ȃ�

  �R�D����
	    ����ԍ�    ���t��			�S����		 �T�v
	    �쐬		2000.04.29      �{��(FQS)
**/
SXFPreWidthTableC::SXFPreWidthTableC()
{
	m_DefaultPreWidthTable.Add(  SXFDefaultPreWidthC( 1, 0.13) );
	m_DefaultPreWidthTable.Add(  SXFDefaultPreWidthC( 2, 0.18) );
	m_DefaultPreWidthTable.Add(  SXFDefaultPreWidthC( 3, 0.25) );
	m_DefaultPreWidthTable.Add(  SXFDefaultPreWidthC( 4, 0.35) );
	m_DefaultPreWidthTable.Add(  SXFDefaultPreWidthC( 5, 0.5) );
	m_DefaultPreWidthTable.Add(  SXFDefaultPreWidthC( 6, 0.7) );
	m_DefaultPreWidthTable.Add(  SXFDefaultPreWidthC( 7, 1.0) );
	m_DefaultPreWidthTable.Add(  SXFDefaultPreWidthC( 8, 1.4) );
	m_DefaultPreWidthTable.Add(  SXFDefaultPreWidthC( 9, 2.0) );
/*  2012.05.21 �g�������X�����������l��0�ɂȂ邽�ߍ폜
	m_DefaultPreWidthTable.Add(  SXFDefaultPreWidthC(10, 0.0) );
*/
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFWidthTableC.cpp                �쐬���F2000.04.29

  �P�D�@�\�T�v
      �f�X�g���N�^

  �Q�D�C���^�[�t�F�[�X
		void	SXFPreWidthTableC::~SXFPreWidthTableC()
		
	����	�F	�^		������				���e
		�Ȃ�

  �R�D����
	    ����ԍ�    ���t��			�S����		 �T�v
	    �쐬		2000.04.29      �{��(FQS)
**/
SXFPreWidthTableC::~SXFPreWidthTableC(){
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFWidthTableC.cpp                �쐬���F2000.04.29

  �P�D�@�\�T�v
      �R�[�h�ɑΉ�����������擾����

  �Q�D�C���^�[�t�F�[�X
		BOOL SXFPreWidthTableC::GetPreWidth(int in_code, 
												double &out_width)

	����	�F	�^		������		���e
				int		in_code		�����R�[�h
				double&	out_width	����

	���A�l
			TRUE		�Ή������������
			FALSE		�Ή���������Ȃ�

  �R�D����
	    ����ԍ�    ���t��			�S����		 �T�v
	    �쐬		2000.04.29      �{��(FQS)
**/
BOOL SXFPreWidthTableC::GetPreWidth(int in_code, double &out_width)
{
/*  2012.09.01 Table�̃T�C�Y���������Ȃ������ߕύX
	if(in_code >= m_DefaultPreWidthTable.GetSize() )
*/
	if(in_code > m_DefaultPreWidthTable.GetSize() )
		return FALSE;

	m_DefaultPreWidthTable[in_code-1].GetWidth(out_width);

	return TRUE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFWidthTableC.cpp                �쐬���F2000.04.29

  �P�D�@�\�T�v
      �����ɑΉ�����R�[�h���擾����

  �Q�D�C���^�[�t�F�[�X
		int SXFPreWidthTableC::GetCode(double IN_Width,double IN_Eps)

	����	�F	�^		������		���e
				double	IN_width	����
				double	IN_Eps		���e�덷

	���A�l
			int		code	�����R�[�h(0:�Ή�����������ނȂ�)

  �R�D����
	    ����ԍ�    ���t��			�S����		 �T�v
	    �쐬		2000.04.29      �{��(FQS)
**/
int SXFPreWidthTableC::GetCode(double IN_Width,double IN_Eps)
{
	for(int i=0;i<m_DefaultPreWidthTable.GetSize();i++){

/* 2012.05.21 �z��͈̔͂𒴂��ăA�N�Z�X���Ă����̂ō폜
		if ((fabs(IN_Width - m_DefaultPreWidthTable[i].m_Width) < IN_Eps) &&
			(fabs(IN_Width - m_DefaultPreWidthTable[i].m_Width) < fabs(IN_Width - m_DefaultPreWidthTable[i+1].m_Width)))
*/
		if (fabs(IN_Width - m_DefaultPreWidthTable[i].m_Width) < IN_Eps) // 2012.05.21
		return m_DefaultPreWidthTable[i].m_Code;
	}
	return 0;
}