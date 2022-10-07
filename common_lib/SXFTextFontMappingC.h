/**
	All Rights Reserved,(c) JACIC 2001
	SXFTextFontMappingC.h								�쐬���F2000.4.14

	�P�D�N���X�T�v
	�����t�H���g��Mapping

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.14			�{��(FQS)			�Ȃ��B

**/

#if !defined(AFX_SXFTEXTFONTMAPPINGC_H__279A9280_1095_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFTEXTFONTMAPPINGC_H__279A9280_1095_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFStruct.h"

class SXFD_InstC;
class SXFD_TypeC;
class SXFD_StrC;
class SXFPart21FileC;

class SXFTextFontMappingC  
{
public:
	int GetID();
	BOOL WriteAP202(SXFPart21FileC* IN_File);
	BOOL MappingStruct(Text_Font_Struct* IN_Struct);
	SXFTextFontMappingC();
	virtual ~SXFTextFontMappingC();

private:
	//////////////////////////////////////
	//�C���X�^���XID
	//////////////////////////////////////
	int m_ID;
	//////////////////////////////////////
	//������^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_StrC* m_str2;
	SXFD_StrC* m_str1;
	//////////////////////////////////////
	//�C���X�^���X�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_InstC* m_inst[2];
	//////////////////////////////////////
	//TYPE�^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_TypeC* m_type2;
	SXFD_TypeC* m_type1;
};

#endif // !defined(AFX_SXFTEXTFONTMAPPINGC_H__279A9280_1095_11D4_A76E_00000EB03267__INCLUDED_)
