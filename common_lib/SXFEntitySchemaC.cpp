/**
	All Rights Reserved,(c) JACIC 2001
	ファイル名				作成日：2000.04.22
	SXFEntitySchemaC.cpp

	１．クラス概要
		Part21インスタンスチェック機能を呼び出す

	２．履歴
	履歴番号		日付		担当者		概要
	作成		2000.04.22	　藤本(FQS)	　　なし。

**/
#include "stdafx.h"
#include "SXFEntitySchemaC.h"
#include "SXFErrorMsgC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

///////////////////////////////////////////////////////////////////////
class MyContextC : public SXFMainContextC
{
public:
//-----------------------------------------------------------------------------
//	エラー出力
//-----------------------------------------------------------------------------
	virtual void OnError(int IN_instanceID, 
						 LPCTSTR IN_entityname, 
						 SXFErrorCode IN_error_code, 
						 LPCTSTR IN_param_string) {
		if (IN_error_code == 2)
		{
			SXFErrorMsgC::RecordError(IN_error_code, 
								  IN_entityname, 
								  2, 
								  IN_instanceID, 
								  IN_entityname
								  );
		}
		else{
			SXFErrorMsgC::RecordError(IN_error_code, 
								  IN_entityname, 
								  3, 
								  IN_instanceID, 
								  IN_entityname,
								  IN_param_string
								  );
		}
	}
};
/**
	All Rights Reserved,(c) JACIC 2001
	ファイル名				作成日：2000.04.22
	SXFcheck_ruleC.cpp

  　１．機能概要
	    デフォルトコンストラクタ

	２．インターフェイス
	SXFEntitySchemaC::SXFEntitySchemaC()

	引数：	型	引数名		内容
			なし。

  　復帰値：なし。

	３．履歴
	履歴番号		日付け		担当者		概要
	作成		2000.04.22	　　藤本(FQS)	なし。
**/
SXFEntitySchemaC::SXFEntitySchemaC()
{
}
/**
	All Rights Reserved,(c) JACIC 2001
	ファイル名				作成日：2000.04.22
	SXFEntitySchemaC.cpp

	１．機能概要
	　　デフォルトデストラクタ

	２．インターフェイス
		SXFEntitySchemaC::~SXFEntitySchemaC()

	引数：	型	引数名		内容
	　　　　なし。

	復帰値：なし。

	３．履歴
	履歴番号		日付け		担当者		概要
	作成		2000.04.22	　　藤本(FQS)	なし。
**/
SXFEntitySchemaC::~SXFEntitySchemaC()
{
}
/**
	All Rights Reserved,(c) JACIC 2001
	ファイル名				作成日：2000.04.22
	SXFEntitySchemaC.cpp

	１．機能概要
	    Pare21インスタンスのチェック機能を起動

	２．インターフェイス
		BOOL SXFEntitySchemaC::EntitySchemaCheck()


	引数：型	引数名		内容
		　なし。

  　復帰値：なし。

	３．履歴
	履歴番号		日付け		担当者		概要
	作成		2000.04.22　	藤本(FQS)	なし。
	更新		2004.01.30		K.Naono		Ver3.0対応
**/
BOOL SXFEntitySchemaC::EntitySchemaCheck()
{
	m_schema = new SXFCKSchemaC();
	if (part21){

		MyContextC	mc;
		
		// HASHサイズを大きくする
		mc.m_refmap.InitHashTable( 2999 );

		SXFCKSchemaC	*ps = m_schema;
		ps->SetIDManager(part21->m_InstanceIDManager);

#ifdef _DEBUG
		clock_t	start = clock() ;
#endif

#ifdef _RELEASE
		clock_t	start = clock() ;
#endif

//		int count = part21->m_InstanceIDManager->m_EntityArray.GetSize();
//		for (int i = 0; i < count; i++) {
//			SXFEntityDataC *ent = part21->m_InstanceIDManager
//										->m_EntityArray[i];
		for( POSITION pos = part21->m_InstanceIDManager->m_EntityArray.GetHeadPosition(); pos; ) {
			SXFEntityDataC*	ent = part21->m_InstanceIDManager->m_EntityArray.GetNext(pos) ;
			if (ps->Check(&mc, ent)) {

			}
		}
#ifdef _DEBUG
		clock_t	finish = clock() ;
		double	duration = (double)(finish - start) / CLOCKS_PER_SEC ;
		printf("\tエンティティチェック:%2.1f 秒です。\n", duration) ;
#endif

#ifdef _RELEASE
		clock_t	finish = clock() ;
		double	duration = (double)(finish - start) / CLOCKS_PER_SEC ;
		printf("\tエンティティチェック:%2.1f 秒です。\n", duration) ;
#endif

#ifdef _DEBUG
		start = clock() ;
#endif

#ifdef _RELEASE
		start = clock() ;
#endif

		// 参照チェック
//		for (i = 0; i < count; i++) {
//			SXFEntityDataC *ent = part21->m_InstanceIDManager->m_EntityArray[i];
		for( pos = part21->m_InstanceIDManager->m_EntityArray.GetHeadPosition(); pos; ) {
			SXFEntityDataC*	ent = part21->m_InstanceIDManager->m_EntityArray.GetNext(pos) ;
			int refcount = mc.RefCount(ent->m_InstanceID);
			if (refcount == 0) {
				if ((ent->m_EntityName == DEF_DIMENSION_CALLOUT_RELATIONSHIP) |
					(ent->m_EntityName == DEF_DRAUGHTING_TITLE)|
					(ent->m_EntityName == DEF_INVISIBILITY)|
					(ent->m_EntityName == DEF_PRESENTATION_LAYER_USAGE)|
					(ent->m_EntityName == DEF_PRESENTATION_SIZE)|
					(ent->m_EntityName == DEF_DRAWING_SHEET_REVISION_USAGE)|
//	ADD(S)	Ver3.0対応	K.Naono	04.01.30
					(ent->m_EntityName == DEF_DRAUGHTING_CONTRACT_ASSIGNMENT)|
					(ent->m_EntityName == DEF_DRAUGHTING_APPROVAL_ASSIGNMENT)|
					(ent->m_EntityName == DEF_APPROVAL_DATE_TIME)|
					(ent->m_EntityName == DEF_DRAUGHTING_ORGANIZATION_ASSIGNMENT)
//	ADD(E)	Ver3.0対応	K.Naono	04.01.30
					)
				{
				}
				else
				{
// 2012.07.03					SXFErrorMsgC::RecordError(SXFNOREF, ent->m_EntityName,
//								2, ent->m_InstanceID, ent->m_EntityName);
				}
			}
		}
#ifdef _DEBUG
		finish = clock() ;
		duration = (double)(finish - start) / CLOCKS_PER_SEC ;
		printf("\t参照チェック:%2.1f 秒です。\n", duration) ;
#endif
#ifdef _RELEASE
		finish = clock() ;
		duration = (double)(finish - start) / CLOCKS_PER_SEC ;
		printf("\t参照チェック:%2.1f 秒です。\n", duration) ;
#endif

	}
	delete m_schema;
	return TRUE;
}
