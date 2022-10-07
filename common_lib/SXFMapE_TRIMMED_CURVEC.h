/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_TRIMMED_CURVEC.h						作成日：2000.04.17

	１．クラス概要
		TRIMMED_CURVEを管理するクラス

	２．履歴
		履歴番号	日付け		担当者		概要
		作成		2000.04.17	

**/
#ifndef _SXFMapE_TRIMMED_CURVEC_CLASS_
#define _SXFMapE_TRIMMED_CURVEC_CLASS_

#include <afx.h>
#include <afxtempl.h>

#include "SXFMapEntityBaseC.h"
#include "SXFMapT_trimming_preferenceE.h"

#include "SXFMapE_LINEC.h"
#include "SXFMapE_CIRCLEC.h"

class SXFInstanceIDC;
class SXFMapE_CARTESIAN_POINTC;
class SXFMapE_VECTORC;

class SXFMapE_TRIMMED_CURVEC : public SXFMapEntityBaseC {
public :
//
//	<デフォルトコンストラクタ>
	SXFMapE_TRIMMED_CURVEC( ) ;

//	<コンストラクタ>
//	<インスタンスＩＤへのポインタを登録し生成する>
	SXFMapE_TRIMMED_CURVEC(SXFInstanceIDC* IN_InstanceIDManeger) ;

//	<デストラクタ>
	virtual	~SXFMapE_TRIMMED_CURVEC() ;


//エンティティパラメタの登録
	int	SetParameter();

//	<メンバ変数>	//////////////////////////////////////

//<エンティティデータ>
/*  
  ENTITY trimmed_curve
    SUBTYPE OF (bounded_curve);
      basis_curve           : curve;
      trim_1                : SET [1:2] OF trimming_select;
      trim_2                : SET [1:2] OF trimming_select;
      sense_agreement       : BOOLEAN;
      master_representation : trimming_preference;
(* abf WRs always fail when only one member of set (SEDS 42, my seds1)
in 2nd ed part 42, XOR replaced with OR.
    WHERE
      wr1: (HIINDEX(trim_1) = 1) XOR (TYPEOF(trim_1[1]) <> TYPEOF(trim_1[2]));
      wr2: (HIINDEX(trim_2) = 1) XOR (TYPEOF(trim_2[1]) <> TYPEOF(trim_2[2]));
*)
    WHERE
      wr1: (HIINDEX(trim_1) = 1) OR (TYPEOF(trim_1[1]) <> TYPEOF(trim_1[2]));
      wr2: (HIINDEX(trim_2) = 1) OR (TYPEOF(trim_2[1]) <> TYPEOF(trim_2[2]));
  END_ENTITY; -- trimmed_curve

  TYPE trimming_select = SELECT
    (cartesian_point,
     parameter_value);
  END_TYPE; -- trimming_select
 */
  
//#427 = TRIMMED_CURVE('trimmed_curve3', #426, (#422), (#421), .T., .CARTESIAN.);
//#521 = TRIMMED_CURVE('',#520,(#516,PARAMETER_VALUE(0.0)),(#517,
//       PARAMETER_VALUE(12.383404246416728)),.T.,.PARAMETER.);
//#104 = TRIMMED_CURVE('trimmed_curve1', #103, (PARAMETER_VALUE(3.141593)), 
//(PARAMETER_VALUE(0.)), .T., .PARAMETER.);

	//1.nameパラメタ
	CString		m_name;

	//2.basis_curve へのインスタンスID
	int		m_basis_curve_Inst;
	//basis_curveへのポインタ
	void*	m_basis_curve_P;
	//basis_curveの名前
	CString	m_basis_curve_Name;

	//3.trim_1 へのインスタンスID
	int		m_trim_1_Inst;
	//trim_1へのポインタ
	SXFMapE_CARTESIAN_POINTC*	m_trim_1_P;
	//trim1のパラメータバリュー
	double	m_trim1_para;

	//3.trim_2 へのインスタンスID
	int		m_trim_2_Inst;
	//trim_2へのポインタ
	SXFMapE_CARTESIAN_POINTC*	m_trim_2_P;
	//trim2のパラメータバリュー
	double	m_trim2_para;

	//4.sense_agreement
	BOOL		m_sense;

	//5.master_representation
	preferencetype		m_e_rep;

private :

protected :

//トリミングパフォーマンスを求める
int	GetEnumType(CString IN_EntityData,	preferencetype& OUT_Enum );

} ;

#endif
