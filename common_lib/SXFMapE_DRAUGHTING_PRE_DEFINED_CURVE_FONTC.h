/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_DRAUGHTING_PRE_DEFINED_CURVE_FONTC.h						�쐬���F2000.04.17

	�P�D�N���X�T�v
		DRAUGHTING_PRE_DEFINED_CURVE_FONT���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#ifndef _SXFMapE_DRAUGHTING_PRE_DEFINED_CURVE_FONTC_CLASS_
#define _SXFMapE_DRAUGHTING_PRE_DEFINED_CURVE_FONTC_CLASS_

#include <afx.h>
#include <afxtempl.h>
#include "SXFMapEntityBaseC.h"

class SXFInstanceIDC;

class SXFMapE_DRAUGHTING_PRE_DEFINED_CURVE_FONTC : public SXFMapEntityBaseC {
public :
//
//	<�f�t�H���g�R���X�g���N�^>
	SXFMapE_DRAUGHTING_PRE_DEFINED_CURVE_FONTC( ) ;

//	<�R���X�g���N�^>
//	<�C���X�^���X�h�c�ւ̃|�C���^��o�^����������>
	SXFMapE_DRAUGHTING_PRE_DEFINED_CURVE_FONTC(SXFInstanceIDC* IN_InstanceIDManeger) ;

//	<�f�X�g���N�^>
	virtual	~SXFMapE_DRAUGHTING_PRE_DEFINED_CURVE_FONTC() ;

//�G���e�B�e�B�p�����^�̓o�^
	int	SetParameter();

//	<�����o�ϐ�>	//////////////////////////////////////

//<�G���e�B�e�B�f�[�^>
//  ENTITY draughting_pre_defined_curve_font
//    SUBTYPE OF (pre_defined_curve_font);
//    WHERE
//      wr1: SELF.name IN ['continuous','chain','chain double dash','dashed',
//               'dotted'];
//  END_ENTITY; -- draughting_pre_defined_curve_font

//#20 = DRAUGHTING_PRE_DEFINED_CURVE_FONT('continuous');
	//name�p�����^
	CString		m_name;	

private :

protected :

} ;

#endif
