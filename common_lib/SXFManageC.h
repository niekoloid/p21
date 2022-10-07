/**
	All Rights Reserved,(c) JACIC 2001
	SXFManageC.h								作成日：2001.05.29

	１．クラス概要
	変換管理クラス

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2001.05.29			佐々木(FQS)			なし。
	更新			2015.04.27			T.Matsushima		JPCERT/CC 指摘 脆弱性対応

**/
#if !defined(AFX_SXFMANAGEC_H__A3F5E7A2_049F_11D4_A76E_00000EB03267__INCLUDED_)
#define AFX_SXFMANAGEC_H__A3F5E7A2_049F_11D4_A76E_00000EB03267__INCLUDED_

#include "SXFComInfoC.h"	// ClassView によって追加されました。
#include "SXFRuleCheckC.h"	// ClassView によって追加されました。
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
//	int Read_next_feature(char* OUT_Type,LPVOID& OUT_Struct, int* OUT_EndFlag);						JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
	int Read_next_feature(char* OUT_Type,size_t TypeSize, LPVOID &OUT_Struct, int *OUT_EndFlag);	// バッファサイズを渡すように変更
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
	//外部定義ファイル(ハッチ)オブジェクト
	/////////////////////////////////////////////
	//ファイル入力オブジェクト
	SXFPart21FileReadC* m_ReadExHatchFile;
	//インスタンスIDオブジェクト
	SXFInstanceIDC* m_ExHatchFileInstanceIDManager;
	//定義テーブル管理オブジェクト
	SXFTableManagerC* m_ExHatchFileTableManager;
	//ReadAP202管理オブジェクト
	SXFReadAP202ManagerC* m_ExHatchFileReadAP202Manager;
	//共通情報管理オブジェクト
	SXFComInfoC m_ExHatchFileInfo;
	/////////////////////////////////////////////
	//外部定義ファイル(シンボル)オブジェクト
	/////////////////////////////////////////////
	//ファイル入力オブジェクト
	SXFPart21FileReadC* m_ReadExSymbolFile;
	//インスタンスIDオブジェクト
	SXFInstanceIDC* m_ExSymbolFileInstanceIDManager;
	//定義テーブル管理オブジェクト
	SXFTableManagerC* m_ExSymbolFileTableManager;
	//ReadAP202管理オブジェクト
	SXFReadAP202ManagerC* m_ExSymbolFileReadAP202Manager;
	//共通情報管理オブジェクト
	SXFComInfoC m_ExSymbolFileInfo;

	/////////////////////////////////////////////
	//インスタンスIDオブジェクト
	/////////////////////////////////////////////
	SXFInstanceIDC* m_InstanceIDManager;
	/////////////////////////////////////////////
	//アセンブリ型
	/////////////////////////////////////////////
	int m_Assem_type;
	/////////////////////////////////////////////
	//Write管理オブジェクト
	/////////////////////////////////////////////
	SXFWriteManagerC* m_WriteManager;
	/////////////////////////////////////////////
	//ルールチェックオブジェクト
	/////////////////////////////////////////////
	SXFRuleCheckC m_rulecheck;
	/////////////////////////////////////////////
	//定義テーブル管理オブジェクト
	/////////////////////////////////////////////
	SXFTableManagerC* m_TableManager;
	/////////////////////////////////////////////
	//ファイル出力オブジェクト
	/////////////////////////////////////////////
	SXFPart21FileWriteC* m_WriteFile;
	/////////////////////////////////////////////
	//ファイル入力オブジェクト
	/////////////////////////////////////////////
	SXFPart21FileReadC* m_ReadFile;
	/////////////////////////////////////////////
	//共通情報管理オブジェクト
	/////////////////////////////////////////////
	SXFComInfoC m_Info;
	/////////////////////////////////////////////
	//ReadAP202管理オブジェクト
	/////////////////////////////////////////////
	SXFReadAP202ManagerC* m_ReadAP202Manager;
	//
	int Param_Check(int IN_rw_flg,int IN_level, int IN_mode);

};

#endif // !defined(AFX_SXFMANAGEC_H__A3F5E7A2_049F_11D4_A76E_00000EB03267__INCLUDED_)
