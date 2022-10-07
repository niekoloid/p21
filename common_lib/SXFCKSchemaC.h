/**
	All Rights Reserved,(c) JACIC 2001
	SXFCKSchemaC.h			作成日：2000.04.23

	１．機能概要
		Part21インスタンスのチェックを行う

	２．履歴
	履歴番号	日付け		担当者		概要
	作成		2000.04.23	　　藤本(FQS)	なし。

**/
#if !defined(SXFCKSchemaC_INCLUDED_)
#define SXFCKSchemaC_INCLUDED_

#include "SXFDataStructC.h"
#include "SXFEntityDataC.h"
#include "SXFInstanceIDC.h"
#include "SXFPart21FileC.h"
#include "SXFPart21FileReadC.h"

#include "SXFTokenC.h"

#include "SXFErrorCode.h"
#include "SXFErrorMsgC.h"

class SXFCKAttrTypeC ;
class SXFCKEntityC;
struct SXFCKAttrLink ;
class SXFCheckContext;


struct SXFCKValue {
	enum VTYPE {
		VT_UNDEFINED = 0,
		VT_INTEGER,
		VT_REAL,
		VT_STRING,
		VT_BOOLEAN,
		VT_LOGICAL,
		VT_AGGR,
		VT_INSTANCE,
	} m_type;
	union {
		int	ival;
		double	rval;
		CString	*sval;
		char	bval;
		char	lval;
	} u;
	SXFCKValue() {
		m_type = VT_UNDEFINED;
	}
	~SXFCKValue() {
		Clear();
	}
	void Clear() {
		if (m_type == VT_STRING) {
			delete u.sval;
		}
		m_type = VT_UNDEFINED;
	}
	void SetString(LPCTSTR sval) {
		Clear();
		m_type = VT_STRING;
		u.sval = new CString(sval);
	}
	void SetInteger(int ival) {
		Clear();
		m_type = VT_INTEGER;
		u.ival = ival;
	}
	void SetReal(double rval) {
		Clear();
		m_type = VT_REAL;
		u.rval = rval;
	}
	void SetBoolean(int bval) {
		Clear();
		m_type = VT_BOOLEAN;
		u.bval = bval;
	}
	void SetLogical(int lval) {
		Clear();
		m_type = VT_LOGICAL;
		u.lval = lval;
	}
	void SetAggr() {
		Clear();
		m_type = VT_AGGR;
		u.ival = 0;
	}
	void SetInstance(int ival) {
		Clear();
		m_type = VT_INSTANCE;
		u.ival = ival;
	}
};
//////////////////////////////////////////////////////////////////////
/**
	All Rights Reserved,(c) JACIC 2001
	SXFCKSchemaC.h			作成日：2000.04.23

	１．機能概要
		エラー出力、インスタンスID検索

	２．履歴
	履歴番号	日付け		担当者		概要
	作成		2000.04.23	　　藤本(FQS)	なし。

**/
class SXFMainContextC
{
public:
//------------------------------------------------------------------------------
//	参照関係テーブル
//------------------------------------------------------------------------------
	CMap<int,int&,int,int&>	m_refmap;

//------------------------------------------------------------------------------
//	インスタンスID検索
//------------------------------------------------------------------------------
	void RefInstance(int IN_instanceID) {
		int	count;
		if (m_refmap.Lookup(IN_instanceID, count)) {
			count++;
		}
		else {
			count = 1;
			m_refmap.SetAt(IN_instanceID, count);
		}
	}
	int RefCount(int IN_instanceID) {
		int	count = 0;
		if (m_refmap.Lookup(IN_instanceID, count)) {
		}
		return count;
	}
//------------------------------------------------------------------------------
//	エラー出力
//------------------------------------------------------------------------------
	virtual void OnError(int IN_instanceID, 
						 LPCTSTR IN_entityname, 
						 SXFErrorCode IN_error_code, 
						 LPCTSTR IN_param_string) 
	{
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

//-----------------------------------------------------------------------------
/**
	All Rights Reserved,(c) JACIC 2001
	SXFCKSchemaC.h			作成日：2000.04.23

	１．機能概要
		Part21インスタンスをチェックする

	２．履歴
	履歴番号	日付け		担当者		概要
	作成		2000.04.23	　　藤本(FQS)	なし。

**/
class SXFCKSchemaC {
public:
//-----------------------------------------------------------------------------
//	デフォルトコンストラクタ
//-----------------------------------------------------------------------------
	SXFCKSchemaC();

//-----------------------------------------------------------------------------
//	デフォルトデストラクタ
//-----------------------------------------------------------------------------
	~SXFCKSchemaC();

//-----------------------------------------------------------------------------
//	基本データ型の属性生成
//-----------------------------------------------------------------------------
	void SetupBasicType();

//-----------------------------------------------------------------------------
//	基本データ型以外の属性生成
//-----------------------------------------------------------------------------
	void SetupExtraType();

//-----------------------------------------------------------------------------
//	属性追加
//-----------------------------------------------------------------------------
	void AddAttr(SXFCKAttrTypeC *IN_Attr);

//-----------------------------------------------------------------------------
//	属性リンク
//-----------------------------------------------------------------------------
	BOOL LinkAttr(SXFCKAttrLink *IN_AttrLink);
	CMapStringToPtr	m_attrmap;

//-----------------------------------------------------------------------------
//	属性型取得
//-----------------------------------------------------------------------------
	SXFCKAttrTypeC *GetAttr(LPCTSTR IN_name);

//-----------------------------------------------------------------------------
//	インスタンスIDを保持
//-----------------------------------------------------------------------------
	void SetIDManager(SXFInstanceIDC *IN_manager) {
		m_manager = IN_manager;
	}

//-----------------------------------------------------------------------------
//	チェック
//-----------------------------------------------------------------------------
	BOOL Check(SXFMainContextC *IN_mc, SXFEntityDataC *IN_entity);

//-----------------------------------------------------------------------------
//	複合インスタンス以外のチェック
//-----------------------------------------------------------------------------
	BOOL CheckSingleInstance(SXFEntityDataC *IN_entity, 
							 SXFCheckContext *IN_context);

//-----------------------------------------------------------------------------
//	複合インスタンスのチェック
//-----------------------------------------------------------------------------
	BOOL CheckComplexInstance(SXFEntityDataC *IN_entity, 
							  SXFCheckContext *IN_context, 
							  CArray<SXFCKEntityC*,SXFCKEntityC*> *IN_ents);

//-----------------------------------------------------------------------------
//	インスタンスID
//-----------------------------------------------------------------------------
	SXFInstanceIDC	*m_manager;
};
//-----------------------------------------------------------------------------
/**
	All Rights Reserved,(c) JACIC 2001
	SXFCKSchemaC.h			作成日：2000.04.23

	１．機能概要
		チェックすべき値を保持する。

	２．履歴
	履歴番号	日付け		担当者		概要
	作成		2000.04.23	　　藤本(FQS)	なし。

**/
class SXFCheckContext : public SXFTokenC {
public:
	SXFCheckContext(SXFMainContextC *IN_mc) : SXFTokenC()
	{
		m_MainContext = IN_mc;
	}
	SXFMainContextC	*m_MainContext;

//-----------------------------------------------------------------------------
//	文字列型の判定
//-----------------------------------------------------------------------------
	BOOL IsString() {
		return m_Type == T_STRING;
	}

//-----------------------------------------------------------------------------
//	実数型の判定
//-----------------------------------------------------------------------------
	BOOL IsReal() {
		return m_Type == T_REAL;
	}

//-----------------------------------------------------------------------------
//	整数型の判定
//-----------------------------------------------------------------------------
	BOOL IsInteger() {
		return m_Type == T_INTEGER;
	}

//-----------------------------------------------------------------------------
//	インスタンスIDかの判定
//-----------------------------------------------------------------------------
	BOOL IsID() {
		return m_Type == T_ID;
	}

//-----------------------------------------------------------------------------
//	エラー出力
//-----------------------------------------------------------------------------
	void SXFCheckContext::Output(SXFErrorCode error_code, 
								 int param_num, 
								 LPCTSTR param_string);

//-----------------------------------------------------------------------------
//	インスタンスの情報を保持
//-----------------------------------------------------------------------------
	void SetInstanceInfo(int instanceID, LPCTSTR entityname) {
		m_instanceID = instanceID;
		m_entityname = entityname;
	}

//-----------------------------------------------------------------------------
//	インスタンスID
//-----------------------------------------------------------------------------
	int			m_instanceID;

//-----------------------------------------------------------------------------
//	エラーコード
//-----------------------------------------------------------------------------
	SXFErrorCode m_error_code;

//-----------------------------------------------------------------------------
//	エラー出力に必要なパラメータ数
//-----------------------------------------------------------------------------
	int m_param_num;

//-----------------------------------------------------------------------------
//	エンティティ名、インスタンスID以外のパラメータ
//-----------------------------------------------------------------------------
	CString m_param_string;

//-----------------------------------------------------------------------------
//	エンティティ名
//-----------------------------------------------------------------------------
	CString		m_entityname;

//-----------------------------------------------------------------------------
//	エラー用文字列
//-----------------------------------------------------------------------------
	CString		m_errortext;
};

//-----------------------------------------------------------------------------
/**
	All Rights Reserved,(c) JACIC 2001
	SXFCKSchemaC.h			作成日：2000.04.23

	１．機能概要
		属性の型を保持。

	２．履歴
	履歴番号	日付け		担当者		概要
	作成		2000.04.23	　　藤本(FQS)	なし。

**/
class SXFCKAttrTypeC {
public:
//-----------------------------------------------------------------------------
//	コンストラクタ
//-----------------------------------------------------------------------------
	SXFCKAttrTypeC(SXFCKSchemaC *IN_schema) {
		m_schema = IN_schema;
	}

//-----------------------------------------------------------------------------
//	デストラクタ
//-----------------------------------------------------------------------------
	virtual ~SXFCKAttrTypeC() {
	}

//-----------------------------------------------------------------------------
//	名前取得
//-----------------------------------------------------------------------------
	CString GetName() {
		return m_name;
	}

//-----------------------------------------------------------------------------
//	初期化
//-----------------------------------------------------------------------------
	virtual BOOL Initialize() {
		return TRUE;
	}

//-----------------------------------------------------------------------------
//	チェック
//-----------------------------------------------------------------------------
	virtual BOOL Check(SXFEntityDataC *IN_entity, 
					   SXFCheckContext *IN_context, 
					   SXFCKValue *val) 
	{
		IN_context->Output(SXFNODICT, 2, "");
		return FALSE;
	};
protected:

//-----------------------------------------------------------------------------
//	名前
//-----------------------------------------------------------------------------
	CString	m_name;
	SXFCKSchemaC	*m_schema;
};

struct SXFCKAttrLink {
	CString			m_attrname;
	CString			m_typename;
	SXFCKAttrTypeC	*m_attr;
	BOOL			m_deletable;
	enum FLAGS {
		FLAG_OPTIONAL = 0x0001,
		FLAG_UNIQUE = 0x0002,
		FLAG_DERIVE = 0x0004,
	};
	DWORD			m_flags;
	SXFCKAttrLink() {
		m_attr = NULL;
		m_deletable = FALSE;
		m_flags = 0;
	}
	SXFCKAttrLink(LPCTSTR attrname, LPCTSTR typenam, DWORD flags) {
		m_attrname = attrname;
		m_typename = typenam;
		m_attr = NULL;
		m_deletable = FALSE;
		m_flags = flags;
	}
	~SXFCKAttrLink() {
		if (m_deletable) {
			delete m_attr;
		}
	}
};

struct SXFCKDeriveAttrLink: public SXFCKAttrLink {
	SXFCKDeriveAttrLink(LPCTSTR supertype, LPCTSTR attrname) :
		SXFCKAttrLink(attrname, "", 0) {
		m_supertype = supertype;
	}
	CString		m_supertype;// DERIVEする属性を持つクラス。カレントならEmpty()
};

//-----------------------------------------------------------------------------
/**
	All Rights Reserved,(c) JACIC 2001
	SXFCKSchemaC.h			作成日：2000.04.23

	１．機能概要
		基本データ型をチェック。

	２．履歴
	履歴番号	日付け		担当者		概要
	作成		2000.04.23	　　藤本(FQS)	なし。

**/
class SXFCKBasicTypeC : public SXFCKAttrTypeC {
public:
//-----------------------------------------------------------------------------
//	コンストラクタ
//-----------------------------------------------------------------------------
	SXFCKBasicTypeC(SXFCKSchemaC *IN_schema) : SXFCKAttrTypeC(IN_schema) {
	}
protected:
};

//-----------------------------------------------------------------------------
/**
	All Rights Reserved,(c) JACIC 2001
	SXFCKSchemaC.h			作成日：2000.04.23

	１．機能概要
		整数型をチェック。

	２．履歴
	履歴番号	日付け		担当者		概要
	作成		2000.04.23	　　藤本(FQS)	なし。

**/
class SXFCKIntegerC : public SXFCKBasicTypeC {
public:
//-----------------------------------------------------------------------------
//	コンストラクタ
//-----------------------------------------------------------------------------
	SXFCKIntegerC(SXFCKSchemaC *IN_schema) : SXFCKBasicTypeC(IN_schema) {
		m_name = "INTEGER";
	}

//-----------------------------------------------------------------------------
//	チェック
//-----------------------------------------------------------------------------
	virtual BOOL Check(SXFEntityDataC *IN_entity, 
					   SXFCheckContext *IN_context, 
					   SXFCKValue *val);
protected:
};

//-----------------------------------------------------------------------------
/**
	All Rights Reserved,(c) JACIC 2001
	SXFCKSchemaC.h			作成日：2000.04.23

	１．機能概要
		実数型をチェック。

	２．履歴
	履歴番号	日付け		担当者		概要
	作成		2000.04.23	　　藤本(FQS)	なし。

**/
class SXFCKRealC : public SXFCKBasicTypeC {
public:
//-----------------------------------------------------------------------------
//	コンストラクタ
//-----------------------------------------------------------------------------
	SXFCKRealC(SXFCKSchemaC *IN_schema) : SXFCKBasicTypeC(IN_schema) {
		m_name = "REAL";
	}

//-----------------------------------------------------------------------------
//	チェック
//-----------------------------------------------------------------------------
	virtual BOOL Check(SXFEntityDataC *IN_entity, 
					   SXFCheckContext *IN_context, 
					   SXFCKValue *val);
protected:
};

//-----------------------------------------------------------------------------
/**
	All Rights Reserved,(c) JACIC 2001
	SXFCKSchemaC.h			作成日：2000.04.23

	１．機能概要
		BOOL型をチェック。

	２．履歴
	履歴番号	日付け		担当者		概要
	作成		2000.04.23	　　藤本(FQS)	なし。

**/
class SXFCBooleanC : public SXFCKBasicTypeC {
public:
//-----------------------------------------------------------------------------
//	コンストラクタ
//-----------------------------------------------------------------------------
	SXFCBooleanC(SXFCKSchemaC *IN_schema) : SXFCKBasicTypeC(IN_schema) {
		m_name = "BOOLEAN";
	}

//-----------------------------------------------------------------------------
//	チェック
//-----------------------------------------------------------------------------
	virtual BOOL Check(SXFEntityDataC *IN_entity, 
					   SXFCheckContext *IN_context, 
					   SXFCKValue *val);
protected:
};

//-----------------------------------------------------------------------------
/**
	All Rights Reserved,(c) JACIC 2001
	SXFCKSchemaC.h			作成日：2000.04.23

	１．機能概要
		LOGICAL型をチェック。

	２．履歴
	履歴番号	日付け		担当者		概要
	作成		2000.04.23	　　藤本(FQS)	なし。

**/
class SXFCLogicalC : public SXFCKBasicTypeC {
public:
//-----------------------------------------------------------------------------
//	コンストラクタ
//-----------------------------------------------------------------------------
	SXFCLogicalC(SXFCKSchemaC *IN_schema) : SXFCKBasicTypeC(IN_schema) {
		m_name = "LOGICAL";
	}

//-----------------------------------------------------------------------------
//	チェック
//-----------------------------------------------------------------------------
	virtual BOOL Check(SXFEntityDataC *IN_entity, 
					   SXFCheckContext *IN_context, 
					   SXFCKValue *val);
protected:
};

//-----------------------------------------------------------------------------
/**
	All Rights Reserved,(c) JACIC 2001
	SXFCKSchemaC.h			作成日：2000.04.23

	１．機能概要
		文字列型をチェック。

	２．履歴
	履歴番号	日付け		担当者		概要
	作成		2000.04.23	　　藤本(FQS)	なし。

**/
class SXFCStringC : public SXFCKBasicTypeC {
public:
//-----------------------------------------------------------------------------
//	コンストラクタ
//-----------------------------------------------------------------------------
	SXFCStringC(SXFCKSchemaC *IN_schema) : SXFCKBasicTypeC(IN_schema) {
		m_name = "STRING";
	}

//-----------------------------------------------------------------------------
//	チェック
//-----------------------------------------------------------------------------
	virtual BOOL Check(SXFEntityDataC *IN_entity, 
					   SXFCheckContext *IN_context, 
					   SXFCKValue *val);
protected:
};

//-----------------------------------------------------------------------------
/**
	All Rights Reserved,(c) JACIC 2001
	SXFCKSchemaC.h			作成日：2000.04.23

	１．機能概要
		集合体型をチェック。

	２．履歴
	履歴番号	日付け		担当者		概要
	作成		2000.04.23	　　藤本(FQS)	なし。

**/
class SXFCAggrC : public SXFCKBasicTypeC {
public:
//-----------------------------------------------------------------------------
//	コンストラクタ
//-----------------------------------------------------------------------------
	SXFCAggrC(SXFCKSchemaC *IN_schema) : SXFCKBasicTypeC(IN_schema) {
	}
	int		m_lower;// 下限
	int		m_upper;// 上限

//-----------------------------------------------------------------------------
//	要素
//-----------------------------------------------------------------------------
	SXFCKAttrLink	m_element;

//-----------------------------------------------------------------------------
//	チェック
//-----------------------------------------------------------------------------
	virtual BOOL Check(SXFEntityDataC *IN_entity, 
					   SXFCheckContext *IN_context, 
					   SXFCKValue *val);
};

//-----------------------------------------------------------------------------
/**
	All Rights Reserved,(c) JACIC 2001
	SXFCKSchemaC.h			作成日：2000.04.23

	１．機能概要
		SET型をチェック。

	２．履歴
	履歴番号	日付け		担当者		概要
	作成		2000.04.23	　　藤本(FQS)	なし。

**/
class SXFCSetC : public SXFCAggrC {
public:
//-----------------------------------------------------------------------------
//	コンストラクタ
//-----------------------------------------------------------------------------
	SXFCSetC(SXFCKSchemaC *IN_schema) : SXFCAggrC(IN_schema) {
		m_name = "SET";
	}
protected:
};

//-----------------------------------------------------------------------------
/**
	All Rights Reserved,(c) JACIC 2001
	SXFCKSchemaC.h			作成日：2000.04.23

	１．機能概要
		BAG型をチェック。

	２．履歴
	履歴番号	日付け		担当者		概要
	作成		2000.04.23	　　藤本(FQS)	なし。

**/
class SXFCBagC : public SXFCAggrC {
public:
//-----------------------------------------------------------------------------
//	コンストラクタ
//-----------------------------------------------------------------------------
	SXFCBagC(SXFCKSchemaC *IN_schema) : SXFCAggrC(IN_schema) {
		m_name = "BAG";
	}
protected:
};

//-----------------------------------------------------------------------------
/**
	All Rights Reserved,(c) JACIC 2001
	SXFCKSchemaC.h			作成日：2000.04.23

	１．機能概要
		ARRAY型をチェック。

	２．履歴
	履歴番号	日付け		担当者		概要
	作成		2000.04.23	　　藤本(FQS)	なし。

**/
class SXFCArrayC : public SXFCAggrC {
public:
//-----------------------------------------------------------------------------
//	コンストラクタ
//-----------------------------------------------------------------------------
	SXFCArrayC(SXFCKSchemaC *IN_schema) : SXFCAggrC(IN_schema) {
		m_name = "ARRAY";
	}
protected:
};

//-----------------------------------------------------------------------------
/**
	All Rights Reserved,(c) JACIC 2001
	SXFCKSchemaC.h			作成日：2000.04.23

	１．機能概要
		LIST型をチェック。

	２．履歴
	履歴番号	日付け		担当者		概要
	作成		2000.04.23	　　藤本(FQS)	なし。

**/
class SXFCListC : public SXFCAggrC {
public:
//-----------------------------------------------------------------------------
//	コンストラクタ
//------------------------------------------------------------------------------
	SXFCListC(SXFCKSchemaC *IN_schema) : SXFCAggrC(IN_schema) {
		m_name = "LIST";
	}
protected:
};

//-----------------------------------------------------------------------------
/**
	All Rights Reserved,(c) JACIC 2001
	SXFCKSchemaC.h			作成日：2000.04.23

	１．機能概要
		Part21インスタンスをチェック。

	２．履歴
	履歴番号	日付け		担当者		概要
	作成		2000.04.23	　　藤本(FQS)	なし。

**/
class SXFCKEntityC : public SXFCKAttrTypeC {
public:
//-----------------------------------------------------------------------------
//	コンストラクタ
//-----------------------------------------------------------------------------
	SXFCKEntityC(SXFCKSchemaC *IN_schema) : SXFCKAttrTypeC(IN_schema) {
		/*	==>	Added by S.Kakizawa(KLS) on 2006/01/11	*/
		m_notArgs = TRUE;
		/*	<==	Added by S.Kakizawa(KLS) on 2006/01/11	*/
	}

//-----------------------------------------------------------------------------
//	デストラクタ
//-----------------------------------------------------------------------------
	virtual ~SXFCKEntityC();

//-----------------------------------------------------------------------------
//	初期化
//-----------------------------------------------------------------------------
	virtual BOOL Initialize();

//-----------------------------------------------------------------------------
//	チェック
//-----------------------------------------------------------------------------
	virtual BOOL Check(SXFEntityDataC *IN_entity, 
					   SXFCheckContext *IN_context, 
					   SXFCKValue *val);

//-----------------------------------------------------------------------------
//	エンティティをチェックする
//-----------------------------------------------------------------------------
	BOOL CheckEntity(SXFEntityDataC *IN_entity, 
					 SXFCheckContext *IN_context, 
					 BOOL bComplex, SXFCKValue *val);

//-----------------------------------------------------------------------------
//	サブタイプ判定
//-----------------------------------------------------------------------------
	BOOL IsSubclassOf(SXFCKEntityC *IN_ent);
protected:
//-----------------------------------------------------------------------------
//	マージした属性を取得
//-----------------------------------------------------------------------------
	void GetMargedArgs(CArray<SXFCKAttrLink*,SXFCKAttrLink*> &IO_args);

//-----------------------------------------------------------------------------
//	スーパータイプ
//-----------------------------------------------------------------------------
	CList<SXFCKAttrLink*,SXFCKAttrLink*>	m_supers;

//-----------------------------------------------------------------------------
//	属性
//-----------------------------------------------------------------------------
	CList<SXFCKAttrLink*,SXFCKAttrLink*>	m_attrs;

//-----------------------------------------------------------------------------
//	DERIVE属性
//-----------------------------------------------------------------------------
	CList<SXFCKDeriveAttrLink*,SXFCKDeriveAttrLink*>	m_deriveattrs;

	/*	==>	Added by S.Kakizawa(KLS) on 2006/01/11	*/
	//------------------------------------------------------------------------------------------------
	//	Attribute Name:
	//		m_args
	//	Exposition:
	//		Array of the Argument.
	//	Protective:
	//		protected
	//	Type:
	//		CArray<SXFCKAttrLink*,SXFCKAttrLink*>: Array of the Pointer to the Argument.
	//	History:
	//		Created by S.Kakizawa(KLS) on 2006/01/11.
	//	Notes:
	//		All Rights Reserved,(c) JACIC 2006
	//------------------------------------------------------------------------------------------------
	CArray<SXFCKAttrLink*,SXFCKAttrLink*>	m_args;

	//------------------------------------------------------------------------------------------------
	//	Attribute Name:
	//		m_notArgs
	//	Exposition:
	//		Flag for Set Argument.
	//	Protective:
	//		protected
	//	Type:
	//		BOOL : If this is 'TRUE', m_args has not yet Set.
	//	History:
	//		Created by S.Kakizawa(KLS) on 2006/01/11.
	//	Notes:
	//		All Rights Reserved,(c) JACIC 2006
	//------------------------------------------------------------------------------------------------
	BOOL									m_notArgs;
	/*	<==	Added by S.Kakizawa(KLS) on 2006/01/11	*/
};

//-----------------------------------------------------------------------------
/**
	All Rights Reserved,(c) JACIC 2001
	SXFCKSchemaC.h			作成日：2000.04.23

	１．機能概要
		型定義

	２．履歴
	履歴番号	日付け		担当者		概要
	作成		2000.04.23	　　藤本(FQS)	なし。

**/
class SXFCKTypeDefC : public SXFCKAttrTypeC {
public:
//-----------------------------------------------------------------------------
//	コンストラクタ
//-----------------------------------------------------------------------------
	SXFCKTypeDefC(SXFCKSchemaC *IN_schema) : SXFCKAttrTypeC(IN_schema) {
	}
protected:
};

//-----------------------------------------------------------------------------
/**
	All Rights Reserved,(c) JACIC 2001
	SXFCKSchemaC.h			作成日：2000.04.23

	１．機能概要
		単純データ型定義

	２．履歴
	履歴番号	日付け		担当者		概要
	作成		2000.04.23	　　藤本(FQS)	なし。

**/
class SXFCKTypeDefSingleC : public SXFCKTypeDefC {
public:
//-----------------------------------------------------------------------------
//	コンストラクタ
//-----------------------------------------------------------------------------
	SXFCKTypeDefSingleC(SXFCKSchemaC *IN_schema) : SXFCKTypeDefC(IN_schema) {
	}

//-----------------------------------------------------------------------------
//	デストラクタ
//-----------------------------------------------------------------------------
	virtual ~SXFCKTypeDefSingleC() {
	}

//-----------------------------------------------------------------------------
//	初期化
//-----------------------------------------------------------------------------
	virtual BOOL Initialize() {
		return m_schema->LinkAttr(&m_definedtype);
	}

//-----------------------------------------------------------------------------
//	チェック
//-----------------------------------------------------------------------------
	virtual BOOL Check(SXFEntityDataC *IN_entity, 
					   SXFCheckContext *IN_context, 
					   SXFCKValue *val);
protected:
//-----------------------------------------------------------------------------
//	定義型データ
//-----------------------------------------------------------------------------
	SXFCKAttrLink	m_definedtype;
};

//-----------------------------------------------------------------------------
/**
	All Rights Reserved,(c) JACIC 2001
	SXFCKSchemaC.h			作成日：2000.04.23

	１．機能概要
		SELECT型チェック

	２．履歴
	履歴番号	日付け		担当者		概要
	作成		2000.04.23	　　藤本(FQS)	なし。

**/
class SXFCKSelectC : public SXFCKTypeDefC {
public:
//-----------------------------------------------------------------------------
//	コンストラクタ
//-----------------------------------------------------------------------------
	SXFCKSelectC(SXFCKSchemaC *IN_schema) : SXFCKTypeDefC(IN_schema) {
	}

//-----------------------------------------------------------------------------
//	デストラクタ
//-----------------------------------------------------------------------------
	virtual ~SXFCKSelectC() {
//		for (int i = 0; i < m_select.GetSize(); i++) {
//			delete m_select[i];
//		}
		for(POSITION pos = m_select.GetHeadPosition(); pos; ) {
			delete m_select.GetNext(pos) ;
		}
	}

//-----------------------------------------------------------------------------
//	初期化
//-----------------------------------------------------------------------------
	virtual BOOL Initialize();

//-----------------------------------------------------------------------------
//	チェック
//-----------------------------------------------------------------------------
	virtual BOOL Check(SXFEntityDataC *IN_entity, 
					   SXFCheckContext *IN_contex, 
					   SXFCKValue *valt);
protected:
//-----------------------------------------------------------------------------
//	SELECTデータ
//-----------------------------------------------------------------------------
	CList<SXFCKAttrLink*,SXFCKAttrLink*>	m_select;
};

//-----------------------------------------------------------------------------
/**
	All Rights Reserved,(c) JACIC 2001
	SXFCKSchemaC.h			作成日：2000.04.23

	１．機能概要
		ENUMERATION型チェック

	２．履歴
	履歴番号	日付け		担当者		概要
	作成		2000.04.23	　　藤本(FQS)	なし。

**/
class SXFCKEnumerationC : public SXFCKTypeDefC {
public:
//-----------------------------------------------------------------------------
//	コンストラクタ
//-----------------------------------------------------------------------------
	SXFCKEnumerationC(SXFCKSchemaC *IN_schema) : SXFCKTypeDefC(IN_schema) {
	}
//-----------------------------------------------------------------------------
//	デストラクタ
//-----------------------------------------------------------------------------
	virtual ~SXFCKEnumerationC() {
//		for (int i = 0; i < m_enum.GetSize(); i++) {
//			delete m_enum[i];
//		}
		for(POSITION pos = m_enum.GetHeadPosition(); pos; ) {
			delete m_enum.GetNext(pos) ;
		}
	}

//-----------------------------------------------------------------------------
//	チェック
//-----------------------------------------------------------------------------
	virtual BOOL Check(SXFEntityDataC *IN_entity, 
					   SXFCheckContext *IN_context, 
					   SXFCKValue *val);
protected:
//-----------------------------------------------------------------------------
//	ENUMERATIONデータ
//-----------------------------------------------------------------------------
	CList<SXFCKAttrLink*,SXFCKAttrLink*>	m_enum;
};

#endif // !defined(SXFCKSchemaC_INCLUDED_)
