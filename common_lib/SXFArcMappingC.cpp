/**
	All Rights Reserved,(c) JACIC 2001
	SXFArcMappingC.cpp								�쐬���F2001.06.16

	�P�D�N���X�T�v
	�~�ʃt�B�[�`����Mapping

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.16			���X��(FQS)			�Ȃ��B

**/

#include "stdafx.h"
#include <math.h>
#include "SXFArcMappingC.h"
#include "SXFPart21FileC.h"
#include "SXFTableManagerC.h"
#include "SXFD_InstC.h"
#include "SXFD_RealC.h"
#include "SXFD_StrC.h"
#include "SXFD_AggrC.h"
#include "SXFD_EnumC.h"
#include "SXFD_BoolC.h"
#include "SXFD_TypeC.h"
#include "SXFE_cartesian_pointC.h"
#include "SXFE_axis2_placement_2dC.h"
#include "SXFE_circleC.h"
#include "SXFE_curve_styleC.h"
#include "SXFE_trimmed_curveC.h"
#include "SXFE_presentation_style_assignmentC.h"
#include "SXFE_styled_itemC.h"
#include "SXFE_composite_curve_segmentC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFArcMappingC.cpp								�쐬���F2001.06.16

	�P�D�@�\�T�v
	�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void	SXFArcMappingC::SXFArcMappingC()

	����	�F	�^		������				���e
		�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.16			���X��(FQS)			�Ȃ��B

**/
SXFArcMappingC::SXFArcMappingC()
{
	for (int i = 0; i < 7; i++){
		m_inst[i] = NULL;
	}
	for (i = 0; i < 5; i++){
		m_inst_curve[i] = NULL;
	}
	m_ins1 = NULL;
	m_ins2 = NULL;
	m_ins3 = NULL;
	m_aggr1 = NULL;
	m_aggr2 = NULL;
	m_aggr3 = NULL;
	m_aggr4 = NULL;
	m_aggr5 = NULL;
	m_str1 = NULL;
	m_str2 = NULL;
	m_str3 = NULL;
	m_str4 = NULL;
	m_str5 = NULL;
	m_str6 = NULL;
	m_str7 = NULL;
	m_real1 = NULL;
	m_real2 = NULL;
	m_real3 = NULL;
	m_real4 = NULL;
	m_real5 = NULL;
	m_bool1 = NULL;
	m_bool2 = NULL;
	m_enum1 = NULL;
	m_enum2 = NULL;
	m_slist = NULL;
	m_type1 = NULL;
	m_type2 = NULL;

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFArcMappingC.cpp								�쐬���F2001.06.16

	�P�D�@�\�T�v
	�f�X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void	SXFArcMappingC::~SXFArcMappingC()
		
	����	�F	�^		������				���e
		�Ȃ�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.16			���X��(FQS)			�Ȃ��B

**/
SXFArcMappingC::~SXFArcMappingC()
{
	if (m_inst[6] != NULL)
		delete m_inst[6];
	if (m_inst_curve[4] != NULL)
		delete m_inst_curve[4];
	if (m_real4 != NULL)
		delete m_real4;
	if (m_real5 != NULL)
		delete m_real5;
	m_ID = -1;
	m_assign_ID = -1;
	m_DimFlag = -1;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFArcMappingC.cpp								�쐬���F2001.06.16

	�P�D�@�\�T�v
	�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
		void	SXFArcMappingC::SXFArcMappingC(SXFTableManagerC *IN_TableManager,int IN_DimFlag)

	�����F	�^					������				���e
			SXFTableManagerC 	*IN_TableManager	��`ð��يǗ���޼ު��
			int 				IN_DimFlag			Dim or Label

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.16			���X��(FQS)			�Ȃ��B

**/
SXFArcMappingC::SXFArcMappingC(SXFTableManagerC *IN_TableManager,int IN_DimFlag)
{
	m_ID = -1;
	m_assign_ID = -1;
	m_TableManager = IN_TableManager;
	m_DimFlag = IN_DimFlag;
	for (int i = 0; i < 7; i++){
		m_inst[i] = NULL;
	}
	for (i = 0; i < 5; i++){
		m_inst_curve[i] = NULL;
	}
	m_ins1 = NULL;
	m_ins2 = NULL;
	m_ins3 = NULL;
	m_aggr1 = NULL;
	m_aggr2 = NULL;
	m_aggr3 = NULL;
	m_aggr4 = NULL;
	m_aggr5 = NULL;
	m_str1 = NULL;
	m_str2 = NULL;
	m_str3 = NULL;
	m_str4 = NULL;
	m_str5 = NULL;
	m_str6 = NULL;
	m_str7 = NULL;
	m_real1 = NULL;
	m_real2 = NULL;
	m_real3 = NULL;
	m_real4 = NULL;
	m_real5 = NULL;
	m_bool1 = NULL;
	m_bool2 = NULL;
	m_enum1 = NULL;
	m_enum2 = NULL;
	m_slist = NULL;
	m_type1 = NULL;
	m_type2 = NULL;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFArcMappingC.cpp								�쐬���F2001.06.16

	�P�D�@�\�T�v
	�~�ʂ�Mapping

	�Q�D�C���^�[�t�F�[�X
	BOOL MappingStruct(Arc_Struct IN_Struct)
	����:	�^					������				���e
			Arc_Struct			IN_Struct			�\����

	���A�l	���펞�FTRUE
			�ُ펞�FFALSE

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.16			���X��(FQS)			�Ȃ��B

**/
BOOL SXFArcMappingC::MappingStruct(Arc_Struct IN_Struct)
{
	m_str1 = new SXFD_StrC(" ");
	m_real1 = new SXFD_RealC(IN_Struct.center_x);
	m_real2 = new SXFD_RealC(IN_Struct.center_y);
	m_aggr1 = new SXFD_AggrC() ;
	m_aggr1->AddElem(m_real1) ;
	m_aggr1->AddElem(m_real2) ;
	m_inst[0] = new SXFE_cartesian_pointC(m_str1,m_aggr1) ;
	
	m_str2 = new SXFD_StrC(" ");
	m_str3 = new SXFD_StrC(DEF_DOLLAR);
	m_inst[1] = new SXFE_axis2_placement_2dC(m_str2, m_inst[0], m_str3);
	
	m_str4 = new SXFD_StrC(" ");
	m_real3 = new SXFD_RealC(IN_Struct.radius);
	m_inst[2] = new SXFE_circleC(m_str4, m_inst[1], m_real3);
	
	m_str5 = new SXFD_StrC(" ");
	m_real4 = new SXFD_AngleC(IN_Struct.start_angle* acos(-1.)/180.0);
	m_type1 = new SXFD_TypeC(DEF_PARAMETER_VALUE);
	m_type1->SetNext(m_real4);
	m_aggr2 = new SXFD_AggrC();
	m_aggr2->AddElem(m_type1);
	m_real5 = new SXFD_AngleC(IN_Struct.end_angle*acos(-1.)/180.0);
	m_type2 = new SXFD_TypeC(DEF_PARAMETER_VALUE);
	m_type2->SetNext(m_real5);
	m_aggr3 = new SXFD_AggrC();
	m_aggr3->AddElem(m_type2);
	if(IN_Struct.direction == 0){
		m_bool1 = new SXFD_BoolC(TRUE);
	}
	else 
		m_bool1 = new SXFD_BoolC(FALSE);
	m_enum1 = new SXFD_EnumC(DEF_PARAMETER) ;
	m_inst[3] = new SXFE_trimmed_curveC
					(m_str5,
					 m_inst[2],
					 m_aggr2,
					 m_aggr3,
					 m_bool1,
					 m_enum1) ;
	
	m_str6 = new SXFD_StrC(" ");
	int table_type;
	if (IN_Struct.type < 17)
		table_type = 4;
	else
		table_type = 5;
	m_ins1 = new SXFD_InstC(m_TableManager->GetID(table_type,IN_Struct.type));
	m_ins2 = new SXFD_InstC(m_TableManager->GetID(6,IN_Struct.line_width));
	if (IN_Struct.color < 17)
		table_type = 2;
	else
		table_type = 3;
		m_ins3 = new SXFD_InstC(m_TableManager->GetID(table_type,IN_Struct.color));
		m_inst[4] = new SXFE_curve_styleC(m_str6,m_ins1,m_ins2,m_ins3) ;
	
		m_aggr4 = new SXFD_AggrC() ;
		m_aggr4->AddElem( m_inst[4] ) ;
		m_inst[5] = new SXFE_presentation_style_assignmentC(m_aggr4) ;
		m_assign_ID = m_inst[5]->GetInsID();
	
		m_str7 = new SXFD_StrC(" ");
		m_slist = new CStringList();
		m_slist->AddTail(DEF_ANNOTATION_CURVE_OCCURRENCE);
		m_slist->AddTail(DEF_ANNOTATION_OCCURRENCE);
	if (m_DimFlag)
		m_slist->AddTail(DEF_DIMENSION_CURVE);
		m_slist->AddTail(DEF_DRAUGHTING_ANNOTATION_OCCURRENCE);
		m_slist->AddTail(DEF_GEOMETRIC_REPRESENTATION_ITEM);
		m_aggr5 = new SXFD_AggrC() ;
		m_aggr5->AddElem( m_inst[5] ) ;
		m_inst[6] = new SXFE_styled_itemC(m_str7,m_aggr5,m_inst[3],m_slist);
		m_ID = m_inst[6]->GetInsID();
		m_TableManager->SetLayerElement(IN_Struct.layer,m_ID);
		return TRUE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFArcMappingC.cpp								�쐬���F2001.06.16

	�P�D�@�\�T�v
	�~�ʃC���X�^���X�̃t�@�C���ւ̏o��

	�Q�D�C���^�[�t�F�[�X
	BOOL WriteAP202(SXFPart21FileC *IN_File)
	����:	�^					������				���e
			SXFPart21FileC*		IN_File				�t�@�C���I�u�W�F�N�g�̃A�h���X
	
	 ���A�l	���펞�FTRUE
			�ُ펞�FFALSE

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.16			���X��(FQS)			�Ȃ��B

**/
BOOL SXFArcMappingC::WriteAP202(SXFPart21FileC *IN_File)
{
	m_inst[6]->WriteP21(IN_File);
	return TRUE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFArcMappingC.cpp								�쐬���F2001.06.16

	�P�D�@�\�T�v
	�C���X�^���XID�̕ԋp

	�Q�D�C���^�[�t�F�[�X
	int GetID()
	����:	�^					������				���e
			�Ȃ�
	
	 ���A�l	�C���X�^���XID

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.16			���X��(FQS)			�Ȃ��B

**/
int SXFArcMappingC::GetID()
{
	return m_ID;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFArcMappingC.cpp								�쐬���F2001.06.16

	�P�D�@�\�T�v
	�����Ȑ���̗v�f�̂Ƃ��̉~�ʂ�Mapping

	�Q�D�C���^�[�t�F�[�X
	BOOL MappingStructCurve(Arc_Struct IN_Struct,double &INOUT_PointX,double &INOUT_PointY,int &INOUT_PointN)
	����:	�^					������				���e
			Arc_Struct			IN_Struct			�\����
			double&				INOUT_PointX		�n�b�`���O�����̓_X
			double&				INOUT_PointY		�n�b�`���O�����̓_Y
			int&				INOUT_PointN		�n�b�`���O�����̓_�v�Z�p���W�̌�


	���A�l	���펞�FTRUE
			�ُ펞�FFALSE

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.16			���X��(FQS)			�Ȃ��B

**/
BOOL SXFArcMappingC::MappingStructCurve(Arc_Struct IN_Struct,double &INOUT_PointX,double &INOUT_PointY,int &INOUT_PointN)
{
	m_str1 = new SXFD_StrC(" ");
	m_real1 = new SXFD_RealC(IN_Struct.center_x);
	m_real2 = new SXFD_RealC(IN_Struct.center_y);
	m_aggr1 = new SXFD_AggrC() ;
	m_aggr1->AddElem(m_real1) ;
	m_aggr1->AddElem(m_real2) ;
	m_inst_curve[0] = new SXFE_cartesian_pointC(m_str1,m_aggr1) ;
	
	m_str2 = new SXFD_StrC(" ");
	m_str3 = new SXFD_StrC(DEF_DOLLAR);
	m_inst_curve[1] = new SXFE_axis2_placement_2dC(m_str2, m_inst_curve[0], m_str3);
	
	m_str4 = new SXFD_StrC(" ");
	m_real3 = new SXFD_RealC(IN_Struct.radius);
	m_inst_curve[2] = new SXFE_circleC(m_str4, m_inst_curve[1], m_real3);
	
	m_str5 = new SXFD_StrC(" ");
	m_real4 = new SXFD_AngleC(IN_Struct.start_angle* acos(-1.)/180.0);
	m_type1 = new SXFD_TypeC(DEF_PARAMETER_VALUE);
	m_type1->SetNext(m_real4);
	m_aggr2 = new SXFD_AggrC();
	m_aggr2->AddElem(m_type1);
	m_real5 = new SXFD_AngleC(IN_Struct.end_angle*acos(-1.)/180.0);
	m_type2 = new SXFD_TypeC(DEF_PARAMETER_VALUE);
	m_type2->SetNext(m_real5);
	m_aggr3 = new SXFD_AggrC();
	m_aggr3->AddElem(m_type2);
	if(IN_Struct.direction == 0){
		m_bool1 = new SXFD_BoolC(TRUE);
	}
	else 
		m_bool1 = new SXFD_BoolC(FALSE);
		m_enum1 = new SXFD_EnumC(DEF_PARAMETER) ;
		m_inst_curve[3] = new SXFE_trimmed_curveC
					(m_str5,
					 m_inst_curve[2],
					 m_aggr2,
					 m_aggr3,
					 m_bool1,
					 m_enum1) ;
		m_enum2 = new SXFD_EnumC(DEF_CONTINUOUS);
		m_bool2 = new SXFD_BoolC(DEF_TRUE);
		m_inst_curve[4] = new SXFE_composite_curve_segmentC(m_enum2,m_bool2,m_inst_curve[3]);
		m_ID = m_inst_curve[4]->GetInsID();

	//�n�b�`���O�����̓_�̌v�Z
	INOUT_PointX = IN_Struct.center_x + IN_Struct.radius * cos(IN_Struct.start_angle*acos(-1.)/180.0)
					+ IN_Struct.center_x +IN_Struct.radius * cos(IN_Struct.end_angle*acos(-1.)/180.0);
	INOUT_PointY = IN_Struct.center_y + IN_Struct.radius * sin(IN_Struct.start_angle*acos(-1.)/180.0)
					+ IN_Struct.center_y +IN_Struct.radius * sin(IN_Struct.end_angle*acos(-1.)/180.0);
	INOUT_PointN += 2;

	return TRUE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFArcMappingC.cpp								�쐬���F2001.06.16

	�P�D�@�\�T�v
	�����Ȑ���̉~�ʃC���X�^���X�̃t�@�C���ւ̏o��

	�Q�D�C���^�[�t�F�[�X
	BOOL WriteAP202Curve(SXFPart21FileC *IN_File)
	����:	�^					������				���e
			SXFPart21FileC*		IN_File				�t�@�C���I�u�W�F�N�g�̃A�h���X
	
	 ���A�l	���펞�FTRUE
			�ُ펞�FFALSE

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.16			���X��(FQS)			�Ȃ��B

**/
BOOL SXFArcMappingC::WriteAP202Curve(SXFPart21FileC* IN_File)
{
	m_inst_curve[4]->WriteP21(IN_File);
	return TRUE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFArcMappingC.cpp								�쐬���F2001.06.16

	�P�D�@�\�T�v
	PRESENTATION_STYLED_ASSIGNMENT�̃C���X�^���XID��ԋp

	�Q�D�C���^�[�t�F�[�X
	int GetAssignID()
	����:	�^					������				���e
			�Ȃ�
	
	 ���A�l	PRESENTATION_STYLED_ASSIGNMENT�̃C���X�^���XID

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.16			���X��(FQS)			�Ȃ��B

**/
int SXFArcMappingC::GetAssignID()
{
	return m_assign_ID;
}
