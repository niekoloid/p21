/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_TEXT_STYLE_FOR_DEFINED_FONTC.cpp						�쐬���F2000.04.17

	�P�D�N���X�T�v
		TEXT_STYLE_FOR_DEFINED_FONT���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#include "stdafx.h"
#include <afxtempl.h>
#include "SXFMapEntAConvC.h"
#include "SXFMapEntityBaseC.h"
#include "SXFInstanceIDC.h"
#include "SXFMapE_TEXT_STYLE_FOR_DEFINED_FONTC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_TEXT_STYLE_FOR_DEFINED_FONTC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�f�t�H���g�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_TEXT_STYLE_FOR_DEFINED_FONTC::SXFMapE_TEXT_STYLE_FOR_DEFINED_FONTC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_TEXT_STYLE_FOR_DEFINED_FONTC::SXFMapE_TEXT_STYLE_FOR_DEFINED_FONTC()
{
	m_EntityName = DEF_TEXT_STYLE_FOR_DEFINED_FONT;

	m_Color_Inst = 0;
	//m_Color_p = NULL;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_TEXT_STYLE_FOR_DEFINED_FONTC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�C���X�^���X�h�c�ւ̃|�C���^���w�肵�Đ�������ꍇ
		(�R���X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_TEXT_STYLE_FOR_DEFINED_FONTC::SXFMapE_TEXT_STYLE_FOR_DEFINED_FONTC(
						SXFInstanceIDC* IN_InstanceIDManeger)
        :SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	���� �F	�^				������				���e
			SXFInstanceIDC* IN_InstanceIDManeger	�ݽ�ݽID�Ǘ���޼ު��

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_TEXT_STYLE_FOR_DEFINED_FONTC::SXFMapE_TEXT_STYLE_FOR_DEFINED_FONTC(
	SXFInstanceIDC* IN_InstanceIDManeger)
	:SXFMapEntityBaseC(IN_InstanceIDManeger)

{
	m_EntityName = DEF_TEXT_STYLE_FOR_DEFINED_FONT;

	m_Color_Inst = 0;
	//m_Color_p = NULL;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_TEXT_STYLE_FOR_DEFINED_FONTC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		(�f�X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_TEXT_STYLE_FOR_DEFINED_FONTC::~SXFMapE_TEXT_STYLE_FOR_DEFINED_FONTC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_TEXT_STYLE_FOR_DEFINED_FONTC::~SXFMapE_TEXT_STYLE_FOR_DEFINED_FONTC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_TEXT_STYLE_FOR_DEFINED_FONTC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�G���e�B�e�B�̃p�����^�ݒ�

	�Q�D�C���^�[�t�F�C�X
		int		SXFMapE_TEXT_STYLE_FOR_DEFINED_FONTC::SetParameter()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
int SXFMapE_TEXT_STYLE_FOR_DEFINED_FONTC::SetParameter( )
{

	SXFMapEntAConvC convent(m_EntityArray);

	//�����G���[
	if ( convent.GetInst(0,m_Color_Inst ) < 0 ){
		SXFErrorMsgC::RecordError( SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	return 0;
}
