/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_ARCC.h						�쐬���F2000.04.17

	�P�D�N���X�T�v
		�N���\�C�h�t�B�[�`�����Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/

#ifndef _SXFMapF_CLOTHOIDC_CLASS_
#define _SXFMapF_CLOTHOIDC_CLASS_

class SXFMapF_CLOTHOIDC : 
	public SXFMapFeatureBaseC,
	public SXFMapF_CurveStyleBaseC {
public :
	SXFMapF_CLOTHOIDC( );
	~SXFMapF_CLOTHOIDC( );

	BOOL GetStructData( Clothoid_Struct* INOUT_Struct );

public:
	double	base_x ;			/* �z�u��_�w���W */
	double	base_y ;			/* �z�u��_�x���W */
	double	parameter ;			/* �N���\�C�h�p�����[�^ */
	int direction;				/* �����t���O */
	double angle;				/* ��]�p */
	double start_length;		/* �J�n�Ȑ��� */
	double end_length;			/* �I���Ȑ��� */
};
#endif
