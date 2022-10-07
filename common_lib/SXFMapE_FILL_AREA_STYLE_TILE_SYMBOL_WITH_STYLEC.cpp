/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_FILL_AREA_STYLE_TILE_SYMBOL_WITH_STYLEC.cpp						�쐬���F2000.04.17

	�P�D�N���X�T�v
		FILL_AREA_STYLE_TILE_SYMBOL_WITH_STYLE���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#include "stdafx.h"
#include <afxtempl.h>
#include "SXFMapEntAConvC.h"
#include "SXFMapEntityBaseC.h"
#include "SXFInstanceIDC.h"
#include "SXFMapE_FILL_AREA_STYLE_TILE_SYMBOL_WITH_STYLEC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_FILL_AREA_STYLE_TILE_SYMBOL_WITH_STYLEC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�f�t�H���g�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_FILL_AREA_STYLE_TILE_SYMBOL_WITH_STYLEC::SXFMapE_FILL_AREA_STYLE_TILE_SYMBOL_WITH_STYLEC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_FILL_AREA_STYLE_TILE_SYMBOL_WITH_STYLEC::SXFMapE_FILL_AREA_STYLE_TILE_SYMBOL_WITH_STYLEC()
{
	m_EntityName = DEF_FILL_AREA_STYLE_TILE_SYMBOL_WITH_STYLE;

	m_Symbol_Inst = 0;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_FILL_AREA_STYLE_TILE_SYMBOL_WITH_STYLEC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�C���X�^���X�h�c�ւ̃|�C���^���w�肵�Đ�������ꍇ
		(�R���X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_FILL_AREA_STYLE_TILE_SYMBOL_WITH_STYLEC::SXFMapE_FILL_AREA_STYLE_TILE_SYMBOL_WITH_STYLEC(
						SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	����  �F	�^				������				���e
				SXFInstanceIDC* IN_InstanceIDManeger	�ݽ�ݽID�Ǘ���޼ު��

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_FILL_AREA_STYLE_TILE_SYMBOL_WITH_STYLEC::SXFMapE_FILL_AREA_STYLE_TILE_SYMBOL_WITH_STYLEC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)

{
	m_EntityName = DEF_FILL_AREA_STYLE_TILE_SYMBOL_WITH_STYLE;

	m_Symbol_Inst = 0;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_FILL_AREA_STYLE_TILE_SYMBOL_WITH_STYLEC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		(�f�X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_FILL_AREA_STYLE_TILE_SYMBOL_WITH_STYLEC::~SXFMapE_FILL_AREA_STYLE_TILE_SYMBOL_WITH_STYLEC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_FILL_AREA_STYLE_TILE_SYMBOL_WITH_STYLEC::~SXFMapE_FILL_AREA_STYLE_TILE_SYMBOL_WITH_STYLEC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_FILL_AREA_STYLE_TILE_SYMBOL_WITH_STYLEC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�G���e�B�e�B�̃p�����^�ݒ�

	�Q�D�C���^�[�t�F�C�X
		int		SXFMapE_FILL_AREA_STYLE_TILE_SYMBOL_WITH_STYLEC::SetParameter()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
int SXFMapE_FILL_AREA_STYLE_TILE_SYMBOL_WITH_STYLEC::SetParameter( )
{

	SXFMapEntAConvC convent(m_EntityArray);

	//�����G���[
	if ( convent.GetCString(0,m_Name) < 0 ){
		SXFErrorMsgC::RecordError( SXFPARAMS,
								m_EntityName,
								2,
								m_RootID,
								m_EntityName
								);
		return SXFPARAMS;
	}

	//�����G���[
	if ( convent.GetInst(1,m_Symbol_Inst ) < 0 ){
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
