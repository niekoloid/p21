/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_calendar_dateC.h								�쐬���F2000.4.18

	�P�D�N���X�T�v
	calendar_date�̃G���e�B�e�B�f�[�^�Ǘ�

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/

#if !defined(AFX_SXFE_CALENDAR_DATEC_H__A801C3B8_4027_43B1_A92A_B1AD3240466B__INCLUDED_)
#define AFX_SXFE_CALENDAR_DATEC_H__A801C3B8_4027_43B1_A92A_B1AD3240466B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SXFD_InstC.h"
class SXFD_IntC;

class SXFE_calendar_dateC : public SXFD_InstC  
{
public:
	SXFE_calendar_dateC(SXFD_IntC* yy,SXFD_IntC* dd,SXFD_IntC* mm);
	virtual ~SXFE_calendar_dateC();

};

#endif // !defined(AFX_SXFE_CALENDAR_DATEC_H__A801C3B8_4027_43B1_A92A_B1AD3240466B__INCLUDED_)
