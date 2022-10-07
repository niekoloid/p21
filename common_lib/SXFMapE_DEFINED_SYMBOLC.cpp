/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_DEFINED_SYMBOLC.cpp						作成日：2000.04.17

	１．クラス概要
		DEFINED_SYMBOLを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#include "stdafx.h"
#include "SXFMapEntityBaseC.h"
#include "SXFInstanceIDC.h"
#include "SXFMapEntAConvC.h"
#include "SXFMapE_DEFINED_SYMBOLC.h"
#include "SXFMapE_PRE_DEFINED_TERMINATOR_SYMBOLC.h"
#include "SXFMapE_EXTERNALLY_DEFINED_SYMBOLC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_DEFINED_SYMBOLC.cpp						作成日：2000.04.17

	１．機能概要
		デフォルトコンストラクタ

	２．インターフェイス
		void	SXFMapE_DEFINED_SYMBOLC::SXFMapE_DEFINED_SYMBOLC()

	引数  ：	型			引数名				内容
			なし
	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/

SXFMapE_DEFINED_SYMBOLC::SXFMapE_DEFINED_SYMBOLC()
{
	m_EntityName = DEF_DEFINED_SYMBOL;

	m_Definition_Inst = 0;
	m_Definition_p = NULL;
	m_Target_Inst = 0;
	m_Target_p = NULL;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_DEFINED_SYMBOLC.cpp						作成日：2000.04.17

	１．機能概要
		インスタンスＩＤへのポインタを指定して生成する場合
		(コンストラクタ)

	２．インターフェイス
		void	SXFMapE_DEFINED_SYMBOLC::SXFMapE_DEFINED_SYMBOLC(
							SXFInstanceIDC* IN_InstanceIDManeger)
        :SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	引数：	型					引数名				内容
			SXFInstanceIDC*		IN_InstanceIDManeger	ｲﾝｽﾀﾝｽID管理ｵﾌﾞｼﾞｪｸﾄ

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/

SXFMapE_DEFINED_SYMBOLC::SXFMapE_DEFINED_SYMBOLC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)

{
	m_EntityName = DEF_DEFINED_SYMBOL;

	m_Definition_Inst = 0;
	m_Definition_p = NULL;

	m_Target_Inst = 0;
	m_Target_p = NULL;

	m_DefsymKind = 0;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_DEFINED_SYMBOLC.cpp						作成日：2000.04.17

	１．機能概要
		(デストラクタ)

	２．インターフェイス
		void	SXFMapE_DEFINED_SYMBOLC::~SXFMapE_DEFINED_SYMBOLC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_DEFINED_SYMBOLC::~SXFMapE_DEFINED_SYMBOLC()
{

	if(m_Definition_p != NULL){
		if ( m_DefsymKind == 1 ) delete (SXFMapE_PRE_DEFINED_POINT_MARKER_SYMBOLC*)m_Definition_p;
		if ( m_DefsymKind == 2 ) delete (SXFMapE_PRE_DEFINED_TERMINATOR_SYMBOLC*)m_Definition_p;
		if ( m_DefsymKind == 3 ) delete (SXFMapE_EXTERNALLY_DEFINED_SYMBOLC*)m_Definition_p;
	}
	if(m_Target_p != NULL)  delete m_Target_p;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_DEFINED_SYMBOLC.cpp						作成日：2000.04.17

	１．機能概要
		エンティティのパラメタ設定

	２．インターフェイス
		int		SXFMapE_DEFINED_SYMBOLC::SetParameter()

	引数  ：	型			引数名				内容
			なし	

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/

int SXFMapE_DEFINED_SYMBOLC::SetParameter( )
{

	int ircode;

	SXFMapEntAConvC convent(m_EntityArray);

	//引数エラー
	if ( convent.GetCString(0,m_Name) < 0 ){
		SXFErrorMsgC::RecordError( SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	//引数エラー
	if ( convent.GetInst(1,m_Definition_Inst ) < 0 ){
		SXFErrorMsgC::RecordError( SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	CString InstEntityName;
	//m_Definitioを取得し、判別する。
	InstEntityName = SXFMapInstIDC::GetEntityName(m_Definition_Inst);

	if ( InstEntityName == DEF_PRE_DEFINED_POINT_MARKER_SYMBOL){
		m_DefsymKind = 1;

		m_Definition_p = 
			new SXFMapE_PRE_DEFINED_POINT_MARKER_SYMBOLC(m_InstanceIDManager );

		ircode = ((SXFMapE_PRE_DEFINED_POINT_MARKER_SYMBOLC*)m_Definition_p)->SetRootID(m_Definition_Inst);
		if ( ircode < 0 )
			return ircode ;
		ircode = ((SXFMapE_PRE_DEFINED_POINT_MARKER_SYMBOLC*)m_Definition_p)->SetParameter();
		if ( ircode < 0 )
			return ircode ;

		if ( convent.GetInst(2,m_Target_Inst ) < 0 ){
			SXFErrorMsgC::RecordError( SXFPARAMS,
										m_EntityName,
										2,
										m_RootID,
										m_EntityName
										);
			return SXFPARAMS;
		}
	}
	else if ( InstEntityName == DEF_PRE_DEFINED_TERMINATOR_SYMBOL ){

		m_DefsymKind = 2;

		m_Definition_p =
			new SXFMapE_PRE_DEFINED_TERMINATOR_SYMBOLC(m_InstanceIDManager );

		ircode = ((SXFMapE_PRE_DEFINED_TERMINATOR_SYMBOLC*)m_Definition_p)->SetRootID(m_Definition_Inst);
		if ( ircode < 0 )
			return ircode ;
		ircode =  ((SXFMapE_PRE_DEFINED_TERMINATOR_SYMBOLC*)m_Definition_p)->SetParameter();
		if ( ircode < 0 )
			return ircode ;

		if ( convent.GetInst(2,m_Target_Inst ) < 0 ){
			SXFErrorMsgC::RecordError( SXFPARAMS,
										m_EntityName,
										2,
										m_RootID,
										m_EntityName
										);
			return SXFPARAMS;
		}
	}
	else if ( InstEntityName == DEF_EXTERNALLY_DEFINED_SYMBOL){
		// #1386 = EXTERNALLY_DEFINED_SYMBOL(IDENTIFIER('star'), #1385);

		m_DefsymKind = 3;

		m_Definition_p = 
			new SXFMapE_EXTERNALLY_DEFINED_SYMBOLC(m_InstanceIDManager );

		ircode = ((SXFMapE_EXTERNALLY_DEFINED_SYMBOLC*)m_Definition_p)->SetRootID(m_Definition_Inst);
		if ( ircode < 0 )
			return ircode ;
		ircode = ((SXFMapE_EXTERNALLY_DEFINED_SYMBOLC*)m_Definition_p)->SetParameter();
		if ( ircode < 0 )
			return ircode ;

		if ( convent.GetInst(2,m_Target_Inst ) < 0 ){
			SXFErrorMsgC::RecordError( SXFPARAMS,
										m_EntityName,
										2,
										m_RootID,
										m_EntityName
										);
			return SXFPARAMS;
		}
	}
	else{
		//err SCDAEC外
	}

	m_Target_p = 
		new SXFMapE_SYMBOL_TARGETC(m_InstanceIDManager );

	ircode = m_Target_p->SetRootID(m_Target_Inst);
	if ( ircode < 0 )
		return ircode ;
	ircode = m_Target_p->SetParameter();
	if ( ircode < 0 )
		return ircode ;

	return 0;
}
