/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_CurveStyleBaseC.h						�쐬���F2000.04.17

	�P�D�N���X�T�v
		�t�B�[�`����CurveStyle���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/

#ifndef _SXFMapF_CurveStyleBaseC_CLASS_
#define _SXFMapF_CurveStyleBaseC_CLASS_

#include "SXFMapF_LayerBaseC.h"

class SXFMapF_CurveStyleBaseC : public SXFMapF_LayerBaseC  {
public :
//
//	<�f�t�H���g�R���X�g���N�^>
	SXFMapF_CurveStyleBaseC( );
//	<�f�X�g���N�^>
	virtual	~SXFMapF_CurveStyleBaseC( );
	
//	<�t�B�[�`���\���̂̎擾>
//  BOOL GetStructData( void* INOUT_Struct );

public:
	int	m_color ;				//�F�R�[�h
	int	m_type ;				//����R�[�h
	int	m_line_width ;			//�����R�[�h
};
#endif

