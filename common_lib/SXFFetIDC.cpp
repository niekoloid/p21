/**
	All Rights Reserved,(c)JACIC 2001
	SXFFetIDC.cpp					�쐬���F2000.03.21

	�P�D�N���X�T�v
	�t�@�C���ɏo�͂��ׂ��C���X�^���XID���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2000.03.21	�ЎR(FQS)	�Ȃ��B
**/

#include "stdafx.h"
#include "SXFFetIDC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
/**
	All Rights Reserved,(c) JACIC 2001
	SXFFetIDC.cpp								�쐬���F2000.3.21

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void	SXFFetIDC::SXFFetIDC()
		
	����	�F	�^		������				���e
		�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.3.21			�|�R(FQS)			�Ȃ��B

**/
SXFFetIDC::SXFFetIDC()
{
	m_insID = 0 ;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFFetIDC.cpp								�쐬���F2000.3.21

	�P�D�@�\�T�v
		�f�X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void	SXFFetIDC::~SXFFetIDC()
		
	����	�F	�^		������				���e
		�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.3.21			�|�R(FQS)			�Ȃ��B

**/
SXFFetIDC::~SXFFetIDC ()
{
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFFetIDC.cpp								�쐬���F2000.3.21

	�P�D�@�\�T�v
		�C���X�^���XID�̕ԋp

	�Q�D�C���^�[�t�F�[�X
		int	SXFFetIDC::Get_ID()
		
	����	�F	�^		������				���e
		�Ȃ�

	���A�l
			int		m_insID		�C���X�^���XID

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.3.21			�|�R(FQS)			�Ȃ��B

**/
int SXFFetIDC::Get_ID (){
	m_insID += 10 ;
	return m_insID ;
}
