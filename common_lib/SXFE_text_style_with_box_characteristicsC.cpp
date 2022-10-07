/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_text_style_with_box_characteristicsC.cpp								作成日：2000.4.18

	１．クラス概要
	エンティティデータ管理

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/

#include "stdafx.h"
#include "SXFD_StrC.h"
#include "SXFD_TypeC.h"
#include "SxFD_RealC.h"
#include "SXFD_AggrC.h"
#include "SXFE_text_style_with_box_characteristicsC.h"
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
	SXFE_text_style_with_box_characteristicsC.cpp								作成日：2000.4.18

	１．機能概要
		コンストラクタ

	２．インターフェース
	void	SXFE_text_style_with_box_characteristicsC(SXFD_StrC *str,
													  SXFD_InstC *inst,
													  SXFD_AggrC *aggr,
													  SXFD_TypeC *type1)
	引数:	型				引数名			内容
			SXFD_StrC 		*str				ｴﾝﾃｨﾃｨﾃﾞｰﾀ
			SXFD_InstC 		*inst				ｴﾝﾃｨﾃｨﾃﾞｰﾀ
			SXFD_AggrC 		*aggr				ｴﾝﾃｨﾃｨﾃﾞｰﾀ
			SXFD_TypeC 		*type1				ｴﾝﾃｨﾃｨﾃﾞｰﾀ

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/
SXFE_text_style_with_box_characteristicsC
:: SXFE_text_style_with_box_characteristicsC(SXFD_StrC *str,SXFD_InstC *inst,SXFD_AggrC *aggr,SXFD_TypeC *type1){

	m_Flg = 1;

	m_InstanceID = gl_InstanceID;
	gl_InstanceID += 10;

	m_Entity = DEF_TEXT_STYLE_WITH_BOX_CHARACTERISTICS;

	m_Data.AddTail(str);
	m_Data.AddTail(inst);
	m_Data.AddTail(aggr);
	m_Data.AddTail(type1);

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_text_style_with_box_characteristicsC.cpp								作成日：2000.4.18

	１．機能概要
		インスタンスの出力

	２．インターフェース
	SXFE_text_style_with_box_characteristicsC::WriteP21(SXFPart21FileC *IN_file)
	引数:	型				引数名			内容
	SXFPart21FileC		 *IN_file	ﾌｧｲﾙｵﾌﾞｼﾞｪｸﾄ
  
	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/
void	SXFE_text_style_with_box_characteristicsC::WriteP21(SXFPart21FileC *IN_file) {
	if(m_Flg){

		for( POSITION pos = m_Data.GetTailPosition(); pos != NULL;) {

			((SXFInstanceC*)m_Data.GetPrev(pos))->WriteP21(IN_file);

		}

		pos = m_Data.GetHeadPosition();
		CString insID;
		insID.Format("#%d=(",m_InstanceID);
		IN_file->WriteString(insID);
		IN_file->WriteString("\n");
		IN_file->WriteString("TEXT_STYLE(") ;
		((SXFInstanceC*)m_Data.GetNext(pos))->WriteAttr(IN_file);
		IN_file->WriteString(",") ;
		((SXFInstanceC*)m_Data.GetNext(pos))->WriteAttr(IN_file);
		IN_file->WriteString(")\n") ;
		IN_file->WriteString("TEXT_STYLE_WITH_BOX_CHARACTERISTICS(") ;
		((SXFInstanceC*)m_Data.GetNext(pos))->WriteAttr(IN_file);
		IN_file->WriteString(")\n") ;
		IN_file->WriteString("TEXT_STYLE_WITH_SPACING(") ;
		((SXFInstanceC*)m_Data.GetNext(pos))->WriteAttr(IN_file);
		IN_file->WriteString(")\n") ;
		IN_file->WriteString(");\n") ;

		m_Flg = 0;

	}
}
