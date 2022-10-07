/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_CURVE_STYLEC.h						�쐬���F2000.04.17

	�P�D�N���X�T�v
		CURVE_STYLE���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#ifndef _SXFMapE_CURVE_STYLEC_CLASS_
#define _SXFMapE_CURVE_STYLEC_CLASS_

#include <afx.h>
#include <afxtempl.h>

#include "SXFMapEntityBaseC.h"

class SXFInstanceIDC;
class SXFMapE_CARTESIAN_POINTC;
class SXFMapE_VECTORC;

class SXFMapE_CURVE_STYLEC : public SXFMapEntityBaseC {
public :
//
//	<�f�t�H���g�R���X�g���N�^>
	SXFMapE_CURVE_STYLEC( ) ;

//	<�R���X�g���N�^>
//	<�C���X�^���X�h�c�ւ̃|�C���^��o�^����������>
	SXFMapE_CURVE_STYLEC(SXFInstanceIDC* IN_InstanceIDManeger) ;

//	<�f�X�g���N�^>
	virtual	~SXFMapE_CURVE_STYLEC() ;


//�G���e�B�e�B�p�����^�̓o�^
	int	SetParameter();

//	<�����o�ϐ�>	//////////////////////////////////////

//<�G���e�B�e�B�f�[�^>
/*
  ENTITY curve_style;
	  name		   : label;
	  curve_font   : curve_font_or_scaled_curve_font_select;
	  curve_width  : size_select;
	  curve_colour : colour;
  END_ENTITY; -- curve_style
*/
//#100 = CURVE_STYLE('curve_style3', #20, #60, #40);
	//	1.name�p�����^
	CString		m_name;

//�C���X�^���XID���`�e�[�u���I�u�W�F�N�g�ɓn���A
//�Y�������`�e�[�u���̃R�[�h���󂯎��B
//���̂��ߎQ�Ɛ�̃G���e�B�e�B�C���X�^���X�͍쐬���Ȃ��B

	//	2.font �ւ̃C���X�^���XID
	int		m_font_Inst;

	//	3.width �ւ̃C���X�^���XID
	int		m_width_Inst;

	//	4.colour �ւ̃C���X�^���XID
	int		m_colour_Inst;

private :

protected :

} ;

#endif
