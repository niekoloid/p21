//---------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFPart21FileC.cpp					  作成日：2001.05.25
//
//	１．クラス概要
//      ファイルの入力と出力を管理する
//
//	２．履歴
//		履歴番号	日付け		 担当者		概要
//		作成		2001.05.25	佐々木(FQS)
//
//---------------------------------------------------------
#include "stdafx.h"
#include <afx.h>
//#include "ComSplitStringC.h"
#include "SXFDataStructC.h"
#include "SXFPart21FileC.h"
#include "SXFutyConvKanjiC.h"
#include "max.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFPart21FileC.cpp					  作成日：2001.05.25
//
//	１．機能概要
//		(コンストラクタ)
//
//	２．インターフェイス
//		SXFPart21FileC::SXFPart21FileC()
//
//	引数  ：	型				引数名				内容
//			なし	  
//
//	復帰値：なし
//
//	３．履歴
//		履歴番号	日付け		 担当者		概要
//		作成		2001.05.25	佐々木(FQS)
//---------------------------------------------------------
SXFPart21FileC::SXFPart21FileC()
{
	ap202count = 0;
	featurecount = 0;
}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFPart21FileC.cpp					  作成日：2001.05.25
//
//	１．機能概要
//		(コンストラクタ)
//
//	２．インターフェイス
//		void	SXFPart21FileC::SXFPart21FileC( 
//								LPCTSTR IN_lpszFileName,
//								UINT IN_nOpenFlags)
//
//	引数	：	型			引数名				内容
//				LPCTSTR		IN_lpszFileName		ファイル名
//				UINT		IN_nOpenFlags		ファイルオープンモード
//		
//	復帰値：なし
//
//	３．履歴
//		履歴番号	日付け			担当者		概要
//		作成		2001.05.25		佐々木(FQS)
//---------------------------------------------------------
SXFPart21FileC::SXFPart21FileC( FILE* IN_pOpenStream )
			   :CStdioFile( IN_pOpenStream )
{
	ap202count = 0;
	featurecount = 0;
}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFPart21FileC.cpp					  作成日：2001.05.25
//
//	１．機能概要
//		(コンストラクタ)
//
//	２．インターフェイス
//		void	SXFPart21FileC::SXFPart21FileC( 
//								LPCTSTR IN_lpszFileName,
//								UINT IN_nOpenFlags)
//
//	引数	：	型			引数名				内容
//				LPCTSTR		IN_lpszFileName		ファイル名
//				UINT		IN_nOpenFlags		ファイルオープンモード
//		
//	復帰値：なし
//
//	３．履歴
//		履歴番号	日付け			担当者		概要
//		作成		2001.05.25		佐々木(FQS)
//---------------------------------------------------------
SXFPart21FileC::SXFPart21FileC( LPCTSTR IN_lpszFileName,
								UINT IN_nOpenFlags)
			   :CStdioFile( IN_lpszFileName,IN_nOpenFlags )
{
	ap202count = 0;
	featurecount = 0;
}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFPart21FileC.cpp					  作成日：2001.05.25
//
//	１．機能概要
//		クラス消滅
//
//	２．インターフェイス
//
//
//	３．履歴
//		履歴番号	日付け		 担当者		概要
//		作成		2001.05.25	佐々木(FQS)
//---------------------------------------------------------
SXFPart21FileC::~SXFPart21FileC()
{
}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFPart21FileC.cpp					  作成日：2001.05.25
//
//	１．機能概要
//		Head Section部分を読み込む
//
//	２．インターフェイス
//		int ReadHeadSection(HEADSECTION *IO_Head)
//
//		引数: 型			  引数名				内容
//			  HEADSECTION*	  IO_Head			   HeadSectionの
//												   構造体のアドレス
//		復帰値	
//			  正常時：	1 : OK
//			  異常時： -1 : file end
//					  -2  : found syntax error 
//					  -3  : can not to find a headsection
//		
//
//	３．履歴
//		履歴番号	日付け		 担当者		概要
//		作成		2001.05.25	佐々木(FQS)
//---------------------------------------------------------
int SXFPart21FileC::ReadHeadSection(HEADSECTION *IO_Head)
{
	return 1;
}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFPart21FileC.cpp					  作成日：2001.05.25
//
//	１．機能概要
//		一つのInstanceを読み込む
//
//	２．インターフェイス
//		int ReadInstance(INSTANCEDATA *IO_Instance)
//
//		引数: 型			  引数名				内容
//			  INSTANCEDATA*   IO_Instance		   Instance Dataの
//												   構造体のアドレス
//		復帰値	
//			  正常時：	 1 :  OK
//			  異常時：	-1 :  file end
//					   -2 :  found syntax error
//					   -3 :  can not to find a ap202 instance
//							 in this file
//					   -4 :  can not to find a feature instance
//							 in this file 
//
//	３．履歴
//		履歴番号	日付け		 担当者		概要
//		作成		2001.05.25	佐々木(FQS)
//---------------------------------------------------------
int SXFPart21FileC::ReadInstance(INSTANCEDATA *IO_Instance)
{
	return 1;
}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFPart21FileC.cpp					  作成日：2001.05.25
//
//	１．機能概要
//
//		Head Section部を出力する
//
//	２．インターフェイス
//		BOOL WriteHeadSection(HEADSECTION *IN_Head)
//
//		引数: 型			  引数名				内容
//			  HEADSECTION*	  IN_Head			   Head Sectionの
//												   構造体のアドレス
//		復帰値	
//			  正常時： TRUE
//			  異常時：	FALSE
//
//	３．履歴
//		履歴番号	日付け		 担当者		概要
//		作成		2001.05.25	佐々木(FQS)
//---------------------------------------------------------
BOOL SXFPart21FileC::WriteHeadSection(HEADSECTION *IN_Head)
{
	CString headsection;
	CString tempstring;
	CString mode;
	CString endline("\n");
	headsection="ISO-10303-21;";
	headsection+=endline;
	headsection+="HEADER;";
	headsection+=endline;

	/* ﾓｰﾄﾞ */
	switch (IN_Head->Mode)
	{
	case 0:
		mode = "ambi_mode";
		break;
	case 1:
		mode = "feature_mode";
		break;
	case 2:
		mode = "AP202_mode";
		break;
	default:
		break;	 
	}
	/* level, modeの出力ﾌｫｰﾏｯﾄ作成 */
	tempstring.Format("FILE_DESCRIPTION(('SCADEC level%d %s'),\n",
					   IN_Head->Level,mode);
	headsection += tempstring;
	headsection += "		'2;1');";
	headsection+=endline;
	/* file name(need not path name) */
	CString filename = IN_Head->FileName;
	int backslash_find = filename.ReverseFind('\\');
	if (backslash_find != -1){
		filename = filename.Mid(backslash_find+1);
	}
	/* ﾌｧｲﾙ名をUNICODEへ変換 */
	char out_filename[MAXUNICODENAME];
//	SXFutyConvKanjiC::ConvKanji(DEF_FROMJIS,(char*)(LPCTSTR)filename,out_filename);
//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
//	SXFutyConvKanjiC::FromJIS((char*)(LPCTSTR)filename,out_filename);
	SXFutyConvKanjiC::FromJIS((char*)(LPCTSTR)filename,out_filename,_countof(out_filename));
	/* ﾌｧｲﾙ名の出力ﾌｫｰﾏｯﾄ作成 */
	tempstring.Format("FILE_NAME('%s',\n",out_filename);
	headsection += tempstring;
	//current date and time
	CTime currenttime=CTime::GetCurrentTime();
	tempstring.Format("		   '%d-%d-%dT%d:%d:%d',\n",
					  currenttime.GetYear(),
					  currenttime.GetMonth(),
					  currenttime.GetDay(),
					  currenttime.GetHour(),
					  currenttime.GetMinute(),
					  currenttime.GetSecond() );
	headsection += tempstring;
	/* authorをUNICODEに変換 */
	char out_author[MAXUNICODENAME];
//	SXFutyConvKanjiC::ConvKanji(DEF_FROMJIS,(char*)(LPCTSTR)IN_Head->Author,out_author);
//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
//	SXFutyConvKanjiC::FromJIS((char*)(LPCTSTR)IN_Head->Author,out_author);
	SXFutyConvKanjiC::FromJIS((char*)(LPCTSTR)IN_Head->Author,out_author,_countof(out_author));
	/* 出力ﾌｫｰﾏｯﾄ作成 */
	tempstring.Format("		   ('%s'),\n",out_author);
	headsection += tempstring;

	/* organization をUNICODEに変換 */
	char out_org[MAXUNICODENAME];
//	SXFutyConvKanjiC::ConvKanji(DEF_FROMJIS,(char*)(LPCTSTR)IN_Head->Organization,out_org);
//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
//	SXFutyConvKanjiC::FromJIS((char*)(LPCTSTR)IN_Head->Organization,out_org);
	SXFutyConvKanjiC::FromJIS((char*)(LPCTSTR)IN_Head->Organization,out_org,_countof(out_org));
	/* 出力ﾌｫｰﾏｯﾄ作成 */
	tempstring.Format("		   ('%s'),\n",out_org);
	headsection += tempstring;
	/* version 出力ﾌｫｰﾏｯﾄ作成 */
	tempstring.Format("		   '%s',\n",IN_Head->Version);
	headsection += tempstring;
	char out_orgsystem[MAXUNICODENAME];
	/* Originating system 出力ﾌｫｰﾏｯﾄ作成 */
//	SXFutyConvKanjiC::ConvKanji(DEF_FROMJIS,(char*)(LPCTSTR)IN_Head->OriginatingSystem,out_orgsystem);
//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
//	SXFutyConvKanjiC::FromJIS((char*)(LPCTSTR)IN_Head->OriginatingSystem,out_orgsystem);
	SXFutyConvKanjiC::FromJIS((char*)(LPCTSTR)IN_Head->OriginatingSystem,out_orgsystem,_countof(out_orgsystem));
	tempstring.Format("		   '%s',\n",out_orgsystem);
	/* ﾍｯﾀﾞｰ出力ﾌｫｰﾏｯﾄ作成 */
	headsection += tempstring;
	headsection += "		'');";
	headsection += endline;
	headsection += "FILE_SCHEMA(('ASSOCIATIVE_DRAUGHTING'));";
	headsection+=endline;
	headsection += "ENDSEC;";
	headsection+=endline;
	headsection += "DATA;";
	headsection+=endline;
	/* ﾍｯﾀﾞｰの出力 */
	WriteString(headsection);

	//単位インスタンスの出力
	if (IN_Head->Mode == 0 || IN_Head->Mode == 2){
		CString unit_instance;
		unit_instance = "#10=(";
		unit_instance += endline;
		unit_instance += "LENGTH_UNIT()";
		unit_instance += endline;
		unit_instance += "NAMED_UNIT(*)";
		unit_instance += endline;
		unit_instance += "SI_UNIT(.MILLI.,.METRE.)";
		unit_instance += endline;
		unit_instance += ");";
		unit_instance += endline;
		WriteString(unit_instance);
	}

	return TRUE;
}

//---------------------------------------------------------
//	All Rights Reserved,(c)JACIC 2001
//	SXFPart21FileC.cpp					  作成日：2001.05.25
//
//	１．機能概要
//		一つのInstanceを出力する
//
//	２．インターフェイス
//		BOOL WriteInstance(INSTANCEDATA *IN_Instance)
//
//		引数: 型			  引数名				内容
//			  INSTANCEDATA*   IN_Instance		   Instance Dataの
//												   構造体のアドレス
//		復帰値	
//			  正常時： TRUE
//			  異常時： FALSE
//
//
//	３．履歴
//		履歴番号	日付け		 担当者		概要
//		作成		2001.05.25	佐々木(FQS)
//---------------------------------------------------------
BOOL SXFPart21FileC::WriteInstance(INSTANCEDATA *IN_Instance)
{
	CString instance;

	switch (IN_Instance->InstanceMode)
	{
	case SXF_IM_COMMENT: //comment
		/* 出力ﾌｫｰﾏｯﾄ作成 */
		instance.Format("/*\n%s\n*/",IN_Instance->EntityData);
		break;
	case SXF_IM_SECTIONMARK: //SectionMark
		/* 出力ﾌｫｰﾏｯﾄ作成 */
		instance.Format("%s;\n",IN_Instance->EntityName);
		break;
	case SXF_IM_AP_ENTITY: //AP202 entity
	case SXF_IM_AP_TABLE:  //AP202 table
	case SXF_IM_AP_ASSEMBLY: //AP202 assembly
		if (IN_Instance->EntityName == DEF_SXF_COMPLEX_INSTANCE){
			//if entityname=="SXF_COMPLEX_INSTANCE"
			//then complex_instance eg.#10=(a()
									  //	b()
									  //	c());
			/* 出力ﾌｫｰﾏｯﾄ作成 */
			instance.Format("#%d=%s;\n",
							IN_Instance->InstanceID,
							IN_Instance->EntityData);
		}else{ // if not a complex instance 
			/* 出力ﾌｫｰﾏｯﾄ作成 */
			instance.Format("#%d=%s%s;\n",
							IN_Instance->InstanceID,
							IN_Instance->EntityName,
							IN_Instance->EntityData);
		}
		break;
	case SXF_IM_FT_ENTITY: //Feature
	case SXF_IM_FT_TABLE:  //Feature table
	case SXF_IM_FT_ASSEMBLY: //Feature assembly
		/* 出力ﾌｫｰﾏｯﾄ作成 */
		instance.Format("\n/*SXF\n#%d = %s%s\nSXF*/\n\n",
						IN_Instance->InstanceID,
						IN_Instance->EntityName,
						IN_Instance->EntityData);
		break;
	default: 
		break;
	}
	
	/* ｲﾝｽﾀﾝｽ出力 */
	WriteString(instance);

	return TRUE;
}
