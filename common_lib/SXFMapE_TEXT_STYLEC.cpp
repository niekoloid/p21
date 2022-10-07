/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_TEXT_STYLEC.cpp						�쐬���F2000.04.17

	�P�D�N���X�T�v
		SYMBOL_STYLE���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#include "stdafx.h"
#include "SXFMapE_TEXT_STYLEC.h"
#include "SXFMapE_TEXT_STYLE_FOR_DEFINED_FONTC.h"

#include "SXFMapEntCConvC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_TEXT_STYLEC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�f�t�H���g�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_TEXT_STYLEC::SXFMapE_TEXT_STYLEC()

	����  �F	�^			������				���e
			�Ȃ�
	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_TEXT_STYLEC::SXFMapE_TEXT_STYLEC()
{
//	<������>
	m_EntityName = DEF_SXF_COMPLEX_INSTANCE;
//<�G���e�B�e�B�f�[�^>

//#253 = TEXT_STYLE_FOR_DEFINED_FONT(#40);
//#254 = (
//  TEXT_STYLE('text_style1', #253)
//  TEXT_STYLE_WITH_BOX_CHARACTERISTICS((
//		BOX_HEIGHT(1.), 
//		BOX_WIDTH(1.), 
//		BOX_SLANT_ANGLE(0.), 
//		BOX_ROTATE_ANGLE(0.)))
//  TEXT_STYLE_WITH_SPACING(LENGTH_MEASURE(0.2)));

	//	1.name�p�����^
	m_name.Empty();

	//	2.symbol_colour �ւ̃C���X�^���XID
	m_text_appe_Inst = 0;

	//	symbol_colour�ւ̃|�C���^
	m_text_appe_P =NULL;

//	<��������>
	m_height=0.;
//	<������>
	m_width=0.;
//	<�X�����g�p�x radian>
	m_slant_angle=0.;
//	<������p�x radian>
	m_rotate_angle=0.;
//	<�����Ԋu>
	m_spacing=0.;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_TEXT_STYLEC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�C���X�^���X�h�c�ւ̃|�C���^���w�肵�Đ�������ꍇ
		(�R���X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_TEXT_STYLEC::SXFMapE_TEXT_STYLEC(
						SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	����  �F	�^				������				���e
				SXFInstanceIDC* IN_InstanceIDManeger	�ݽ�ݽID�Ǘ���޼ު��

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_TEXT_STYLEC::SXFMapE_TEXT_STYLEC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
{
//	<������>
	m_EntityName = DEF_SYMBOL_STYLE;
//<�G���e�B�e�B�f�[�^>

//#253 = TEXT_STYLE_FOR_DEFINED_FONT(#40);
//#254 = (
//  TEXT_STYLE('text_style1', #253)
//  TEXT_STYLE_WITH_BOX_CHARACTERISTICS((
//		BOX_HEIGHT(1.), 
//		BOX_WIDTH(1.), 
//		BOX_SLANT_ANGLE(0.), 
//		BOX_ROTATE_ANGLE(0.)))
//  TEXT_STYLE_WITH_SPACING(LENGTH_MEASURE(0.2)));

	//	1.name�p�����^
	m_name.Empty();

	//	2.symbol_colour �ւ̃C���X�^���XID
	m_text_appe_Inst = 0;

	//	symbol_colour�ւ̃|�C���^
	m_text_appe_P =NULL;

	//	<��������>
	m_height=0.;
	//	<������>
	m_width=0.;
	//	<�X�����g�p�x radian>
	m_slant_angle=0.;
	//	<������p�x radian>
	m_rotate_angle=0.;
	//	<�����Ԋu>
	m_spacing=0.;
}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_TEXT_STYLEC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		(�f�X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_TEXT_STYLEC::~SXFMapE_TEXT_STYLEC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_TEXT_STYLEC::~SXFMapE_TEXT_STYLEC()
{
	if(m_text_appe_P != NULL)
	{
		delete m_text_appe_P;
	}
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_TEXT_STYLEC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�G���e�B�e�B�̃p�����^�ݒ�

	�Q�D�C���^�[�t�F�C�X
		int		SXFMapE_TEXT_STYLEC::SetParameter()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
int SXFMapE_TEXT_STYLEC::SetParameter()

{
//	<1. �G���e�B�e�B�p�����^�̐ݒ�>

	int ircode=0;
//<�G���e�B�e�B�f�[�^>

//#253 = TEXT_STYLE_FOR_DEFINED_FONT(#40);
//#254 = (
//  TEXT_STYLE('text_style1', #253)
//  TEXT_STYLE_WITH_BOX_CHARACTERISTICS((
//		BOX_HEIGHT(1.), 
//		BOX_WIDTH(1.), 
//		BOX_SLANT_ANGLE(0.), 
//		BOX_ROTATE_ANGLE(0.)))
//  TEXT_STYLE_WITH_SPACING(LENGTH_MEASURE(0.2)));

	SXFMapEntCConvC convert(m_EntityArray);

	//	TEXT_STYLE �̂��p�����^�����o��
	convert.SplitComplex(DEF_TEXT_STYLE);
	//	1.name�p�����^
	convert.GetCString(0,m_name);

	//	2.text_style_for_defined_font �ւ̃C���X�^���XID
	convert.GetInst(1,m_text_appe_Inst);

	//	�Q�Ɛ��text_style_for_defined_font�쐬

	//�G���e�B�e�B�C���X�^���X���쐬
//	SXFMapE_TEXT_STYLE_FOR_DEFINED_FONTC m_text_appe_P(m_InstanceIDManager);
	m_text_appe_P = new SXFMapE_TEXT_STYLE_FOR_DEFINED_FONTC(m_InstanceIDManager);
	ircode = m_text_appe_P->SetRootID(m_text_appe_Inst);
	if ( ircode < 0 )	return ircode ;
	//�G���e�B�e�B�p�����^�̐ݒ�
	ircode = m_text_appe_P->SetParameter();
	if ( ircode < 0 )	return ircode ;

	//	TEXT_STYLE_WITH_BOX_CHARACTERISTICS �̂��p�����^�����o��
	convert.SplitComplex(DEF_TEXT_STYLE_WITH_BOX_CHARACTERISTICS);

	CArray<double,double> OUT_array;
	int OUT_Num;

	//	SELECT�^�̒l�����o��
	//	<��������>
	convert.GetSetSelectDouble(0,DEF_BOX_HEIGHT,OUT_Num,OUT_array);
	m_height	=	OUT_array[0];
	//	<������>
	convert.GetSetSelectDouble(0,DEF_BOX_WIDTH,OUT_Num,OUT_array);
	m_width			=	OUT_array[0];
	//	<�X�����g�p�x radian>
	convert.GetSetSelectDouble(0,DEF_BOX_SLANT_ANGLE,OUT_Num,OUT_array);
	m_slant_angle	=	OUT_array[0];
	//	<������p�x radian>
	convert.GetSetSelectDouble(0,DEF_BOX_ROTATE_ANGLE,OUT_Num,OUT_array);
	m_rotate_angle	=	OUT_array[0];

	//	TEXT_STYLE_WITH_SPACING �̂��p�����^�����o��
	convert.SplitComplex(DEF_TEXT_STYLE_WITH_SPACING);
	//	SELECT�^�̒l�����o��
	//	<�����Ԋu��>
	convert.GetSelectDouble(0,DEF_LENGTH_MEASURE,m_spacing);

	return 0;
}
