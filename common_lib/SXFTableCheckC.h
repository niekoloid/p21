/**
	All Rights Reserved,(c) JACIC 2001
	SXFTableCheckC.h								�쐬���F2000.4.17

	�P�D�N���X�T�v
		��`�e�[�u���v�f�̃��[���`�F�b�N

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.17			�{��(FQS)			�Ȃ��B

**/

#if !defined(AFX_SXFTABLECHECKC_H__2E711DE2_12B6_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFTABLECHECKC_H__2E711DE2_12B6_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFCheckInfoC.h"

class SXFTableManagerC;

class SXFTableCheckC  :virtual public SXFCheckInfoC
{
public:
	int ExHatchFeature_Check();
	int SfiglocFeature_Check();
	int ExSymbol_Check(int IN_ColorFlag);
	int PointMarkerFeature_CheckC();
	int DimFeature_Check(int IN_TextFlag);
	int CompCurveFeature_Check();
	int LineFeature_Check();
	int TextFeature_Check();
	int FontCheck();
	int WidthCheck();
	int TypeCheck();
	int ColorCheck();
	int LayerCheck();
	SXFTableCheckC();
	virtual ~SXFTableCheckC();

};

#endif // !defined(AFX_SXFTABLECHECKC_H__2E711DE2_12B6_11D4_A76E_00000EB03267__INCLUDED_)
