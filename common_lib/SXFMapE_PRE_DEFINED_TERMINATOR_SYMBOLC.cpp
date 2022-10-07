/**
	All Rights Reserved,(c) JACIC 2001
	�t�@�C����				�쐬���F2000.05.12
	SXFMapE_PRE_DEFINED_TERMINATOR_SYMBOLC.cpp

	�P�D�@�\�T�v
	    �ȉ��̃G���e�B�e�B�Ɋւ�������Ǘ�����B

			ENTITY pre_defined_terminator_symbol
				SUBTYPE OF (pre_defined_symbol);
				WHERE
					wr1: SELF.name IN [
									   'blanked arrow',
									   'blanked box',
									   'blanked dot',
									   'dimension origin',
									   'filled arrow',
									   'filled box',
									   'filled dot',
									   'integral symbol',
									   'open arrow',
									   'slash',
									   'unfilled arrow'
									   ];
			END_ENTITY;

	�Q�D����
	����ԍ�		���t��		�S����		�T�v
	�쐬		2000.05.12	�@���{(FQS)	�@�@�Ȃ��B

**/
#include "stdafx.h"
#include <afxtempl.h>
#include "SXFMapEntAConvC.h"
#include "SXFMapEntityBaseC.h"
#include "SXFInstanceIDC.h"
#include "SXFMapE_PRE_DEFINED_TERMINATOR_SYMBOLC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	�t�@�C����				�쐬���F2000.05.12
	SXFMapE_PRE_DEFINED_TERMINATOR_SYMBOLC.cpp

  �@�P�D�@�\�T�v
	    �f�t�H���g�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		SXFMapE_PRE_DEFINED_TERMINATOR_SYMBOLC( )

	�����F	�^	������		���e
			�Ȃ��B

  �@���A�l�F�Ȃ��B

	�R�D����
	����ԍ�		���t��		�S����		�T�v
	�쐬		2000.05.12	�@�@���{(FQS)	�Ȃ��B
**/
SXFMapE_PRE_DEFINED_TERMINATOR_SYMBOLC::SXFMapE_PRE_DEFINED_TERMINATOR_SYMBOLC()
{

	// �G���e�B�e�B����ݒ肷��B
	m_EntityName = DEF_PRE_DEFINED_TERMINATOR_SYMBOL;

}

/**
	All Rights Reserved,(c) JACIC 2001
	�t�@�C����				�쐬���F2000.05.12
	SXFMapE_PRE_DEFINED_TERMINATOR_SYMBOLC.cpp

  �@�P�D�@�\�T�v
	    �R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		SXFMapE_PRE_DEFINED_TERMINATOR_SYMBOLC(SXFInstanceIDC* IN_InstanceIDManeger)

	�����F	�^					������					���e
			SXFInstanceIDC*		IN_InstanceIDManeger	�C���X�^���XID
														�I�u�W�F�N�g�̃|�C���^

  �@���A�l�F�Ȃ��B

	�R�D����
	����ԍ�		���t��		�S����		�T�v
	�쐬		2000.05.12	�@�@���{(FQS)	�Ȃ��B
**/
SXFMapE_PRE_DEFINED_TERMINATOR_SYMBOLC::
		SXFMapE_PRE_DEFINED_TERMINATOR_SYMBOLC(
				SXFInstanceIDC* IN_InstanceIDManeger)
        		:SXFMapEntityBaseC(IN_InstanceIDManeger)

{
	// �G���e�B�e�B����ݒ肷��B
	m_EntityName = DEF_PRE_DEFINED_TERMINATOR_SYMBOL;

}

/**
	All Rights Reserved,(c) JACIC 2001
	�t�@�C����				�쐬���F2000.05.12
	SXFMapE_PRE_DEFINED_TERMINATOR_SYMBOLC.cpp

  �@�P�D�@�\�T�v
	    �f�t�H���g�f�X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		~SXFMapE_PRE_DEFINED_TERMINATOR_SYMBOLC( )

	�����F	�^		������		���e
			�Ȃ��B

  �@���A�l�F�Ȃ��B

	�R�D����
	����ԍ�		���t��		�S����		�T�v
	�쐬		2000.05.12	�@�@���{(FQS)	�Ȃ��B
**/
SXFMapE_PRE_DEFINED_TERMINATOR_SYMBOLC::
			~SXFMapE_PRE_DEFINED_TERMINATOR_SYMBOLC()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	�t�@�C����				�쐬���F2000.05.12
	SXFMapE_PRE_DEFINED_TERMINATOR_SYMBOLC.cpp

  �@�P�D�@�\�T�v
	    ���R�[�h���Z�b�g���郁���o�֐�

	�Q�D�C���^�[�t�F�C�X
		int	SetParameter( )

	�����F	�^		������		���e
			�Ȃ��B

  �@���A�l�F0

	�R�D����
	����ԍ�		���t��		�S����		�T�v
	�쐬		2000.05.12	�@�@���{(FQS)	�Ȃ��B
**/

int SXFMapE_PRE_DEFINED_TERMINATOR_SYMBOLC::SetParameter( )
{

	SXFMapEntAConvC convent(m_EntityArray);

	if ( convent.GetCString(0,m_Name) < 0 ){
		SXFErrorMsgC::RecordError(	SXFPARAMS,
									m_EntityName,
									2,
									m_RootID,
									m_EntityName
									);
		return SXFPARAMS;	
	}

//
//	<���R�[�h�̔���>
//

	//	'blanked arrow'�̎��F1
	if ( m_Name=="blanked arrow") {
		m_code = 1;
	}
	//	'blanked box'�̎��F2
	else if (m_Name=="blanked box") {
		m_code = 2;
	}
	//	'blanked dot'�̎��F3
	else if ( m_Name=="blanked dot") {
		m_code = 3;
	}
	//	'dimension origin'�̎��F4
	else if (m_Name=="dimension origin") {
		m_code = 4;
	}
	//	'filled box'�̎��F5
	else if (m_Name.Find("filled box") != -1 ) {
		m_code = 5;
	}
	//	'filled arrow'�̎��F6
	else if ( m_Name=="filled arrow") {
		m_code = 6;
	}
	//	'filled dot'�̎��F7
	else if ( m_Name=="filled dot") {
		m_code = 7;
	}
	//	'integral symbol'�̎��F8
	else if (m_Name=="integral symbol") {
		m_code = 8;
	}
	//	'open arrow'�̎��F9	
	else if (m_Name=="open arrow") {
		m_code = 9;
	}
	//	'slash'�̎��F10
	else if (m_Name=="slash") {
		m_code = 10;
	}
	//	'unfilled arrow'�̎��F11
	else if (m_Name=="unfilled arrow") {
		m_code = 11;
	}
	//	��L�ȊO�̖��O�̎�
	else {
		//err �|�C���g�}�[�J�[�̖��O���������Ȃ�
	}
	return 0;
}
