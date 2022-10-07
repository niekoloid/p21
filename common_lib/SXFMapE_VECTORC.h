/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_VECTORC.h						�쐬���F2000.04.17

	�P�D�N���X�T�v
		VECTOR���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#ifndef _SXFMapE_VECTORC_CLASS_
#define _SXFMapE_VECTORC_CLASS_

#include <afx.h>
#include <afxtempl.h>

#include "SXFMapEntityBaseC.h"

class SXFInstanceIDC;
class SXFMapE_DIRECTIONC;

class SXFMapE_VECTORC : public SXFMapEntityBaseC {
public :
//
//	<�f�t�H���g�R���X�g���N�^>
	SXFMapE_VECTORC( ) ;

//	<�R���X�g���N�^>
//	<�C���X�^���X�h�c�ւ̃|�C���^��o�^����������>
	SXFMapE_VECTORC(SXFInstanceIDC* IN_InstanceIDManeger) ;

//	<�f�X�g���N�^>
	virtual	~SXFMapE_VECTORC() ;

//�G���e�B�e�B�p�����^�̓o�^
	int	SetParameter();

//	<�����o�ϐ�>	//////////////////////////////////////

//<�G���e�B�e�B�f�[�^>
/*  ENTITY vector
    SUBTYPE OF (geometric_representation_item);
      orientation : direction;
      magnitude   : length_measure;
    WHERE
      wr1: magnitude >= 0;
  END_ENTITY; -- vector*/

//#424 = VECTOR('vector1', #423, 30.);
	//name�p�����^
	CString		m_name;

	//DIRECTION �ւ̃C���X�^���XID
	int		m_DIRECTION_Inst;
	//DIRECTION�ւ̃|�C���^
	SXFMapE_DIRECTIONC*	m_DIRECTION_P;

	//�x�N�g���̑傫��
	double	m_magni;

private :

protected :

} ;

#endif
