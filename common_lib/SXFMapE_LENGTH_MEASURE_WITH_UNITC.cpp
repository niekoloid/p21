/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_LENGTH_MEASURE_WITH_UNITC.cpp						�쐬���F2001.06.17

	�P�D�N���X�T�v
		LENGTH_MEASURE_WITH_UNIT���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2001.06.17	

**/
#include "stdafx.h"
#include "SXFMapEntAConvC.h"
#include "SXFMapEntityBaseC.h"
#include "SXFInstanceIDC.h"
#include "SXFMapE_LENGTH_MEASURE_WITH_UNITC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_LENGTH_MEASURE_WITH_UNITC.cpp						�쐬���F2001.06.17

	�P�D�@�\�T�v
		�f�t�H���g�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_LENGTH_MEASURE_WITH_UNITC::SXFMapE_LENGTH_MEASURE_WITH_UNITC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2001.06.17	
**/
SXFMapE_LENGTH_MEASURE_WITH_UNITC::SXFMapE_LENGTH_MEASURE_WITH_UNITC()
{
	m_EntityName = DEF_LENGTH_MEASURE_WITH_UNIT;

	m_Width = 0.0;
	m_UnitComponent_Inst = 0;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_LENGTH_MEASURE_WITH_UNITC.cpp						�쐬���F2001.06.17

	�P�D�@�\�T�v
		�C���X�^���X�h�c�ւ̃|�C���^���w�肵�Đ�������ꍇ
		(�R���X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_LENGTH_MEASURE_WITH_UNITC::SXFMapE_LENGTH_MEASURE_WITH_UNITC(
						SXFInstanceIDC* IN_InstanceIDManeger)
        :SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	���� �F	�^				������				���e
			SXFInstanceIDC* IN_InstanceIDManeger	�ݽ�ݽID�Ǘ���޼ު��

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2001.06.17	
**/
SXFMapE_LENGTH_MEASURE_WITH_UNITC::SXFMapE_LENGTH_MEASURE_WITH_UNITC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)

{
	m_EntityName = DEF_LENGTH_MEASURE_WITH_UNIT;

	m_Width = 0.0;
	m_UnitComponent_Inst = 0;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_LENGTH_MEASURE_WITH_UNITC.cpp						�쐬���F2001.06.17

	�P�D�@�\�T�v
		(�f�X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_LENGTH_MEASURE_WITH_UNITC::~SXFMapE_LENGTH_MEASURE_WITH_UNITC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2001.06.17	
**/
SXFMapE_LENGTH_MEASURE_WITH_UNITC::~SXFMapE_LENGTH_MEASURE_WITH_UNITC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_LENGTH_MEASURE_WITH_UNITC.cpp						�쐬���F2001.06.17

	�P�D�@�\�T�v
		�G���e�B�e�B�̃p�����^�ݒ�

	�Q�D�C���^�[�t�F�C�X
		int		SXFMapE_LENGTH_MEASURE_WITH_UNITC::SetParameter()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2001.06.17	
**/
int SXFMapE_LENGTH_MEASURE_WITH_UNITC::SetParameter( )
{

	SXFMapEntAConvC convent(m_EntityArray);

	CString tempstring;
	//�����G���[
	if ( convent.GetCString(0,tempstring) < 0 ){
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

	int left = tempstring.Find('(');
	int right = tempstring.Find(')');

	CString widthstring = tempstring.Mid(left+1,right-left-1);

	m_Width = atof(widthstring);

	//�������ُ�
	if(m_Width<0){
		SXFErrorMsgC::RecordError(	SXFWIDTHERROR,
									m_EntityName,
									1,
									m_Width);
		return SXFWIDTHERROR;
	}

	//�����G���[
	if ( convent.GetInst(1,m_UnitComponent_Inst) < 0 ){
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
