/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_CURVE_STYLE_FONT_PATTERNC.h						�쐬���F2000.04.17

	�P�D�N���X�T�v
		CURVE_STYLE_FONT_PATTERN���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#ifndef _SXFMapE_CURVE_STYLE_FONT_PATTERNC_CLASS_
#define _SXFMapE_CURVE_STYLE_FONT_PATTERNC_CLASS_

#include <afx.h>
#include <afxtempl.h>
#include "SXFMapEntityBaseC.h"

class SXFInstanceIDC;

class SXFMapE_CURVE_STYLE_FONT_PATTERNC : public SXFMapEntityBaseC {
public :
//
//	<�f�t�H���g�R���X�g���N�^>
	SXFMapE_CURVE_STYLE_FONT_PATTERNC( ) ;

//	<�R���X�g���N�^>
//	<�C���X�^���X�h�c�ւ̃|�C���^��o�^����������>
	SXFMapE_CURVE_STYLE_FONT_PATTERNC(SXFInstanceIDC* IN_InstanceIDManeger) ;

//	<�f�X�g���N�^>
	virtual	~SXFMapE_CURVE_STYLE_FONT_PATTERNC() ;

//�G���e�B�e�B�p�����^�̓o�^
	int	SetParameter();

//	<�����o�ϐ�>	//////////////////////////////////////
//  ENTITY curve_style_font_pattern;
//      visible_segment_length   : positive_length_measure;
//      invisible_segment_length : positive_length_measure;
//  END_ENTITY; -- curve_style_font_pattern

//<�G���e�B�e�B�f�[�^>
//#81 = CURVE_STYLE_FONT_PATTERN(4., 2.);
///	CString		m_name;		//name�p�����^
	double		m_visi;		//�\�������̒���
	double		m_invisi;	//��\�������̒���

private :

protected :

} ;

#endif
