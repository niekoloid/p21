/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_SymbolStyleBaseC.h						�쐬���F2000.04.17

	�P�D�N���X�T�v
		�t�B�[�`����SymbolStyle���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/

#ifndef _SXFMapF_SymbolStyleBaseC_CLASS_
#define _SXFMapF_SymbolStyleBaseC_CLASS_

#include "SXFMapF_LayerBaseC.h"

class SXFMapF_SymbolStyleBaseC : public SXFMapF_LayerBaseC  {
public :
//
//	<�f�t�H���g�R���X�g���N�^>
	SXFMapF_SymbolStyleBaseC( );

//	<�f�X�g���N�^>
	virtual	~SXFMapF_SymbolStyleBaseC( );

//	<�t�B�[�`���\���̂̎擾>
//  BOOL GetStructData( void* INOUT_Struct );

public:
	int	m_color ;				//�F�R�[�h

};
#endif
