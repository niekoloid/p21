/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapA_SYMBOL_STYLEC.h						�쐬���F2000.04.21

	�P�D�N���X�T�v
		SYMBOL_STYLE���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.21	

**/
#ifndef _SXFMapA_SYMBOL_STYLEC_CLASS_
#define _SXFMapA_SYMBOL_STYLEC_CLASS_

#include <afx.h>

#include "SXFMapT_EnumC.h"

class SXFMapA_SYMBOL_STYLEC {
public :
//
//	<�f�t�H���g�R���X�g���N�^>
	SXFMapA_SYMBOL_STYLEC( ) ;

//
//	<�f�X�g���N�^>
	virtual	~SXFMapA_SYMBOL_STYLEC() ;

////////styles�̎��
E_AnnoKindtype  m_stylesKind;//////////////////////
		//	NONSTYLE,		//0:�s��
		//	CURVESTYLE,		//1:
		//	SYMBOLSTYLE,	//2:
		//	FILLSTYLE,		//3:
		//	TEXTSTYLE,		//4:
		//	NULLSTYLE		//5:

//	<��`�e�[�u���₢���킹�p�̃C���X�^���XID>

	//	Colour�ւ̃C���X�^���X�h�c
	int m_colorID;

//	<��`�e�[�u���v�f�̃R�[�hD>

	//	Colour�R�[�h
	int m_color;

private :

protected :

} ;
#endif
