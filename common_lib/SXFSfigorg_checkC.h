/**
	All Rights Reserved,(c) JACIC 2001
	SXFSfigorg_checkC.h								�쐬���F2000.4.3

	�P�D�N���X�T�v
	�����}�`��`�t�B�[�`���̃��[���`�F�b�N���s���N���X

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.3			�{��(FQS)			�Ȃ��B

**/

#if !defined(AFX_SXFSFIGORG_CHECKC_H__1C2F3FC3_0971_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFSFIGORG_CHECKC_H__1C2F3FC3_0971_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFStruct.h"
#include "SXFCheckInfoC.h"

class SXFSfigorg_checkC  :public SXFCheckInfoC
{
public:
	int str_rule_check(Sfigorg_Struct* IN_sfigorg_str);
	int Feature_rule_check(Sfigorg_Struct* IN_sfigorg_str,
							CString IN_InstanceID);
	SXFSfigorg_checkC();
	virtual ~SXFSfigorg_checkC();

};

#endif // !defined(AFX_SXFSFIGORG_CHECKC_H__1C2F3FC3_0971_11D4_A76E_00000EB03267__INCLUDED_)
