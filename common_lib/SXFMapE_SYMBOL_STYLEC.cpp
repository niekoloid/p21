/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_SYMBOL_STYLEC.cpp						�쐬���F2000.04.17

	�P�D�N���X�T�v
		SYMBOL_STYLE���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#include "stdafx.h"
#include "SXFMapE_SYMBOL_STYLEC.h"
#include "SXFMapE_SYMBOL_COLOURC.h"
#include "SXFMapEntAConvC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_SYMBOL_STYLEC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�f�t�H���g�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_SYMBOL_STYLEC::SXFMapE_SYMBOL_STYLEC()

	����  �F	�^			������				���e
			�Ȃ�
	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_SYMBOL_STYLEC::SXFMapE_SYMBOL_STYLEC()
{
//	<������>
	m_EntityName = DEF_SYMBOL_STYLE;
//<�G���e�B�e�B�f�[�^>

//#110=SYMBOL_STYLE(' ',#100);
	//	1.name�p�����^
	m_name.Empty();

	//	2.symbol_colour �ւ̃C���X�^���XID
	m_symbol_colour_Inst = 0;

	//	symbol_colour�ւ̃|�C���^
	m_symbol_colour_P =NULL;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_SYMBOL_STYLEC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�C���X�^���X�h�c�ւ̃|�C���^���w�肵�Đ�������ꍇ
		(�R���X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_SYMBOL_STYLEC::SXFMapE_SYMBOL_STYLEC(
						SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	����  �F	�^				������				���e
				SXFInstanceIDC* IN_InstanceIDManeger	�ݽ�ݽID�Ǘ���޼ު��

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_SYMBOL_STYLEC::SXFMapE_SYMBOL_STYLEC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
{
//	<������>
	m_EntityName = DEF_SYMBOL_STYLE;
//<�G���e�B�e�B�f�[�^>

//#110=SYMBOL_STYLE(' ',#100);
	//	1.name�p�����^
	m_name.Empty();

	//	2.symbol_colour �ւ̃C���X�^���XID
	m_symbol_colour_Inst = 0;

	//	symbol_colour�ւ̃|�C���^
	m_symbol_colour_P =NULL;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_SYMBOL_STYLEC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		(�f�X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_SYMBOL_STYLEC::~SXFMapE_SYMBOL_STYLEC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_SYMBOL_STYLEC::~SXFMapE_SYMBOL_STYLEC()
{
	if(m_symbol_colour_P != NULL)
	{
		delete m_symbol_colour_P;
	}
}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_SYMBOL_STYLEC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�G���e�B�e�B�̃p�����^�ݒ�

	�Q�D�C���^�[�t�F�C�X
		int		SXFMapE_SYMBOL_STYLEC::SetParameter()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
int SXFMapE_SYMBOL_STYLEC::SetParameter()

{
//	<1. �G���e�B�e�B�p�����^�̐ݒ�>

	int ircode=0;
//<�G���e�B�e�B�f�[�^>

//#110=SYMBOL_STYLE(' ',#100);

	SXFMapEntAConvC convent(m_EntityArray);

	//	1.name�p�����^
	convent.GetCString(0,m_name);

	//	2.symbol_colour �ւ̃C���X�^���XID
	convent.GetInst(1,m_symbol_colour_Inst);


//	<2. �Q�Ɛ��DIRECTION�G���e�B�e�B�p�����^�̐ݒ�>
	//#100=SYMBOL_COLOUR(#40);

	//�G���e�B�e�B�C���X�^���X���쐬
	m_symbol_colour_P = new SXFMapE_SYMBOL_COLOURC(m_InstanceIDManager);

	if (m_EntityArray->GetSize() > 1){
		if (m_EntityArray->GetAt(1) == DEF_DOLLAR){
			return 1;
		}
	}

	ircode = m_symbol_colour_P->SetRootID(m_symbol_colour_Inst);
		if ( ircode < 0 )	return ircode ;
	//�G���e�B�e�B�p�����^�̐ݒ�
	ircode = m_symbol_colour_P->SetParameter();
		if ( ircode < 0 )	return ircode ;

	return 0;
}
