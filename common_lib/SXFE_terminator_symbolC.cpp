/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_terminator_symbolC.cpp								作成日：2000.4.18

	１．クラス概要
	エンティティデータ管理

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/

#include "stdafx.h"
#include "SXFD_EnumC.h"
#include "SXFD_StrC.h"
#include "SXFD_AggrC.h"
#include "SXFE_terminator_symbolC.h"
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
	SXFE_terminator_symbolC.cpp								作成日：2000.4.18

	１．機能概要
		コンストラクタ

	２．インターフェース
	void	SXFE_terminator_symbolC(SXFD_EnumC *enu,
									SXFD_StrC *str,
									SXFD_AggrC *aggr,
									SXFD_InstC *ins1,
									SXFD_InstC *ins2)
	引数:	型				引数名			内容
			SXFD_EnumC 		*enu				ｴﾝﾃｨﾃｨﾃﾞｰﾀ
			SXFD_StrC 		*str				ｴﾝﾃｨﾃｨﾃﾞｰﾀ
			SXFD_AggrC 		*aggr				ｴﾝﾃｨﾃｨﾃﾞｰﾀ
			SXFD_InstC 		*ins1				ｴﾝﾃｨﾃｨﾃﾞｰﾀ
			SXFD_InstC 		*ins2				ｴﾝﾃｨﾃｨﾃﾞｰﾀ

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/
SXFE_terminator_symbolC::SXFE_terminator_symbolC(SXFD_EnumC *enu,SXFD_StrC *str,SXFD_AggrC *aggr,SXFD_InstC *ins1,SXFD_InstC *ins2){

	m_Flg = 1;
	type_flag = 1;

	m_InstanceID = gl_InstanceID;
	gl_InstanceID += 10;

	m_Entity = DEF_TERMINATOR_SYMBOL;

	m_Data.AddTail(enu);
	m_Data.AddTail(str);
	m_Data.AddTail(aggr);
	m_Data.AddTail(ins1);
	m_Data.AddTail(ins2);

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_terminator_symbolC.cpp								作成日：2000.4.18

	１．機能概要
		コンストラクタ

	２．インターフェース
	void	SXFE_terminator_symbolC(SXFD_StrC *str,
									SXFD_AggrC *aggr,
									SXFD_InstC *ins1,
									SXFD_InstC *ins2)
	引数:	型				引数名			内容
			SXFD_StrC 		*str				ｴﾝﾃｨﾃｨﾃﾞｰﾀ
			SXFD_AggrC 		*aggr				ｴﾝﾃｨﾃｨﾃﾞｰﾀ
			SXFD_InstC 		*ins1				ｴﾝﾃｨﾃｨﾃﾞｰﾀ
			SXFD_InstC 		*ins2				ｴﾝﾃｨﾃｨﾃﾞｰﾀ

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/
SXFE_terminator_symbolC::SXFE_terminator_symbolC(SXFD_StrC *str,SXFD_AggrC *aggr,SXFD_InstC *ins1,SXFD_InstC *ins2){

	m_Flg = 1;
	type_flag = 2;

	m_InstanceID = gl_InstanceID;
	gl_InstanceID += 10;

	m_Entity = DEF_TERMINATOR_SYMBOL;

	m_Data.AddTail(str);
	m_Data.AddTail(aggr);
	m_Data.AddTail(ins1);
	m_Data.AddTail(ins2);

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_terminator_symbolC.cpp								作成日：2000.4.18

	１．機能概要
		インスタンス出力

	２．インターフェース
	void	WriteP21(SXFPart21FileC* IN_file)
	引数:	型				引数名			内容
			SXFPart21FileC* IN_file	ファイルオブジェクトのアドレス

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/
void	SXFE_terminator_symbolC::WriteP21(SXFPart21FileC* IN_file) {
	if(m_Flg){

		for( POSITION pos = m_Data.GetTailPosition(); pos != NULL;) {

			((SXFInstanceC*)m_Data.GetPrev(pos))->WriteP21(IN_file);

		}

		if (type_flag == 1){
			CString insID;
			insID.Format("#%d=(",m_InstanceID);
			IN_file->WriteString(insID);
			IN_file->WriteString("\n");

			pos = m_Data.GetHeadPosition();
			IN_file->WriteString("ANNOTATION_OCCURRENCE()\n");
			IN_file->WriteString("ANNOTATION_SYMBOL_OCCURRENCE()\n");
			IN_file->WriteString("DIMENSION_CURVE_TERMINATOR(");
			((SXFInstanceC*)m_Data.GetNext(pos))->WriteAttr(IN_file);
			IN_file->WriteString(")\n");
			IN_file->WriteString("DRAUGHTING_ANNOTATION_OCCURRENCE()\n");
			IN_file->WriteString("GEOMETRIC_REPRESENTATION_ITEM()\n");
			IN_file->WriteString("REPRESENTATION_ITEM(");
			((SXFInstanceC*)m_Data.GetNext(pos))->WriteAttr(IN_file);
			IN_file->WriteString(")\n");
			IN_file->WriteString("STYLED_ITEM(");
			((SXFInstanceC*)m_Data.GetNext(pos))->WriteAttr(IN_file);
			IN_file->WriteString(",");
			((SXFInstanceC*)m_Data.GetNext(pos))->WriteAttr(IN_file);
			IN_file->WriteString(")\n");
			IN_file->WriteString("TERMINATOR_SYMBOL(");
			((SXFInstanceC*)m_Data.GetNext(pos))->WriteAttr(IN_file);
			IN_file->WriteString(")\n);\n");
		}
		else if (type_flag == 2){
			CString insID;
			insID.Format("#%d=(",m_InstanceID);
			IN_file->WriteString(insID);
			IN_file->WriteString("\n");

			pos = m_Data.GetHeadPosition();
			IN_file->WriteString("ANNOTATION_OCCURRENCE()\n");
			IN_file->WriteString("ANNOTATION_SYMBOL_OCCURRENCE()\n");
			IN_file->WriteString("DRAUGHTING_ANNOTATION_OCCURRENCE()\n");
			IN_file->WriteString("GEOMETRIC_REPRESENTATION_ITEM()\n");
			IN_file->WriteString("LEADER_TERMINATOR()\n");
			IN_file->WriteString("REPRESENTATION_ITEM(");
			((SXFInstanceC*)m_Data.GetNext(pos))->WriteAttr(IN_file);
			IN_file->WriteString(")\n");
			IN_file->WriteString("STYLED_ITEM(");
			((SXFInstanceC*)m_Data.GetNext(pos))->WriteAttr(IN_file);
			IN_file->WriteString(",");
			((SXFInstanceC*)m_Data.GetNext(pos))->WriteAttr(IN_file);
			IN_file->WriteString(")\n");
			IN_file->WriteString("TERMINATOR_SYMBOL(");
			((SXFInstanceC*)m_Data.GetNext(pos))->WriteAttr(IN_file);
			IN_file->WriteString(")\n);\n");
		}
		m_Flg = 0;
	}
}
