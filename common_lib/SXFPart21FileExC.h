//---------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFPart21FileC.cpp					�쐬���F2001.09.17
//
//	�P�D�N���X�T�v
//		�t�@�C���̓��͂��Ǘ�����
//
//	�Q�D����
//		����ԍ�	���t��		 �S����			�T�v
//		�쐬		2001.09.17	K.Naono(FQS)	�w�b�_��͏����̉��P�Ή�
//
//---------------------------------------------------------

#if !defined(AFX_SXFPART21FILEEXC_H__40E65DD5_E579_4BD7_9F20_F22034443495__INCLUDED_)
#define AFX_SXFPART21FILEEXC_H__40E65DD5_E579_4BD7_9F20_F22034443495__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SXFPart21FileC.h"

#define	ID_ENDSEC			"ENDSEC"
#define	ID_SCADEC			"SCADEC"
#define	ID_LEVEL1			"level1"
#define	ID_LEVEL2			"level2"
#define	ID_AMBI_MODE		"ambi_mode"
#define	ID_FEATURE_MODE		"feature_mode"
#define	ID_AP202_MODE		"AP202_mode"

class CSXFHeaderLex ;

class SXFPart21FileExC : public SXFPart21FileC  
{
public:
	//	�R���X�g���N�^
	SXFPart21FileExC( LPCTSTR IN_lpszFileName, UINT IN_nOpenFlags);

	//	�f�X�g���N�^
	virtual ~SXFPart21FileExC();

	virtual int  ReadHeadSection(HEADSECTION* IO_Head);
//	ADD(S)	�`���[�j���O�Ή�	K.Naono	03.07.04
	virtual int  ReadInstance(INSTANCEDATA *IO_Instance);
//	ADD(E)	�`���[�j���O�Ή�	K.Naono	03.07.04

protected:
	CSXFHeaderLex*	m_pDataLex ;
	CString*		m_pDataRecord ;

private:
	void	getAttribute(
						CSXFHeaderLex*	pLex,
						CStringArray&	array) ;
	int		analyzeDescription(
						CStringArray&	array,
						HEADSECTION*	IO_Head) ;
	int		analyzeName(
						CStringArray&	array,
						HEADSECTION*	IO_Head) ;
	void	skippedComment(CString& recordline) ;
	BOOL	isQuoteString(
						CString&	strRecord,
						int			nIndex) ;
};

#endif // !defined(AFX_SXFPART21FILEEXC_H__40E65DD5_E579_4BD7_9F20_F22034443495__INCLUDED_)
