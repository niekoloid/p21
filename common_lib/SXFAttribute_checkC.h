/**
	All Rights Reserved,(c) JACIC 2002
	SXFAttribute_checkC.h							作成日：2002.12.3

	１．クラス概要
	図面表題欄フィーチャのルールチェックを行うクラス

	２．履歴
	履歴番号		日付け			担当者				概要
	作成			2002.12.03		K.Naono(FQS)		Ver3.0対応

**/

#if !defined(AFX_SXFATTRIBUTE_CHECKC_H__91CE787C_EB5D_49CC_8504_702ED54094DC__INCLUDED_)
#define AFX_SXFATTRIBUTE_CHECKC_H__91CE787C_EB5D_49CC_8504_702ED54094DC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SXFStruct.h"
#include "SXFComFunctionC.h"
#include "SXFTableCheckC.h"

class SXFAttribute_checkC : 
	public SXFTableCheckC, 
	public SXFComFunctionC  
{
public:
	int attr_rule_check(Attribute_Struct* IN_attribute_str) ;
	int str_rule_check(Attribute_Struct* IN_attribute_str) ;
	int Feature_rule_check(Attribute_Struct* IN_attribute_str,
						SXFTableManagerC* IN_TableManager,
						CString IN_InstanceID) ;
	SXFAttribute_checkC() ;
	virtual ~SXFAttribute_checkC() ;
};

#endif // !defined(AFX_SXFATTRIBUTE_CHECKC_H__91CE787C_EB5D_49CC_8504_702ED54094DC__INCLUDED_)
