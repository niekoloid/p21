/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_CARTESIAN_POINTC.h						�쐬���F2000.04.17

	�P�D�N���X�T�v
		CARTESIAN_POINT���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#ifndef _SXFMapE_CARTESIAN_POINTC_CLASS_
#define _SXFMapE_CARTESIAN_POINTC_CLASS_

#include <afx.h>
//#include <afxtempl.h>
#include "SXFMapEntityBaseC.h"

class SXFInstanceIDC;

class SXFMapE_CARTESIAN_POINTC : public SXFMapEntityBaseC {
public :
//
//	<�f�t�H���g�R���X�g���N�^>
	SXFMapE_CARTESIAN_POINTC( ) ;

//	<�R���X�g���N�^>
//	<�C���X�^���X�h�c�ւ̃|�C���^��o�^����������>
	SXFMapE_CARTESIAN_POINTC(SXFInstanceIDC* IN_InstanceIDManeger) ;

//	<�f�X�g���N�^>
	virtual	~SXFMapE_CARTESIAN_POINTC() ;

//�G���e�B�e�B�p�����^�̓o�^
	int	SetParameter();

//	<�����o�ϐ�>	//////////////////////////////////////

//	<�G���e�B�e�B�f�[�^>
//#101 = CARTESIAN_POINT('cartesian_point1', (0., 0.));
//name
	CString		m_name;
//	<(x,Y)>
	double		m_x;
	double		m_y;

private :

protected :

} ;

#endif
