/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_TERMSYMBOLC.h						�쐬���F2000.04.17

	�P�D�N���X�T�v
		�t�B�[�`���̖����Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/

#ifndef _SXFMapF_TERMSYMBOLC_CLASS_
#define _SXFMapF_TERMSYMBOLC_CLASS_

class SXFMapF_TERMSYMBOLC : 
	public SXFMapFeatureBaseC,
	public SXFMapF_ColorBaseC {
public :
	SXFMapF_TERMSYMBOLC( );
	~SXFMapF_TERMSYMBOLC( );

//    BOOL GetStructData( Externally_Defined_Symbol_Struct* INOUT_Struct );

//	<�⏕���̒[�_�P�C�Q�ǂ��炩�H��\�킷�t���O�ݒ�>
	BOOL Set12flg(CString& IN_name);

public:
/*
//------------------------------------------------
//	���@�[�_�V���{��
//------------------------------------------------
//���������@�̏ꍇ��
	int		arr1_code1 ;	//���P�R�[�h
	int		arr1_code2 ;	//���P���O�R�[�h(�O�F�Ȃ��A�P�F�O�����A�Q�F������)
	double	arr1_x ;		//���P�z�u�n�_�w���W
	double	arr1_y ;		//���P�z�u�n�_�x���W
	double	arr1_r ;		//���P�z�u�{��
*/
//	���@�[�_�V���{���ŗL
	int    m_flag;				//���P�Q�t���O�i�O�F�����l,�P�F�[�_�P��, �Q�F�[�_�Q��)
	int    m_arr_code;			//���R�[�h

//	�}�[�J�V���{���A�O����`�V���{���A���@�[�_�V���{������
	double m_start_x;			//�z�u�ʒuX���W
	double m_start_y;			//�z�u�ʒuY���W
	double m_scale;				//���z�u�{��

	double m_vecter_x;			//���̃x�N�g��X
	double m_vecter_y;			//���̃x�N�g��Y

};
#endif
