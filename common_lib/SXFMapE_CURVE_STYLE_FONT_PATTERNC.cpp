/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_CURVE_STYLE_FONT_PATTERNC.cpp						�쐬���F2000.04.17

	�P�D�N���X�T�v
		EntityData���^�ϊ�����

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#include "stdafx.h"
#include "SXFMapE_CURVE_STYLE_FONT_PATTERNC.h"
#include "SXFMapEntAConvC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_CURVE_STYLE_FONT_PATTERNC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�f�t�H���g�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_CURVE_STYLE_FONT_PATTERNC::SXFMapE_CURVE_STYLE_FONT_PATTERNC()

	����  �F	�^			������				���e
			�Ȃ�
	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_CURVE_STYLE_FONT_PATTERNC::SXFMapE_CURVE_STYLE_FONT_PATTERNC()
{
//	<������>
	m_EntityName = DEF_CURVE_STYLE_FONT_PATTERN;
//#81 = CURVE_STYLE_FONT_PATTERN(4., 2.);
//<�G���e�B�e�B�f�[�^>
//	m_name.Empty();		//name�p�����^
	m_visi = 0;		//�\�������̒���
	m_invisi = 0;	//��\�������̒���

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_CURVE_STYLE_FONT_PATTERNC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�C���X�^���X�h�c�ւ̃|�C���^���w�肵�Đ�������ꍇ
		(�R���X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_CURVE_STYLE_FONT_PATTERNC::SXFMapE_CURVE_STYLE_FONT_PATTERNC(
						SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	�����F	�^				������				���e
			SXFInstanceIDC* IN_InstanceIDManeger	�ݽ�ݽID�Ǘ���޼ު��

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_CURVE_STYLE_FONT_PATTERNC::SXFMapE_CURVE_STYLE_FONT_PATTERNC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
{
//	<������>
	m_EntityName = DEF_CURVE_STYLE_FONT_PATTERN;
//#81 = CURVE_STYLE_FONT_PATTERN(4., 2.);
//<�G���e�B�e�B�f�[�^>
//	m_name.Empty();		//name�p�����^
	m_visi = 0;		//�\�������̒���
	m_invisi = 0;	//��\�������̒���
}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_CURVE_STYLE_FONT_PATTERNC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		(�f�X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_CURVE_STYLE_FONT_PATTERNC::~SXFMapE_CURVE_STYLE_FONT_PATTERNC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_CURVE_STYLE_FONT_PATTERNC::~SXFMapE_CURVE_STYLE_FONT_PATTERNC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_CURVE_STYLE_FONT_PATTERNC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�G���e�B�e�B�̃p�����^�ݒ�

	�Q�D�C���^�[�t�F�C�X
		int		SXFMapE_CURVE_STYLE_FONT_PATTERNC::SetParameter()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/


int SXFMapE_CURVE_STYLE_FONT_PATTERNC::SetParameter()

{
//	ADD(S)	�o�O�C��	K.Naono	01.09.26
	if( m_EntityArray->GetSize() != 2 ) {
		//�G���e�B�e�B�p�����^�̐��Ɏӂ肪����܂��B
			SXFErrorMsgC::RecordError(
				SXFPARAMS,			//err���b�Z�[�W�ԍ�
				m_EntityName,		//�G���e�B�e�B��
				2,					//�p�����^�̌�
				m_RootID,			//�p�����^
				m_EntityName
				);
		return SXFPARAMS;	//-55003
	}
//	ADD(E)	�o�O�C��	K.Naono	01.09.26

//#81 = CURVE_STYLE_FONT_PATTERN(4., 2.);
	SXFMapEntAConvC convent(m_EntityArray);
	//<name>
//	convent.GetCString(0,m_name);
	convent.GetDouble(0,m_visi);
	convent.GetDouble(1,m_invisi);

//	m_visi ;	//�\�������̒���
//	m_invisi ;	//��\�������̒���
/*	int num;
	CArray<double,double> array;
	convent.GetSetDouble(0,num,array);
	if ( num >=2 ){
		m_visi   = array[0];
		m_invisi = array[1];
	}
	else{
		//�G���e�B�e�B�p�����^�̐��Ɏӂ肪����܂��B
			SXFErrorMsgC::RecordError(
				SXFPARAMS,			//err���b�Z�[�W�ԍ�
				m_EntityName,		//�G���e�B�e�B��
				2,					//�p�����^�̌�
				m_RootID,			//�p�����^
				m_EntityName
				);
		return SXFPARAMS;	//-55003
	}*/
	return 0;
}
