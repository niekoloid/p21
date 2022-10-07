/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_LayerBaseC.h						作成日：2000.04.17

	１．クラス概要
		フィーチャのレイヤを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/

#ifndef _SXFMapF_LayerBaseC_CLASS_
#define _SXFMapF_LayerBaseC_CLASS_

#include <afx.h>
#include <afxtempl.h>

class SXFMapF_LayerBaseC {
public :
//
//	<デフォルトコンストラクタ>
	SXFMapF_LayerBaseC( );
//	<デストラクタ>
	virtual	~SXFMapF_LayerBaseC( );

//	<フィーチャ構造体の取得>
//  BOOL GetStructData( void* INOUT_Struct );

public:

	int		m_layer ;			//レイヤコード

};
#endif
