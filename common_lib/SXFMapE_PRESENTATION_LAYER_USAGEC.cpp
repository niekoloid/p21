/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_PRESENTATION_LAYER_USAGEC.cpp						�쐬���F2000.04.17

	�P�D�N���X�T�v
		PRESENTATION_LAYER_USAGE���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#include "stdafx.h"
#include "SXFMapEntAConvC.h"
#include "SXFMapEntityBaseC.h"
#include "SXFInstanceIDC.h"
#include "SXFMapE_PRESENTATION_LAYER_USAGEC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_PRESENTATION_LAYER_USAGEC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�f�t�H���g�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_PRESENTATION_LAYER_USAGEC::SXFMapE_PRESENTATION_LAYER_USAGEC()

	����  �F	�^			������				���e
			�Ȃ�
	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_PRESENTATION_LAYER_USAGEC::SXFMapE_PRESENTATION_LAYER_USAGEC()
{
	m_EntityName = DEF_PRESENTATION_LAYER_USAGE;

	m_Assignment_Inst = 0;
	m_Assignment_p = NULL;
	m_Presentation_Inst = 0;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_PRESENTATION_LAYER_USAGEC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�C���X�^���X�h�c�ւ̃|�C���^���w�肵�Đ�������ꍇ
		(�R���X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_PRESENTATION_LAYER_USAGEC::SXFMapE_PRESENTATION_LAYER_USAGEC(
						SXFInstanceIDC* IN_InstanceIDManeger)
        :SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	����  �F	�^				������				���e
				SXFInstanceIDC* IN_InstanceIDManeger	�ݽ�ݽID�Ǘ���޼ު��

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_PRESENTATION_LAYER_USAGEC::SXFMapE_PRESENTATION_LAYER_USAGEC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)

{
	m_EntityName = DEF_PRESENTATION_LAYER_USAGE;

	m_Assignment_Inst = 0;
	m_Assignment_p = NULL;
	m_Presentation_Inst = 0;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_PRESENTATION_LAYER_USAGEC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		(�f�X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_PRESENTATION_LAYER_USAGEC::~SXFMapE_PRESENTATION_LAYER_USAGEC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_PRESENTATION_LAYER_USAGEC::~SXFMapE_PRESENTATION_LAYER_USAGEC()
{
	if(m_Assignment_p != NULL)
		delete m_Assignment_p;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_PRESENTATION_LAYER_USAGEC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�G���e�B�e�B�̃p�����^�ݒ�

	�Q�D�C���^�[�t�F�C�X
		int		SXFMapE_PRESENTATION_LAYER_USAGEC::SetParameter()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
int SXFMapE_PRESENTATION_LAYER_USAGEC::SetParameter( )
{

	int ircode;

	SXFMapEntAConvC convent(m_EntityArray);

	//�����G���[
	if ( convent.GetInst(0,m_Assignment_Inst) < 0 ){
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	m_Assignment_p =
		new SXFMapE_PRESENTATION_LAYER_ASSIGNMENTC(m_InstanceIDManager);
	ircode = m_Assignment_p->SetRootID( m_Assignment_Inst);
	if ( ircode < 0 )
		return ircode ;
	ircode = m_Assignment_p->SetParameter();
	if ( ircode < 0 )
		return ircode ;

	//�����G���[
	if ( convent.GetInst(1,m_Presentation_Inst) < 0 ){
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
