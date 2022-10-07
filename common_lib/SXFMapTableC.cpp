/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapTableC.cpp						作成日：2000.04.21

	１．クラス概要
		AP202エンティティからフィーチャへのマッピングを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.21	

**/
#include "stdafx.h"
#include "SXFMapEntityBaseC.h"
#include "SXFInstanceIDC.h"
#include "SXFComInfoC.h"
#include "SXFTableKindE.h"
#include "SXFMapEntAConvC.h"

#include "SXFLayerC.h"
#include "SXFPreDefFontC.h"
#include "SXFUserDefFontC.h"
#include "SXFPreDefColorC.h"
#include "SXFUserDefColorC.h"
#include "SXFWidthC.h"
#include "SXFTextFontC.h"

#include "SXFMapE_PRESENTATION_LAYER_USAGEC.h"
#include "SXFMapE_PRESENTATION_LAYER_ASSIGNMENTC.h"
#include "SXFMapE_DRAUGHTING_PRE_DEFINED_CURVE_FONTC.h"
#include "SXFMapE_CURVE_STYLE_FONTC.h"
#include "SXFMapE_CURVE_STYLE_FONT_PATTERNC.h"
#include "SXFMapE_DRAUGHTING_PRE_DEFINED_COLOURC.h"
#include "SXFMapE_COLOUR_RGBC.h"
#include "SXFMapE_EXTERNAL_SOURCEC.h"
#include "SXFMapE_EXTERNAL_DEFINED_TEXT_FONTC.h"
#include "SXFMapE_LENGTH_MEASURE_WITH_UNITC.h"
#include "SXFTableManagerC.h"//ID_218_000706_ins

#include "SXFMapTableC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapTableC.cpp						作成日：2000.04.21

	１．機能概要
		デフォルトコンストラクタ

	２．インターフェイス
		void	SXFMapTableC::SXFMapTableC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.21	
**/
SXFMapTableC::SXFMapTableC()
{
//
//	<初期化>
//
	m_Type	= 0; 
	m_BodyP = NULL ;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapTableC.cpp						作成日：2000.04.21

	１．機能概要
		(コンストラクタ)

	２．インターフェイス
		void	SXFMapTableC::SXFMapTableC(
						SXFInstanceIDC* IN_InstanceIDManeger,
						SXFComInfoC* IN_ComInfoC,
						SXFTableManagerC* IN_TableManager)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	引数  ：	型				引数名				内容
			SXFInstanceIDC* 	IN_InstanceIDManeger	ｲﾝｽﾀﾝｽID管理ｵﾌﾞｼﾞｪｸﾄ
			SXFComInfoC* 		IN_ComInfoC				共通情報管理ｵﾌﾞｼﾞｪｸﾄ
			SXFTableManagerC*	IN_TableManager			定義ﾃｰﾌﾞﾙ管理ｵﾌﾞｼﾞｪｸﾄ

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.21	
**/

//	<インスタンスＩＤへのポインタを登録し生成する>
SXFMapTableC::SXFMapTableC(
		SXFInstanceIDC* IN_InstanceIDManeger,
		SXFComInfoC* IN_ComInfoC,
		SXFTableManagerC* IN_TableManager)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
{
	m_Type	= 0; 
	m_BodyP = NULL ;
	m_ComInfoC = IN_ComInfoC;
	m_TableManager = IN_TableManager;
}

//	<ルートＩＤとフィーチャ種別を指定して生成する場合>
SXFMapTableC::SXFMapTableC(
			int	IN_RootID, 
			int	IN_FeatureKind)
{
//
//	<初期化>
//
	m_Type	= 0; 
	m_BodyP = NULL ;
	m_RootID= IN_RootID;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapTableC.cpp						作成日：2000.04.21

	１．機能概要
		(デストラクタ)

	２．インターフェイス
		void	SXFMapTableC::~SXFMapTableC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.21	
**/
SXFMapTableC::~SXFMapTableC()
{

/*	E_LAYER = 1,	//1:レイヤ
	E_PRECOLOR,		//2:既定義色
	E_USERCOLOR,	//3:ユーザ定義色
	E_PREFONT,		//4:既定義線種
	E_USERFONT,		//5:ユーザ定義線種
	E_WIDTH,		//6:線幅
	E_TEXTFONT		//7:文字フォント*/

	if (m_BodyP!=NULL){

		if (m_Type == E_LAYER) {
			 delete (SXFLayerC*)m_BodyP;	//1:レイヤ
		}
		else if (m_Type == E_PRECOLOR) {
			 delete (SXFPreDefColorC*)m_BodyP; 	//2:既定義色
		}
		else if (m_Type == E_USERCOLOR) {
			 delete (SXFUserDefColorC*)m_BodyP;	//3:ユーザ定義色
		}
		else if (m_Type ==  E_PREFONT) {
		 	 delete (SXFPreDefFontC*)m_BodyP;	//4:既定義線種
		}
		else if (m_Type == E_USERFONT){
			 delete (SXFUserDefFontC*)m_BodyP;	//5:ユーザ定義線種
		}
		else if (m_Type == E_WIDTH){
			 delete (SXFWidthC*)m_BodyP;	//6:線幅
		}
		else if (m_Type == E_TEXTFONT){
			 delete (SXFTextFontC*)m_BodyP;	//7:文字フォント
		}

	}
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapTableC.cpp						作成日：2000.04.21

	１．機能概要
		定義テーブル要素フィーチャ構造体の作成

	２．インターフェイス
		int		SXFMapTableC::SetFeatureParameter(
					int		OUT_type,
					void*	OUT_Class)


	引数  ：	型			引数名				内容
				int		OUT_type,	//定義テーブル種別	
									1:レイヤ
									2:既定義色
									3:ユーザ定義色
									4:既定義線種
									5:ユーザ定義線種
									6:線幅
									7:文字フォント
				void*	OUT_Class)	//定義テーブルフィーチャクラスへのポインタ


	復帰値：定義テーブル種別

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.21	
**/

int	SXFMapTableC::	SetFeatureParameter(
					int&	OUT_Type,	//定義テーブル種別	
					LPVOID&	OUT_Class)	//定義テーブルフィーチャクラスへのポインタ

{
//
//	<初期化>
//
	int ircode;
	OUT_Type = 0;
	OUT_Class = NULL;

//	<エンティティの判定>
	//////	<レイヤ> ///////////////////////////////////////////////////////
	if (m_EntityName == DEF_PRESENTATION_LAYER_USAGE) {
		//#1421 = PRESENTATION_LAYER_USAGE(#1420, #1412);
		//#1420 = PRESENTATION_LAYER_ASSIGNMENT('Layer', 'all elements', (#140, #180, 
		//#200, #240, #280, #320, #360, #461, #460, #521, #520, #598, #1340, #1380));
		SXFMapE_PRESENTATION_LAYER_USAGEC e_layer(m_InstanceIDManager);
		//インスタンスＩＤを指定しエンティティデータを設定
		ircode = e_layer.SetEntityArraydata(m_RootID,m_EntityName,m_EntityArray);
		if ( ircode < 0 )	return ircode ;
		//エンティティパラメタの設定
		ircode = e_layer.SetParameter();
		if ( ircode < 0 )	return ircode ;

		//フィーチャデータの設定	
		SXFLayerC* layer = new SXFLayerC;
		//レイヤ名
		layer->m_Name = e_layer.m_Assignment_p->m_Name;
//	MOD(S)	チューニング対応	K.Naono	03.07.04
//		for ( int i=0;i<(e_layer.m_Assignment_p->m_AssignedItems.GetSize());i++){
//			m_LayerElements.Add(e_layer.m_Assignment_p->m_AssignedItems[i]);
//		}
		INT_PTR	nCount = e_layer.m_Assignment_p->m_AssignedItems.GetSize() ;
		m_LayerElements.SetSize(nCount) ;
		for(int i = 0; i < nCount; i++) {
			m_LayerElements[i] = e_layer.m_Assignment_p->m_AssignedItems[i] ;
		}
//	MOD(E)	チューニング対応	K.Naono	03.07.04

		//  表示・非表示フラグの設定 /////////////////////////////////////////
		layer->m_LfFlag = !(m_TableManager->GetInvisibilityFlag(e_layer.m_Assignment_Inst));
		//////////////////////////////////////////////////////////////////////
		//定義テーブル種類
		m_Type = E_LAYER;		//=1
		//クラスへのポインタを返す。
		m_BodyP = layer;
	}

	//////	<既定義色> ///////////////////////////////////////////////////////	
	else if (m_EntityName == DEF_DRAUGHTING_PRE_DEFINED_COLOUR) {
		//#40 = DRAUGHTING_PRE_DEFINED_COLOUR('black');

		//エンティティインスタンスを作成
		SXFMapE_DRAUGHTING_PRE_DEFINED_COLOURC e_predefcolor(m_InstanceIDManager);
		//インスタンスＩＤを指定しエンティティデータを設定
		ircode = e_predefcolor.SetEntityArraydata(m_RootID,m_EntityName,m_EntityArray);
		if ( ircode < 0 )	return ircode ;
		//エンティティパラメタの設定
		ircode = e_predefcolor.SetParameter();
		if ( ircode < 0 )	return ircode ;

		//フィーチャデータの設定	
		SXFPreDefColorC*	predefcolor = new SXFPreDefColorC;
		//既定義色名
		if (!predefcolor->SetName(e_predefcolor.m_name)){
			SXFErrorMsgC::RecordError(SXFNOTPRECOLOUR,DEF_PREDEFINED_COLOUR,1,e_predefcolor.m_name);
			return SXFNOTPRECOLOUR;
		}
		//定義テーブル種類
		m_Type  = E_PRECOLOR;		//=2
		//クラスへのポインタを返す。		===>>>> これでいいの？？？？
		m_BodyP = predefcolor;
	}
	//////	<ユーザ定義色又は既定義色> ///////////////////////////////////////////////////////
	else if (m_EntityName == DEF_COLOUR_RGB) {
		//#140 = COLOUR_RGB('colour_rgb1', 0.12, 0.56, 1.);
		//#140 = COLOUR_RGB('$$SXF_', 0.12, 0.56, 1.);

		//エンティティインスタンスを作成
		SXFMapE_COLOUR_RGBC e_userdefcolor(m_InstanceIDManager);
		//インスタンスＩＤを指定しエンティティデータを設定
		ircode = e_userdefcolor.SetEntityArraydata(m_RootID,m_EntityName,m_EntityArray);
		if ( ircode < 0 )	return ircode ;
		//エンティティパラメタの設定
		ircode = e_userdefcolor.SetParameter();
		if ( ircode < 0 )	return ircode ;

		//フィーチャデータの設定	
		//SCADECの既定義色かユーザ定義色かの判定

		//////SCADEC既定義色の場合 ///////////////////////////////////////////////////
		if ( e_userdefcolor.m_name.Left(6) == "$$SXF_"){
			SXFPreDefColorC*	predefcolor = new  SXFPreDefColorC;
			//既定義色名
			CString colorname;
			colorname = e_userdefcolor.m_name;
			colorname.TrimLeft("$$SXF_");
			if (!predefcolor->SetName(colorname)) {
				SXFErrorMsgC::RecordError(SXFNOTPRECOLOUR,DEF_PREDEFINED_COLOUR,1,e_userdefcolor.m_name);
				return SXFNOTPRECOLOUR;
			}

			//定義テーブル種類
			m_Type  = E_PRECOLOR;		//=2
			//クラスへのポインタを返す。
			m_BodyP = predefcolor;
		}
		//////ユーザ定義色の場合 ///////////////////////////////////////////////////
		else{
			SXFUserDefColorC* userdefcolor = new SXFUserDefColorC;
			userdefcolor->R = (int)(e_userdefcolor.m_R * 255. + 0.5);
			userdefcolor->G = (int)(e_userdefcolor.m_G * 255. + 0.5);
			userdefcolor->B = (int)(e_userdefcolor.m_B * 255. + 0.5);

			//定義テーブル種類
			m_Type  = E_USERCOLOR;	//=3
			//クラスへのポインタを返す。
			m_BodyP = userdefcolor;
		}
	}

	//////	<既定義線種> ///////////////////////////////////////////////////////
	else if (m_EntityName == DEF_DRAUGHTING_PRE_DEFINED_CURVE_FONT) {

		//#20 = DRAUGHTING_PRE_DEFINED_CURVE_FONT('continuous');
		//エンティティインスタンスを作成
		SXFMapE_DRAUGHTING_PRE_DEFINED_CURVE_FONTC e_predeffont(m_InstanceIDManager);
		//インスタンスＩＤを指定しエンティティデータを設定
		ircode = e_predeffont.SetEntityArraydata(m_RootID,m_EntityName,m_EntityArray);
		if ( ircode < 0 )	return ircode ;
		//エンティティパラメタの設定
		ircode = e_predeffont.SetParameter();
		if ( ircode < 0 )	return ircode ;

		//フィーチャデータの設定	
		SXFPreDefFontC*	predeffont = new SXFPreDefFontC;
		//既定義線種名
		if (!predeffont->SetName( e_predeffont.m_name) ){
			SXFErrorMsgC::RecordError(SXFNOTPRETYPE,DEF_PREDEFINED_LINETYPE,1,e_predeffont.m_name);
			return SXFNOTPRETYPE;
		}

		//定義テーブル種類
		m_Type  = E_PREFONT;	//=2
		//クラスへのポインタを返す。
		m_BodyP = predeffont;
	}

	//////	<ユーザ定義線種> ///////////////////////////////////////////////////////
	else if (m_EntityName == DEF_CURVE_STYLE_FONT) {

		//#80 = CURVE_STYLE_FONT('chain_4212', (#81, #82));
		//エンティティインスタンスを作成
		SXFMapE_CURVE_STYLE_FONTC e_stylefont(m_InstanceIDManager);
		//インスタンスＩＤを指定しエンティティデータを設定
		ircode = e_stylefont.SetEntityArraydata(m_RootID,m_EntityName,m_EntityArray);
		if ( ircode < 0 )	return ircode ;
		//エンティティパラメタの設定
		ircode = e_stylefont.SetParameter();
		if ( ircode < 0 )	return ircode ;

		//フィーチャデータの設定	
		SXFUserDefFontC* userdeffont = new SXFUserDefFontC;
		//	<フォント名>
		userdeffont->m_Name = e_stylefont.m_name;
		userdeffont->m_Segment = e_stylefont.m_Segment*2;

		//#82 = CURVE_STYLE_FONT_PATTERN(1., 2.);
		//CURVE_STYLE_FONTの参照先CURVE_STYLE_FONT_PATTERNの
		//表示部長さ、非表示部長さを設定する。
		for (int i=0 ;i<e_stylefont.m_Segment;i++ ){
			userdeffont->m_Pitch.Add(e_stylefont.m_CURVE_STYLE_FONT_PATTERN_P[i]->m_visi);
			userdeffont->m_Pitch.Add(e_stylefont.m_CURVE_STYLE_FONT_PATTERN_P[i]->m_invisi);
		}
		//定義テーブル種類
		m_Type  = E_USERFONT;		//=5
		//クラスへのポインタを返す。
		m_BodyP = userdeffont;
	}

	//////	<線幅> ///////////////////////////////////////////////////////
	else if (m_EntityName == DEF_LENGTH_MEASURE_WITH_UNIT) {
		//#60 = LENGTH_MEASURE_WITH_UNIT(POSITIVE_LENGTH_MEASURE(0.5), #62);
		//エンティティインスタンスを作成
		SXFMapE_LENGTH_MEASURE_WITH_UNITC e_width(m_InstanceIDManager);
		//インスタンスＩＤを指定しエンティティデータを設定
		ircode = e_width.SetEntityArraydata(m_RootID,m_EntityName,m_EntityArray);
			if ( ircode < 0 )	return ircode ;
		//エンティティパラメタの設定
		ircode = e_width.SetParameter();
			if ( ircode < 0 )	return ircode ;
		//フィーチャデータの設定	
		SXFWidthC* width = new SXFWidthC;
		width->m_Width = e_width.m_Width;
		//定義テーブル種類
		m_Type  = E_WIDTH;		//=6
		//クラスへのポインタを返す。
		m_BodyP = width;

	}
	//////	<文字フォント> ///////////////////////////////////////////////////////
	else if (m_EntityName == DEF_EXTERNALLY_DEFINED_TEXT_FONT) {
		//#81 = EXTERNAL_SOURCE(IDENTIFIER('Helvetica8'));
		//#80 = EXTERNALLY_DEFINED_TEXT_FONT(IDENTIFIER('Helvetica8'), #81);
		//エンティティインスタンスを作成
		SXFMapE_EXTERNAL_DEFINED_TEXT_FONTC e_textfont(m_InstanceIDManager);
		//インスタンスＩＤを指定しエンティティデータを設定
		ircode = e_textfont.SetEntityArraydata(m_RootID,m_EntityName,m_EntityArray);
			if ( ircode < 0 )	return ircode ;
		//エンティティパラメタの設定
		ircode = e_textfont.SetParameter();
			if ( ircode < 0 )	return ircode ;
		//フィーチャデータの設定	
		SXFTextFontC* textfont = new SXFTextFontC;

		//	テキストフォントのベースライン比率の削除
		
		textfont->m_Name = e_textfont.m_Name;
		//定義テーブル種類
		m_Type  = E_TEXTFONT;		//=7
		//クラスへのポインタを返す。
		m_BodyP = textfont;

	}
	//	<エラー>
	else{
		//err
		return -10000;
	}

	//定義テーブル種類
	OUT_Type  = m_Type;	
	//クラスへのポインタを返す。
	OUT_Class = m_BodyP;

	return 0;
}
