/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_EXTERNALLY_DEFINED_HATCHC.cpp						�쐬���F2000.04.17

	�P�D�N���X�T�v
		EXTERNALLY_DEFINED_HATCH���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#include "stdafx.h"
#include "SXFMapEntAConvC.h"
#include "SXFMapEntityBaseC.h"
#include "SXFInstanceIDC.h"
#include "SXFMapE_EXTERNALLY_DEFINED_HATCHC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_EXTERNALLY_DEFINED_HATCHC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�f�t�H���g�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_EXTERNALLY_DEFINED_HATCHC::SXFMapE_EXTERNALLY_DEFINED_HATCHC()

	����  �F	�^			������				���e
			�Ȃ�
	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_EXTERNALLY_DEFINED_HATCHC::SXFMapE_EXTERNALLY_DEFINED_HATCHC()
{
	m_EntityName = DEF_EXTERNALLY_DEFINED_HATCH;

	m_Source_Inst = 0;
	m_Source_p = NULL;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_EXTERNALLY_DEFINED_HATCHC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�C���X�^���X�h�c�ւ̃|�C���^���w�肵�Đ�������ꍇ
		(�R���X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_EXTERNALLY_DEFINED_HATCHC::SXFMapE_EXTERNALLY_DEFINED_HATCHC(
						SXFInstanceIDC* IN_InstanceIDManeger)
        :SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	���� �F	�^				������				���e
			SXFInstanceIDC* IN_InstanceIDManeger	�ݽ�ݽID�Ǘ���޼ު��

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_EXTERNALLY_DEFINED_HATCHC::SXFMapE_EXTERNALLY_DEFINED_HATCHC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)

{
	m_EntityName = DEF_EXTERNALLY_DEFINED_HATCH;

	m_Source_Inst = 0;
	m_Source_p = NULL;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_EXTERNALLY_DEFINED_HATCHC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		(�f�X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_EXTERNALLY_DEFINED_HATCHC::~SXFMapE_EXTERNALLY_DEFINED_HATCHC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_EXTERNALLY_DEFINED_HATCHC::~SXFMapE_EXTERNALLY_DEFINED_HATCHC()
{
	if(m_Source_p != NULL)
		delete m_Source_p;
}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_EXTERNALLY_DEFINED_HATCHC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�G���e�B�e�B�̃p�����^�ݒ�

	�Q�D�C���^�[�t�F�C�X
		int		SXFMapE_EXTERNALLY_DEFINED_HATCHC::SetParameter()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
int SXFMapE_EXTERNALLY_DEFINED_HATCHC::SetParameter( )
{

	int ircode;

	SXFMapEntAConvC convent(m_EntityArray);

	//#1203 = EXTERNALLY_DEFINED_HATCH(IDENTIFIER('circle'), #1202, 'externally_defined_HATCH1');

	CString tempstring;
	//�����G���[
	if ( convent.GetSelectCString(0, DEF_IDENTIFIER, tempstring )<0) {
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	tempstring.TrimLeft("'");
	tempstring.TrimRight("'");
	m_Name = tempstring;	
  
//    int left = tempstring.Find('\'');
//    int right = tempstring.Find('\'',left);

//    m_Name = tempstring.Mid(left+1,right-left-1);
//    m_Name.TrimLeft();
//    m_Name.TrimRight();

	//�����G���[
	if(m_Name.IsEmpty()){
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	//�����G���[
	if ( convent.GetInst(1,m_Source_Inst) < 0 ){
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	//�I�u�W�F�N�g����
	m_Source_p = new SXFMapE_EXTERNAL_SOURCEC(m_InstanceIDManager);

	ircode = m_Source_p->SetRootID(m_Source_Inst);
	if ( ircode < 0 )
		return ircode ;
	ircode = m_Source_p->SetParameter();
	if ( ircode < 0 )
		return ircode ;

	return 0;
}
