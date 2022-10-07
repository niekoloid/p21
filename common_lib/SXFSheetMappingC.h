/**
	All Rights Reserved,(c) JACIC 2001
	SXFSheetMappingC.h								�쐬���F2000.4.14

	�P�D�N���X�T�v
	�p����Mapping

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.14			�{��(FQS)			�Ȃ��B

**/

#if !defined(AFX_SXFSHEETMAPPINGC_H__16DFD9E5_1172_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFSHEETMAPPINGC_H__16DFD9E5_1172_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFStruct.h"

class SXFD_InstC;
class SXFD_RealC;
class SXFD_StrC;
class SXFD_AggrC;
class SXFPart21FileC;
class SXFTableManagerC;

class SXFSheetMappingC  
{
public:
	int GetID();
	BOOL WriteAP202(SXFPart21FileC *IN_File);
//	BOOL MappingStruct(Sheet_Struct IN_Struct,CUIntArray* IN_ChildrenID);
	BOOL MappingStruct(
						Sheet_Struct		IN_Struct,
						CUIntArray*			IN_ChildrenID,
						Attribute_Struct*	IN_AttrStr) ;
	SXFSheetMappingC();
	SXFSheetMappingC(SXFTableManagerC* IN_TableManagerC);
	virtual ~SXFSheetMappingC();
//	ADD(S)	Ver3.0�Ή�	K.Naono	04.01.30
	//	DRAUGHTING_DRAWING_REVISION�̃C���X�^���XID��ԋp����
	int	GetDwgRevID() ;
//	ADD(E)	Ver3.0�Ή�	K.Naono	04.01.30

private:
	BOOL MappingStruct(Sheet_Struct IN_Struct,CUIntArray* IN_ChildrenID);
	//////////////////////////////////////
	//��`�e�[�u���Ǘ��I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFTableManagerC* m_TableManager;
	//////////////////////////////////////
	//�C���X�^���XID
	//////////////////////////////////////
	int m_ID;
	//////////////////////////////////////
	//�C���X�^���X�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_InstC* m_inst[11];
	SXFD_InstC* m_elem_inst;
	//////////////////////////////////////
	//�����^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_RealC* m_real1;
	SXFD_RealC* m_real2;
	SXFD_RealC* m_real3;
	SXFD_RealC* m_real4;
	SXFD_RealC* m_real5;
	SXFD_RealC* m_real6;
	//////////////////////////////////////
	//������^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_StrC* m_str1;
	SXFD_StrC* m_str2;
	SXFD_StrC* m_str3;
	SXFD_StrC* m_str4;
	SXFD_StrC* m_str5;
	SXFD_StrC* m_str6;
	SXFD_StrC* m_str7;
	SXFD_StrC* m_str8;
	SXFD_StrC* m_str9;
	SXFD_StrC* m_str10;
	SXFD_StrC* m_str11;
	SXFD_StrC* m_str12;
	SXFD_StrC* m_str13;
	//////////////////////////////////////
	//�W���̌^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_AggrC* m_aggr1;
	SXFD_AggrC* m_aggr2;
	SXFD_AggrC* m_aggr3;
	SXFD_AggrC* m_aggr4;

//	ADD(S)	Ver3.0�Ή�	K.Naono	04.01.30
	//	DRAUGHTING_DRAWING_REVISION�̃C���X�^���XID
	int	m_nDwgRevID ;
//	ADD(E)	Ver3.0�Ή�	K.Naono	04.01.30
};

#endif // !defined(AFX_SXFSHEETMAPPINGC_H__16DFD9E5_1172_11D4_A76E_00000EB03267__INCLUDED_)
