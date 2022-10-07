/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_PRESENTATION_LAYER_ASSIGNMENTC.cpp						�쐬���F2000.04.17

	�P�D�N���X�T�v
		PRESENTATION_LAYER_ASSIGNMENT���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#include "stdafx.h"
#include "SXFMapEntAConvC.h"
#include "SXFMapEntityBaseC.h"
#include "SXFInstanceIDC.h"
#include "SXFMapE_PRESENTATION_LAYER_ASSIGNMENTC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_PRESENTATION_LAYER_ASSIGNMENTC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�f�t�H���g�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_PRESENTATION_LAYER_ASSIGNMENTC::SXFMapE_PRESENTATION_LAYER_ASSIGNMENTC()

	����  �F	�^			������				���e
			�Ȃ�
	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_PRESENTATION_LAYER_ASSIGNMENTC::SXFMapE_PRESENTATION_LAYER_ASSIGNMENTC()
{
	m_EntityName = DEF_PRESENTATION_LAYER_ASSIGNMENT;

	m_AssignedItemsCount = 0;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_PRESENTATION_LAYER_ASSIGNMENTC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�C���X�^���X�h�c�ւ̃|�C���^���w�肵�Đ�������ꍇ
		(�R���X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_PRESENTATION_LAYER_ASSIGNMENTC::SXFMapE_PRESENTATION_LAYER_ASSIGNMENTC(
								SXFInstanceIDC* IN_InstanceIDManeger)
  		:SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	����  �F	�^				������				���e
				SXFInstanceIDC* IN_InstanceIDManeger	�ݽ�ݽID�Ǘ���޼ު��

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_PRESENTATION_LAYER_ASSIGNMENTC::SXFMapE_PRESENTATION_LAYER_ASSIGNMENTC(
		SXFInstanceIDC* IN_InstanceIDManeger)
  		:SXFMapEntityBaseC(IN_InstanceIDManeger)
{
	m_EntityName = DEF_PRESENTATION_LAYER_ASSIGNMENT;

	m_AssignedItemsCount = 0;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_PRESENTATION_LAYER_ASSIGNMENTC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		(�f�X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_PRESENTATION_LAYER_ASSIGNMENTC::~SXFMapE_PRESENTATION_LAYER_ASSIGNMENTC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_PRESENTATION_LAYER_ASSIGNMENTC::~SXFMapE_PRESENTATION_LAYER_ASSIGNMENTC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_PRESENTATION_LAYER_ASSIGNMENTC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�G���e�B�e�B�̃p�����^�ݒ�

	�Q�D�C���^�[�t�F�C�X
		int		SXFMapE_PRESENTATION_LAYER_ASSIGNMENTC::SetParameter()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
int SXFMapE_PRESENTATION_LAYER_ASSIGNMENTC::SetParameter( )
{

/*
  ENTITY presentation_layer_assignment;
      name           : label;
      description    : text;
      assigned_items : SET [1:?] OF layered_item;
  END_ENTITY; -- presentation_layer_assignment */
  
//#1440 = PRESENTATION_LAYER_ASSIGNMENT
//('LayerCurve', 'layer associated with label, balloon, polyline and bezier', 
//(#1168, #1177, .........));

	SXFMapEntAConvC convent(m_EntityArray);
	INT_PTR size;
	size = m_EntityArray->GetSize();

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

 //[1]='layer associated with label'
 //[2]=' balloon'
 //[3]=' polyline and bezier'
//		=>[1]+[2]+[3]

	CString tmpcstring, comma;
	comma =',';

	for ( int i=1 ; i <size-1 ;i++){
		//�����G���[
		if ( convent.GetCString(i,tmpcstring) < 0 ){
			SXFErrorMsgC::RecordError( SXFPARAMS,
										m_EntityName,
										2,
										m_RootID,
										m_EntityName
										);
			return SXFPARAMS;
		}
		if (i<size-2)tmpcstring+=comma;
		m_Description+=tmpcstring;
	}

//	name,description �̒��� ', '�������Ă���ƁA
//	EntityData�͂����ŕ��������B
//	=>  EntityData�̌�납��f�[�^�����B

	if ( convent.GetSetInst( (int)(size-1),m_AssignedItemsCount,
		m_AssignedItems ) < 0 ){
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
