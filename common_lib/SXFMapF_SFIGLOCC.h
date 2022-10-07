/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_SFIGLOCC.h						�쐬���F2000.04.17

	�P�D�N���X�T�v
		�����}�`�z�u�t�B�[�`�����Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/

#ifndef _SXFMapF_SFIGLOCC_CLASS_
#define _SXFMapF_SFIGLOCC_CLASS_

class SXFMapF_SFIGLOCC : 
	public SXFMapFeatureBaseC,
	public SXFMapF_LayerBaseC {
public :
	SXFMapF_SFIGLOCC( );
	~SXFMapF_SFIGLOCC( );

	BOOL GetStructData( Sfigloc_StructDF* INOUT_Struct );


public:
/*
//------------------------------------------------
//	�����}�`�z�u
//------------------------------------------------
typedef struct Sfigloc_StructDF{
	int layer;						//���C���R�[�h
	char name[MAXFIGURENAME];		//�����}�`��
	double x;						//�z�u�ʒuX���W
	double y;						//�z�u�ʒuY���W
	double angle;					//��]�p
	double ratio_x;					//X�����ړx
	double ratio_y;					//Y�����ړx
} Sfigloc_Struct;
*/

	CString m_name;				  	//�����}�`��
	double m_angle;					//��]�p
	double m_ratio_x;				//X�����ړx
	double m_ratio_y;				//Y�����ړx
//	�}�[�J�V���{���A�O����`�V���{���A���@�[�_�V���{������
	double m_start_x;				//�z�u�ʒuX���W
	double m_start_y;				//�z�u�ʒuY���W

};
#endif
