/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_EXTERNAL_DEFINED_TEXT_FONTC.cpp						�쐬���F2000.04.17

	�P�D�N���X�T�v
		EXTERNAL_DEFINED_TEXT_FONT���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#include "stdafx.h"
#include "SXFMapEntAConvC.h"
#include "SXFMapEntityBaseC.h"
#include "SXFInstanceIDC.h"
#include "SXFMapE_EXTERNAL_DEFINED_TEXT_FONTC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_EXTERNAL_DEFINED_TEXT_FONTC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�f�t�H���g�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_EXTERNAL_DEFINED_TEXT_FONTC::SXFMapE_EXTERNAL_DEFINED_TEXT_FONTC()

	����  �F	�^			������				���e
			�Ȃ�
	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_EXTERNAL_DEFINED_TEXT_FONTC::SXFMapE_EXTERNAL_DEFINED_TEXT_FONTC()
{
	m_EntityName = DEF_EXTERNAL_DEFINED_TEXT_FONT;

	m_Source_Inst = 0;
	m_Source_p = NULL;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_EXTERNAL_DEFINED_TEXT_FONTC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�C���X�^���X�h�c�ւ̃|�C���^���w�肵�Đ�������ꍇ
		(�R���X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_EXTERNAL_DEFINED_TEXT_FONTC::SXFMapE_EXTERNAL_DEFINED_TEXT_FONTC(
						SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	���� �F	�^				������				���e
			SXFInstanceIDC* IN_InstanceIDManeger	�ݽ�ݽID�Ǘ���޼ު��

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_EXTERNAL_DEFINED_TEXT_FONTC::SXFMapE_EXTERNAL_DEFINED_TEXT_FONTC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)

{
	m_EntityName = DEF_EXTERNAL_DEFINED_TEXT_FONT;

	m_Source_Inst = 0;
	m_Source_p = NULL;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_EXTERNAL_DEFINED_TEXT_FONTC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		(�f�X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_EXTERNAL_DEFINED_TEXT_FONTC::~SXFMapE_EXTERNAL_DEFINED_TEXT_FONTC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_EXTERNAL_DEFINED_TEXT_FONTC::~SXFMapE_EXTERNAL_DEFINED_TEXT_FONTC()
{
	if(m_Source_p != NULL)
		delete m_Source_p;
}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_EXTERNAL_DEFINED_TEXT_FONTC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�G���e�B�e�B�̃p�����^�ݒ�

	�Q�D�C���^�[�t�F�C�X
		int		SXFMapE_EXTERNAL_DEFINED_TEXT_FONTC::SetParameter()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
int SXFMapE_EXTERNAL_DEFINED_TEXT_FONTC::SetParameter( )
{
//#260 = EXTERNALLY_DEFINED_TEXT_FONT(IDENTIFIER('\X2\30B730C330AF\X0\-15-3'), #261);

	int ircode;

	SXFMapEntAConvC convent(m_EntityArray);

	CString tempstring;
	//�����G���[
	if ( convent.GetSelectCString(0, DEF_IDENTIFIER, tempstring )<0) {
		SXFErrorMsgC::RecordError( SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}


//	  int left = tempstring.Find('\'');
//	  int right = tempstring.Find('\'',left);

//	  m_Name = tempstring.Mid(left+1,right-left-1);
//	  m_Name.TrimLeft();
//	  m_Name.TrimRight();

	tempstring.TrimLeft("'");
	tempstring.TrimRight("'");
	m_Name = tempstring;

	//�����G���[
	if(m_Name.IsEmpty()){
		SXFErrorMsgC::RecordError( SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}
	
	//�����G���[
	if ( convent.GetInst(1,m_Source_Inst) < 0 ){
		SXFErrorMsgC::RecordError( SXFPARAMS,
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
