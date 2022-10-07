/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_EXTERNALLY_DEFINED_SYMBOLC.cpp						�쐬���F2000.04.17

	�P�D�N���X�T�v
		EXTERNALLY_DEFINED_SYMBOL���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#include "stdafx.h"
#include "SXFMapEntAConvC.h"
#include "SXFMapEntityBaseC.h"
#include "SXFInstanceIDC.h"
#include "SXFMapE_EXTERNALLY_DEFINED_SYMBOLC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_EXTERNALLY_DEFINED_SYMBOLC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�f�t�H���g�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_EXTERNALLY_DEFINED_SYMBOLC::SXFMapE_EXTERNALLY_DEFINED_SYMBOLC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_EXTERNALLY_DEFINED_SYMBOLC::SXFMapE_EXTERNALLY_DEFINED_SYMBOLC()
{
	m_EntityName = DEF_EXTERNALLY_DEFINED_SYMBOL;

	m_Source_Inst = 0;
	m_Source_p = NULL;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_EXTERNALLY_DEFINED_SYMBOLC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�C���X�^���X�h�c�ւ̃|�C���^���w�肵�Đ�������ꍇ
		(�R���X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_EXTERNALLY_DEFINED_SYMBOLC::SXFMapE_EXTERNALLY_DEFINED_SYMBOLC(
						SXFInstanceIDC* IN_InstanceIDManeger)
        :SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	���� �F	�^				������				���e
			SXFInstanceIDC* IN_InstanceIDManeger	�ݽ�ݽID�Ǘ���޼ު��

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_EXTERNALLY_DEFINED_SYMBOLC::SXFMapE_EXTERNALLY_DEFINED_SYMBOLC(
		SXFInstanceIDC* IN_InstanceIDManeger)
        :SXFMapEntityBaseC(IN_InstanceIDManeger)

{
	m_EntityName = DEF_EXTERNALLY_DEFINED_SYMBOL;

	m_Source_Inst = 0;
	m_Source_p = NULL;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_EXTERNALLY_DEFINED_SYMBOLC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		(�f�X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_EXTERNALLY_DEFINED_SYMBOLC::~SXFMapE_EXTERNALLY_DEFINED_SYMBOLC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_EXTERNALLY_DEFINED_SYMBOLC::~SXFMapE_EXTERNALLY_DEFINED_SYMBOLC()
{
	if(m_Source_p != NULL)
		delete m_Source_p;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_EXTERNALLY_DEFINED_SYMBOLC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�G���e�B�e�B�̃p�����^�ݒ�

	�Q�D�C���^�[�t�F�C�X
		int		SXFMapE_EXTERNALLY_DEFINED_SYMBOLC::SetParameter()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
int SXFMapE_EXTERNALLY_DEFINED_SYMBOLC::SetParameter( )
{

//#1526 = EXTERNALLY_DEFINED_SYMBOL(IDENTIFIER('open arrow'), #1525);

	int ircode;

	SXFMapEntAConvC convent(m_EntityArray);

	CString tempstring;
	//�����G���[
	if ( convent.GetSelectCString(0, "IDENTIFIER", tempstring )<0) {
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

//	m_Name.TrimLeft("'");
//	m_Name.TrimRight("'");

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
