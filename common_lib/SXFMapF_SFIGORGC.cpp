/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapF_SFIGORGC.cpp						作成日：2000.04.17

	１．クラス概要
		複合図形定義フィーチャを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#include "stdafx.h"
#include "SXFStruct.h"
#include "SXFMapFeatureBaseC.h"
#include "SXFMapF_SFIGORGC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_SFIGORGC.cpp						作成日：2000.04.17

	１．機能概要
		デフォルトコンストラクタ

	２．インターフェイス
		void	SXFMapF_SFIGORGC::SXFMapF_SFIGORGC()

	引数  ：	型			引数名				内容
			なし
	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapF_SFIGORGC::SXFMapF_SFIGORGC()
{
	m_name.Empty();
	m_flag   =0;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_SFIGORGC.cpp						作成日：2000.04.17

	１．機能概要
		(デストラクタ)

	２．インターフェイス
		void	SXFMapF_SFIGORGC::~SXFMapF_SFIGORGC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapF_SFIGORGC::~SXFMapF_SFIGORGC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_SFIGORGC.cpp						作成日：2000.04.17

	１．機能概要
		フィーチャ構造体の取得

	２．インターフェイス
		void	SXFMapF_SFIGORGC::GetStructData(Sfigorg_Struct* INOUT_Struct)

	引数  ：	型				引数名			内容
				Sfigorg_Struct* INOUT_Struct    構造体

	復帰値：正常時：TRUE

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
BOOL SXFMapF_SFIGORGC::GetStructData( Sfigorg_Struct* INOUT_Struct )
{

//	MOD(S)	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
	//strcpy( INOUT_Struct->name, m_name );

	// 文字要素と同じく257バイト以上の文字列は256に切り詰める
	size_t ilen = strlen(m_name);
	if (ilen <= 256) {
		strcpy_s( INOUT_Struct->name,_countof(INOUT_Struct->name), m_name );
	}
	else {
		/* メッセージを出力 */
		// ここも m_RootID = 0,m_TypeName == "" だけど文字要素と同じ処理にしておく
		SXFErrorMsgC::RecordError(SXFNAMELENGTH,m_TypeName,	2, m_RootID, m_TypeName);
		/* 先頭から256バイト切り取る */
		strcpy_s( INOUT_Struct->name,_countof(INOUT_Struct->name), m_name.Left(256) );
	}
//	MOD(E)	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27

	INOUT_Struct->flag	=  m_flag;

	return TRUE;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_SFIGORGC.cpp						作成日：2000.05.13

	１．機能概要
		複合図形名の設定
	２．インターフェイス
		BOOL SXFMapF_SFIGORGC::SetSubName(
			CString IN_name )		//	DRAUGHTING_SUBFIGURE_REPRESENTATION
										 の NAMEパラメタ 


	引数  ：	型			引数名				内容
				CString 	IN_name

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.05.13	大村(FQS)
**/

//
BOOL SXFMapF_SFIGORGC::SetSubName(CString IN_name)
{
//#227 = DRAUGHTING_SUBFIGURE_REPRESENTATION
//('$$FM_SubFigTransform', (#140, #180, #200, #226), #225);

	CStringArray name;
	CString a0(" ");
	CString a1("$$SXF_FM_");
	CString a2("$$SXF_FG_");
	CString a3("$$SXF_G_");
	CString a4("$$SXF_P_");

	name.Add((LPCTSTR)a0);
	name.Add((LPCTSTR)a1);
	name.Add((LPCTSTR)a2);
	name.Add((LPCTSTR)a3);
	name.Add((LPCTSTR)a4);

	//複合定義フラグ
	m_flag = 0;
	CString temstring;
	int index = -1;
	int length = -1;
	for(int i=1;i<=4;i++){
		temstring = name[i];
		if((index = IN_name.Find(name[i])) != -1){
			m_flag=i;
			length = name[i].GetLength();
			IN_name.TrimLeft();
			IN_name = IN_name.Mid(index+length);
			m_name = IN_name;
			break;
		}
	}
	return TRUE;
}
