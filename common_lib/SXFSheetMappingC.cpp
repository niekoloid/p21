/**
	All Rights Reserved,(c) JACIC 2001
	SXFSheetMappingC.cpp								�쐬���F2001.06.14

	�P�D�N���X�T�v
	�p����Mapping

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.14			���X��(FQS)			�Ȃ��B

**/
#include "stdafx.h"
#include "SXFSheetMappingC.h"
#include "SXFE_representation_contextC.h"
#include "SXFE_drawing_definitionC.h"
#include "SXFE_draughting_drawing_revisionC.h"
#include "SXFE_draughting_titleC.h"
#include "SXFE_directionC.h"
#include "SXFE_cartesian_pointC.h"
#include "SXFE_axis2_placement_2dC.h"
#include "SXFE_planar_boxC.h"
#include "SXFE_drawing_sheet_revisionC.h"
#include "SXFE_drawing_sheet_revision_usageC.h"
#include "SXFE_presentation_sizeC.h"
#include "SXFD_InstC.h"
#include "SXFD_RealC.h"
#include "SXFD_StrC.h"
#include "SXFD_AggrC.h"
#include "SXFPart21FileC.h"
#include "SXFTableManagerC.h"
#include "SXFComndef.h"

#include "SXFE_contract_typeC.h"
#include "SXFE_contractC.h"
#include "SXFE_draughting_contract_assignmentC.h"
#include "SXFE_calendar_dateC.h"
#include "SXFE_approval_statusC.h"
#include "SXFE_approvalC.h"
#include "SXFE_approval_date_timeC.h"
#include "SXFE_draughting_approval_assignmentC.h"
#include "SXFE_organizationC.h"
#include "SXFE_organization_roleC.h"
#include "SXFE_draughting_organization_assignmentC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFSheetMappingC.cpp								�쐬���F2001.06.14

	�P�D�@�\�T�v
	�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
	void	SXFSheetMappingC::SXFSheetMappingC()
	����:	�^				������				���e
			�Ȃ�				

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.14			���X��(FQS)			�Ȃ��B

**/
SXFSheetMappingC::SXFSheetMappingC()
{
	m_ID = -1;
	m_TableManager = NULL;
	for (int i = 0; i < 11; i++){
		m_inst[i] = NULL;
	}
	m_elem_inst = NULL;
	m_real1 = NULL;
	m_real2 = NULL;
	m_real3 = NULL;
	m_real4 = NULL;
	m_real5 = NULL;
	m_real6 = NULL;
	m_str1 = NULL;
	m_str2 = NULL;
	m_str3 = NULL;
	m_str4 = NULL;
	m_str5 = NULL;
	m_str6 = NULL;
	m_str7 = NULL;
	m_str8 = NULL;
	m_str9 = NULL;
	m_str10 = NULL;
	m_str11 = NULL;
	m_aggr1 = NULL;
	m_aggr2 = NULL;
	m_aggr3 = NULL;
	m_aggr4 = NULL;

//	ADD(S)	Ver3.0�Ή�	K.Naono	04.01.30
	m_nDwgRevID = -1 ;
//	ADD(E)	Ver3.0�Ή�	K.Naono	04.01.30

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFSheetMappingC.cpp								�쐬���F2001.06.14

	�P�D�@�\�T�v
	�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
	void	SXFSheetMappingC(SXFTableManagerC* IN_TableManagerC)
	����:	�^					������				���e
			SXFTableManagerC*	IN_TableManagerC				

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.14			���X��(FQS)			�Ȃ��B

**/
SXFSheetMappingC::SXFSheetMappingC(SXFTableManagerC* IN_TableManagerC)
{
	m_ID = -1;
	m_TableManager = IN_TableManagerC;
	for (int i = 0; i < 11; i++){
		m_inst[i] = NULL;
	}
	m_elem_inst = NULL;
	m_real1 = NULL;
	m_real2 = NULL;
	m_real3 = NULL;
	m_real4 = NULL;
	m_real5 = NULL;
	m_real6 = NULL;
	m_str1 = NULL;
	m_str2 = NULL;
	m_str3 = NULL;
	m_str4 = NULL;
	m_str5 = NULL;
	m_str6 = NULL;
	m_str7 = NULL;
	m_str8 = NULL;
	m_str9 = NULL;
	m_str10 = NULL;
	m_str11 = NULL;
	m_aggr1 = NULL;
	m_aggr2 = NULL;
	m_aggr3 = NULL;
	m_aggr4 = NULL;

//	ADD(S)	Ver3.0�Ή�	K.Naono	04.01.30
	m_nDwgRevID = -1 ;
//	ADD(E)	Ver3.0�Ή�	K.Naono	04.01.30
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFSheetMappingC.cpp								�쐬���F2001.06.14

	�P�D�@�\�T�v
	�f�X�g���N�^

	�Q�D�C���^�[�t�F�[�X
	void	SXFSheetMappingC::~SXFSheetMappingC()
	����:	�^				������				���e
			�Ȃ�				

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.14			���X��(FQS)			�Ȃ��B

**/
SXFSheetMappingC::~SXFSheetMappingC()
{
	SXFInstanceC::InitDeleteMap();
	if (m_inst[2] != NULL) {
		delete m_inst[2];
		SXFInstanceC::AddDeleted(m_inst[2]);
	}
	if (m_inst[8] != NULL) {
		delete m_inst[8];
		SXFInstanceC::AddDeleted(m_inst[8]);
	}
	if (m_inst[9] != NULL)
		delete m_inst[9];
	if (m_inst[10] != NULL)
		delete m_inst[10];
	SXFInstanceC::EndDeleteMap();
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFSheetMappingC.cpp								�쐬���F2001.06.14

	�P�D�@�\�T�v
	�p����Mapping

	�Q�D�C���^�[�t�F�[�X
	BOOL MappingStruct(Sheet_Struct IN_Struct)
	����:	�^					������				���e
			Sheet_Struct		IN_Struct			�\����

	���A�l	���펞�FTRUE
			�ُ펞�FFALSE

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.14			���X��(FQS)			�Ȃ��B

**/
BOOL SXFSheetMappingC::MappingStruct(Sheet_Struct IN_Struct,CUIntArray* IN_ChildrenID)
{
	m_aggr2 = new SXFD_AggrC() ;
	m_real1 = new SXFD_RealC(1.0);
	m_real2 = new SXFD_RealC(0.0);
	m_aggr2->AddElem(m_real1) ;
	m_aggr2->AddElem(m_real2) ;
	m_str7 = new SXFD_StrC(" ");
	m_inst[3] = new SXFE_directionC(m_str7,m_aggr2);

	m_str8 = new SXFD_StrC(" ");
	m_aggr3 = new SXFD_AggrC() ;
	m_real3 = new SXFD_RealC(0.0);
	m_real4 = new SXFD_RealC(0.0);
	m_aggr3->AddElem(m_real3) ;
	m_aggr3->AddElem(m_real4) ;
	m_inst[4] = new SXFE_cartesian_pointC(m_str8,m_aggr3);

	m_str9 = new SXFD_StrC(" ");
	m_inst[5] = new SXFE_axis2_placement_2dC(m_str9,m_inst[4],m_inst[3]);

	m_str10 = new SXFD_StrC(" ");
	double x = 0.0;
	double y = 0.0;
	switch(IN_Struct.type){
	case 0:
		x = 1189.0;
		y = 841.0;
		break;
	case 1:
		x = 841.0;
		y = 594.0;
		break;
	case 2:
		x = 594.0;
		y = 420.0;
		break;
	case 3:
		x = 420.0;
		y = 297.0;
		break;
	case 4:
		x = 297.0;
		y = 210.0;
		break;
	case 9:
		x = IN_Struct.x;
		y = IN_Struct.y;
		break;
	default:
		break;
	}
	if (IN_Struct.orient == 1 ||
		IN_Struct.type == 9){
		m_real5 = new SXFD_RealC(x);
		m_real6 = new SXFD_RealC(y);
	}
	else{
		m_real5 = new SXFD_RealC(y);
		m_real6 = new SXFD_RealC(x);
	}
	m_inst[6] = new SXFE_planar_boxC(m_str10,m_real5,m_real6,m_inst[5]);
		
	////////////////////////////
	//�P�ʃC���X�^���X
	////////////////////////////
	m_inst[7] = new SXFE_representation_contextC();

	char orient_name[16];

	switch(IN_Struct.orient){
	case 0:
		//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
		//strcpy(orient_name,DEF_vertical);
		strcpy_s(orient_name,_countof(orient_name),DEF_vertical);
		break;
	case 1:
		//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
		//strcpy(orient_name,DEF_horizontal);
		strcpy_s(orient_name,_countof(orient_name),DEF_horizontal);
		break;
	default:
		break;
	}

	char sheet_name[257];

	switch(IN_Struct.type){
	case 0:
	//	MOD(S)	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
		//strcpy(sheet_name,"A0_");
		//strcat(sheet_name,orient_name);
		strcpy_s(sheet_name,_countof(sheet_name),"A0_");
		strcat_s(sheet_name,_countof(sheet_name),orient_name);
	//	MOD(E)	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
		break;
	case 1:
	//	MOD(S)	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
		//strcpy(sheet_name,"A1_");
		//strcat(sheet_name,orient_name);
		strcpy_s(sheet_name,_countof(sheet_name),"A1_");
		strcat_s(sheet_name,_countof(sheet_name),orient_name);
	//	MOD(E)	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
		break;
	case 2:
	//	MOD(S)	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
		//strcpy(sheet_name,"A2_");
		//strcat(sheet_name,orient_name);
		strcpy_s(sheet_name,_countof(sheet_name),"A2_");
		strcat_s(sheet_name,_countof(sheet_name),orient_name);
	//	MOD(E)	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
		break;
	case 3:
	//	MOD(S)	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
		//strcpy(sheet_name,"A3_");
		//strcat(sheet_name,orient_name);
		strcpy_s(sheet_name,_countof(sheet_name),"A3_");
		strcat_s(sheet_name,_countof(sheet_name),orient_name);
	//	MOD(E)	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
		break;
	case 4:
	//	MOD(S)	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
		//strcpy(sheet_name,"A4_");
		//strcat(sheet_name,orient_name);
		strcpy_s(sheet_name,_countof(sheet_name),"A4_");
		strcat_s(sheet_name,_countof(sheet_name),orient_name);
	//	MOD(E)	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
		break;
	case 9:
		//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
		//strcpy(sheet_name,DEF_FREE);
		strcpy_s(sheet_name,_countof(sheet_name),DEF_FREE);
		break;
	default:
		break;
	}

	m_str11 = new SXFD_StrC(sheet_name);
	///�p����̗v�f
	m_aggr4 = new SXFD_AggrC();
	for (int i = 0; i < IN_ChildrenID->GetSize(); i++){
		m_elem_inst = new SXFD_InstC(IN_ChildrenID->GetAt(i));
		m_aggr4->AddElem(m_elem_inst);
	}
	m_aggr4->AddElem(m_inst[6]);

	m_str12 = new SXFD_StrC("01");
	m_inst[8] = new SXFE_drawing_sheet_revisionC(m_str11,m_aggr4,m_inst[7],m_str12);
	m_str13 = new SXFD_StrC("01");
	m_inst[9] = new SXFE_drawing_sheet_revision_usageC(m_inst[8],m_inst[1],m_str13);

	m_inst[10] = new SXFE_presentation_sizeC(m_inst[8],m_inst[6]);

	m_ID = m_inst[8]->GetInsID();////////�p���̂h�c
	m_TableManager->SetLayerSheetID(m_ID);

	//	DRAUGHTING_DRAWING_REVISION�̃C���X�^���XID��ۑ����Ă���
	m_nDwgRevID = m_inst[1]->GetInsID() ;

	return TRUE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFSheetMappingC.cpp								�쐬���F2001.06.14

	�P�D�@�\�T�v
	�p���C���X�^���X�̃t�@�C���ւ̏o��

	�Q�D�C���^�[�t�F�[�X
	BOOL WriteAP202(SXFPart21FileC *IN_File)
	����:	�^					������			���e
			SXFPart21FileC*		IN_File			�t�@�C���I�u�W�F�N�g�̃A�h���X
	 ���A�l	���펞�FTRUE
			�ُ펞�FFALSE

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.14			���X��(FQS)			�Ȃ��B

**/
BOOL SXFSheetMappingC::WriteAP202(SXFPart21FileC *IN_File)
{
	m_inst[2]->WriteP21(IN_File);
	m_inst[6]->WriteP21(IN_File);
	m_inst[9]->WriteP21(IN_File);
	m_inst[10]->WriteP21(IN_File);
	return TRUE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFSheetMappingC.cpp								�쐬���F2001.06.14

	�P�D�@�\�T�v
	�C���X�^���XID�̕ԋp

	�Q�D�C���^�[�t�F�[�X
	int GetID()
	����:	�^					������				���e
			�Ȃ�
	
	 ���A�l	�C���X�^���XID

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.14			���X��(FQS)			�Ȃ��B

**/
int SXFSheetMappingC::GetID()
{
	return m_ID;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFSheetMappingC.cpp								�쐬���F2001.06.14

	�P�D�@�\�T�v
	DRAUGHTING_DRAWING_REVISION�̃C���X�^���XID��ԋp

	�Q�D�C���^�[�t�F�[�X
	int GetDwgRevID()
	����:	�^					������				���e
			�Ȃ�
	
	���A�l	�C���X�^���XID

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2004.01.30			K.Naono				Ver3.0�Ή�

**/
int	SXFSheetMappingC::GetDwgRevID()
{
	return m_nDwgRevID ;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFSheetMappingC.cpp								�쐬���F2001.06.14

	�P�D�@�\�T�v
	�p����Mapping

	�Q�D�C���^�[�t�F�[�X
	BOOL MappingStruct(Sheet_Struct IN_Struct)
	����:	�^					������					���e
			Sheet_Struct		IN_Struct			�p���\����
			CUIntArray*			IN_ChildrenID		�A�Z���u���v�f������ʗv�f�̃C���X�^���XID�̔z��
			Attribute_Struct*	IN_AttrStr			�}�ʕ\�藓�\����

	���A�l	���펞�FTRUE
			�ُ펞�FFALSE

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2004.01.30			K.Naono				Ver3.0�Ή�

**/
BOOL SXFSheetMappingC::MappingStruct(
						Sheet_Struct		IN_Struct,
						CUIntArray*			IN_ChildrenID,
						Attribute_Struct*	IN_AttrStr)
{
	//	�}�ʕ\�藓�̏o��
	if( IN_AttrStr != NULL ) {
		m_str1		= new SXFD_StrC(IN_AttrStr->d_number) ;
		m_str2		= new SXFD_StrC(IN_AttrStr->d_type) ;
		m_inst[0]	= new SXFE_drawing_definitionC(m_str1, m_str2) ;

		m_str3		= new SXFD_StrC("01") ;
		m_str4		= new SXFD_StrC(IN_AttrStr->d_scale) ;
		m_inst[1] = new SXFE_draughting_drawing_revisionC(m_str3, m_inst[0], m_str4) ;

		m_aggr1		= new SXFD_AggrC() ;
		m_aggr1->AddElem(m_inst[1]) ;
		m_str5		= new SXFD_StrC("JAPANESE") ;
		m_str6		= new SXFD_StrC(IN_AttrStr->d_title) ;
		m_inst[2]	= new SXFE_draughting_titleC(m_aggr1, m_str5, m_str6) ;

	} else {
		m_str1		= new SXFD_StrC("01") ;
		m_inst[0]	= new SXFE_drawing_definitionC(m_str1) ;

		m_str2		= new SXFD_StrC("01") ;
		m_inst[1]	= new SXFE_draughting_drawing_revisionC(m_str2, m_inst[0]) ;

		m_aggr1		= new SXFD_AggrC() ;
		m_aggr1->AddElem(m_inst[1]) ;
		m_str3		= new SXFD_StrC("JAPANESE") ;
		m_str4		= new SXFD_StrC((LPTSTR)(LPCTSTR)IN_Struct.name) ;
		m_inst[2]	= new SXFE_draughting_titleC(m_aggr1, m_str3, m_str4) ;
	}

	return MappingStruct(IN_Struct, IN_ChildrenID) ;
}
