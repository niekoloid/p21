/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_AggrC.cpp						作成日：2001.06.12

	１．クラス概要
		集合体型の要素を保持し出力するクラス

	２．履歴
		履歴番号	日付		担当者		概要
		作成		2001.06.12	佐々木(FQS)	なし。
**/
#include "stdafx.h"
#include "SXFD_AggrC.h"
#include "SXFPart21FileC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_AggrC.cpp						作成日：2001.06.12

	１．機能概要
		デストラクタ
		
	２．インターフェイス
	~SXFD_AggrC( )
	引数:	型								引数名				内容
			なし
	復帰値	なし
		

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2001.06.12	佐々木(FQS)	なし。
**/
SXFD_AggrC::~SXFD_AggrC( ) {
	CObject	*obj ;
	for( POSITION pos = m_Data.GetHeadPosition(); pos != NULL; ) {
		obj = m_Data.GetNext( pos ) ;
		if(obj) {
			if (CheckDeleteable(obj)) {
				AddDeleted(obj);
				delete obj ;
			}
			else {
				CObject *o = obj;
			}
		}
	}
	m_Data.RemoveAll() ;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_AggrC.cpp						作成日：2001.06.12

	１．機能概要
		要素を追加する
		
	２．インターフェイス
	void AddElem( CObject* obj )
	引数:	型								引数名				内容
			CObject							IN_obj			要素			
	復帰値	なし
		

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2001.06.12	佐々木(FQS)	なし。
**/
void	SXFD_AggrC::AddElem( CObject* IN_obj ) {
	m_Data.AddTail(IN_obj) ;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_AggrC.cpp						作成日：2001.06.12

	１．機能概要
		メンバm_Dataを削除する
		
	２．インターフェイス
	void　RemoveTail
	引数:	型								引数名				内容
			なし					
	復帰値	なし
		

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2001.06.12	佐々木(FQS)	なし。
**/
void	SXFD_AggrC::RemoveTail( ) {
	m_Data.RemoveTail() ;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_AggrC.cpp						作成日：2001.06.12

	１．機能概要
		メンバm_Dataを削除する
		
	２．インターフェイス
	void　Remove
	引数:	型								引数名				内容
			なし					
	復帰値	なし
		

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2001.06.12	佐々木(FQS)	なし。
**/
void SXFD_AggrC::Remove( ) {
	m_Data.RemoveAll() ;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_AggrC.cpp						作成日：2001.06.12

	１．機能概要
		メンバm_Dataを返却
		
	２．インターフェイス
	void　GetData
	引数:	型								引数名				内容
			なし					
	復帰値	m_Data
		

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2001.06.12	佐々木(FQS)	なし。
**/
CObList& SXFD_AggrC::GetData(){
	return m_Data;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_AggrC.cpp						作成日：2001.06.12

	１．機能概要
		要素を出力
		
	２．インターフェイス
	void WriteAttr(SXFPart21FileC *IN_file)
	引数:	型								引数名				内容
			SXFPart21FileC*					IN_file				SXFPart21FileCへのポインタ
	復帰値	なし
		

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2001.06.12	佐々木(FQS)	なし。
**/
void SXFD_AggrC::WriteAttr(SXFPart21FileC *IN_file){
	int flg = 0;
	for( POSITION pos = m_Data.GetHeadPosition(); pos != NULL;) {

		if(flg == 0){
			IN_file->WriteString("(");
			flg =1;
		}
		else{
			IN_file->WriteString(",");
		}

		((SXFInstanceC*)m_Data.GetNext(pos))->WriteAttr(IN_file);

	}
	IN_file->WriteString(")");
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_AggrC.cpp						作成日：2001.06.12

	１．機能概要
		インスタンスを出力
		
	２．インターフェイス
	void WriteP21(SXFPart21FileC *IN_file)
	引数:	型								引数名				内容
			SXFPart21FileC*					IN_file				SXFPart21FileCへのポインタ
	復帰値	なし
		

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2001.06.12	佐々木(FQS)	なし。
**/
void SXFD_AggrC::WriteP21(SXFPart21FileC *IN_file){

	for( POSITION pos = m_Data.GetTailPosition(); pos != NULL;) {

		((SXFInstanceC*)m_Data.GetPrev(pos))->WriteP21(IN_file);

	}

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_AggrC.cpp						作成日：2001.06.12

	１．機能概要
		要素が空かどうか確かめる
		
	２．インターフェイス
	BOOL Is_Empty
	引数:	型								引数名				内容
			なし。
	復帰値	空：TRUE
			要素あり：FALSE
		

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2001.06.12	佐々木(FQS)	なし。
**/
BOOL SXFD_AggrC::Is_Empty(){
	//空の場合
	if (m_Data.IsEmpty())
		return TRUE;
	else
		return FALSE;
}

