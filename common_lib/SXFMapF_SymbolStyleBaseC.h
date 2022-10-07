/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_SymbolStyleBaseC.h						作成日：2000.04.17

	１．クラス概要
		フィーチャのSymbolStyleを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/

#ifndef _SXFMapF_SymbolStyleBaseC_CLASS_
#define _SXFMapF_SymbolStyleBaseC_CLASS_

#include "SXFMapF_LayerBaseC.h"

class SXFMapF_SymbolStyleBaseC : public SXFMapF_LayerBaseC  {
public :
//
//	<デフォルトコンストラクタ>
	SXFMapF_SymbolStyleBaseC( );

//	<デストラクタ>
	virtual	~SXFMapF_SymbolStyleBaseC( );

//	<フィーチャ構造体の取得>
//  BOOL GetStructData( void* INOUT_Struct );

public:
	int	m_color ;				//色コード

};
#endif
