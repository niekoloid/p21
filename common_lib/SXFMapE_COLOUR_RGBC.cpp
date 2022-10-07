/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_COLOUR_RGBC.cpp						�쐬���F2000.04.17

	�P�D�N���X�T�v
		COLOUR_RGB���Ǘ�����

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#include "stdafx.h"
#include "SXFMapE_COLOUR_RGBC.h"
#include "SXFMapEntAConvC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_COLOUR_RGBC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�f�t�H���g�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_COLOUR_RGBC::SXFMapE_COLOUR_RGBC()

	����  �F	�^			������				���e
			�Ȃ�
	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_COLOUR_RGBC::SXFMapE_COLOUR_RGBC()
{

//#101 = COLOUR_RGB('COLOUR_RGB1', (0., 0.));

//	<������>
	m_EntityName = DEF_COLOUR_RGB;
//
//	<�G���e�B�e�B�f�[�^>
//  ENTITY colour_rgb
//    SUBTYPE OF (colour_specification);
//      red   : REAL;
//      green : REAL;
//      blue  : REAL;
//    WHERE
//      wr1: (0 <= red) AND (red <= 1);
//      wr2: (0 <= green) AND (green <= 1);
//      wr3: (0 <= blue) AND (blue <= 1);
//  END_ENTITY; -- colour_rgb
//#140 = COLOUR_RGB('colour_rgb1', 0.12, 0.56, 1.);
//#140 = COLOUR_RGB('$$SXF_', 0.12, 0.56, 1.);
//	<name(�F���j>
	m_name.Empty();

//	<RGB�l>	
	m_R = m_G = m_B = 0;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_COLOUR_RGBC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�G���e�B�e�B�f�[�^���w�肵�Đ�������ꍇ
		(�R���X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_COLOUR_RGBC::SXFMapE_COLOUR_RGBC(
					SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	�����F	�^				������					���e
			SXFInstanceIDC* IN_InstanceIDManeger	�ݽ�ݽID�Ǘ���޼ު��

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_COLOUR_RGBC::SXFMapE_COLOUR_RGBC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
{
//#101 = COLOUR_RGB('COLOUR_RGB1', (0., 0.));

//	<������>
	m_EntityName = DEF_COLOUR_RGB;
//	<�G���e�B�e�B�f�[�^>
//  ENTITY colour_rgb
//    SUBTYPE OF (colour_specification);
//      red   : REAL;
//      green : REAL;
//      blue  : REAL;
//    WHERE
//      wr1: (0 <= red) AND (red <= 1);
//      wr2: (0 <= green) AND (green <= 1);
//      wr3: (0 <= blue) AND (blue <= 1);
//  END_ENTITY; -- colour_rgb
//#140 = COLOUR_RGB('colour_rgb1', 0.12, 0.56, 1.);
//#140 = COLOUR_RGB('$$SXF_', 0.12, 0.56, 1.);
//	<name(�F���j>
	m_name.Empty();

//	<RGB�l>	
	m_R = m_G = m_B = 0;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_COLOUR_RGBC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		(�f�X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_COLOUR_RGBC::~SXFMapE_COLOUR_RGBC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_COLOUR_RGBC::~SXFMapE_COLOUR_RGBC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_COLOUR_RGBC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�G���e�B�e�B�f�[�^�̓o�^

	�Q�D�C���^�[�t�F�C�X
		int		SXFMapE_COLOUR_RGBC::SetParameter()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/


int SXFMapE_COLOUR_RGBC::SetParameter()

{
	SXFMapEntAConvC convent(m_EntityArray);
	//<name(�F��)>
	convent.GetCString(0,m_name);

	//	<RGB�l>	
	double color;

//	m_R = m_G = m_B = 0;
	convent.GetDouble(1,m_R);
	convent.GetDouble(2,m_G);
	convent.GetDouble(3,m_B);

//      wr1: (0 <= red) AND (red <= 1);
	for( int i=0 ; i<3 ; i++ ){
		if ( i == 0 ) color = m_R;
		if ( i == 1 ) color = m_G;
		if ( i == 2 ) color = m_B;

		if ( color<0. || color>1. ){
			//COLOUR_RGB��RGB�l�ɂɈُ킪����܂��B
			SXFErrorMsgC::RecordError(
				SXFRGBERROR,		//err���b�Z�[�W�ԍ�
				m_EntityName,		//�G���e�B�e�B��
				1,					//�p�����^�̌�
				color				//�p�����^
			);
			return SXFRGBERROR;	
		}
	}

	return 0;
}
