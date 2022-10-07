/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_curve_dimensionC.cpp								作成日：2007.1.29

	１．クラス概要
	エンティティデータ管理

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2007.1.29			西木				なし。

**/
#include "stdafx.h"
#include "SXFE_curve_dimensionC.h"
#include "SXFD_StrC.h"
#include "SXFD_AggrC.h"
#include "SXF_EXT.h"
#include "SXFPart21FileC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_curve_dimensionC.cpp								作成日：2007.1.29

	１．機能概要
	コンストラクタ

	２．インターフェース
	void	SXFE_curve_dimensionC(SXFD_StrC *str,SXFD_AggrC *aggr)
	引数:	型								引数名				内容
			SXFD_StrC						*str			ｴﾝﾃｨﾃｨﾃﾞｰﾀ
			SXFD_StrC						*aggr			ｴﾝﾃｨﾃｨﾃﾞｰﾀ

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2007.1.29			西木				なし。

**/
SXFE_curve_dimensionC::SXFE_curve_dimensionC(SXFD_StrC *str,SXFD_AggrC *aggr){

	m_Flg = 1;

	m_InstanceID = gl_InstanceID;
	gl_InstanceID += 10;

	m_Entity = DEF_CURVE_DIMENSION;

	m_Data.AddTail(str);
	m_Data.AddTail(aggr);

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_curve_dimensionC.cpp								作成日：2007.1.29

	１．機能概要
		インスタンスを出力

	２．インターフェース
	void	WriteP21(SXFPart21FileC *IN_file)
	引数:	型								引数名				内容
			SXFPart21FileC					*IN_file		ファイルオブジェクトのアドレス

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2007.1.29			西木				なし。

**/
void	SXFE_curve_dimensionC::WriteP21(SXFPart21FileC *IN_file) {
	if(m_Flg){

		for( POSITION pos = m_Data.GetTailPosition(); pos != NULL;) {

			((SXFInstanceC*)m_Data.GetPrev(pos))->WriteP21(IN_file);

		}

		CString insID;
		insID.Format("#%d=(",m_InstanceID);
		IN_file->WriteString(insID);
		IN_file->WriteString("\n");

		IN_file->WriteString("CURVE_DIMENSION()\n");
		pos = m_Data.GetTailPosition();
		IN_file->WriteString("DIMENSION_CURVE_DIRECTED_CALLOUT()\n");
		IN_file->WriteString("DRAUGHTING_CALLOUT(");
		((SXFInstanceC*)m_Data.GetPrev(pos))->WriteAttr(IN_file);
		IN_file->WriteString(")\n");
		IN_file->WriteString("DRAUGHTING_ELEMENTS()\n");
		IN_file->WriteString("GEOMETRIC_REPRESENTATION_ITEM()\n");
		IN_file->WriteString("REPRESENTATION_ITEM(");
		((SXFInstanceC*)m_Data.GetPrev(pos))->WriteAttr(IN_file);
		IN_file->WriteString(")\n);\n");

		m_Flg = 0;

	}
}
