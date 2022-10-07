/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_PLANAR_BOXC.cpp						�쐬���F2000.04.17

	�P�D�N���X�T�v
		PLANAR_BOX���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#include "stdafx.h"
#include <afxtempl.h>
#include "SXFMapEntAConvC.h"
#include "SXFMapEntityBaseC.h"
#include "SXFInstanceIDC.h"
#include "SXFMapE_PLANAR_BOXC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_PLANAR_BOXC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�f�t�H���g�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_PLANAR_BOXC::SXFMapE_PLANAR_BOXC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_PLANAR_BOXC::SXFMapE_PLANAR_BOXC()
{
	m_EntityName = DEF_PLANAR_BOX;

	m_Size_x = 0.0;
	m_Size_y = 0.0;

	m_Placement_Inst = 0;
	m_Placement_p = NULL;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_PLANAR_BOXC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�C���X�^���X�h�c�ւ̃|�C���^���w�肵�Đ�������ꍇ
		(�R���X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_PLANAR_BOXC::SXFMapE_PLANAR_BOXC(
						SXFInstanceIDC* IN_InstanceIDManeger)
        :SXFMapEntityBaseC(IN_InstanceIDManeger)

					

	���� �F	�^				������				���e
			SXFInstanceIDC* IN_InstanceIDManeger	�ݽ�ݽID�Ǘ���޼ު��

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_PLANAR_BOXC::SXFMapE_PLANAR_BOXC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)

{
	m_EntityName = DEF_PLANAR_BOX;

	m_Size_x = 0.0;
	m_Size_y = 0.0;

	m_Placement_Inst = 0;
	m_Placement_p = NULL;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_PLANAR_BOXC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		(�f�X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_PLANAR_BOXC::~SXFMapE_PLANAR_BOXC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_PLANAR_BOXC::~SXFMapE_PLANAR_BOXC()
{

	if(m_Placement_p !=NULL)
		delete m_Placement_p;

}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_PLANAR_BOXC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�G���e�B�e�B�̃p�����^�ݒ�

	�Q�D�C���^�[�t�F�C�X
		int		SXFMapE_PLANAR_BOXC::SetParameter()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
int SXFMapE_PLANAR_BOXC::SetParameter( )
{

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
	if ( convent.GetDouble(1,m_Size_x ) < 0 ){
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	//�����G���[
	if ( convent.GetDouble(2,m_Size_y ) < 0 ){
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	//�����G���[
	if ( convent.GetInst(3,m_Placement_Inst ) < 0 ){
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	m_Placement_p = 
		new SXFMapE_AXIS2_PLACEMENT_2DC(m_InstanceIDManager );

	ircode = m_Placement_p->SetRootID(m_Placement_Inst);
	if ( ircode < 0 )
		return ircode ;
	ircode = m_Placement_p->SetParameter();
	if ( ircode < 0 )
		return ircode ;

	return 0;
}
