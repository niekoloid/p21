/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_EnumC.cpp						作成日：2000.04.12

	１．クラス概要
		列挙型の要素を保持し出力するクラス

	２．履歴
		履歴番号	日付		担当者		概要
		作成		2000.04.12	宮園(FQS)	なし。
**/
#include "stdafx.h"
#include "SXFD_EnumC.h"
#include "SXFPart21FileC.h"

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
	SXFD_EnumC( )
	引数:	型				引数名				内容
			char*			data			char型データ	
	復帰値	なし
		

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2000.04.12	宮園(FQS)	なし。
**/
SXFD_EnumC::SXFD_EnumC(char *data) {
	m_Data = data ;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_EnumC.cpp						作成日：2000.04.12

	１．機能概要
		データのセット
		
	２．インターフェイス
	SXFD_EnumC( )
	引数:	型				引数名				内容
			char*			data				char型データ
	復帰値	なし
		
	３．履歴
		履歴番号	日付		担当者		概要
		作成		2000.04.12	宮園(FQS)	なし。
**/
void	SXFD_EnumC::SetData( char* data ) {
	m_Data = data ;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_BoolC.cpp						作成日：2000.04.12

	１．機能概要
		データを取得
		
	２．インターフェイス
	SXFD_EnumC()
	引数:	型				引数名				内容
			なし				
	復帰値	要素
		
	３．履歴
		履歴番号	日付		担当者		概要
		作成		2000.04.12	宮園(FQS)	なし。
**/
LPCTSTR	SXFD_EnumC::GetData( ) {
	return (LPCTSTR)m_Data ;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_BoolC.cpp						作成日：2000.04.12

	１．機能概要
		要素を出力

	２．インターフェイス
	SXFD_EnumC( )
	引数:	型					引数名				内容
			SXFPart21FileC*		IN_file				ﾌｧｲﾙｵﾌﾞｼﾞｪｸﾄ
	復帰値	なし
		
	３．履歴
		履歴番号	日付		担当者		概要
		作成		2000.04.12	宮園(FQS)	なし。
**/
void	SXFD_EnumC::WriteAttr(SXFPart21FileC *IN_file){
	CString data_str;
	data_str.Format(".%s.",m_Data);
	IN_file->WriteString(data_str);
}
