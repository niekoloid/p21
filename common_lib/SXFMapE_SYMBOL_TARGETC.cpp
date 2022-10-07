/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_SYMBOL_TARGETC.cpp						�쐬���F2000.04.17

	�P�D�N���X�T�v
		SYMBOL_TARGET���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#include "stdafx.h"
#include <afxtempl.h>
#include "SXFMapEntAConvC.h"
#include "SXFMapEntityBaseC.h"
#include "SXFInstanceIDC.h"
#include "SXFMapE_SYMBOL_TARGETC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_SYMBOL_TARGETC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�f�t�H���g�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_SYMBOL_TARGETC::SXFMapE_SYMBOL_TARGETC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_SYMBOL_TARGETC::SXFMapE_SYMBOL_TARGETC()
{
	m_EntityName = DEF_SYMBOL_TARGET;

	m_Placement_Inst = 0;
	m_Placement_p = NULL;
	m_Scale_x = 0.0;
	m_Scale_y = 0.0;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_SYMBOL_TARGETC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�C���X�^���X�h�c�ւ̃|�C���^���w�肵�Đ�������ꍇ
		(�R���X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_SYMBOL_TARGETC::SXFMapE_SYMBOL_TARGETC(
						SXFInstanceIDC* IN_InstanceIDManeger)
        :SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	����  �F	�^				������				���e
				SXFInstanceIDC* IN_InstanceIDManeger	�ݽ�ݽID�Ǘ���޼ު��

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_SYMBOL_TARGETC::SXFMapE_SYMBOL_TARGETC(
	SXFInstanceIDC* IN_InstanceIDManeger)
	:SXFMapEntityBaseC(IN_InstanceIDManeger)

{
	m_EntityName = DEF_SYMBOL_TARGET;

	m_Placement_Inst = 0;
	m_Placement_p = NULL;
	m_Scale_x = 0.0;
	m_Scale_y = 0.0;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_SYMBOL_TARGETC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		(�f�X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_SYMBOL_TARGETC::~SXFMapE_SYMBOL_TARGETC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_SYMBOL_TARGETC::~SXFMapE_SYMBOL_TARGETC()
{

	if(m_Placement_p !=NULL)
		delete m_Placement_p;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_SYMBOL_TARGETC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�G���e�B�e�B�̃p�����^�ݒ�

	�Q�D�C���^�[�t�F�C�X
		int		SXFMapE_SYMBOL_TARGETC::SetParameter()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
int SXFMapE_SYMBOL_TARGETC::SetParameter( )
{

	int ircode;

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
	if ( convent.GetInst(1,m_Placement_Inst ) < 0 ){
		SXFErrorMsgC::RecordError( SXFPARAMS,
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

	//�����G���[
	if ( convent.GetDouble(2,m_Scale_x ) < 0 ){
		SXFErrorMsgC::RecordError( SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	//�����G���[
	if ( convent.GetDouble(3,m_Scale_y ) < 0 ){
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
