/**
	All Rights Reserved,(c) JACIC 2001
	SXFErrorMsgC.h								作成日：2000.3.27

	１．クラス概要
	エラーメッセージリスト管理

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.3.27			宮園(FQS)			なし。

**/

#ifndef _ERRORMSGC_H_
#define	_ERRORMSGC_H_

#include <afx.h>
#include "SXFErrorCode.h"

class SXFErrorRecC;

class SXFErrorMsgC {
public:
	static void	RecordError(SXFErrorCode IN_Code, const char* IN_Name,int IN_param, ...);
	static void	RecordError2(SXFErrorCode IN_Code, const char* IN_Name,int IN_param, ...);
	static SXFErrorRecC*	PeekError();
};


#endif	// _ERRORMSGC_H_ 
