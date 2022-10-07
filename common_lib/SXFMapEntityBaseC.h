/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntityBaseC.h						作成日：2000.04.17

	１．クラス概要
		Entityデータを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#ifndef _SXFMapEntityBaseC_CLASS_
#define _SXFMapEntityBaseC_CLASS_

#include <afx.h>
#include <afxtempl.h>
#include "SXFMapBaseC.h"

class SXFInstanceIDC;

class SXFMapEntityBaseC : public SXFMapBaseC {
public :
//
//	<デフォルトコンストラクタ>
	SXFMapEntityBaseC( ) ;

//	<コンストラクタ>
//	<インスタンスＩＤへのポインタを登録し生成する>
	SXFMapEntityBaseC(SXFInstanceIDC* IN_InstanceIDManeger) ;

//	<デストラクタ>
	virtual	~SXFMapEntityBaseC() ;

//ルートＩＤ、エンティティ名、エンティティデータの登録
	int	SetEntitydata(int IN_RootID ,CString IN_EntityName, CString IN_EntityData);

//ルートＩＤ、エンティティ名、エンティティデータ(Split)の登録
	int	SetEntityArraydata(int IN_RootID , CString IN_EntityName ,CStringArray* IN_EntityArray);

//エンティティ名とエンティティデータ(Split)の取得
	CStringArray*	GetEntityArraydata(int&);

//インスタンスＩＤの登録
	int	SetRootID(int	IN_RootID);

//m_RootIDをもとにエンティティ名とエンティティデータ(Split)を取得し登録する
	int	SetEntity();

//
//	<エンティティデータ>
	CString		m_EntityName;
//
//	<エンティティデータ>
	CString		m_EntityData;
//
//	<分割したエンティティデータ>
	CStringArray*	m_EntityArray;
	CStringArray	m_MyArray;

private :

protected :

//取得したエンティティ名とm_EntityNameのチェック
	BOOL	Checkm_EntityName(CString IN_EntityName);
} ;

#endif
