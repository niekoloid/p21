/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_LayerBaseC.h						�쐬���F2000.04.17

	�P�D�N���X�T�v
		�t�B�[�`���̃��C�����Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/

#ifndef _SXFMapF_LayerBaseC_CLASS_
#define _SXFMapF_LayerBaseC_CLASS_

#include <afx.h>
#include <afxtempl.h>

class SXFMapF_LayerBaseC {
public :
//
//	<�f�t�H���g�R���X�g���N�^>
	SXFMapF_LayerBaseC( );
//	<�f�X�g���N�^>
	virtual	~SXFMapF_LayerBaseC( );

//	<�t�B�[�`���\���̂̎擾>
//  BOOL GetStructData( void* INOUT_Struct );

public:

	int		m_layer ;			//���C���R�[�h

};
#endif
