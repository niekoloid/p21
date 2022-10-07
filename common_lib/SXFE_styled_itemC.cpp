/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_styled_itemC.cpp								作成日：2000.4.18

	１．クラス概要
	エンティティデータ管理

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/

#include "stdafx.h"
#include "SXFD_StrC.h"
#include "SXFD_AggrC.h"
#include "SXFD_TypeC.h"
#include "SXFE_styled_itemC.h"
#include "SXFPart21FileC.h"
#include "SXF_EXT.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_styled_itemC.cpp								作成日：2000.4.18

	１．機能概要
		コンストラクタ

	２．インターフェース
	void	SXFE_styled_itemC(SXFD_StrC *str,SXFD_AggrC *aggr,SXFD_InstC *inst,CStringList *slist)
	引数:	型				引数名			内容
			SXFD_StrC 		*str				ｴﾝﾃｨﾃｨﾃﾞｰﾀ
			SXFD_AggrC 		*aggr				ｴﾝﾃｨﾃｨﾃﾞｰﾀ
			SXFD_InstC 		*inst				ｴﾝﾃｨﾃｨﾃﾞｰﾀ
			CStringList 	*slist				ｴﾝﾃｨﾃｨﾃﾞｰﾀ

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/
////複合曲線
SXFE_styled_itemC::SXFE_styled_itemC(SXFD_StrC *str,SXFD_AggrC *aggr,SXFD_InstC *inst,CStringList *slist){

	m_Flg = 1;
	type_flg = 1;
	m_InstanceID = gl_InstanceID;
	gl_InstanceID += 10;

	m_Entity = DEF_STYLED_ITEM;

	m_Data.AddTail(str);
	m_Data.AddTail(aggr);
	m_Data.AddTail(inst);

	m_StrList = slist;

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_styled_itemC.cpp								作成日：2000.4.18

	１．機能概要
		コンストラクタ

	２．インターフェース
	void	SXFE_styled_itemC(SXFD_AggrC *aggr1,
							  SXFD_AggrC *aggrs,
							  SXFD_InstC *inst1,
							  SXFD_AggrC* aggr2)
	引数:	型				引数名			内容
			SXFD_AggrC 		*aggr1				ｴﾝﾃｨﾃｨﾃﾞｰﾀ
			SXFD_AggrC 		*aggrs				ｴﾝﾃｨﾃｨﾃﾞｰﾀ
			SXFD_InstC 		*inst1				ｴﾝﾃｨﾃｨﾃﾞｰﾀ
			SXFD_AggrC* 	aggr2				ｴﾝﾃｨﾃｨﾃﾞｰﾀ

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/
SXFE_styled_itemC::SXFE_styled_itemC(SXFD_AggrC *aggr1,SXFD_AggrC *aggrs,SXFD_InstC *inst1,SXFD_AggrC* aggr2){

	m_Flg = 1;
	type_flg = 2;
	m_InstanceID = gl_InstanceID;
	gl_InstanceID += 10;

	m_Entity = DEF_STYLED_ITEM;

	m_Data.AddTail(aggr1);
	m_Data.AddTail(aggrs);
	m_Data.AddTail(inst1);
	m_Data.AddTail(aggr2);

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_styled_itemC.cpp								作成日：2000.4.18

	１．機能概要
		コンストラクタ

	２．インターフェース
	void	SXFE_styled_itemC(SXFD_AggrC *aggr1,SXFD_AggrC *aggrs,SXFD_InstC *inst1)
	引数:	型				引数名			内容
			SXFD_AggrC 		*aggr1				ｴﾝﾃｨﾃｨﾃﾞｰﾀ
			SXFD_AggrC 		*aggrs				ｴﾝﾃｨﾃｨﾃﾞｰﾀ
			SXFD_InstC		*inst1				ｴﾝﾃｨﾃｨﾃﾞｰﾀ

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/
SXFE_styled_itemC::SXFE_styled_itemC(SXFD_AggrC *aggr1,SXFD_AggrC *aggrs,SXFD_InstC *inst1){

	m_Flg = 1;
	type_flg = 3;
	m_InstanceID = gl_InstanceID;
	gl_InstanceID += 10;

	m_Entity = DEF_STYLED_ITEM;

	m_Data.AddTail(aggr1);
	m_Data.AddTail(aggrs);
	m_Data.AddTail(inst1);

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_styled_itemC.cpp								作成日：2000.4.18

	１．機能概要
		コンストラクタ

	２．インターフェース
	void	SXFE_styled_itemC(SXFD_StrC* str1,SXFD_AggrC* aggr1,SXFD_InstC *inst1)
	引数:	型				引数名			内容
			SXFD_StrC* 		str1				ｴﾝﾃｨﾃｨﾃﾞｰﾀ
			SXFD_AggrC*	 	aggr1				ｴﾝﾃｨﾃｨﾃﾞｰﾀ
			SXFD_InstC 		*inst1				ｴﾝﾃｨﾃｨﾃﾞｰﾀ

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/
SXFE_styled_itemC::SXFE_styled_itemC(SXFD_StrC* str1,SXFD_AggrC* aggr1,SXFD_InstC *inst1){

	m_Flg = 1;
	type_flg = 4;
	m_InstanceID = gl_InstanceID;
	gl_InstanceID += 10;

	m_Entity = DEF_STYLED_ITEM;

	m_Data.AddTail(str1);
	m_Data.AddTail(aggr1);
	m_Data.AddTail(inst1);

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_styled_itemC.cpp								作成日：2000.4.18

	１．機能概要
		インスタンス出力

	２．インターフェース
	void	SXFE_styled_itemC::WriteP21(SXFPart21FileC *IN_file)
	引数:	型				引数名			内容
			SXFPart21FileC 	*IN_file	ファイルオブジェクトのアドレス

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/
void	SXFE_styled_itemC::WriteP21(SXFPart21FileC *IN_file) {

	SXFD_AggrC *aggr1,*aggr2;

	if(m_Flg){
		for( POSITION pos = m_Data.GetTailPosition(); pos != NULL;) {
			((SXFInstanceC*)m_Data.GetPrev(pos))->WriteP21(IN_file);
		}
		if (type_flg == 4){
			CString insID;
			insID.Format("#%d=%s(",m_InstanceID,m_Entity);
			IN_file->WriteString(insID);
			pos = m_Data.GetHeadPosition();
			((SXFInstanceC*)m_Data.GetNext(pos))->WriteAttr(IN_file);
			IN_file->WriteString(",");
			((SXFInstanceC*)m_Data.GetNext(pos))->WriteAttr(IN_file);
			IN_file->WriteString(",");
			((SXFInstanceC*)m_Data.GetNext(pos))->WriteAttr(IN_file);
			IN_file->WriteString(");\n");

		}
		else{
			CString insID;
			insID.Format("#%d=(",m_InstanceID);
			IN_file->WriteString(insID);
			IN_file->WriteString("\n");

			if(type_flg == 1){
				for(pos = m_StrList->GetHeadPosition();pos != NULL;){
					IN_file->WriteString(m_StrList->GetNext(pos));
					IN_file->WriteString("()\n");
				}
				pos = m_Data.GetHeadPosition();
				IN_file->WriteString("REPRESENTATION_ITEM(") ;
				((SXFInstanceC*)m_Data.GetNext(pos))->WriteAttr(IN_file);
				IN_file->WriteString(")\n");
				IN_file->WriteString("STYLED_ITEM(");
				((SXFInstanceC*)m_Data.GetNext(pos))->WriteAttr(IN_file);
				IN_file->WriteString(",");
				((SXFInstanceC*)m_Data.GetNext(pos))->WriteAttr(IN_file);
				IN_file->WriteString(")\n");
				IN_file->WriteString(");\n");
				delete m_StrList;
			}
			else if(type_flg == 2){

				aggr1 = (SXFD_AggrC*)(m_Data.GetAt(m_Data.FindIndex(0)));
				aggr2 = (SXFD_AggrC*)(m_Data.GetAt(m_Data.FindIndex(3)));
				
				for(pos = (aggr1->GetData()).GetHeadPosition();pos != NULL;){
					((SXFD_TypeC*)(aggr1->GetData()).GetNext(pos))->WriteAttr(IN_file);
					IN_file->WriteString("\n");
				}
				IN_file->WriteString("STYLED_ITEM(");
				((SXFInstanceC*)m_Data.GetAt(m_Data.FindIndex(1)))->WriteAttr(IN_file);
				IN_file->WriteString(",");
				((SXFInstanceC*)m_Data.GetAt(m_Data.FindIndex(2)))->WriteAttr(IN_file);
				IN_file->WriteString(")\n");
				for(pos = (aggr2->GetData()).GetHeadPosition();pos != NULL;){
					((SXFD_TypeC*)(aggr2->GetData()).GetNext(pos))->WriteAttr(IN_file);
					IN_file->WriteString("\n");
				}
				IN_file->WriteString(");\n");
			}
			else if (type_flg == 3){

				aggr1 = (SXFD_AggrC*)(m_Data.GetAt(m_Data.FindIndex(0)));
				
				for(pos = (aggr1->GetData()).GetHeadPosition();pos != NULL;){
					((SXFD_TypeC*)(aggr1->GetData()).GetNext(pos))->WriteAttr(IN_file);
					IN_file->WriteString("\n");
				}
				IN_file->WriteString("STYLED_ITEM(");
				((SXFInstanceC*)m_Data.GetAt(m_Data.FindIndex(1)))->WriteAttr(IN_file);
				IN_file->WriteString(",");
				((SXFInstanceC*)m_Data.GetAt(m_Data.FindIndex(2)))->WriteAttr(IN_file);
				IN_file->WriteString(")\n");
				IN_file->WriteString(");\n");
			}
		}
		m_Flg = 0;
	}
}
