/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapTableC.h						�쐬���F2000.04.21

	�P�D�N���X�T�v
		��`�e�[�u���̃}�b�s���O���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.21	

**/
#ifndef _SXFMapTableC_CLASS_
#define _SXFMapTableC_CLASS_

#include <afx.h>
#include "SXFMapEntityBaseC.h"

class SXFInstanceIDC;
class SXFComInfoC;
class SXFTableManagerC;//ID_218_000706_ins

class SXFMapTableC: public SXFMapEntityBaseC{
public :
//
//	<�f�t�H���g�R���X�g���N�^>
	SXFMapTableC( ) ;

//	<�C���X�^���X�h�c�ւ̃|�C���^��o�^����������>
	SXFMapTableC(
		SXFInstanceIDC* IN_InstanceIDManeger,
		SXFComInfoC* IN_ComInfoC,
		SXFTableManagerC* IN_TableManager) ;

//	<�R���X�g���N�^�F���[�g�h�c�ƃt�B�[�`����ʂ�o�^����������>
	SXFMapTableC(int,int) ;

//

//	<�f�X�g���N�^>
	virtual	~SXFMapTableC() ;

//	<�A�Z���u���v�f�̃��[�g�h�c�̓o�^>
//	int		SetAssemblyRootID(int) ;
//	<��ʗv�f�̃��[�g�h�c�̓o�^��Body��ʔ���>
//	int		SetGeometryRootID(int) ;
//
//	<�t�B�[�`���\���̂ւ̒l�̐ݒ�>
	int	SetFeatureParameter(int& OUT_Type,	LPVOID&	OUT_Class);

//
//	<��`�e�[�u���v�f�̃��[�gEntity�ւ̃|�C���^�̎擾>
//	void*	GetBodyP();


//	<Layer�̃G�������g��
//	CArray<int,int>	m_LayerElements;
	CUIntArray	m_LayerElements;

private :

protected :

//	<SXFComInfoC�ւ̃|�C���^>
		SXFComInfoC* m_ComInfoC;

//	<Table���>
	int			m_Type ;

//	<Body�ւ̃|�C���^>
	void*		m_BodyP ;

	SXFTableManagerC* m_TableManager;


} ;
#endif
