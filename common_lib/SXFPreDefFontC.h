//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFPreDefFontC.h					 �쐬���F2000.04.16
//
//	�P�D�N���X�T�v
//		PreDefFont Instance Table Data���Ǘ�����
//
//	�Q�D����
//		����ԍ�	���t��		   �S����	 �T�v
//		�쐬		2000.04.16	   ��
//
//------------------------------------------------------------
#ifndef _SXFPREDEFFONTC_H_
#define _SXFPREDEFFONTC_H_

#include <afx.h>

class SXFTableMapManagerC;

class SXFPreDefFontC  
{
public:
	SXFPreDefFontC( );
	virtual ~SXFPreDefFontC();
	BOOL SetName(LPCTSTR IN_Name);

public:
	int m_Code;
	int m_ID;
	CString m_Name;

	SXFTableMapManagerC* m_MappingManager;

};

#endif
