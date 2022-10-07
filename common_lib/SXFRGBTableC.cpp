/**
	All Rights Reserved,(c) JACIC 2001
	SXFRGBTableC.cpp                �쐬���F2000.04.29

	�P�D�N���X�T�v
		�F�e�[�u�������Ǘ�����

	�Q�D����
	    ����ԍ�    ���t��         �S����		�T�v
		�쐬		2000.4.29     �{��(FQS)
**/
#include "stdafx.h"
#include <afx.h>
#include "SXFRGBTableC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFRGBTableC.cpp                �쐬���F2000.04.29

  �P�D�@�\�T�v
      �R���X�g���N�^

  �Q�D�C���^�[�t�F�[�X
		void	SXFRGBTableC::SXFRGBTableC()
		
	����	�F	�^		������				���e
		�Ȃ�

  �R�D����
	    ����ԍ�    ���t��			�S����		 �T�v
	    �쐬		2000.04.29      �{��(FQS)
**/
SXFRGBTableC::SXFRGBTableC(){
	m_DefaultColorTable.Add( SXFDefaultRGBC( 1,"black"     ,  0,  0,  0)  );
	m_DefaultColorTable.Add( SXFDefaultRGBC( 2,"red"       ,255,  0,  0)  );
	m_DefaultColorTable.Add( SXFDefaultRGBC( 3,"green"     ,  0,255,  0)  );
	m_DefaultColorTable.Add( SXFDefaultRGBC( 4,"blue"      ,  0,  0,255)  );
	m_DefaultColorTable.Add( SXFDefaultRGBC( 5,"yellow"    ,255,252,  0)  );
	m_DefaultColorTable.Add( SXFDefaultRGBC( 6,"magenta"   ,255,  0,255)  );
	m_DefaultColorTable.Add( SXFDefaultRGBC( 7,"cyan"      ,  0,255,255)  );
	m_DefaultColorTable.Add( SXFDefaultRGBC( 8,"white"     ,255,255,255)  );
	m_DefaultColorTable.Add( SXFDefaultRGBC( 9,"deeppink"  ,192,  0,128)  );
	m_DefaultColorTable.Add( SXFDefaultRGBC(10,"brown"     ,192,128, 64)  );
	m_DefaultColorTable.Add( SXFDefaultRGBC(11,"orange"    ,255,128,  0)  );
	m_DefaultColorTable.Add( SXFDefaultRGBC(12,"lightgreen",128,192,128)  );
	m_DefaultColorTable.Add( SXFDefaultRGBC(13,"lightblue" ,  0,128,255)  );
	m_DefaultColorTable.Add( SXFDefaultRGBC(14,"lavender"  ,128, 64,255)  );
	m_DefaultColorTable.Add( SXFDefaultRGBC(15,"lightgray" ,192,192,192)  );
	m_DefaultColorTable.Add( SXFDefaultRGBC(16,"darkgray"  ,128,128,128)  );
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFRGBTableC.cpp                �쐬���F2000.04.29

  �P�D�@�\�T�v
      �f�X�g���N�^

  �Q�D�C���^�[�t�F�[�X
		void	SXFRGBTableC::~SXFRGBTableC()
		
	����	�F	�^		������				���e
		�Ȃ�

  �R�D����
	    ����ԍ�    ���t��			�S����		 �T�v
	    �쐬		2000.04.29      �{��(FQS)
**/
SXFRGBTableC::~SXFRGBTableC(){
}

int SXFRGBTableC::GetCode(int red,int green,int blue){
	int code = 3;
	double err , min_err = 1.0e99;
	for(int i= 0; i < m_DefaultColorTable.GetSize(); i++){
		err = m_DefaultColorTable[i].GetError(red,green,blue);
		if(err < min_err){
			min_err = err;
			code = m_DefaultColorTable[i].GetCode();
		}
	}
	return code;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFRGBTableC.cpp                �쐬���F2000.04.29

  �P�D�@�\�T�v
      �F������F�R�[�h���擾����

  �Q�D�C���^�[�t�F�[�X
		int	SXFRGBTableC::GetColorCode(const char* name,int& code)
		
	����	�F	�^		������		���e
				char*	name		�F��
				int&	code		�F�R�[�h

	���A�l
			TRUE	�F���ɑΉ�����RGB�l����
			FALSE	�F���ɑΉ�����RGB�l�Ȃ�

  �R�D����
	    ����ԍ�    ���t��			�S����		 �T�v
	    �쐬		2000.04.29      �{��(FQS)
**/
BOOL SXFRGBTableC::GetRGB(const char* name, int& code, int& red, int& green, int& blue){
	char* color_name;
	BOOL findflg= FALSE;
	for (int i= 0; i < m_DefaultColorTable.GetSize(); i++){
		m_DefaultColorTable[i].GetName(color_name);
		if (strcmp(color_name, name) == 0){
			m_DefaultColorTable[i].GetDefaultRGB(red,green,blue);
			code = m_DefaultColorTable[i].m_Code;
			findflg= TRUE;

			break;
		}
	}
	if(findflg== FALSE)
		return FALSE;

	return TRUE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFRGBTableC.cpp                �쐬���F2000.04.29

  �P�D�@�\�T�v
      �F�R�[�h����F�����擾����

  �Q�D�C���^�[�t�F�[�X
		int	SXFRGBTableC::GetPreColor(int code, char* & name, int& red, int& green, int& blue)
		
	����	�F	�^		������		���e
				char*	name		�F��
				int&	code		�F�R�[�h
				int&	red			R�l
				int&	green		G�l
				int&	blue		B�l
	���A�l
			TRUE	�F�R�[�h�ɑΉ�����RGB�l����
			FALSE	�F�R�[�h�ɑΉ�����RGB�l�Ȃ�

  �R�D����
	    ����ԍ�    ���t��			�S����		 �T�v
	    �쐬		2000.04.29      �{��(FQS)
**/
BOOL SXFRGBTableC::GetPreColor(int code, char* & name, int& red, int& green, int& blue)
{
	if(code > m_DefaultColorTable.GetSize())
		return FALSE;
	m_DefaultColorTable[code-1].GetName(name);
	m_DefaultColorTable[code-1].GetDefaultRGB(red,green,blue);
	return TRUE;
}
