/**
	All Rights Reserved,(c) JACIC 2001
	SXFExHatchMappingC.cpp								�쐬���F2001.06.17

	�P�D�N���X�T�v
	�n�b�`���O(����`�j��Mapping

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.17			���X��(FQS)			�Ȃ��B
	�X�V			2001.09.18			K.Naono				�n�b�`���O��Q�Ή�

**/
#include "stdafx.h"
#include "SXFExHatchMappingC.h"
#include "SXFTableManagerC.h"
#include "SXFPart21FileC.h"
#include "SXFD_InstC.h"
#include "SXFD_AggrC.h"
#include "SXFD_StrC.h"
#include "SXFD_TypeC.h"
#include "SXFE_annotation_fill_areaC.h"
#include "SXFE_external_sourceC.h"
#include "SXFE_externally_defined_hatch_styleC.h"
#include "SXFE_fill_area_styleC.h"
#include "SXFE_presentation_style_assignmentC.h"
#include "SXFE_styled_itemC.h"
//	ADD(S)	�n�b�`���O��Q�Ή�	K.Naono		01.09.18
#include "SXFD_RealC.h"
#include "SXFE_cartesian_pointC.h"
//	ADD(E)	�n�b�`���O��Q�Ή�	K.Naono		01.09.18
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFExHatchMappingC.cpp						�쐬���F2001.06.18

	�P�D�@�\�T�v
		�R���X�g���N�^
		
	�Q�D�C���^�[�t�F�C�X
	void	SXFExHatchMappingC::SXFExHatchMappingC()		
	����:	�^				������				���e
			�Ȃ�				

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2001.06.18	���X��(FQS)	�Ȃ��B
		�X�V		2001.09.18	K.Naono		�n�b�`���O��Q�Ή�
**/
SXFExHatchMappingC::SXFExHatchMappingC()
{
	for (int i = 0; i < 6; i++)
		m_inst[i] = NULL;
	m_inst1 = NULL;
	m_inst2 = NULL;
	m_inst3 = NULL;
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
	m_type1 = NULL;
	m_type2 = NULL;
	m_type3 = NULL;
	m_type4 = NULL;
	m_type5 = NULL;
	m_type6 = NULL;
	m_type7 = NULL;
	m_ID = -1;

//	ADD(S)	�n�b�`���O��Q�Ή�	K.Naono		01.09.18
	m_inst_point = NULL;
//	ADD(E)	�n�b�`���O��Q�Ή�	K.Naono		01.09.18
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFExHatchMappingC.cpp						�쐬���F2001.06.18

	�P�D�@�\�T�v
		�R���X�g���N�^
		
	�Q�D�C���^�[�t�F�C�X
	void	SXFExHatchMappingC(SXFTableManagerC* IN_TableManager,
							   CUIntArray* IN_AssemblyTable,
							   CUIntArray* IN_PointTable)		
	����:	�^					������				���e
			SXFTableManagerC* 	IN_TableManager		��`ð��يǗ���޼ު��
			CUIntArray* 		IN_AssemblyTable	������ð���
			CUIntArray* 		IN_PointTable		�߲��ð���		

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2001.06.18	���X��(FQS)	�Ȃ��B
		�X�V		2001.09.18	K.Naono		�n�b�`���O��Q�Ή�
**/
SXFExHatchMappingC::SXFExHatchMappingC(
				SXFTableManagerC*	IN_TableManager,
				CUIntArray*			IN_AssemblyTable,
//	MOD(S)	�n�b�`���O��Q�Ή�	K.Naono		01.09.18
//				CUIntArray*			IN_PointTable)
				CArray<SXF_POINT,SXF_POINT&>*	IN_PointTable)
//	MOD(E)	�n�b�`���O��Q�Ή�	K.Naono		01.09.18
{
	m_TableManager = IN_TableManager;
	m_AssemblyTable = IN_AssemblyTable;
	m_PointTable = IN_PointTable;
	for (int i = 0; i < 6; i++)
		m_inst[i] = NULL;
	m_inst1 = NULL;
	m_inst2 = NULL;
	m_inst3 = NULL;
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
	m_type1 = NULL;
	m_type2 = NULL;
	m_type3 = NULL;
	m_type4 = NULL;
	m_type5 = NULL;
	m_type6 = NULL;
	m_type7 = NULL;
	m_ID = -1;

//	ADD(S)	�n�b�`���O��Q�Ή�	K.Naono		01.09.18
	m_inst_point = NULL;
//	ADD(E)	�n�b�`���O��Q�Ή�	K.Naono		01.09.18
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFExHatchMappingC.cpp						�쐬���F2001.06.18

	�P�D�@�\�T�v
	�f�X�g���N�^
		
	�Q�D�C���^�[�t�F�C�X
	void	SXFExHatchMappingC::~SXFExHatchMappingC()		
	����:	�^				������				���e
			�Ȃ�				

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2001.06.18	���X��(FQS)	�Ȃ��B
		�X�V		2001.09.18	K.Naono		�n�b�`���O��Q�Ή�
**/
SXFExHatchMappingC::~SXFExHatchMappingC()
{
	if (m_str2 != NULL)
		delete m_str2;
	if (m_str3 != NULL)
		delete m_str3;
	if (m_str6 != NULL)
		delete m_str6;
	if (m_inst3 != NULL)
		delete m_inst3;
	if (m_inst[5] != NULL)
		delete m_inst[5];

//	ADD(S)	�n�b�`���O��Q�Ή�	K.Naono		01.09.18
	if (m_inst_point)
		delete m_inst_point;
//	ADD(E)	�n�b�`���O��Q�Ή�	K.Naono		01.09.18
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFExHatchMappingC.cpp						�쐬���F2001.06.18

	�P�D�@�\�T�v
	�n�b�`���O(����`�j��Mapping

	�Q�D�C���^�[�t�F�[�X
	BOOL MappingStruct(Externally_Defined_Hatch_Struct IN_Struct)
	����:	�^									������				���e
			Externally_Defined_Hatch_Struct		IN_Struct			�\����

	 ���A�l	���펞�FTRUE
			�ُ펞�FFALSE

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2001.06.18	���X��(FQS)	�Ȃ��B
		�X�V		2001.09.18	K.Naono		�n�b�`���O��Q�Ή�
**/
BOOL SXFExHatchMappingC::MappingStruct(Externally_Defined_Hatch_Struct* IN_Struct)
{
	int out_ID = 0;
	if(IN_Struct->out_id < 1 || IN_Struct->out_id > m_AssemblyTable->GetSize())
		return FALSE;
	else
		out_ID = m_AssemblyTable->GetAt(IN_Struct->out_id-1);

	//�A�Z���u���e�[�u�����O�`�̃R�[�h����h�c���擾
	m_inst1 = new SXFD_InstC(out_ID);
	m_aggr1 = new SXFD_AggrC() ;
	m_aggr1->AddElem(m_inst1) ;
	
	for(int i = 0;i < IN_Struct->number; i++){
		int in_ID = 0;
		if(IN_Struct->in_id[i] < 1 || IN_Struct->in_id[i] > m_AssemblyTable->GetSize())
			return FALSE;
		else
			in_ID = m_AssemblyTable->GetAt(IN_Struct->in_id[i]-1);
		m_inst2 = new SXFD_InstC(in_ID);/////////�A�Z���u���e�[�u����蒆�����̃R�[�h����h�c���擾
		m_aggr1->AddElem(m_inst2) ;
	}
	m_str1 = new SXFD_StrC(" ");
	m_inst[0] = new SXFE_annotation_fill_areaC(m_str1,m_aggr1) ;

	m_str2 = new SXFD_StrC("scadec");
	m_type1 = new SXFD_TypeC(DEF_IDENTIFIER);
	m_type1->SetNext(m_str2);
	m_inst[1] = new SXFE_external_sourceC(m_type1) ;

	m_str3 = new SXFD_StrC((LPTSTR)(LPCTSTR)IN_Struct->name);
	m_str4 = new SXFD_StrC(" ");
	m_type2 = new SXFD_TypeC(DEF_IDENTIFIER);
	m_type2->SetNext(m_str3);
	m_inst[2] = new SXFE_externally_defined_hatch_styleC(m_type2,m_inst[1],m_str4) ;

	m_str5 = new SXFD_StrC(" ");
	m_aggr2 = new SXFD_AggrC() ;
	m_aggr2->AddElem(m_inst[2]);
	m_inst[3] = new SXFE_fill_area_styleC(m_str5,m_aggr2);

	m_aggr3 = new SXFD_AggrC() ;
	m_aggr3->AddElem(m_inst[3]);
	m_inst[4] = new SXFE_presentation_style_assignmentC(m_aggr3);

	m_type3 = new SXFD_TypeC(DEF_ANNOTATION_FILL_AREA_OCCURRENCE);
	int pointID = 0;
	if(IN_Struct->out_id < 1 || IN_Struct->out_id > m_PointTable->GetSize())
		return FALSE;
//	MOD(S)	�n�b�`���O��Q�Ή�	K.Naono		01.09.18
/*
	else
		pointID = m_PointTable->GetAt(IN_Struct->out_id-1);
*/
	else {
		SXF_POINT	point = m_PointTable->GetAt(IN_Struct->out_id-1);
		SXFD_AggrC*	aggr = new SXFD_AggrC() ;
		aggr->AddElem(new SXFD_RealC(point.x)) ;
		aggr->AddElem(new SXFD_RealC(point.y)) ;
		m_inst_point = new SXFE_cartesian_pointC(new SXFD_StrC(" "), aggr);
		pointID = m_inst_point->GetInsID();
	}
//	MOD(E)	�n�b�`���O��Q�Ή�	K.Naono		01.09.18
	m_inst3 = new SXFD_InstC(pointID);//CARTESIAN_POINT�̂h�c
	m_type3->SetNext(m_inst3);
	m_type4 = new SXFD_TypeC(DEF_ANNOTATION_OCCURRENCE);
	m_type5 = new SXFD_TypeC(DEF_DRAUGHTING_ANNOTATION_OCCURRENCE);
	m_type6 = new SXFD_TypeC(DEF_GEOMETRIC_REPRESENTATION_ITEM);
	m_str6 = new SXFD_StrC(" ");
	m_type7 = new SXFD_TypeC(DEF_REPRESENTATION_ITEM);
	m_type7->SetNext(m_str6);

	m_aggr4 = new SXFD_AggrC();
	m_aggr4->AddElem(m_type3);
	m_aggr4->AddElem(m_type4);
	m_aggr4->AddElem(m_type5);
	m_aggr4->AddElem(m_type6);
	m_aggr4->AddElem(m_type7);

	m_aggr5 = new SXFD_AggrC() ;
	m_aggr5->AddElem( m_inst[4] ) ;
	m_inst[5] = new SXFE_styled_itemC(m_aggr4,m_aggr5,m_inst[0]) ;

	m_ID = m_inst[5]->GetInsID();
	m_TableManager->SetLayerElement(IN_Struct->layer,m_ID);
	return TRUE;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFExHatchMappingC.cpp						�쐬���F2001.06.18

	�P�D�@�\�T�v
	�C���X�^���X�̃t�@�C���ւ̏o��

	�Q�D�C���^�[�t�F�[�X
	BOOL WriteAP202(SXFPart21FileC *IN_File)
	����:	�^					������			���e
			SXFPart21FileC*		IN_File			�t�@�C���I�u�W�F�N�g�̃A�h���X

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2001.06.18	���X��(FQS)	�Ȃ��B
		�X�V		2001.09.18	K.Naono		�n�b�`���O��Q�Ή�
**/
BOOL SXFExHatchMappingC::WriteAP202(SXFPart21FileC *IN_File)
{
//	ADD(S)	�n�b�`���O��Q�Ή�	K.Naono		01.09.18
	if( m_inst_point )
		m_inst_point->WriteP21(IN_File);
//	ADD(E)	�n�b�`���O��Q�Ή�	K.Naono		01.09.18

	m_inst[5]->WriteP21(IN_File);
	return TRUE;
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFExHatchMappingC.cpp						�쐬���F2001.06.18

	�P�D�@�\�T�v
	�C���X�^���XID��ԋp����

	�Q�D�C���^�[�t�F�[�X
	int GetID()
	����:	�^					������				���e
			�Ȃ�
	
	 ���A�l	�C���X�^���XID

	�R�D����
		����ԍ�	���t		�S����		�T�v
		�쐬		2001.06.18	���X��(FQS)	�Ȃ��B
**/
int SXFExHatchMappingC::GetID()
{
	return m_ID;
}
