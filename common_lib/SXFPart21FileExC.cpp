//---------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFPart21FileC.cpp					作成日：2001.09.17
//
//	１．クラス概要
//		ファイルの入力を管理する
//
//	２．履歴
//		履歴番号	日付け		 担当者			概要
//		作成		2001.09.17	K.Naono(FQS)	ヘッダ解析処理の改善対応
//
//---------------------------------------------------------
#include "stdafx.h"
#include "SXFPart21FileExC.h"
#include "SXFHeaderLex.h"
//#include "ComSplitStringC.h"
#include "SXFComncApi.h"
#include "SXFutyConvKanjiC.h"
#include "SXFComndef.h"

//////////////////////////////////////////////////////////////////////
// 構築/消滅
//////////////////////////////////////////////////////////////////////

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFPart21FileC.cpp					作成日：2001.09.17
//
//	１．機能概要
//		コンストラクタ
//
//	２．インターフェイス
//		SXFPart21FileExC::SXFPart21FileExC(
//						LPCTSTR	IN_lpszFileName,
//						UINT	IN_nOpenFlags)
//
//		引数: 型				引数名				内容
//				LPCTSTR		IN_lpszFileName		ファイル名
//				UINT		IN_nOpenFlags		ファイルオープンモード
//
//		復帰値	なし
//
//	３．履歴
//		履歴番号	日付け		 担当者			概要
//		作成		2001.09.17	K.Naono(FQS)
//---------------------------------------------------------
SXFPart21FileExC::SXFPart21FileExC(
						LPCTSTR	IN_lpszFileName,
						UINT	IN_nOpenFlags)
				:SXFPart21FileC(IN_lpszFileName, IN_nOpenFlags)
{
	m_pDataLex		= NULL ;
	m_pDataRecord	= NULL ;
}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFPart21FileC.cpp					作成日：2001.09.17
//
//	１．機能概要
//		デストラクタ
//
//	２．インターフェイス
//		SXFPart21FileExC::~SXFPart21FileExC()
//
//		引数:	なし
//
//		復帰値	なし
//
//	３．履歴
//		履歴番号	日付け		 担当者			概要
//		作成		2001.09.17	K.Naono(FQS)
//---------------------------------------------------------
SXFPart21FileExC::~SXFPart21FileExC()
{
	if( m_pDataLex )
		delete m_pDataLex ;

	if( m_pDataRecord )
		delete m_pDataRecord ;
}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFPart21FileC.cpp					作成日：2001.09.17
//
//	１．機能概要
//		Head Section部分を読み込む
//
//	２．インターフェイス
//		int SXFPart21FileExC::ReadHeadSection(
//							HEADSECTION*	IO_Head)
//
//		引数: 型				引数名				内容
//			HEADSECTION*	IO_Head				HeadSectionの
//												構造体のアドレス
//		復帰値
//			正常時： 1 : OK
//			異常時：
//					-1 : file end
//					-2 : found syntax error 
//					-3 : can not to find a headsection
//
//	３．履歴
//		履歴番号	日付け		 担当者			概要
//		作成		2001.09.17	K.Naono(FQS)
//---------------------------------------------------------
int SXFPart21FileExC::ReadHeadSection(HEADSECTION* IO_Head)
{
	ASSERT(IO_Head) ;
	if( IO_Head == NULL ) {
		return -1 ;
	}

	//	HEADER ～ ENDSECまでを読み込む
	CString	buffer ;
	CString	record ;

	while( ReadString(record) ) {
		record.TrimLeft() ;
		record.TrimRight() ;
		buffer += record ;
		if( record.Find(ID_ENDSEC) != -1 )
			break ;
	}
	if( buffer.GetLength() == 0 ) {
		return -3 ;
	}

	//	字句の解析を始める
	BOOL			bExistHeader = FALSE ;
	CStringArray	array ;
	int token = 0, ret = 0 ;
	CSXFHeaderLex*	pLex = new CSXFHeaderLex(buffer) ;
	while( (token = pLex->Lex()) != TT_EOF ) {

		switch(token) {
		case TT_FILE_DESCRIPTION :
			//	属性値の取得
			getAttribute(pLex, array) ;

			//	属性値の解析
			if( (ret = analyzeDescription(array, IO_Head)) == 1 ) {
				break ;
			}
			delete pLex ;
			if( ret == 0 ) {
				return ret ;
			} else {
				return !bExistHeader ? -3 : ret ;
			}
			break ;

		case TT_FILE_NAME :
			//	属性値の取得
			getAttribute(pLex, array) ;

			//	属性値の解析
			if( (ret = analyzeName(array, IO_Head)) < 0 ) {
				delete pLex ;
				return !bExistHeader ? -3 : ret ;
			}
			break ;

		case TT_FILE_SCHEMA :
			break ;

		case TT_HEADER :
			bExistHeader = TRUE ;
			break ;

		case TT_ENDSEC :
			bExistHeader = FALSE ;
			break ;
		}
	}

	delete pLex ;

	return 1 ;
}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFPart21FileC.cpp					作成日：2001.09.17
//
//	１．機能概要
//		Part21 FileのFILE_DESCRIPTION部分を解析する
//
//	２．インターフェイス
//		int SXFPart21FileExC::analyzeDescription(
//							CStringArray&	array,
//							HEADSECTION*	IO_Head)
//
//		引数: 型				引数名				内容
//			CStringArray&		array			属性値
//			HEADSECTION*		IO_Head			HeadSectionの
//												構造体のアドレス
//		復帰値	
//			正常時： 1 : OK
//			異常時：
//					-1 : file end
//					-2 : found syntax error 
//					-3 : can not to find a headsection
//
//	３．履歴
//		履歴番号	日付け		 担当者			概要
//		作成		2001.09.17	K.Naono(FQS)
//---------------------------------------------------------
int SXFPart21FileExC::analyzeDescription(
							CStringArray&	array,
							HEADSECTION*	IO_Head)
{
	if( array.GetSize() != 2 ) {
		return -2 ;
	}

//	MOD(S)	チューニング対応	K.Naono	03.07.03
/*
	CStringArray*	pElem ;
	ComSplitStringC split(array[0]) ;
	pElem = split.Split(' ') ;
	if( pElem->GetSize() < 3 ) {
		return -2 ;
	}
	//	SCADEC以外のファイル
	if( (*pElem)[0] != ID_SCADEC ) {
		return 0 ;
	}

	//	SCADEC flg をON
	IO_Head->scadec_flg = 1 ;
	for(int i = 0; i < pElem->GetSize(); i++) {
		//	レベル
		if( !(*pElem)[i].CompareNoCase(ID_LEVEL1) ) {
			IO_Head->Level = 1 ;

		} else if( !(*pElem)[i].CompareNoCase(ID_LEVEL2) ) {
			IO_Head->Level = 2 ;

		//	モード
		} else if( !(*pElem)[i].CompareNoCase(ID_AMBI_MODE) ) {
			IO_Head->Mode = 0 ;

		} else if( !(*pElem)[i].CompareNoCase(ID_FEATURE_MODE) ) {
			IO_Head->Mode = 1 ;

		} else if( !(*pElem)[i].CompareNoCase(ID_AP202_MODE) ) {
			IO_Head->Mode = 2 ;
		}
	}
*/
	CStringArray	arElem ;
	int	nCount = GFn_SplitString(array[0], ' ' , arElem) ;
	if( nCount < 3 ) {
		return -2 ;
	}
	//	SCADEC以外のファイル
	if( arElem[0] != ID_SCADEC ) {
		return 0 ;
	}

	//	SCADEC flg をON
	IO_Head->scadec_flg = 1 ;
	for(int i = 0; i < nCount; i++) {
		//	レベル
		if( !arElem[i].CompareNoCase(ID_LEVEL1) ) {
			IO_Head->Level = 1 ;

		} else if( !arElem[i].CompareNoCase(ID_LEVEL2) ) {
			IO_Head->Level = 2 ;

		//	モード
		} else if( !arElem[i].CompareNoCase(ID_AMBI_MODE) ) {
			IO_Head->Mode = 0 ;

		} else if( !arElem[i].CompareNoCase(ID_FEATURE_MODE) ) {
			IO_Head->Mode = 1 ;

		} else if( !arElem[i].CompareNoCase(ID_AP202_MODE) ) {
			IO_Head->Mode = 2 ;
		}
	}
//	MOD(E)	チューニング対応	K.Naono	03.07.03

	return 1 ;
}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFPart21FileC.cpp					作成日：2001.09.17
//
//	１．機能概要
//		Part21 FileのFILE_NAME部分を解析する
//
//	２．インターフェイス
//		int SXFPart21FileExC::analyzeName(
//							CStringArray&	array,
//							HEADSECTION*	IO_Head)
//
//		引数: 型				引数名				内容
//			CStringArray&		array			属性値
//			HEADSECTION*		IO_Head			HeadSectionの
//												構造体のアドレス
//		復帰値	
//			正常時： 1 : OK
//			異常時：
//					-1 : file end
//					-2 : found syntax error 
//					-3 : can not to find a headsection
//
//	３．履歴
//		履歴番号	日付け		 担当者			概要
//		作成		2001.09.17	K.Naono(FQS)
//---------------------------------------------------------
int SXFPart21FileExC::analyzeName(
							CStringArray&	array,
							HEADSECTION*	IO_Head)
{
	if( array.GetSize() != 7 ) {
		return -2 ;
	}

	TCHAR	buffer[257] ;
	//	name属性値の取得
//	SXFutyConvKanjiC::ConvKanji(DEF_ToJIS,
	SXFutyConvKanjiC::ToJIS(
//					(char*)(LPCTSTR)array[0], buffer) ;	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
					(char*)(LPCTSTR)array[0], buffer, _countof(buffer)) ;
	IO_Head->FileName = buffer ;

	//	author属性値の取得
//	SXFutyConvKanjiC::ConvKanji(DEF_ToJIS,
	SXFutyConvKanjiC::ToJIS(
//					(char*)(LPCTSTR)array[2], buffer) ;	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
					(char*)(LPCTSTR)array[2], buffer, _countof(buffer)) ;
	IO_Head->Author = buffer ;

	//	organization属性値の取得
//	SXFutyConvKanjiC::ConvKanji(DEF_ToJIS,
	SXFutyConvKanjiC::ToJIS(
//					(char*)(LPCTSTR)array[3], buffer) ;	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
					(char*)(LPCTSTR)array[3], buffer, _countof(buffer)) ;
	IO_Head->Organization = buffer ;

	//	preprocessor_version属性値の取得
//	SXFutyConvKanjiC::ConvKanji(DEF_ToJIS,
	SXFutyConvKanjiC::ToJIS(
//					(char*)(LPCTSTR)array[4], buffer) ;	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
					(char*)(LPCTSTR)array[4], buffer, _countof(buffer)) ;
	IO_Head->Version = buffer ;

	//	originating_system属性値の取得
//	SXFutyConvKanjiC::ConvKanji(DEF_ToJIS,
	SXFutyConvKanjiC::ToJIS(
//					(char*)(LPCTSTR)array[5], buffer) ;	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
					(char*)(LPCTSTR)array[5], buffer, _countof(buffer)) ;
	IO_Head->OriginatingSystem = buffer ;

	return 1 ;
}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFPart21FileC.cpp					作成日：2001.09.17
//
//	１．機能概要
//		Part21 Fileのエンティティの属性値を取得する
//
//	２．インターフェイス
//		void SXFPart21FileExC::getAttribute(
//							CSXFHeaderLex*	pLex,
//							CStringArray&	array)
//
//		引数: 型				引数名				内容
//			CSXFHeaderLex*		pLex			Lexオブジェクト
//			CStringArray&		array			属性値格納用配列
//
//		復帰値
//			なし
//
//	３．履歴
//		履歴番号	日付け		 担当者			概要
//		作成		2001.09.17	K.Naono(FQS)
//---------------------------------------------------------
void SXFPart21FileExC::getAttribute(
					CSXFHeaderLex*	pLex,
					CStringArray&	array)
{
	if( array.GetSize() > 0 ) {
		array.RemoveAll() ;
	}

//	CString	key ;
	int token ;
	while( (token = pLex->Lex()) != ';' ) {
//	ADD(S)	バグ修正	K.Naono	03.05.29
		if( token == TT_EOF ) break ;
//	ADD(E)	バグ修正	K.Naono	03.05.29

		// 読み飛ばし
		if( token == ' ' || token == '\t' )	continue ;

		if( token == TT_LINE_COMMENT ) {
			while((token = pLex->Lex()) != TT_EOL) ;
			continue ;
		}
		if( token == TT_BLOCK_COMMENT_START ) {
//			while((token = pLex->Lex()) != TT_BLOCK_COMMENT_END) ;
			while( (token = pLex->Lex()) != TT_EOF ) {
				if( token == TT_BLOCK_COMMENT_END )
					break ;
			}
			continue ;
		}

		switch(token) {
		// キーワード
		case TT_IDENTIFIER :
		case TT_STRING :
			array.Add(pLex->GetTokenImage()) ;
			break ;

		default :
			break ;
		}
	}
}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFPart21FileC.cpp					作成日：2001.05.25
//
//	１．機能概要
//		一つのInstanceを読み込む
//
//	２．インターフェイス
//		int ReadInstance(INSTANCEDATA *IO_Instance)
//
//		引数: 型			引数名				内容
//			INSTANCEDATA*	IO_Instance			Instance Dataの
//													構造体のアドレス
//		復帰値	
//			正常時： 1 :	OK
//			異常時：-1 :	file end
//					-2 :	found syntax error
//					-3 :	can not to find a ap202 instance
//							in this file
//					-4 :	can not to find a feature instance
//							in this file 
//
//	３．履歴
//		履歴番号	日付け		 担当者		概要
//		作成		2003.07.04	K.Naono		チューニング対応
//---------------------------------------------------------
int SXFPart21FileExC::ReadInstance(INSTANCEDATA* IO_Instance)
{
	CString	recordline ;
	CString	record ;

	while( ReadString(recordline) ) {
		recordline.TrimLeft() ; recordline.TrimRight() ;

		//	コメントであれば、コメントを読み飛ばす
		if( recordline.Find("/*") != -1 )
			skippedComment(recordline) ;

		if( recordline.GetLength() == 0 )
			continue;

		record += recordline ;

		if( record.Right(1) == ";" ) {
			break ;
		}
	}

	//	ファイルを最後まで読んだ
	if( record.GetLength() == 0 ) {
		//	ﾌｨｰﾁｬｲﾝｽﾀﾝｽが一つもない
		if( ap202count == 0 )
			return -3 ; 
		return -1 ;//file end
	}

	record.TrimRight(';') ;

	if(record[0] != '#') {
		return -2 ;
	}

	ap202count++ ;//ap202 instance count ++

	int	findequalsign = record.Find('=') ;
	if (findequalsign < 2) 
		return -2 ;//found syntax error in file

	//	インスタンス番号を取得
	CString	idstring = record.Mid(1, findequalsign - 1) ;
	idstring.TrimLeft() ;
	idstring.TrimRight() ;
	int	instanceid = atoi(idstring) ;
	if (instanceid <= 0)
		return -2;//found syntax error in file
	IO_Instance->InstanceID = instanceid ;

	//	エンティティの属性情報を取得
	CString datastring = record.Right(record.GetLength()
									- findequalsign - 1) ;
	datastring.TrimLeft() ;
	datastring.TrimRight() ;
	int	findfirstparentheses = datastring.Find('(') ;
	if (findfirstparentheses < 0) {
		return -2;//found syntax error in file

	//	複合エンティティの場合
	} else if( findfirstparentheses == 0 ) {
		IO_Instance->EntityName = DEF_SXF_COMPLEX_INSTANCE;
					// if a complex instance 
					// then set entity name:
					// "SXF_COMPLEX_INSTANCE"
		IO_Instance->EntityData = datastring ;

	//	単純エンティティの場合
	} else {
		IO_Instance->EntityName = datastring.Left( findfirstparentheses);
		IO_Instance->EntityName.TrimRight();
		IO_Instance->EntityData = datastring.Right(
						datastring.GetLength() - findfirstparentheses) ;
		IO_Instance->EntityData.TrimLeft() ;
	}

	//	定義テーブル情報
	if( IO_Instance->EntityName == DEF_PRESENTATION_LAYER_USAGE ||
		IO_Instance->EntityName == DEF_DRAUGHTING_PRE_DEFINED_CURVE_FONT ||
		IO_Instance->EntityName == DEF_COLOUR_RGB ||
		IO_Instance->EntityName == DEF_DRAUGHTING_PRE_DEFINED_COLOUR ||
		IO_Instance->EntityName == DEF_LENGTH_MEASURE_WITH_UNIT ||
		IO_Instance->EntityName == DEF_EXTERNALLY_DEFINED_TEXT_FONT ||
		IO_Instance->EntityName == DEF_CURVE_STYLE_FONT)
	{
		IO_Instance->InstanceMode = SXF_IM_AP_TABLE ;

	//	アセンブリ情報
	} else if (	IO_Instance->EntityName == DEF_SYMBOL_REPRESENTATION_MAP ||
				IO_Instance->EntityName == DEF_DRAWING_SHEET_REVISION_USAGE ||
				IO_Instance->EntityName == DEF_COMPOSITE_CURVE ) {
		IO_Instance->InstanceMode = SXF_IM_AP_ASSEMBLY ;

	} else if (	IO_Instance->EntityName == DEF_INVISIBILITY ) {
		IO_Instance->InstanceMode = SXF_IM_AP_INVISIBILITY ;

	} else if (	IO_Instance->EntityName == DEF_PRESENTATION_SIZE ) {
		IO_Instance->InstanceMode = SXF_IM_AP_PRESENTATION_SIZE ;

	} else if (	IO_Instance->EntityName == DEF_DRAUGHTING_TITLE ) {
		IO_Instance->InstanceMode = SXF_IM_AP_DRAUGHTING_TITLE ;

//	ADD(S)	Ver3.0対応	K.Naono	04.01.30
	} else if (	IO_Instance->EntityName == DEF_DRAUGHTING_CONTRACT_ASSIGNMENT ||
				IO_Instance->EntityName == DEF_DRAUGHTING_APPROVAL_ASSIGNMENT ||
				IO_Instance->EntityName == DEF_APPROVAL_DATE_TIME ||
				IO_Instance->EntityName == DEF_DRAUGHTING_ORGANIZATION_ASSIGNMENT ) {
		IO_Instance->InstanceMode = SXF_IM_AP_ATTRIBUTE ;
//	ADD(E)	Ver3.0対応	K.Naono	04.01.30
	} else {
		IO_Instance->InstanceMode = SXF_IM_AP_ENTITY ;
	}

	return 1 ;
}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2003
//	SXFPart21FileC.cpp						作成日：2003.07.04
//
//	１．機能概要
//		コメントを読み飛ばす
//
//	２．インターフェイス
//		void skippedComment(CString& strRecord)
//
//		引数: 型			引数名			内容
//			CString&		strRecord		現在読み込み中の文字列
//
//		復帰値	
//			なし
//
//	３．履歴
//		履歴番号	日付け		担当者		概要
//		作成		2003.07.04	K.Naono		チューニング対応
//---------------------------------------------------------
void SXFPart21FileExC::skippedComment(CString& strRecord)
{
	int		idx = strRecord.Find("/*") ;
	if( idx == -1 || isQuoteString(strRecord, idx) ) {
		return ;
	}

	CString	record, recordline ;

	//	コメント開始までの文字列取得
	if( idx > 0 ) {
		record = CString((LPCTSTR)strRecord, idx) ;
	}
	idx = strRecord.Find("*/") ;

	//	コメント終了がなければ、コメント終了まで読み飛ばす
	if( idx == -1 || (idx > 0 && isQuoteString(strRecord, idx)) ) {
		while( ReadString(recordline) ) {
			recordline.TrimLeft() ; recordline.TrimRight() ;
			idx = recordline.Find("*/") ;
			if( idx != -1 && !isQuoteString(recordline, idx) ) {
				if( idx != (recordline.GetLength() - 2) ) {
					record += CString((LPCTSTR)recordline + (idx + 2),
									recordline.GetLength() - (idx + 2)) ;
				} else {
					recordline.Empty() ;
				}
				break ;
			}
		}

	//	コメント終了が途中にあれば、コメント終了以降を取得
	} else if( idx != (strRecord.GetLength() - 2) ) {
		record += CString((LPCTSTR)strRecord + (idx + 2),
						strRecord.GetLength() - (idx + 2)) ;
	}
	record.TrimLeft() ;
	record.TrimRight() ;
	strRecord = record ;

	if( strRecord.Find("/*") != -1 )
		skippedComment(strRecord) ;
}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2003
//	SXFPart21FileC.cpp						作成日：2003.07.04
//
//	１．機能概要
//		コメント開始文字列(/*)が、文字列か否かを判定する
//
//	２．インターフェイス
//		void isQuoteString(CString& strRecord)
//
//		引数: 型			引数名			内容
//			CString&		strRecord		現在読み込み中の文字列
//			int				nIndex			コメント開始インデックス
//
//		復帰値	
//			TRUE	:属性内文字列
//			FALSE	:コメント
//
//	３．履歴
//		履歴番号	日付け		担当者		概要
//		作成		2003.07.04	K.Naono		チューニング対応
//---------------------------------------------------------
BOOL	SXFPart21FileExC::isQuoteString(
								CString&	strRecord,
								int			nIndex)
{
	bool	bQuote = false ;
	int		s_quote = 0, e_quote = 0 ;
	int		nLength = strRecord.GetLength() ;
	LPCTSTR	wp = (LPCTSTR)strRecord ;

	//	コメントインデックスより前を検査
	for(int i = nIndex - 1; i >= 0; i--) {
		if( wp[i] == '\'' ) {
			bQuote = !bQuote ;
		} else if( wp[i] == ',' ) {
			break ;
		}
	}
	if( !bQuote ) {
		return FALSE ;
	}
	//	'の開始インデックスを取得
	s_quote = i ;

	//	コメントインデックスより後ろを検査
	bQuote = false ;
	for(i = nIndex + 1; i < nLength; i++) {
		if( wp[i] == '\'' ) {
			bQuote = !bQuote ;
		} else if( wp[i] == ',' ) {
			break ;
		}
	}
	if( !bQuote ) {
		return FALSE ;
	}
	//	'の終了インデックスを取得
	e_quote = i ;

	//	'～'の間であれば、コメントではない
	if( nIndex > s_quote && nIndex < e_quote ) {
		return TRUE ;
	}

	return FALSE ;
}
