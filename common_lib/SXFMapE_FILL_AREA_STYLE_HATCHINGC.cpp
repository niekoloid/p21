/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_FILL_AREA_STYLE_HATCHINGC.cpp						�쐬���F2000.04.17

	�P�D�N���X�T�v
		FILL_AREA_STYLE_HATCHING���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#include "stdafx.h"
#include <afxtempl.h>
#include "SXFMapEntAConvC.h"
#include "SXFMapEntityBaseC.h"
#include "SXFInstanceIDC.h"
#include "SXFMapE_FILL_AREA_STYLE_HATCHINGC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_FILL_AREA_STYLE_HATCHINGC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�f�t�H���g�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_FILL_AREA_STYLE_HATCHINGC::SXFMapE_FILL_AREA_STYLE_HATCHINGC()

	����  �F	�^			������				���e
			�Ȃ�
	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_FILL_AREA_STYLE_HATCHINGC::SXFMapE_FILL_AREA_STYLE_HATCHINGC()
{
	m_EntityName = DEF_FILL_AREA_STYLE_HATCHING;

	m_HatchLineAppeatance_Inst = 0;
	m_HatchLineAppeatance_p = NULL;

	m_StartOfNextHatchLine_Inst = 0;
	m_StartOfNextHatchLine_p = NULL;

	m_PointOfReferenceHatchLine_Inst = 0;
	m_PointOfReferenceHatchLine_p = NULL;

	m_PatternStart_Inst = 0;
	m_PatternStart_p = NULL;

	m_HatchLineAngle = 0.0;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_FILL_AREA_STYLE_HATCHINGC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�C���X�^���X�h�c�ւ̃|�C���^���w�肵�Đ�������ꍇ
		(�R���X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_FILL_AREA_STYLE_HATCHINGC::SXFMapE_FILL_AREA_STYLE_HATCHINGC(
						SXFInstanceIDC* IN_InstanceIDManeger)
        :SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	���� �F	�^				������				���e
			SXFInstanceIDC* IN_InstanceIDManeger	�ݽ�ݽID�Ǘ���޼ު��

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_FILL_AREA_STYLE_HATCHINGC::SXFMapE_FILL_AREA_STYLE_HATCHINGC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)

{
	m_EntityName = DEF_FILL_AREA_STYLE_HATCHING;

	m_HatchLineAppeatance_Inst = 0;
	m_HatchLineAppeatance_p = NULL;

	m_StartOfNextHatchLine_Inst = 0;
	m_StartOfNextHatchLine_p = NULL;

	m_PointOfReferenceHatchLine_Inst = 0;
	m_PointOfReferenceHatchLine_p = NULL;

	m_PatternStart_Inst = 0;
	m_PatternStart_p = NULL;

	m_HatchLineAngle = 0.0;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_FILL_AREA_STYLE_HATCHINGC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		(�f�X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_FILL_AREA_STYLE_HATCHINGC::~SXFMapE_FILL_AREA_STYLE_HATCHINGC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_FILL_AREA_STYLE_HATCHINGC::~SXFMapE_FILL_AREA_STYLE_HATCHINGC()
{
	if(m_HatchLineAppeatance_p != NULL)
		delete m_HatchLineAppeatance_p;
	if(m_StartOfNextHatchLine_p != NULL)
		delete m_StartOfNextHatchLine_p;
	if(m_PointOfReferenceHatchLine_p != NULL)
		delete m_PointOfReferenceHatchLine_p;
	if(m_PatternStart_p != NULL)
		delete m_PatternStart_p;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_FILL_AREA_STYLE_HATCHINGC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�G���e�B�e�B�̃p�����^�ݒ�

	�Q�D�C���^�[�t�F�C�X
		int		SXFMapE_FILL_AREA_STYLE_HATCHINGC::SetParameter()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
int SXFMapE_FILL_AREA_STYLE_HATCHINGC::SetParameter( )
{
//#2427 = FILL_AREA_STYLE_HATCHING
//('fill_area_style_hatching1', #2422, #2426, #2423, #2423, 5.497787144);

	int ircode;

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
	if ( convent.GetInst(1,m_HatchLineAppeatance_Inst ) < 0 ){
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	//�I�u�W�F�N�g����
	m_HatchLineAppeatance_p = new SXFMapE_CURVE_STYLEC(m_InstanceIDManager );

	ircode = m_HatchLineAppeatance_p->SetRootID(m_HatchLineAppeatance_Inst);
	if ( ircode < 0 )
		return ircode ;
	ircode = m_HatchLineAppeatance_p->SetParameter();
	if ( ircode < 0 )
		return ircode ;

	//�����G���[
	if ( convent.GetInst(2,m_StartOfNextHatchLine_Inst ) < 0 ){
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	//�I�u�W�F�N�g����
	m_StartOfNextHatchLine_p = 
		new SXFMapE_ONE_DIRECTION_REPEAT_FACTORC(m_InstanceIDManager );

	ircode = m_StartOfNextHatchLine_p->SetRootID(m_StartOfNextHatchLine_Inst);
	if ( ircode < 0 )
		return ircode ;
	ircode = m_StartOfNextHatchLine_p->SetParameter();
	if ( ircode < 0 )
		return ircode ;

	//�����G���[
	if ( convent.GetInst(3,m_PointOfReferenceHatchLine_Inst ) < 0 ){
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	//�I�u�W�F�N�g����
	m_PointOfReferenceHatchLine_p = 
		new SXFMapE_CARTESIAN_POINTC(m_InstanceIDManager );

	ircode = m_PointOfReferenceHatchLine_p->SetRootID(m_PointOfReferenceHatchLine_Inst);
	if ( ircode < 0 )
		return ircode ;
	ircode = m_PointOfReferenceHatchLine_p->SetParameter();
	if ( ircode < 0 )
		return ircode ;

	//�����G���[
	if ( convent.GetInst(4,m_PatternStart_Inst ) < 0 ){
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	//�I�u�W�F�N�g����
	m_PatternStart_p = 
		new SXFMapE_CARTESIAN_POINTC(m_InstanceIDManager );

	ircode = m_PatternStart_p->SetRootID(m_PatternStart_Inst);
	if ( ircode < 0 )
		return ircode ;
	ircode = m_PatternStart_p->SetParameter();
	if ( ircode < 0 )
		return ircode ;

	//�����G���[
	if ( convent.GetDouble(5,m_HatchLineAngle ) < 0 ){
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
