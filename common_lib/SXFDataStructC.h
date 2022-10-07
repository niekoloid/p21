//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFDataStructC.h					  作成日：2001.05.25
//
//	１．クラス概要
//		Instance DataとHead Section Dataの構造体の定義
//		
//	２．履歴
//		履歴番号	日付け		   担当者	 概要
//		作成		2001.05.25	   佐々木		なし
//
//------------------------------------------------------------
#ifndef _SXFDATASTRUCTC_H_
#define _SXFDATASTRUCTC_H_

#include <afx.h>

struct HEADSECTION{
	CString FileName;
	int		Level;
	int		Mode;//0:ambilateral(mix)
				 //1:Feature
				 //2:AP202
	CString Author;  
	CString Organization;
	CString Version;
	CString OriginatingSystem;
	int		scadec_flg;				/* SCADECﾌｧｲﾙﾌﾗｸﾞ */
										//-1:SCADEC以外のﾌｧｲﾙ
										//1:SCADECﾌｧｲﾙ
};

#define SXF_IM_NULL			0

#define SXF_IM_COMMENT		1
#define SXF_IM_SECTIONMARK	2
#define SXF_IM_HEADSECTION	3

#define SXF_IM_AP_ENTITY	11
#define SXF_IM_AP_TABLE		12
#define SXF_IM_AP_ASSEMBLY	13
//	ADD(S)	チューニング対応	K.Naono	03.07.03
#define SXF_IM_AP_INVISIBILITY		14
#define SXF_IM_AP_PRESENTATION_SIZE	15
#define SXF_IM_AP_DRAUGHTING_TITLE	16
//	ADD(E)	チューニング対応	K.Naono	03.07.03
//	ADD(S)	Ver3.0対応	K.Naono	04.01.30
#define SXF_IM_AP_ATTRIBUTE	17
//	ADD(E)	Ver3.0対応	K.Naono	04.01.30

#define SXF_IM_FT_ENTITY	21
#define SXF_IM_FT_TABLE		22
#define SXF_IM_FT_ASSEMBLY	23


struct INSTANCEDATA{
	int		InstanceMode;//0  NULL,
						 //1  Comment
						 //2  SectionMark
						 //3  HeadSection
						 //11 AP202_Entity
						 //12 AP202_Table
						 //13 AP202_Assembly
						 //21 Feature_Entity
						 //22 Feature_Table
						 //23 Feature_Assembly
	int		InstanceID;
	CString EntityName;
	CString EntityData;
};

#endif

