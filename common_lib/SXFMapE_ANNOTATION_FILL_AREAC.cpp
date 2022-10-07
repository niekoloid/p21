/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_ANNOTATION_FILL_AREAC.cpp						�쐬���F2000.04.21

	�P�D�N���X�T�v
	ANNOTATION_FILL_AREA���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.21	

**/

#include "stdafx.h"
#include "SXFMapEntAConvC.h"
#include "SXFMapEntityBaseC.h"
#include "SXFInstanceIDC.h"
#include "SXFMapE_ANNOTATION_FILL_AREAC.h"
#include "SXFMapE_COMPOSITE_CURVEC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_ANNOTATION_FILL_AREAC.cpp						�쐬���F2000.04.21

	�P�D�@�\�T�v
		�f�t�H���g�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		SXFMapE_ANNOTATION_FILL_AREAC::SXFMapE_ANNOTATION_FILL_AREAC()

	����  �F	�^			������				���e
			�Ȃ�
	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.21	
**/

SXFMapE_ANNOTATION_FILL_AREAC::SXFMapE_ANNOTATION_FILL_AREAC()
{
	m_EntityName = DEF_ANNOTATION_FILL_AREA;

	m_BoundaryCont = 0;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_ANNOTATION_FILL_AREAC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�C���X�^���X�h�c�ւ̃|�C���^���w�肵�Đ�������ꍇ
		(�R���X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_ANNOTATION_FILL_AREAC::SXFMapE_ANNOTATION_FILL_AREAC(
						SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	�����F	�^					������					���e
			SXFInstanceIDC* 	IN_InstanceIDManeger	�ݽ�ݽID�Ǘ���޼ު��

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/

SXFMapE_ANNOTATION_FILL_AREAC::SXFMapE_ANNOTATION_FILL_AREAC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)

{
	m_EntityName = DEF_ANNOTATION_FILL_AREA;
	m_BoundaryCont = 0;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_ANNOTATION_FILL_AREAC.cpp						�쐬���F2000.04.21

	�P�D�@�\�T�v
		(�f�X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_ANNOTATION_FILL_AREAC::~SXFMapE_ANNOTATION_FILL_AREAC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.21	
**/
SXFMapE_ANNOTATION_FILL_AREAC::~SXFMapE_ANNOTATION_FILL_AREAC()
{
	for(int i=0;i<m_Boundary_P.GetSize();i++){
		if( m_Boundary_P[i] != NULL)
			delete m_Boundary_P[i];
	}
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_ANNOTATION_FILL_AREAC.cpp						�쐬���F2000.04.21

	�P�D�@�\�T�v
		�G���e�B�e�B�̃p�����^�ݒ�

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_ANNOTATION_FILL_AREAC::SetParameter()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.21	
**/

int SXFMapE_ANNOTATION_FILL_AREAC::SetParameter( )
{

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
	if ( convent.GetSetInst(1, m_BoundaryCont, m_Boundary_Inst) < 0 ){
		SXFErrorMsgC::RecordError( SXFPARAMS,
								m_EntityName,
								2,
								m_RootID,
								m_EntityName
								);
		return SXFPARAMS;
	}
	
	//�I�u�W�F�N�g����
	for(int i=0;i<m_BoundaryCont;i++){
		SXFMapE_COMPOSITE_CURVEC* temp_p = 
			new SXFMapE_COMPOSITE_CURVEC(m_InstanceIDManager);
		m_Boundary_P.Add(temp_p);

		int ircode = temp_p->SetRootID(m_Boundary_Inst[i]);
		if ( ircode < 0 )
			return ircode ;
		ircode = temp_p->SetParameter();
		if ( ircode < 0 )
			return ircode ;
	}

	return 0;
}
