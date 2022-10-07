/**
	All Rights Reserved,(c)JACIC 2001
	SXFComInfoC.h						作成日：2001.05.17

	１．クラス概要
		共通情報（レベル・モード）を保持するクラス

	２．履歴
		履歴番号	日付		担当者		概要
		作成		2001.05.17	諌山(FQS)	なし。
**/

#ifndef _SXFCOMINFOC_CLASS_
#define _SXFCOMINFOC_CLASS_
#include "SXFDataStructC.h"

class SXFComInfoC
{
	char	m_file_name[257] ;		//ファイル名
	int		m_rw_flg ;				//読／書フラグ
	double	m_tolerance ;			//長さ用許容誤差
	double	m_tolerance2 ;			//角度許容誤差
	double	m_devide ;				//許容誤差
	int		m_level ;				//レベル指定
	int		m_mode ;				//モード
	char	m_author[257] ;			//ファイル作成者
	char	m_organization[257] ;	//作成者所属
	char	m_trans_name[257] ;		//トランスレータ名
	char	m_version[257] ;		//共通ライブラリバージョン
	int		m_IN_level;				//入力されたレベル
	int		m_exfile;				//外部ファイル読み込みフラグ

public :
//	void Get_ExFileFlg(int &OUT_ExFileFlg);
//	void Get_Divide(double& OUT_Divide);
	int SetFileInfo(HEADSECTION IN_Head);
	void Get_RWFlag(int &OUT_RWFlag);
//------------------------------------------------
//	コンストラクタ
//------------------------------------------------
	SXFComInfoC() ;
//------------------------------------------------
//	デストラクタ
//------------------------------------------------
	~SXFComInfoC() ;
//------------------------------------------------
//	共通情報を保持(write)
//------------------------------------------------
	void Set_Write_Come(char IN_fname[257], int IN_flg, double IN_tolerance, double IN_tolerance2, double IN_devide, int IN_level, int IN_mode, char IN_author[257], char IN_organization[257], char IN_trans_name[257]) ;
//------------------------------------------------
//	共通情報を保持(read)
//------------------------------------------------
	void Set_Read_Come(char IN_fname[257], int IN_flg, double IN_tolerance, double IN_tolerance2, double IN_devide, int IN_level, int IN_mode) ;
//------------------------------------------------
//	全情報返却
//------------------------------------------------
	void Get_Come(char OUT_fname[257], int &OUT_flg, double &OUT_tolerance, double &OUT_tolerance2, double &OUT_devide, int &OUT_level, int &OUT_mode, char OUT_author[257], char OUT_organization[257], char OUT_trans_name[257], char OUT_version[257]) ;
//------------------------------------------------
//	フラグの取得
//------------------------------------------------
	void Get_Flg(int &OUT_flg) ;
//------------------------------------------------
//	トレランス情報の取得
//------------------------------------------------
	void Get_Tolerance(double &OUT_tolerance, double &OUT_tolerance2) ;
private:
	int m_FileMode;
	int m_FileLevel;
} ;

#endif