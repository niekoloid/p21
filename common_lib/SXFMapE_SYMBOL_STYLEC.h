/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_SYMBOL_STYLEC.h						�쐬���F2000.04.17

	�P�D�N���X�T�v
		SYMBOL_STYLE���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#ifndef _SXFMapE_SYMBOL_STYLEC_CLASS_
#define _SXFMapE_SYMBOL_STYLEC_CLASS_

#include <afx.h>
#include <afxtempl.h>

#include "SXFMapEntityBaseC.h"

class SXFInstanceIDC;
class SXFMapE_SYMBOL_COLOURC;

class SXFMapE_SYMBOL_STYLEC : public SXFMapEntityBaseC {
public :
//
//	<�f�t�H���g�R���X�g���N�^>
	SXFMapE_SYMBOL_STYLEC( ) ;

//	<�R���X�g���N�^>
//	<�C���X�^���X�h�c�ւ̃|�C���^��o�^����������>
	SXFMapE_SYMBOL_STYLEC(SXFInstanceIDC* IN_InstanceIDManeger) ;

//	<�f�X�g���N�^>
	virtual	~SXFMapE_SYMBOL_STYLEC() ;

//�G���e�B�e�B�p�����^�̓o�^
	int	SetParameter();

//	<�����o�ϐ�>	//////////////////////////////////////

//<�G���e�B�e�B�f�[�^>
/*
  ENTITY symbol_style;
      name            : label;
      style_of_symbol : symbol_style_select;
  END_ENTITY; -- symbol_style
  
  ENTITY symbol_colour;
      colour_of_symbol : colour;
  END_ENTITY; -- symbol_colour
*/
//#100=SYMBOL_COLOUR(#40);
//#110=SYMBOL_STYLE(' ',#100);

	//	1.name�p�����^
	CString		m_name;

//�C���X�^���XID���`�e�[�u���I�u�W�F�N�g�ɓn���A
//�Y�������`�e�[�u���̃R�[�h���󂯎��B
//���̂��ߎQ�Ɛ�̃G���e�B�e�B�C���X�^���X�͍쐬���Ȃ��B

	//	2.symbol_colour �ւ̃C���X�^���XID
	int		m_symbol_colour_Inst;

	//	symbol_colour�ւ̃|�C���^
	SXFMapE_SYMBOL_COLOURC*		m_symbol_colour_P;

private :

protected :

} ;

#endif
