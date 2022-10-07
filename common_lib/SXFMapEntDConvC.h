/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntDConvC.h						作成日：2000.04.17

	１．クラス概要
		EntityDataを型変換する

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#ifndef _SXFMapEntDConvC_CLASS_
#define _SXFMapEntDConvC_CLASS_

#include <afx.h>
#include <afxtempl.h>

class SXFMapEntDConvC {
public :
//
//	<デフォルトコンストラクタ>
	SXFMapEntDConvC( ) ;

//	<コンストラクタ>
	SXFMapEntDConvC(CString*) ;
	SXFMapEntDConvC(CString&) ;
	SXFMapEntDConvC(char*) ;

//	<デストラクタ>
//
	virtual	~SXFMapEntDConvC() ;

//
//エンティティ名の登録
	int	SetEntitydata(CString&);

//
//	<integerへの変換>
	int		GetInt(int&);
//
//	<doubleへの変換>
	double	GetDouble(double& );
//
//	<Stringへの変換>
	CString	GetCString();
//
//	<instanceIDへの変換>
	int		GetInst(int&);
//
//	<BOOLへの変換>	
	int	GetBOOL(BOOL& OUT_BOOL);

//
//	<Set型のintegerへの変換>
	int		GetSetInt(int&	OUT_Num ,CArray<int,int>&);
//
//	<Set型のdoubleへの変換>
	int		GetSetDouble(int& OUT_Num , CArray<double,double>& OUT_Instarray);
//
//	<Set型のinstanceIDへの変換>
	int		GetSetInst(int&	OUT_Num ,CArray<int,int>& );

//
//	<SetSelect型のdoubleへの変換>
	int		GetSetSelectDouble( CString& IN_Select, int& OUT_Num, CArray<double,double>& OUT_array);
	int		GetSetSelectDouble( char* IN_Select, int& OUT_Num, CArray<double,double>& OUT_array);

//
//	<Select型の double への変換>
	int		GetSelectDouble( CString& IN_Select, double &OUT_Double );
	int		GetSelectDouble( char* IN_Select, double &OUT_Double );
//
//	<Select型の CString への変換>
	BOOL	GetSelectCString(CString& IN_Select, CString& OUT_CString);
	BOOL	GetSelectCString(char* IN_Select, CString& OUT_CString);

// SELECT型の文字列削除 IDENTIFIER('XXXXXX')=>XXXXXX (文字コード変換なし)
	BOOL	TrimSelect( CString& IN_Select, CString &OUT_CString );
	BOOL	TrimSelect( char* IN_Select, CString &OUT_CString );

//	DEL(S)	チューニング対応	K.Naono
/*
//	前後の括弧（） を削除する
	BOOL TrimKako(CString*& INOUT_CString);
*/
//	DEL(E)	チューニング対応	K.Naono

private :

	void consumeQuote(CString& inSource) ;
//
//	<Set型のCStringArrayへの変換>
	int		ConvCStringArray();

protected :

//
//	<エンティティデータ>
	CString		m_Entity;

//
//	<分割したエンティティデータ>
//	CStringArray*	m_Splitarray;

//	<分割したエンティティデータ(ワーク)>
//	CStringArray	m_SplitarrayTemp;

//
//	<分割したエンティティデータ>
//	CStringArray*	m_SplitarrayPP;

//	<分割したエンティティデータ(ワーク)>
//	CStringArray	m_SplitarrayTT;

} ;

#endif

////////////////////////////
