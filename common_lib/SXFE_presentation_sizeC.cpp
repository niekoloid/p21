/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_presentation_sizeC.cpp								作成日：2000.4.18

	１．クラス概要
	エンティティデータ管理

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/

#include "stdafx.h"
#include "SXFE_presentation_sizeC.h"
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
	SXFE_presentation_sizeC.cpp								作成日：2000.4.18

	１．機能概要
		コンストラクタ
	
	２．インターフェース
	void	SXFE_presentation_sizeC(SXFD_InstC *inst1,SXFD_InstC *inst2)
	引数:	型				引数名			内容
			SXFD_InstC 		*inst1				ｴﾝﾃｨﾃｨﾃﾞｰﾀ
			SXFD_InstC 		*inst2				ｴﾝﾃｨﾃｨﾃﾞｰﾀ

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/
SXFE_presentation_sizeC
::SXFE_presentation_sizeC(SXFD_InstC *inst1,SXFD_InstC *inst2){

	m_Flg = 1;

	m_InstanceID = gl_InstanceID;
	gl_InstanceID += 10;

	m_Entity = DEF_PRESENTATION_SIZE;

	m_Data.AddTail(inst1);
	m_Data.AddTail(inst2);
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_presentation_sizeC.cpp								作成日：2000.4.18

	１．機能概要
		インスタンスの出力

	２．インターフェース
	void	SXFE_presentation_sizeC::WriteP21(SXFPart21FileC *IN_file)
	引数:	型				引数名			内容
			SXFPart21FileC 	*IN_file	ファイルオブジェクトのアドレス

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/
void	SXFE_presentation_sizeC::WriteP21(SXFPart21FileC *IN_file) {

	if(m_Flg){

		CString instID;
		instID.Format("#%d=%s",m_InstanceID,m_Entity);
		IN_file->WriteString(instID);
		int Flg = 0;
		for(POSITION pos = m_Data.GetHeadPosition(); pos != NULL;) {

			if(Flg == 0){
				IN_file->WriteString("(");
				Flg =1;
			}
			else{
				IN_file->WriteString(",");
			}

			((SXFInstanceC*)m_Data.GetNext(pos))->WriteAttr(IN_file);

		}
		IN_file->WriteString(");");
		IN_file->WriteString("\n");
		m_Flg = 0;
	}
}
