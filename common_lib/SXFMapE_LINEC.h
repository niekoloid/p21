/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_LINEC.h						作成日：2000.04.17

	１．クラス概要
		LINEを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#ifndef _SXFMapE_LINEC_CLASS_
#define _SXFMapE_LINEC_CLASS_

#include <afx.h>
#include <afxtempl.h>

#include "SXFMapEntityBaseC.h"

class SXFInstanceIDC;
class SXFMapE_CARTESIAN_POINTC;
class SXFMapE_VECTORC;


class SXFMapE_LINEC : public SXFMapEntityBaseC {
public :
//
//	<デフォルトコンストラクタ>
	SXFMapE_LINEC( ) ;

//	<コンストラクタ>
//	<インスタンスＩＤへのポインタを登録し生成する>
	SXFMapE_LINEC(SXFInstanceIDC* IN_InstanceIDManeger) ;

//	<デストラクタ>
	virtual	~SXFMapE_LINEC() ;


//エンティティパラメタの登録
	int	SetParameter();

//	<メンバ変数>	//////////////////////////////////////

//<エンティティデータ>
/*
	ENTITY line
	SUBTYPE OF (curve);
	  pnt : cartesian_point;
	  dir : vector;
	WHERE
	  wr1: dir.dim = pnt.dim;
	END_ENTITY; -- line
*/
//#426 = LINE('line1', #425, #424);

	//nameパラメタ
	CString		m_name;
	
	//cartesian_point へのインスタンスID
	int		m_pnt_Inst;
	//cartesian_pointへのポインタ
	
	SXFMapE_CARTESIAN_POINTC*	m_pnt_P;

	//vector へのインスタンスID
	int		m_vector_Inst;
	//vectorへのポインタ

	SXFMapE_VECTORC*	m_vector_P;

private :

protected :

} ;

#endif
