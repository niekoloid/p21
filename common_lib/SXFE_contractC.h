/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_contractC.h								�쐬���F2000.4.18

	�P�D�N���X�T�v
	contract�̃G���e�B�e�B�f�[�^�Ǘ�

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/


#if !defined(AFX_SXFE_CONTRACTC_H__A3FCB504_E58B_4149_B828_913B719B2D51__INCLUDED_)
#define AFX_SXFE_CONTRACTC_H__A3FCB504_E58B_4149_B828_913B719B2D51__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SXFD_InstC.h"
class SXFD_StrC;
class SXFD_InstC;

class SXFE_contractC : public SXFD_InstC  
{
public:
	SXFE_contractC(SXFD_StrC* str1,SXFD_StrC* str2,SXFD_InstC* inst);
	virtual ~SXFE_contractC();

};

#endif // !defined(AFX_SXFE_CONTRACTC_H__A3FCB504_E58B_4149_B828_913B719B2D51__INCLUDED_)
