
/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapT_trimming_preferenceE.cpp						作成日：2000.04.21

	１．機能概要
		列挙型を定義する

		  TYPE trimming_preference = ENUMERATION OF
		    (cartesian,
		     parameter,
		     unspecified);
		  END_TYPE; -- trimming_preference

	２．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.21	
**/


#include "stdafx.h"
#include "SXFErrorMsgC.h"
#include "SXFMapT_trimming_preferenceE.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

int	GetEnumType(CString IN_EntityData,	preferencetype& OUT_Enum )
{

		if (IN_EntityData.Find(DEF_D_CARTESIAN) != -1){
			OUT_Enum = 	cartesian;	
		}
		else if ( IN_EntityData.Find(DEF_D_PARAMETER) != -1){
			OUT_Enum = 	parameter;	
		}
		else if ( IN_EntityData.Find(DEF_D_UNSPECIFIED) != -1){
			OUT_Enum = 	unspecified;	
		}
		else{
			//SCADECの対象外エンティティ -54000
			return SXFEXCEPT;
		}

	return 0;
}
