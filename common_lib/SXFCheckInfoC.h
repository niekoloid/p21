/**
	All Rights Reserved,(c) JACIC 2001
	SXFCheckInfoC.h  								�쐬���F2001.2.15

	�P�D�N���X�T�v
		���[���`�F�b�N�����Ǘ�����N���X

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.2.15			�{��(FQS)			�Ȃ��B

**/

#if !defined(AFX_SXFCHECKINFOC_H__91910F21_02D7_11D5_A3BC_009027565E9B__INCLUDED_)
#define AFX_SXFCHECKINFOC_H__91910F21_02D7_11D5_A3BC_009027565E9B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>

class SXFTableManagerC;
class SXFComInfoC;

class SXFCheckInfoC  
{
public:
	SXFCheckInfoC();
	virtual ~SXFCheckInfoC();
protected:
	CString				m_InstanceID;		/* �ݽ�ݽID */
	char*				m_feature_name;		/* ̨����� */
	SXFTableManagerC*	m_TableManager;		/* ��`ð��يǗ���޼ު�� */
	SXFComInfoC*		m_ComInfo;			/* ���ʏ���޼ު�� */
	int					m_font;				/* ����̫�ĺ��� */
	int					m_type;				/* ������ */
	int					m_line_width;		/* �������� */
	int					m_color;			/* �F���� */
	int					m_layer;			/* ڲԺ��� */
private:
	void initialize();
};

#endif // !defined(AFX_SXFCHECKINFOC_H__91910F21_02D7_11D5_A3BC_009027565E9B__INCLUDED_)
