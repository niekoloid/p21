/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapFeatureBaseC.h						�쐬���F2000.04.17

	�P�D�N���X�T�v
		���[�g�G���e�B�e�BID�A�t�B�[�`���̎�ʁi�A�Z���u���A��`�e�[�u���A��ʁj�A
		�t�B�[�`�������Ǘ�����

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#ifndef _SXFMapFeatureBaseC_CLASS_
#define _SXFMapFeatureBaseC_CLASS_

#include <afx.h>

#include "SXFF_FeatureTypeE.h"
#include "SXFMapBaseC.h"

class SXFInstanceIDC;

class SXFMapFeatureBaseC : public SXFMapBaseC {
public :
//
//	<�f�t�H���g�R���X�g���N�^>
	SXFMapFeatureBaseC( ) ;
	
//	<�C���X�^���X�h�c�ւ̃|�C���^��o�^����������>
	SXFMapFeatureBaseC(SXFInstanceIDC* IN_InstanceIDManeger) ;

//	<�R���X�g���N�^�F���[�g�t�B�[�`���h�c��o�^����>
	SXFMapFeatureBaseC(int) ;
//

//	<�f�X�g���N�^>
//
	virtual	~SXFMapFeatureBaseC() ;

//	<�t�B�[�`����ʂ̐ݒ�>
//	int	SetFetureKind(int);
//
//	<�t�B�[�`����ʂ̎擾>
//	int	GetFetureKind();
//
//	<�t�B�[�`�����̐ݒ�>
	int	SetFeatureName(CString);
//
//	<�t�B�[�`�����̎擾>
	CString	GetFeatureName();
	
//
//	<�t�B�[�`���̃��[�g�G���e�B�e�B�ւ̃|�C���^�̐ݒ�>
//	int	SetRootEntityP(void*);

/////// �����o�ϐ� //////////////////////////////////////////////
//
//	<�t�B�[�`����>
	CString	m_TypeName;

//	<�t�B�[�`���^�C�v>
	E_type m_Type;

//	<�t�B�[�`���\���̂ւ̃|�C���^>
	void*	m_StructData;	
//
//	<�t�B�[�`�����>
//	int		m_FeatureKind;
//	0:�s�� 1:��`�e�[�u���v�f 2:�A�Z���u���v�f
//	3:��ʗv�f 99:���̑��i��\���A�P�ʌn�j

//	<�t�B�[�`���̃��[�g�G���e�B�e�B�ւ̃|�C���^>
//	void*	m_RootEntityP;

private :

protected :

} ;
#endif
