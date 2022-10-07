/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapGeometryC.h						作成日：2000.04.21

	１．クラス概要
		AP202エンティティからフィーチャへのマッピングを管理するクラス

	２．履歴
		履歴番号	日付け		担当者			概要
		作成		2000.04.21	
		更新		2015.04.27	T.Matsushima	JPCERT/CC 指摘 脆弱性対応

**/
#ifndef _SXFMapGeometryC_CLASS_
#define _SXFMapGeometryC_CLASS_

#include <afx.h>
#include "SXFMapEntityBaseC.h"
#include "SXFF_FeatureTypeE.h"


class SXFMapAnnoBodyC;
class SXFMapCalloutBodyC;
class SXFMapCompBodyC;
class SXFInstanceIDC;
class SXFTableManagerC;
class SXFComInfoC;

class SXFMapGeometryC: public SXFMapEntityBaseC{
public :
//
//	<デフォルトコンストラクタ>
	SXFMapGeometryC( ) ;

//	<インスタンスＩＤへのポインタを登録し生成する>
//	SXFMapGeometryC(SXFInstanceIDC* IN_InstanceIDManeger) ;
//	SXFMapGeometryC(SXFInstanceIDC* IN_InstanceIDManeger, 
//		SXFTableManagerC* IN_TableManager) ;
	SXFMapGeometryC(
		SXFInstanceIDC* IN_InstanceIDManeger,
		SXFTableManagerC* IN_TableManager,
		SXFComInfoC* IN_ComInfoC,
		SXFReadAP202ManagerC* IN_ReadManager);

	//
//	<デストラクタ>
	virtual	~SXFMapGeometryC() ;

//
//	<フィーチャクラスへの値の設定>
	int		SetFeatureParameter(int& OUT_Type,	LPVOID&	OUT_Class);

//
//	<フィーチャ構造体への値の設定>
//	BOOL	SetStructData(E_type IN_Type,	LPVOID	IN_Class);
//	BOOL	SetStructData(int& IN_Type,	LPVOID&	IN_Class);
	BOOL	SetStructData(int  IN_Type,	LPVOID	IN_Class);

//
//	<フィーチャ構造体へのポインタ返却>
//	int		GetStructData(CString& OUT_TypeName, LPVOID OUT_Struct );
//	int		GetStructData( char*& OUT_Name, LPVOID& OUT_Struct );					JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
	int		GetStructData( char*& OUT_Name, size_t NameSize, LPVOID& OUT_Struct );	// バッファサイズを渡すように変更

	//ダウンコンバート用
	int GetStructDataLevel( char*& OUT_Name, LPVOID& OUT_Struct,int& OUT_Level );

//
//	<定義テーブル要素のルートEntityへのポインタの取得>
//	void*	GetBodyP();


private :

protected :
//	<BODY種別> ///////////////////////////////////////////////////////
	int		m_BodyKind;
//		0:不明
//		1:ANNOTATION_OCCURRENCE
//		2:DRAUGHTING_CALLOUT
//		3:COMPOSITE_CURVE_SEGMENT

//	<SXFTableManagerCへのポインタ>
	SXFTableManagerC* m_TableManager;
	
//	<SXFComInfoCへのポインタ>
	SXFComInfoC* m_ComInfoC;

//	<フィーチャタイプ>
	E_type	m_Type;

//	<フィーチャクラスへのポインタ>
	void*	m_Class;

//	<フィーチャ名>
//	CString	m_TypeName;
    char m_TypeName[30];

//	<フィーチャ構造体へのポインタ>
	void*	m_StructData;

	SXFReadAP202ManagerC* m_ReadManager;

	//ダウンコンバート時に使用
	//フィーチャのレベル
	int m_Level;

	SXFMapCalloutBodyC* m_calloutbody;
	SXFMapAnnoBodyC* m_annobody;
	SXFMapCompBodyC* m_compbody;
} ;
#endif
