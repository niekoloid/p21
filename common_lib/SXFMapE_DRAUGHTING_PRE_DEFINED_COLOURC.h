/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_DRAUGHTING_PRE_DEFINED_COLOURC.h						�쐬���F2000.04.17

	�P�D�N���X�T�v
		DRAUGHTING_PRE_DEFINED_COLOUR���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#ifndef _SXFMapE_DRAUGHTING_PRE_DEFINED_COLOURC_CLASS_
#define _SXFMapE_DRAUGHTING_PRE_DEFINED_COLOURC_CLASS_

#include <afx.h>
#include <afxtempl.h>
#include "SXFMapEntityBaseC.h"

class SXFInstanceIDC;

class SXFMapE_DRAUGHTING_PRE_DEFINED_COLOURC : public SXFMapEntityBaseC {
public :
//
//	<�f�t�H���g�R���X�g���N�^>
	SXFMapE_DRAUGHTING_PRE_DEFINED_COLOURC( ) ;

//	<�R���X�g���N�^>
//	<�C���X�^���X�h�c�ւ̃|�C���^��o�^����������>
	SXFMapE_DRAUGHTING_PRE_DEFINED_COLOURC(SXFInstanceIDC* IN_InstanceIDManeger) ;

//	<�f�X�g���N�^>
	virtual	~SXFMapE_DRAUGHTING_PRE_DEFINED_COLOURC() ;

//�G���e�B�e�B�p�����^�̓o�^
	int	SetParameter();

//	<�����o�ϐ�>	//////////////////////////////////////

//<�G���e�B�e�B�f�[�^>
//  ENTITY draughting_pre_defined_colour
//    SUBTYPE OF (pre_defined_colour);
//    WHERE
//      wr1: SELF.name IN ['black','red','green','blue','yellow','magenta',
//               'cyan','white'];
//  END_ENTITY; -- draughting_pre_defined_colour

//#40 = DRAUGHTING_PRE_DEFINED_COLOUR('black');
//name�p�����^
	CString		m_name;	

private :

protected :

} ;

#endif
