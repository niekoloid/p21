/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_CURVE_STYLE_FONTC.cpp						作成日：2000.04.17

	１．クラス概要
		EntityDataを型変換する

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#include "stdafx.h"
#include "SXFMapE_CURVE_STYLE_FONTC.h"
#include "SXFMapE_CURVE_STYLE_FONT_PATTERNC.h"
#include "SXFMapEntAConvC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_CURVE_STYLE_FONTC.cpp						作成日：2000.04.17

	１．機能概要
		デフォルトコンストラクタ

	２．インターフェイス
		void	SXFMapE_CURVE_STYLE_FONTC::SXFMapE_CURVE_STYLE_FONTC()

	引数  ：	型			引数名				内容
			なし
	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_CURVE_STYLE_FONTC::SXFMapE_CURVE_STYLE_FONTC()
{
//	<初期化>
	m_EntityName = DEF_CURVE_STYLE_FONT;
//#80 = CURVE_STYLE_FONT('chain_4212', (#81, #82));
//<エンティティデータ>
	m_name.Empty();		//nameパラメタ
	//m_CURVE_STYLE_FONT_PATTERN_InsへのインスタンスID
	m_CURVE_STYLE_FONT_PATTERN_Inst.RemoveAll();
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_CURVE_STYLE_FONTC.cpp						作成日：2000.04.17

	１．機能概要
		インスタンスＩＤへのポインタを指定して生成する場合
		(コンストラクタ)

	２．インターフェイス
		void	SXFMapE_CURVE_STYLE_FONTC::SXFMapE_CURVE_STYLE_FONTC(
						SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	引数：	型				引数名				内容
			SXFInstanceIDC* IN_InstanceIDManeger	ｲﾝｽﾀﾝｽID管理ｵﾌﾞｼﾞｪｸﾄ

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_CURVE_STYLE_FONTC::SXFMapE_CURVE_STYLE_FONTC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
{
//	<初期化>
	m_EntityName = DEF_CURVE_STYLE_FONT;
//#80 = CURVE_STYLE_FONT('chain_4212', (#81, #82));
//<エンティティデータ>
	m_name.Empty();		//nameパラメタ
	//m_CURVE_STYLE_FONT_PATTERN_InsへのインスタンスID
	m_CURVE_STYLE_FONT_PATTERN_Inst.RemoveAll();
}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_CURVE_STYLE_FONTC.cpp						作成日：2000.04.17

	１．機能概要
		(デストラクタ)

	２．インターフェイス
		void	SXFMapE_CURVE_STYLE_FONTC::~SXFMapE_CURVE_STYLE_FONTC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_CURVE_STYLE_FONTC::~SXFMapE_CURVE_STYLE_FONTC()
{
	for(int i=0;i<m_CURVE_STYLE_FONT_PATTERN_P.GetSize();i++){
		if( m_CURVE_STYLE_FONT_PATTERN_P[i] != NULL)
			delete m_CURVE_STYLE_FONT_PATTERN_P[i];
	}
}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_CURVE_STYLE_FONTC.cpp						作成日：2000.04.17

	１．機能概要
		エンティティのパラメタ設定

	２．インターフェイス
		int		SXFMapE_CURVE_STYLE_FONTC::SetParameter()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
int SXFMapE_CURVE_STYLE_FONTC::SetParameter()
{
int ircode;
//	<1. エンティティパラメタの設定>

//<エンティティデータ>
//#80 = CURVE_STYLE_FONT('chain_4212', (#81, #82));			
	SXFMapEntAConvC convent(m_EntityArray);
	//<name>
	convent.GetCString(0,m_name);

	//m_CURVE_STYLE_FONT_PATTERN_InsへのインスタンスIDの設定
	convent.GetSetInst(1,m_Segment,m_CURVE_STYLE_FONT_PATTERN_Inst);
	if ( m_Segment < 1 ) {
		//エンティティパラメタの数に謝りがあります。
			SXFErrorMsgC::RecordError(
				SXFPARAMS,			//errメッセージ番号
				m_EntityName,		//エンティティ名
				2,					//パラメタの個数
				m_RootID,			//パラメタ
				m_EntityName
				);
		return SXFPARAMS;
	}

//	<2. 参照先のCURVE_STYLE_FONT_PATTERNエンティティパラメタの設定>

		//#81 = CURVE_STYLE_FONT_PATTERN(4., 2.);

		//エンティティインスタンスを作成
		for ( int i=0; i<m_Segment ; i++ ){

			SXFMapE_CURVE_STYLE_FONT_PATTERNC* temp_p =		
				new SXFMapE_CURVE_STYLE_FONT_PATTERNC(m_InstanceIDManager);
			m_CURVE_STYLE_FONT_PATTERN_P.Add(temp_p);
			//インスタンスＩＤを指定しエンティティデータを設定
			ircode = temp_p->SetRootID(m_CURVE_STYLE_FONT_PATTERN_Inst[i]);
				if ( ircode < 0 )	return ircode ;
			//エンティティパラメタの設定
			ircode = temp_p->SetParameter();
				if ( ircode < 0 )	return ircode ;
		
		}

	return 0;
}
