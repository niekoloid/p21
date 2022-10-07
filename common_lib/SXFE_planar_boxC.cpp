/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_planar_boxC.cpp								作成日：2000.4.18

	１．クラス概要
	エンティティデータ管理

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/

#include "stdafx.h"
#include "SXFD_strC.h"
#include "SXFD_RealC.h"
#include "SXFE_planar_boxC.h"
#include "SXF_EXT.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_planar_boxC.cpp								作成日：2000.4.18

	１．機能概要
		コンストラクタ

	２．インターフェース
	void	SXFE_planar_boxC(SXFD_StrC *str,SXFD_RealC *real1,SXFD_RealC *real2,SXFD_InstC *inst)
	引数:	型				引数名			内容
			SXFD_StrC 		*str				ｴﾝﾃｨﾃｨﾃﾞｰﾀ
			SXFD_RealC 		*real1				ｴﾝﾃｨﾃｨﾃﾞｰﾀ
			SXFD_RealC 		*real2				ｴﾝﾃｨﾃｨﾃﾞｰﾀ
			SXFD_InstC 		*inst				ｴﾝﾃｨﾃｨﾃﾞｰﾀ

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.4.18			宮園(FQS)			なし。

**/
SXFE_planar_boxC
::SXFE_planar_boxC(SXFD_StrC *str,SXFD_RealC *real1,SXFD_RealC *real2,SXFD_InstC *inst){

	m_Flg = 1;

	m_InstanceID = gl_InstanceID;
	gl_InstanceID += 10;

	m_Entity = DEF_PLANAR_BOX;

	m_Data.AddTail(str);
	m_Data.AddTail(real1);
	m_Data.AddTail(real2);
	m_Data.AddTail(inst);
}
