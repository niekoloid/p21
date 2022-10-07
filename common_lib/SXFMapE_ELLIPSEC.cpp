/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_ELLIPSEC.cpp						�쐬���F2000.04.17

	�P�D�N���X�T�v
		ELLIPSE���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#include "stdafx.h"
#include "SXFMapE_ELLIPSEC.h"
#include "SXFMapE_AXIS2_PLACEMENT_2DC.h"
#include "SXFMapEntAConvC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_ELLIPSEC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�f�t�H���g�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_ELLIPSEC::SXFMapE_ELLIPSEC()

	����  �F	�^			������				���e
			�Ȃ�
	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_ELLIPSEC::SXFMapE_ELLIPSEC()
{
	m_EntityName = DEF_ELLIPSE;

	m_axis2_Inst = 0;
	m_axis2_P = NULL;

	m_semi_axis_1 = 0.0;
	m_semi_axis_2 = 0.0;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_ELLIPSEC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�C���X�^���X�h�c�ւ̃|�C���^���w�肵�Đ�������ꍇ
		(�R���X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_ELLIPSEC::SXFMapE_ELLIPSEC(
					SXFInstanceIDC* IN_InstanceIDManeger)
        :SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	���� �F	�^				������				���e
			SXFInstanceIDC* IN_InstanceIDManeger	�ݽ�ݽID�Ǘ���޼ު��

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_ELLIPSEC::SXFMapE_ELLIPSEC(
		SXFInstanceIDC* IN_InstanceIDManeger)
        :SXFMapEntityBaseC(IN_InstanceIDManeger)

{
	m_EntityName = DEF_ELLIPSE;

	m_axis2_Inst = 0;
	m_axis2_P = NULL;

	m_semi_axis_1 = 0.0;
	m_semi_axis_2 = 0.0;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_ELLIPSEC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		(�f�X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_ELLIPSEC::~SXFMapE_ELLIPSEC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_ELLIPSEC::~SXFMapE_ELLIPSEC()
{
	if(m_axis2_P!= NULL)
		delete m_axis2_P;
}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_ELLIPSEC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�G���e�B�e�B�̃p�����^�ݒ�

	�Q�D�C���^�[�t�F�C�X
		int		SXFMapE_ELLIPSEC::SetParameter()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
int SXFMapE_ELLIPSEC::SetParameter( )
{

	SXFMapEntAConvC convent(m_EntityArray);

	//�����G���[
	if ( convent.GetCString(0,m_EllipseName) < 0 ){
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	//�����G���[
	if ( convent.GetInst(1,m_axis2_Inst) < 0 ){
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	//�����G���[
	if ( convent.GetDouble(2,m_semi_axis_1) < 0 ){
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	//�����G���[
	if ( convent.GetDouble(3,m_semi_axis_2) < 0 ){
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	//�I�u�W�F�N�g����
	m_axis2_P = 
		new SXFMapE_AXIS2_PLACEMENT_2DC(m_InstanceIDManager);
	int ircode = m_axis2_P->SetRootID(m_axis2_Inst);
	if ( ircode < 0 )
		return ircode ;
	ircode = m_axis2_P->SetParameter();
	if ( ircode < 0 )
		return ircode ;

	return 0;
}
