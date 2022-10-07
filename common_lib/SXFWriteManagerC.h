//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFWriteManagerC.h					  作成日：2001.06.18
//
//	１．クラス概要
//      出力時のアセンブリ間の参照関係を管理する
//
//	２．履歴
//	    履歴番号    日付け         担当者    概要
//		作成		2001.06.18	  佐々木(FQS)
//		更新		2001.09.18	K.Naono		ハッチング障害対応
//
//------------------------------------------------------------
#ifndef _SXFWRITEMANAGERC_H_
#define _SXFWRITEMANAGERC_H_
#include <afx.h>
#include <afxtempl.h>

typedef struct sfigorgcheck{
	int		ID;
	int		type;
	CString	name;
	int		flag;
	int		locate_flag ;
	int		error;//定義がエラーのときは-1
//	ADD(S)	チューニング対応	K.Naono	03.07.08
	sfigorgcheck() {
		ID			= -1 ;
		type		= -1 ;
		flag		= -1 ;
		locate_flag	= -1 ;
		error		= -1 ;
	}
//	ADD(E)	チューニング対応	K.Naono	03.07.08
}SXFSFIGORGCHECK;

//	MOD(S)	チューニング対応	K.Naono	03.07.08
//typedef CArray<SXFSFIGORGCHECK,SXFSFIGORGCHECK&> SXFSFIGORGTABLE;
typedef CList<SXFSFIGORGCHECK*,SXFSFIGORGCHECK*&> SXFSFIGORGTABLE;
//	MOD(E)	チューニング対応	K.Naono	03.07.08

#include "SXFWriteMappingManagerC.h"

class SXFPart21FileC;
class SXFTableManagerC;
class SXFWriteMappingManagerC;
class SXFComInfoC;
class SXFPart21FileWriteC;
class SXFInstanceIDC;

class SXFWriteManagerC	
{
public:
	BOOL SfigLocateCheck(LPCTSTR IN_Name);
	int ErrorAssembly();
	int GetAssemType();
	BOOL CloseAssembly();
	SXFWriteManagerC();
	SXFWriteManagerC(
			SXFPart21FileC* IN_File,
			SXFTableManagerC* IN_TableManager,
			SXFComInfoC* IN_ComInfo,
			SXFPart21FileWriteC* IN_WriteFile,
			SXFInstanceIDC* IN_InstanceIDManager);
	virtual ~SXFWriteManagerC();
	int RegisterAssembly(int IN_AssemblyType,LPVOID IN_Struct);
	int RegisterFeature(char* IN_FeatureType,LPVOID IN_Struct);
	BOOL CheckSameSfig( LPCTSTR IN_Name);
//	DEL(S)	チューニング対応	K.Naono	03.07.08
//	BOOL SfigNameCheck( LPCTSTR IN_Name);
//	DEL(E)	チューニング対応	K.Naono	03.07.08
	BOOL GetSfigFlg( LPCTSTR IN_Name,
					int* OUT_Type,
					int* OUT_LocFlg);
	BOOL SetLocFlg( LPCTSTR IN_Name);
	BOOL CheckHatchID( unsigned int IN_ID);
	CUIntArray m_InvisibilityCurveTable;
	BOOL MappingInvisibility();
	CUIntArray m_AssemblyTable;
	SXFSFIGORGTABLE m_SfigorgTable;

private:
	SXFPart21FileWriteC* m_WriteFile;
	SXFComInfoC* m_ComInfo;
	SXFInstanceIDC* m_InstanceIDManager;
	int m_SfigTableIndex;
	int m_SfigFlag;
	int m_AssemType;
	BOOL m_SheetAssemblyFlag;
	SXFPart21FileC* m_Part21File;
	//TABLEDATA:
	SXFWriteMappingManagerC* m_CurrentAssembly;
	SXFWriteMappingManagerC* m_CurrentChild;
	CUIntArray* m_ChildrenArray;
	BOOL m_FirstAssemblyFlag;
	SXFTableManagerC* m_TableManager;
//	MOD(S)	ハッチング障害対応	K.Naono		01.09.18
//	CUIntArray m_PointTable;
	CArray<SXF_POINT,SXF_POINT&>	m_PointTable ;
//	MOD(E)	ハッチング障害対応	K.Naono		01.09.18
	int m_CurveViewFlag;
	double m_PointX;
	double m_PointY;
	int m_PointN;
	BOOL						m_ErrorFlag;			/** ｱｾﾝﾌﾞﾘｴﾗｰﾌﾗｸﾞ **/
//	MOD(S)	チューニング対応	K.Naono	03.07.09
//	CUIntArray					m_CurveTable;			/** 複合曲線ﾃｰﾌﾞﾙ **/
	CList<int,int&>				m_CurveTable ;
//	MOD(E)	チューニング対応	K.Naono	03.07.09
	int							m_CurveFlag;			/** 複合曲線ﾌﾗｸﾞ **/
	int							m_AssemblyCode;			/** ｱｾﾝﾌﾞﾘｺｰﾄﾞ **/
//	ADD(S)	チューニング対応	K.Naono	03.07.08
	CMapStringToPtr				m_mapSfigOrg ;
//	ADD(E)	チューニング対応	K.Naono	03.07.08
};

#endif
