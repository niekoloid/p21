/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_PRE_DEFINED_POINT_MARKER_SYMBOLC.cpp						�쐬���F2000.04.17

	�P�D�N���X�T�v
		PRE_DEFINED_POINT_MARKER_SYMBOL���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#include "stdafx.h"
#include <afxtempl.h>
#include "SXFMapEntAConvC.h"
#include "SXFMapEntityBaseC.h"
#include "SXFInstanceIDC.h"
#include "SXFMapE_PRE_DEFINED_POINT_MARKER_SYMBOLC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_PRE_DEFINED_POINT_MARKER_SYMBOLC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�f�t�H���g�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_PRE_DEFINED_POINT_MARKER_SYMBOLC::SXFMapE_PRE_DEFINED_POINT_MARKER_SYMBOLC()

	����  �F	�^			������				���e
			�Ȃ�
	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_PRE_DEFINED_POINT_MARKER_SYMBOLC::SXFMapE_PRE_DEFINED_POINT_MARKER_SYMBOLC()
{
	m_EntityName = DEF_PRE_DEFINED_POINT_MARKER_SYMBOL;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_PRE_DEFINED_POINT_MARKER_SYMBOLC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�C���X�^���X�h�c�ւ̃|�C���^���w�肵�Đ�������ꍇ
		(�R���X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_PRE_DEFINED_POINT_MARKER_SYMBOLC::SXFMapE_PRE_DEFINED_POINT_MARKER_SYMBOLC(
							SXFInstanceIDC* IN_InstanceIDManeger)
        :SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	����  �F	�^				������				���e
				SXFInstanceIDC* IN_InstanceIDManeger	�ݽ�ݽID�Ǘ���޼ު��

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_PRE_DEFINED_POINT_MARKER_SYMBOLC::SXFMapE_PRE_DEFINED_POINT_MARKER_SYMBOLC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)

{
	m_EntityName = DEF_PRE_DEFINED_POINT_MARKER_SYMBOL;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_PRE_DEFINED_POINT_MARKER_SYMBOLC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		(�f�X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_PRE_DEFINED_POINT_MARKER_SYMBOLC::~SXFMapE_PRE_DEFINED_POINT_MARKER_SYMBOLC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_PRE_DEFINED_POINT_MARKER_SYMBOLC::~SXFMapE_PRE_DEFINED_POINT_MARKER_SYMBOLC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_PRE_DEFINED_POINT_MARKER_SYMBOLC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�G���e�B�e�B�̃p�����^�ݒ�

	�Q�D�C���^�[�t�F�C�X
		int		SXFMapE_PRE_DEFINED_POINT_MARKER_SYMBOLC::SetParameter()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
int SXFMapE_PRE_DEFINED_POINT_MARKER_SYMBOLC::SetParameter( )
{

	SXFMapEntAConvC convent(m_EntityArray);

	//�����G���[
	if ( convent.GetCString(0,m_Name) < 0 ){
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;
	}

//	<�|�C���g�}�[�J�[�R�[�h�̔���>
//     wr1: SELF.name IN ['asterisk','circle','dot','plus','square',
//               'triangle','x'];

	if (m_Name=="asterisk") {
		m_code = 1;
	}
	else if (m_Name=="circle") {
		m_code = 2;
	}
	else if (m_Name=="dot") {
		m_code = 3;
	}
	else if (m_Name=="plus") {
		m_code = 4;
	}
	else if (m_Name=="square") {
		m_code = 5;
	}
	else if (m_Name=="triangle") {
		m_code = 6;
	}
	else if (m_Name=="x") {
		m_code = 7;
	}
	else {
		//err �|�C���g�}�[�J�[�̖��O���������Ȃ�
	}

	return 0;
}
