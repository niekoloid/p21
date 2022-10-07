/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_COMPOSITE_CURVEC.cpp								作成日：2000.3.29

	１．クラス概要
	

	２．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.3.29			宮園(FQS)			なし。

**/
#include "stdafx.h"
//#include <afxtempl.h>
#include "SXFMapEntAConvC.h"
#include "SXFMapEntityBaseC.h"
#include "SXFInstanceIDC.h"

#include "SXFMapE_COMPOSITE_CURVEC.h"
#include "SXFMapE_COMPOSITE_CURVE_SEGMENTC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFManageC.cpp								作成日：2000.3.29

	１．機能概要
	コンストラクタ

	２．インターフェース
	void	SXFMapE_COMPOSITE_CURVEC::SXFMapE_COMPOSITE_CURVEC()
	引数:	型				引数名			内容
			なし。

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.3.29			宮園(FQS)			なし。

**/
SXFMapE_COMPOSITE_CURVEC::SXFMapE_COMPOSITE_CURVEC()
{
	m_EntityName = DEF_ANNOTATION_FILL_AREA;

	m_SegmentCount = 0;

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFManageC.cpp								作成日：2000.3.29

	１．機能概要
	デストラクタ

	２．インターフェース
	void	SXFMapE_COMPOSITE_CURVEC::SXFMapE_COMPOSITE_CURVEC(
					SXFInstanceIDC* IN_InstanceIDManeger)
	:SXFMapEntityBaseC(IN_InstanceIDManeger)

	引数:	型				引数名			内容
			SXFInstanceIDC* IN_InstanceIDManeger

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.3.29			宮園(FQS)			なし。

**/
SXFMapE_COMPOSITE_CURVEC::SXFMapE_COMPOSITE_CURVEC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)

{
	m_EntityName = DEF_ANNOTATION_FILL_AREA;
	m_SegmentCount = 0;

}


/**
	All Rights Reserved,(c) JACIC 2001
	SXFManageC.cpp								作成日：2000.3.29

	１．機能概要
	デストラクタ

	２．インターフェース
	void	SXFMapE_COMPOSITE_CURVEC::~SXFMapE_COMPOSITE_CURVEC()
	引数:	型				引数名			内容
			なし。

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.3.29			宮園(FQS)			なし。

**/
SXFMapE_COMPOSITE_CURVEC::~SXFMapE_COMPOSITE_CURVEC()
{
	for(int i=0;i<m_SegmentArray_p.GetSize();i++){
		if( m_SegmentArray_p[i] != NULL)
			delete m_SegmentArray_p[i];
	}
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFManageC.cpp								作成日：2000.3.29

	１．機能概要
	

	２．インターフェース
	int SXFMapE_COMPOSITE_CURVEC::SetParameter( )
	引数:	型				引数名			内容
			なし。

	３．履歴
	履歴番号		日付け				担当者				概要
	作成			2000.3.29			宮園(FQS)			なし。

**/
int SXFMapE_COMPOSITE_CURVEC::SetParameter( )
{

	SXFMapEntAConvC convert(m_EntityArray);

	if ( convert.GetCString(0,m_Name) < 0 ){
		SXFErrorMsgC::RecordError( SXFPARAMS,
								m_EntityName,
								2,
								m_RootID,
								m_EntityName
								);
		return SXFPARAMS;
	}

	if ( convert.GetSetInst(1, m_SegmentCount, m_SegmentArray_Inst) < 0 ){
		SXFErrorMsgC::RecordError( SXFPARAMS,
								m_EntityName,
								2,
								m_RootID,
								m_EntityName
								);
		return SXFPARAMS;
	}

	convert.GetBOOL(2,m_Intersect);	

//	不要かも ///////////////////////////////////////////////////////////////

	for(int i=0;i<m_SegmentCount;i++){
		SXFMapE_COMPOSITE_CURVE_SEGMENTC* temp_p = 
			new SXFMapE_COMPOSITE_CURVE_SEGMENTC(m_InstanceIDManager);
		m_SegmentArray_p.Add(temp_p);

		int ircode = temp_p->SetRootID(m_SegmentArray_Inst[i]);
		if ( ircode < 0 )
			return ircode ;
		ircode = temp_p->SetParameter();
		if ( ircode < 0 )
			return ircode ;
	}

	return 0;
}
