/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_DRAUGHTING_DRAWING_REVISIONC.cpp						�쐬���F2000.04.17

	�P�D�N���X�T�v
		DRAUGHTING_DRAWING_REVISION���Ǘ�����

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#include "stdafx.h"
#include <afxtempl.h>
#include "SXFMapEntAConvC.h"
#include "SXFMapEntityBaseC.h"
#include "SXFInstanceIDC.h"
#include "SXFMapE_DRAUGHTING_DRAWING_REVISIONC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_DRAUGHTING_DRAWING_REVISIONC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�f�t�H���g�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_DRAUGHTING_DRAWING_REVISIONC::SXFMapE_DRAUGHTING_DRAWING_REVISIONC()

	����  �F	�^			������				���e
			�Ȃ�
	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_DRAUGHTING_DRAWING_REVISIONC::SXFMapE_DRAUGHTING_DRAWING_REVISIONC()
{
	m_EntityName = DEF_DRAUGHTING_DRAWING_REVISION;

	m_DrawingIdentifier_Inst = 0;
	m_DrawingIdentifier_p = NULL;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_DRAUGHTING_DRAWING_REVISIONC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�G���e�B�e�B�f�[�^���w�肵�Đ�������ꍇ
		(�R���X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_DRAUGHTING_DRAWING_REVISIONC::SXFMapE_DRAUGHTING_DRAWING_REVISIONC(
						SXFInstanceIDC* IN_InstanceIDManeger)
        :SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	�����F	�^				������				���e
			SXFInstanceIDC* IN_InstanceIDManeger	�ݽ�ݽID�Ǘ���޼ު��

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_DRAUGHTING_DRAWING_REVISIONC::SXFMapE_DRAUGHTING_DRAWING_REVISIONC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)

{
	m_EntityName = DEF_DRAUGHTING_DRAWING_REVISION;

	m_DrawingIdentifier_Inst = 0;
	m_DrawingIdentifier_p = NULL;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_DRAUGHTING_DRAWING_REVISIONC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		(�f�X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_DRAUGHTING_DRAWING_REVISIONC::~SXFMapE_DRAUGHTING_DRAWING_REVISIONC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_DRAUGHTING_DRAWING_REVISIONC::~SXFMapE_DRAUGHTING_DRAWING_REVISIONC()
{

	if(m_DrawingIdentifier_p !=NULL)
		delete m_DrawingIdentifier_p;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_DRAUGHTING_DRAWING_REVISIONC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�G���e�B�e�B�f�[�^�̓o�^

	�Q�D�C���^�[�t�F�C�X
		int		SXFMapE_DRAUGHTING_DRAWING_REVISIONC::SetParameter()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
int SXFMapE_DRAUGHTING_DRAWING_REVISIONC::SetParameter( )
{

	int ircode;

	SXFMapEntAConvC convent(m_EntityArray);

	//�����G���[
	if ( convent.GetCString(0,m_RevisionIdentifier) < 0 ){
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	//�����G���[
	if ( convent.GetInst(1,m_DrawingIdentifier_Inst ) < 0 ){
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	//�I�u�W�F�N�g����
	m_DrawingIdentifier_p =
		new SXFMapE_DRAWING_DEFINITIONC(m_InstanceIDManager );

	ircode = m_DrawingIdentifier_p->SetRootID(m_DrawingIdentifier_Inst);
	if ( ircode < 0 )
		return ircode ;
	ircode = m_DrawingIdentifier_p->SetParameter();
	if ( ircode < 0 )
		return ircode ;

	//�����G���[
	if ( convent.GetCString(2,m_IntendedScale ) < 0 ){
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
