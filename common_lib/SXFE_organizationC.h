/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_organizationC.h								�쐬���F2000.4.18

	�P�D�N���X�T�v
	organization�̃G���e�B�e�B�f�[�^�Ǘ�

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/

#if !defined(AFX_SXFE_ORGANIZATIONC_H__590B1241_20F4_43AF_B477_C361D5B5A444__INCLUDED_)
#define AFX_SXFE_ORGANIZATIONC_H__590B1241_20F4_43AF_B477_C361D5B5A444__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SXFD_InstC.h"
class SXFD_StrC;

class SXFE_organizationC : public SXFD_InstC  
{
public:
	SXFE_organizationC(SXFD_StrC* str1, SXFD_StrC* str2, SXFD_StrC* str3);
	SXFE_organizationC(SXFD_StrC* str1, SXFD_StrC* str2);
	virtual ~SXFE_organizationC();

};

#endif // !defined(AFX_SXFE_ORGANIZATIONC_H__590B1241_20F4_43AF_B477_C361D5B5A444__INCLUDED_)
