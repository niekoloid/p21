/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_BoolC.cpp						作成日：2000.04.12

	１．クラス概要
		Bool型の要素を保持し出力するクラス

	２．履歴
		履歴番号	日付		担当者		概要
		作成		2000.04.12	宮園(FQS)	なし。
**/

#include "stdafx.h"
#include "SXFD_BoolC.h"
#include "SXFPart21FileC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_BoolC.cpp						作成日：2000.04.12

	１．機能概要
		コンストラクタ
		
	２．インターフェイス
	SXFD_BoolC(CString data)
	引数:	型				引数名				内容
			CString			data				BOOL型要素
	復帰値	なし
		

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2000.04.12	宮園(FQS)	なし。
**/
SXFD_BoolC::SXFD_BoolC(CString data) {
	s_Data = data ;
	if(s_Data == DEF_TRUE)	m_Data = TRUE;
	else					m_Data = FALSE;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_BoolC.cpp						作成日：2000.04.12

	１．機能概要
		コンストラクタ
		
	２．インターフェイス
	SXFD_BoolC( )
	引数:	型				引数名				内容
			Bool			data				
	復帰値	なし
		

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2000.04.12	宮園(FQS)	なし。
**/
SXFD_BoolC::SXFD_BoolC(BOOL data) {
	m_Data = data ;
	if(m_Data)	s_Data = DEF_TRUE;
	else		s_Data = DEF_FALSE;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_BoolC.cpp						作成日：2000.04.12

	１．機能概要
		データのセット
		
	２．インターフェイス
	SXFD_BoolC( BOOL data  )
	引数:	型				引数名				内容
			BOOL			data		BOOL型要素		
	復帰値	なし
		

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2000.04.12	宮園(FQS)	なし。
**/
void	SXFD_BoolC::SetData( BOOL data ) {
	m_Data = data ;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_BoolC.cpp						作成日：2000.04.12

	１．機能概要
		データを取得
		
	２．インターフェイス
	Bool SXFD_BoolC( )
	引数:	型				引数名				内容
			なし。
			
	復帰値	データ
		

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2000.04.12	宮園(FQS)	なし。
**/
BOOL	SXFD_BoolC::GetData( ) {
	return m_Data ;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_BoolC.cpp						作成日：2000.04.12

	１．機能概要
		要素を出力
		
	２．インターフェイス
	SXFD_BoolC( )
	引数:	型					引数名				内容
			SXFPart21FileC*		IN_file				ﾌｧｲﾙｵﾌﾞｼﾞｪｸﾄ
	
	復帰値	なし
		
	３．履歴
		履歴番号	日付		担当者		概要
		作成		2000.04.12	宮園(FQS)	なし。
**/
void	SXFD_BoolC::WriteAttr(SXFPart21FileC *IN_file){
	if(s_Data == DEF_UNKNOWN){
		IN_file->WriteString(DEF_D_U);
	}
	else if(s_Data == DEF_UNSPECIFIED){
		IN_file->WriteString(DEF_D_UNSPECIFIED);
	}
	else if (s_Data == DEF_NULL){
		IN_file->WriteString(DEF_D_NULL);
	}
	else if(m_Data){
		IN_file->WriteString(DEF_D_T);
	}
	else {
		IN_file->WriteString(DEF_D_F);
	}
}

