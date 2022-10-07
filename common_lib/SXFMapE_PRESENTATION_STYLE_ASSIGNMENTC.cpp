/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_PRESENTATION_STYLE_ASSIGNMENTC.cpp						作成日：2000.04.17

	１．クラス概要
		PRESENTATION_STYLE_ASSIGNMENTを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#include "stdafx.h"
#include "SXFMapE_PRESENTATION_STYLE_ASSIGNMENTC.h"
#include "SXFMapE_CURVE_STYLEC.h"
#include "SXFMapE_SYMBOL_STYLEC.h"
#include "SXFMapE_FILL_AREA_STYLEC.h"
#include "SXFMapE_TEXT_STYLEC.h"
#include "SXFMapEntAConvC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_PRESENTATION_STYLE_ASSIGNMENTC.cpp						作成日：2000.04.17

	１．機能概要
		デフォルトコンストラクタ

	２．インターフェイス
		void	SXFMapE_PRESENTATION_STYLE_ASSIGNMENTC::SXFMapE_PRESENTATION_STYLE_ASSIGNMENTC()

	引数  ：	型			引数名				内容
			なし
	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_PRESENTATION_STYLE_ASSIGNMENTC::SXFMapE_PRESENTATION_STYLE_ASSIGNMENTC()
{
//	<初期化>
	m_EntityName = DEF_PRESENTATION_STYLE_ASSIGNMENT;
//<エンティティデータ>
//#143 = PRESENTATION_STYLE_ASSIGNMENT((#142));
	//	1.stylesへのインスタンスＩＤ

	//m_STYLE_InsへのインスタンスID
	m_styles_Inst=NULL;

	//セグメント数	※エンティティパラメタには存在しない。
	m_Segment=0;

	//stylesへのポインタ
	m_styles_P = NULL;

	//stylesの種類
	m_stylesKind = 0;
		//	NONSTYLE,		//0:不明
		//	CURVESTYLE,		//1:
		//	SYMBOLSTYLE,	//2:
		//	FILLSTYLE,		//3:
		//	TEXTSTYLE,		//4:
		//	NULLSTYLE		//5:

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_PRESENTATION_STYLE_ASSIGNMENTC.cpp						作成日：2000.04.17

	１．機能概要
		インスタンスＩＤへのポインタを指定して生成する場合
		(コンストラクタ)

	２．インターフェイス
		void	SXFMapE_PRESENTATION_STYLE_ASSIGNMENTC::SXFMapE_PRESENTATION_STYLE_ASSIGNMENTC(
						SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	引数  ：	型				引数名				内容
				SXFInstanceIDC* IN_InstanceIDManeger	ｲﾝｽﾀﾝｽID管理ｵﾌﾞｼﾞｪｸﾄ

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_PRESENTATION_STYLE_ASSIGNMENTC::SXFMapE_PRESENTATION_STYLE_ASSIGNMENTC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
{
//	<初期化>
	m_EntityName = DEF_PRESENTATION_STYLE_ASSIGNMENT;
//<エンティティデータ>
//<エンティティデータ>
//#143 = PRESENTATION_STYLE_ASSIGNMENT((#142));
	//	1.stylesへのインスタンスＩＤ

	//m_STYLE_InsへのインスタンスID
	m_styles_Inst=NULL;

	//セグメント数	※エンティティパラメタには存在しない。
	m_Segment=0;

	//stylesへのポインタ
	m_styles_P = NULL;

	//stylesの種類
	m_stylesKind = 0;
		//	NONSTYLE,		//0:不明
		//	CURVESTYLE,		//1:
		//	SYMBOLSTYLE,	//2:
		//	FILLSTYLE,		//3:
		//	TEXTSTYLE,		//4:
		//	NULLSTYLE		//5:

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_PRESENTATION_STYLE_ASSIGNMENTC.cpp						作成日：2000.04.17

	１．機能概要
		(デストラクタ)

	２．インターフェイス
		void	SXFMapE_PRESENTATION_STYLE_ASSIGNMENTC::~SXFMapE_PRESENTATION_STYLE_ASSIGNMENTC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_PRESENTATION_STYLE_ASSIGNMENTC::~SXFMapE_PRESENTATION_STYLE_ASSIGNMENTC()
{
	if(m_styles_P != NULL){
		if (m_stylesKind==CURVESTYLE)  delete (SXFMapE_CURVE_STYLEC*)m_styles_P;
		if (m_stylesKind==SYMBOLSTYLE) delete (SXFMapE_SYMBOL_STYLEC*)m_styles_P;
		if (m_stylesKind==FILLSTYLE)   delete (SXFMapE_FILL_AREA_STYLEC*)m_styles_P;
		if (m_stylesKind==TEXTSTYLE)   delete (SXFMapE_TEXT_STYLEC*)m_styles_P;
	}
}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_PRESENTATION_STYLE_ASSIGNMENTC.cpp						作成日：2000.04.17

	１．機能概要
		エンティティのパラメタ設定

	２．インターフェイス
		int		SXFMapE_PRESENTATION_STYLE_ASSIGNMENTC::SetParameter()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
int SXFMapE_PRESENTATION_STYLE_ASSIGNMENTC::SetParameter()

{
	int ircode;
	CArray<int,int> IntArray;

//	<1. エンティティパラメタの設定>

//<エンティティデータ>
//#143 = PRESENTATION_STYLE_ASSIGNMENT((#142));
//#143 = PRESENTATION_STYLE_ASSIGNMENT((NULL_STYLE(.NULL.)));


//	1. NULL_STYLEか？ の判断 //////////////////////////////////////////////////////

	if ( (*m_EntityArray)[0].Find(DEF_NULL_STYLE) != -1 ){
		m_stylesKind=NULLSTYLE;
		return 0;
	}

//	2. エンティティパラメタの設定/////////////////////////////////////////////////
	SXFMapEntAConvC convent(m_EntityArray);
	//	1.stylesへのインスタンスＩＤ
	//m_STYLE_InsへのインスタンスID
	//セグメント数	※エンティティパラメタには存在しない。
	convent.GetSetInst(0,m_Segment,IntArray);
	m_styles_Inst=IntArray[0];

	if (m_styles_Inst == 0 ) return -10000;

//	<2. 参照先のエンティティパラメタの設定>
	CString InstEntityName;

	//stylesのエンティティ名を取得し、応じたクラスを作成する。
	//PRESENTATION_STYLE_ASSIGNMENTの参照するインスタンスIDはSet型だが、
	//ルール上、１つのインスタンスしか参照しない。
	//そのため、最初の１つだけ判断し、エンティティインスタンスを作成する。

	InstEntityName = SXFMapInstIDC::GetEntityName(m_styles_Inst);

	if (InstEntityName.Find(DEF_CURVE_STYLE) != -1){
		m_stylesKind=CURVESTYLE;
		m_styles_P = new SXFMapE_CURVE_STYLEC(m_InstanceIDManager);

		//インスタンスＩＤを指定しエンティティデータを設定
		ircode = ((SXFMapE_CURVE_STYLEC*)m_styles_P)->SetRootID(m_styles_Inst);
			if ( ircode < 0 )	return ircode ;
		//エンティティパラメタの設定
		ircode = ((SXFMapE_CURVE_STYLEC*)m_styles_P)->SetParameter();
			if ( ircode < 0 )	return ircode ;
	}
	else if (InstEntityName.Find(DEF_SYMBOL_STYLE) != -1){
		m_stylesKind=SYMBOLSTYLE;
		m_styles_P = new SXFMapE_SYMBOL_STYLEC(m_InstanceIDManager);

		//インスタンスＩＤを指定しエンティティデータを設定
		ircode = ((SXFMapE_SYMBOL_STYLEC*)m_styles_P)->SetRootID(m_styles_Inst);
			if ( ircode < 0 )	return ircode ;
		//エンティティパラメタの設定
		ircode = ((SXFMapE_SYMBOL_STYLEC*)m_styles_P)->SetParameter();
		//既定義シンボル色コードフラグが０のとき
		if (ircode == 1){
			m_stylesKind = NONSTYLE;
		}
		if ( ircode < 0 )	return ircode ;
	}
	else if (InstEntityName.Find(DEF_FILL_AREA_STYLE) != -1){
		m_stylesKind=FILLSTYLE;
		m_styles_P = new SXFMapE_FILL_AREA_STYLEC(m_InstanceIDManager);

		//インスタンスＩＤを指定しエンティティデータを設定
		ircode = ((SXFMapE_FILL_AREA_STYLEC*)m_styles_P)->SetRootID(m_styles_Inst);
			if ( ircode < 0 )	return ircode ;
		//エンティティパラメタの設定
		ircode = ((SXFMapE_FILL_AREA_STYLEC*)m_styles_P)->SetParameter();
		if ( ircode < 0 )	return ircode ;
	}
	else if (InstEntityName.Find(DEF_SXF_COMPLEX_INSTANCE) != -1||
						InstEntityName.Find(DEF_TEXT_STYLE) != -1){
		m_stylesKind=TEXTSTYLE;
		m_styles_P = new SXFMapE_TEXT_STYLEC(m_InstanceIDManager);
		
		//インスタンスＩＤを指定しエンティティデータを設定
		ircode = ((SXFMapE_TEXT_STYLEC*)m_styles_P)->SetRootID(m_styles_Inst);
		if ( ircode < 0 )	return ircode ;
		//エンティティパラメタの設定
		ircode = ((SXFMapE_TEXT_STYLEC*)m_styles_P)->SetParameter();
		if ( ircode < 0 )	return ircode ;

		//コンプレックスエンティティなので後からチェック
		if ( ((SXFMapE_TEXT_STYLEC*)m_styles_P)->m_EntityData.Find(DEF_TEXT_STYLE) == -1 ){
			//err TEXT_STYLEエンティティに不整合がある
			return -10000;

		}

	}
	else {
	// SCADECの対象ではないENTITYです
		SXFErrorMsgC::RecordError(
			SXFEXCEPT,			//errメッセージ番号
			InstEntityName,		//エンティティ名
			2,					//パラメタの個数
			m_styles_Inst,	//パラメタ
			InstEntityName
			);
		return SXFEXCEPT;

	}

		//	FILLSTYLE,		//3:
		//	TEXTSTYLE,		//4:
		//	NULLSTYLE		//5:

	return 0;
}
