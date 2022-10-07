/**
	All Rights Reserved,(c) JACIC 2001
	SXFTermSymbolMappingC.h								�쐬���F2000.4.17

	�P�D�N���X�T�v
	����Mapping

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.17			�{��(FQS)			�Ȃ��B

**/

#if !defined(AFX_SXFTERMSYMBOLMAPPINGC_H__1A5803C2_13AE_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFTERMSYMBOLMAPPINGC_H__1A5803C2_13AE_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFStruct.h"

class SXFTableManagerC;
class SXFPart21FileC;
class SXFD_InstC;
class SXFD_RealC;
class SXFD_StrC;
class SXFD_AggrC;
class SXFD_EnumC;

class SXFTermSymbolMappingC  
{
public:
	int GetID();
	void SetTermID(int assignID);
	void GetTermID(int &OUT_assignID);
	BOOL WriteAP202(SXFPart21FileC* IN_File);
	BOOL MappingStructDim(TermSymbol_Struct IN_Struct);
	SXFTermSymbolMappingC();
	SXFTermSymbolMappingC(SXFTableManagerC* IN_TableManager,int IN_Flag,int IN_DimFlag);
	virtual ~SXFTermSymbolMappingC();

private:
	//////////////////////////////////////
	//�C���X�^���XID
	//////////////////////////////////////
	int m_ID;
	//////////////////////////////////////
	//PRESENTATION_STYLED_ASSIGNMENT�̃C���X�^���XID
	//////////////////////////////////////
	int m_assignID;
	//////////////////////////////////////
	//��`�e�[�u���Ǘ��I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFTableManagerC* m_TableManager;
	//////////////////////////////////////
	//�t���O
	//�P�F	�O�F
	//////////////////////////////////////
	int m_Flag;
	//////////////////////////////////////
	//���@���t���O
	//���@���̐��@�l�F�P�A�����v�f�F�O
	//////////////////////////////////////
	int m_DimFlag;
	//////////////////////////////////////
	//CStringList�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	CStringList* m_slist;
	//////////////////////////////////////
	//�C���X�^���X�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_InstC* m_inst[10];
	SXFD_InstC* m_ins1;
	SXFD_InstC* m_ins2;
	SXFD_InstC* m_ins3;
	//////////////////////////////////////
	//�W���̌^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_AggrC* m_aggr1;
	SXFD_AggrC* m_aggr2;
	SXFD_AggrC* m_aggr3;
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
	//////////////////////////////////////
	//�񋓌^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_EnumC* m_enum1;
	//////////////////////////////////////
	//�����^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_RealC* m_real1;
	SXFD_RealC* m_real2;
	SXFD_RealC* m_real3;
	SXFD_RealC* m_real4;
	SXFD_RealC* m_real5;
	SXFD_RealC* m_real6;
};

#endif // !defined(AFX_SXFTERMSYMBOLMAPPINGC_H__1A5803C2_13AE_11D4_A76E_00000EB03267__INCLUDED_)
