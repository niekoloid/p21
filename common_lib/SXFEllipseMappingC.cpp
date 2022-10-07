/**
	All Rights Reserved,(c) JACIC 2001
	SXFEllipseMappingC.cpp								�쐬���F2000.4.15

	�P�D�N���X�T�v
	�ȉ~��Mapping

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.15			�{��(FQS)			�Ȃ��B

**/
#include "stdafx.h"
#include <math.h>
#include "SXFEllipseMappingC.h"
#include "SXFPart21FileC.h"
#include "SXFTableManagerC.h"
#include "SXFD_InstC.h"
#include "SXFD_RealC.h"
#include "SXFD_StrC.h"
#include "SXFD_AggrC.h"
#include "SXFE_directionC.h"
#include "SXFE_cartesian_pointC.h"
#include "SXFE_axis2_placement_2dC.h"
#include "SXFE_ellipseC.h"
#include "SXFE_curve_styleC.h"
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
	SXFEllipseMappingC.cpp								�쐬���F2000.4.15

	�P�D�@�\�T�v
	�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
	void	SXFEllipseMappingC::SXFEllipseMappingC()
	����:	�^				������				���e
			�Ȃ�				

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.15			�{��(FQS)			�Ȃ��B

**/
SXFEllipseMappingC::SXFEllipseMappingC()
{
	m_TableManager = NULL;
	m_ID = -1;
	for (int i = 0; i < 7; i++){
		m_inst[i] = NULL;
	}
	m_ins1 = NULL;
	m_ins2 = NULL;
	m_ins3 = NULL;
	m_aggr1 = NULL;
	m_aggr2 = NULL;
	m_aggr3 = NULL;
	m_str1 = NULL;
	m_str2 = NULL;
	m_str3 = NULL;
	m_str4 = NULL;
	m_str5 = NULL;
	m_str6 = NULL;
	m_real1 = NULL;
	m_real2 = NULL;
	m_real3 = NULL;
	m_real4 = NULL;
	m_real5 = NULL;
	m_real6 = NULL;
	m_slist = NULL;

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFEllipseMappingC.cpp								�쐬���F2000.4.15

	�P�D�@�\�T�v
	�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
	void	SXFEllipseMappingC(SXFTableManagerC* IN_TableManager)
	����:	�^					������				���e
			SXFTableManagerC* 	IN_TableManager		��`ð��يǗ���޼ު��		

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.15			�{��(FQS)			�Ȃ��B

**/
SXFEllipseMappingC::SXFEllipseMappingC(SXFTableManagerC* IN_TableManager)
{
	m_TableManager = IN_TableManager;
	m_ID = -1;
	for (int i = 0; i < 7; i++){
		m_inst[i] = NULL;
	}
	m_ins1 = NULL;
	m_ins2 = NULL;
	m_ins3 = NULL;
	m_aggr1 = NULL;
	m_aggr2 = NULL;
	m_aggr3 = NULL;
	m_str1 = NULL;
	m_str2 = NULL;
	m_str3 = NULL;
	m_str4 = NULL;
	m_str5 = NULL;
	m_str6 = NULL;
	m_real1 = NULL;
	m_real2 = NULL;
	m_real3 = NULL;
	m_real4 = NULL;
	m_real5 = NULL;
	m_real6 = NULL;
	m_slist = NULL;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFEllipseMappingC.cpp								�쐬���F2000.4.15

	�P�D�@�\�T�v
		�f�X�g���N�^

	�Q�D�C���^�[�t�F�[�X
	void	SXFEllipseMappingC::~SXFEllipseMappingC()
	����:	�^				������				���e
			�Ȃ�				

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.15			�{��(FQS)			�Ȃ��B

**/
SXFEllipseMappingC::~SXFEllipseMappingC()
{
	if (m_inst[6] != NULL)
		delete m_inst[6];
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFEllipseMappingC.cpp								�쐬���F2000.4.15

	�P�D�@�\�T�v
	���~�t�B�[�`����Mapping

	�Q�D�C���^�[�t�F�[�X
	BOOL MappingStruct(Ellipse_Struct IN_Struct)
	����:	�^					������				���e
			Ellipse_Struct		IN_Struct			�\����
	 ���A�l	���펞�FTRUE
			�ُ펞�FFALSE

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.15			�{��(FQS)			�Ȃ��B

**/
BOOL SXFEllipseMappingC::MappingStruct(Ellipse_Struct IN_Struct)
{
	double	m_direction_x = cos(acos(-1.)*IN_Struct.rotation_angle/180.0);
	double	m_direction_y = sin(acos(-1.)*IN_Struct.rotation_angle/180.0);
	m_str1 = new SXFD_StrC("");
	m_real1 = new SXFD_AngleC(m_direction_x);
	m_real2 = new SXFD_AngleC(m_direction_y);
	m_aggr1 = new SXFD_AggrC() ;
	m_aggr1->AddElem(m_real1) ;
	m_aggr1->AddElem(m_real2) ;
	m_inst[0] = new SXFE_directionC(m_str1,m_aggr1) ;

	m_str2 = new SXFD_StrC(" ");
	m_real3 = new SXFD_RealC(IN_Struct.center_x);
	m_real4 = new SXFD_RealC(IN_Struct.center_y);
	m_aggr2 = new SXFD_AggrC() ;
	m_aggr2->AddElem( m_real3) ;
	m_aggr2->AddElem( m_real4 ) ;
	m_inst[1] = new SXFE_cartesian_pointC(m_str2,m_aggr2) ;

	m_str3 = new SXFD_StrC(" ");
	m_inst[2] = new SXFE_axis2_placement_2dC(m_str3, m_inst[1], m_inst[0]);

	m_str4 = new SXFD_StrC(" ");
	m_real5 = new SXFD_RealC(IN_Struct.radius_x);
	m_real6 = new SXFD_RealC(IN_Struct.radius_y);
	m_inst[3] = new SXFE_ellipseC(m_str4,m_inst[2],m_real5,m_real6);

	m_str5 = new SXFD_StrC(" ");
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

	m_inst[4] = new SXFE_curve_styleC(m_str5,m_ins1,m_ins2,m_ins3) ;

	m_aggr3 = new SXFD_AggrC() ;
	m_aggr3->AddElem( m_inst[4] ) ;
	m_inst[5] = new SXFE_presentation_style_assignmentC(m_aggr3) ;

	m_str6 = new SXFD_StrC();
	m_slist = new CStringList();
	m_slist->AddTail(DEF_ANNOTATION_CURVE_OCCURRENCE);
	m_slist->AddTail(DEF_ANNOTATION_OCCURRENCE);
	m_slist->AddTail(DEF_DRAUGHTING_ANNOTATION_OCCURRENCE);
	m_slist->AddTail(DEF_GEOMETRIC_REPRESENTATION_ITEM);
	m_aggr4 = new SXFD_AggrC() ;
	m_aggr4->AddElem( m_inst[5] ) ;
	m_inst[6] = new SXFE_styled_itemC(m_str6,m_aggr4,m_inst[3],m_slist) ;

	m_ID = m_inst[6]->GetInsID();
	m_TableManager->SetLayerElement(IN_Struct.layer,m_ID);
	return TRUE;
	
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFEllipseMappingC.cpp								�쐬���F2000.4.15

	�P�D�@�\�T�v
	���~�C���X�^���X�̃t�@�C���ւ̏o��

	�Q�D�C���^�[�t�F�[�X
	BOOL WriteAP202(SXFPart21FileC *IN_File)
	����:	�^					������			���e
			SXFPart21FileC*		IN_File			�t�@�C���I�u�W�F�N�g�̃A�h���X

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.15			�{��(FQS)			�Ȃ��B

**/
BOOL SXFEllipseMappingC::WriteAP202(SXFPart21FileC *IN_File)
{
	m_inst[6]->WriteP21(IN_File);
	return TRUE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFEllipseMappingC.cpp								�쐬���F2000.4.15

	�P�D�@�\�T�v
	�C���X�^���XID�̕ԋp

	�Q�D�C���^�[�t�F�[�X
	int GetID()
	����:	�^					������				���e
			�Ȃ�
	
	 ���A�l	�C���X�^���XID

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.15			�{��(FQS)			�Ȃ��B

**/
int SXFEllipseMappingC::GetID()
{
	return m_ID;
}
