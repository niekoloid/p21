/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_InstC.cpp						作成日：2001.06.12

	１．クラス概要
		インスタンスを保持し出力するクラス

	２．履歴
		履歴番号	日付		担当者		概要
		作成		2001.06.12	佐々木(FQS)	なし。
**/
#include "stdafx.h"
#include "SXFD_InstC.h"
#include "SXFPart21FileC.h"
#include "SXF_EXT.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CMapPtrToPtr *SXFInstanceC::m_deleteMap = NULL;

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_InstC.cpp						作成日：2001.06.12

	１．機能概要
		コンストラクタ
		
	２．インターフェイス
	SXFD_InstC( )
	引数:	型				引数名				内容
			なし				
	復帰値	なし
		

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2001.06.12	佐々木(FQS)	なし。
**/
SXFD_InstC::SXFD_InstC() { 
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_InstC.cpp						作成日：2001.06.12

	１．機能概要
		コンストラクタ
		
	２．インターフェイス
	SXFD_InstC( )
	引数:	型				引数名				内容
			int				i					インスタンスＩＤ
	復帰値	なし
		

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2001.06.12	佐々木(FQS)	なし。
**/
SXFD_InstC::SXFD_InstC(int i) {
	m_InstanceID = i;
	m_Flg = 0;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_InstC.cpp						作成日：2001.06.12

	１．機能概要
		デストラクタ
		
	２．インターフェイス
		void	SXFD_InstC::~SXFD_InstC( )

	引数:	型				引数名				内容
			なし				

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2001.06.12	佐々木(FQS)	なし。
**/
SXFD_InstC::~SXFD_InstC( ) {
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
	SXFD_InstC.cpp						作成日：2001.06.12

	１．機能概要
		エンティティ名のセット
		
	２．インターフェイス
	SetEntity( CString ent )
	引数:	型				引数名				内容
			CString			ent					エンティティ名				
	復帰値	なし
		

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2001.06.12	佐々木(FQS)	なし。
**/
void	SXFD_InstC::SetEntity( CString ent ) {
	m_Entity = ent ;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_InstC.cpp						作成日：2001.06.12

	１．機能概要
		要素のセット
		
	２．インターフェイス
	AddAttr( CObject* data ) 
	引数:	型				引数名				内容
			CObject*		data				ｲﾝｽﾀﾝｽ
	復帰値	なし
		

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2001.06.12	佐々木(FQS)	なし。
**/
void	SXFD_InstC::AddAttr( CObject* data ) {
	m_Data.AddTail(data) ;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_InstC.cpp						作成日：2001.06.12

	１．機能概要
		インスタンスを出力
		
	２．インターフェイス
	WriteP21(SXFPart21FileC *IN_file)
	引数:	型					引数名				内容
			SXFPart21FileC*		IN_file			ﾌｧｲﾙｵﾌﾞｼﾞｪｸﾄ
	復帰値	なし
		

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2001.06.12	佐々木(FQS)	なし。
**/
void	SXFD_InstC::WriteP21(SXFPart21FileC *IN_file) {
	if(m_Flg){

		for( POSITION pos = m_Data.GetTailPosition(); pos != NULL;) {

			((SXFInstanceC*)m_Data.GetPrev(pos))->WriteP21(IN_file);

		}

		CString insID;
		insID.Format("#%d=%s",m_InstanceID,m_Entity);
		IN_file->WriteString(insID);

		int flg = 0;
		for(pos = m_Data.GetHeadPosition(); pos != NULL;) {
	
			if(flg == 0){
				IN_file->WriteString("(");
				flg =1;
			}
			else{
				IN_file->WriteString(",");
			}

			((SXFInstanceC*)m_Data.GetNext(pos))->WriteAttr(IN_file);

		}
		IN_file->WriteString(");\n");
		m_Flg = 0;

	}
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_InstC.cpp						作成日：2001.06.12

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
void	SXFD_InstC::WriteAttr(SXFPart21FileC *IN_file) {
	CString insID;
	insID.Format("#%d",m_InstanceID);
	IN_file->WriteString(insID);
}

/**
	All Rights Reserved,(c) JACIC 2001
	ファイル名				作成日：2001.06.23
	SXFD_InstC.cpp

	１．機能概要
	　　属性の型を取得

	２．インターフェイス
		SXFD_InstC::GetAttr( )

	引数：型		引数名		内容
		　なし　　　

	復帰値：入力された属性名があれば、属性の型を返却する。
			ない時は、NULLを返却する。

	３．履歴
	履歴番号		日付け		担当者		概要
	作成		2001.06.23	　　佐々木(FQS)	なし。
**/
CObList&	SXFD_InstC::GetAttr( ) {
	return m_Data ;
}

/**
	All Rights Reserved,(c) JACIC 2001
	ファイル名				作成日：2001.06.23
	SXFD_InstC.cpp

	１．機能概要
	　　IDを取得

	２．インターフェイス
		SXFD_InstC::GetInsID( )

	引数：型		引数名		内容
		　なし　　　

	復帰値：正常時：インスタンスID
			異常時：NULL

	３．履歴
	履歴番号		日付け		担当者		概要
	作成		2001.06.23	　　佐々木(FQS)	なし。
**/
int		SXFD_InstC::GetInsID( ) {
	return m_InstanceID ;
}

