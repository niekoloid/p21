/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_CURVE_STYLE_FONTC.cpp						�쐬���F2000.04.17

	�P�D�N���X�T�v
		EntityData���^�ϊ�����

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#include "stdafx.h"
#include "SXFMapE_CURVE_STYLE_FONTC.h"
#include "SXFMapE_CURVE_STYLE_FONT_PATTERNC.h"
#include "SXFMapEntAConvC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_CURVE_STYLE_FONTC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�f�t�H���g�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_CURVE_STYLE_FONTC::SXFMapE_CURVE_STYLE_FONTC()

	����  �F	�^			������				���e
			�Ȃ�
	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_CURVE_STYLE_FONTC::SXFMapE_CURVE_STYLE_FONTC()
{
//	<������>
	m_EntityName = DEF_CURVE_STYLE_FONT;
//#80 = CURVE_STYLE_FONT('chain_4212', (#81, #82));
//<�G���e�B�e�B�f�[�^>
	m_name.Empty();		//name�p�����^
	//m_CURVE_STYLE_FONT_PATTERN_Ins�ւ̃C���X�^���XID
	m_CURVE_STYLE_FONT_PATTERN_Inst.RemoveAll();
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_CURVE_STYLE_FONTC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�C���X�^���X�h�c�ւ̃|�C���^���w�肵�Đ�������ꍇ
		(�R���X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_CURVE_STYLE_FONTC::SXFMapE_CURVE_STYLE_FONTC(
						SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	�����F	�^				������				���e
			SXFInstanceIDC* IN_InstanceIDManeger	�ݽ�ݽID�Ǘ���޼ު��

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_CURVE_STYLE_FONTC::SXFMapE_CURVE_STYLE_FONTC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
{
//	<������>
	m_EntityName = DEF_CURVE_STYLE_FONT;
//#80 = CURVE_STYLE_FONT('chain_4212', (#81, #82));
//<�G���e�B�e�B�f�[�^>
	m_name.Empty();		//name�p�����^
	//m_CURVE_STYLE_FONT_PATTERN_Ins�ւ̃C���X�^���XID
	m_CURVE_STYLE_FONT_PATTERN_Inst.RemoveAll();
}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_CURVE_STYLE_FONTC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		(�f�X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_CURVE_STYLE_FONTC::~SXFMapE_CURVE_STYLE_FONTC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_CURVE_STYLE_FONTC::~SXFMapE_CURVE_STYLE_FONTC()
{
	for(int i=0;i<m_CURVE_STYLE_FONT_PATTERN_P.GetSize();i++){
		if( m_CURVE_STYLE_FONT_PATTERN_P[i] != NULL)
			delete m_CURVE_STYLE_FONT_PATTERN_P[i];
	}
}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_CURVE_STYLE_FONTC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�G���e�B�e�B�̃p�����^�ݒ�

	�Q�D�C���^�[�t�F�C�X
		int		SXFMapE_CURVE_STYLE_FONTC::SetParameter()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
int SXFMapE_CURVE_STYLE_FONTC::SetParameter()
{
int ircode;
//	<1. �G���e�B�e�B�p�����^�̐ݒ�>

//<�G���e�B�e�B�f�[�^>
//#80 = CURVE_STYLE_FONT('chain_4212', (#81, #82));			
	SXFMapEntAConvC convent(m_EntityArray);
	//<name>
	convent.GetCString(0,m_name);

	//m_CURVE_STYLE_FONT_PATTERN_Ins�ւ̃C���X�^���XID�̐ݒ�
	convent.GetSetInst(1,m_Segment,m_CURVE_STYLE_FONT_PATTERN_Inst);
	if ( m_Segment < 1 ) {
		//�G���e�B�e�B�p�����^�̐��Ɏӂ肪����܂��B
			SXFErrorMsgC::RecordError(
				SXFPARAMS,			//err���b�Z�[�W�ԍ�
				m_EntityName,		//�G���e�B�e�B��
				2,					//�p�����^�̌�
				m_RootID,			//�p�����^
				m_EntityName
				);
		return SXFPARAMS;
	}

//	<2. �Q�Ɛ��CURVE_STYLE_FONT_PATTERN�G���e�B�e�B�p�����^�̐ݒ�>

		//#81 = CURVE_STYLE_FONT_PATTERN(4., 2.);

		//�G���e�B�e�B�C���X�^���X���쐬
		for ( int i=0; i<m_Segment ; i++ ){

			SXFMapE_CURVE_STYLE_FONT_PATTERNC* temp_p =		
				new SXFMapE_CURVE_STYLE_FONT_PATTERNC(m_InstanceIDManager);
			m_CURVE_STYLE_FONT_PATTERN_P.Add(temp_p);
			//�C���X�^���X�h�c���w�肵�G���e�B�e�B�f�[�^��ݒ�
			ircode = temp_p->SetRootID(m_CURVE_STYLE_FONT_PATTERN_Inst[i]);
				if ( ircode < 0 )	return ircode ;
			//�G���e�B�e�B�p�����^�̐ݒ�
			ircode = temp_p->SetParameter();
				if ( ircode < 0 )	return ircode ;
		
		}

	return 0;
}
