/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_ColorBaseC.h						�쐬���F2000.04.17

	�P�D�N���X�T�v
		�V���{���A�����A�n�b�`���O�t�B�[�`����color�p�����^���Ǘ�����N���X
		�iCurveStyle�ȊO�j

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/

#ifndef _SXFMapF_ColorBaseC_CLASS_
#define _SXFMapF_ColorBaseC_CLASS_

#include "SXFMapF_LayerBaseC.h"

class SXFMapF_ColorBaseC : public SXFMapF_LayerBaseC  {
public :
//
//	<�f�t�H���g�R���X�g���N�^>
	SXFMapF_ColorBaseC( );

//	<�f�X�g���N�^>
	virtual	~SXFMapF_ColorBaseC( );

//	<�t�B�[�`���\���̂̎擾>
//  BOOL GetStructData( void* INOUT_Struct );

public:
	int	m_color ;				//�F�R�[�h

};
#endif
