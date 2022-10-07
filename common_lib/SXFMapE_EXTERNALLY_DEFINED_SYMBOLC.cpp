/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_EXTERNALLY_DEFINED_SYMBOLC.cpp						作成日：2000.04.17

	１．クラス概要
		EXTERNALLY_DEFINED_SYMBOLを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#include "stdafx.h"
#include "SXFMapEntAConvC.h"
#include "SXFMapEntityBaseC.h"
#include "SXFInstanceIDC.h"
#include "SXFMapE_EXTERNALLY_DEFINED_SYMBOLC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_EXTERNALLY_DEFINED_SYMBOLC.cpp						作成日：2000.04.17

	１．機能概要
		デフォルトコンストラクタ

	２．インターフェイス
		void	SXFMapE_EXTERNALLY_DEFINED_SYMBOLC::SXFMapE_EXTERNALLY_DEFINED_SYMBOLC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_EXTERNALLY_DEFINED_SYMBOLC::SXFMapE_EXTERNALLY_DEFINED_SYMBOLC()
{
	m_EntityName = DEF_EXTERNALLY_DEFINED_SYMBOL;

	m_Source_Inst = 0;
	m_Source_p = NULL;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_EXTERNALLY_DEFINED_SYMBOLC.cpp						作成日：2000.04.17

	１．機能概要
		インスタンスＩＤへのポインタを指定して生成する場合
		(コンストラクタ)

	２．インターフェイス
		void	SXFMapE_EXTERNALLY_DEFINED_SYMBOLC::SXFMapE_EXTERNALLY_DEFINED_SYMBOLC(
						SXFInstanceIDC* IN_InstanceIDManeger)
        :SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	引数 ：	型				引数名				内容
			SXFInstanceIDC* IN_InstanceIDManeger	ｲﾝｽﾀﾝｽID管理ｵﾌﾞｼﾞｪｸﾄ

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_EXTERNALLY_DEFINED_SYMBOLC::SXFMapE_EXTERNALLY_DEFINED_SYMBOLC(
		SXFInstanceIDC* IN_InstanceIDManeger)
        :SXFMapEntityBaseC(IN_InstanceIDManeger)

{
	m_EntityName = DEF_EXTERNALLY_DEFINED_SYMBOL;

	m_Source_Inst = 0;
	m_Source_p = NULL;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_EXTERNALLY_DEFINED_SYMBOLC.cpp						作成日：2000.04.17

	１．機能概要
		(デストラクタ)

	２．インターフェイス
		void	SXFMapE_EXTERNALLY_DEFINED_SYMBOLC::~SXFMapE_EXTERNALLY_DEFINED_SYMBOLC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_EXTERNALLY_DEFINED_SYMBOLC::~SXFMapE_EXTERNALLY_DEFINED_SYMBOLC()
{
	if(m_Source_p != NULL)
		delete m_Source_p;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_EXTERNALLY_DEFINED_SYMBOLC.cpp						作成日：2000.04.17

	１．機能概要
		エンティティのパラメタ設定

	２．インターフェイス
		int		SXFMapE_EXTERNALLY_DEFINED_SYMBOLC::SetParameter()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
int SXFMapE_EXTERNALLY_DEFINED_SYMBOLC::SetParameter( )
{

//#1526 = EXTERNALLY_DEFINED_SYMBOL(IDENTIFIER('open arrow'), #1525);

	int ircode;

	SXFMapEntAConvC convent(m_EntityArray);

	CString tempstring;
	//引数エラー
	if ( convent.GetSelectCString(0, "IDENTIFIER", tempstring )<0) {
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	tempstring.TrimLeft("'");
	tempstring.TrimRight("'");
	m_Name = tempstring;

//    int left = tempstring.Find('\'');
//    int right = tempstring.Find('\'',left);

//    m_Name = tempstring.Mid(left+1,right-left-1);
//    m_Name.TrimLeft();
//    m_Name.TrimRight();

//	m_Name.TrimLeft("'");
//	m_Name.TrimRight("'");

	//引数エラー
	if(m_Name.IsEmpty()){
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	//引数エラー
	if ( convent.GetInst(1,m_Source_Inst) < 0 ){
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	//オブジェクト生成
	m_Source_p = new SXFMapE_EXTERNAL_SOURCEC(m_InstanceIDManager);

	ircode = m_Source_p->SetRootID(m_Source_Inst);
	if ( ircode < 0 )
		return ircode ;
	ircode = m_Source_p->SetParameter();
	if ( ircode < 0 )
	        return ircode ;

	return 0;
}
