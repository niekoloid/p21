/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapA_CURVE_STYLEC.h						�쐬���F2000.04.21

	�P�D�N���X�T�v
		CURVE_STYLE���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.21	

**/
#ifndef _SXFMapA_CURVE_STYLEC_CLASS_
#define _SXFMapA_CURVE_STYLEC_CLASS_

#include <afx.h>

#include "SXFMapT_EnumC.h"

class SXFMapA_CURVE_STYLEC {
public :
//
//	<�f�t�H���g�R���X�g���N�^>
	SXFMapA_CURVE_STYLEC( ) ;

//
//	<�f�X�g���N�^>
	virtual	~SXFMapA_CURVE_STYLEC() ;

////////styles�̎��
E_AnnoKindtype	m_stylesKind;//////////////////////
		//	NONSTYLE,		//0:�s��
		//	CURVESTYLE,		//1:
		//	SYMBOLSTYLE,	//2:
		//	FILLSTYLE,		//3:
		//	TEXTSTYLE,		//4:
		//	NULLSTYLE		//5:


//	<��`�e�[�u���₢���킹�p�̃C���X�^���XID>

	//	Colour�ւ̃C���X�^���X�h�c
	int m_colorID;
	
	//	font�ւ̃C���X�^���X�h�c
	int m_fontID;
	
	//	width�ւ̃C���X�^���X�h�c
	int m_widthID;

//	<��`�e�[�u���v�f�̃R�[�hD>

	//	Colour�R�[�h
	int m_color;

	//	font�R�[�h
	int m_font;

	//	width�R�[�h
	int m_width;

private :

protected :

} ;
#endif
