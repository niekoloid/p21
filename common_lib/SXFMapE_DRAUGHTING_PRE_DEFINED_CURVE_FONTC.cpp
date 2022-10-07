/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_DRAUGHTING_PRE_DEFINED_CURVE_FONTC.cpp						�쐬���F2000.04.17

	�P�D�N���X�T�v
		DRAUGHTING_PRE_DEFINED_CURVE_FONT���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#include "stdafx.h"
#include "SXFMapE_DRAUGHTING_PRE_DEFINED_CURVE_FONTC.h"
#include "SXFMapEntAConvC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_DRAUGHTING_PRE_DEFINED_CURVE_FONTC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�f�t�H���g�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_DRAUGHTING_PRE_DEFINED_CURVE_FONTC::SXFMapE_DRAUGHTING_PRE_DEFINED_CURVE_FONTC()

	����  �F	�^			������				���e
			�Ȃ�
	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_DRAUGHTING_PRE_DEFINED_CURVE_FONTC::SXFMapE_DRAUGHTING_PRE_DEFINED_CURVE_FONTC()
{
//	<������>
	m_EntityName = DEF_DRAUGHTING_PRE_DEFINED_CURVE_FONT;

//<�G���e�B�e�B�f�[�^>
//#20 = DRAUGHTING_PRE_DEFINED_CURVE_FONT('continuous');
	//name�p�����^
	m_name.Empty();	
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_DRAUGHTING_PRE_DEFINED_CURVE_FONTC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�C���X�^���X�h�c�ւ̃|�C���^���w�肵�Đ�������ꍇ
		(�R���X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_DRAUGHTING_PRE_DEFINED_CURVE_FONTC::SXFMapE_DRAUGHTING_PRE_DEFINED_CURVE_FONTC(
						SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	���� �F	�^				������				���e
			SXFInstanceIDC* IN_InstanceIDManeger	�ݽ�ݽID�Ǘ���޼ު��

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_DRAUGHTING_PRE_DEFINED_CURVE_FONTC::SXFMapE_DRAUGHTING_PRE_DEFINED_CURVE_FONTC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
{
//	<������>
	m_EntityName = DEF_DRAUGHTING_PRE_DEFINED_CURVE_FONT;

//<�G���e�B�e�B�f�[�^>
//#20 = DRAUGHTING_PRE_DEFINED_CURVE_FONT('continuous');
	//name�p�����^
	m_name.Empty();	

}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_DRAUGHTING_PRE_DEFINED_CURVE_FONTC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		(�f�X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_DRAUGHTING_PRE_DEFINED_CURVE_FONTC::~SXFMapE_DRAUGHTING_PRE_DEFINED_CURVE_FONTC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_DRAUGHTING_PRE_DEFINED_CURVE_FONTC::~SXFMapE_DRAUGHTING_PRE_DEFINED_CURVE_FONTC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_DRAUGHTING_PRE_DEFINED_CURVE_FONTC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�G���e�B�e�B�̃p�����^�ݒ�

	�Q�D�C���^�[�t�F�C�X
		int		SXFMapE_DRAUGHTING_PRE_DEFINED_CURVE_FONTC::SetParameter()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
int SXFMapE_DRAUGHTING_PRE_DEFINED_CURVE_FONTC::SetParameter()

{
//	<1. �G���e�B�e�B�p�����^�̐ݒ�>
//<�G���e�B�e�B�f�[�^>
//#20 = DRAUGHTING_PRE_DEFINED_CURVE_FONT('continuous');

	SXFMapEntAConvC convent(m_EntityArray);
	//<name>
	if ( convent.GetCString(0,m_name) < 0 ) {
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

	return 0;
}
