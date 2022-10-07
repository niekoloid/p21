/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_TERMSYMBOLC.cpp					�쐬���F2000.04.17

	�P�D�N���X�T�v
		�t�B�[�`���̖����Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#include "stdafx.h"
#include "SXFStruct.h"
#include "SXFMapFeatureBaseC.h"
#include "SXFMapF_ColorBaseC.h"
#include "SXFMapF_TERMSYMBOLC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_TERMSYMBOLC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�f�t�H���g�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapF_TERMSYMBOLC::SXFMapF_TERMSYMBOLC()

	����  �F	�^			������				���e
			�Ȃ�
	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapF_TERMSYMBOLC::SXFMapF_TERMSYMBOLC()
{

	m_Type = dimension_terminator_symbol ;
	m_TypeName = "dimension_terminator_symbol";

	m_flag = 0;				//���P�Q�t���O�i�O�F�����l,�P�F�[�_�P��, �Q�F�[�_�Q��)
	m_arr_code;				//���R�[�h
	m_start_x = 0.0;	    //�z�u�ʒuX���W
	m_start_y = 0.0;		//�z�u�ʒuY���W
	m_scale = 0.0;			//���z�u�{��
	m_vecter_x =0.0;		//���̃x�N�g��X
	m_vecter_y =0.0;		//���̃x�N�g��Y

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_TERMSYMBOLC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		(�f�X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapF_TERMSYMBOLC::~SXFMapF_TERMSYMBOLC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapF_TERMSYMBOLC::~SXFMapF_TERMSYMBOLC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_TERMSYMBOLC.cpp							�쐬���F2000.05.13

	�P�D�@�\�T�v
		�⏕���̃t���O�ݒ�
	�Q�D�C���^�[�t�F�C�X
		BOOL SXFMapF_LINEC::Set12flg(
			CString& IN_name )		//	BODY �� NAME�p�����^ 


	����  �F	�^			������				���e
				CString& 	IN_name

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.05.13	�呺(FQS)
**/

//	<�⏕���̒[�_�P�C�Q�ǂ��炩�H��\�킷�t���O�ݒ�>
BOOL SXFMapF_TERMSYMBOLC::Set12flg(CString& IN_name)
{

	CStringArray pojflg;
	CString a1(" ");
	CString a2("$$SXF_arw_1");
	CString a3("$$SXF_arw_2");
	pojflg.Add((LPCTSTR)a1);
	pojflg.Add((LPCTSTR)a2);
	pojflg.Add((LPCTSTR)a3);

//�[�_�P�Q�t���O�i0:�����l,1:�[�_�P��, 2:�[�_�Q��)
	m_flag = 0;
	for(int i=1;i<=2;i++){
		if( IN_name==pojflg.GetAt(i)){
			m_flag=i;
			break;
		}
	}
	return TRUE;
}
