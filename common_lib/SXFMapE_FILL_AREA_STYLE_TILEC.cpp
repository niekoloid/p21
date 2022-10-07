/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_FILL_AREA_STYLE_TILEC.cpp						�쐬���F2000.04.17

	�P�D�N���X�T�v
		FILL_AREA_STYLE_TILE���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#include "stdafx.h"
#include <afxtempl.h>
#include "SXFMapEntAConvC.h"
#include "SXFMapEntityBaseC.h"
#include "SXFInstanceIDC.h"
#include "SXFMapE_FILL_AREA_STYLE_TILEC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_FILL_AREA_STYLE_TILEC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�f�t�H���g�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_FILL_AREA_STYLE_TILEC::SXFMapE_FILL_AREA_STYLE_TILEC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_FILL_AREA_STYLE_TILEC::SXFMapE_FILL_AREA_STYLE_TILEC()
{
	m_EntityName = "FILL_AREA_STYLE_TILE";

	m_TilingPattern_Inst = 0;
	m_TilingPattern_p = NULL;

	m_TileCount = 0; 

	m_TilingScale = 0.0;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_FILL_AREA_STYLE_TILEC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�C���X�^���X�h�c�ւ̃|�C���^���w�肵�Đ�������ꍇ
		(�R���X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_FILL_AREA_STYLE_TILEC::SXFMapE_FILL_AREA_STYLE_TILEC(
						SXFInstanceIDC* IN_InstanceIDManeger)
        :SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	����  �F	�^				������				���e
				SXFInstanceIDC* IN_InstanceIDManeger	�ݽ�ݽID�Ǘ���޼ު��

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_FILL_AREA_STYLE_TILEC::SXFMapE_FILL_AREA_STYLE_TILEC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)

{
	m_EntityName = DEF_FILL_AREA_STYLE_TILES;

	m_TilingPattern_Inst = 0;
	m_TilingPattern_p = NULL;

	m_TileCount = 0; 

	m_TilingScale = 0.0;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_FILL_AREA_STYLE_TILEC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		(�f�X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_FILL_AREA_STYLE_TILEC::~SXFMapE_FILL_AREA_STYLE_TILEC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_FILL_AREA_STYLE_TILEC::~SXFMapE_FILL_AREA_STYLE_TILEC()
{
	if(m_TilingPattern_p != NULL)
		delete m_TilingPattern_p;

	for(int i=0;i<m_TileArray_p.GetSize();i++){
		if(m_TileArray_p[i]!=NULL)
			delete m_TileArray_p[i];
	}

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_FILL_AREA_STYLE_TILEC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�G���e�B�e�B�̃p�����^�ݒ�

	�Q�D�C���^�[�t�F�C�X
		int		SXFMapE_FILL_AREA_STYLE_TILEC::SetParameter()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
int SXFMapE_FILL_AREA_STYLE_TILEC::SetParameter( )
{

//	#2679 = FILL_AREA_STYLE_TILES('fill_area_style_tiles1', #2678, (#2673), 1.);

	int ircode;

	SXFMapEntAConvC convent(m_EntityArray);

	//	1.name�p�����^
	convent.GetCString(0,m_name);

	//�����G���[
	if ( convent.GetInst(1,m_TilingPattern_Inst) < 0 ){
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	m_TilingPattern_p =
		new SXFMapE_TWO_DIRECTION_REPEAT_FACTORC(m_InstanceIDManager );

	ircode = m_TilingPattern_p->SetRootID(m_TilingPattern_Inst);
	if ( ircode < 0 )
		return ircode ;
	ircode = m_TilingPattern_p->SetParameter();
	if ( ircode < 0 )
		return ircode ;

	//�����G���[
	if ( convent.GetSetInst(2,m_TileCount,m_TileArray_Inst ) < 0 ){
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	for(int i=0;i<m_TileCount;i++){
		SXFMapE_FILL_AREA_STYLE_TILE_SYMBOL_WITH_STYLEC* tempptr = 
			new SXFMapE_FILL_AREA_STYLE_TILE_SYMBOL_WITH_STYLEC(m_InstanceIDManager );
		m_TileArray_p.Add(tempptr);

		ircode = tempptr->SetRootID(m_TileArray_Inst[i]);
		if ( ircode < 0 )
			return ircode ;
		ircode = tempptr->SetParameter();
		if ( ircode < 0 )
			return ircode ;
	}

	//�����G���[
	if ( convent.GetDouble( 3, m_TilingScale ) < 0 ){
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	return 0;
}
