/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_LINEC.h						�쐬���F2000.04.17

	�P�D�N���X�T�v
		LINE���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

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
//	<�f�t�H���g�R���X�g���N�^>
	SXFMapE_LINEC( ) ;

//	<�R���X�g���N�^>
//	<�C���X�^���X�h�c�ւ̃|�C���^��o�^����������>
	SXFMapE_LINEC(SXFInstanceIDC* IN_InstanceIDManeger) ;

//	<�f�X�g���N�^>
	virtual	~SXFMapE_LINEC() ;


//�G���e�B�e�B�p�����^�̓o�^
	int	SetParameter();

//	<�����o�ϐ�>	//////////////////////////////////////

//<�G���e�B�e�B�f�[�^>
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

	//name�p�����^
	CString		m_name;
	
	//cartesian_point �ւ̃C���X�^���XID
	int		m_pnt_Inst;
	//cartesian_point�ւ̃|�C���^
	
	SXFMapE_CARTESIAN_POINTC*	m_pnt_P;

	//vector �ւ̃C���X�^���XID
	int		m_vector_Inst;
	//vector�ւ̃|�C���^

	SXFMapE_VECTORC*	m_vector_P;

private :

protected :

} ;

#endif
