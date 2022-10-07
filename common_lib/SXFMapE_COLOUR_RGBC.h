/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_COLOUR_RGBC.h						�쐬���F2000.04.17

	�P�D�N���X�T�v
		COLOUR_RGB���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#ifndef _SXFMapE_COLOUR_RGBC_CLASS_
#define _SXFMapE_COLOUR_RGBC_CLASS_

#include <afx.h>
#include <afxtempl.h>
#include "SXFMapEntityBaseC.h"

class SXFInstanceIDC;

class SXFMapE_COLOUR_RGBC : public SXFMapEntityBaseC {
public :
//
//	<�f�t�H���g�R���X�g���N�^>
	SXFMapE_COLOUR_RGBC( ) ;

//	<�R���X�g���N�^>
//	<�C���X�^���X�h�c�ւ̃|�C���^��o�^����������>
	SXFMapE_COLOUR_RGBC(SXFInstanceIDC* IN_InstanceIDManeger) ;

//	<�f�X�g���N�^>
	virtual	~SXFMapE_COLOUR_RGBC() ;


//�G���e�B�e�B�p�����^�̓o�^
	int	SetParameter();

//	<�����o�ϐ�>	//////////////////////////////////////

//	<�G���e�B�e�B�f�[�^>
//	ENTITY colour_rgb
//	  SUBTYPE OF (colour_specification);
//		red   : REAL;
//		green : REAL;
//		blue  : REAL;
//	  WHERE
//		wr1: (0 <= red) AND (red <= 1);
//		wr2: (0 <= green) AND (green <= 1);
//		wr3: (0 <= blue) AND (blue <= 1);
//	END_ENTITY; -- colour_rgb

//#140 = COLOUR_RGB('colour_rgb1', 0.12, 0.56, 1.);
//#140 = COLOUR_RGB('$$SXF_', 0.12, 0.56, 1.);
//	<name(�F���j>
	CString		m_name;
	
//	<RGB�l>	
	double		m_R;	// 0=< m_R =< 1.0
	double		m_G;
	double		m_B;

private :

protected :

} ;

#endif
