/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_DIRECTIONC.h						�쐬���F2000.04.17

	�P�D�N���X�T�v
		DIRECTION���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#ifndef _SXFMapE_DIRECTIONC_CLASS_
#define _SXFMapE_DIRECTIONC_CLASS_

#include <afx.h>
#include <afxtempl.h>
#include "SXFMapEntityBaseC.h"

class SXFInstanceIDC;

class SXFMapE_DIRECTIONC : public SXFMapEntityBaseC {
public :
//
//	<�f�t�H���g�R���X�g���N�^>
	SXFMapE_DIRECTIONC( ) ;

//	<�R���X�g���N�^>
//	<�C���X�^���X�h�c�ւ̃|�C���^��o�^����������>
	SXFMapE_DIRECTIONC(SXFInstanceIDC* IN_InstanceIDManeger) ;

//	<�f�X�g���N�^>
	virtual	~SXFMapE_DIRECTIONC() ;


//�G���e�B�e�B�p�����^�̓o�^
	int	SetParameter();

//	<�����o�ϐ�>	//////////////////////////////////////

//	<�G���e�B�e�B�f�[�^>
//#940 = DIRECTION('direction49', (1., 1.));
//name
	CString		m_name;
//	<(x,Y)>
	double		m_x;
	double		m_y;

private :

protected :

} ;

#endif
