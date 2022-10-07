/**
	All Rights Reserved,(c) JACIC 2001
	SXFLayerMappingC.h								�쐬���F2000.4.14

	�P�D�N���X�T�v
	���C����Mapping

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.14			�{��(FQS)			�Ȃ��B

**/

#if !defined(AFX_SXFLAYERMAPPINGC_H__279A9284_1095_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFLAYERMAPPINGC_H__279A9284_1095_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFStruct.h"

class SXFPart21FileC;
class SXFLayerC;
class SXFD_InstC;
class SXFD_StrC;
class SXFD_AggrC;

class SXFLayerMappingC  
{
public:
	BOOL WriteAP202(SXFPart21FileC* IN_File);
	BOOL MappingStruct(SXFLayerC* IN_Layer);
	SXFLayerMappingC();
	virtual ~SXFLayerMappingC();
	int GetID();

private:
	//////////////////////////////////////
	//�C���X�^���X�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_InstC* m_elem1;
	SXFD_InstC* m_sheet;
	SXFD_InstC* m_inst[2];
	//////////////////////////////////////
	//�W���̌^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_AggrC* m_aggr1;
	//////////////////////////////////////
	//������^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_StrC* m_str2;
	SXFD_StrC* m_str1;
	//////////////////////////////////////
	//�C���X�^���XID
	//////////////////////////////////////
	int m_ID;
};

#endif // !defined(AFX_SXFLAYERMAPPINGC_H__279A9284_1095_11D4_A76E_00000EB03267__INCLUDED_)
