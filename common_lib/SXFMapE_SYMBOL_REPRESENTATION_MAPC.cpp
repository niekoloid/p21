/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_SYMBOL_REPRESENTATION_MAPC.cpp						�쐬���F2000.04.17

	�P�D�N���X�T�v
		SYMBOL_REPRESENTATION_MAP���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#include "stdafx.h"
#include "SXFMapE_SYMBOL_REPRESENTATION_MAPC.h"
#include "SXFMapE_AXIS2_PLACEMENT_2DC.h"
#include "SXFMapE_DRAUGHTING_SUBFIGURE_REPRESENTATIONC.h"
#include "SXFMapEntAConvC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_SYMBOL_REPRESENTATION_MAPC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�f�t�H���g�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_SYMBOL_REPRESENTATION_MAPC::SXFMapE_SYMBOL_REPRESENTATION_MAPC()

	����  �F	�^			������				���e
			�Ȃ�
	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_SYMBOL_REPRESENTATION_MAPC::SXFMapE_SYMBOL_REPRESENTATION_MAPC()
{
	m_EntityName = DEF_ELLIPSE;

	m_axis2_Inst = 0;
	m_axis2_P = NULL;

	m_subfig_rep_Inst=0;
	m_subfig_rep_P =NULL;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_SYMBOL_REPRESENTATION_MAPC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�C���X�^���X�h�c�ւ̃|�C���^���w�肵�Đ�������ꍇ
		(�R���X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_SYMBOL_REPRESENTATION_MAPC::SXFMapE_SYMBOL_REPRESENTATION_MAPC(
						SXFInstanceIDC* IN_InstanceIDManeger)
        :SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	����  �F	�^				������				���e
				SXFInstanceIDC* IN_InstanceIDManeger	�ݽ�ݽID�Ǘ���޼ު��

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_SYMBOL_REPRESENTATION_MAPC::SXFMapE_SYMBOL_REPRESENTATION_MAPC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)

{
	m_EntityName = DEF_ELLIPSE;

	m_axis2_Inst = 0;
	m_axis2_P = NULL;

	m_subfig_rep_Inst=0;
	m_subfig_rep_P =NULL;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_SYMBOL_REPRESENTATION_MAPC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		(�f�X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_SYMBOL_REPRESENTATION_MAPC::~SXFMapE_SYMBOL_REPRESENTATION_MAPC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_SYMBOL_REPRESENTATION_MAPC::~SXFMapE_SYMBOL_REPRESENTATION_MAPC()
{
	if(m_axis2_P!= NULL)
		delete m_axis2_P;
	if(m_subfig_rep_P!= NULL)
		delete m_subfig_rep_P;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_SYMBOL_REPRESENTATION_MAPC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�G���e�B�e�B�̃p�����^�ݒ�

	�Q�D�C���^�[�t�F�C�X
		int		SXFMapE_SYMBOL_REPRESENTATION_MAPC::SetParameter()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
int SXFMapE_SYMBOL_REPRESENTATION_MAPC::SetParameter( )
{

	SXFMapEntAConvC convent(m_EntityArray);
    
	//�����G���[
	if ( convent.GetInst(0,m_axis2_Inst) < 0 ){
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	//�����G���[
	if ( convent.GetInst(1,m_subfig_rep_Inst) < 0 ){
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	m_axis2_P =
		new SXFMapE_AXIS2_PLACEMENT_2DC(m_InstanceIDManager);
	int ircode = m_axis2_P->SetRootID(m_axis2_Inst);
	if ( ircode < 0 )
		return ircode ;
	ircode = m_axis2_P->SetParameter();
	if ( ircode < 0 )
		return ircode ;

	m_subfig_rep_P =
		new SXFMapE_DRAUGHTING_SUBFIGURE_REPRESENTATIONC(m_InstanceIDManager);
	ircode = m_subfig_rep_P->SetRootID(m_subfig_rep_Inst);
	if ( ircode < 0 )
		return ircode ;
	ircode = m_subfig_rep_P->SetParameter();
	if ( ircode < 0 )
		return ircode ;

	return 0;
}
