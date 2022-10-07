/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapF_SFIGORGC.cpp						�쐬���F2000.04.17

	�P�D�N���X�T�v
		�����}�`��`�t�B�[�`�����Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#include "stdafx.h"
#include "SXFStruct.h"
#include "SXFMapFeatureBaseC.h"
#include "SXFMapF_SFIGORGC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_SFIGORGC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�f�t�H���g�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapF_SFIGORGC::SXFMapF_SFIGORGC()

	����  �F	�^			������				���e
			�Ȃ�
	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapF_SFIGORGC::SXFMapF_SFIGORGC()
{
	m_name.Empty();
	m_flag   =0;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_SFIGORGC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		(�f�X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapF_SFIGORGC::~SXFMapF_SFIGORGC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapF_SFIGORGC::~SXFMapF_SFIGORGC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_SFIGORGC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�t�B�[�`���\���̂̎擾

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapF_SFIGORGC::GetStructData(Sfigorg_Struct* INOUT_Struct)

	����  �F	�^				������			���e
				Sfigorg_Struct* INOUT_Struct    �\����

	���A�l�F���펞�FTRUE

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
BOOL SXFMapF_SFIGORGC::GetStructData( Sfigorg_Struct* INOUT_Struct )
{

//	MOD(S)	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
	//strcpy( INOUT_Struct->name, m_name );

	// �����v�f�Ɠ�����257�o�C�g�ȏ�̕������256�ɐ؂�l�߂�
	size_t ilen = strlen(m_name);
	if (ilen <= 256) {
		strcpy_s( INOUT_Struct->name,_countof(INOUT_Struct->name), m_name );
	}
	else {
		/* ���b�Z�[�W���o�� */
		// ������ m_RootID = 0,m_TypeName == "" �����Ǖ����v�f�Ɠ��������ɂ��Ă���
		SXFErrorMsgC::RecordError(SXFNAMELENGTH,m_TypeName,	2, m_RootID, m_TypeName);
		/* �擪����256�o�C�g�؂��� */
		strcpy_s( INOUT_Struct->name,_countof(INOUT_Struct->name), m_name.Left(256) );
	}
//	MOD(E)	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27

	INOUT_Struct->flag	=  m_flag;

	return TRUE;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapF_SFIGORGC.cpp						�쐬���F2000.05.13

	�P�D�@�\�T�v
		�����}�`���̐ݒ�
	�Q�D�C���^�[�t�F�C�X
		BOOL SXFMapF_SFIGORGC::SetSubName(
			CString IN_name )		//	DRAUGHTING_SUBFIGURE_REPRESENTATION
										 �� NAME�p�����^ 


	����  �F	�^			������				���e
				CString 	IN_name

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.05.13	�呺(FQS)
**/

//
BOOL SXFMapF_SFIGORGC::SetSubName(CString IN_name)
{
//#227 = DRAUGHTING_SUBFIGURE_REPRESENTATION
//('$$FM_SubFigTransform', (#140, #180, #200, #226), #225);

	CStringArray name;
	CString a0(" ");
	CString a1("$$SXF_FM_");
	CString a2("$$SXF_FG_");
	CString a3("$$SXF_G_");
	CString a4("$$SXF_P_");

	name.Add((LPCTSTR)a0);
	name.Add((LPCTSTR)a1);
	name.Add((LPCTSTR)a2);
	name.Add((LPCTSTR)a3);
	name.Add((LPCTSTR)a4);

	//������`�t���O
	m_flag = 0;
	CString temstring;
	int index = -1;
	int length = -1;
	for(int i=1;i<=4;i++){
		temstring = name[i];
		if((index = IN_name.Find(name[i])) != -1){
			m_flag=i;
			length = name[i].GetLength();
			IN_name.TrimLeft();
			IN_name = IN_name.Mid(index+length);
			m_name = IN_name;
			break;
		}
	}
	return TRUE;
}
