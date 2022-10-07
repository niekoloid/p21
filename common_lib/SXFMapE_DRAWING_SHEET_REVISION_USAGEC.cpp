/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_DRAWING_SHEET_REVISION_USAGEC.cpp						�쐬���F2000.04.17

	�P�D�N���X�T�v
		DRAWING_SHEET_REVISION_USAGE���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#include "stdafx.h"
#include <afxtempl.h>
#include "SXFMapEntAConvC.h"
#include "SXFMapEntityBaseC.h"
#include "SXFInstanceIDC.h"
#include "SXFMapE_DRAWING_SHEET_REVISION_USAGEC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_DRAWING_SHEET_REVISION_USAGEC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�f�t�H���g�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_DRAWING_SHEET_REVISION_USAGEC::SXFMapE_DRAWING_SHEET_REVISION_USAGEC()

	����  �F	�^			������				���e
			�Ȃ�
	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_DRAWING_SHEET_REVISION_USAGEC::SXFMapE_DRAWING_SHEET_REVISION_USAGEC()
{
	m_EntityName = DEF_DRAWING_SHEET_REVISION_USAGE;

	m_Area_Inst = 0;
	m_Area_p = NULL;

	m_InSet_Inst = 0;
	m_InSet_p = NULL;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_DRAWING_DEFINITIONC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�C���X�^���X�h�c�ւ̃|�C���^���w�肵�Đ�������ꍇ
		(�R���X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_DRAWING_SHEET_REVISION_USAGEC::SXFMapE_DRAWING_SHEET_REVISION_USAGEC(
						SXFInstanceIDC* IN_InstanceIDManeger)
        :SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	���� �F	�^				������				���e
			SXFInstanceIDC* IN_InstanceIDManeger	�ݽ�ݽID�Ǘ���޼ު��

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_DRAWING_SHEET_REVISION_USAGEC::SXFMapE_DRAWING_SHEET_REVISION_USAGEC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)

{
	m_EntityName = DEF_DRAWING_SHEET_REVISION_USAGE;

	m_Area_Inst = 0;
	m_Area_p = NULL;

	m_InSet_Inst = 0;
	m_InSet_p = NULL; 
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_DRAWING_SHEET_REVISION_USAGEC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		(�f�X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_DRAWING_SHEET_REVISION_USAGEC::~SXFMapE_DRAWING_SHEET_REVISION_USAGEC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_DRAWING_SHEET_REVISION_USAGEC::~SXFMapE_DRAWING_SHEET_REVISION_USAGEC()
{

	if(m_Area_p !=NULL)
		delete m_Area_p;

	if(m_InSet_p !=NULL)
		delete m_InSet_p;

}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_DRAWING_SHEET_REVISION_USAGEC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�G���e�B�e�B�̃p�����^�ݒ�

	�Q�D�C���^�[�t�F�C�X
		int		SXFMapE_DRAWING_SHEET_REVISION_USAGEC::SetParameter()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
int SXFMapE_DRAWING_SHEET_REVISION_USAGEC::SetParameter( )
{

	int ircode;

	SXFMapEntAConvC convent(m_EntityArray);

	//�����G���[
	if ( convent.GetInst(0,m_Area_Inst) < 0 ){
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	//�I�u�W�F�N�g����
	m_Area_p = 
		new SXFMapE_DRAWING_SHEET_REVISIONC(m_InstanceIDManager );

	ircode = m_Area_p->SetRootID(m_Area_Inst);
	if ( ircode < 0 )
		return ircode ;
	ircode = m_Area_p->SetParameter();
	if ( ircode < 0 )
		return ircode ;

	//�����G���[
	if ( convent.GetInst(1,m_InSet_Inst ) < 0 ){
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	//�I�u�W�F�N�g����
	m_InSet_p = 
		new SXFMapE_DRAUGHTING_DRAWING_REVISIONC(m_InstanceIDManager );

	ircode = m_InSet_p->SetRootID(m_InSet_Inst);
	if ( ircode < 0 )
		return ircode ;
	ircode = m_InSet_p->SetParameter();
	if ( ircode < 0 )
		return ircode ;

	//�����G���[
	if ( convent.GetCString(2,m_SheetNumber ) < 0 ){
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
