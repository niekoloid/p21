/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_CurveStyleBaseC.h						作成日：2000.04.17

	１．クラス概要
		フィーチャのCurveStyleを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/

#ifndef _SXFMapF_CurveStyleBaseC_CLASS_
#define _SXFMapF_CurveStyleBaseC_CLASS_

#include "SXFMapF_LayerBaseC.h"

class SXFMapF_CurveStyleBaseC : public SXFMapF_LayerBaseC  {
public :
//
//	<デフォルトコンストラクタ>
	SXFMapF_CurveStyleBaseC( );
//	<デストラクタ>
	virtual	~SXFMapF_CurveStyleBaseC( );
	
//	<フィーチャ構造体の取得>
//  BOOL GetStructData( void* INOUT_Struct );

public:
	int	m_color ;				//色コード
	int	m_type ;				//線種コード
	int	m_line_width ;			//線幅コード
};
#endif

