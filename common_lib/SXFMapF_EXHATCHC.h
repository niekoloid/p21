/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_EXHATCHC.h						�쐬���F2000.04.17

	�P�D�N���X�T�v
		�n�b�`���O�i����`�j�t�B�[�`�����Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/

#ifndef _SXFMapF_EXHATCHC_CLASS_
#define _SXFMapF_EXHATCHC_CLASS_

class SXFMapF_EXHATCHC : 
	public SXFMapFeatureBaseC ,
	public SXFMapF_LayerBaseC{
public :
	SXFMapF_EXHATCHC( );
	~SXFMapF_EXHATCHC( );

	BOOL GetStructData( Externally_Defined_Hatch_Struct* INOUT_Struct );

public:
/*
typedef struct Externally_Defined_Hatch_StructDF{
	int layer;
	char name[MAXHATCHNAME];
	int out_id;
	int number;
	CArray<int, int> in_id;
} Externally_Defined_Hatch_Struct;
*/

	CString m_name;				  	//�n�b�`���O��
	int m_out_id;
	int m_number;
	CArray<int,int> m_in_id;
};
#endif

