/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_PRESENTATION_STYLE_ASSIGNMENTC.cpp						�쐬���F2000.04.17

	�P�D�N���X�T�v
		PRESENTATION_STYLE_ASSIGNMENT���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#include "stdafx.h"
#include "SXFMapE_PRESENTATION_STYLE_ASSIGNMENTC.h"
#include "SXFMapE_CURVE_STYLEC.h"
#include "SXFMapE_SYMBOL_STYLEC.h"
#include "SXFMapE_FILL_AREA_STYLEC.h"
#include "SXFMapE_TEXT_STYLEC.h"
#include "SXFMapEntAConvC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_PRESENTATION_STYLE_ASSIGNMENTC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�f�t�H���g�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_PRESENTATION_STYLE_ASSIGNMENTC::SXFMapE_PRESENTATION_STYLE_ASSIGNMENTC()

	����  �F	�^			������				���e
			�Ȃ�
	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_PRESENTATION_STYLE_ASSIGNMENTC::SXFMapE_PRESENTATION_STYLE_ASSIGNMENTC()
{
//	<������>
	m_EntityName = DEF_PRESENTATION_STYLE_ASSIGNMENT;
//<�G���e�B�e�B�f�[�^>
//#143 = PRESENTATION_STYLE_ASSIGNMENT((#142));
	//	1.styles�ւ̃C���X�^���X�h�c

	//m_STYLE_Ins�ւ̃C���X�^���XID
	m_styles_Inst=NULL;

	//�Z�O�����g��	���G���e�B�e�B�p�����^�ɂ͑��݂��Ȃ��B
	m_Segment=0;

	//styles�ւ̃|�C���^
	m_styles_P = NULL;

	//styles�̎��
	m_stylesKind = 0;
		//	NONSTYLE,		//0:�s��
		//	CURVESTYLE,		//1:
		//	SYMBOLSTYLE,	//2:
		//	FILLSTYLE,		//3:
		//	TEXTSTYLE,		//4:
		//	NULLSTYLE		//5:

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_PRESENTATION_STYLE_ASSIGNMENTC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�C���X�^���X�h�c�ւ̃|�C���^���w�肵�Đ�������ꍇ
		(�R���X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_PRESENTATION_STYLE_ASSIGNMENTC::SXFMapE_PRESENTATION_STYLE_ASSIGNMENTC(
						SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	����  �F	�^				������				���e
				SXFInstanceIDC* IN_InstanceIDManeger	�ݽ�ݽID�Ǘ���޼ު��

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_PRESENTATION_STYLE_ASSIGNMENTC::SXFMapE_PRESENTATION_STYLE_ASSIGNMENTC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
{
//	<������>
	m_EntityName = DEF_PRESENTATION_STYLE_ASSIGNMENT;
//<�G���e�B�e�B�f�[�^>
//<�G���e�B�e�B�f�[�^>
//#143 = PRESENTATION_STYLE_ASSIGNMENT((#142));
	//	1.styles�ւ̃C���X�^���X�h�c

	//m_STYLE_Ins�ւ̃C���X�^���XID
	m_styles_Inst=NULL;

	//�Z�O�����g��	���G���e�B�e�B�p�����^�ɂ͑��݂��Ȃ��B
	m_Segment=0;

	//styles�ւ̃|�C���^
	m_styles_P = NULL;

	//styles�̎��
	m_stylesKind = 0;
		//	NONSTYLE,		//0:�s��
		//	CURVESTYLE,		//1:
		//	SYMBOLSTYLE,	//2:
		//	FILLSTYLE,		//3:
		//	TEXTSTYLE,		//4:
		//	NULLSTYLE		//5:

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_PRESENTATION_STYLE_ASSIGNMENTC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		(�f�X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_PRESENTATION_STYLE_ASSIGNMENTC::~SXFMapE_PRESENTATION_STYLE_ASSIGNMENTC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_PRESENTATION_STYLE_ASSIGNMENTC::~SXFMapE_PRESENTATION_STYLE_ASSIGNMENTC()
{
	if(m_styles_P != NULL){
		if (m_stylesKind==CURVESTYLE)  delete (SXFMapE_CURVE_STYLEC*)m_styles_P;
		if (m_stylesKind==SYMBOLSTYLE) delete (SXFMapE_SYMBOL_STYLEC*)m_styles_P;
		if (m_stylesKind==FILLSTYLE)   delete (SXFMapE_FILL_AREA_STYLEC*)m_styles_P;
		if (m_stylesKind==TEXTSTYLE)   delete (SXFMapE_TEXT_STYLEC*)m_styles_P;
	}
}


/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_PRESENTATION_STYLE_ASSIGNMENTC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�G���e�B�e�B�̃p�����^�ݒ�

	�Q�D�C���^�[�t�F�C�X
		int		SXFMapE_PRESENTATION_STYLE_ASSIGNMENTC::SetParameter()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
int SXFMapE_PRESENTATION_STYLE_ASSIGNMENTC::SetParameter()

{
	int ircode;
	CArray<int,int> IntArray;

//	<1. �G���e�B�e�B�p�����^�̐ݒ�>

//<�G���e�B�e�B�f�[�^>
//#143 = PRESENTATION_STYLE_ASSIGNMENT((#142));
//#143 = PRESENTATION_STYLE_ASSIGNMENT((NULL_STYLE(.NULL.)));


//	1. NULL_STYLE���H �̔��f //////////////////////////////////////////////////////

	if ( (*m_EntityArray)[0].Find(DEF_NULL_STYLE) != -1 ){
		m_stylesKind=NULLSTYLE;
		return 0;
	}

//	2. �G���e�B�e�B�p�����^�̐ݒ�/////////////////////////////////////////////////
	SXFMapEntAConvC convent(m_EntityArray);
	//	1.styles�ւ̃C���X�^���X�h�c
	//m_STYLE_Ins�ւ̃C���X�^���XID
	//�Z�O�����g��	���G���e�B�e�B�p�����^�ɂ͑��݂��Ȃ��B
	convent.GetSetInst(0,m_Segment,IntArray);
	m_styles_Inst=IntArray[0];

	if (m_styles_Inst == 0 ) return -10000;

//	<2. �Q�Ɛ�̃G���e�B�e�B�p�����^�̐ݒ�>
	CString InstEntityName;

	//styles�̃G���e�B�e�B�����擾���A�������N���X���쐬����B
	//PRESENTATION_STYLE_ASSIGNMENT�̎Q�Ƃ���C���X�^���XID��Set�^�����A
	//���[����A�P�̃C���X�^���X�����Q�Ƃ��Ȃ��B
	//���̂��߁A�ŏ��̂P�������f���A�G���e�B�e�B�C���X�^���X���쐬����B

	InstEntityName = SXFMapInstIDC::GetEntityName(m_styles_Inst);

	if (InstEntityName.Find(DEF_CURVE_STYLE) != -1){
		m_stylesKind=CURVESTYLE;
		m_styles_P = new SXFMapE_CURVE_STYLEC(m_InstanceIDManager);

		//�C���X�^���X�h�c���w�肵�G���e�B�e�B�f�[�^��ݒ�
		ircode = ((SXFMapE_CURVE_STYLEC*)m_styles_P)->SetRootID(m_styles_Inst);
			if ( ircode < 0 )	return ircode ;
		//�G���e�B�e�B�p�����^�̐ݒ�
		ircode = ((SXFMapE_CURVE_STYLEC*)m_styles_P)->SetParameter();
			if ( ircode < 0 )	return ircode ;
	}
	else if (InstEntityName.Find(DEF_SYMBOL_STYLE) != -1){
		m_stylesKind=SYMBOLSTYLE;
		m_styles_P = new SXFMapE_SYMBOL_STYLEC(m_InstanceIDManager);

		//�C���X�^���X�h�c���w�肵�G���e�B�e�B�f�[�^��ݒ�
		ircode = ((SXFMapE_SYMBOL_STYLEC*)m_styles_P)->SetRootID(m_styles_Inst);
			if ( ircode < 0 )	return ircode ;
		//�G���e�B�e�B�p�����^�̐ݒ�
		ircode = ((SXFMapE_SYMBOL_STYLEC*)m_styles_P)->SetParameter();
		//����`�V���{���F�R�[�h�t���O���O�̂Ƃ�
		if (ircode == 1){
			m_stylesKind = NONSTYLE;
		}
		if ( ircode < 0 )	return ircode ;
	}
	else if (InstEntityName.Find(DEF_FILL_AREA_STYLE) != -1){
		m_stylesKind=FILLSTYLE;
		m_styles_P = new SXFMapE_FILL_AREA_STYLEC(m_InstanceIDManager);

		//�C���X�^���X�h�c���w�肵�G���e�B�e�B�f�[�^��ݒ�
		ircode = ((SXFMapE_FILL_AREA_STYLEC*)m_styles_P)->SetRootID(m_styles_Inst);
			if ( ircode < 0 )	return ircode ;
		//�G���e�B�e�B�p�����^�̐ݒ�
		ircode = ((SXFMapE_FILL_AREA_STYLEC*)m_styles_P)->SetParameter();
		if ( ircode < 0 )	return ircode ;
	}
	else if (InstEntityName.Find(DEF_SXF_COMPLEX_INSTANCE) != -1||
						InstEntityName.Find(DEF_TEXT_STYLE) != -1){
		m_stylesKind=TEXTSTYLE;
		m_styles_P = new SXFMapE_TEXT_STYLEC(m_InstanceIDManager);
		
		//�C���X�^���X�h�c���w�肵�G���e�B�e�B�f�[�^��ݒ�
		ircode = ((SXFMapE_TEXT_STYLEC*)m_styles_P)->SetRootID(m_styles_Inst);
		if ( ircode < 0 )	return ircode ;
		//�G���e�B�e�B�p�����^�̐ݒ�
		ircode = ((SXFMapE_TEXT_STYLEC*)m_styles_P)->SetParameter();
		if ( ircode < 0 )	return ircode ;

		//�R���v���b�N�X�G���e�B�e�B�Ȃ̂Ōォ��`�F�b�N
		if ( ((SXFMapE_TEXT_STYLEC*)m_styles_P)->m_EntityData.Find(DEF_TEXT_STYLE) == -1 ){
			//err TEXT_STYLE�G���e�B�e�B�ɕs����������
			return -10000;

		}

	}
	else {
	// SCADEC�̑Ώۂł͂Ȃ�ENTITY�ł�
		SXFErrorMsgC::RecordError(
			SXFEXCEPT,			//err���b�Z�[�W�ԍ�
			InstEntityName,		//�G���e�B�e�B��
			2,					//�p�����^�̌�
			m_styles_Inst,	//�p�����^
			InstEntityName
			);
		return SXFEXCEPT;

	}

		//	FILLSTYLE,		//3:
		//	TEXTSTYLE,		//4:
		//	NULLSTYLE		//5:

	return 0;
}
