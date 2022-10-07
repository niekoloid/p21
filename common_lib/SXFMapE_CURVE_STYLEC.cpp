/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_CURVE_STYLEC.cpp						作成日：2000.04.17

	１．クラス概要
		CURVE_STYLEを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#include "stdafx.h"
#include "SXFMapE_CURVE_STYLEC.h"
#include "SXFMapE_CARTESIAN_POINTC.h"
#include "SXFMapE_VECTORC.h"
#include "SXFMapEntAConvC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_CURVE_STYLEC.cpp						作成日：2000.04.17

	１．機能概要
		デフォルトコンストラクタ

	２．インターフェイス
		void	SXFMapE_CURVE_STYLEC::SXFMapE_CURVE_STYLEC()

	引数  ：	型			引数名				内容
			なし
	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_CURVE_STYLEC::SXFMapE_CURVE_STYLEC()
{
//	<初期化>
	m_EntityName = DEF_CURVE_STYLE;
//<エンティティデータ>

//#100 = CURVE_STYLE('curve_style3', #20, #60, #40);
	//	1.nameパラメタ
	m_name.Empty();

	//	2.font へのインスタンスID
	m_font_Inst= 0;

	//	3.width へのインスタンスID
	m_width_Inst=0;

	//	4.colour へのインスタンスID
	m_colour_Inst=0;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_CURVE_STYLEC.cpp						作成日：2000.04.17

	１．機能概要
		インスタンスＩＤへのポインタを指定して生成する場合
		(コンストラクタ)

	２．インターフェイス
		void	SXFMapE_CURVE_STYLEC::SXFMapE_CURVE_STYLEC(
						SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	引数：	型					引数名				内容
			SXFInstanceIDC* 	IN_InstanceIDManeger	ｲﾝｽﾀﾝｽID管理ｵﾌﾞｼﾞｪｸﾄ

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_CURVE_STYLEC::SXFMapE_CURVE_STYLEC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
{
//	<初期化>
	m_EntityName = DEF_CURVE_STYLE;
//<エンティティデータ>
//#100 = CURVE_STYLE('curve_style3', #20, #60, #40);
	//	1.nameパラメタ
	m_name.Empty();

	//	2.font へのインスタンスID
	m_font_Inst= 0;

	//	3.width へのインスタンスID
	m_width_Inst=0;

	//	4.colour へのインスタンスID
	m_colour_Inst=0;
	
}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_CURVE_STYLEC.cpp						作成日：2000.04.17

	１．機能概要
		(デストラクタ)

	２．インターフェイス
		void	SXFMapE_CURVE_STYLEC::~SXFMapE_CURVE_STYLEC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_CURVE_STYLEC::~SXFMapE_CURVE_STYLEC()
{
}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_CURVE_STYLEC.cpp						作成日：2000.04.17

	１．機能概要
		エンティティのパラメタ設定

	２．インターフェイス
		int		SXFMapE_CURVE_STYLEC::SetParameter()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/

int SXFMapE_CURVE_STYLEC::SetParameter()

{
//	<1. エンティティパラメタの設定>

//<エンティティデータ>

//#100 = CURVE_STYLE('curve_style3', #20, #60, #40);
	SXFMapEntAConvC convent(m_EntityArray);

	//	1.nameパラメタ
	convent.GetCString(0,m_name);

//インスタンスIDを定義テーブルオブジェクトに渡し、
//該当する定義テーブルのコードを受け取る。
//そのため参照先のエンティティインスタンスは作成しない。

	//	2.font へのインスタンスID
	convent.GetInst(1,m_font_Inst);

	//	3.width へのインスタンスID
	convent.GetInst(2,m_width_Inst);

	//	4.colour へのインスタンスID
	convent.GetInst(3,m_colour_Inst);

	return 0;
}
