/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_TEXT_LITERAL_WITH_EXTENTC.cpp						�쐬���F2000.04.17

	�P�D�N���X�T�v
		TEXT_LITERAL_WITH_EXTENT���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#include "stdafx.h"
#include <afxtempl.h>
#include "SXFMapEntAConvC.h"
#include "SXFMapEntityBaseC.h"
#include "SXFInstanceIDC.h"
#include "SXFMapE_TEXT_LITERAL_WITH_EXTENTC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_TEXT_LITERAL_WITH_EXTENTC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�f�t�H���g�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_TEXT_LITERAL_WITH_EXTENTC::SXFMapE_TEXT_LITERAL_WITH_EXTENTC()

	����  �F	�^			������				���e
			�Ȃ�
	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_TEXT_LITERAL_WITH_EXTENTC::SXFMapE_TEXT_LITERAL_WITH_EXTENTC()
{
	m_EntityName = DEF_TEXT_LITERAL_WITH_EXTENT;

	m_Placement_Inst = 0;
	m_Placement_p = NULL;
	m_Font_Inst = 0;
	//m_Font_p = NULL;
	m_PlanarExtent_Inst = 0;
	m_PlanarExtent_p = NULL;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_TEXT_LITERAL_WITH_EXTENTC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�C���X�^���X�h�c�ւ̃|�C���^���w�肵�Đ�������ꍇ
		(�R���X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_TEXT_LITERAL_WITH_EXTENTC::SXFMapE_TEXT_LITERAL_WITH_EXTENTC(
						SXFInstanceIDC* IN_InstanceIDManeger)
        :SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	����  �F	�^				������				���e
				SXFInstanceIDC* IN_InstanceIDManeger		�ݽ�ݽID�Ǘ���޼ު��

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_TEXT_LITERAL_WITH_EXTENTC::SXFMapE_TEXT_LITERAL_WITH_EXTENTC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)

{
	m_EntityName = DEF_TEXT_LITERAL_WITH_EXTENT;

	m_Placement_Inst = 0;
	m_Placement_p = NULL;
	m_Font_Inst = 0;
	//m_Font_p = NULL;
	m_PlanarExtent_Inst = 0;
	m_PlanarExtent_p = NULL;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_TEXT_LITERAL_WITH_EXTENTC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		(�f�X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_TEXT_LITERAL_WITH_EXTENTC::~SXFMapE_TEXT_LITERAL_WITH_EXTENTC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_TEXT_LITERAL_WITH_EXTENTC::~SXFMapE_TEXT_LITERAL_WITH_EXTENTC()
{
	if(m_Placement_p != NULL)
		delete m_Placement_p;
	if(m_PlanarExtent_p != NULL)
		delete m_PlanarExtent_p;
}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_TEXT_LITERAL_WITH_EXTENTC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�G���e�B�e�B�̃p�����^�ݒ�

	�Q�D�C���^�[�t�F�C�X
		int		SXFMapE_TEXT_LITERAL_WITH_EXTENTC::SetParameter()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
int SXFMapE_TEXT_LITERAL_WITH_EXTENTC::SetParameter( )
{

	int ircode;

//	Text Literal�̒��� ', '�������Ă���ƁA
//	EntityData�͂����ŕ��������B
//	=>  EntityData�̌�납��f�[�^�����B
//#485 = TEXT_LITERAL_WITH_EXTENT(
//	'$$SXF_baseline centre', 
//	'Part21 \X2\30EC30D930EB\X0\1',
// #484, 'baseline centre', .RIGHT., #180, #481);

	INT_PTR size;
	size = m_EntityArray->GetSize();
	//�����G���[
	if ( size <7 ) {
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	SXFMapEntAConvC convent(m_EntityArray);
	//�����G���[
	if ( convent.GetCString(0,m_Name) < 0 ){
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	//�����G���[
	if ( convent.GetCString(1,m_Literal ) < 0 ){
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	//�����G���[
	if ( convent.GetInst((int)(size-5),m_Placement_Inst ) < 0 ){
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	m_Placement_p = new SXFMapE_AXIS2_PLACEMENT_2DC(m_InstanceIDManager);

	ircode = m_Placement_p->SetRootID(m_Placement_Inst);
	if ( ircode < 0 )
		return ircode ;
	ircode = m_Placement_p->SetParameter();
	if ( ircode < 0 )
		return ircode ;

	//�����G���[
	if ( convent.GetCString((int)(size - 4) ,m_Alignment ) < 0 ){
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	//�����G���[
	if ( convent.GetCString((int)(size-3),m_Path ) < 0 ){
		SXFErrorMsgC::RecordError( SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	//�����G���[
	if ( convent.GetInst((int)(size-2),m_Font_Inst ) < 0 ){
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	//�����G���[
	if ( convent.GetInst((int)(size-1),m_PlanarExtent_Inst ) < 0 ){
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	m_PlanarExtent_p = new SXFMapE_PLANAR_EXTENTC(m_InstanceIDManager);

	ircode = m_PlanarExtent_p->SetRootID(m_PlanarExtent_Inst);
	if ( ircode < 0 )
		return ircode ;
	ircode = m_PlanarExtent_p->SetParameter();
	if ( ircode < 0 )
		return ircode ;

	return 0;
}
