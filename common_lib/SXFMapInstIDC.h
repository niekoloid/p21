/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapInstIDC.h						作成日：2000.04.21

	１．クラス概要
		InstanceIDクラスへのアクセスを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.21	

**/
#ifndef _SXFMAPINSTIDC_CLASS_
#define _SXFMAPINSTIDC_CLASS_

#include <afx.h>
#include <afxtempl.h>
#include "SXFErrorMsgC.h"

class SXFInstanceIDC;

class SXFMapInstIDC{

public :
//
//	<デフォルトコンストラクタ>
	SXFMapInstIDC() ;
	
//	<コンストラクタ>
//	インスタンスＩＤへのポインタを登録し生成する
	SXFMapInstIDC(SXFInstanceIDC* IN_InstanceIDManeger) ;

//	<デストラクタ>
//
	virtual	~SXFMapInstIDC() ;


private :

protected :


//	<インスタンスＩＤを指定しエンティティ名を取得する>
	CString		GetEntityName(int);
	
//	<インスタンスＩＤを指定しエンティティ名とエンティティデータを取得する>
	CString		GetEntityData(int) ;

//	<エンティティ名を指定し、そのエンティティ名をインスタンスにもつＩＤ群を取得する>
//	CArray<int,int>*  GetIDArray(CString IN_InstanceName) ;	
	CList<int,int>*  GetIDArray(CString IN_InstanceName) ;	
//	<インスタンスＩＤを指定しエンティティ名とエンティティデータ(Split)を取得する>
//	<インスタンスＩＤを指定しエンティティ名とエンティティデータ(Split)を取得する>
	BOOL	GetMyArray(int IN_InstID, CStringArray &OUT_EntityDataArray);
	
//	<インスタンスＩＤへのポインタ>
	SXFInstanceIDC* m_InstanceIDManager;

//	<エンティティデータ>
    
} ;

#endif
