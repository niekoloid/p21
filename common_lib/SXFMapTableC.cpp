/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapTableC.cpp						�쐬���F2000.04.21

	�P�D�N���X�T�v
		AP202�G���e�B�e�B����t�B�[�`���ւ̃}�b�s���O���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.21	

**/
#include "stdafx.h"
#include "SXFMapEntityBaseC.h"
#include "SXFInstanceIDC.h"
#include "SXFComInfoC.h"
#include "SXFTableKindE.h"
#include "SXFMapEntAConvC.h"

#include "SXFLayerC.h"
#include "SXFPreDefFontC.h"
#include "SXFUserDefFontC.h"
#include "SXFPreDefColorC.h"
#include "SXFUserDefColorC.h"
#include "SXFWidthC.h"
#include "SXFTextFontC.h"

#include "SXFMapE_PRESENTATION_LAYER_USAGEC.h"
#include "SXFMapE_PRESENTATION_LAYER_ASSIGNMENTC.h"
#include "SXFMapE_DRAUGHTING_PRE_DEFINED_CURVE_FONTC.h"
#include "SXFMapE_CURVE_STYLE_FONTC.h"
#include "SXFMapE_CURVE_STYLE_FONT_PATTERNC.h"
#include "SXFMapE_DRAUGHTING_PRE_DEFINED_COLOURC.h"
#include "SXFMapE_COLOUR_RGBC.h"
#include "SXFMapE_EXTERNAL_SOURCEC.h"
#include "SXFMapE_EXTERNAL_DEFINED_TEXT_FONTC.h"
#include "SXFMapE_LENGTH_MEASURE_WITH_UNITC.h"
#include "SXFTableManagerC.h"//ID_218_000706_ins

#include "SXFMapTableC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapTableC.cpp						�쐬���F2000.04.21

	�P�D�@�\�T�v
		�f�t�H���g�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapTableC::SXFMapTableC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.21	
**/
SXFMapTableC::SXFMapTableC()
{
//
//	<������>
//
	m_Type	= 0; 
	m_BodyP = NULL ;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapTableC.cpp						�쐬���F2000.04.21

	�P�D�@�\�T�v
		(�R���X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapTableC::SXFMapTableC(
						SXFInstanceIDC* IN_InstanceIDManeger,
						SXFComInfoC* IN_ComInfoC,
						SXFTableManagerC* IN_TableManager)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	����  �F	�^				������				���e
			SXFInstanceIDC* 	IN_InstanceIDManeger	�ݽ�ݽID�Ǘ���޼ު��
			SXFComInfoC* 		IN_ComInfoC				���ʏ��Ǘ���޼ު��
			SXFTableManagerC*	IN_TableManager			��`ð��يǗ���޼ު��

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.21	
**/

//	<�C���X�^���X�h�c�ւ̃|�C���^��o�^����������>
SXFMapTableC::SXFMapTableC(
		SXFInstanceIDC* IN_InstanceIDManeger,
		SXFComInfoC* IN_ComInfoC,
		SXFTableManagerC* IN_TableManager)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
{
	m_Type	= 0; 
	m_BodyP = NULL ;
	m_ComInfoC = IN_ComInfoC;
	m_TableManager = IN_TableManager;
}

//	<���[�g�h�c�ƃt�B�[�`����ʂ��w�肵�Đ�������ꍇ>
SXFMapTableC::SXFMapTableC(
			int	IN_RootID, 
			int	IN_FeatureKind)
{
//
//	<������>
//
	m_Type	= 0; 
	m_BodyP = NULL ;
	m_RootID= IN_RootID;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapTableC.cpp						�쐬���F2000.04.21

	�P�D�@�\�T�v
		(�f�X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapTableC::~SXFMapTableC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.21	
**/
SXFMapTableC::~SXFMapTableC()
{

/*	E_LAYER = 1,	//1:���C��
	E_PRECOLOR,		//2:����`�F
	E_USERCOLOR,	//3:���[�U��`�F
	E_PREFONT,		//4:����`����
	E_USERFONT,		//5:���[�U��`����
	E_WIDTH,		//6:����
	E_TEXTFONT		//7:�����t�H���g*/

	if (m_BodyP!=NULL){

		if (m_Type == E_LAYER) {
			 delete (SXFLayerC*)m_BodyP;	//1:���C��
		}
		else if (m_Type == E_PRECOLOR) {
			 delete (SXFPreDefColorC*)m_BodyP; 	//2:����`�F
		}
		else if (m_Type == E_USERCOLOR) {
			 delete (SXFUserDefColorC*)m_BodyP;	//3:���[�U��`�F
		}
		else if (m_Type ==  E_PREFONT) {
		 	 delete (SXFPreDefFontC*)m_BodyP;	//4:����`����
		}
		else if (m_Type == E_USERFONT){
			 delete (SXFUserDefFontC*)m_BodyP;	//5:���[�U��`����
		}
		else if (m_Type == E_WIDTH){
			 delete (SXFWidthC*)m_BodyP;	//6:����
		}
		else if (m_Type == E_TEXTFONT){
			 delete (SXFTextFontC*)m_BodyP;	//7:�����t�H���g
		}

	}
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapTableC.cpp						�쐬���F2000.04.21

	�P�D�@�\�T�v
		��`�e�[�u���v�f�t�B�[�`���\���̂̍쐬

	�Q�D�C���^�[�t�F�C�X
		int		SXFMapTableC::SetFeatureParameter(
					int		OUT_type,
					void*	OUT_Class)


	����  �F	�^			������				���e
				int		OUT_type,	//��`�e�[�u�����	
									1:���C��
									2:����`�F
									3:���[�U��`�F
									4:����`����
									5:���[�U��`����
									6:����
									7:�����t�H���g
				void*	OUT_Class)	//��`�e�[�u���t�B�[�`���N���X�ւ̃|�C���^


	���A�l�F��`�e�[�u�����

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.21	
**/

int	SXFMapTableC::	SetFeatureParameter(
					int&	OUT_Type,	//��`�e�[�u�����	
					LPVOID&	OUT_Class)	//��`�e�[�u���t�B�[�`���N���X�ւ̃|�C���^

{
//
//	<������>
//
	int ircode;
	OUT_Type = 0;
	OUT_Class = NULL;

//	<�G���e�B�e�B�̔���>
	//////	<���C��> ///////////////////////////////////////////////////////
	if (m_EntityName == DEF_PRESENTATION_LAYER_USAGE) {
		//#1421 = PRESENTATION_LAYER_USAGE(#1420, #1412);
		//#1420 = PRESENTATION_LAYER_ASSIGNMENT('Layer', 'all elements', (#140, #180, 
		//#200, #240, #280, #320, #360, #461, #460, #521, #520, #598, #1340, #1380));
		SXFMapE_PRESENTATION_LAYER_USAGEC e_layer(m_InstanceIDManager);
		//�C���X�^���X�h�c���w�肵�G���e�B�e�B�f�[�^��ݒ�
		ircode = e_layer.SetEntityArraydata(m_RootID,m_EntityName,m_EntityArray);
		if ( ircode < 0 )	return ircode ;
		//�G���e�B�e�B�p�����^�̐ݒ�
		ircode = e_layer.SetParameter();
		if ( ircode < 0 )	return ircode ;

		//�t�B�[�`���f�[�^�̐ݒ�	
		SXFLayerC* layer = new SXFLayerC;
		//���C����
		layer->m_Name = e_layer.m_Assignment_p->m_Name;
//	MOD(S)	�`���[�j���O�Ή�	K.Naono	03.07.04
//		for ( int i=0;i<(e_layer.m_Assignment_p->m_AssignedItems.GetSize());i++){
//			m_LayerElements.Add(e_layer.m_Assignment_p->m_AssignedItems[i]);
//		}
		INT_PTR	nCount = e_layer.m_Assignment_p->m_AssignedItems.GetSize() ;
		m_LayerElements.SetSize(nCount) ;
		for(int i = 0; i < nCount; i++) {
			m_LayerElements[i] = e_layer.m_Assignment_p->m_AssignedItems[i] ;
		}
//	MOD(E)	�`���[�j���O�Ή�	K.Naono	03.07.04

		//  �\���E��\���t���O�̐ݒ� /////////////////////////////////////////
		layer->m_LfFlag = !(m_TableManager->GetInvisibilityFlag(e_layer.m_Assignment_Inst));
		//////////////////////////////////////////////////////////////////////
		//��`�e�[�u�����
		m_Type = E_LAYER;		//=1
		//�N���X�ւ̃|�C���^��Ԃ��B
		m_BodyP = layer;
	}

	//////	<����`�F> ///////////////////////////////////////////////////////	
	else if (m_EntityName == DEF_DRAUGHTING_PRE_DEFINED_COLOUR) {
		//#40 = DRAUGHTING_PRE_DEFINED_COLOUR('black');

		//�G���e�B�e�B�C���X�^���X���쐬
		SXFMapE_DRAUGHTING_PRE_DEFINED_COLOURC e_predefcolor(m_InstanceIDManager);
		//�C���X�^���X�h�c���w�肵�G���e�B�e�B�f�[�^��ݒ�
		ircode = e_predefcolor.SetEntityArraydata(m_RootID,m_EntityName,m_EntityArray);
		if ( ircode < 0 )	return ircode ;
		//�G���e�B�e�B�p�����^�̐ݒ�
		ircode = e_predefcolor.SetParameter();
		if ( ircode < 0 )	return ircode ;

		//�t�B�[�`���f�[�^�̐ݒ�	
		SXFPreDefColorC*	predefcolor = new SXFPreDefColorC;
		//����`�F��
		if (!predefcolor->SetName(e_predefcolor.m_name)){
			SXFErrorMsgC::RecordError(SXFNOTPRECOLOUR,DEF_PREDEFINED_COLOUR,1,e_predefcolor.m_name);
			return SXFNOTPRECOLOUR;
		}
		//��`�e�[�u�����
		m_Type  = E_PRECOLOR;		//=2
		//�N���X�ւ̃|�C���^��Ԃ��B		===>>>> ����ł����́H�H�H�H
		m_BodyP = predefcolor;
	}
	//////	<���[�U��`�F���͊���`�F> ///////////////////////////////////////////////////////
	else if (m_EntityName == DEF_COLOUR_RGB) {
		//#140 = COLOUR_RGB('colour_rgb1', 0.12, 0.56, 1.);
		//#140 = COLOUR_RGB('$$SXF_', 0.12, 0.56, 1.);

		//�G���e�B�e�B�C���X�^���X���쐬
		SXFMapE_COLOUR_RGBC e_userdefcolor(m_InstanceIDManager);
		//�C���X�^���X�h�c���w�肵�G���e�B�e�B�f�[�^��ݒ�
		ircode = e_userdefcolor.SetEntityArraydata(m_RootID,m_EntityName,m_EntityArray);
		if ( ircode < 0 )	return ircode ;
		//�G���e�B�e�B�p�����^�̐ݒ�
		ircode = e_userdefcolor.SetParameter();
		if ( ircode < 0 )	return ircode ;

		//�t�B�[�`���f�[�^�̐ݒ�	
		//SCADEC�̊���`�F�����[�U��`�F���̔���

		//////SCADEC����`�F�̏ꍇ ///////////////////////////////////////////////////
		if ( e_userdefcolor.m_name.Left(6) == "$$SXF_"){
			SXFPreDefColorC*	predefcolor = new  SXFPreDefColorC;
			//����`�F��
			CString colorname;
			colorname = e_userdefcolor.m_name;
			colorname.TrimLeft("$$SXF_");
			if (!predefcolor->SetName(colorname)) {
				SXFErrorMsgC::RecordError(SXFNOTPRECOLOUR,DEF_PREDEFINED_COLOUR,1,e_userdefcolor.m_name);
				return SXFNOTPRECOLOUR;
			}

			//��`�e�[�u�����
			m_Type  = E_PRECOLOR;		//=2
			//�N���X�ւ̃|�C���^��Ԃ��B
			m_BodyP = predefcolor;
		}
		//////���[�U��`�F�̏ꍇ ///////////////////////////////////////////////////
		else{
			SXFUserDefColorC* userdefcolor = new SXFUserDefColorC;
			userdefcolor->R = (int)(e_userdefcolor.m_R * 255. + 0.5);
			userdefcolor->G = (int)(e_userdefcolor.m_G * 255. + 0.5);
			userdefcolor->B = (int)(e_userdefcolor.m_B * 255. + 0.5);

			//��`�e�[�u�����
			m_Type  = E_USERCOLOR;	//=3
			//�N���X�ւ̃|�C���^��Ԃ��B
			m_BodyP = userdefcolor;
		}
	}

	//////	<����`����> ///////////////////////////////////////////////////////
	else if (m_EntityName == DEF_DRAUGHTING_PRE_DEFINED_CURVE_FONT) {

		//#20 = DRAUGHTING_PRE_DEFINED_CURVE_FONT('continuous');
		//�G���e�B�e�B�C���X�^���X���쐬
		SXFMapE_DRAUGHTING_PRE_DEFINED_CURVE_FONTC e_predeffont(m_InstanceIDManager);
		//�C���X�^���X�h�c���w�肵�G���e�B�e�B�f�[�^��ݒ�
		ircode = e_predeffont.SetEntityArraydata(m_RootID,m_EntityName,m_EntityArray);
		if ( ircode < 0 )	return ircode ;
		//�G���e�B�e�B�p�����^�̐ݒ�
		ircode = e_predeffont.SetParameter();
		if ( ircode < 0 )	return ircode ;

		//�t�B�[�`���f�[�^�̐ݒ�	
		SXFPreDefFontC*	predeffont = new SXFPreDefFontC;
		//����`���햼
		if (!predeffont->SetName( e_predeffont.m_name) ){
			SXFErrorMsgC::RecordError(SXFNOTPRETYPE,DEF_PREDEFINED_LINETYPE,1,e_predeffont.m_name);
			return SXFNOTPRETYPE;
		}

		//��`�e�[�u�����
		m_Type  = E_PREFONT;	//=2
		//�N���X�ւ̃|�C���^��Ԃ��B
		m_BodyP = predeffont;
	}

	//////	<���[�U��`����> ///////////////////////////////////////////////////////
	else if (m_EntityName == DEF_CURVE_STYLE_FONT) {

		//#80 = CURVE_STYLE_FONT('chain_4212', (#81, #82));
		//�G���e�B�e�B�C���X�^���X���쐬
		SXFMapE_CURVE_STYLE_FONTC e_stylefont(m_InstanceIDManager);
		//�C���X�^���X�h�c���w�肵�G���e�B�e�B�f�[�^��ݒ�
		ircode = e_stylefont.SetEntityArraydata(m_RootID,m_EntityName,m_EntityArray);
		if ( ircode < 0 )	return ircode ;
		//�G���e�B�e�B�p�����^�̐ݒ�
		ircode = e_stylefont.SetParameter();
		if ( ircode < 0 )	return ircode ;

		//�t�B�[�`���f�[�^�̐ݒ�	
		SXFUserDefFontC* userdeffont = new SXFUserDefFontC;
		//	<�t�H���g��>
		userdeffont->m_Name = e_stylefont.m_name;
		userdeffont->m_Segment = e_stylefont.m_Segment*2;

		//#82 = CURVE_STYLE_FONT_PATTERN(1., 2.);
		//CURVE_STYLE_FONT�̎Q�Ɛ�CURVE_STYLE_FONT_PATTERN��
		//�\���������A��\����������ݒ肷��B
		for (int i=0 ;i<e_stylefont.m_Segment;i++ ){
			userdeffont->m_Pitch.Add(e_stylefont.m_CURVE_STYLE_FONT_PATTERN_P[i]->m_visi);
			userdeffont->m_Pitch.Add(e_stylefont.m_CURVE_STYLE_FONT_PATTERN_P[i]->m_invisi);
		}
		//��`�e�[�u�����
		m_Type  = E_USERFONT;		//=5
		//�N���X�ւ̃|�C���^��Ԃ��B
		m_BodyP = userdeffont;
	}

	//////	<����> ///////////////////////////////////////////////////////
	else if (m_EntityName == DEF_LENGTH_MEASURE_WITH_UNIT) {
		//#60 = LENGTH_MEASURE_WITH_UNIT(POSITIVE_LENGTH_MEASURE(0.5), #62);
		//�G���e�B�e�B�C���X�^���X���쐬
		SXFMapE_LENGTH_MEASURE_WITH_UNITC e_width(m_InstanceIDManager);
		//�C���X�^���X�h�c���w�肵�G���e�B�e�B�f�[�^��ݒ�
		ircode = e_width.SetEntityArraydata(m_RootID,m_EntityName,m_EntityArray);
			if ( ircode < 0 )	return ircode ;
		//�G���e�B�e�B�p�����^�̐ݒ�
		ircode = e_width.SetParameter();
			if ( ircode < 0 )	return ircode ;
		//�t�B�[�`���f�[�^�̐ݒ�	
		SXFWidthC* width = new SXFWidthC;
		width->m_Width = e_width.m_Width;
		//��`�e�[�u�����
		m_Type  = E_WIDTH;		//=6
		//�N���X�ւ̃|�C���^��Ԃ��B
		m_BodyP = width;

	}
	//////	<�����t�H���g> ///////////////////////////////////////////////////////
	else if (m_EntityName == DEF_EXTERNALLY_DEFINED_TEXT_FONT) {
		//#81 = EXTERNAL_SOURCE(IDENTIFIER('Helvetica8'));
		//#80 = EXTERNALLY_DEFINED_TEXT_FONT(IDENTIFIER('Helvetica8'), #81);
		//�G���e�B�e�B�C���X�^���X���쐬
		SXFMapE_EXTERNAL_DEFINED_TEXT_FONTC e_textfont(m_InstanceIDManager);
		//�C���X�^���X�h�c���w�肵�G���e�B�e�B�f�[�^��ݒ�
		ircode = e_textfont.SetEntityArraydata(m_RootID,m_EntityName,m_EntityArray);
			if ( ircode < 0 )	return ircode ;
		//�G���e�B�e�B�p�����^�̐ݒ�
		ircode = e_textfont.SetParameter();
			if ( ircode < 0 )	return ircode ;
		//�t�B�[�`���f�[�^�̐ݒ�	
		SXFTextFontC* textfont = new SXFTextFontC;

		//	�e�L�X�g�t�H���g�̃x�[�X���C���䗦�̍폜
		
		textfont->m_Name = e_textfont.m_Name;
		//��`�e�[�u�����
		m_Type  = E_TEXTFONT;		//=7
		//�N���X�ւ̃|�C���^��Ԃ��B
		m_BodyP = textfont;

	}
	//	<�G���[>
	else{
		//err
		return -10000;
	}

	//��`�e�[�u�����
	OUT_Type  = m_Type;	
	//�N���X�ւ̃|�C���^��Ԃ��B
	OUT_Class = m_BodyP;

	return 0;
}
