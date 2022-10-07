/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapBaseC.h						�쐬���F2000.04.17

	�P�D�N���X�T�v
		���[�g�G���e�B�e�BID���Ǘ�����

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#ifndef _SXFMAPBASEC_CLASS_
#define _SXFMAPBASEC_CLASS_

#include <afx.h>

#include "SXFMapInstIDC.h"
#include "SXFMapT_EnumC.h"

class SXFInstanceIDC;
class SXFComInfoC;

class SXFMapBaseC : public SXFMapInstIDC {
public :
//
//	<�f�t�H���g�R���X�g���N�^>
	SXFMapBaseC() ;

//	<�R���X�g���N�^>
//	<�C���X�^���X�h�c�ւ̃|�C���^��o�^����������>
	SXFMapBaseC(SXFInstanceIDC* IN_InstanceIDManeger) ;

//	<�C���X�^���X�h�c�Ƌ��ʏ��Ǘ��ւ̃|�C���^��o�^����������>
	SXFMapBaseC(SXFInstanceIDC* IN_InstanceIDManeger,SXFComInfoC* IN_ComInfoC ) ;

//	<���[�g�t�B�[�`���h�c��o�^����>
	SXFMapBaseC(int) ;
//
//	<�R���X�g���N�^>
	SXFMapBaseC(int	, int) ;

//	<�f�X�g���N�^>
//
	virtual	~SXFMapBaseC() ;

//
//	<���[�gID�̐ݒ�>
	virtual	int	SetRootID(int);
//
//	<���[�gID�̎擾>
	int	GetRootID( );

private :

protected :

//	<���[�g�h�c>
	int		m_RootID ;

//	<���e�덷>
	double	m_Eps_lenth;
	double	m_Eps_angle;

//	<���ʏ��Ǘ��ւ̃|�C���^>
	SXFComInfoC* m_ComInfoC;

} ;

#endif
