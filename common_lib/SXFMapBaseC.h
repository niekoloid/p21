/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapBaseC.h						作成日：2000.04.17

	１．クラス概要
		ルートエンティティIDを管理する

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#ifndef _SXFMAPBASEC_CLASS_
#define _SXFMAPBASEC_CLASS_

#include <afx.h>

#include "SXFMapInstIDC.h"
#include "SXFMapT_EnumC.h"

class SXFInstanceIDC;
class SXFComInfoC;

class SXFMapBaseC : public SXFMapInstIDC {
public :
//
//	<デフォルトコンストラクタ>
	SXFMapBaseC() ;

//	<コンストラクタ>
//	<インスタンスＩＤへのポインタを登録し生成する>
	SXFMapBaseC(SXFInstanceIDC* IN_InstanceIDManeger) ;

//	<インスタンスＩＤと共通情報管理へのポインタを登録し生成する>
	SXFMapBaseC(SXFInstanceIDC* IN_InstanceIDManeger,SXFComInfoC* IN_ComInfoC ) ;

//	<ルートフィーチャＩＤを登録する>
	SXFMapBaseC(int) ;
//
//	<コンストラクタ>
	SXFMapBaseC(int	, int) ;

//	<デストラクタ>
//
	virtual	~SXFMapBaseC() ;

//
//	<ルートIDの設定>
	virtual	int	SetRootID(int);
//
//	<ルートIDの取得>
	int	GetRootID( );

private :

protected :

//	<ルートＩＤ>
	int		m_RootID ;

//	<許容誤差>
	double	m_Eps_lenth;
	double	m_Eps_angle;

//	<共通情報管理へのポインタ>
	SXFComInfoC* m_ComInfoC;

} ;

#endif
