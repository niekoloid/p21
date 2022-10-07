/**
	All Rights Reserved,(c) JACIC 2001
	SXFPreLineTypeTableC.cpp                �쐬���F2000.04.29

	�P�D�N���X�T�v
		����`����e�[�u�������Ǘ�����

	�Q�D����
	    ����ԍ�    ���t��         �S����		�T�v
		�쐬		2000.4.29     �{��(FQS)
**/
#include "stdafx.h"
#include <afx.h>
#include "SXFPreLineTypeTableC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFPreLineTypeTableC.cpp                �쐬���F2000.04.29

  �P�D�@�\�T�v
      �N���X�\�z

  �Q�D�C���^�[�t�F�[�X
		void	SXFPreLineTypeTableC::SXFPreLineTypeTableC()
		
	����	�F	�^		������				���e
		�Ȃ�

  �R�D����
	    ����ԍ�    ���t��         �S����		 �T�v
		�쐬		2000.04.29     �{��(FQS)
**/
SXFPreLineTypeTableC::SXFPreLineTypeTableC()
{
	m_DefaultPreLineTypeTable.Add(  SXFDefaultPreLineTypeC( 1,  "continuous",                      "continuous")  );
	m_DefaultPreLineTypeTable.Add(  SXFDefaultPreLineTypeC( 2,  "dashed",                          "dashed")  );
	m_DefaultPreLineTypeTable.Add(  SXFDefaultPreLineTypeC( 3,  "dashed spaced",                   "")  );
	m_DefaultPreLineTypeTable.Add(  SXFDefaultPreLineTypeC( 4,  "long dashed dotted",              "")  );
	m_DefaultPreLineTypeTable.Add(  SXFDefaultPreLineTypeC( 5,  "long dashed double-dotted",       "")  );
	m_DefaultPreLineTypeTable.Add(  SXFDefaultPreLineTypeC( 6,  "long dashed triplicate-dotted",   "")  );
	m_DefaultPreLineTypeTable.Add(  SXFDefaultPreLineTypeC( 7,  "dotted",                          "dotted")  );
	m_DefaultPreLineTypeTable.Add(  SXFDefaultPreLineTypeC( 8,  "chain",                           "chain")  );
	m_DefaultPreLineTypeTable.Add(  SXFDefaultPreLineTypeC( 9,  "chain double dash",               "chain double dash")  );
	m_DefaultPreLineTypeTable.Add(  SXFDefaultPreLineTypeC( 10, "dashed dotted",                   "")  );
	m_DefaultPreLineTypeTable.Add(  SXFDefaultPreLineTypeC( 11, "double-dashed dotted",            "")  );
	m_DefaultPreLineTypeTable.Add(  SXFDefaultPreLineTypeC( 12, "dashed double-dotted",            "")  );
	m_DefaultPreLineTypeTable.Add(  SXFDefaultPreLineTypeC( 13, "double-dashed double-dotted",     "")  );
	m_DefaultPreLineTypeTable.Add(  SXFDefaultPreLineTypeC( 14, "dashed triplicate-dotted",        "")  );
	m_DefaultPreLineTypeTable.Add(  SXFDefaultPreLineTypeC( 15, "double-dashed triplicate-dotted", "")  );
	m_DefaultPreLineTypeTable.Add(  SXFDefaultPreLineTypeC( 16, "",                                "")  );
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFPreLineTypeTableC.cpp                �쐬���F2000.04.29

  �P�D�@�\�T�v
      �f�X�g���N�^

  �Q�D�C���^�[�t�F�[�X
		void	SXFPreLineTypeTableC::~SXFPreLineTypeTableC()
		
	����	�F	�^		������				���e
		�Ȃ�

  �R�D����
	    ����ԍ�    ���t��         �S����		 �T�v
	    �쐬		2000.04.29     �{��(FQS)

**/
SXFPreLineTypeTableC::~SXFPreLineTypeTableC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFPreLineTypeTableC.cpp                �쐬���F2000.04.29

  �P�D�@�\�T�v
      �R�[�h�ɑΉ�������햼���擾����

  �Q�D�C���^�[�t�F�[�X
		BOOL	SXFPreLineTypeTableC::GetPreLinetype(int in_code, 
													char *&out_name)
		
	����	�F	�^		������			���e
				int		in_code			����R�[�h		
				char*&	out_name		���햼
	���A�l
			TRUE	�Ή�������햼����
			FALSE	�Ή�������햼�Ȃ�

  �R�D����
	    ����ԍ�    ���t��         �S����		 �T�v
		 �쐬		2000.04.29     �{��(FQS)

**/
BOOL SXFPreLineTypeTableC::GetPreLinetype(int in_code, char *&out_name)
{
	if(in_code > m_DefaultPreLineTypeTable.GetSize())
		return FALSE;
	m_DefaultPreLineTypeTable[in_code-1].GetName(out_name);
	return TRUE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFPreLineTypeTableC.cpp                �쐬���F2000.04.29

  �P�D�@�\�T�v
      ���햼�ɑΉ�����R�[�h���擾����

  �Q�D�C���^�[�t�F�[�X
	int		SXFPreLineTypeTableC::GetAP202UserDefCode(const char* in_name)
		
	����	�F	�^		������			���e
				char*	int_name		���햼
	���A�l
			int		code	����R�[�h

  �R�D����
	    ����ԍ�    ���t��         �S����		 �T�v
	     �쐬		2000.04.29     �{��(FQS)

**/
int SXFPreLineTypeTableC::GetAP202UserDefCode(const char* in_name)
{
	char* type_name1;
	CString type_name2;
	CString tmp_name = in_name;
	int ret = 1;
	for (int i = 0; i < m_DefaultPreLineTypeTable.GetSize()-1; i++){
		m_DefaultPreLineTypeTable[i].GetName(type_name1);
		type_name2 = type_name1;
		if (tmp_name.Find(type_name2) != -1){
			ret = m_DefaultPreLineTypeTable[i].GetCode();
			break;
		}
	}

	return ret;
}
/**
	All Rights Reserved,(c) JACIC 2001
	SXFPreLineTypeTableC.cpp                �쐬���F2000.04.29

  �P�D�@�\�T�v
      ���햼�ɑΉ�����R�[�h���擾����

  �Q�D�C���^�[�t�F�[�X
	int		SXFPreLineTypeTableC::GetCode(const char* in_name)
		
	����	�F	�^		������			���e
				char*	int_name		���햼
	���A�l
			int		code	����R�[�h

  �R�D����
	    ����ԍ�    ���t��         �S����		 �T�v
	     �쐬		2000.04.29     �{��(FQS)

**/
int SXFPreLineTypeTableC::GetCode(const char* in_name)
{
	char* type_name;
	int ret = 1;
	for (int i = 0; i < m_DefaultPreLineTypeTable.GetSize(); i++){
		m_DefaultPreLineTypeTable[i].GetName(type_name);
		if ( strcmp(type_name,in_name) == 0){
			ret = m_DefaultPreLineTypeTable[i].GetCode();
			break;
		}
	}

	return ret;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFPreLineTypeTableC.cpp                �쐬���F2000.04.29

  �P�D�@�\�T�v
      ���햼�ɑΉ�����R�[�h���擾����

  �Q�D�C���^�[�t�F�[�X
	int		SXFPreLineTypeTableC::GetPreCode(const char* in_name)
		
	����	�F	�^		������			���e
				char*	int_name		���햼
	���A�l
			int		code	����R�[�h

  �R�D����
	    ����ԍ�    ���t��         �S����		 �T�v
	     �쐬		2000.04.29     �{��(FQS)

**/
int SXFPreLineTypeTableC::GetPreCode(const char* in_name)
{
	char* type_name;
	int ret = 0;
	for (int i = 0; i < m_DefaultPreLineTypeTable.GetSize(); i++){
		m_DefaultPreLineTypeTable[i].GetName(type_name);
		if ( strcmp(type_name,in_name) == 0){
			ret = m_DefaultPreLineTypeTable[i].GetCode();
			break;
		}
	}

	return ret;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFPreLineTypeTableC.cpp                �쐬���F2000.04.29

  �P�D�@�\�T�v
      ���햼�ɑΉ�����type���擾����

  �Q�D�C���^�[�t�F�[�X
	int		SXFPreLineTypeTableC::GetUserLinetype(int in_code, char *out_name,size_t NameSize)
		
	����	�F	�^		������			���e
				�@int in_code			����R�[�h
				  char*	out_name		���햼
				  size_t NameSize		���햼�o�b�t�@�T�C�Y
	���A�l
			���펞�FTRUE
			�ُ펞�FFALSE

  �R�D����
	    ����ԍ�    ���t��         �S����		 �T�v
	    �쐬		2000.04.29     �{��(FQS)
		�X�V		2015.04.27		T.Matsushima	JPCERT/CC �w�E �Ǝ㐫�Ή�

**/
//BOOL SXFPreLineTypeTableC::GetUserLinetype(int in_code, char *out_name)
BOOL SXFPreLineTypeTableC::GetUserLinetype(int in_code, char *out_name,size_t NameSize)
{
	char *pre_name;

	if(in_code >= m_DefaultPreLineTypeTable.GetSize())
		return FALSE;
	m_DefaultPreLineTypeTable[in_code-1].GetName(pre_name);
//	MOD(S)	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
	//strcpy(out_name,"$$");
	//strcat(out_name,pre_name);
	//strcat(out_name,"_");
	strcpy_s(out_name,NameSize,"$$");
	strcat_s(out_name,NameSize,pre_name);
	strcat_s(out_name,NameSize,"_");
//	MOD(E)	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27

	return TRUE;
}

