//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFLayerC.h                           �쐬���F2000.04.16
//
//	�P�D�N���X�T�v
//      Layer Instance Table Data���Ǘ�����
//
//	�Q�D����
//	    ����ԍ�    ���t��         �S����    �T�v
//      �쐬		2000.04.16     ��
//
//------------------------------------------------------------
#ifndef _SXFLAYERC_H_
#define _SXFLAYERC_H_

#include <afx.h>

class SXFTableMapManagerC;

class SXFLayerC  
{
public:
	SXFLayerC();
	virtual ~SXFLayerC();
	SXFLayerC& operator=(const SXFLayerC &IN_Layer);
	int m_Code;
	int m_ID;
	CString m_Name;
	int m_LfFlag;
	int m_ElementsReferenceID;
	CUIntArray m_Element;
	int m_SheetID;
	SXFTableMapManagerC* m_MappingManager;

};

#endif
