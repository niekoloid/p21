//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFUserDefColorC.h                    �쐬���F2000.04.10
//
//	�P�D�N���X�T�v
//      UserDefColor Instance Table Data���Ǘ�����
//
//	�Q�D����
//	    ����ԍ�    ���t��         �S����    �T�v
//      �쐬		2000.04.10     ��
//
//------------------------------------------------------------
#ifndef _SXFUSERDEFCOLORC_H_
#define _SXFUSERDEFCOLORC_H_

#include <afx.h>

class SXFTableMapManagerC;

class SXFUserDefColorC
{
public:
	SXFUserDefColorC(  );
	virtual ~SXFUserDefColorC();

public:
	int m_Code;
	int m_ID;
	CString m_Name;
	int R,G,B;

	SXFTableMapManagerC* m_MappingManager;

	int m_Level1Code;

};
#endif
