/**
	All Rights Reserved,(c)JACIC 2001
	SXFComInfoC.cpp						作成日：2001.05.17

	１．クラス概要
		共通情報（レベル・モード）を保持するクラス

	２．履歴
		履歴番号	日付		担当者		概要
		作成		2001.05.17	諌山(FQS)	なし。
**/

#include "stdafx.h"
#include <string.h>
#include "SXFComInfoC.h"
#include "SXFErrorMsgC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFComInfoC.cpp						作成日：2001.05.17

	１．機能概要
		コンストラクタ
		
	２．インターフェイス
		void	SXFComInfoC::SXFComInfoC()
		
	引数	：	型		引数名				内容
		なし

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2001.05.17	諌山(FQS)	なし。
**/
SXFComInfoC::SXFComInfoC()
{
//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
//	strcpy(m_file_name, "");
	strcpy_s(m_file_name,_countof(m_file_name), "");
	m_rw_flg = 0;
	m_tolerance = 0.0;
	m_tolerance2 = 0.0;	
	m_devide = 0.0;	
	m_level = 0;
	m_mode = 0;	
//	MOD(S)	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
//	strcpy(m_author, "");	
//	strcpy(m_organization,"");
//	strcpy(m_trans_name,"");
//	strcpy(m_version, "");
	strcpy_s(m_author,_countof(m_author), "");	
	strcpy_s(m_organization,_countof(m_organization),"");
	strcpy_s(m_trans_name,_countof(m_trans_name),"");
	strcpy_s(m_version,_countof(m_version), "");
//	MOD(E)	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
	m_IN_level = 0;
	m_exfile = 0;

}
/**
	All Rights Reserved,(c)JACIC 2001
	SXFComInfoC.cpp						作成日：2001.05.17

	１．機能概要
		デストラクタ
		
	２．インターフェイス
		void	SXFComInfoC::~SXFComInfoC ()
		
	引数	：	型		引数名				内容
		なし

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2001.05.17	諌山(FQS)	なし。
**/
SXFComInfoC::~SXFComInfoC ()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFComInfoC.cpp						作成日：2001.05.17

	１．機能概要
		共通情報を保持
		
	２．インターフェイス
		void	Set_Write_Come(char IN_fname[257], 
							   int IN_flg,
							   double IN_tolerance, 
							   double IN_tolerance2, 
							   double IN_devide, 
							   int IN_level, 
							   int IN_mode, 
							   char IN_author[257],
							   char IN_organization[257], 
							   char IN_trans_name[257])
		
	引数：	型		引数名				内容
			int		IN_flg					読書きフラグ
			double	IN_tolerance			許容誤差
			double	IN_tolerance2			角度許容誤差
			double	IN_devide				許容誤差(スプライン分割用)
			int		IN_level				レベル
			int		IN_mode					モード
			char	IN_author[257]			ファイル作成者
			char	IN_organization[257]	作成者所属
			char	IN_trans_name[257]		トランスレータ名
	３．履歴
		履歴番号	日付		担当者		概要
		作成		2001.05.17	諌山(FQS)	なし。
**/
void SXFComInfoC::Set_Write_Come(char IN_fname[257], int IN_flg, double IN_tolerance, double IN_tolerance2, double IN_devide, int IN_level, int IN_mode, char IN_author[257], char IN_organization[257], char IN_trans_name[257])
{
//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
//	strcpy(m_file_name, IN_fname);
	strcpy_s(m_file_name,_countof(m_file_name), IN_fname);
	m_rw_flg = IN_flg ;
	m_tolerance = IN_tolerance ;
	m_tolerance2 = IN_tolerance2 ;
	m_devide = IN_devide ;
	m_level = IN_level ;
	m_mode = IN_mode ;
//	MOD(S)	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
//	strcpy(m_author, IN_author);
//	strcpy(m_organization, IN_organization);
//	strcpy(m_trans_name, IN_trans_name);
	strcpy_s(m_author,_countof(m_author), IN_author);
	strcpy_s(m_organization,_countof(m_organization), IN_organization);
	strcpy_s(m_trans_name,_countof(m_trans_name), IN_trans_name);
//	MOD(E)	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFComInfoC.cpp						作成日：2001.05.17

	１．機能概要
		共通情報を保持
		
	２．インターフェイス
		void	Set_Read_Come(char IN_fname[257], 
							  int IN_flg, 
							  double IN_tolerance, 
							  double IN_tolerance2, 
							  double IN_devide, 
							  int IN_level, 
							  int IN_mode)
		
	引数：	型		引数名				内容

				char	IN_fname[257]		ファイル名
				int		IN_flg				読書きフラグ
				double	IN_tolerance		許容誤差
				double	IN_tolerance2		角度用許容誤差
				double	IN_devide			許容誤差(スプライン分割用)
				int		IN_level			レベル
				int		IN_mode				モード

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2001.05.17	諌山(FQS)	なし。
**/
void SXFComInfoC::Set_Read_Come(char IN_fname[257], int IN_flg, double IN_tolerance, double IN_tolerance2, double IN_devide, int IN_level, int IN_mode)
{
//	JPCERT/CC 指摘 脆弱性対応	T.Matsushima	2015.04.27
//	strcpy(m_file_name, IN_fname);
	strcpy_s(m_file_name,_countof(m_file_name), IN_fname);
	m_rw_flg = IN_flg ;
	m_tolerance = IN_tolerance ;
	m_tolerance2 = IN_tolerance2 ;
	m_devide = IN_devide ;
	m_level = IN_level ;
	m_mode = IN_mode ;
	m_IN_level = IN_level;
	m_exfile = 0;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFComInfoC.cpp						作成日：2001.05.17

	１．機能概要
		フラグの返却
		
	２．インターフェイス
		void	SXFComInfoC::Get_Flg(int &OUT_flg)
		
	引数：	型		引数名				内容
			int		&OUT_flg	読み書きフラグ

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2001.05.17	諌山(FQS)	なし。
**/
void SXFComInfoC::Get_Flg(int &OUT_flg)
{
	OUT_flg = m_rw_flg ;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFComInfoC.cpp						作成日：2001.05.17

	１．機能概要
		トレランス情報の取得
		
	２．インターフェイス
		void	 SXFComInfoC::Get_Tolerance(double &OUT_tolerance, 
											double &OUT_tolerance2)
		
	引数	：	型			引数名				内容
				double&		OUT_tolerance		許容誤差
				double&		OUT_tolerance2		角度用許容誤差
		

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2001.05.17	諌山(FQS)	なし。
**/
void SXFComInfoC::Get_Tolerance(double &OUT_tolerance, double &OUT_tolerance2)
{
	OUT_tolerance = m_tolerance ;
	OUT_tolerance2 = m_tolerance2 ;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFComInfoC.cpp						作成日：2001.06.24

	１．機能概要
		読書きフラグの取得
		
	２．インターフェイス
		void	 SXFComInfoC::Get_RWFlag(int &OUT_RWFlag)
		
	引数	：	型			引数名				内容
				int&		OUT_RWFlag			読書きフラグ		

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2001.06.24	佐々木(FQS)	なし。
**/
void SXFComInfoC::Get_RWFlag(int &OUT_RWFlag)
{
	OUT_RWFlag = m_rw_flg;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFComInfoC.cpp						作成日：2001.06.24

	１．機能概要
		Part21ファイルの情報と呼び出し情報を比較チェックし、不整合を通知する
		(ワーニング処理)
		
	２．インターフェイス
		int	 SXFComInfoC::SetFileInfo(HEADSECTION IN_Head) 
		
	引数	：	型				引数名		内容
				HEADSECTION		IN_Head		ﾌｧｲﾙのﾍｯﾀﾞ情報

	復帰値：
		正常終了	：0
		異常終了	：エラーコード

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2001.06.24	佐々木(FQS)	なし。
**/
int SXFComInfoC::SetFileInfo(HEADSECTION IN_Head)
{
	/** Level **/
	m_FileLevel = IN_Head.Level;
	/** Mode **/
	m_FileMode = IN_Head.Mode;
	/* SCADEC以外のﾌｧｲﾙ */
	if (IN_Head.scadec_flg == -1){
//	MOD(S)	メッセージ修正	K.Naono	04.03.05
//		SXFErrorMsgC::RecordError(SXFSCADECFILEERR,"",0);
		SXFErrorMsgC::RecordError2(SXFSCADECFILEERR,"",0);
//	MOD(E)	メッセージ修正	K.Naono	04.03.05
		/* フィーチャコメント、レベル２として処理する */
		m_mode = 2;
		m_level = 2;
	}
	else{
		/* FileLevel１のとき */
		if (m_FileLevel == 1)
			m_level = 2;
		/* FileLevel2のとき */
		else if (m_FileLevel == 2){
			if (m_level == 1){
				//ダウンコンバートは行いません。
//	MOD(S)	メッセージ修正	K.Naono	04.03.05
//				SXFErrorMsgC::RecordError(SXFWARNINGDC,"",0);
				SXFErrorMsgC::RecordError2(SXFWARNINGDC,"",0);
//	MOD(E)	メッセージ修正	K.Naono	04.03.05
				m_level = 2;
			}
			else
				m_level = 2;
		}
		//error
		else{
			SXFErrorMsgC::RecordError(SXFNOLEVEL,"",1,m_FileLevel);
			return SXFNOLEVEL;
		}
		/* モード */
		switch(m_FileMode){
			case 0:
			case 2:
				break;
			case 1:
				/* フィーチャコメントのﾌｧｲﾙ */
//	MOD(S)	メッセージ修正	K.Naono	04.03.05
//				SXFErrorMsgC::RecordError(SXFAP202FILE,"",0);
				SXFErrorMsgC::RecordError2(SXFAP202FILE,"",0);
//	MOD(E)	メッセージ修正	K.Naono	04.03.05
				/* AP202モードとして処理する */
				m_mode = 2;
				break;
			default:
				/* モードが０，１，２以外 */
				SXFErrorMsgC::RecordError(SXFNOMODE,"",1,m_FileMode);
				return SXFNOMODE;
		}
	}
	return 0;
}
