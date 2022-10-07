/**
	All Rights Reserved,(c) JACIC 2001
	SXFDiameterDimMappingC.cpp								�쐬���F2001.06.18

	�P�D�N���X�T�v
	���a���@�t�B�[�`���̃}�b�s���O

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.18			���X��(FQS)			�Ȃ��B

**/

#include "stdafx.h"
#include <math.h>
#include "SXFDiameterDimMappingC.h"
#include "SXFTableManagerC.h"
#include "SXFPart21FileC.h"
#include "SXFLineMappingC.h"
#include "SXFTermSymbolMappingC.h"
#include "SXFTextStringMappingC.h"
#include "SXFD_AggrC.h"
#include "SXFD_StrC.h"
#include "SXFD_InstC.h"
#include "SXFD_TypeC.h"
#include "SXFD_BoolC.h"
#include "SXFE_structured_dimension_calloutC.h"
#include "SXFE_diameter_dimensionC.h"
#include "SXFE_dimension_callout_relationshipC.h"
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
	SXFDiameterDimMappingC.cpp								�쐬���F2001.06.18

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void SXFDiameterDimMappingC::SXFDiameterDimMappingC()
	����:	�^								������				���e
			�Ȃ�					

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.18			���X��(FQS)			�Ȃ��B

**/
SXFDiameterDimMappingC::SXFDiameterDimMappingC()
{
	m_ID1 = -1;
	m_ID2 = -1;
	m_LineMapping = NULL;
	m_TextStringMapping = NULL;
	m_TermSymbolMapping1 = NULL;
	m_TermSymbolMapping2 = NULL;
	for  (int i = 0; i < 6 ; i ++)
		m_inst[i] = NULL;
	m_ins_line = NULL;
	m_ins_text = NULL;
	m_term1_inst = NULL;
	m_term2_inst = NULL;
	m_text_inst = NULL;
	m_aggr1 = NULL;
	m_aggr2 = NULL;
	m_aggr3 = NULL;
	m_aggr4 = NULL;
	m_aggr5 = NULL;
	m_bool1 = NULL;
	m_type1 = NULL;
	m_str1 = NULL;
	m_str2 = NULL;
	m_str3 = NULL;
	m_str4 = NULL;
	m_str5 = NULL;
	m_str6 = NULL;

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFDiameterDimMappingC.cpp								�쐬���F2001.06.18

	�P�D�@�\�T�v
	�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
	void	SXFDiameterDimMappingC(SXFTableManagerC* IN_TableManager)
	����:	�^								������				���e
			SXFTableManagerC*				IN_TableManager		��`ð��يǗ���޼ު��	
	

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.18			���X��(FQS)			�Ȃ��B

**/
SXFDiameterDimMappingC::SXFDiameterDimMappingC(SXFTableManagerC* IN_TableManager)
{
	m_ID1 = -1;
	m_ID2 = -1;
	m_TableManager = IN_TableManager;
	m_TableManager = IN_TableManager;
	m_LineMapping = NULL;
	m_TextStringMapping = NULL;
	m_TermSymbolMapping1 = NULL;
	m_TermSymbolMapping2 = NULL;
	for  (int i = 0; i < 6 ; i ++)
		m_inst[i] = NULL;
	m_ins_line = NULL;
	m_ins_text = NULL;
	m_term1_inst = NULL;
	m_term2_inst = NULL;
	m_text_inst = NULL;
	m_aggr1 = NULL;
	m_aggr2 = NULL;
	m_aggr3 = NULL;
	m_aggr4 = NULL;
	m_aggr5 = NULL;
	m_bool1 = NULL;
	m_type1 = NULL;
	m_str1 = NULL;
	m_str2 = NULL;
	m_str3 = NULL;
	m_str4 = NULL;
	m_str5 = NULL;
	m_str6 = NULL;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFDiameterDimMappingC.cpp								�쐬���F2001.06.18

	�P�D�@�\�T�v
		�f�X�g���N�^

	�Q�D�C���^�[�t�F�[�X
	void	SXFDiameterDimMappingC::~SXFDiameterDimMappingC()
	����:	�^								������				���e
			�Ȃ�					

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.18			���X��(FQS)			�Ȃ��B

**/
SXFDiameterDimMappingC::~SXFDiameterDimMappingC()
{
	if (m_bool1 != NULL)
		delete m_bool1;
	if (m_TextStringMapping != NULL)
		delete m_TextStringMapping;
	if (m_LineMapping != NULL)
		delete m_LineMapping;
	if (m_TermSymbolMapping1 != NULL)
		delete m_TermSymbolMapping1;
	if (m_TermSymbolMapping2 != NULL)
		delete m_TermSymbolMapping2;

/*	if (m_inst[2] != NULL)
		delete m_inst[2];
	if (m_inst[5] != NULL)
		delete m_inst[5];*/
	
	SXFInstanceC::InitDeleteMap();
	if(m_inst[2] != NULL) {
		SXFInstanceC::AddDeleted(m_inst[2]);
		delete	m_inst[2];
	}
	if(m_inst[4] != NULL)
		delete	m_inst[4];
	if(m_inst[5] != NULL)
		delete	m_inst[5];
	SXFInstanceC::EndDeleteMap();
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFDiameterDimMappingC.cpp								�쐬���F2001.06.18

	�P�D�@�\�T�v
		�\���̂̃}�b�s���O

	�Q�D�C���^�[�t�F�[�X
	BOOL	MappingStruct(DiameterDim_Struct IN_Struct,int IN_AssemType)
	����:	�^								������				���e
			DiameterDim_Struct				IN_Struct		�\����
			int								IN_AssemType	�����،^

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.18			���X��(FQS)			�Ȃ��B

**/
BOOL SXFDiameterDimMappingC::MappingStruct(DiameterDim_Struct IN_Struct,int IN_AssemType)
{
	Line_Struct Line_str;
	Line_str.layer = IN_Struct.layer;
	Line_str.color = IN_Struct.color;
	Line_str.type = IN_Struct.type;
	Line_str.line_width = IN_Struct.line_width;
	Line_str.start_x = IN_Struct.sun_x1;
	Line_str.start_y = IN_Struct.sun_y1;
	Line_str.end_x = IN_Struct.sun_x2;
	Line_str.end_y = IN_Struct.sun_y2;
	//���@����Mapping
	m_LineMapping = new SXFLineMappingC(m_TableManager,1);
	m_LineMapping->MappingStruct(Line_str);
	//
	//���@����STYLED_ITEM..�̂h�c
	//DRAUGHTING_CALLOUT�Ɏg�p
	//�܂�TEMINATOR_SYMBOL�ɂ��g�p
	int LineID = m_LineMapping->GetID();
	m_ins_line = new SXFD_InstC(LineID);
	m_aggr1 = new SXFD_AggrC();
	m_aggr1->AddElem(m_ins_line);

	//������Mapping
	Text_Struct TextString_str;
	TextString_str.layer = IN_Struct.layer;
	TextString_str.color = IN_Struct.color;
	TextString_str.font = IN_Struct.font;
	//���@�l�L���t���O��0�������ꍇ
	//�������" "�Ƃ���B
	if (IN_Struct.flg == 0){
		//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
		//strcpy(TextString_str.str,"");
		strcpy_s(TextString_str.str,_countof(TextString_str.str),"");
	}
	else
		//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
		//strcpy(TextString_str.str,IN_Struct.str);
		strcpy_s(TextString_str.str,_countof(TextString_str.str),IN_Struct.str);
		TextString_str.text_x = IN_Struct.text_x;
		TextString_str.text_y = IN_Struct.text_y;
		TextString_str.height = IN_Struct.height;
		TextString_str.width = IN_Struct.width;
		TextString_str.spc   = IN_Struct.spc;
		TextString_str.angle = IN_Struct.angle;
		TextString_str.slant = IN_Struct.slant;
		TextString_str.b_pnt = IN_Struct.b_pnt;
		TextString_str.direct = IN_Struct.direct;
		m_TextStringMapping = new SXFTextStringMappingC(m_TableManager,1);
		m_TextStringMapping->MappingStruct(TextString_str);
		int Text_ID = m_TextStringMapping->GetID();
		m_text_inst = new SXFD_InstC(Text_ID);
		m_aggr1->AddElem(m_text_inst);
	//
	//���1��Mapping
	TermSymbol_Struct TermSymbol_str1;
	TermSymbol_str1.color = IN_Struct.color;
	TermSymbol_str1.code = IN_Struct.arr1_code1;
	TermSymbol_str1.flag = IN_Struct.arr1_code2;
	TermSymbol_str1.x = IN_Struct.arr1_x;
	TermSymbol_str1.y = IN_Struct.arr1_y;
	TermSymbol_str1.scale =IN_Struct.arr1_r;
	TermSymbol_str1.target_ID = LineID;//���@����STYLED_ITEM�̂h�c
	//
	TermSymbol_Struct TermSymbol_str2;
	TermSymbol_str2.color = IN_Struct.color;
	TermSymbol_str2.code = IN_Struct.arr2_code1;
	TermSymbol_str2.flag = IN_Struct.arr2_code2;
	TermSymbol_str2.x = IN_Struct.arr2_x;
	TermSymbol_str2.y = IN_Struct.arr2_y;
	TermSymbol_str2.scale =IN_Struct.arr2_r;
	TermSymbol_str2.target_ID = LineID;//���@����STYLED_ITEM�̂h�c
	//DIRECTION�̌v�Z
	if (IN_Struct.arr1_code2 != 0 || IN_Struct.arr2_code2 != 0){
		if (!CalcArrowDir(IN_Struct,TermSymbol_str1.direction_x,TermSymbol_str1.direction_y,TermSymbol_str2.direction_x,TermSymbol_str2.direction_y))
			return FALSE;
	}
	//Mapping
	int colorID;
	if (IN_Struct.arr1_code2 != 0){
		TermSymbol_str1.flag = 1;
		m_TermSymbolMapping1 = new SXFTermSymbolMappingC(m_TableManager,1,1);//�P�Ԗڂ̖��,Dimension
		m_TermSymbolMapping1->MappingStructDim(TermSymbol_str1);
		m_TermSymbolMapping1->GetTermID(colorID);
		int term1ID= m_TermSymbolMapping1->GetID();
		m_term1_inst = new SXFD_InstC(term1ID);
		m_aggr1->AddElem(m_term1_inst);
	}
	if (IN_Struct.arr2_code2 != 0){
		m_TermSymbolMapping2 = new SXFTermSymbolMappingC(m_TableManager,2,1);//2�Ԗڂ̖��,Dimension
		if (TermSymbol_str1.flag == 1){
			TermSymbol_str2.flag = 2;//2��󂪂���
			m_TermSymbolMapping2->SetTermID(colorID);
		}
		else
			TermSymbol_str2.flag = 1;//1����
		m_TermSymbolMapping2->MappingStructDim(TermSymbol_str2);
		int term2ID= m_TermSymbolMapping2->GetID();
		m_term2_inst = new SXFD_InstC(term2ID);
		m_aggr1->AddElem(m_term2_inst);
	}
	//
	m_str1 = new SXFD_StrC(" ");
	m_ins_text = new SXFD_InstC(Text_ID);
	m_aggr2 = new SXFD_AggrC() ;
	m_aggr2->AddElem(m_ins_text) ;
	m_inst[0] = new SXFE_structured_dimension_calloutC(m_str1,m_aggr2);
	//
	m_str2 = new SXFD_StrC(" ");
	m_inst[1] = new SXFE_diameter_dimensionC(m_str2,m_aggr1);
	//
	m_str3 = new SXFD_StrC("primary");
	m_str4 = new SXFD_StrC(" ");
	m_inst[2] = new SXFE_dimension_callout_relationshipC
			(m_str3,m_str4,m_inst[1],m_inst[0]); 

	//�A�Z���u���v�f�i�p���A�����}�`�j����̎Q�Ƃ���h�c�̐ݒ�
	//�p���̏ꍇ
	//DRAWING_SHEET_REVISION => STYLED_ITEM => STRUCTURED_DIMENSION_CALLOUT()
	//                       => STYLED_ITEM => DIAMETER_DIMENSION()
	if (IN_AssemType == 1){
		m_bool1 = new SXFD_BoolC(DEF_NULL);
		m_type1 = new SXFD_TypeC(DEF_NULL_STYLE);
		m_type1->SetNext(m_bool1);
		m_aggr3 = new SXFD_AggrC() ;
		m_aggr3->AddElem(m_type1);
		m_inst[3] = new SXFE_presentation_style_assignmentC(m_aggr3);
		//
		m_str5 = new SXFD_StrC(" ");
		m_aggr4 = new SXFD_AggrC();
		m_aggr4->AddElem(m_inst[3]);
		m_inst[4] = new SXFE_styled_itemC(m_str5,m_aggr4,m_inst[0]);
		//�A�Z���u���v�f���Q�Ƃ���ID�Ƃ��āASTYLED_ITEM��ID��o�^
		m_ID1 = m_inst[4]->GetInsID();//�A�Z���u���v�f�����h�c
		//
		m_str6 = new SXFD_StrC(" ");
		m_aggr5 = new SXFD_AggrC();
		m_aggr5->AddElem(m_inst[3]);
		m_inst[5] = new SXFE_styled_itemC(m_str6,m_aggr5,m_inst[1]);
		//�A�Z���u���v�f���Q�Ƃ���ID�Ƃ��āASTYLED_ITEM��ID��o�^
		m_ID2 =m_inst[5]->GetInsID();//�A�Z���u���v�f�����h�c
		//
	}
	//
	//�����}�`�̏ꍇ
	//DRAUGHTING_SUBFIGURE_REPRESENTATION => STRUCTURED_DIMENSION_CALLOUT()
	//                                    => DIAMETER_DIMENSION()
	else{
		//�A�Z���u���v�f���Q�Ƃ���ID�Ƃ��āASTRUCTURED_DIMENSION_CALLOUT��ID��o�^
		m_ID1 = m_inst[0]->GetInsID();//�A�Z���u���v�f�����h�c
		//�A�Z���u���v�f���Q�Ƃ���ID�Ƃ��āADIAMETER_DIMENSION��ID��o�^
		m_ID2 = m_inst[1]->GetInsID();//�A�Z���u���v�f�����h�c;
	}

	return TRUE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFDiameterDimMappingC.cpp								�쐬���F2001.06.18

	�P�D�@�\�T�v
		�C���X�^���X�̃t�@�C���ւ̏o��

	�Q�D�C���^�[�t�F�[�X
	BOOL	WriteAP202(SXFPart21FileC *IN_File)
	����:	�^								������				���e
			SXFPart21FileC					*IN_File		̧�ٵ�޼ު��	

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.18			���X��(FQS)			�Ȃ��B

**/
BOOL SXFDiameterDimMappingC::WriteAP202(SXFPart21FileC *IN_File)
{
	if (m_LineMapping != NULL)
		m_LineMapping->WriteAP202(IN_File);
	if (m_TextStringMapping != NULL)
		m_TextStringMapping->WriteAP202(IN_File);
	if (m_TermSymbolMapping1 != NULL)
		m_TermSymbolMapping1->WriteAP202(IN_File);
	if (m_TermSymbolMapping2 != NULL)
		m_TermSymbolMapping2->WriteAP202(IN_File);
	if (m_inst[2] != NULL)
		m_inst[2]->WriteP21(IN_File);
	if (m_inst[4] != NULL)
		m_inst[4]->WriteP21(IN_File);
	if (m_inst[5] != NULL)
		m_inst[5]->WriteP21(IN_File);

	return TRUE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFDiameterDimMappingC.cpp								�쐬���F2001.06.18

	�P�D�@�\�T�v
		�C���X�^���XID�̕ԋp

	�Q�D�C���^�[�t�F�[�X
	void	GetID(int &OUT_ID1,int &OUT_ID2)
	����:	�^						������				���e
			int						&OUT_ID1	�A�Z���u���v�f�̃C���X�^���XID
			int						&OUT_ID2	�A�Z���u���v�f�̃C���X�^���XID
		
	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.18			���X��(FQS)			�Ȃ��B

**/
void SXFDiameterDimMappingC::GetID(int &OUT_ID1,int &OUT_ID2)
{
	OUT_ID1 = m_ID1;
	OUT_ID2 = m_ID2;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFDiameterDimMappingC.cpp								�쐬���F2001.06.18

	�P�D�@�\�T�v
		DIRECTION�̌v�Z

	�Q�D�C���^�[�t�F�[�X
	BOOL	CalcArrowDir(DiameterDim_Struct IN_Struct, 
						 double &OUT_Arrow1_x, 
						 double &OUT_Arrow1_y, 
						 double &OUT_Arrow2_x, 
						 double &OUT_Arrow2_y)
	����:	�^								������				���e
			DiameterDim_Struct				IN_Struct		�\����
			double				OUT_Arrow1_x	���P��DIRECTION X
			double				OUT_Arrow1_y	���P��DIRECTION Y
			double				OUT_Arrow2_x	���Q��DIRECTION X
			double				OUT_Arrow2_y	���Q��DIRECTION Y
	
	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.18			���X��(FQS)			�Ȃ��B

**/
BOOL SXFDiameterDimMappingC::CalcArrowDir(DiameterDim_Struct IN_Struct, double &OUT_Arrow1_x, double &OUT_Arrow1_y, double &OUT_Arrow2_x, double &OUT_Arrow2_y)
{
	//���2�̏ꍇ
	if ((IN_Struct.arr1_code2 != 0) && (IN_Struct.arr2_code2 != 0)){
		//���P�Ɛ��@���n�_�̒���
		double Length1 = fabs(sqrt(pow((IN_Struct.arr1_x - IN_Struct.sun_x1),2) + pow((IN_Struct.arr1_y - IN_Struct.sun_y1),2)));
		//���Q�Ɛ��@���n�_�̒���
		double Length2 = fabs(sqrt(pow((IN_Struct.arr2_x - IN_Struct.sun_x1),2) + pow((IN_Struct.arr2_y - IN_Struct.sun_y1),2)));
		//���@���̒���
		double Line_Length = fabs(sqrt(pow(IN_Struct.sun_x2 - IN_Struct.sun_x1, 2)+pow(IN_Struct.sun_y2 - IN_Struct.sun_y1, 2)));
		//���@���̕����x�N�g��
		double Line_Dir_x = (IN_Struct.sun_x2 - IN_Struct.sun_x1) / Line_Length;
		double Line_Dir_y = (IN_Struct.sun_y2 - IN_Struct.sun_y1) / Line_Length;
		//���P�����@���̎n�_�ɋ߂��Ƃ�
		if (Length1 <= Length2){
			//���P�̕����x�N�g����ݒ肷��
			//���P�̓��O�R�[�h���Q�i�������j�̂Ƃ��A���@���̕����x�N�g���Ɠ������ɐݒ肷��
			if(IN_Struct.arr1_code2 == 2){
				OUT_Arrow1_x = Line_Dir_x;
				OUT_Arrow1_y = Line_Dir_y;
			}
			//���P�̓��O�R�[�h���P�i�O�����j�̂Ƃ��A���@���̕����x�N�g���Ɣ��Ε����ɐݒ肷��
			else if(IN_Struct.arr1_code2 == 1){
				OUT_Arrow1_x = - Line_Dir_x;
				OUT_Arrow1_y = - Line_Dir_y;
			}
			else{
				return FALSE;
			}

			//���Q�̕����x�N�g����ݒ肷��
			//���Q�̓��O�R�[�h���Q�i�������j�̂Ƃ��A���@���̕����x�N�g���Ɣ��Ε����ɐݒ肷��
			if(IN_Struct.arr2_code2 == 2){
				OUT_Arrow2_x = -Line_Dir_x;
				OUT_Arrow2_y = -Line_Dir_y;
			}
			//���Q�̓��O�R�[�h���P�i�O�����j�̂Ƃ��A���@���̕����x�N�g���Ɠ������ɐݒ肷��
			else if(IN_Struct.arr2_code2 == 1){
				OUT_Arrow2_x = Line_Dir_x;
				OUT_Arrow2_y = Line_Dir_y;
			}
			else{
				return FALSE;
			}
		}
		//���Q�����@���n�_�ɋ߂��Ƃ�
		else {
			//���Q�̕����x�N�g����ݒ肷��
			//���Q�̓��O�R�[�h���Q�i�������j�̂Ƃ��A���@���̕����x�N�g���Ɠ������ɐݒ肷��
			if(IN_Struct.arr2_code2 == 2){
				OUT_Arrow2_x = Line_Dir_x;
				OUT_Arrow2_y = Line_Dir_y;
			}
			//���Q�̓��O�R�[�h���P�i�O�����j�̂Ƃ��A���@���̕����x�N�g���Ɣ��Ε����ɐݒ肷��
			else if(IN_Struct.arr2_code2 == 1){
				OUT_Arrow2_x = -Line_Dir_x;
				OUT_Arrow2_y = -Line_Dir_y;
			}
			else{
				return FALSE;
			}
			//���P�̕����x�N�g����ݒ肷��
			//���P�̓��O�R�[�h���Q�i�������j�̂Ƃ��A���@���̕����x�N�g���Ɣ��Ε����ɐݒ肷��
			if(IN_Struct.arr1_code2 == 2){
				OUT_Arrow1_x = -Line_Dir_x;
				OUT_Arrow1_y = -Line_Dir_y;
			}
			//���P�̓��O�R�[�h���P�i�O�����j�̂Ƃ��A���@���̕����x�N�g���Ɠ������ɐݒ肷��
			else if(IN_Struct.arr1_code2 == 1){
				OUT_Arrow1_x = Line_Dir_x;
				OUT_Arrow1_y = Line_Dir_y;
			}
			else{
				return FALSE;
			}
		}
	}
	//��󂪈�̏ꍇ(���1�̏ꍇ�j
	else if ((IN_Struct.arr1_code2 != 0) && (IN_Struct.arr2_code2 == 0)){
		//���@���̕����x�N�g�����v�Z����
		//���@���̎n�_����I�_�܂ł̒���
		double L1 = fabs(sqrt(pow(IN_Struct.sun_x2 - IN_Struct.sun_x1, 2)+pow(IN_Struct.sun_y2 - IN_Struct.sun_y1, 2)));
		double Dim_x = (IN_Struct.sun_x2 - IN_Struct.sun_x1) / L1;
		double Dim_y = (IN_Struct.sun_y2 - IN_Struct.sun_y1) / L1;
		//���P�̕����x�N�g����ݒ肷��
		//���P�̓��O�R�[�h���Q�i�������j�̂Ƃ��A���@���̕����x�N�g���Ɠ������ɐݒ肷��
		if(IN_Struct.arr1_code2 == 2){
			OUT_Arrow1_x = Dim_x;
			OUT_Arrow1_y = Dim_y;
		}
		//���P�̓��O�R�[�h���P�i�O�����j�̂Ƃ��A���@���̕����x�N�g���Ɣ��Ε����ɐݒ肷��
		else if(IN_Struct.arr1_code2 == 1){
			OUT_Arrow1_x = -Dim_x;
			OUT_Arrow1_y = -Dim_y;
		}
		else
			return FALSE;
	}
	//��󂪈�̏ꍇ�i���Q�̏ꍇ�j
	else if ((IN_Struct.arr1_code2 == 0) && (IN_Struct.arr2_code2 != 0)){
		//���@���̕����x�N�g�����v�Z����
		//���@���̎n�_����I�_�܂ł̒���
		double L1 = fabs(sqrt(pow(IN_Struct.sun_x2 - IN_Struct.sun_x1, 2)+pow(IN_Struct.sun_y2 - IN_Struct.sun_y1, 2)));
		double Dim_x = (IN_Struct.sun_x2 - IN_Struct.sun_x1) / L1;
		double Dim_y = (IN_Struct.sun_y2 - IN_Struct.sun_y1) / L1;
		//���Q�̕����x�N�g����ݒ肷��
		//���Q�̓��O�R�[�h���Q�i�������j�̂Ƃ��A���@���̕����x�N�g���Ɣ��Ε����ɐݒ肷��
		if(IN_Struct.arr2_code2 == 2){
			OUT_Arrow2_x = -Dim_x;
			OUT_Arrow2_y = -Dim_y;
		}
		//���Q�̓��O�R�[�h���P�i�O�����j�̂Ƃ��A���@���̕����x�N�g���Ɠ������ɐݒ肷��
		else if(IN_Struct.arr2_code2 == 1){
			OUT_Arrow2_x = Dim_x;
			OUT_Arrow2_y = Dim_y;
		}
		else 
			return FALSE;
	}
	else 
		FALSE;
	return TRUE;
}

