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
#ifndef _SXFUSERDEFFONTC_H_
#define _SXFUSERDEFFONTC_H_

#include <afx.h>
#include <afxtempl.h>

class SXFTableMapManagerC;

class SXFUserDefFontC  
{
public:
	SXFUserDefFontC(  );
	virtual ~SXFUserDefFontC();

public:
	int m_Code;
	int m_ID;
	CString m_Name;
	int m_Segment;
	CArray<double,double> m_Pitch;
	SXFUserDefFontC& operator=(const SXFUserDefFontC& IN_Userfont);
	SXFTableMapManagerC* m_MappingManager;
	int m_Level1Code;

};

#endif
