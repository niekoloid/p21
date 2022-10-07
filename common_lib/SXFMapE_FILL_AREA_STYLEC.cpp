/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_FILL_AREA_STYLEC.cpp						作成日：2000.04.17

	１．クラス概要
		FILL_AREA_STYLEを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#include "stdafx.h"
#include <afxtempl.h>
#include "SXFMapEntAConvC.h"
#include "SXFMapEntityBaseC.h"
#include "SXFInstanceIDC.h"
#include "SXFMapE_EXTERNALLY_DEFINED_HATCHC.h"
#include "SXFMapE_FILL_AREA_STYLE_COLOURC.h"
#include "SXFMapE_FILL_AREA_STYLE_HATCHINGC.h"
#include "SXFMapE_FILL_AREA_STYLE_TILEC.h"
#include "SXFMapE_FILL_AREA_STYLEC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_FILL_AREA_STYLEC.cpp						作成日：2000.04.17

	１．機能概要
		デフォルトコンストラクタ

	２．インターフェイス
		void	SXFMapE_FILL_AREA_STYLEC::SXFMapE_FILL_AREA_STYLEC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_FILL_AREA_STYLEC::SXFMapE_FILL_AREA_STYLEC()
{
	m_EntityName = DEF_FILL_AREA_STYLE;

	m_FillStyle_Count = 0;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_FILL_AREA_STYLEC.cpp						作成日：2000.04.17

	１．機能概要
		インスタンスＩＤへのポインタを指定して生成する場合
		(コンストラクタ)

	２．インターフェイス
		void	SXFMapE_FILL_AREA_STYLEC::SXFMapE_FILL_AREA_STYLEC(
						SXFInstanceIDC* IN_InstanceIDManeger)
        :SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	引数 ：	型				引数名				内容
			SXFInstanceIDC* IN_InstanceIDManeger	ｲﾝｽﾀﾝｽID管理ｵﾌﾞｼﾞｪｸﾄ

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_FILL_AREA_STYLEC::SXFMapE_FILL_AREA_STYLEC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)

{
	m_EntityName = DEF_FILL_AREA_STYLE;

	m_FillStyle_Count = 0;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_FILL_AREA_STYLEC.cpp						作成日：2000.04.17

	１．機能概要
		(デストラクタ)

	２．インターフェイス
		void	SXFMapE_FILL_AREA_STYLEC::~SXFMapE_FILL_AREA_STYLEC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_FILL_AREA_STYLEC::~SXFMapE_FILL_AREA_STYLEC()
{

	for(int i=0;i<m_FillStyleArray_p.GetSize();i++){
		if(m_FillStyleArray_p[i]!=NULL){
			if( m_FillStyle_Name[i]==DEF_EXTERNALLY_DEFINED_HATCH_STYLE)
				 delete (SXFMapE_EXTERNALLY_DEFINED_HATCHC*)m_FillStyleArray_p[i];

			if( m_FillStyle_Name[i]==DEF_FILL_AREA_STYLE_COLOUR)
				 delete (SXFMapE_FILL_AREA_STYLE_COLOURC*)m_FillStyleArray_p[i];

			if( m_FillStyle_Name[i]==DEF_FILL_AREA_STYLE_HATCHING)
				 delete (SXFMapE_FILL_AREA_STYLE_HATCHINGC*)m_FillStyleArray_p[i];

			if( m_FillStyle_Name[i]==DEF_FILL_AREA_STYLE_TILES)
				 delete (SXFMapE_FILL_AREA_STYLE_TILEC*)m_FillStyleArray_p[i];
		}
	}

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_FILL_AREA_STYLEC.cpp						作成日：2000.04.17

	１．機能概要
		エンティティのパラメタ設定

	２．インターフェイス
		int		SXFMapE_FILL_AREA_STYLEC::SetParameter()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
int SXFMapE_FILL_AREA_STYLEC::SetParameter( )
{
	int ircode;

	SXFMapEntAConvC convent(m_EntityArray);

	//引数エラー
	if ( convent.GetCString(0,m_Name) < 0 ){
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	//引数エラー
	if ( convent.GetSetInst(1,m_FillStyle_Count,m_FillStyleArray_Inst ) < 0 ){
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	for(int i=m_FillStyle_Count-1;i>=0;i--){

		CString InstEntityName;
		//Fill_Styleを取得し、判別する。
		InstEntityName = SXFMapInstIDC::GetEntityName(m_FillStyleArray_Inst[i]);

		//EXTERNALLY_DEFINED_HATCH_STYLE
		if (InstEntityName ==DEF_EXTERNALLY_DEFINED_HATCH_STYLE){
			m_FillStyle_Name.Add( DEF_EXTERNALLY_DEFINED_HATCH_STYLE );

			SXFMapE_EXTERNALLY_DEFINED_HATCHC* tempptr = 
				new SXFMapE_EXTERNALLY_DEFINED_HATCHC(m_InstanceIDManager );
			m_FillStyleArray_p.Add((SXFMapE_EXTERNALLY_DEFINED_HATCHC*)tempptr);

			ircode = tempptr->SetRootID(m_FillStyleArray_Inst[i]);
			if ( ircode < 0 )
				return ircode ;
			ircode = tempptr->SetParameter();
			if ( ircode < 0 )
				return ircode ;
		}
		//FILL_AREA_STYLE_COLOUR
		else if (InstEntityName ==DEF_FILL_AREA_STYLE_COLOUR){
			m_FillStyle_Name.Add( DEF_FILL_AREA_STYLE_COLOUR );

			SXFMapE_FILL_AREA_STYLE_COLOURC* tempptr = 
				new SXFMapE_FILL_AREA_STYLE_COLOURC(m_InstanceIDManager );
			m_FillStyleArray_p.Add((SXFMapE_FILL_AREA_STYLE_COLOURC*)tempptr);

			ircode = tempptr->SetRootID(m_FillStyleArray_Inst[i]);
			if ( ircode < 0 )
				return ircode ;
			ircode = tempptr->SetParameter();
			if ( ircode < 0 )
				return ircode ;
		}
    	// FILL_AREA_STYLE_HATCHING
		else if (InstEntityName ==DEF_FILL_AREA_STYLE_HATCHING){
			m_FillStyle_Name.Add ( DEF_FILL_AREA_STYLE_HATCHING );
			SXFMapE_FILL_AREA_STYLE_HATCHINGC* tempptr = 
				new SXFMapE_FILL_AREA_STYLE_HATCHINGC(m_InstanceIDManager );
			m_FillStyleArray_p.Add((SXFMapE_FILL_AREA_STYLE_HATCHINGC*)tempptr);

			ircode = tempptr->SetRootID(m_FillStyleArray_Inst[i]);
			if ( ircode < 0 )
				return ircode ;
			ircode = tempptr->SetParameter();
			if ( ircode < 0 )
				return ircode ;
		}
		// FILL_AREA_STYLE_TILES
		else if (InstEntityName ==DEF_FILL_AREA_STYLE_TILES){
			m_FillStyle_Name.Add (DEF_FILL_AREA_STYLE_TILES );
			SXFMapE_FILL_AREA_STYLE_TILEC* tempptr = 
				new SXFMapE_FILL_AREA_STYLE_TILEC(m_InstanceIDManager );
			m_FillStyleArray_p.Add((SXFMapE_FILL_AREA_STYLE_TILEC*)tempptr);

			ircode = tempptr->SetRootID(m_FillStyleArray_Inst[i]);
			if ( ircode < 0 )
				return ircode ;
			ircode = tempptr->SetParameter();
			if ( ircode < 0 )
				return ircode ;
		}
		else {
			//err
		}
	}

	return 0;
}
