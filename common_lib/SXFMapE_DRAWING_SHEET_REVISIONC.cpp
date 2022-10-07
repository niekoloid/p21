/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_DRAWING_SHEET_REVISIONC.cpp						�쐬���F2000.04.17

	�P�D�N���X�T�v
		DRAWING_SHEET_REVISION���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#include "stdafx.h"
#include <afxtempl.h>
#include "SXFMapEntAConvC.h"
#include "SXFMapEntityBaseC.h"
#include "SXFInstanceIDC.h"
#include "SXFComndef.h"

#include "SXFMapE_DRAWING_SHEET_REVISIONC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_DRAWING_SHEET_REVISIONC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�f�t�H���g�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_DRAWING_SHEET_REVISIONC::SXFMapE_DRAWING_SHEET_REVISIONC()

	����  �F	�^			������				���e
			�Ȃ�
	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_DRAWING_SHEET_REVISIONC::SXFMapE_DRAWING_SHEET_REVISIONC()
{
	m_EntityName = DEF_DRAWING_SHEET_REVISION;

	m_ItemCount = 0;
	m_ContextOfItem_Inst = 0;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_DRAWING_SHEET_REVISIONC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�C���X�^���X�h�c�ւ̃|�C���^���w�肵�Đ�������ꍇ
		(�R���X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_DRAWING_SHEET_REVISIONC::SXFMapE_DRAWING_SHEET_REVISIONC(
						SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	���� �F	�^				������				���e
			SXFInstanceIDC* IN_InstanceIDManeger	�ݽ�ݽID�Ǘ���޼ު��

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_DRAWING_SHEET_REVISIONC::SXFMapE_DRAWING_SHEET_REVISIONC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)

{
	m_EntityName = DEF_DRAWING_SHEET_REVISION;

	m_ItemCount = 0;
	m_ContextOfItem_Inst = 0;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_DRAWING_SHEET_REVISIONC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		(�f�X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_DRAWING_SHEET_REVISIONC::~SXFMapE_DRAWING_SHEET_REVISIONC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_DRAWING_SHEET_REVISIONC::~SXFMapE_DRAWING_SHEET_REVISIONC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_DRAWING_SHEET_REVISIONC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�G���e�B�e�B�̃p�����^�ݒ�

	�Q�D�C���^�[�t�F�C�X
		int		SXFMapE_DRAWING_SHEET_REVISIONC::SetParameter()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
int SXFMapE_DRAWING_SHEET_REVISIONC::SetParameter( )
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
	if ( convent.GetSetInst(1,m_ItemCount, m_ItemArray_Inst ) < 0 ){
		SXFErrorMsgC::RecordError( SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}


	//�����G���[
	if ( convent.GetInst(2,m_ContextOfItem_Inst ) < 0 ){
		SXFErrorMsgC::RecordError( SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}
	
	//�����G���[
	if ( convent.GetCString(3,m_RevisionIdentifier ) < 0 ){
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


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_DRAWING_SHEET_REVISIONC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		PlanarBox�̃T�C�Y�擾

	�Q�D�C���^�[�t�F�C�X
		int		SXFMapE_DRAWING_SHEET_REVISIONC::GetPlanarBoxSize(int IN_ID, double &OUT_X, double &OUT_Y)

	���� �F	�^			������				���e
			int 		IN_ID
			double 		&OUT_X
			double		&OUT_Y

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
BOOL SXFMapE_DRAWING_SHEET_REVISIONC::GetPlanarBoxSize(int IN_ID, double &OUT_X, double &OUT_Y)

{

	CStringArray* tmparrayP;
	CStringArray tmparray;
	GetMyArray(IN_ID,tmparray);
	
	tmparrayP = &tmparray;
	SXFMapEntAConvC convert(tmparrayP);
	convert.GetDouble(1,OUT_X);
	convert.GetDouble(2,OUT_Y);

	return TRUE;

}