/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_LINEC.h						�쐬���F2000.04.17

	�P�D�N���X�T�v
		�����t�B�[�`�����Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#ifndef _SXFMapF_LINEC_CLASS_
#define _SXFMapF_LINEC_CLASS_


//class SXFInstanceIDC;
//class SXFMapE_CARTESIAN_POINTC;
//class SXFMapE_VECTORC;

//#include "SXFMapFeatureBaseC.h"

class SXFMapF_LINEC : 
	public SXFMapFeatureBaseC,
	public SXFMapF_CurveStyleBaseC  {
public :
//
//	<�f�t�H���g�R���X�g���N�^>
	SXFMapF_LINEC( ) ;

//	<�R���X�g���N�^>
//	<�C���X�^���X�h�c�ւ̃|�C���^��o�^����������>
//	SXFMapF_LINEC(SXFInstanceIDC* IN_InstanceIDManeger) ;

//	<�f�X�g���N�^>
	virtual	~SXFMapF_LINEC() ;

//	<�t�B�[�`���\���̂̎擾>
    BOOL GetStructData( Line_Struct* INOUT_Struct );

//	<�⏕���̒[�_�P�C�Q�ǂ��炩�H��\�킷�t���O�ݒ�>
	BOOL Set12flg(CString& IN_name);

//	<�����o�ϐ�>	//////////////////////////////////////

//<�t�B�[�`���f�[�^>
/*
//------------------------------------------------
//	����
//------------------------------------------------
typedef struct Line_StructDF{
	int layer;				//���C���R�[�h
	int color;				//�F�R�[�h
	int type;				//����R�[�h
	int line_width;			//�����R�[�h
	
	double start_x;			//�n�_�w���W
	double start_y;			//�n�_�x���W
	double end_x;			//�I�_�w���W
	double end_y;			//�I�_�x���W
} Line_Struct;
*/

	double m_start_x;			//�n�_�w���W
	double m_start_y;			//�n�_�x���W
	double m_end_x;			//�I�_�w���W
	double m_end_y;			//�I�_�x���W


//------------------------------------------------
//	PROJECTION LINE �ŗL
//------------------------------------------------

	int    m_flag;			//�[�_�P�Q�t���O�i0:�����l,1:�[�_�P��, 2:�[�_�Q��)
	double m_org_x;			//��_�w���W
	double m_org_y;			//��_�x���W

private :

protected :

} ;
#endif
