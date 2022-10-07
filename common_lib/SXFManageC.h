/**
	All Rights Reserved,(c) JACIC 2001
	SXFManageC.h								�쐬���F2001.05.29

	�P�D�N���X�T�v
	�ϊ��Ǘ��N���X

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.05.29			���X��(FQS)			�Ȃ��B
	�X�V			2015.04.27			T.Matsushima		JPCERT/CC �w�E �Ǝ㐫�Ή�

**/
#if !defined(AFX_SXFMANAGEC_H__A3F5E7A2_049F_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFMANAGEC_H__A3F5E7A2_049F_11D4_A76E_00000EB03267__INCLUDED_

#include "SXFComInfoC.h"	// ClassView �ɂ���Ēǉ�����܂����B
#include "SXFRuleCheckC.h"	// ClassView �ɂ���Ēǉ�����܂����B
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class SXFComInfoC;
class SXFPart21FileWriteC;
class SXFTableManagerC;
class SXFWriteManagerC;
class SXFInstanceIDC;
class SXFPart21FileReadC;
class SXFReadAP202ManagerC;
class SXFManageC  
{
public:
	void Delete_assembly(int assem_type,void*& f_struct);
	void Delete_feature(char* feature_name,void*& f_struct);
	int Usr2pre(int type,void* str,int *code);
	int Draw2model(char *sfig_name,double draw_coord_x,double draw_coord_y,double *model_coord_x,double *model_coord_y);
	int	Model2draw(char *sfig_name,double model_coord_x,double model_coord_y,double *draw_coord_x,double *draw_coord_y);
	int Setboundary(char* IN_Type,void* IN_Struct);
	int Read_expand_feature(char *OUT_Type,void* &OUT_Struct,int *OUT_EndFlag);
	int Expand_structure(char* IN_FeatureType,void* IN_Struct);
//	int Read_next_feature(char* OUT_Type,LPVOID& OUT_Struct, int* OUT_EndFlag);						JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
	int Read_next_feature(char* OUT_Type,size_t TypeSize, LPVOID &OUT_Struct, int *OUT_EndFlag);	// �o�b�t�@�T�C�Y��n���悤�ɕύX
	int Read_assembly_name(int IN_Type,LPVOID& OUT_Struct,int* OUT_EndFlag);
	int Read_table(int IN_TableType,LPVOID OUT_Struct,int* OUT_EndFlag);
	int Write_next_feature(char* IN_FeatureType,void* IN_Struct);
	int Write_assembly_name(int IN_Assem_type,void* IN_Struct);
	SXFComInfoC GetInfo();
	int Write_table(int IN_table_type,void* IN_str);
	int Close();
	int Open(char IN_file_name[257],int IN_rw_flg, double IN_tolerance1,double IN_tolerance2,double IN_divide, int IN_level, int IN_mode, char INOUT_author[257], char INOUT_org[257],char INOUT_translator_name[257],char OUT_version[257]);
	SXFManageC();
	virtual ~SXFManageC();

private:
	/////////////////////////////////////////////
	//�O����`�t�@�C��(�n�b�`)�I�u�W�F�N�g
	/////////////////////////////////////////////
	//�t�@�C�����̓I�u�W�F�N�g
	SXFPart21FileReadC* m_ReadExHatchFile;
	//�C���X�^���XID�I�u�W�F�N�g
	SXFInstanceIDC* m_ExHatchFileInstanceIDManager;
	//��`�e�[�u���Ǘ��I�u�W�F�N�g
	SXFTableManagerC* m_ExHatchFileTableManager;
	//ReadAP202�Ǘ��I�u�W�F�N�g
	SXFReadAP202ManagerC* m_ExHatchFileReadAP202Manager;
	//���ʏ��Ǘ��I�u�W�F�N�g
	SXFComInfoC m_ExHatchFileInfo;
	/////////////////////////////////////////////
	//�O����`�t�@�C��(�V���{��)�I�u�W�F�N�g
	/////////////////////////////////////////////
	//�t�@�C�����̓I�u�W�F�N�g
	SXFPart21FileReadC* m_ReadExSymbolFile;
	//�C���X�^���XID�I�u�W�F�N�g
	SXFInstanceIDC* m_ExSymbolFileInstanceIDManager;
	//��`�e�[�u���Ǘ��I�u�W�F�N�g
	SXFTableManagerC* m_ExSymbolFileTableManager;
	//ReadAP202�Ǘ��I�u�W�F�N�g
	SXFReadAP202ManagerC* m_ExSymbolFileReadAP202Manager;
	//���ʏ��Ǘ��I�u�W�F�N�g
	SXFComInfoC m_ExSymbolFileInfo;

	/////////////////////////////////////////////
	//�C���X�^���XID�I�u�W�F�N�g
	/////////////////////////////////////////////
	SXFInstanceIDC* m_InstanceIDManager;
	/////////////////////////////////////////////
	//�A�Z���u���^
	/////////////////////////////////////////////
	int m_Assem_type;
	/////////////////////////////////////////////
	//Write�Ǘ��I�u�W�F�N�g
	/////////////////////////////////////////////
	SXFWriteManagerC* m_WriteManager;
	/////////////////////////////////////////////
	//���[���`�F�b�N�I�u�W�F�N�g
	/////////////////////////////////////////////
	SXFRuleCheckC m_rulecheck;
	/////////////////////////////////////////////
	//��`�e�[�u���Ǘ��I�u�W�F�N�g
	/////////////////////////////////////////////
	SXFTableManagerC* m_TableManager;
	/////////////////////////////////////////////
	//�t�@�C���o�̓I�u�W�F�N�g
	/////////////////////////////////////////////
	SXFPart21FileWriteC* m_WriteFile;
	/////////////////////////////////////////////
	//�t�@�C�����̓I�u�W�F�N�g
	/////////////////////////////////////////////
	SXFPart21FileReadC* m_ReadFile;
	/////////////////////////////////////////////
	//���ʏ��Ǘ��I�u�W�F�N�g
	/////////////////////////////////////////////
	SXFComInfoC m_Info;
	/////////////////////////////////////////////
	//ReadAP202�Ǘ��I�u�W�F�N�g
	/////////////////////////////////////////////
	SXFReadAP202ManagerC* m_ReadAP202Manager;
	//
	int Param_Check(int IN_rw_flg,int IN_level, int IN_mode);

};

#endif // !defined(AFX_SXFMANAGEC_H__A3F5E7A2_049F_11D4_A76E_00000EB03267__INCLUDED_)
