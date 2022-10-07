/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_ColorBaseC.h						作成日：2000.04.17

	１．クラス概要
		シンボル、文字、ハッチングフィーチャのcolorパラメタを管理するクラス
		（CurveStyle以外）

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/

#ifndef _SXFMapF_ColorBaseC_CLASS_
#define _SXFMapF_ColorBaseC_CLASS_

#include "SXFMapF_LayerBaseC.h"

class SXFMapF_ColorBaseC : public SXFMapF_LayerBaseC  {
public :
//
//	<デフォルトコンストラクタ>
	SXFMapF_ColorBaseC( );

//	<デストラクタ>
	virtual	~SXFMapF_ColorBaseC( );

//	<フィーチャ構造体の取得>
//  BOOL GetStructData( void* INOUT_Struct );

public:
	int	m_color ;				//色コード

};
#endif
