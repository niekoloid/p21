/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableUniqueCheckC.cpp								�쐬���F2000.4.17

	�P�D�N���X�T�v
		��`�e�[�u���v�f�̃��j�[�N�`�F�b�N���s��

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.17			�{��(FQS)			�Ȃ��B

**/

#if !defined(AFX_SXFTABLEUNIQUECHECKC_H__2E711DE3_12B6_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFTABLEUNIQUECHECKC_H__2E711DE3_12B6_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFCheckInfoC.h"

class SXFTableManagerC;

class SXFTableUniqueCheckC  :virtual public SXFCheckInfoC
{
public:
	int NameUniqueCheck(int IN_TableType);
	SXFTableUniqueCheckC();
	virtual ~SXFTableUniqueCheckC();

protected:
	double	m_UniqueWidth;		/* ���� */
	CString m_UniqueName;		/* ���O */
};

#endif // !defined(AFX_SXFTABLEUNIQUECHECKC_H__2E711DE3_12B6_11D4_A76E_00000EB03267__INCLUDED_)
