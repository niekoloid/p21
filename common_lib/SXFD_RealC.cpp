/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_RealC.cpp						作成日：2001.06.12

	１．クラス概要
		実数型要素を保持し出力するクラス

	２．履歴
		履歴番号	日付		担当者		概要
		作成		2001.06.12	佐々木(FQS)	なし。
**/

#include "stdafx.h"
#include "SXFD_RealC.h"
#include "SXFPart21FileC.h"
#include "SXFutyFunctionC.h"
#include <iomanip>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_RealC.cpp						作成日：2001.06.12

	１．機能概要

	２．インターフェース
		void	SXFD_RealC::SXFD_RealC(float data)
	引数:	型						引数名				内容
			float					data			実数型要素

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2001.06.12	佐々木(FQS)	なし。
**/
SXFD_RealC::SXFD_RealC(float data) {
	m_Data = (double)data ;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_RealC.cpp						作成日：2001.06.12

	１．機能概要
		コンストラクタ

	２．インターフェース
		void	SXFD_RealC(double data)
	引数:	型						引数名				内容
			double					data		実数型要素

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2001.06.12	佐々木(FQS)	なし。
**/
SXFD_RealC::SXFD_RealC(double data) {
	m_Data = data ;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_RealC.cpp						作成日：2001.06.12

	１．機能概要
		コンストラクタ

	２．インターフェース
		void	SXFD_RealC(int data)
	引数:	型						引数名				内容
			int						data		実数型要素

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2001.06.12	佐々木(FQS)	なし。
**/
SXFD_RealC::SXFD_RealC(int data) {
	m_Data = (double)data ;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_RealC.cpp						作成日：2001.06.12

	１．機能概要
		データのセット

	２．インターフェース
		void	SetData( float data )
	引数:	型					引数名				内容
			float				data		実数型要素

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2001.06.12	佐々木(FQS)	なし。
**/
void	SXFD_RealC::SetData( float data ) {
	m_Data = (double)data ;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_RealC.cpp						作成日：2001.06.12

	１．機能概要
		データのセット

	２．インターフェース
	void	SetData( double data )
	引数:	型						引数名				内容
			double					data		double型要素

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2001.06.12	佐々木(FQS)	なし。
**/
void	SXFD_RealC::SetData( double data ) {
	m_Data = data ;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_RealC.cpp						作成日：2001.06.12

	１．機能概要
		データのセット

	２．インターフェース
		void	SetData( int data )
	引数:	型						引数名				内容
			int						data			int型要素

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2001.06.12	佐々木(FQS)	なし。
**/
void	SXFD_RealC::SetData( int data ) {
	m_Data = (double)data ;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_RealC.cpp						作成日：2001.06.12

	１．機能概要
		データを取得

	２．インターフェース
		double	SXFD_RealC::GetData( )
	引数:	型								引数名				内容
			なし					

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2001.06.12	佐々木(FQS)	なし。
**/
double	SXFD_RealC::GetData( ) {
	return m_Data ;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_RealC.cpp						作成日：2001.06.12

	１．機能概要
		要素を出力

	２．インターフェース
		void	WriteAttr(SXFPart21FileC *IN_file)
	引数:	型								引数名				内容
			SXFPart21FileC					*IN_file	ﾌｧｲﾙｵﾌﾞｼﾞｪｸﾄ

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2001.06.12	佐々木(FQS)	なし。
**/
void	SXFD_RealC::WriteAttr(SXFPart21FileC *IN_file) {
	CString real_str;
	real_str.Format("%16.6lf",m_Data);
	real_str.TrimLeft();
	real_str.TrimRight();
	IN_file->WriteString(real_str);
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFD_RealC.cpp						作成日：2001.06.12

	１．機能概要
		要素を出力

	２．インターフェース
		void	WriteAttr(SXFPart21FileC *IN_file)
	引数:	型								引数名				内容
			SXFPart21FileC					*IN_file	ﾌｧｲﾙｵﾌﾞｼﾞｪｸﾄ

	３．履歴
		履歴番号	日付		担当者		概要
		作成		2001.06.12	佐々木(FQS)	なし。
**/
void	SXFD_AngleC::WriteAttr(SXFPart21FileC *IN_file) {
	CString real_str;
	real_str = SXFutyFunctionC::out_ctl(m_Data);
	real_str.TrimLeft();
	real_str.TrimRight();
	IN_file->WriteString(real_str);
}
