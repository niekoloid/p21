/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_CURVE_STYLE_FONTC.h						�쐬���F2000.04.17

	�P�D�N���X�T�v
		CURVE_STYLE_FONT���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#ifndef _SXFMapE_CURVE_STYLE_FONTC_CLASS_
#define _SXFMapE_CURVE_STYLE_FONTC_CLASS_

#include <afx.h>
#include <afxtempl.h>

#include "SXFMapEntityBaseC.h"

class SXFInstanceIDC;
class SXFMapE_CURVE_STYLE_FONT_PATTERNC;

class SXFMapE_CURVE_STYLE_FONTC : public SXFMapEntityBaseC {
public :
//
//	<�f�t�H���g�R���X�g���N�^>
	SXFMapE_CURVE_STYLE_FONTC( ) ;

//	<�R���X�g���N�^>
//	<�C���X�^���X�h�c�ւ̃|�C���^��o�^����������>
	SXFMapE_CURVE_STYLE_FONTC(SXFInstanceIDC* IN_InstanceIDManeger) ;

//	<�f�X�g���N�^>
	virtual	~SXFMapE_CURVE_STYLE_FONTC() ;


//�G���e�B�e�B�p�����^�̓o�^
	int	SetParameter();

//	<�����o�ϐ�>	//////////////////////////////////////

//<�G���e�B�e�B�f�[�^>
//#80 = CURVE_STYLE_FONT('chain_4212', (#81, #82));
	//name�p�����^
	CString		m_name;	
	//m_CURVE_STYLE_FONT_PATTERN_Ins�ւ̃C���X�^���XID
	CArray<int,int>		m_CURVE_STYLE_FONT_PATTERN_Inst;

	//�Z�O�����g��	���G���e�B�e�B�p�����^�ɂ͑��݂��Ȃ��B					
	int	m_Segment;
	//m_CURVE_STYLE_FONT_PATTERN_Ins�ւ̃|�C���^
	CArray<SXFMapE_CURVE_STYLE_FONT_PATTERNC*,SXFMapE_CURVE_STYLE_FONT_PATTERNC*>	m_CURVE_STYLE_FONT_PATTERN_P;

private :

protected :

} ;

#endif
