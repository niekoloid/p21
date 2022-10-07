/**
	All Rights Reserved,(c) JACIC 2001
	SXFLabelMappingC.cpp								�쐬���F2001.06.20

	�P�D�N���X�T�v
	���o������Mapping

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.20			���X��(FQS)			�Ȃ��B

**/
#include "stdafx.h"
#include "SXFLabelMappingC.h"
#include "SXFPart21FileC.h"
#include "SXFTableManagerC.h"
#include "SXFPolylineMappingC.h"
#include "SXFTermSymbolMappingC.h"
#include "SXFTextStringMappingC.h"
#include "SXFD_AggrC.h"
#include "SXFD_StrC.h"
#include "SXFD_InstC.h"
#include "SXFD_TypeC.h"
#include "SXFD_BoolC.h"
#include "SXFE_leader_directed_calloutC.h"
#include "SXFE_presentation_style_assignmentC.h"
#include "SXFE_styled_itemC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFLabelMappingC.cpp								�쐬���F2001.06.20

	�P�D�@�\�T�v
	�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
	void	SXFLabelMappingC::SXFLabelMappingC()
	����:	�^				������				���e
			�Ȃ�				

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.20			���X��(FQS)			�Ȃ��B

**/
SXFLabelMappingC::SXFLabelMappingC()
{
	m_PolylineMapping = NULL;
	m_TextStringMapping = NULL;
	m_TermSymbolMapping = NULL;
	for  (int i = 0; i < 3 ; i ++)
		m_inst[i] = NULL;
	m_ins_line = NULL;
	m_ins_text = NULL;
	m_term_inst = NULL;
	m_aggr1 = NULL;
	m_aggr2 = NULL;
	m_aggr3 = NULL;
	m_bool1 = NULL;
	m_type1 = NULL;
	m_str1 = NULL;
	m_str2 = NULL;

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFLabelMappingC.cpp								�쐬���F2001.06.20

	�P�D�@�\�T�v
	�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
	void	SXFLabelMappingC::SXFLabelMappingC(SXFTableManagerC* IN_TableManager)
	����:	�^					������				���e
			SXFTableManagerC* 	IN_TableManager				

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.20			���X��(FQS)			�Ȃ��B

**/
SXFLabelMappingC::SXFLabelMappingC(SXFTableManagerC* IN_TableManager)
{
	m_TableManager = IN_TableManager;
	m_PolylineMapping = NULL;
	m_TextStringMapping = NULL;
	m_TermSymbolMapping = NULL;
	for  (int i = 0; i < 3 ; i ++)
		m_inst[i] = NULL;
	m_ins_line = NULL;
	m_ins_text = NULL;
	m_term_inst = NULL;
	m_aggr1 = NULL;
	m_aggr2 = NULL;
	m_aggr3 = NULL;
	m_bool1 = NULL;
	m_type1 = NULL;
	m_str1 = NULL;
	m_str2 = NULL;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFLabelMappingC.cpp								�쐬���F2001.06.20

	�P�D�@�\�T�v
	�f�X�g���N�^

	�Q�D�C���^�[�t�F�[�X
	void	SXFLabelMappingC::~SXFLabelMappingC()
	����:	�^				������				���e
			�Ȃ�				

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.20			���X��(FQS)			�Ȃ��B

**/
SXFLabelMappingC::~SXFLabelMappingC()
{
	if (m_PolylineMapping != NULL)
		delete m_PolylineMapping;
	if (m_TextStringMapping != NULL)
		delete m_TextStringMapping;
	if (m_TermSymbolMapping != NULL)
		delete m_TermSymbolMapping;
	if (m_bool1 != NULL)
		delete m_bool1;
	SXFInstanceC::InitDeleteMap();
	if (m_inst[0] != NULL) {
		SXFInstanceC::AddDeleted(m_inst[0]);
		delete m_inst[0];
	}
	if (m_inst[2] != NULL)
		delete m_inst[2];
	SXFInstanceC::EndDeleteMap();
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFLabelMappingC.cpp								�쐬���F2001.06.20

	�P�D�@�\�T�v
	���o������Mapping

	�Q�D�C���^�[�t�F�[�X
	BOOL MappingStruct(Label_Struct IN_Struct)
	����:	�^				������				���e
			Label_Struct	IN_Struct			�\����

	���A�l	���펞�FTRUE
			�ُ펞�FFALSE

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.20			���X��(FQS)			�Ȃ��B

**/
BOOL SXFLabelMappingC::MappingStruct(Label_Struct *IN_Struct,int IN_AssemType)
{
	Polyline_Struct Polyline_Str;
	Polyline_Str.layer = IN_Struct->layer;
	Polyline_Str.color = IN_Struct->color;
	Polyline_Str.type = IN_Struct->type;
	Polyline_Str.line_width = IN_Struct->line_width;
	Polyline_Str.number = IN_Struct->vertex_number;
	for (int i = 0; i < Polyline_Str.number;i++){
		Polyline_Str.x.Add(IN_Struct->vertex_x[i]);
		Polyline_Str.y.Add(IN_Struct->vertex_y[i]);
	}
	//�ܐ���Mapping
	m_PolylineMapping = new SXFPolylineMappingC(m_TableManager,1);
	m_PolylineMapping->MappingStruct(&Polyline_Str);

	//�ܐ���STYLED_ITEM..�̂h�c
	//DRAUGHTING_CALLOUT�Ɏg�p
	//�܂�TEMINATOR_SYMBOL�ɂ��g�p
	int PolylineID = m_PolylineMapping->GetID();
	m_ins_line = new SXFD_InstC(PolylineID);
	m_aggr1 = new SXFD_AggrC();
	m_aggr1->AddElem(m_ins_line);
	//������Mapping
	if (IN_Struct->flg != 0){
		Text_Struct TextString_str;
		TextString_str.layer = IN_Struct->layer;
		TextString_str.color = IN_Struct->color;
		TextString_str.font = IN_Struct->font;
		//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
		//strcpy(TextString_str.str,IN_Struct->str);
		strcpy_s(TextString_str.str,_countof(TextString_str.str),IN_Struct->str);
		TextString_str.text_x = IN_Struct->text_x;
		TextString_str.text_y = IN_Struct->text_y;
		TextString_str.height = IN_Struct->height;
		TextString_str.width = IN_Struct->width;
		TextString_str.spc   = IN_Struct->spc;
		TextString_str.angle = IN_Struct->angle;
		TextString_str.slant = IN_Struct->slant;
		TextString_str.b_pnt = IN_Struct->b_pnt;
		TextString_str.direct = IN_Struct->direct;
		m_TextStringMapping = new SXFTextStringMappingC(m_TableManager,1);
		m_TextStringMapping->MappingStruct(TextString_str);
		int Text_ID = m_TextStringMapping->GetID();
		m_ins_text = new SXFD_InstC(Text_ID);
		m_aggr1->AddElem(m_ins_text) ;
	}

	//����Mapping
	TermSymbol_Struct TermSymbol_str;
	TermSymbol_str.color = IN_Struct->color;
	TermSymbol_str.code = IN_Struct->arr_code;
	TermSymbol_str.flag = 1;
	TermSymbol_str.x = IN_Struct->vertex_x[0];
	TermSymbol_str.y = IN_Struct->vertex_y[0];
	TermSymbol_str.scale =IN_Struct->arr_r;
	TermSymbol_str.target_ID = PolylineID;//�ܐ���STYLED_ITEM�̂h�c
	TermSymbol_str.direction_x = IN_Struct->vertex_x[1]-IN_Struct->vertex_x[0];
	TermSymbol_str.direction_y = IN_Struct->vertex_y[1]-IN_Struct->vertex_y[0];
	m_TermSymbolMapping = new SXFTermSymbolMappingC(m_TableManager,0,0);//����1�����ALabel
	m_TermSymbolMapping->MappingStructDim(TermSymbol_str);
	int termID= m_TermSymbolMapping->GetID();
	m_term_inst = new SXFD_InstC(termID);
	m_aggr1->AddElem(m_term_inst);

	m_str1 = new SXFD_StrC(" ");
	m_inst[0] = new SXFE_leader_directed_calloutC(m_str1,m_aggr1);

	//�A�Z���u���v�f�i�p���A�����}�`�j����̎Q�Ƃ���h�c�̐ݒ�
	//�p���̏ꍇ
	//DRAWING_SHEET_REVISION => STYLED_ITEM => LEADER_DIRECTED_CALLOUT()
	if (IN_AssemType == 1){
		m_bool1 = new SXFD_BoolC(DEF_NULL);
		m_type1 = new SXFD_TypeC(DEF_NULL_STYLE);
		m_type1->SetNext(m_bool1);
		m_aggr2 = new SXFD_AggrC() ;
		m_aggr2->AddElem(m_type1);
		m_inst[1] = new SXFE_presentation_style_assignmentC(m_aggr2);

		m_str2 = new SXFD_StrC(" ");
		m_aggr3 = new SXFD_AggrC();
		m_aggr3->AddElem(m_inst[1]);
		m_inst[2] = new SXFE_styled_itemC(m_str2,m_aggr3,m_inst[0]);
		//�A�Z���u���v�f���Q�Ƃ���ID�Ƃ��āASTYLED_ITEM��ID��o�^
		m_ID = m_inst[2]->GetInsID();//�A�Z���u���v�f�����h�c
	}
	//�����}�`�̏ꍇ
	//DRAUGHTING_SUBFIGURE_REPRESENTATION => LEADER_DIRECTED_CALLOUT()
	else{
		//�A�Z���u���v�f���Q�Ƃ���ID�Ƃ��āALEADER_DIRECTED_CALLOUT��ID��o�^
		m_ID = m_inst[0]->GetInsID();//�A�Z���u���v�f�����h�c
	}
	return TRUE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFLabelMappingC.cpp								�쐬���F2001.06.20

	�P�D�@�\�T�v
	�C���X�^���X�̃t�@�C���ւ̏o��

	�Q�D�C���^�[�t�F�[�X
	BOOL WriteAP202(SXFPart21FileC *IN_File)
	����:	�^					������			���e
			SXFPart21FileC*		IN_File			�t�@�C���I�u�W�F�N�g�̃A�h���X

	 ���A�l	���펞�FTRUE
			�ُ펞�FFALSE

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.20			���X��(FQS)			�Ȃ��B

**/
BOOL SXFLabelMappingC::WriteAP202(SXFPart21FileC *IN_File)
{
	if (m_PolylineMapping != NULL)
		m_PolylineMapping->WriteAP202(IN_File);
	if (m_TextStringMapping != NULL)
		m_TextStringMapping->WriteAP202(IN_File);
	if (m_TermSymbolMapping != NULL)
		m_TermSymbolMapping->WriteAP202(IN_File);
	if (m_inst[0] != NULL)
		m_inst[0]->WriteP21(IN_File);
	if (m_inst[2] != NULL)
		m_inst[2]->WriteP21(IN_File);
	return TRUE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFLabelMappingC.cpp								�쐬���F2001.06.20

	�P�D�@�\�T�v
	�C���X�^���XID��ԋp����

	�Q�D�C���^�[�t�F�[�X
	int GetID()
	����:	�^					������				���e
			�Ȃ�
	
	 ���A�l	�C���X�^���XID

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.20			���X��(FQS)			�Ȃ��B

**/
int SXFLabelMappingC::GetID()
{
	return m_ID;
}
