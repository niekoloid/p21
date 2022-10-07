/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapAssemblyC.h						作成日：2000.04.21

	１．クラス概要
		ASSEMBLY要素のBODYを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.21	

**/
#ifndef _SXFMapAssemblyC_CLASS_
#define _SXFMapAssemblyC_CLASS_

#include <afx.h>
#include "SXFMapEntityBaseC.h"
#include "SXFF_FeatureTypeE.h"


class SXFInstanceIDC;
class SXFTableManagerC;
class SXFComInfoC;

class SXFMapAssemblyC: public SXFMapEntityBaseC{
public :
//
//	<デフォルトコンストラクタ>
	SXFMapAssemblyC( ) ;

//	<インスタンスＩＤへのポインタを登録し生成する>
//	SXFMapAssemblyC(SXFInstanceIDC* IN_InstanceIDManeger) ;
//	SXFMapAssemblyC(SXFInstanceIDC* IN_InstanceIDManeger, 
//		SXFTableManagerC* IN_TableManager) ;
	SXFMapAssemblyC(
		SXFInstanceIDC* IN_InstanceIDManeger,
		SXFTableManagerC* IN_TableManager,
		SXFComInfoC* IN_ComInfoC ) ;

	//
//	<デストラクタ>
	virtual	~SXFMapAssemblyC() ;

//
//	<フィーチャクラスへの値の設定>
//	int		SetFeatureParameter(int OUT_Type,	LPVOID	OUT_Class);
	int		SetFeatureParameter(int& OUT_Type,	LPVOID&	OUT_Class);

//
//	<フィーチャ構造体への値の設定>
//	BOOL	SetStructData(E_type IN_Type,	LPVOID	IN_Class);
	BOOL	SetStructData(int IN_Type,	LPVOID	IN_Class);

//
//	<フィーチャ構造体(OUT_Struct)へのポインタ返却>
//	int		GetStructData(CString& OUT_TypeName, LPVOID OUT_Struct );
//	int		GetStructData( char*& OUT_Name, LPVOID OUT_Struct );
//	int		GetStructData( LPVOID OUT_Struct );
	int		GetStructData( LPVOID& OUT_Struct );

//
//	<定義テーブル要素のルートEntityへのポインタの取得>
//	void*	GetBodyP();

private :

protected :
//	<BODY種別> ///////////////////////////////////////////////////////
	int		m_AsmKind;
//		0:不明
//		1:DRAWING_SHEET_REVISION_USAGE
//		2:DRAUGHTING_CALLOUT
//		3:COMPOSITE_CURVE

//	<SXFTableManagerCへのポインタ>
	SXFTableManagerC* m_TableManager;

//	<SXFComInfoCへのポインタ>
	SXFComInfoC* m_ComInfoC;

//	<アセンブリ要素のエンティティへのポインタ>
	void*	m_AssmP ;

//	<フィーチャタイプ>
	E_type	m_Type;

//	<フィーチャクラスへのポインタ>
	void*	m_Class;

//	<フィーチャ名>
//	CString	m_TypeName;
	char m_TypeName[30];

//	<フィーチャ構造体へのポインタ>
	void*	m_StructData;

//	<アセンブリ要素が抱える、要素群へのインスタンスＩＤ>
	CUIntArray m_Elements;

} ;
#endif
