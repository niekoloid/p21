/**
	All Rights Reserved,(c) JACIC 2001
	SXFCurveDimMappingC.h								�쐬���F2007.1.29

	�P�D�N���X�T�v
	�ʒ����@��Mapping

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2007.1.29			����				�Ȃ��B

**/

#if !defined(AFX_SXFCURVEDIMMAPPINGC_H__1F88C680_149F_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFCURVEDIMMAPPINGC_H__1F88C680_149F_11D4_A76E_00000EB03267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afx.h>
#include "SXFStruct.h"

class SXFTableManagerC;
class SXFPart21FileC;
class SXFArcMappingC;
class SXFProjMappingC;
class SXFTermSymbolMappingC;
class SXFTextStringMappingC;
class SXFD_AggrC;
class SXFD_InstC;
class SXFD_StrC;
class SXFD_TypeC;
class SXFD_BoolC;

class SXFCurveDimMappingC  
{
public:
	void GetID(int &OUT_ID1,int &OUT_ID2);
	BOOL WriteAP202(SXFPart21FileC* IN_File);
	int MappingStruct(CurveDim_Struct IN_Struct,int IN_AssemType);
	SXFCurveDimMappingC();
	SXFCurveDimMappingC(SXFTableManagerC* IN_TableManager);
	virtual ~SXFCurveDimMappingC();
private:
	//////////////////////////////////////
	//�C���X�^���XID
	//////////////////////////////////////
	int m_ID1;
	int m_ID2;
	//////////////////////////////////////
	//���@���t���O
	//���@���̐��@�l�F�P�A�����v�f�F�O
	//////////////////////////////////////
	int m_DimFlag;
	//////////////////////////////////////
	//�C���X�^���X�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_InstC* m_term2_inst;
	SXFD_InstC* m_term1_inst;
	SXFD_InstC* m_text_inst;
	SXFD_InstC* m_inst[6];
	SXFD_InstC* m_ins_proj1;
	SXFD_InstC* m_ins_proj2;
	SXFD_InstC* m_ins_line;
	SXFD_InstC* m_ins_text;
	//////////////////////////////////////
	//�W���̌^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_AggrC* m_aggr1;
	SXFD_AggrC* m_aggr2;
	SXFD_AggrC* m_aggr3;
	SXFD_AggrC* m_aggr4;
	SXFD_AggrC* m_aggr5;
	//////////////////////////////////////
	//Bool�^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_BoolC* m_bool1;
	//////////////////////////////////////
	//TYPE�^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_TypeC* m_type1;
	//////////////////////////////////////
	//������^�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFD_StrC* m_str1;
	SXFD_StrC* m_str2;
	SXFD_StrC* m_str3;
	SXFD_StrC* m_str4;
	SXFD_StrC* m_str5;
	SXFD_StrC* m_str6;
	//////////////////////////////////////
	//�����v�f�t�B�[�`��Mapping�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFTextStringMappingC* m_TextStringMapping;
	//////////////////////////////////////
	//���Mapping�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFTermSymbolMappingC* m_TermSymbolMapping1;
	SXFTermSymbolMappingC* m_TermSymbolMapping2;
	//////////////////////////////////////
	//�⏕��Mapping�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFProjMappingC* m_ProjMapping1;
	SXFProjMappingC* m_ProjMapping2;
	//////////////////////////////////////
	//�~�ʃt�B�[�`��Mapping�I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFArcMappingC* m_ArcMapping;
	//////////////////////////////////////
	//��`�e�[�u���Ǘ��I�u�W�F�N�g�̃A�h���X
	//////////////////////////////////////
	SXFTableManagerC* m_TableManager;
	//////////////////////////////////////
	//���DIRECTION�v�Z�p���\�b�h
	//////////////////////////////////////
	int CalcArrowDir(CurveDim_Struct IN_Struct,double& OUT_Arrow1_x,double& OUT_Arrow1_y,double& OUT_Arrow2_x,double& OUT_Arrow2_y);
	void CalcAngle(double IN_x1,double IN_y1,double IN_x2,double IN_y2,double& OUT_angle);
	void CalcAngleSub(double IN_angle1,double IN_angle2,double& OUT_angle);
	void CalcAngleSub2(double IN_angle1,double IN_angle2,double& OUT_angle);

/*	==>	Added by S.Kakizawa(KLS) on 2006/03/14	*/
	BOOL	AngleIsInside( const double& dbAngleStart, const double& dbAngleEnd, const double& dbAngleCheck, const double& dbEps ) const;
/*	<==	Added by S.Kakizawa(KLS) on 2006/03/14	*/
};

#endif // !defined(AFX_SXFCURVEDIMMAPPINGC_H__1F88C680_149F_11D4_A76E_00000EB03267__INCLUDED_)
