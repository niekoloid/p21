/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapEntDConvC.cpp						作成日：2000.04.17

	１．クラス概要
		EntityDataを型変換する

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#include "stdafx.h"
#include "SXFMapEntDConvC.h"
//#include "SXFSplitAP202C.h"
#include "SXFComncApi.h"
//#include "ComSplitStringC.h"
#include "SXFutyConvKanjiC.h"
#include "max.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2003

	１．機能概要
		'xxx'からxxxのみを抽出する

	２．インターフェイス
		void	SXFMapEntDConvC::SXFMapEntDConvC()

	引数  ：	型			引数名				内容
			CString&		inSource		属性値文字列
	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2003.07.10	K.Naono
**/
void SXFMapEntDConvC::consumeQuote(CString& inSource)
{
	CString	str ;
	register int		i, j ;
	register bool		bQuot = false ;
	register int		nLength = inSource.GetLength() ;
	register LPCTSTR	wp = (LPCTSTR)inSource ;

	//	クォートがなければ、最初にあることにする
	if( strchr(wp, '\'') == NULL ) {
		bQuot = true ;
	}

	for(i = 0; i < nLength; i++) {
		if( wp[i] == '\'' ) {
			//	初めてのクォート(')は開始の印
			if( !bQuot ) {
				bQuot = true ;

			//	クォートが続く場合('')は取得
			} else if( (i + 1) < nLength && wp[i + 1] == '\'' ) {
				LPCTSTR p = &wp[nLength - 1] ;
				for(j = nLength - 1; j >= 0; j--) {
					if( wp[j] == '\'' ) break ;
				}
				//	次が終わりのクォート(')でなければ次のクォートまで取得
				if( (i + 1) != j ) {
					str += (TCHAR)wp[i] ;
					str += (TCHAR)wp[i + 1] ;
					i++ ;
				//	次が終わりのクォート(')ならばカレントのみ取得
				} else {
					str += (TCHAR)wp[i] ;
				}

			//	終わりのクォートであればループを終了
			} else if( bQuot ) {
				break ;
			}
			continue ;
		}
		//	クォート(')移行は取得する
		if( bQuot )
			str += (TCHAR)wp[i] ;
	}
	inSource = str ;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntDConvC.cpp						作成日：2000.04.17

	１．機能概要
		デフォルトコンストラクタ

	２．インターフェイス
		void	SXFMapEntDConvC::SXFMapEntDConvC()

	引数  ：	型			引数名				内容
			なし
	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapEntDConvC::SXFMapEntDConvC()
{
//
//	<初期化>
//
	m_Entity.Empty();

}
/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntDConvC.cpp						作成日：2000.04.17

	１．機能概要
		エンティティデータを指定して生成する場合
		(コンストラクタ)

	２．インターフェイス
		void	SXFMapEntDConvC::SXFMapEntDConvC(
					CString*		IN_Entity)
					

	引数  ：	型				引数名				内容
				CString*		IN_Entity		エンティティデータ

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapEntDConvC::SXFMapEntDConvC(
			CString*	IN_Entity)
{
	m_Entity = *IN_Entity;
//	m_SplitarrayPP = &m_SplitarrayTT;
}

SXFMapEntDConvC::SXFMapEntDConvC(
			CString&	IN_Entity)
{
	m_Entity = IN_Entity;
//	m_SplitarrayPP = &m_SplitarrayTT;

}

SXFMapEntDConvC::SXFMapEntDConvC(
			char*	IN_Entity)
{
	m_Entity = IN_Entity;
//	m_Splitarray = &m_SplitarrayTemp;
}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntDConvC.cpp						作成日：2000.04.17

	１．機能概要
		(デストラクタ)

	２．インターフェイス
		void	SXFMapEntDConvC::~SXFMapEntDConvC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapEntDConvC::~SXFMapEntDConvC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntDConvC.cpp						作成日：2000.04.17

	１．機能概要
		エンティティデータの登録

	２．インターフェイス
		int		SXFMapEntDConvC::SetEntitydata(
			CString& IN_Entity)

	引数  ：	型			引数名				内容
				CString& 	IN_Entity

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
int SXFMapEntDConvC::SetEntitydata(CString& IN_Entity)
{
	m_Entity = IN_Entity;
	return 0;
}

//エンティティ名の登録
	int	SetEntitydata(CString&);

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntDConvC.cpp						作成日：2000.04.17

	１．機能概要
		フォーチャデータをInteger型に変換する

	２．インターフェイス
		int		SXFMapEntDConvC::GetInt(int& OUT_Int)

	引数  ：	型			引数名				内容
				int& 		OUT_Int

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
int SXFMapEntDConvC::GetInt(int& OUT_Int)
{
	OUT_Int = atoi( m_Entity );

	return 0;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntDConvC.cpp						作成日：2000.04.17

	１．機能概要
		フォーチャデータをdouble型に変換する

	２．インターフェイス
		double		SXFMapEntDConvC::GetDouble(double& OUT_Double)

	引数  ：	型			引数名				内容
				double&		OUT_Double

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/

double SXFMapEntDConvC::GetDouble(double& OUT_Double)
{
	OUT_Double=atof( m_Entity );

	return 0;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntDConvC.cpp						作成日：2000.04.17

	１．機能概要
		フィーチャデータをdouble型に変換する

	２．インターフェイス
		void	CString SXFMapEntDConvC::GetCString()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/

CString SXFMapEntDConvC::GetCString()
{
//	MOD(S)	チューニング対応	K.Naono	03.07.09
/*
	///////////////////////////////////////////////////////////////
	// ※ 要変更
	m_Entity.TrimLeft();
	int find=-1;
	find = m_Entity.Find("'");
	if (find != -1)
		m_Entity = m_Entity.Mid(find+1);
	m_Entity.TrimRight();
	find = m_Entity.ReverseFind('\'');
	if (find != -1)
		m_Entity = m_Entity.Left(find);
*/
	consumeQuote(m_Entity) ;
//	MOD(E)	チューニング対応	K.Naono	03.07.09

	// コードの変換 UNI=>SJIS
//	MOD(S)	チューニング対応	K.Naono	03.07.11
//	char OUT_Char[MAXTEXT];		//文字列
	static char OUT_Char[MAXTEXT];		//文字列
//	MOD(E)	チューニング対応	K.Naono	03.07.11
//	SXFutyConvKanjiC::ConvKanji(DEF_ToJIS,(char*)(LPCTSTR)m_Entity,OUT_Char);
//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
//	SXFutyConvKanjiC::ToJIS((char*)(LPCTSTR)m_Entity,OUT_Char);
	SXFutyConvKanjiC::ToJIS((char*)(LPCTSTR)m_Entity,OUT_Char, _countof(OUT_Char));

	m_Entity  = OUT_Char;

	return m_Entity;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntDConvC.cpp						作成日：2000.04.17

	１．機能概要
		フィーチャデータをInstanceIDに変換する

	２．インターフェイス
		int		SXFMapEntDConvC::GetInst(int& OUT_Inst)

	引数  ：	型			引数名				内容
				int& 		OUT_Inst

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
int SXFMapEntDConvC::GetInst(int& OUT_Inst)
{
	m_Entity.TrimLeft();
	if(m_Entity[0] != '#')
		return -10000 ;
	m_Entity.TrimLeft('#') ;
	OUT_Inst = atoi(  m_Entity	);
	return 0;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntDConvC.cpp						作成日：2000.04.17

	１．機能概要
		フィーチャデータをBOOL型に変換する
	//BOOL (TRUE,FALSE)
	//LOGICAL 論理型（TRUE、FALSE、UNKNOWN）

	２．インターフェイス
		int		SXFMapEntDConvC::GetBOOL(
			BOOL& OUT_BOOL)

	引数  ：	型			引数名				内容
				BOOL& 		OUT_BOOL

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
int SXFMapEntDConvC::GetBOOL(BOOL& OUT_BOOL)
{
	if ( m_Entity.Find(DEF_D_T) != -1 ){ 
		OUT_BOOL=TRUE;
		return 0;
	}
	if ( m_Entity.Find(DEF_D_F) != -1 ){ 
		OUT_BOOL=FALSE;
		return 0;
	}
	if ( m_Entity.Find(DEF_D_UNSPECIFIED) != -1 ){ 
		OUT_BOOL=TRUE;
		return 0;
	}

	return -10000;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntDConvC.cpp						作成日：2000.04.17

	１．機能概要
		セット型のフォーチャデータをInstanceIDに変換する

	２．インターフェイス
		int		SXFMapEntDConvC::GetSetInst(
				int& Out_num,
				CArray<int,int>& Out_Intarray);

	引数 ：	型					引数名				内容
			int& 				Out_num
			CArray<int,int>& 	Out_Intarray

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/

int	SXFMapEntDConvC::GetSetInt( int& OUT_Num	
							 ,CArray<int,int>& OUT_Instarray )
{

	OUT_Instarray.RemoveAll();

	m_Entity.TrimLeft();
	m_Entity.TrimLeft('(');
	m_Entity.TrimRight();
	m_Entity.TrimRight(')');

//	MOD(S)	チューニング対応	K.Naono	03.07.03
/*
	ComSplitStringC split(m_Entity);
	m_Splitarray = split.Split(',');
	OUT_Num = m_Splitarray->GetSize(); 

	for(int i=0;i<OUT_Num;i++){
		OUT_Instarray.Add( atoi( (*m_Splitarray)[i] ) );
	}
*/
	CStringArray	array ;
	OUT_Num = GFn_SplitString(m_Entity, ',' , array) ;
	for(int i = 0; i < OUT_Num; i++) {
		OUT_Instarray.Add(atoi(array[i])) ;
	}
//	MOD(E)	チューニング対応	K.Naono	03.07.03

	return 0;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntDConvC.cpp						作成日：2000.04.17

	１．機能概要
		セット型のフォーチャデータをdoubleに変換する

	２．インターフェイス
		int		SXFMapEntDConvC::GetSetDouble(
				int& Out_num,
				CArray<double,double>& Out_Intarray);

	引数 ：	型						引数名				内容
			int& 					OUT_Num
			CArray<double,double>&	OUT_Instarray

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
int	SXFMapEntDConvC::GetSetDouble( int& OUT_Num	
							 ,CArray<double,double>&  OUT_Instarray )
{

	OUT_Instarray.RemoveAll();

	m_Entity.TrimLeft('(');
	m_Entity.TrimLeft();
	m_Entity.TrimRight(')');
	m_Entity.TrimRight();

//	MOD(S)	チューニング対応	K.Naono	03.07.03
/*
	ComSplitStringC split(m_Entity);

	m_Splitarray = split.Split(',');

	OUT_Num = m_Splitarray->GetSize();	

	for(int i=0;i<OUT_Num;i++){
		OUT_Instarray.Add( atof( (*m_Splitarray)[i] ) );
	}
*/
	CStringArray	array ;
	OUT_Num = GFn_SplitString(m_Entity, ',' , array) ;
	for(int i = 0; i < OUT_Num; i++) {
		OUT_Instarray.Add(atof(array[i])) ;
	}
//	MOD(E)	チューニング対応	K.Naono	03.07.03

	return 0;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntDConvC.cpp						作成日：2000.04.17

	１．機能概要
		セット型のフィーチャデータをInstanceIDに変換する

	２．インターフェイス
		int		SXFMapEntDConvC::GetSetInst(
				int& Out_num,
				CArray<int,int>& Out_Intarray);

	引数 ：	型					引数名				内容
			int& 				OUT_Num
			CArray<int,int>& 	OUT_Instarray

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/

int	SXFMapEntDConvC::GetSetInst( int& OUT_Num	
							 ,CArray<int,int>& OUT_Instarray )
{

	OUT_Instarray.RemoveAll();

	m_Entity.TrimLeft();
	m_Entity.TrimLeft('(');
	m_Entity.TrimRight();
	m_Entity.TrimRight(')');
//	MOD(S)	チューニング対応	K.Naono	03.07.03
/*
	ComSplitStringC split(m_Entity);
	m_Splitarray = split.Split(',');

	if (m_Splitarray == NULL) return -10000; 

	OUT_Num = m_Splitarray->GetSize();		
	CString tmpstring;
	for(int i=0;i<OUT_Num;i++){
		tmpstring = 	(*m_Splitarray)[i];
		(*m_Splitarray)[i].TrimLeft();
		tmpstring.Find('#');
		(*m_Splitarray)[i].TrimLeft('#') ;
		OUT_Instarray.Add( atoi( (*m_Splitarray)[i] ) );
	}
*/
	CStringArray	array ;
	OUT_Num = GFn_SplitString(m_Entity, ',' , array) ;
	for(int i = 0; i < OUT_Num; i++) {
		array[i].TrimLeft() ;
		array[i].TrimLeft('#') ;
		OUT_Instarray.Add(atoi(array[i])) ;
	}
//	MOD(E)	チューニング対応	K.Naono	03.07.03

  return 0;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntDConvC.cpp						作成日：2000.04.17

	１．機能概要
		Set+Select型のdoubleへの変換

	２．インターフェイス
		int		SXFMapEntDConvC::GetSetSelectDouble(
						CString& IN_Select, 
						int& OUT_Num, 
						CArray<double,double>& OUT_array)

	引数 ：	型						引数名				内容
			CString& 				IN_Select
			int& 					OUT_Num
			CArray<double,double>& 	OUT_array

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/

int		SXFMapEntDConvC::GetSetSelectDouble(
						CString& IN_Select,
						int& OUT_Num,
						CArray<double,double>& OUT_array)

{
// SET+SELECT型の例
//#427 = TRIMMED_CURVE('trimmed_curve3', #426, (#422), (#421), .T., .CARTESIAN.);
//#521 = TRIMMED_CURVE('',#520,	(#516,PARAMETER_VALUE(0.0)),
//		(#517,PARAMETER_VALUE(12.383404246416728)), .T.,.PARAMETER.);
//#104 = TRIMMED_CURVE('trimmed_curve1', #103, 
//	(PARAMETER_VALUE(3.141593)),(PARAMETER_VALUE(0.)), .T., .PARAMETER.);


//#200	TEXT_STYLE_WITH_BOX_CHARACTERISTICS(
//	( BOX_HEIGHT(1.), BOX_WIDTH(1.),BOX_SLANT_ANGLE(0.),BOX_ROTATE_ANGLE(0.)) )

//	MOD(S)	チューニング対応	K.Naono	03.07.03
/*
	int IN_Mode = 2; 
	SXFSplitAP202C	split(IN_Mode, m_Entity) ;

	m_Splitarray = split.Split();
	OUT_Num = m_Splitarray->GetSize();

	CString tmpstring;
	for(int i=0;i<OUT_Num;i++){
		if ( (*m_Splitarray)[i].Find(IN_Select,0) ){
			tmpstring = (*m_Splitarray)[i];
			tmpstring.TrimLeft();			//先頭の空白を削除
			tmpstring.TrimLeft(IN_Select);	//
			tmpstring.TrimLeft();			
			tmpstring.TrimLeft('(');
			tmpstring.TrimRight();
			tmpstring.TrimRight(')');
			OUT_array.Add( atof( tmpstring ) );
		}
	}

	return 0;
*/
	return GetSetSelectDouble((char*)(LPCTSTR)IN_Select, OUT_Num, OUT_array) ;
//	MOD(E)	チューニング対応	K.Naono	03.07.03
}

//			Set+Select型のdoubleへの変換
int		SXFMapEntDConvC::GetSetSelectDouble(
						char* IN_Select, 
						int& OUT_Num, 
						CArray<double,double>& OUT_array)

{

	CString tmpstring;
	m_Entity.TrimLeft();
	m_Entity.TrimLeft("(");
	tmpstring = m_Entity;
	m_Entity.Delete( tmpstring.GetLength()-1,1);

	OUT_array.RemoveAll();

//	MOD(S)	チューニング対応	K.Naono	03.07.03
/*
	ComSplitStringC split(m_Entity);
	m_SplitarrayPP = split.Split(',');
	m_SplitarrayTT.Copy(*m_SplitarrayPP);
	OUT_Num = m_SplitarrayTT.GetSize();
	for(int i=0;i<OUT_Num;i++){
		if ( m_SplitarrayTT[i].Find(IN_Select,0) != -1 ){
			tmpstring = m_SplitarrayTT[i];
			tmpstring.TrimLeft();			//先頭の空白を削除
			tmpstring.TrimLeft(IN_Select);	//
			tmpstring.TrimLeft();
			tmpstring.TrimLeft('(');
			tmpstring.TrimRight();
			tmpstring.TrimRight(')');
			OUT_array.Add( atof( tmpstring ) );
		}
	}
*/
	CStringArray	array ;
	OUT_Num = GFn_SplitString(m_Entity, ',' , array) ;
	for(int i = 0; i < OUT_Num; i++) {
		if ( array[i].Find(IN_Select,0) == -1 ) {
			continue ;
		}
		array[i].TrimLeft() ;			//先頭の空白を削除
		array[i].TrimLeft(IN_Select) ;
		array[i].TrimLeft() ;
		array[i].TrimLeft('(') ;
		array[i].TrimRight() ;
		array[i].TrimRight(')') ;
		OUT_array.Add(atof(array[i])) ;
	}
//	MOD(E)	チューニング対応	K.Naono	03.07.03

	return 0;
}

////////////////////////////////////////////////////////////////////////
/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntDConvC.cpp						作成日：2000.04.17

	１．機能概要
		Select型のdoubleへの変換

	２．インターフェイス
		int		SXFMapEntDConvC::GetSelectDouble(
					CString& IN_Select, 
					double &OUT_Double )

	引数  ：	型			引数名				内容
				CString& 	IN_Select
				double 		&OUT_Double

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
////////////////////////////////////////////////////////////////////////
//	Select型のdoubleへの変換
int	SXFMapEntDConvC::GetSelectDouble( 
			CString& IN_Select, 
			double &OUT_Double )
{
	//SELECT+double型の例
	//TEXT_STYLE_WITH_SPACING(LENGTH_MEASURE(0.2)) ;
	//入力データ==> LENGTH_MEASURE(0.2)

//	MOD(S)	チューニング対応	K.Naono	03.07.10
/*
	m_Entity.TrimLeft();		//先頭の空白を削除
	if (m_Entity.Find(IN_Select)!=-1 ){

		m_Entity.TrimLeft(IN_Select);	//
		m_Entity.TrimLeft();
		m_Entity.TrimLeft('(');
		m_Entity.TrimRight();
		m_Entity.TrimRight(')');
		OUT_Double =  atof( m_Entity ) ;
	}
	else{
		return -10000;
	}
	return 0;
*/
	return GetSelectDouble((char*)(LPCTSTR)IN_Select, OUT_Double) ;
//	MOD(E)	チューニング対応	K.Naono	03.07.10
}

////////////////////////////////////////////////////////////////////////
int	SXFMapEntDConvC::GetSelectDouble( 
			char* IN_Select, 
			double &OUT_Double )
{
	//SELECT+double型の例
	//TEXT_STYLE_WITH_SPACING(LENGTH_MEASURE(0.2)) ;
	//入力データ==> LENGTH_MEASURE(0.2)
	
	m_Entity.TrimLeft();		//先頭の空白を削除
	if (m_Entity.Find(IN_Select)!=-1 ){

		m_Entity.TrimLeft(IN_Select);
		m_Entity.TrimLeft();
		m_Entity.TrimLeft('(');
		m_Entity.TrimRight();
		m_Entity.TrimRight(')');
		OUT_Double =  atof( m_Entity ) ;
	}
	else{
		return -10000;
	}
	return 0;
}


////////////////////////////////////////////////////////////////////////
//	<Select型の CString への変換>
BOOL	SXFMapEntDConvC::GetSelectCString(
			CString& IN_Select, CString& OUT_CString)

{
	//SELECT+CString 型の例
	//#181 = EXTERNAL_SOURCE(IDENTIFIER('\X2\FF2DFF33002030B430B730C330AF\X0\-15-3'));
	//#180 = EXTERNALLY_DEFINED_TEXT_FONT(IDENTIFIER('\X2\FF2DFF33002030B430B730C330AF\X0\-15-3'), #181);
	//入力データ==>IDENTIFIER('\X2\FF2DFF33002030B430B730C330AF\X0\-15-3'

	///////////////////////////////////////////////////////////////
	//	SELECTの文字列と前後のかっこ削除
	TrimSelect(IN_Select,OUT_CString);

	///////////////////////////////////////////////////////////////
	// ※ 要変更
	int find=-1;
	find = OUT_CString.Find("'");
	if (find != -1)
		OUT_CString = OUT_CString.Mid(find+1);
	OUT_CString.TrimRight();
	find = OUT_CString.ReverseFind('\'');
	if (find != -1)
		OUT_CString = OUT_CString.Left(find);

	// コードの変換 UNI=>SJIS
//	MOD(S)	チューニング対応	K.Naono	03.07.11
//	char OUT_Char[MAXTEXT];		//文字列
	static char OUT_Char[MAXTEXT];		//文字列
//	MOD(E)	チューニング対応	K.Naono	03.07.11
//	SXFutyConvKanjiC::ConvKanji(DEF_ToJIS,(char*)(LPCTSTR)OUT_CString,OUT_Char);
//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
//	SXFutyConvKanjiC::ToJIS((char*)(LPCTSTR)OUT_CString,OUT_Char);
	SXFutyConvKanjiC::ToJIS((char*)(LPCTSTR)OUT_CString,OUT_Char, _countof(OUT_Char));

	OUT_CString  = OUT_Char;

	return TRUE;
}

BOOL	SXFMapEntDConvC::GetSelectCString(
			char* IN_Select, CString& OUT_CString)
{
	//SELECT+CString 型の例
	//#181 = EXTERNAL_SOURCE(IDENTIFIER('\X2\FF2DFF33002030B430B730C330AF\X0\-15-3'));
	//#180 = EXTERNALLY_DEFINED_TEXT_FONT(IDENTIFIER('\X2\FF2DFF33002030B430B730C330AF\X0\-15-3'), #181);
	//入力データ==>IDENTIFIER('\X2\FF2DFF33002030B430B730C330AF\X0\-15-3'

	///////////////////////////////////////////////////////////////
	//	SELECTの文字列と前後のかっこ削除
	TrimSelect(IN_Select,OUT_CString);

	///////////////////////////////////////////////////////////////
	// ※ 要変更
//	MOD(S)	チューニング対応	K.Naono	03.07.09
/*
	int find=-1;
	find = OUT_CString.Find("'");
	if (find != -1)
		OUT_CString = OUT_CString.Mid(find+1);
	OUT_CString.TrimRight();
	find = OUT_CString.ReverseFind('\'');
	if (find != -1)
		OUT_CString = OUT_CString.Left(find);
*/
	consumeQuote(OUT_CString) ;
//	MOD(E)	チューニング対応	K.Naono	03.07.09

	// コードの変換 UNI=>SJIS
//	MOD(S)	チューニング対応	K.Naono	03.07.11
//	char OUT_Char[MAXTEXT];		//文字列
	static char OUT_Char[MAXTEXT];		//文字列
//	MOD(E)	チューニング対応	K.Naono	03.07.11
//	SXFutyConvKanjiC::ConvKanji(DEF_ToJIS,(char*)(LPCTSTR)OUT_CString,OUT_Char);
//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
//	SXFutyConvKanjiC::ToJIS((char*)(LPCTSTR)OUT_CString,OUT_Char);
	SXFutyConvKanjiC::ToJIS((char*)(LPCTSTR)OUT_CString,OUT_Char, _countof(OUT_Char));

	OUT_CString  = OUT_Char;

	return TRUE;
}

////////////////////////////////////////////////////////////////////////

// SELECT型の文字列削除 IDENTIFIER('XXXXXX')=>XXXXXX (文字コード変換なし)

BOOL	SXFMapEntDConvC::TrimSelect( 
			char* IN_Select, 
			CString &OUT_CString )
{
	//SELECT+CString 型の例
	//#181 = EXTERNAL_SOURCE(IDENTIFIER('\X2\FF2DFF33002030B430B730C330AF\X0\-15-3'));
	//#180 = EXTERNALLY_DEFINED_TEXT_FONT(IDENTIFIER('\X2\FF2DFF33002030B430B730C330AF\X0\-15-3'), #181);
	//入力データ==>IDENTIFIER('\X2\FF2DFF33002030B430B730C330AF\X0\-15-3'
	
	m_Entity.TrimLeft();		//先頭の空白を削除
	if (m_Entity.Find(IN_Select)!=-1 ){
		m_Entity.TrimLeft(IN_Select);	//
		m_Entity.TrimLeft();
		m_Entity.TrimLeft('(');
		m_Entity.TrimRight();
		m_Entity.TrimRight(')');
		OUT_CString =  m_Entity ;
	}
	else{
		return FALSE;
	}
	return TRUE;
}

// SELECT型の文字列削除 IDENTIFIER('XXXXXX')=>XXXXXX (文字コード変換なし)

BOOL	SXFMapEntDConvC::TrimSelect( 
			CString& IN_Select, 
			CString &OUT_CString )
{
	//SELECT+CString 型の例
	//#181 = EXTERNAL_SOURCE(IDENTIFIER('\X2\FF2DFF33002030B430B730C330AF\X0\-15-3'));
	//#180 = EXTERNALLY_DEFINED_TEXT_FONT(IDENTIFIER('\X2\FF2DFF33002030B430B730C330AF\X0\-15-3'), #181);
	//入力データ==>IDENTIFIER('\X2\FF2DFF33002030B430B730C330AF\X0\-15-3'
	
	m_Entity.TrimLeft();		//先頭の空白を削除
	if (m_Entity.Find(IN_Select)!=-1 ){
		m_Entity.TrimLeft(IN_Select);	//
		m_Entity.TrimLeft();
		m_Entity.TrimLeft('(');
		m_Entity.TrimRight();
		m_Entity.TrimRight(')');
		OUT_CString =  m_Entity ;
	}
	else{
		return FALSE;
	}
	return TRUE;
}

////////////////////////////////////////////////////////////////////////

//	DEL(S)	チューニング対応	K.Naono
/*
//	前後の括弧（） を削除する
BOOL SXFMapEntDConvC::TrimKako(CString*& INOUT_CString)
{
	INOUT_CString->TrimLeft();
	if (INOUT_CString->Find('(')!=1 ) return FALSE;
	INOUT_CString->Delete(0,1);
	INOUT_CString->TrimRight();
	CString tmpstring;
	tmpstring = *INOUT_CString;
	if (INOUT_CString->Find('(')!= (tmpstring.GetLength()-1) ) return FALSE;
	tmpstring = *INOUT_CString;
	INOUT_CString->Delete(tmpstring.GetLength()-1,1);

	return TRUE;
}
*/
//	DEL(E)	チューニング対応	K.Naono

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapEntDConvC.cpp						作成日：2000.04.17

	１．機能概要
		セット型のフィーチャデータをCStringArrayに変換する

	２．インターフェイス
		int		SXFMapEntDConvC::ConvCStringArray()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/

int	SXFMapEntDConvC::ConvCStringArray()
{

	m_Entity.TrimLeft();
	m_Entity.TrimLeft('(');
	m_Entity.TrimRight();
	m_Entity.TrimRight(')');

//	MOD(S)	チューニング対応	K.Naono	03.07.03
/*
	ComSplitStringC split(m_Entity);
	m_Splitarray = split.Split(',');

	int array_num = m_Splitarray->GetSize();

	return array_num;
*/
	CStringArray	array ;
	return GFn_SplitString(m_Entity, ',' , array) ;
//	MOD(E)	チューニング対応	K.Naono	03.07.03
}

