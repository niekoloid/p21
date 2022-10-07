/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_TRIMMED_CURVEC.h						�쐬���F2000.04.17

	�P�D�N���X�T�v
		TRIMMED_CURVE���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

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
//	<�f�t�H���g�R���X�g���N�^>
	SXFMapE_TRIMMED_CURVEC( ) ;

//	<�R���X�g���N�^>
//	<�C���X�^���X�h�c�ւ̃|�C���^��o�^����������>
	SXFMapE_TRIMMED_CURVEC(SXFInstanceIDC* IN_InstanceIDManeger) ;

//	<�f�X�g���N�^>
	virtual	~SXFMapE_TRIMMED_CURVEC() ;


//�G���e�B�e�B�p�����^�̓o�^
	int	SetParameter();

//	<�����o�ϐ�>	//////////////////////////////////////

//<�G���e�B�e�B�f�[�^>
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

	//1.name�p�����^
	CString		m_name;

	//2.basis_curve �ւ̃C���X�^���XID
	int		m_basis_curve_Inst;
	//basis_curve�ւ̃|�C���^
	void*	m_basis_curve_P;
	//basis_curve�̖��O
	CString	m_basis_curve_Name;

	//3.trim_1 �ւ̃C���X�^���XID
	int		m_trim_1_Inst;
	//trim_1�ւ̃|�C���^
	SXFMapE_CARTESIAN_POINTC*	m_trim_1_P;
	//trim1�̃p�����[�^�o�����[
	double	m_trim1_para;

	//3.trim_2 �ւ̃C���X�^���XID
	int		m_trim_2_Inst;
	//trim_2�ւ̃|�C���^
	SXFMapE_CARTESIAN_POINTC*	m_trim_2_P;
	//trim2�̃p�����[�^�o�����[
	double	m_trim2_para;

	//4.sense_agreement
	BOOL		m_sense;

	//5.master_representation
	preferencetype		m_e_rep;

private :

protected :

//�g���~���O�p�t�H�[�}���X�����߂�
int	GetEnumType(CString IN_EntityData,	preferencetype& OUT_Enum );

} ;

#endif
