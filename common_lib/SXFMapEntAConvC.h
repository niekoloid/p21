/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntAConvC.h						作成日：2000.04.17

	１．クラス概要
		EntityArrayDataを型変換する

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#ifndef _SXFMapEntAConvC_CLASS_
#define _SXFMapEntAConvC_CLASS_

#include <afx.h>
#include <afxtempl.h>
#include "SXFMapEntDConvC.h"

class SXFMapEntAConvC : public SXFMapEntDConvC{
public :
//
//	<デフォルトコンストラクタ>
	SXFMapEntAConvC( ) ;

//	<コンストラクタ>
	SXFMapEntAConvC(CStringArray*) ;
//	SXFMapEntAConvC(CStringArray&) ;

//	<デストラクタ>
//
	virtual	~SXFMapEntAConvC() ;

//エンティティ名とエンティティデータの登録
	int	SetEntityArray(CStringArray*);

////// Get用のメンバ関数///////////////

//	<添え字で指定されたエンティティデータの、integerへ変換>
	int		GetInt(int	,int&);

//	<添え字で指定されたエンティティデータの、doubleへ変換>
	int		GetDouble(int	,double& );

//	<添え字で指定されたエンティティデータの、CStringへ変換>
	int		GetCString(int	,CString&);

//	<添え字で指定されたエンティティデータの、instanceIDへ変換>
	int		GetInst(int	,int&);

//	<添え字で指定されたエンティティデータの、BOOLへ変換>
	int		GetBOOL(int IN_Int	,BOOL& OUT_BOOL);

//
//	<添え字で指定されたエンティティデータの、Setのintegerへ変換>
	int		GetSetInt(int	,int&	,CArray<int,int>&);
//
//	<添え字で指定されたエンティティデータの、Setのdoubleへ変換>
	int		GetSetDouble(int	,int&	,CArray<double,double>& );
//
//	<添え字で指定されたエンティティデータの、SetのinstanceIDへ変換>
	int		GetSetInst( int IN_Num	,int& OUT_Num	,CArray<int,int>& OUT_array );

//
//	<添え字で指定されたエンティティデータの、Selectのdoubleへ変換>

int		GetSelectDouble(int IN_Num,CString& IN_Select,double& OUT_Double);
int		GetSelectDouble(int IN_Num, char* IN_Select,double& OUT_Double);

//
//	<添え字で指定されたエンティティデータの、SelectのCStringへ変換>
BOOL	GetSelectCString(int IN_Num, CString& IN_Select, CString& OUT_CString);
BOOL	GetSelectCString(int IN_Num, char* IN_Select, CString& OUT_CString);

//
//	<添え字で指定されたエンティティデータの、SetSelectのdoubleへ変換>
//		SetSelect型のdoubleへの変換
int		GetSetSelectDouble(int IN_Num,CString& IN_Select,int& OUT_Num, 
						   CArray<double,double>& OUT_array);
int		GetSetSelectDouble(int IN_Num,char* IN_Select,int& OUT_Num, 
						   CArray<double,double>& OUT_array);

//	<Set型のCStringArrayへの変換>
//	CStringArray*		ConvCStringArray(CString&);

private :

protected :

//
//	<エンティティデータ>
//	CString		m_EntityName;
//
//	<エンティティデータ>
//	CString		m_EntityData;
//
//	<分割したエンティティデータ>
	CStringArray*	m_EntityArray;

} ;

#endif

////////////////////////////
