/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_EXTERNAL_SOURCEC.h						�쐬���F2000.04.17

	�P�D�N���X�T�v
		EXTERNAL_SOURCE���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#ifndef _SXFMapE_EXTERNAL_SOURCEC_CLASS_
#define _SXFMapE_EXTERNAL_SOURCEC_CLASS_

class SXFMapE_EXTERNAL_SOURCEC:public SXFMapEntityBaseC{
public :
	SXFMapE_EXTERNAL_SOURCEC( );
	SXFMapE_EXTERNAL_SOURCEC(
		SXFInstanceIDC* IN_InstanceIDManeger);

	~SXFMapE_EXTERNAL_SOURCEC( );

	int	SetParameter( );

public:

	CString m_Name;
};
#endif
