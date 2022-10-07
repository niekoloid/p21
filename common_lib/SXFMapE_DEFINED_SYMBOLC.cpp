/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_DEFINED_SYMBOLC.cpp						�쐬���F2000.04.17

	�P�D�N���X�T�v
		DEFINED_SYMBOL���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#include "stdafx.h"
#include "SXFMapEntityBaseC.h"
#include "SXFInstanceIDC.h"
#include "SXFMapEntAConvC.h"
#include "SXFMapE_DEFINED_SYMBOLC.h"
#include "SXFMapE_PRE_DEFINED_TERMINATOR_SYMBOLC.h"
#include "SXFMapE_EXTERNALLY_DEFINED_SYMBOLC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_DEFINED_SYMBOLC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�f�t�H���g�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_DEFINED_SYMBOLC::SXFMapE_DEFINED_SYMBOLC()

	����  �F	�^			������				���e
			�Ȃ�
	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/

SXFMapE_DEFINED_SYMBOLC::SXFMapE_DEFINED_SYMBOLC()
{
	m_EntityName = DEF_DEFINED_SYMBOL;

	m_Definition_Inst = 0;
	m_Definition_p = NULL;
	m_Target_Inst = 0;
	m_Target_p = NULL;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_DEFINED_SYMBOLC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�C���X�^���X�h�c�ւ̃|�C���^���w�肵�Đ�������ꍇ
		(�R���X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_DEFINED_SYMBOLC::SXFMapE_DEFINED_SYMBOLC(
							SXFInstanceIDC* IN_InstanceIDManeger)
        :SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	�����F	�^					������				���e
			SXFInstanceIDC*		IN_InstanceIDManeger	�ݽ�ݽID�Ǘ���޼ު��

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/

SXFMapE_DEFINED_SYMBOLC::SXFMapE_DEFINED_SYMBOLC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)

{
	m_EntityName = DEF_DEFINED_SYMBOL;

	m_Definition_Inst = 0;
	m_Definition_p = NULL;

	m_Target_Inst = 0;
	m_Target_p = NULL;

	m_DefsymKind = 0;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_DEFINED_SYMBOLC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		(�f�X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_DEFINED_SYMBOLC::~SXFMapE_DEFINED_SYMBOLC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_DEFINED_SYMBOLC::~SXFMapE_DEFINED_SYMBOLC()
{

	if(m_Definition_p != NULL){
		if ( m_DefsymKind == 1 ) delete (SXFMapE_PRE_DEFINED_POINT_MARKER_SYMBOLC*)m_Definition_p;
		if ( m_DefsymKind == 2 ) delete (SXFMapE_PRE_DEFINED_TERMINATOR_SYMBOLC*)m_Definition_p;
		if ( m_DefsymKind == 3 ) delete (SXFMapE_EXTERNALLY_DEFINED_SYMBOLC*)m_Definition_p;
	}
	if(m_Target_p != NULL)  delete m_Target_p;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_DEFINED_SYMBOLC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�G���e�B�e�B�̃p�����^�ݒ�

	�Q�D�C���^�[�t�F�C�X
		int		SXFMapE_DEFINED_SYMBOLC::SetParameter()

	����  �F	�^			������				���e
			�Ȃ�	

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/

int SXFMapE_DEFINED_SYMBOLC::SetParameter( )
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
	if ( convent.GetInst(1,m_Definition_Inst ) < 0 ){
		SXFErrorMsgC::RecordError( SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	CString InstEntityName;
	//m_Definitio���擾���A���ʂ���B
	InstEntityName = SXFMapInstIDC::GetEntityName(m_Definition_Inst);

	if ( InstEntityName == DEF_PRE_DEFINED_POINT_MARKER_SYMBOL){
		m_DefsymKind = 1;

		m_Definition_p = 
			new SXFMapE_PRE_DEFINED_POINT_MARKER_SYMBOLC(m_InstanceIDManager );

		ircode = ((SXFMapE_PRE_DEFINED_POINT_MARKER_SYMBOLC*)m_Definition_p)->SetRootID(m_Definition_Inst);
		if ( ircode < 0 )
			return ircode ;
		ircode = ((SXFMapE_PRE_DEFINED_POINT_MARKER_SYMBOLC*)m_Definition_p)->SetParameter();
		if ( ircode < 0 )
			return ircode ;

		if ( convent.GetInst(2,m_Target_Inst ) < 0 ){
			SXFErrorMsgC::RecordError( SXFPARAMS,
										m_EntityName,
										2,
										m_RootID,
										m_EntityName
										);
			return SXFPARAMS;
		}
	}
	else if ( InstEntityName == DEF_PRE_DEFINED_TERMINATOR_SYMBOL ){

		m_DefsymKind = 2;

		m_Definition_p =
			new SXFMapE_PRE_DEFINED_TERMINATOR_SYMBOLC(m_InstanceIDManager );

		ircode = ((SXFMapE_PRE_DEFINED_TERMINATOR_SYMBOLC*)m_Definition_p)->SetRootID(m_Definition_Inst);
		if ( ircode < 0 )
			return ircode ;
		ircode =  ((SXFMapE_PRE_DEFINED_TERMINATOR_SYMBOLC*)m_Definition_p)->SetParameter();
		if ( ircode < 0 )
			return ircode ;

		if ( convent.GetInst(2,m_Target_Inst ) < 0 ){
			SXFErrorMsgC::RecordError( SXFPARAMS,
										m_EntityName,
										2,
										m_RootID,
										m_EntityName
										);
			return SXFPARAMS;
		}
	}
	else if ( InstEntityName == DEF_EXTERNALLY_DEFINED_SYMBOL){
		// #1386 = EXTERNALLY_DEFINED_SYMBOL(IDENTIFIER('star'), #1385);

		m_DefsymKind = 3;

		m_Definition_p = 
			new SXFMapE_EXTERNALLY_DEFINED_SYMBOLC(m_InstanceIDManager );

		ircode = ((SXFMapE_EXTERNALLY_DEFINED_SYMBOLC*)m_Definition_p)->SetRootID(m_Definition_Inst);
		if ( ircode < 0 )
			return ircode ;
		ircode = ((SXFMapE_EXTERNALLY_DEFINED_SYMBOLC*)m_Definition_p)->SetParameter();
		if ( ircode < 0 )
			return ircode ;

		if ( convent.GetInst(2,m_Target_Inst ) < 0 ){
			SXFErrorMsgC::RecordError( SXFPARAMS,
										m_EntityName,
										2,
										m_RootID,
										m_EntityName
										);
			return SXFPARAMS;
		}
	}
	else{
		//err SCDAEC�O
	}

	m_Target_p = 
		new SXFMapE_SYMBOL_TARGETC(m_InstanceIDManager );

	ircode = m_Target_p->SetRootID(m_Target_Inst);
	if ( ircode < 0 )
		return ircode ;
	ircode = m_Target_p->SetParameter();
	if ( ircode < 0 )
		return ircode ;

	return 0;
}
