//---------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFPart21FileC.h	                  作成日：2000.03.25
//
//	１．クラス概要
//      ファイルの入力と出力を管理する
//
//	２．履歴
//		履歴番号	日付け		 担当者	    概要
//		作成		2000.03.25  周
//		更新		2001.09.17	K.Naono		ヘッダ解析処理の改善対応
//
//---------------------------------------------------------
#include "SXFDataStructC.h"

class SXFPart21FileC:public CStdioFile{

public:
//
//	<コンストラクタ>
//
    SXFPart21FileC();
    SXFPart21FileC( FILE* IN_pOpenStream );
    SXFPart21FileC( LPCTSTR IN_lpszFileName, UINT IN_nOpenFlags);

//
//	<デストラクタ>
//
    ~SXFPart21FileC();

//	MOD(S)	ヘッダ解析処理の改善対応	K.Naono		01.09.17
//	int  ReadHeadSection(HEADSECTION *IO_Head);
	virtual int  ReadHeadSection(HEADSECTION* IO_Head) ;
//	MOD(E)	ヘッダ解析処理の改善対応	K.Naono		01.09.17

//	int  ReadInstance(INSTANCEDATA *IO_Instance);
	virtual int  ReadInstance(INSTANCEDATA *IO_Instance) ;
	BOOL WriteHeadSection(HEADSECTION *IN_Head);
	BOOL WriteInstance(INSTANCEDATA *IN_Instance);

protected:
//	DEL(S)	チューニング対応	K.Naono	03.07.03
//private:
//	DEL(E)	チューニング対応	K.Naono	03.07.03
	int ap202count;
	int featurecount;

};
