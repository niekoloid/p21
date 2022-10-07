/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_PRESENTATION_SIZEC.cpp						�쐬���F2000.04.17

	�P�D�N���X�T�v
		PRESENTATION_SIZE���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#include "stdafx.h"
#include <afxtempl.h>
#include "SXFMapEntAConvC.h"
#include "SXFMapEntityBaseC.h"
#include "SXFInstanceIDC.h"
#include "SXFMapE_PRESENTATION_SIZEC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_PRESENTATION_SIZEC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�f�t�H���g�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_PRESENTATION_SIZEC::SXFMapE_PRESENTATION_SIZEC()

	����  �F	�^			������				���e
			�Ȃ�
	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_PRESENTATION_SIZEC::SXFMapE_PRESENTATION_SIZEC()
{
	m_EntityName = DEF_PRESENTATION_SIZE;

	m_Unit_Inst = 0;
	m_Unit_p = NULL;
	m_Size_Inst = 0;
	m_Size_p = NULL;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_PRESENTATION_SIZEC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�C���X�^���X�h�c�ւ̃|�C���^���w�肵�Đ�������ꍇ
		(�R���X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_PRESENTATION_SIZEC::SXFMapE_PRESENTATION_SIZEC(
						SXFInstanceIDC* IN_InstanceIDManeger)
        :SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	���� �F	�^				������				���e
			SXFInstanceIDC* IN_InstanceIDManeger	�ݽ�ݽID�Ǘ���޼ު��

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_PRESENTATION_SIZEC::SXFMapE_PRESENTATION_SIZEC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)

{
	m_EntityName = DEF_PRESENTATION_SIZE;

	m_Unit_Inst = 0;
	m_Unit_p = NULL;
	m_Size_Inst = 0;
	m_Size_p = NULL;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_PRESENTATION_SIZEC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		(�f�X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_PRESENTATION_SIZEC::~SXFMapE_PRESENTATION_SIZEC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_PRESENTATION_SIZEC::~SXFMapE_PRESENTATION_SIZEC()
{

	if(m_Unit_p !=NULL)
		delete m_Unit_p;

	if(m_Size_p != NULL)
		delete m_Size_p;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_PRESENTATION_SIZEC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�G���e�B�e�B�̃p�����^�ݒ�

	�Q�D�C���^�[�t�F�C�X
		int		SXFMapE_PRESENTATION_SIZEC::SetParameter()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
int SXFMapE_PRESENTATION_SIZEC::SetParameter( )
{

	int ircode;

	SXFMapEntAConvC convent(m_EntityArray);

	//�����G���[
	if ( convent.GetInst(0,m_Unit_Inst) < 0 ){
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	m_Unit_p = 
		new SXFMapE_DRAWING_SHEET_REVISIONC(m_InstanceIDManager );

	ircode = m_Unit_p->SetRootID(m_Unit_Inst);
	if ( ircode < 0 )
		return ircode ;
	ircode = m_Unit_p->SetParameter();
	if ( ircode < 0 )
		return ircode ;

	//�����G���[
	if ( convent.GetInst(1,m_Size_Inst ) < 0 ){
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	m_Size_p = 
		new SXFMapE_PLANAR_BOXC(m_InstanceIDManager );

	ircode = m_Size_p->SetRootID(m_Size_Inst);
	if ( ircode < 0 )
		return ircode ;
	ircode = m_Size_p->SetParameter();
	if ( ircode < 0 )
		return ircode ;

	return 0;
}
