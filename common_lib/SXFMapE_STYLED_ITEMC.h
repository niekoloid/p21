/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_STYLED_ITEMC.h						�쐬���F2000.04.17

	�P�D�N���X�T�v
		STYLED_ITEM���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#ifndef _SXFMapE_STYLED_ITEMC_CLASS_
#define _SXFMapE_STYLED_ITEMC_CLASS_

#include <afx.h>
#include <afxtempl.h>
#include "SXFMapEntityBaseC.h"

class SXFInstanceIDC;

class SXFMapE_STYLED_ITEMC : public SXFMapEntityBaseC {
public :
//
//	<�f�t�H���g�R���X�g���N�^>
	SXFMapE_STYLED_ITEMC( ) ;

//	<�R���X�g���N�^>
//	<�C���X�^���X�h�c�ւ̃|�C���^��o�^����������>
	SXFMapE_STYLED_ITEMC(SXFInstanceIDC* IN_InstanceIDManeger) ;

//	<�f�X�g���N�^>
	virtual	~SXFMapE_STYLED_ITEMC() ;

//�G���e�B�e�B�p�����^�̓o�^
	int	SetParameter();

//	<�����o�ϐ�>	//////////////////////////////////////

//	<�G���e�B�e�B�f�[�^>
//#101 = STYLED_ITEM('',(#508), #505);

//	styled_item �P�Ƃ̎���name�p�����^���K�v /////////////////////
//	1. name�p�����^>
	CString m_name;

//	<�}�`�������ւ̂h�c>
	int		m_AppeID ;
//	<�}�`�C���X�^���X���ւ̂h�c>
	int		m_InstID ;
//	<�}�`�������ւ̃|�C���^>
//	void*		m_AppeP ;
//	<�}�`�C���X�^���X���ւ̃|�C���^>
//	void*		m_InstP ;
private :

protected :

} ;

#endif
