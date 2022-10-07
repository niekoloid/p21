/**
	All Rights Reserved,(c) JACIC 2001
	ファイル名				作成日：2000.04.23
	SXFCKSchemaC.cpp

	１．機能概要
	　　Part21インスタンスのチェックを行う。

	２．履歴
	履歴番号		日付け		担当者		概要
	作成		2000.04.23	　藤本(FQS)	　　なし。

**/
#include "stdafx.h"
#include "SXFCKSchemaC.h"
#include "SXFErrorMsgC.h"
#include "iostream"
#include "SXFComndef.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	ファイル名				作成日：2000.04.23
	SXFCKSchemaC.cpp

  　１．機能概要
	    デフォルトコンストラクタ

	２．インターフェイス
	SXFCKSchemaC::SXFCKSchemaC()

	引数：	型	引数名		内容
			なし。

  　復帰値：なし。

	３．履歴
	履歴番号		日付け		担当者		概要
	作成		2000.04.23	　　藤本(FQS)	なし。
**/
SXFCKSchemaC::SXFCKSchemaC()
{
	SetupBasicType();
	SetupExtraType();
	for(POSITION pos = m_attrmap.GetStartPosition(); pos != NULL; )
	{
		CString key;
		SXFCKAttrTypeC* pa;
   		m_attrmap.GetNextAssoc( pos, key, (void*&)pa );
		pa->Initialize();
	}
}

/**
	All Rights Reserved,(c) JACIC 2001
	ファイル名				作成日：2000.04.23
	SXFCKSchemaC.cpp

	１．機能概要
	　　デフォルトデストラクタ

	２．インターフェイス
		SXFCKSchemaC::~SXFCKSchemaC()

	引数：	型	引数名		内容
	　　　　なし。

	復帰値：なし。

	３．履歴
	履歴番号		日付け		担当者		概要
	作成		2000.04.23	　　藤本(FQS)	なし。
**/
SXFCKSchemaC::~SXFCKSchemaC()
{
	for(POSITION pos = m_attrmap.GetStartPosition(); pos != NULL; )
	{
		CString key;
		SXFCKAttrTypeC* pa;
		m_attrmap.GetNextAssoc( pos, key, (void*&)pa );
		delete pa;
	}
}

/**
	All Rights Reserved,(c) JACIC 2001
	ファイル名				作成日：2000.04.23
	SXFCKSchemaC.cpp

	１．機能概要
	　　属性を追加する。

	２．インターフェイス
		void SXFCKSchemaC::AddAttr(SXFCKAttrTypeC *IN_Attr)

	引数：型				引数名		内容
		　SXFCKAttrTypeC	*IN_Attr	属性　　　　

	復帰値：なし。

	３．履歴
	履歴番号		日付け		担当者		概要
	作成		2000.04.23	　　藤本(FQS)	なし。
**/
void SXFCKSchemaC::AddAttr(SXFCKAttrTypeC *IN_Attr)
{
	m_attrmap.SetAt(IN_Attr->GetName(), IN_Attr);
}

/**
	All Rights Reserved,(c) JACIC 2001
	ファイル名				作成日：2000.04.23
	SXFCKSchemaC.cpp

	１．機能概要
	　　属性の型を取得する。

	２．インターフェイス
		SXFCKAttrTypeC *SXFCKSchemaC::GetAttr(LPCTSTR IN_name)

	引数：型		引数名		内容
		　LPCTSTR	IN_name		属性名　　　　

	復帰値：入力された属性名があれば、属性の型を返却する。
			ない時は、NULLを返却する。

	３．履歴
	履歴番号		日付け		担当者		概要
	作成		2000.04.23	　　藤本(FQS)	なし。
**/
SXFCKAttrTypeC *SXFCKSchemaC::GetAttr(LPCTSTR IN_name)
{
	SXFCKAttrTypeC* pa;
	if (!m_attrmap.Lookup(IN_name, (void*&)pa )) {
		return NULL;
	}
	return pa;
}

/**
	All Rights Reserved,(c) JACIC 2001
	ファイル名				作成日：2000.04.23
	SXFCKSchemaC.cpp

	１．機能概要
	　　データ型の属性追加。

	２．インターフェイス
		void SXFCKSchemaC::SetupBasicType()

	引数：型		引数名		内容
		　なし。

	復帰値：なし。

	３．履歴
	履歴番号		日付け		担当者		概要
	作成		2000.04.23	　　藤本(FQS)	なし。
**/
void SXFCKSchemaC::SetupBasicType()
{
	AddAttr(new SXFCKIntegerC(this));
	AddAttr(new SXFCKRealC(this));
	AddAttr(new SXFCBooleanC(this));
	AddAttr(new SXFCStringC(this));
	AddAttr(new SXFCLogicalC(this));
	AddAttr(new SXFCSetC(this));
	AddAttr(new SXFCBagC(this));
	AddAttr(new SXFCArrayC(this));
	AddAttr(new SXFCListC(this));
}

/**
	All Rights Reserved,(c) JACIC 2001
	ファイル名				作成日：2000.04.23
	SXFCKSchemaC.cpp

	１．機能概要
	　　属性のリンク

	２．インターフェイス
		BOOL SXFCKSchemaC::LinkAttr(SXFCKAttrLink *IN_AttrLink)

	引数：型			引数名			内容
		  SXFCKAttrLink *IN_AttrLink

	復帰値：

	３．履歴
	履歴番号		日付け		担当者		概要
	作成		2000.04.23	　　藤本(FQS)	なし。
**/
BOOL SXFCKSchemaC::LinkAttr(SXFCKAttrLink *IN_AttrLink)
{
	SXFCKAttrTypeC* pa;
   	if (!m_attrmap.Lookup(IN_AttrLink->m_typename, (void*&)pa )) {
		SXFTokenC	tok;
		tok.Set(IN_AttrLink->m_typename);
		tok.GetToken();
		SXFCAggrC *aggr = NULL;
		if (tok.m_string.Compare("SET") == 0) {
			aggr = new SXFCSetC(this);
		}
		else if (tok.m_string.Compare("BAG") == 0) {
			aggr = new SXFCBagC(this);
		}
		else if (tok.m_string.Compare("ARRAY") == 0) {
			aggr = new SXFCArrayC(this);
		}
		else if (tok.m_string.Compare("LIST") == 0) {
			aggr = new SXFCListC(this);
		}
		else {
			CString	s;
//			s.Format("%sが存在しません", IN_AttrLink->m_typename);
//			AfxMessageBox(s);
			return FALSE;
		}
		if (aggr) {
			tok.GetToken();	// [
			tok.GetToken();	// num
			if (tok.m_Type == SXFTokenC::T_INTEGER) {
				aggr->m_lower = atoi(tok.m_string);
			}
			else {
				aggr->m_lower = -1;
			}
			tok.GetToken();	// :
			tok.GetToken();	// num
			if (tok.m_Type == SXFTokenC::T_INTEGER) {
				aggr->m_upper = atoi(tok.m_string);
			}
			else {
				aggr->m_upper = -1;
			}
			tok.GetToken();	// ]
			tok.GetToken();	// OF
			tok.GetToken();	// Element
			aggr->m_element.m_typename = tok.m_string;
			if (!LinkAttr(&aggr->m_element)) {
				return FALSE;
			}
			IN_AttrLink->m_attr = aggr;
			IN_AttrLink->m_deletable = TRUE;
			return TRUE;
		}
		return FALSE;
	}
	IN_AttrLink->m_attr = pa;
	return TRUE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	ファイル名				作成日：2000.04.23
	SXFCKSchemaC.cpp

	１．機能概要
	　　エンティティデータのチェック

	２．インターフェイス
		BOOL SXFCKSchemaC::Check(SXFMainContextC *IN_mc, SXFEntityDataC *IN_entity)

	引数：型				引数名			内容
		  SXFMainContextC	*IN_mc			
		  SXFEntityDataC	*IN_entity		エンティティデータ

	復帰値：

	３．履歴
	履歴番号		日付け		担当者		概要
	作成		2000.04.23	　　藤本(FQS)	なし。
**/
BOOL SXFCKSchemaC::Check(SXFMainContextC *IN_mc, SXFEntityDataC *IN_entity)
{
	SXFCheckContext	context(IN_mc);
	context.SetInstanceInfo(IN_entity->m_InstanceID, IN_entity->m_EntityName);
	context.Set(IN_entity->m_EntityDataPtr);
	context.GetToken();
	BOOL bRet = TRUE;
	if (IN_entity->m_EntityName.Compare(DEF_SXF_COMPLEX_INSTANCE) == 0) {
		bRet = CheckComplexInstance(IN_entity, &context, NULL);
	}
	else {
		bRet = CheckSingleInstance(IN_entity, &context);
	}
	if (bRet == FALSE) {
		// 2012.07.03
		if (!(context.m_entityname.Compare(DEF_STYLED_ITEM) == 0 && context.m_error_code == SXFSYNTAX1)) {
			IN_mc->OnError(context.m_instanceID, context.m_entityname, context.m_error_code, context.m_param_string);
		}
	}
	return bRet;
}

/**
	All Rights Reserved,(c) JACIC 2001
	ファイル名				作成日：2000.04.23
	SXFCKSchemaC.cpp

	１．機能概要
		複合インスタンスでないエンティティデータのチェックを行う。	　　

	２．インターフェイス
		BOOL SXFCKSchemaC::CheckSingleInstance(SXFEntityDataC *IN_entity, 
											   SXFCheckContext *IN_context)

	引数：型				引数名			内容
		  SXFEntityDataC	*IN_entity
		  SXFCheckContext	*IN_context

	復帰値：

	３．履歴
	履歴番号		日付け		担当者		概要
	作成		2000.04.23	　　藤本(FQS)	なし。
**/
BOOL SXFCKSchemaC::CheckSingleInstance(SXFEntityDataC *IN_entity, SXFCheckContext *IN_context)
{
	// ENTITY存在チェック
	SXFCKAttrTypeC* ent = GetAttr(IN_entity->m_EntityName);
	SXFCKValue	val;
	if (ent == NULL) {
		IN_context->Output(SXFNOSCHEMA, 3, IN_entity->m_EntityName);
		return FALSE;
	}
	if (!ent->Check(IN_entity, IN_context, &val)) {
		return FALSE;
	}

	return TRUE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	ファイル名				作成日：2000.04.23
	SXFCKSchemaC.cpp

	１．機能概要
	　　複合インスタンスのチェックを行う。

	２．インターフェイス
		BOOL SXFCKSchemaC::CheckComplexInstance(SXFEntityDataC *IN_entity, 
												SXFCheckContext *IN_context, 
												CArray<SXFCKEntityC*, SXFCKEntityC*> *IN_ents)

	引数：型									引数名			内容
		　SXFEntityDataC						*IN_entity 
		　SXFCheckContext						*IN_context 
		　CArray<SXFCKEntityC*, SXFCKEntityC*>	*IN_ents

  　復帰値：

	３．履歴
	履歴番号		日付け		担当者		概要
	作成		2000.04.23	　　藤本(FQS)	なし。
**/
BOOL SXFCKSchemaC::CheckComplexInstance(SXFEntityDataC *IN_entity, SXFCheckContext *IN_context, CArray<SXFCKEntityC*,SXFCKEntityC*> *IN_ents)
{
	SXFCKValue	val;
	// (ではじまる
	if (!IN_context->Is("(")) {
		IN_context->Output(SXFSYNTAX1, 2 , IN_entity->m_EntityName);
		return FALSE;
	}
	IN_context->GetToken();
	while (1) {
		if (!IN_context->IsString()) {
			// Error
			IN_context->Output(SXFNODICT, 2, IN_context->m_string);
			return FALSE;
		}
		// ENTITY存在チェック
		SXFCKEntityC* ent = (SXFCKEntityC*)GetAttr(IN_context->m_string);
		if (ent == NULL) {

			IN_context->Output(SXFNOSCHEMA, 3, IN_entity->m_EntityName);
			return FALSE;
		}
		IN_context->GetToken();
		if (!ent->CheckEntity(IN_entity, IN_context, TRUE, &val)) {
			return FALSE;
		}
		if (IN_ents) {
			// リストに追加
			IN_ents->Add(ent);
		}
		// , か)
		if (IN_context->Is(")")) {
			// 最後：)
			break;
		}
	}
	IN_context->GetToken();
	return TRUE;
}
//------------------------------------------------------------------------
/**
	All Rights Reserved,(c) JACIC 2001
	ファイル名				作成日：2000.04.23
	SXFCKSchemaC.cpp

	１．機能概要

	２．履歴
	履歴番号		日付け		担当者		概要
	作成		2000.04.23	　藤本(FQS)	　　なし。

**/
#include <stdarg.h>
/**
	All Rights Reserved,(c) JACIC 2001
	ファイル名				作成日：2000.04.23
	SXFCKSchemaC.cpp

	１．機能概要
	　　

	２．インターフェイス
		void SXFCheckContext::Output(SXFErrorCode error_code, 
									 int param_num, 
									 LPCTSTR param_string)


	引数：型			引数名			内容
		  SXFErrorCode	error_code		エラーコード 
		  int			param_num		エラー出力に必要なパラメータの個数
		  LPCTSTR		param_string	エンティティ名、インスタンスID以外に
										エラーメッセージに必要な文字列

  　復帰値：なし。

	３．履歴
	履歴番号		日付け		担当者		概要
	作成		2000.04.23	　　藤本(FQS)	なし。
**/
void SXFCheckContext::Output(SXFErrorCode error_code, int param_num, LPCTSTR param_string)
{
	m_error_code = error_code;
	m_param_num = param_num;
	m_param_string = param_string;
}

//////////////////////////////////////////////////////////////////////
// SXFCKAttrTypeC
//////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////
// SXFCKEntityC
//////////////////////////////////////////////////////////////////////
/**
	All Rights Reserved,(c) JACIC 2001
	ファイル名				作成日：2000.04.23
	SXFCKSchemaC.cpp

	１．機能概要
	　　Part21インスタンスのチェックを行う。

	２．履歴
	履歴番号		日付け		担当者		概要
	作成		2000.04.23	　藤本(FQS)	　　なし。

**/
/**
	All Rights Reserved,(c) JACIC 2001
	ファイル名				作成日：2000.04.23
	SXFCKSchemaC.cpp

	１．機能概要
	　　デフォルトデストラクタ

	２．インターフェイス
		SXFCKEntityC::~SXFCKEntityC()

	引数：	型	引数名		内容
	　　　　なし。

	復帰値：なし。

	３．履歴
	履歴番号		日付け		担当者		概要
	作成		2000.04.23	　　藤本(FQS)	なし。
**/
SXFCKEntityC::~SXFCKEntityC()
{
//	for (int i = 0; i < m_supers.GetSize(); i++) {
//		delete m_supers[i];
//	}
	for(POSITION pos = m_supers.GetHeadPosition(); pos; ) {
		delete m_supers.GetNext(pos) ;
	}
	m_supers.RemoveAll();
//	for (i = 0; i < m_attrs.GetSize(); i++) {
//		delete m_attrs[i];
//	}
	for(pos = m_attrs.GetHeadPosition(); pos; ) {
		delete m_attrs.GetNext(pos) ;
	}
	m_attrs.RemoveAll();
//	for (i = 0; i < m_deriveattrs.GetSize(); i++) {
//		delete m_deriveattrs[i];
//	}
	for(pos = m_deriveattrs.GetHeadPosition(); pos; ) {
		delete m_deriveattrs.GetNext(pos) ;
	}
	m_deriveattrs.RemoveAll();
}

/**
	All Rights Reserved,(c) JACIC 2001
	ファイル名				作成日：2000.04.23
	SXFCKSchemaC.cpp

	１．機能概要
	　　初期化を行う。

	２．インターフェイス
		BOOL SXFCKEntityC::Initialize()

	引数：	型	引数名		内容
	　　　　なし。

	復帰値：

	３．履歴
	履歴番号		日付け		担当者		概要
	作成		2000.04.23	　　藤本(FQS)	なし。
**/
BOOL SXFCKEntityC::Initialize()
{
	BOOL bRet = TRUE;
//	for (int i = 0; i < m_supers.GetSize(); i++) {
//		if (!m_schema->LinkAttr(m_supers[i])) bRet = FALSE;
//	}
	for(POSITION pos = m_supers.GetHeadPosition(); pos; ) {
		if (!m_schema->LinkAttr(m_supers.GetNext(pos)) )
			bRet = FALSE;
	}
//	for (i = 0; i < m_attrs.GetSize(); i++) {
//		if (!m_schema->LinkAttr(m_attrs[i])) bRet = FALSE;
//	}
	for(pos = m_attrs.GetHeadPosition(); pos; ) {
		if (!m_schema->LinkAttr(m_attrs.GetNext(pos)) )
			bRet = FALSE;
	}
	return bRet;
}

/**
	All Rights Reserved,(c) JACIC 2001
	ファイル名				作成日：2000.04.23
	SXFCKSchemaC.cpp

	１．機能概要
		マージした属性を取得する。

	２．インターフェイス
		void SXFCKEntityC::GetMargedArgs(CArray<SXFCKAttrLink*,SXFCKAttrLink*> &IO_args)

	引数：型									引数名		内容
		　CArray<SXFCKAttrLink*,SXFCKAttrLink*> &IO_args	属性	　　　　

	復帰値：なし。

	３．履歴
	履歴番号		日付け		担当者		概要
	作成		2000.04.23	　　藤本(FQS)	なし。
**/
void SXFCKEntityC::GetMargedArgs(CArray<SXFCKAttrLink*,SXFCKAttrLink*> &IO_args)
{
//	for (int i = 0; i < m_supers.GetSize(); i++) {
//		SXFCKEntityC *super = (SXFCKEntityC*)m_supers[i]->m_attr;
	for(POSITION pos = m_supers.GetHeadPosition(); pos; ) {
		SXFCKEntityC *super = (SXFCKEntityC*)m_supers.GetNext(pos)->m_attr ;
		super->GetMargedArgs(IO_args);
	}
//	for (int ia = 0; ia < m_attrs.GetSize(); ia++) {
//		SXFCKAttrLink *al = m_attrs[ia];
	for(pos = m_attrs.GetHeadPosition(); pos; ) {
		SXFCKAttrLink *al = m_attrs.GetNext(pos) ;
		BOOL ok = TRUE;
		for (int is = 0; is < IO_args.GetSize(); is++) {
			SXFCKAttrLink *as = IO_args[is];
			if (as->m_attrname.Compare(al->m_attrname) == 0) {
				// 同じ属性がある
				ok = FALSE;
				break;
			}
		}
		if (ok) {
			// 追加
//			IO_args.Add(m_attrs[ia]);
			IO_args.Add(al);
		}
	}
}

/**
	All Rights Reserved,(c) JACIC 2001
	ファイル名				作成日：2000.04.23
	SXFCKSchemaC.cpp

	１．機能概要
	　　サブタイプかどうかの判定

	２．インターフェイス
		BOOL SXFCKEntityC::IsSubclassOf(SXFCKEntityC *IN_ent)

	引数：	型				引数名		内容
	　　　　SXFCKEntityC	*IN_ent		エンティティ

	復帰値：サブタイプであれば、TRUE
		　	そうでない時は、FALSE

	３．履歴
	履歴番号		日付け		担当者		概要
	作成		2000.04.23	　　藤本(FQS)	なし。
**/
BOOL SXFCKEntityC::IsSubclassOf(SXFCKEntityC *IN_ent)
{
	if (IN_ent == this) {
		return TRUE;
	}
//	for (int i = 0; i < m_supers.GetSize(); i++) {
//		SXFCKEntityC *super = (SXFCKEntityC*)m_supers[i]->m_attr;
	for(POSITION pos = m_supers.GetHeadPosition(); pos; ) {
		SXFCKEntityC *super = (SXFCKEntityC*)m_supers.GetNext(pos)->m_attr ;
		if (super->IsSubclassOf(IN_ent)) {
			return TRUE;
		}
	}
	return FALSE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	ファイル名				作成日：2000.04.23
	SXFCKSchemaC.cpp

	１．機能概要
	　　エンティティのチェックを行う。

	２．インターフェイス
		BOOL SXFCKEntityC::Check(SXFEntityDataC *IN_entity, 
								 SXFCheckContext *IN_context, 
								 SXFCKValue *val)

  　引数：型				引数名		内容
		　SXFEntityDataC	*IN_entity	エンティティ 
		　SXFCheckContext	*IN_context インスタンスデータ
		　SXFCKValue		*val		値

	復帰値：

	３．履歴
	履歴番号		日付け		担当者		概要
	作成		2000.04.23	　　藤本(FQS)	なし。
**/
BOOL SXFCKEntityC::Check(SXFEntityDataC *IN_entity, SXFCheckContext *IN_context, SXFCKValue *val)
{
	return CheckEntity(IN_entity, IN_context, FALSE, val);
}

/**
	All Rights Reserved,(c) JACIC 2001
	ファイル名				作成日：2000.04.23
	SXFCKSchemaC.cpp

	１．機能概要
	　　エンティティのチェックを行う。

	２．インターフェイス
		BOOL SXFCKEntityC::CheckEntity(SXFEntityDataC *IN_entity, 
									　 SXFCheckContext *IN_context, 
									　 BOOL IN_bComplex, SXFCKValue *val)

  　引数：型				引数名		内容
		　SXFEntityDataC	*IN_entity	エンティティ
		　SXFCheckContext	*IN_context インスタンスデータ
		　SXFCKValue		*val		値

	復帰値：インスタンスデータが正しければ、TRUE
			正しくなければ、FALSE

	３．履歴
	履歴番号		日付け		担当者		概要
	作成		2000.04.23	　　藤本(FQS)	なし。
**/
BOOL SXFCKEntityC::CheckEntity(SXFEntityDataC *IN_entity, SXFCheckContext *IN_context, BOOL IN_bComplex, SXFCKValue *val)
{
	if (IN_context->IsID()) {
		// #ID
		int InstanceID = atoi((LPCTSTR)IN_context->m_string + 1);
		IN_context->m_MainContext->RefInstance(InstanceID);
		// #ID存在チェック
		SXFEntityDataC *ent = m_schema->m_manager->Lookup(InstanceID);
		if (ent == NULL) {
			char buf[10];
			//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
			//IN_context->Output(SXFINSTNOTHING, 4, _itoa(InstanceID, buf, 10));
			_itoa_s(InstanceID, buf, _countof(buf), 10);
			IN_context->Output(SXFINSTNOTHING, 4, buf);
			return FALSE;
		}
		if (ent->m_EntityName.Compare(DEF_SXF_COMPLEX_INSTANCE) == 0) {
			// 複合インスタンスチェック
			//
			SXFCheckContext	context(IN_context->m_MainContext);
			context.Set(ent->m_EntityDataPtr);
			context.GetToken();
			CArray<SXFCKEntityC*,SXFCKEntityC*>	ents;
			if (!m_schema->CheckComplexInstance(ent, &context, &ents)) {
				char buf[10];
				//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
				//IN_context->Output(SXFCOMPINST1, 2, _itoa(InstanceID, buf, 10));
				_itoa_s(InstanceID, buf, _countof(buf), 10);
				IN_context->Output(SXFCOMPINST1, 2, buf);
				return FALSE;
			}
			//
			BOOL bOK = FALSE;
			for (int i = 0; i < ents.GetSize(); i++) {
				SXFCKEntityC *ea = ents[i];
				if (ea->IsSubclassOf(this)) {
					// 該当するクラス発見
					bOK = TRUE;
				}
			}
			if (!bOK) {
				char buf[10];
				//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
				//IN_context->Output(SXFCOMPINST2, 3, _itoa(InstanceID, buf, 10) );
				_itoa_s(InstanceID, buf, _countof(buf), 10);
				IN_context->Output(SXFCOMPINST2, 3, buf);
				return FALSE;
			}
			//
			val->SetInstance(InstanceID);
			IN_context->GetToken();
			return TRUE;
		}
		else {
			// #IDクラス存在チェック
			SXFCKEntityC *ea = (SXFCKEntityC*)m_schema->GetAttr(ent->m_EntityName);
			if (ea == NULL) {
				char buf[10];
				//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
				//IN_context->Output(SXFNOINSTCLASS, 3, _itoa(ent->m_InstanceID, buf, 10));
				_itoa_s(ent->m_InstanceID, buf, _countof(buf), 10);
				IN_context->Output(SXFNOINSTCLASS, 3, buf);
				return FALSE;
			}
			if (!ea->IsSubclassOf(this)) {
				char buf[10];
				//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
				//IN_context->Output(SXFNOINSTCLASS, 3, _itoa(InstanceID, buf, 10) );
				_itoa_s(InstanceID, buf, _countof(buf), 10);
				IN_context->Output(SXFNOINSTCLASS, 3, buf);
				return FALSE;
			}
			val->SetInstance(InstanceID);
			IN_context->GetToken();
			return TRUE;
		}
	}
	// (からはじまる
	else if (!IN_context->Is("(")) {
		IN_context->Output(SXFSYNTAX1, 2 , "");
		return FALSE;
	}
	IN_context->GetToken();


	/*	==>	Commented by S.Kakizawa(KLS) on 2006/01/11	//
	CArray<SXFCKAttrLink*,SXFCKAttrLink*> args;
	/*	<==	Commented by S.Kakizawa(KLS) on 2006/01/11	*/
	/*	==>	Modified by S.Kakizawa(KLS) on 2006/01/11	*/
	CArray<SXFCKAttrLink*,SXFCKAttrLink*>& args	= m_args;
	if( m_notArgs )
	{
		m_notArgs = FALSE;
	/*	<==	Modified by S.Kakizawa(KLS) on 2006/01/11	*/

		if (IN_bComplex) {
	//		for (int ia = 0; ia < m_attrs.GetSize(); ia++) {
	//			SXFCKAttrLink *al = m_attrs[ia];
	//			args.Add(m_attrs[ia]);
			for(POSITION pos = m_attrs.GetHeadPosition(); pos; ) {
				SXFCKAttrLink *al = m_attrs.GetNext(pos) ;
				args.Add(al);
			}
		}
		else {
			GetMargedArgs(args);
		}
	/*	==>	Added by S.Kakizawa(KLS) on 2006/01/11	*/
	}
	/*	<==	Added by S.Kakizawa(KLS) on 2006/01/11	*/

	for (int i = 0; i < args.GetSize(); i++) {
		SXFCKAttrLink	*al = args[i];
		SXFCKAttrTypeC *at = al->m_attr;
		DWORD			flags = al->m_flags;
		if (at == NULL) {
			return FALSE;
		}
		if (IN_context->Is(DEF_DOLLAR)) {
			// OPTIONAL宣言された属性は、Part21インスタンスでは、省略可能になり、
			// 省略された時は、$が入る。
			// （省略されていない時は、本来の値が入る。）
			if (!(flags & SXFCKAttrLink::FLAG_OPTIONAL)) {
				IN_context->Output(SXFATTROPTIONAL, 2, IN_context->m_string);
				return FALSE;
			}
			IN_context->GetToken();
		}
		else if (IN_context->Is("*")) {
			// 自分のSUPERTYPEの属性をDERIVEの中で再定義した時は、
			// SUPERTYPEの属性のインスタンスに｢*｣が入っても良い。
			// とりあえず、DERIVE属性のあるものには＊を許す
//			if (!(flags & SXFCKAttrLink::FLAG_DERIVE) ) {
//				IN_context->Output(SXFATTRDERIVE, 3, IN_context->m_string );
//				return FALSE;
//			}
			IN_context->GetToken();
		}
		else {
			if (!at->Check(IN_entity, IN_context, val)) {
				return FALSE;
			}
		}
		// UNIQUE
		if (flags & SXFCKAttrLink::FLAG_UNIQUE) {
			// 
			// UNIQUEは保留
		}

		// , か)
		if (i == args.GetSize()-1) {
			// 最後：)
			if (IN_context->Is(",")) {
				IN_context->Output(SXFPARAMM, 2, "");
				return FALSE;
			}
			else if (!IN_context->Is(")")) {
				IN_context->Output(SXFSYNTAX2, 2, "");
				return FALSE;
			}
			break;
		}
		else {
			// 途中：,
			if (IN_context->Is(")")) {
				IN_context->Output(SXFPARAMS, 2, "");
				return FALSE;
			}
			else if (!IN_context->Is(",")) {
				IN_context->Output(SXFSYNTAX3, 2, "");
				return FALSE;
			}
		}
		IN_context->GetToken();
	}
	IN_context->GetToken();

	return TRUE;
}

//------------------------------------------------------------------------------
/**
	All Rights Reserved,(c) JACIC 2001
	ファイル名				作成日：2000.04.23
	SXFCKSchemaC.cpp

	１．機能概要
	　　データが文字列型かを判定する。

	２．履歴
	履歴番号		日付け		担当者		概要
	作成		2000.04.23	　藤本(FQS)	　　なし。

**/
//-----------------------------------------------------------------------------
/**
	All Rights Reserved,(c) JACIC 2001
	ファイル名				作成日：2000.04.23
	SXFCKSchemaC.cpp

	１．機能概要
	　　入力されたパラメータが文字列型かをチェックする。

	２．インターフェイス
		BOOL SXFCStringC::Check(SXFEntityDataC *IN_entity,
								SXFCheckContext *IN_context, 
								SXFCKValue *val)

  　引数：型				引数名		内容
		　SXFEntityDataC	*IN_entity	エンティティ
		　SXFCheckContext	*IN_context インスタンスデータ
		　SXFCKValue		*val		値

	復帰値：入力されたパラメータが文字列型の時は、TRUE。
			そうでない時は、FALSE。

	３．履歴
	履歴番号		日付け		担当者		概要
	作成		2000.04.23	　　藤本(FQS)	なし。
**/
BOOL SXFCStringC::Check(SXFEntityDataC *IN_entity,
						SXFCheckContext *IN_context, 
						SXFCKValue *val)
{
	if (!IN_context->IsString()) {

		IN_context->Output(SXFTYPESTRING, 3, IN_context->m_string);
		return FALSE;
	}
	val->SetString(IN_context->m_string);
	IN_context->GetToken();
	return TRUE;
}

//------------------------------------------------------------------------------
/**
	All Rights Reserved,(c) JACIC 2001
	ファイル名				作成日：2000.04.23
	SXFCKSchemaC.cpp

	１．機能概要
	　　データが整数型かを判定する。

	２．履歴
	履歴番号		日付け		担当者		概要
	作成		2000.04.23	　藤本(FQS)	　　なし。

**/
//------------------------------------------------------------------------------
/**
	All Rights Reserved,(c) JACIC 2001
	ファイル名				作成日：2000.04.23
	SXFCKSchemaC.cpp

	１．機能概要
	　　入力されたパラメータが整数型かをチェックする。

	２．インターフェイス
		BOOL SXFCKIntegerC::Check(SXFEntityDataC *IN_entity,
								　SXFCheckContext *IN_context, 
								　SXFCKValue *val)

  　引数：型				引数名		内容
		　SXFEntityDataC	*IN_entity  エンティティ名
		　SXFCheckContext	*IN_context インスタンスデータ
		　SXFCKValue		*val		値

	復帰値：入力されたパラメータが整数型の時は、TRUE。
			そうでない時は、FALSE。

	３．履歴
	履歴番号		日付け		担当者		概要
	作成		2000.04.23	　　藤本(FQS)	なし。
**/
BOOL SXFCKIntegerC::Check(SXFEntityDataC *IN_entity,SXFCheckContext *IN_context, SXFCKValue *val)
{
	if (!IN_context->IsInteger()) {
		IN_context->Output(SXFTYPEINTEGER, 3, IN_context->m_string);
		return FALSE;
	}
	val->SetInteger(atoi(IN_context->m_string));
	IN_context->GetToken();
	return TRUE;
}

//------------------------------------------------------------------------------
/**
	All Rights Reserved,(c) JACIC 2001
	ファイル名				作成日：2000.04.23
	SXFCKSchemaC.cpp

	１．機能概要
	　　データが実数型かを判定する。

	２．履歴
	履歴番号		日付け		担当者		概要
	作成		2000.04.23	　藤本(FQS)	　　なし。

**/
//---------------------------------------------------------------------------
/**
	All Rights Reserved,(c) JACIC 2001
	ファイル名				作成日：2000.04.23
	SXFCKSchemaC.cpp

	１．機能概要
	　　入力されたパラメータが実数型かをチェックする。

	２．インターフェイス
		BOOL SXFCKRealC::Check(SXFEntityDataC *IN_entity, 
							　 SXFCheckContext *IN_context, 
							   SXFCKValue *val)

  　引数：型				引数名		内容
		　SXFEntityDataC	*IN_entity  エンティティ名
		　SXFCheckContext	*IN_context インスタンスデータ
		　SXFCKValue		*val　　　　値

	復帰値：入力されたパラメータが実数型の時は、TRUE。
			そうでない時は、FALSE。

	３．履歴
	履歴番号		日付け		担当者		概要
	作成		2000.04.23	　　藤本(FQS)	なし。
**/
BOOL SXFCKRealC::Check(SXFEntityDataC *IN_entity, SXFCheckContext *IN_context, SXFCKValue *val)
{
	if (!IN_context->IsReal()) {
		IN_context->Output(SXFTYPEREAL, 3, IN_context->m_string);
		return FALSE;
	}
	val->SetReal(atof(IN_context->m_string));
	IN_context->GetToken();
	return TRUE;
}

//------------------------------------------------------------------------------
/**
	All Rights Reserved,(c) JACIC 2001
	ファイル名				作成日：2000.04.23
	SXFCKSchemaC.cpp

	１．機能概要
	　　データがBOOL型かを判定する。

	２．履歴
	履歴番号		日付け		担当者		概要
	作成		2000.04.23	　藤本(FQS)	　　なし。

**/
//---------------------------------------------------------------------------
/**
	All Rights Reserved,(c) JACIC 2001
	ファイル名				作成日：2000.04.23
	SXFCKSchemaC.cpp

	１．機能概要
	　　入力されたパラメータがBOOL型かをチェックする。

	２．インターフェイス
		BOOL SXFCBooleanC::Check(SXFEntityDataC *IN_entity, 
								 SXFCheckContext *IN_context, 
								 SXFCKValue *val)

  　引数：型				引数名		内容
		　SXFEntityDataC	*IN_entity  エンティティ名
		　SXFCheckContext	*IN_context インスタンスデータ
		　SXFCKValue		*val　　　　値

	復帰値：入力されたパラメータがBOOL型の時は、TRUE。
			そうでない時は、FALSE。

	３．履歴
	履歴番号		日付け		担当者		概要
	作成		2000.04.23	　　藤本(FQS)	なし。
**/
BOOL SXFCBooleanC::Check(SXFEntityDataC *IN_entity, SXFCheckContext *IN_context, SXFCKValue *val)
{
	char	bval;
	BOOL bRet = FALSE;
	if (IN_context->Is(".")) {
		IN_context->GetToken();	// T F
		if (IN_context->Is("T") || IN_context->Is("F")) {
			bval = IN_context->m_string.GetAt(0);
			IN_context->GetToken();
			if (IN_context->Is(".")) {	// .
				bRet = TRUE;
			}
		}
	}
	if (bRet == FALSE) {
		IN_context->Output(SXFTYPEBOOLEAN, 3, IN_context->m_string);
		return FALSE;
	}
	val->SetBoolean(bval);
	IN_context->GetToken();
	return TRUE;
}

//------------------------------------------------------------------------------
/**
	All Rights Reserved,(c) JACIC 2001
	ファイル名				作成日：2000.04.23
	SXFCKSchemaC.cpp

	１．機能概要
	　　データがLOGICAL型かを判定する。

	２．履歴
	履歴番号		日付け		担当者		概要
	作成		2000.04.23	　藤本(FQS)	　　なし。

**/
//---------------------------------------------------------------------------
/**
	All Rights Reserved,(c) JACIC 2001
	ファイル名				作成日：2000.04.23
	SXFCKSchemaC.cpp

	１．機能概要
	　　入力されたパラメータがLOGICAL型かをチェックする。

	２．インターフェイス
		BOOL SXFCLogicalC::Check(SXFEntityDataC *IN_entity, 
								 SXFCheckContext *IN_context, 
								 SXFCKValue *val)

  　引数：型				引数名		内容
		　SXFEntityDataC	*IN_entity  エンティティ名
		　SXFCheckContext	*IN_context インスタンスデータ
		　SXFCKValue		*val　　　　値

	復帰値：入力されたパラメータがLOGICAL型の時は、TRUE。
			そうでない時は、FALSE。

	３．履歴
	履歴番号		日付け		担当者		概要
	作成		2000.04.23	　　藤本(FQS)	なし。
**/
BOOL SXFCLogicalC::Check(SXFEntityDataC *IN_entity, SXFCheckContext *IN_context, SXFCKValue *val)
{
	BOOL bRet = FALSE;
	char	lval;
	if (IN_context->Is(".")) {
		IN_context->GetToken();	// T F U
		if (IN_context->Is("T") || IN_context->Is("F") || IN_context->Is("U")) {
			lval = IN_context->m_string.GetAt(0);
			IN_context->GetToken();
			if (IN_context->Is(".")) {	// .
				bRet = TRUE;
			}
		}
	}
	if (bRet == FALSE) {
		IN_context->Output(SXFTYPELOGICAL, 3, IN_context->m_string);
		return FALSE;
	}
	val->SetLogical(lval);
	IN_context->GetToken();
	return TRUE;
}

//------------------------------------------------------------------------------
/**
	All Rights Reserved,(c) JACIC 2001
	ファイル名				作成日：2000.04.23
	SXFCKSchemaC.cpp

	１．機能概要
	　　データが集合体型かを判定する。

	２．履歴
	履歴番号		日付け		担当者		概要
	作成		2000.04.23	　藤本(FQS)	　　なし。

**/
//---------------------------------------------------------------------------
/**
	All Rights Reserved,(c) JACIC 2001
	ファイル名				作成日：2000.04.23
	SXFCKSchemaC.cpp

	１．機能概要
	　　入力されたパラメータが集合体型かをチェックする。

	２．インターフェイス
		BOOL SXFCAggrC::Check(SXFEntityDataC *IN_entity, 
							　SXFCheckContext *IN_context, 
							　SXFCKValue *val)

  　引数：型				引数名		内容
		　SXFEntityDataC	*IN_entity  エンティティ名
		　SXFCheckContext	*IN_context インスタンスデータ
		　SXFCKValue		*val　　　　値

	復帰値：入力されたパラメータが集合体型の時は、TRUE。
			そうでない時は、FALSE。

	３．履歴
	履歴番号		日付け		担当者		概要
	作成		2000.04.23	　　藤本(FQS)	なし。
**/
BOOL SXFCAggrC::Check(SXFEntityDataC *IN_entity, SXFCheckContext *IN_context, SXFCKValue *val)
{
	// (からはじまる
	if (!IN_context->Is("(")) {
		IN_context->Output(SXFSYNTAX1, 3, IN_context->m_string);
		return FALSE;
	}
	IN_context->GetToken();
	for (int count = 0;;) {
		if (IN_context->Is(")")) {
			// 最後：)
			break;
		}
		count++;
		if (!m_element.m_attr->Check(IN_entity, IN_context, val)) {
			return FALSE;
		}
		// , か)
		if (IN_context->Is(")")) {
			// 最後：)
			break;
		}
		else if (IN_context->Is(",")) {
			// 途中：,
		}
		else {
			// Error
			IN_context->Output(SXFSYNTAX4, 3, IN_context->m_string);
		}
		IN_context->GetToken();
	}
	if (m_lower >= 0) {
		if (count < m_lower) {
			// Error
			IN_context->Output(SXFAGGRPARAMS, 2, "");
			return FALSE;
		}
	}
	if (m_upper >= 0) {
		if (count > m_upper) {
			// Error
			IN_context->Output(SXFAGGRPARAMM, 2, "");
			return FALSE;
		}
	}
	val->SetAggr();
	IN_context->GetToken();
	return TRUE;
}

//------------------------------------------------------------------------------
/**
	All Rights Reserved,(c) JACIC 2001
	ファイル名				作成日：2000.04.23
	SXFCKSchemaC.cpp

	１．機能概要
	　　データが集合体型かを判定する。

	２．履歴
	履歴番号		日付け		担当者		概要
	作成		2000.04.23	　藤本(FQS)	　　なし。

**/
//---------------------------------------------------------------------------
/**
	All Rights Reserved,(c) JACIC 2001
	ファイル名				作成日：2000.04.23
	SXFCKSchemaC.cpp

	１．機能概要


	２．インターフェイス
		BOOL SXFCKTypeDefSingleC::Check(SXFEntityDataC *IN_entity, 
										SXFCheckContext *IN_context, 
										SXFCKValue *val)

  　引数：型				引数名		内容
		　SXFEntityDataC	*IN_entity  エンティティ名
		　SXFCheckContext	*IN_context インスタンスデータ
		　SXFCKValue		*val		値

	復帰値：

	３．履歴
	履歴番号		日付け		担当者		概要
	作成		2000.04.23	　　藤本(FQS)	なし。
**/
BOOL SXFCKTypeDefSingleC::Check(SXFEntityDataC *IN_entity, SXFCheckContext *IN_context, SXFCKValue *val)
{
	// Check Cast
	if (IN_context->Is(m_name)) {
		// m_name( value )の形
		IN_context->GetToken();
		if (IN_context->Is("(")) {
			// (
			IN_context->GetToken();
			if (!m_definedtype.m_attr->Check(IN_entity, IN_context, val)) {
				return FALSE;
			}
		}
		if (!IN_context->Is(")")) {
			// 最後：)
			IN_context->Output(SXFSYNTAX2, 2, "");
			return FALSE;
		}
		IN_context->GetToken();
		return TRUE;
	}
	return m_definedtype.m_attr->Check(IN_entity, IN_context, val);
}

//------------------------------------------------------------------------------
/**
	All Rights Reserved,(c) JACIC 2001
	ファイル名				作成日：2000.04.23
	SXFCKSchemaC.cpp

	１．機能概要
	　　SELECT型データを判定する。

	２．履歴
	履歴番号		日付け		担当者		概要
	作成		2000.04.23	　藤本(FQS)	　　なし。

**/
//---------------------------------------------------------------------------
/**
	All Rights Reserved,(c) JACIC 2001
	ファイル名				作成日：2000.04.23
	SXFCKSchemaC.cpp

	１．機能概要


	２．インターフェイス
		BOOL SXFCKSelectC::Initialize()

  　引数：型				引数名		内容
		　なし。

	復帰値：

	３．履歴
	履歴番号		日付け		担当者		概要
	作成		2000.04.23	　　藤本(FQS)	なし。
**/
BOOL SXFCKSelectC::Initialize()
{
	BOOL bRet = TRUE;
//	for (int i = 0; i < m_select.GetSize(); i++) {
//		if (!m_schema->LinkAttr(m_select[i])) bRet = FALSE;
	for (POSITION pos = m_select.GetHeadPosition(); pos; ) {
		if (!m_schema->LinkAttr(m_select.GetNext(pos)) )
			bRet = FALSE;
	}
	return bRet;
}

/**
	All Rights Reserved,(c) JACIC 2001
	ファイル名				作成日：2000.04.23
	SXFCKSchemaC.cpp

	１．機能概要


	２．インターフェイス
		BOOL SXFCKSelectC::Check(SXFEntityDataC *IN_entity, 
								 SXFCheckContext *IN_context, 
								 SXFCKValue *val)

  　引数：型				引数名		内容
		　SXFEntityDataC	*IN_entity	エンティティ
		　SXFCheckContext	*IN_context	インスタンスデータ
		　SXFCKValue		*val		値

  　復帰値：

	３．履歴
	履歴番号		日付け		担当者		概要
	作成		2000.04.23	　　藤本(FQS)	なし。
**/
BOOL SXFCKSelectC::Check(SXFEntityDataC *IN_entity, SXFCheckContext *IN_context, SXFCKValue *val)
{
/**	
	BOOL bRet;
	CString	s;
	CString t;
	s = IN_context->m_string;
	for (int j = 0; j < m_select.GetSize(); j++) {
		LPCTSTR sem = m_select[j]->m_typename;
		if (s.Compare(sem) == 0) {
			bRet = TRUE;
		}
	}

	for (int i = 0; i < m_select.GetSize(); i++) {
		SXFCKEntityC *sel = (SXFCKEntityC*)m_select[i]->m_attr;
		if (sel->Check(IN_entity, IN_context, val)) {
			return TRUE;
		}
	}	
	return FALSE;
	
**/	
//	for (int i = 0; i < m_select.GetSize(); i++) {
//		SXFCKEntityC *sel = (SXFCKEntityC*)m_select[i]->m_attr;
	for(POSITION pos = m_select.GetHeadPosition(); pos; ) {
		SXFCKEntityC *sel = (SXFCKEntityC*)m_select.GetNext(pos)->m_attr ;
		if (sel->Check(IN_entity, IN_context, val)) {
			return TRUE;
		}
	}
	return FALSE;

}

//------------------------------------------------------------------------------
/**
	All Rights Reserved,(c) JACIC 2001
	ファイル名				作成日：2000.04.23
	SXFCKSchemaC.cpp

	１．機能概要
	　　ENUMERATION型データを判定する。

	２．履歴
	履歴番号		日付け		担当者		概要
	作成		2000.04.23	　藤本(FQS)	　　なし。

**/
//---------------------------------------------------------------------------
/**
	All Rights Reserved,(c) JACIC 2001
	ファイル名				作成日：2000.04.23
	SXFCKSchemaC.cpp

	１．機能概要


	２．インターフェイス
		BOOL SXFCKEnumerationC::Check(SXFEntityDataC *IN_entity, 
									　SXFCheckContext *IN_context, 
									　SXFCKValue *val)

  　引数：型				引数名		内容
		　SXFEntityDataC	*IN_entity	エンティティ
		　SXFCheckContext	*IN_context インスタンスデータ
		　SXFCKValue		*val		値

	復帰値：

	３．履歴
	履歴番号		日付け		担当者		概要
	作成		2000.04.23	　　藤本(FQS)	なし。
**/
BOOL SXFCKEnumerationC::Check(SXFEntityDataC *IN_entity, SXFCheckContext *IN_context, SXFCKValue *val)
{
	BOOL bRet = FALSE;
	CString s;

	CString t;
	if (isalpha(*IN_context->m_string)){
		t = IN_context->CurText();
		IN_context->m_string = t;
		IN_context->GetToken();
		IN_context->GetToken();
	}

	if (IN_context->Is(".")) {
		IN_context->GetToken();	// T F
		if (IN_context->IsString()) {
			s = IN_context->m_string;
			IN_context->GetToken();
			if (IN_context->Is(".")) {	// .
				bRet = TRUE;
			}
		}
	}
	if (bRet == FALSE) {
		IN_context->Output(SXFTYPEENUM, 3, IN_context->m_string);
		return FALSE;
	}
//	for (int j = 0; j < m_enum.GetSize(); j++) {
//		LPCTSTR nm = m_enum[j]->m_typename;
	for (POSITION pos = m_enum.GetHeadPosition(); pos; ) {
		LPCTSTR nm = m_enum.GetNext(pos)->m_typename ;
		if (s.Compare(nm) == 0) {
			IN_context->GetToken();
			return TRUE;
		}
	}
	IN_context->Output(SXFNOENUMDEC, 3, IN_context->m_string);
	return FALSE;
}