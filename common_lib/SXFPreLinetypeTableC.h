/**
	All Rights Reserved,(c) JACIC 2001
	SXFPreLineTypeTableC.h                �쐬���F2000.04.29

	�P�D�N���X�T�v
		����`����e�[�u�������Ǘ�����

	�Q�D����
	    ����ԍ�    ���t��         �S����		�T�v
		�쐬		2000.4.29     �{��(FQS)
		�X�V		2015.04.27	T.Matsushima	JPCERT/CC �w�E �Ǝ㐫�Ή�
**/
#ifndef _SXFPRELINETYPETABLEC_H_
#define _SXFPRELINETYPETABLEC_H_

#include <string.h>
#include <afxtempl.h>

class SXFDefaultPreLineTypeC{
public:
	SXFDefaultPreLineTypeC()
	{
	};
	
	~SXFDefaultPreLineTypeC()
	{
	};
	
	void GetName(char*& out_name)
	{
		out_name = m_Name;
	};
	
	int GetCode()
	{
		return m_Code;
	};
	
	SXFDefaultPreLineTypeC(int in_code, const char *in_name1, const char *in_name2)
	{
		m_Code = in_code;
	//	MOD(S)	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
		//strcpy(m_Name,in_name1);
		//strcpy(m_Name_202,in_name2);
		strcpy_s(m_Name,_countof(m_Name),in_name1);
		strcpy_s(m_Name_202,_countof(m_Name_202),in_name2);
	//	MOD(E)	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
	};
	
private:
	char m_Name_202[128];
	int m_Code;
	char m_Name[128];
};

typedef CArray<SXFDefaultPreLineTypeC, SXFDefaultPreLineTypeC&> SXFDEFAULTPRELINETYPE;

class SXFPreLineTypeTableC{  

public:
	SXFPreLineTypeTableC();
	~SXFPreLineTypeTableC();
   
	int GetAP202UserDefCode(const char* in_name);
//	BOOL GetUserLinetype(int in_code,char* out_name);					JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
	BOOL GetUserLinetype(int in_code,char* out_name,size_t NameSize);	// �o�b�t�@�T�C�Y��n���悤�ɕύX
	int GetCode(const char* in_name);
	BOOL GetPreLinetype(int in_code, char*& out_name);

	int GetPreCode(const char* in_name);

private:
	SXFDEFAULTPRELINETYPE m_DefaultPreLineTypeTable;

};

#endif // _SXFPRELINETYPETABLEC_H_
