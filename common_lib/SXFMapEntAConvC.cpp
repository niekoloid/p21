/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapEntAConvC.cpp						作成日：2000.04.17

	１．クラス概要
		EntityArrayDataを型変換する

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#include "stdafx.h"
#include "SXFMapEntDConvC.h"
#include "SXFMapEntAConvC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntAConvC.cpp						作成日：2000.04.17

	１．機能概要
		デフォルトコンストラクタ

	２．インターフェイス
		void	SXFMapEntAConvC::SXFMapEntAConvC()

	引数  ：	型			引数名				内容
			なし
	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapEntAConvC::SXFMapEntAConvC()
{
//
//	<初期化>
//	<分割したエンティティデータ>
//	m_EntityArray;
}
/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntAConvC.cpp						作成日：2000.04.17

	１．機能概要
		エンティティデータを指定して生成する場合
		(コンストラクタ)

	２．インターフェイス
		void	SXFMapEntAConvC::SXFMapEntAConvC(
					CStringArray*		IN_EntityArray)
					

	引数  ：	型					引数名				内容
				CStringArray*		IN_EntityArray		エンティティデータ

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapEntAConvC::SXFMapEntAConvC(
		CStringArray*	IN_EntityArray)
{
	m_EntityArray = IN_EntityArray;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntAConvC.cpp						作成日：2000.04.17

	１．機能概要
		(デストラクタ)

	２．インターフェイス
		void	SXFMapEntAConvC::~SXFMapEntAConvC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapEntAConvC::~SXFMapEntAConvC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntAConvC.cpp						作成日：2000.04.17

	１．機能概要
		エンティティデータの登録

	２．インターフェイス
		int		SXFMapEntAConvC::SetEntityArray(
			CStringArray* IN_EntityArray	//	<エンティティデータ>

	引数  ：	型				引数名				内容
				CStringArray* 	IN_EntityArray

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
int SXFMapEntAConvC::SetEntityArray(
		CStringArray* IN_EntityArray	//	<分割したエンティティデータ>
		)
{
	m_EntityArray = IN_EntityArray;

	return 0;
}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntAConvC.cpp						作成日：2000.04.17

	１．機能概要
		指定された配列添え字のフィーチャデータを型変換する

	２．インターフェイス
		int		SXFMapEntAConvC::GetInt(int IN_Int	,int& Out_int)

	引数  ：	型			引数名				内容
				int 		IN_Int
				int&		Out_int

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/

//	<integerへの変換>
int SXFMapEntAConvC::GetInt(int IN_Int	,int& Out_int)
{
//	MOD(S)	バグ修正	K.Naono	01.09.26
//	if(IN_Int > m_EntityArray->GetSize()){
	if(IN_Int >= m_EntityArray->GetSize()){
//	MOD(E)	バグ修正	K.Naono	01.09.26
		//err
		return -100;
	};
	Out_int =  atoi( (*m_EntityArray)[IN_Int] );
	return 0;
}

//	<doubleへの変換>
int SXFMapEntAConvC::GetDouble(int IN_Int	,double& OUT_double)
{
//	MOD(S)	バグ修正	K.Naono	01.09.26
//	if(IN_Int > m_EntityArray->GetSize()){
	if(IN_Int >= m_EntityArray->GetSize()){
//	MOD(E)	バグ修正	K.Naono	01.09.26
		//err
		return -100;
	};
	OUT_double = atof( (*m_EntityArray)[IN_Int] );
	return 0;
}

//	<Stringへの変換>
int SXFMapEntAConvC::GetCString(int IN_Int	,CString& OUT_String)
{
//	MOD(S)	バグ修正	K.Naono	01.09.26
//	if(IN_Int > m_EntityArray->GetSize()){
	if(IN_Int >= m_EntityArray->GetSize()){
//	MOD(E)	バグ修正	K.Naono	01.09.26
		//err
		return -100;
	};
	SXFMapEntDConvC::SetEntitydata((*m_EntityArray)[IN_Int]);
	OUT_String = SXFMapEntDConvC::GetCString();
	return 0;
}

//	<instanceIDへの変換>
int SXFMapEntAConvC::GetInst(int IN_Int	,int& Out_Int)
{
//	MOD(S)	バグ修正	K.Naono	01.09.26
//	if(IN_Int > m_EntityArray->GetSize()){
	if(IN_Int >= m_EntityArray->GetSize()){
//	MOD(E)	バグ修正	K.Naono	01.09.26
		//err
		return -100;
	};
	SXFMapEntDConvC::SetEntitydata((*m_EntityArray)[IN_Int]);
	SXFMapEntDConvC::GetInst(Out_Int);

	return 0;
}

//	<instanceIDへの変換>
int SXFMapEntAConvC::GetBOOL(int IN_Int	,BOOL& OUT_BOOL)
{
//	MOD(S)	バグ修正	K.Naono	01.09.26
//	if(IN_Int > m_EntityArray->GetSize()){
	if(IN_Int >= m_EntityArray->GetSize()){
//	MOD(E)	バグ修正	K.Naono	01.09.26
		//err
		return -100;
	};
	SXFMapEntDConvC::SetEntitydata((*m_EntityArray)[IN_Int]);
	SXFMapEntDConvC::GetBOOL(OUT_BOOL);

	return 0;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntAConvC.cpp						作成日：2000.04.17

	１．機能概要
		セット型のフォーチャデータの型変換する

	２．インターフェイス
		int		SXFMapEntAConvC::GetSetDouble(
					int IN_Num,
					int& OUT_Num,	
					CArray<double,double>&  OUT_array )

	引数 ：	型						引数名				内容
			int 					IN_Num
			int&		 			OUT_Num
			CArray<double,double>&  OUT_array

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/

//		セット型のフィーチャデータをdoubleに変換する

int	SXFMapEntAConvC::GetSetDouble(
					int IN_Num,
					int& OUT_Num,	
					CArray<double,double>&  OUT_array )
{
//	MOD(S)	バグ修正	K.Naono	01.09.26
//	if(IN_Num > m_EntityArray->GetSize()){
	if(IN_Num >= m_EntityArray->GetSize()){
//	MOD(E)	バグ修正	K.Naono	01.09.26
		//err
		return -100;
	};
	SXFMapEntDConvC::SetEntitydata((*m_EntityArray)[IN_Num]);
	SXFMapEntDConvC::GetSetDouble(OUT_Num,OUT_array);

	return 0;

}
//		セット型のフィーチャデータをintegerに変換する
int	SXFMapEntAConvC::GetSetInt( int IN_Num
							,int& OUT_Num
							,CArray<int,int>&  OUT_array )
{
//	MOD(S)	バグ修正	K.Naono	01.09.26
//	if(IN_Num > m_EntityArray->GetSize()){
	if(IN_Num >= m_EntityArray->GetSize()){
//	MOD(E)	バグ修正	K.Naono	01.09.26
		//err
		return -100;
	};
	SXFMapEntDConvC::SetEntitydata((*m_EntityArray)[IN_Num]);
	SXFMapEntDConvC::GetSetInt(OUT_Num,OUT_array);

	return 0;

}

//		セット型のフィーチャデータをInstanceIDに変換する
int	SXFMapEntAConvC::GetSetInst(
			int IN_Num,	
			int& OUT_Num,
			CArray<int,int>& OUT_array )
{
//	MOD(S)	バグ修正	K.Naono	01.09.26
//	if(IN_Num > m_EntityArray->GetSize()){
	if(IN_Num >= m_EntityArray->GetSize()){
//	MOD(E)	バグ修正	K.Naono	01.09.26
		//err
		return -100;
	};
	SXFMapEntDConvC::SetEntitydata((*m_EntityArray)[IN_Num]);
	SXFMapEntDConvC::GetSetInst(OUT_Num,OUT_array);

	return 0;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntAConvC.cpp						作成日：2000.04.17

	１．機能概要
		Select型の変換

	２．インターフェイス
		int		SXFMapEntAConvC::GetSelectDouble(
						int IN_Num,
						CString& IN_Select,
						double& OUT_Double)

	引数 ：	型			引数名				内容
			int 		IN_Num
			CString& 	IN_Select
			double& 	OUT_Double

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
//		Select型のdoubleへの変換
int		SXFMapEntAConvC::GetSelectDouble(
						int IN_Num,
						CString& IN_Select,
						double& OUT_Double)
{

//	MOD(S)	バグ修正	K.Naono	01.09.26
//	if(IN_Num > m_EntityArray->GetSize()){
	if(IN_Num >= m_EntityArray->GetSize()){
//	MOD(E)	バグ修正	K.Naono	01.09.26
		//err
		return -100;
	};
	SXFMapEntDConvC::SetEntitydata((*m_EntityArray)[IN_Num]);
	SXFMapEntDConvC::GetSelectDouble(IN_Select,OUT_Double);

	return 0;

}


int		SXFMapEntAConvC::GetSelectDouble(
						int IN_Num,
						char* IN_Select,
						double& OUT_Double)
{
//	MOD(S)	バグ修正	K.Naono	01.09.26
//	if (IN_Num > m_EntityArray->GetSize()){
	if (IN_Num >= m_EntityArray->GetSize()){
//	MOD(E)	バグ修正	K.Naono	01.09.26
		//err
		return -100;
	};
	SXFMapEntDConvC::SetEntitydata((*m_EntityArray)[IN_Num]);
	SXFMapEntDConvC::GetSelectDouble(IN_Select,OUT_Double);

	return 0;

}


//	<添え字で指定されたエンティティデータの、Select型のCStringへの変換>
BOOL	SXFMapEntAConvC::GetSelectCString(
			int IN_Num, 
			CString& IN_Select, 
			CString& OUT_CString)
{
//	MOD(S)	バグ修正	K.Naono	01.09.26
//	if (IN_Num > m_EntityArray->GetSize()){
	if (IN_Num >= m_EntityArray->GetSize()){
//	MOD(E)	バグ修正	K.Naono	01.09.26
		//err
		return FALSE;
	};
	SXFMapEntDConvC::SetEntitydata((*m_EntityArray)[IN_Num]);
	SXFMapEntDConvC::GetSelectCString( IN_Select, OUT_CString );

	return TRUE;
}


BOOL	SXFMapEntAConvC::GetSelectCString(
			int IN_Num, 
			char* IN_Select, 
			CString& OUT_CString)
{

//	MOD(S)	バグ修正	K.Naono	01.09.26
//	if (IN_Num > m_EntityArray->GetSize()){
	if (IN_Num >= m_EntityArray->GetSize()){
//	MOD(E)	バグ修正	K.Naono	01.09.26
		//err
		return FALSE;
	};
	SXFMapEntDConvC::SetEntitydata((*m_EntityArray)[IN_Num]);
	SXFMapEntDConvC::GetSelectCString(IN_Select,OUT_CString);

	return TRUE;
}



/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntAConvC.cpp						作成日：2000.04.17

	１．機能概要
		Select型のdoubleへの変換

	２．インターフェイス
		int		SXFMapEntAConvC::GetSetSelectDouble(
						int IN_Num,
						CString& IN_Select,
						int& OUT_Num,  
						CArray<double,double>& OUT_array)

	引数 ：	型						引数名				内容
			int 					IN_Num
			CString& 				IN_Select
			int&	 				OUT_Num
			CArray<double,double>& 	OUT_array

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/

// SET+SELECT型の例
//#427 = TRIMMED_CURVE('trimmed_curve3', #426, (#422), (#421), .T., .CARTESIAN.);
//#521 = TRIMMED_CURVE('',#520,	(#516,PARAMETER_VALUE(0.0)),
//		(#517,PARAMETER_VALUE(12.383404246416728)), .T.,.PARAMETER.);
//#104 = TRIMMED_CURVE('trimmed_curve1', #103, 
//	(PARAMETER_VALUE(3.141593)),(PARAMETER_VALUE(0.)), .T., .PARAMETER.);

//#254 = (
//  TEXT_STYLE('text_style1', #253)
//  TEXT_STYLE_WITH_BOX_CHARACTERISTICS(
//	( BOX_HEIGHT(1.), BOX_WIDTH(1.),BOX_SLANT_ANGLE(0.),BOX_ROTATE_ANGLE(0.)) 
//	)
//  TEXT_STYLE_WITH_SPACING(LENGTH_MEASURE(0.2)));

//		SetSelect型のdoubleへの変換
int		SXFMapEntAConvC::GetSetSelectDouble(
						int IN_Num,
						CString& IN_Select,
						int& OUT_Num,  
						CArray<double,double>& OUT_array)
{

//	MOD(S)	バグ修正	K.Naono	01.09.26
//	if(IN_Num > m_EntityArray->GetSize()){
	if(IN_Num >= m_EntityArray->GetSize()){
//	MOD(E)	バグ修正	K.Naono	01.09.26
		//err
		return -100;
	};
	SXFMapEntDConvC::SetEntitydata((*m_EntityArray)[IN_Num]);
	SXFMapEntDConvC::GetSetSelectDouble(IN_Select, OUT_Num, OUT_array);

	return 0;

}

int		SXFMapEntAConvC::GetSetSelectDouble(
						int IN_Num,
						char* IN_Select,
						int& OUT_Num,  
						CArray<double,double>& OUT_array)
{

//	MOD(S)	バグ修正	K.Naono	01.09.26
//	if(IN_Num > m_EntityArray->GetSize()){
	if(IN_Num >= m_EntityArray->GetSize()){
//	MOD(E)	バグ修正	K.Naono	01.09.26
		//err
		return -100;
	};
	SXFMapEntDConvC::SetEntitydata((*m_EntityArray)[IN_Num]);
	SXFMapEntDConvC::GetSetSelectDouble(IN_Select, OUT_Num, OUT_array);

	return 0;

}
