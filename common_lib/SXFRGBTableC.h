/**
	All Rights Reserved,(c) JACIC 2001
	SXFRGBTableC.cpp                �쐬���F2000.04.29

	�P�D�N���X�T�v
		�F�e�[�u�������Ǘ�����

	�Q�D����
	    ����ԍ�    ���t��         �S����		�T�v
		�쐬		2000.4.29     �{��(FQS)
**/
#ifndef _SXFRGBTABLEC_H_
#define _SXFRGBTABLEC_H_

#include <math.h>
#include <string.h>
#include <afxtempl.h>


class SXFDefaultRGBC{
public:
	SXFDefaultRGBC(){};
	SXFDefaultRGBC(int code,char *name, int red,int green,int blue){
		m_Code = code;
	//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
		//strcpy(m_Name,name);
		strcpy_s(m_Name,_countof(m_Name),name);
		m_Red  = red;
		m_Green = green;
		m_Blue = blue;
	};

	~SXFDefaultRGBC(){
	};

	int GetCode(){
		return m_Code;
	};

	double GetError(int red,int green,int blue){
		double dr,dg,db;
		dr = (double)(m_Red - red);
		dg = (double)(m_Green - green);
		db = (double)(m_Blue - blue);
		return sqrt(dr*dr + dg*dg + db*db );
	};
	void GetDefaultRGB(int& red,int& green,int& blue){
		red = m_Red;
		green = m_Green;
		blue = m_Blue;
	};

	void GetName(char*& name){
		name = m_Name;
	};

public:

	int m_Code;
	char m_Name[16];
	int m_Red;
	int m_Green;
	int m_Blue;
};

typedef CArray<SXFDefaultRGBC,SXFDefaultRGBC&> SXFDEFAULTCOLORTABLE;

class SXFRGBTableC{
public:
	SXFRGBTableC();
	~SXFRGBTableC();
	int  GetCode(int,int,int);
	BOOL GetRGB(const char*,int&,int&,int&,int&);
	BOOL GetPreColor(int code,char*&,int&,int&,int&);
private:
	SXFDEFAULTCOLORTABLE m_DefaultColorTable;

};

#endif//_SXFRGBTABLEC_H_
