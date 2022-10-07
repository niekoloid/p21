/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_CARTESIAN_POINTC.cpp						作成日：2000.04.17

	１．クラス概要
		CARTESIAN_POINTを管理する

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#include "stdafx.h"
#include "SXFMapE_CARTESIAN_POINTC.h"
#include "SXFMapEntAConvC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_CARTESIAN_POINTC.cpp						作成日：2000.04.17

	１．機能概要
		デフォルトコンストラクタ

	２．インターフェイス
		void	SXFMapE_CARTESIAN_POINTC::SXFMapE_CARTESIAN_POINTC()

	引数  ：	型			引数名				内容
			なし
	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_CARTESIAN_POINTC::SXFMapE_CARTESIAN_POINTC()
{
//#101 = CARTESIAN_POINT('cartesian_point1', (0., 0.));

//	<初期化>
	m_EntityName = DEF_CARTESIAN_POINT;
//
//	<エンティティデータ>
	m_name.Empty();
//
//	<(x,Y)>
	m_x =  m_y = 0.;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_CARTESIAN_POINTC.cpp						作成日：2000.04.17

	１．機能概要
		エンティティデータを指定して生成する場合
		(コンストラクタ)

	２．インターフェイス
		void	SXFMapE_CARTESIAN_POINTC::SXFMapE_CARTESIAN_POINTC(
						SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	引数：	型				引数名					内容
			SXFInstanceIDC* IN_InstanceIDManeger	ｲﾝｽﾀﾝｽID管理ｵﾌﾞｼﾞｪｸﾄ

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_CARTESIAN_POINTC::SXFMapE_CARTESIAN_POINTC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
{
//#101 = CARTESIAN_POINT('cartesian_point1', (0., 0.));

//	<初期化>
	m_EntityName = DEF_CARTESIAN_POINT;
//
//	<エンティティデータ>
	m_name.Empty();
//
//	<(x,Y)>
	m_x =  m_y = 0.;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_CARTESIAN_POINTC.cpp						作成日：2000.04.17

	１．機能概要
		(デストラクタ)

	２．インターフェイス
		void	SXFMapE_CARTESIAN_POINTC::~SXFMapE_CARTESIAN_POINTC()

	引数  ：	型			引数名				内容
			なし

	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
SXFMapE_CARTESIAN_POINTC::~SXFMapE_CARTESIAN_POINTC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_CARTESIAN_POINTC.cpp						作成日：2000.04.17

	１．機能概要
		エンティティデータの登録

	２．インターフェイス
		int		SXFMapE_CARTESIAN_POINTC::SetParameter()

	引数  ：	型			引数名				内容
						なし
	復帰値：なし

	３．履歴
	履歴番号	日付け		担当者			概要
	作成		2000.04.17	
**/
int SXFMapE_CARTESIAN_POINTC::SetParameter()

{
	SXFMapEntAConvC convent(m_EntityArray);
	//<name>
	convent.GetCString(0,m_name);
	//<(X,Y)>
	int num;
	CArray<double,double> array;
	convent.GetSetDouble(1,num,array);

	if ( num >=2 ){
		m_x = array[0];
		m_y = array[1];
	}
	else{
		//エンティティパラメタの数に謝りがあります。
		SXFErrorMsgC::RecordError(
				SXFPARAMS,			//errメッセージ番号
				m_EntityName,		//エンティティ名
				2,					//パラメタの個数
				m_RootID,			//パラメタ
				m_EntityName
				);
		return SXFPARAMS;
	}
	return 0;
}
