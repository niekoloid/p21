/**
	All Rights Reserved,(c)JACIC 2001
	SXFCompCurveMappingC.cpp						�쐬���F2001.06.15

	�P�D�N���X�T�v
	�����Ȑ���`��Mapping

	�Q�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2001.06.15	���X��(FQS)	�Ȃ��B
		�X�V		2001.09.18	K.Naono		�n�b�`���O��Q�Ή�
**/

#include "stdafx.h"
#include "SXFCompCurveMappingC.h"
#include "SXFE_cartesian_pointC.h"
#include "SXFE_composite_curveC.h"
#include "SXFE_curve_styleC.h"
#include "SXFE_presentation_style_assignmentC.h"
#include "SXFE_styled_itemC.h"
#include "SXFD_InstC.h"
#include "SXFD_BoolC.h"
#include "SXFD_StrC.h"
#include "SXFD_AggrC.h"
#include "SXFD_RealC.h"
#include "SXFPart21FileC.h"
#include "SXFTableManagerC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFCompCurveMappingC.cpp						�쐬���F2001.06.15

	�P�D�@�\�T�v
		�R���X�g���N�^
		
	�Q�D�C���^�[�t�F�C�X
		void	SXFCompCurveMappingC::SXFCompCurveMappingC()
		
	����	�F	�^		������				���e
		�Ȃ�		

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2001.06.15	���X��(FQS)	�Ȃ��B
**/
SXFCompCurveMappingC::SXFCompCurveMappingC()
{
	m_ID1 = -1;
	m_ID2 = -1;
	m_pointID = -1;
	for (int i = 0; i < 4 ; i++)
		m_inst[i] = NULL;
	m_elem_inst = NULL;
	m_ins1 = NULL;
	m_ins2 = NULL;
	m_ins3 = NULL;
	m_inst_point = NULL;
	m_str1 = NULL;
	m_str2 = NULL;
	m_str3 = NULL;
	m_str4 = NULL;
	m_aggr1 = NULL;
	m_aggr2 = NULL;
	m_aggr3 = NULL;
	m_aggr4 = NULL;
	m_bool1 = NULL;
	m_slist = NULL;
	m_real1 = NULL;
	m_real2 = NULL;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFCompCurveMappingC.cpp						�쐬���F2001.06.15

	�P�D�@�\�T�v
		�R���X�g���N�^
		
	�Q�D�C���^�[�t�F�C�X
		void	SXFCompCurveMappingC::SXFCompCurveMappingC(SXFTableManagerC* IN_TableManager,double IN_PointX,double IN_PointY)
		
	����	�F	�^		������				���e
		SXFTableManagerC IN_TableManager	��`�e�[�u���v�f�Ǘ��I�u�W�F�N�g 
		double			 IN_PointX			�_X
		double		     IN_PointY			�_Y

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2001.06.15	���X��(FQS)	�Ȃ��B
**/
SXFCompCurveMappingC::SXFCompCurveMappingC(SXFTableManagerC* IN_TableManager,double IN_PointX,double IN_PointY)
{
	m_TableManager = IN_TableManager;
	m_PointX = IN_PointX;
	m_PointY = IN_PointY;
	m_ID1 = -1;
	m_ID2 = -1;
	m_pointID = -1;
	for (int i = 0; i < 4 ; i++)
		m_inst[i] = NULL;
	m_elem_inst = NULL;
	m_ins1 = NULL;
	m_ins2 = NULL;
	m_ins3 = NULL;
	m_inst_point = NULL;
	m_str1 = NULL;
	m_str2 = NULL;
	m_str3 = NULL;
	m_str4 = NULL;
	m_aggr1 = NULL;
	m_aggr2 = NULL;
	m_aggr3 = NULL;
	m_aggr4 = NULL;
	m_bool1 = NULL;
	m_slist = NULL;
	m_real1 = NULL;
	m_real2 = NULL;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFCompCurveMappingC.cpp						�쐬���F2001.06.15

	�P�D�@�\�T�v
		�f�X�g���N�^
		
	�Q�D�C���^�[�t�F�C�X
		void	SXFCompCurveMappingC::~SXFCompCurveMappingC()

	����	�F	�^		������				���e
		�Ȃ�		

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2001.06.15	���X��(FQS)	�Ȃ��B
**/
SXFCompCurveMappingC::~SXFCompCurveMappingC()
{
	if (m_inst[3] != NULL)
		delete m_inst[3];
	if (m_inst_point)
		delete m_inst_point;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFCompCurveMappingC.cpp						�쐬���F2001.06.15

	�P�D�@�\�T�v
	�����Ȑ���`�t�B�[�`����Mapping

	�Q�D�C���^�[�t�F�[�X
	BOOL MappingStruct(Ccurve_Org_Struct IN_Struct,CUIntArray* IN_ChildrenID)
	����:	�^						������			���e
			Ccurve_Org_Struct		IN_Struct		�\����
			CUIntArray*				IN_ChildrenID	�����Ȑ����w���t�B�[�`���v�f��ID

	���A�l	���펞�FTRUE
			�ُ펞�FFALSE


	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2001.06.15	���X��(FQS)	�Ȃ��B
		�X�V		2001.09.18	K.Naono		�n�b�`���O��Q�Ή�
**/
BOOL SXFCompCurveMappingC::MappingStruct(Ccurve_Org_Struct IN_Struct,CUIntArray* IN_ChildrenID)
{
	//�n�b�`���O�����̓_
//	DEL(S)	�n�b�`���O��Q�Ή�	K.Naono		01.09.18
/*
	m_str4 = new SXFD_StrC(" ");
	m_real1 = new SXFD_RealC(m_PointX);
	m_real2 = new SXFD_RealC(m_PointY);
	m_aggr4 = new SXFD_AggrC() ;
	m_aggr4->AddElem(m_real1) ;
	m_aggr4->AddElem(m_real2) ;
	m_inst_point = new SXFE_cartesian_pointC(m_str4,m_aggr4);
	m_pointID = m_inst_point->GetInsID();//�n�b�`���O�Ɏg�p�@CARTESIAN_POINT�̂h�c
*/
//	DEL(E)	�n�b�`���O��Q�Ή�	K.Naono		01.09.18

	m_str1 = new SXFD_StrC(" ");
	///�����Ȑ���̗v�f
	m_aggr1 = new SXFD_AggrC();
	for (int i = 0; i < IN_ChildrenID->GetSize(); i++){
		m_elem_inst = new SXFD_InstC(IN_ChildrenID->GetAt(i));
		m_aggr1->AddElem(m_elem_inst);
	}

	m_bool1 = new SXFD_BoolC(TRUE);
	m_inst[0] = new SXFE_composite_curveC(m_str1,m_aggr1,m_bool1);

	m_str2 = new SXFD_StrC(" ");
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
	m_inst[1] = new SXFE_curve_styleC(m_str2,m_ins1,m_ins2,m_ins3);

	m_aggr2 = new SXFD_AggrC() ;
	m_aggr2->AddElem(m_inst[1] ) ;
	m_inst[2] = new SXFE_presentation_style_assignmentC(m_aggr2);

	m_str3 = new SXFD_StrC(" ");
	m_slist = new CStringList();
	m_slist->AddTail(DEF_ANNOTATION_CURVE_OCCURRENCE);
	m_slist->AddTail(DEF_ANNOTATION_OCCURRENCE);
	m_slist->AddTail(DEF_DRAUGHTING_ANNOTATION_OCCURRENCE);
	m_slist->AddTail(DEF_GEOMETRIC_REPRESENTATION_ITEM);
	m_aggr3 = new SXFD_AggrC() ;
	m_aggr3->AddElem( m_inst[2] ) ;
	m_inst[3] = new SXFE_styled_itemC(m_str3,m_aggr3,m_inst[0],m_slist) ;

	m_ID1 = m_inst[0]->GetInsID();////////�����Ȑ��̂h�c�@�n�b�`���O�Ɏg�p
	m_ID2 = m_inst[3]->GetInsID();////////�����Ȑ��̂h�c�@INVISIBILITY�Ɏg�p

	return TRUE;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFCompCurveMappingC.cpp						�쐬���F2001.06.15

	�P�D�@�\�T�v
	�����Ȑ���`�C���X�^���X�̃t�@�C���ւ̏o��

	�Q�D�C���^�[�t�F�[�X
	BOOL WriteAP202(SXFPart21FileC *IN_File)
	����:	�^					������			���e
			SXFPart21FileC*		IN_File			�t�@�C���I�u�W�F�N�g�̃A�h���X

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2001.06.15	���X��(FQS)	�Ȃ��B
		�X�V		2001.09.18	K.Naono		�n�b�`���O��Q�Ή�
**/
BOOL SXFCompCurveMappingC::WriteAP202(SXFPart21FileC *IN_File)
{
//	DEL(S)	�n�b�`���O��Q�Ή�	K.Naono		01.09.18
/*
	m_inst_point->WriteP21(IN_File);
*/
//	DEL(E)	�n�b�`���O��Q�Ή�	K.Naono		01.09.18
	m_inst[3]->WriteP21(IN_File);
	return TRUE;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFCompCurveMappingC.cpp						�쐬���F2001.06.15

	�P�D�@�\�T�v
	�C���X�^���XID�̕ԋp

	�Q�D�C���^�[�t�F�[�X
	int GetID(int &OUT_ID1,int &OUT_ID2,int &OUT_PointID)
	����:	�^					������				���e
			int&				OUT_ID1				INVISIBILITY���炳�����ID
			int&				OUT_ID2				�n�b�`���O����w�����
			int&				OUT_PointID			�n�b�`���O�����̓_��ID
	
	 ���A�l	�Ȃ�
		

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2001.06.15	���X��(FQS)	�Ȃ��B
**/
void SXFCompCurveMappingC::GetID(int &OUT_ID1,int &OUT_ID2,int &OUT_PointID)
{
	//�����Ȑ��̂h�c�@INVISIBILITY�Ɏg�p
	OUT_ID1 = m_ID2;
	//�����Ȑ��̂h�c�@�n�b�`���O�Ɏg�p
	OUT_ID2 = m_ID1;
	//�n�b�`���O�Ɏg�p�@CARTESIAN_POINT�̂h�c
	OUT_PointID = m_pointID;
}
