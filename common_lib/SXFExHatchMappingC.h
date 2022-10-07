/**
	All Rights Reserved,(c) JACIC 2001
	SXFExHatchMappingC.cpp								�쐬���F2000.4.17

	�P�D�N���X�T�v
	�n�b�`���O(�O����`�j�t�B�[�`����Mapping

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.17			�{��(FQS)			�Ȃ��B
	�X�V			2001.09.18			K.Naono				�n�b�`���O��Q�Ή�

**/

#if !defined(AFX_SXFEXHATCHMAPPINGC_H__6ACDA8A0_15D4_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFEXHATCHMAPPINGC_H__6ACDA8A0_15D4_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFStruct.h"

class SXFTableManagerC;
class SXFPart21FileC;
class SXFD_InstC;
class SXFD_AggrC;
class SXFD_StrC;
class SXFD_TypeC;

class SXFExHatchMappingC  
{
public:
	int GetID();
	BOOL WriteAP202(SXFPart21FileC* IN_File);
	BOOL MappingStruct(Externally_Defined_Hatch_Struct* IN_Struct);
	SXFExHatchMappingC();
	SXFExHatchMappingC(
			SXFTableManagerC*	IN_TableManager,
			CUIntArray*			IN_AssemblyTable,
//	MOD(S)	�n�b�`���O��Q�Ή�	K.Naono		01.09.18
//			CUIntArray*			IN_PointTable);
			CArray<SXF_POINT,SXF_POINT&>*	IN_PointTable) ;
//	MOD(E)	�n�b�`���O��Q�Ή�	K.Naono		01.09.18
	virtual ~SXFExHatchMappingC();

private:
	//////////////////////////////////////
	//CARTESIAN_POINT(�n�b�`���O�����̓_�j�̃C���X�^���XID�̔z��
	//////////////////////////////////////
//	MOD(S)	�n�b�`���O��Q�Ή�	K.Naono		01.09.18
//	CUIntArray* m_PointTable;
	CArray<SXF_POINT,SXF_POINT&>*	m_PointTable;
	SXFD_InstC*						m_inst_point;
//	MOD(E)	�n�b�`���O��Q�Ή�	K.Naono		01.09.18
	//////////////////////////////////////
	//�����Ȑ���ID�̔z��
	//////////////////////////////////////
	CUIntArray* m_AssemblyTable;
	//////////////////////////////////////
	//TYPE�^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_TypeC* m_type1;
	SXFD_TypeC* m_type2;
	SXFD_TypeC* m_type3;
	SXFD_TypeC* m_type4;
	SXFD_TypeC* m_type5;
	SXFD_TypeC* m_type6;
	SXFD_TypeC* m_type7;
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
	//////////////////////////////////////
	//�C���X�^���X�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_InstC* m_inst1;
	SXFD_InstC* m_inst2;
	SXFD_InstC* m_inst3;
	SXFD_InstC* m_inst[5];
	//////////////////////////////////////
	//�W���̌^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_AggrC* m_aggr1;
	SXFD_AggrC* m_aggr2;
	SXFD_AggrC* m_aggr3;
	SXFD_AggrC* m_aggr4;
	SXFD_AggrC* m_aggr5;
	//////////////////////////////////////
	//�C���X�^���XID
	//////////////////////////////////////
	int m_ID;
	//////////////////////////////////////
	//��`�e�[�u���Ǘ��I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFTableManagerC* m_TableManager;
};

#endif // !defined(AFX_SXFEXHATCHMAPPINGC_H__6ACDA8A0_15D4_11D4_A76E_00000EB03267__INCLUDED_)
