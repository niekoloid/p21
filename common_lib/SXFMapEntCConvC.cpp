/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapEntCConvC.cpp						作成日：2000.04.17

	１．クラス概要
		Complex型EntityArrayDataを型変換する

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#include "stdafx.h"
#include "SXFMapEntAConvC.h"
#include "SXFMapEntCConvC.h"
//#include "SXFSplitAP202C.h"
#include "SXFComncApi.h"
//#include "ComSplitStringC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntCConvC.cpp						作成日：2000.04.17

	１．機能概要
		デフォルトコンストラクタ

	２．インターフェイス
		void	SXFMapEntCConvC::SXFMapEntCConvC()

	引数  ：	型			引数名				内容
			なし
	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapEntCConvC::SXFMapEntCConvC()
{
	//初期化
	m_EntityArray = &m_EntityArrayTempEntC;
}
/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntCConvC.cpp						作成日：2000.04.17

	１．機能概要
		Complex型エンティティデータを指定して生成する場合
		(コンストラクタ)

	２．インターフェイス
		void	SXFMapEntCConvC::SXFMapEntCConvC(
					CStringArray*		IN_ComplexArray)
					

	引数 ：	型				引数名				内容
			CStringArray*	IN_ComplexArray		Complex型エンティティデータ

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapEntCConvC::SXFMapEntCConvC(
		CStringArray*	IN_ComplexArray)

{
	m_ComplexArray = IN_ComplexArray;
	m_EntityArray = &m_EntityArrayTempEntC; 

}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntCConvC.cpp						作成日：2000.04.17

	１．機能概要
		(デストラクタ)

	２．インターフェイス
		void	SXFMapEntCConvC::~SXFMapEntCConvC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapEntCConvC::~SXFMapEntCConvC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntCConvC.cpp						作成日：2000.04.17

	１．機能概要
		Complex型EntityArrayDataの登録

	２．インターフェイス
		BOOL	SetCompelexArray(
					CStringArray*		IN_ComplexArray)

  	引数 ：	型				引数名				内容
  			CStringArray*	IN_ComplexArray		Complex型エンティティデータ

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
BOOL	SXFMapEntCConvC::SetCompelexArray(
			CStringArray*	IN_ComplexArray)	//Complex型エンティティデータ
{
	m_ComplexArray = IN_ComplexArray;
	return 0;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntCConvC.cpp						作成日：2000.04.17

	１．機能概要
		指定されたエンティティ名のデータを取り出し登録

	２．インターフェイス
		BOOL	SplitComplex(
					CString& IN_EntityName);<エンティティ名>

	引数  ：	型			引数名				内容
				CString& 	IN_EntityName		エンティティ名

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
BOOL	SXFMapEntCConvC::SplitComplex(
					CString& IN_EntityName)	//<エンティティ名>

{
	m_EntityName  = IN_EntityName;
	m_EntityArray->RemoveAll();
	CString	IN_Str;
	IN_Str.Empty();
//	ADD(S)	チューニング対応	K.Naono	03.07.03
	CStringArray	array ;
//	ADD(E)	チューニング対応	K.Naono	03.07.03
	for (int i=0; i< m_ComplexArray->GetSize();i++){
		if ((*m_ComplexArray)[i].Left(m_EntityName.GetLength()) == m_EntityName ){
			IN_Str = (*m_ComplexArray)[i];
			IN_Str.TrimLeft();
			IN_Str.TrimLeft(m_EntityName);

//			CStringArray* IN_EntityArray;

			IN_Str.Delete(0,1);
			CString temp = IN_Str;
			IN_Str.Delete(temp.GetLength()-1,1);
//	MOD(S)	チューニング対応	K.Naono	03.07.03
/*
			ComSplitStringC split(IN_Str);
			IN_EntityArray = split.Split(',');
			m_EntityArray->Copy(*IN_EntityArray); 
*/
			if( GFn_SplitString(IN_Str, ',' , array) > 0 )
				m_EntityArray->Copy(array) ;
//	MOD(E)	チューニング対応	K.Naono	03.07.03
	
			return TRUE;
		}
	}

	// ERR 
	return FALSE;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntCConvC.cpp						作成日：2000.04.17

	１．機能概要
		指定されたエンティティ名のデータを取り出し登録

	２．インターフェイス
		BOOL	SplitComplex(
					char* IN_EntityName);<エンティティ名>

	引数  ：	型			引数名				内容
				char*		IN_EntityName			エンティティ名	

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
BOOL	SXFMapEntCConvC::SplitComplex(
					char* IN_EntityName)	//<エンティティ名>

{
	m_EntityName  = IN_EntityName;

	m_EntityArray->RemoveAll();

	CString	IN_Str;
	IN_Str.Empty();
	for (int i=0; i< m_ComplexArray->GetSize();i++){
		if ((*m_ComplexArray)[i].Left(m_EntityName.GetLength()) == m_EntityName ){
			IN_Str = (*m_ComplexArray)[i];
			IN_Str.TrimLeft();
			IN_Str.TrimLeft(m_EntityName);
//	MOD(S)	チューニング対応	K.Naono	03.07.03
/*
			CStringArray* IN_EntityArray;

			int IN_Mode = 2; 
			SXFSplitAP202C  split(IN_Mode, IN_Str) ;
			IN_EntityArray = split.Split();

			m_EntityArray->Copy(*IN_EntityArray); 
*/
			CStringArray	IN_EntityArray ;
			if( GFn_SplitSEntityAttr(IN_Str, IN_EntityArray) > 0 )
				m_EntityArray->Copy(IN_EntityArray) ; 
//	MOD(E)	チューニング対応	K.Naono	03.07.03

			return TRUE;
		}
	}

	// ERR 
	return FALSE;

}
