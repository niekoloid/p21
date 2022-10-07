/**
	All Rights Reserved,(c) JACIC 2001
	SXFSfiglocMappingC.cpp								�쐬���F2001.06.19

	�P�D�N���X�T�v
	�����}�`�z�u��Mapping
	
	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.19			���X��(FQS)			�Ȃ��B
	�X�V			2002.02.20			K.Naono				���C�Ή�

**/

#include "stdafx.h"
#include <math.h>
#include "SXFSfiglocMappingC.h"
#include "SXFPart21FileC.h"
#include "SXFTableManagerC.h"
#include "SXFD_AggrC.h"
#include "SXFD_StrC.h"
#include "SXFD_InstC.h"
#include "SXFD_TypeC.h"
#include "SXFD_BoolC.h"
#include "SXFD_RealC.h"
#include "SXFE_directionC.h"
#include "SXFE_cartesian_pointC.h"
#include "SXFE_axis2_placement_2dC.h"
#include "SXFE_symbol_targetC.h"
#include "SXFE_annotation_symbolC.h"
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
	SXFSfiglocMappingC.cpp								�쐬���F2001.06.19

	�P�D�N���X�T�v
	�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
	void	SXFSfiglocMappingC::SXFSfiglocMappingC()
	����:	�^				������				���e
			�Ȃ�				

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.19			���X��(FQS)			�Ȃ��B

**/
SXFSfiglocMappingC::SXFSfiglocMappingC()
{
	m_TableManager = NULL;
	m_SfigorgTable = NULL;

	m_ID = -1;
	for (int i = 0; i < 7 ; i++){
		m_inst[i] = NULL;
	}
	m_aggr1 = NULL;
	m_aggr2= NULL;
	m_real1= NULL;
	m_real2= NULL;
	m_real3= NULL;
	m_real4= NULL;
	m_real5= NULL;
	m_real6= NULL;
	m_str1= NULL;
	m_str2= NULL;
	m_str3= NULL;
	m_str4= NULL;
	m_str5= NULL;
	m_str6= NULL;
	m_org_inst = NULL;
	m_type1 = NULL;
	m_bool1 = NULL;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFSfiglocMappingC.cpp								�쐬���F2001.06.19

	�P�D�N���X�T�v
	�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
	void	SXFSfiglocMappingC(SXFTableManagerC* IN_TableManager,SXFSFIGORGTABLE* IN_SfigorgTable)
	����:	�^					������				���e
			SXFTableManagerC* 	IN_TableManager		��`ð��يǗ���޼ު��
			SXFSFIGORGTABLE* 	IN_SfigorgTable		�����}�`�e�[�u��		

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.19			���X��(FQS)			�Ȃ��B

**/
//	MOD(S)	�`���[�j���O�Ή�	K.Naono	03.07.08
//SXFSfiglocMappingC::SXFSfiglocMappingC(SXFTableManagerC* IN_TableManager,SXFSFIGORGTABLE* IN_SfigorgTable)
SXFSfiglocMappingC::SXFSfiglocMappingC(
						SXFTableManagerC*	IN_TableManager,
						CMapStringToPtr*	IN_SfigorgTable)
//	MOD(E)	�`���[�j���O�Ή�	K.Naono	03.07.08
{
	m_TableManager = IN_TableManager;
	m_SfigorgTable = IN_SfigorgTable;

	m_ID = -1;
	for (int i = 0; i < 7 ; i++){
		m_inst[i] = NULL;
	}
	m_org_inst = NULL;
	m_aggr1 = NULL;
	m_aggr2= NULL;
	m_aggr3 = NULL;
	m_aggr4= NULL;
	m_real1= NULL;
	m_real2= NULL;
	m_real3= NULL;
	m_real4= NULL;
	m_real5= NULL;
	m_real6= NULL;
	m_str1= NULL;
	m_str2= NULL;
	m_str3= NULL;
	m_str4= NULL;
	m_str5= NULL;
	m_str6= NULL;
	m_slist = NULL;
	m_org_inst = NULL;
	m_type1 = NULL;
	m_bool1 = NULL;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFSfiglocMappingC.cpp								�쐬���F2001.06.19

	�P�D�N���X�T�v
	�f�X�g���N�^

	�Q�D�C���^�[�t�F�[�X
	void	SXFSfiglocMappingC::~SXFSfiglocMappingC()
	����:	�^				������				���e
			�Ȃ�				

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.19			���X��(FQS)			�Ȃ��B

**/
SXFSfiglocMappingC::~SXFSfiglocMappingC()
{
	if (m_inst[6] != NULL)
		delete m_inst[6];
	if (m_bool1 != NULL)
		delete m_bool1;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFSfiglocMappingC.cpp								�쐬���F2001.06.19

	�P�D�N���X�T�v
	Mapping���s��

	�Q�D�C���^�[�t�F�[�X
	BOOL SXFSfiglocMappingC::MappingStruct(Sfigloc_Struct IN_Struct)
	����:	�^				������				���e
			Sfigloc_Struct 	IN_Struct				

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.19			���X��(FQS)			�Ȃ��B

**/
BOOL SXFSfiglocMappingC::MappingStruct(Sfigloc_Struct IN_Struct)
{
	m_str1 = new SXFD_StrC(" ");
	double	m_direction_x = cos(acos(-1.)*IN_Struct.angle/180.0);
	double	m_direction_y = sin(acos(-1.)*IN_Struct.angle/180.0);
	m_real1 = new SXFD_AngleC(m_direction_x);
	m_real2 = new SXFD_AngleC(m_direction_y);
	m_aggr1 = new SXFD_AggrC() ;
	m_aggr1->AddElem(m_real1) ;
	m_aggr1->AddElem(m_real2) ;
	m_inst[0] = new SXFE_directionC(m_str1,m_aggr1);

	m_str2 = new SXFD_StrC(" ");
	m_real3 = new SXFD_RealC(IN_Struct.x);
	m_real4 = new SXFD_RealC(IN_Struct.y);
	m_aggr2 = new SXFD_AggrC() ;
	m_aggr2->AddElem(m_real3) ;
	m_aggr2->AddElem(m_real4) ;
	m_inst[1] = new SXFE_cartesian_pointC(m_str2,m_aggr2);

	m_str3 = new SXFD_StrC(" ");
	m_inst[2] = new SXFE_axis2_placement_2dC(m_str3,m_inst[1],m_inst[0]);

	m_str4 = new SXFD_StrC(" ");
//	MOD(S)	���C�Ή�	K.Naono	02.02.20
/*
	m_real5 = new SXFD_RealC(IN_Struct.ratio_x);
	m_real6 = new SXFD_RealC(IN_Struct.ratio_y);
*/
	m_real5 = new SXFD_AngleC(IN_Struct.ratio_x);
	m_real6 = new SXFD_AngleC(IN_Struct.ratio_y);
//	MOD(E)	���C�Ή�	K.Naono	02.02.20
	m_inst[3] = new SXFE_symbol_targetC(m_str4,m_inst[2],m_real5,m_real6);

	//////////�����}�`�̃e�[�u�����Q��
	//////////���O���h�c
	int sfigID = 0;
	int sfigtype = 0;

//	MOD(S)	�`���[�j���O�Ή�	K.Naono	03.07.08
/*
	for (int i = 0; i < m_SfigorgTable->GetSize(); i++){
		if (m_SfigorgTable->GetAt(i).name == IN_Struct.name){
			sfigID = m_SfigorgTable->GetAt(i).ID;
			sfigtype = m_SfigorgTable->GetAt(i).type;
		}
	}
*/
	SXFSFIGORGCHECK*	pSfigOrg = NULL ;
	if( m_SfigorgTable->Lookup(IN_Struct.name, (void*&)pSfigOrg) ) {
		sfigID	= pSfigOrg->ID ;
		sfigtype= pSfigOrg->type ;
	}
//	MOD(E)	�`���[�j���O�Ή�	K.Naono	03.07.08

    //ID���擾
	m_org_inst = new SXFD_InstC(sfigID);
	m_str5 = new SXFD_StrC(" ");
	m_inst[4] = new SXFE_annotation_symbolC(m_org_inst,m_inst[3],m_str5);

	m_bool1 = new SXFD_BoolC(DEF_NULL);
	m_type1 = new SXFD_TypeC(DEF_NULL_STYLE);
	m_type1->SetNext(m_bool1);
	m_aggr3 = new SXFD_AggrC() ;
	m_aggr3->AddElem(m_type1);
	m_inst[5] = new SXFE_presentation_style_assignmentC(m_aggr3);
	
	char sfig_name[310];
	switch(sfigtype){
	case 1:
		//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
		//strcpy(sfig_name,"$$SXF_FM_");
		strcpy_s(sfig_name,_countof(sfig_name),"$$SXF_FM_");
		break;
	case 2:
		//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
		//strcpy(sfig_name,"$$SXF_FG_");
		strcpy_s(sfig_name,_countof(sfig_name),"$$SXF_FG_");
		break;
	case 3:
		//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
		//strcpy(sfig_name,"$$SXF_G_");
		strcpy_s(sfig_name,_countof(sfig_name),"$$SXF_G_");
		break;
	case 4:
		//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
		//strcpy(sfig_name,"$$SXF_P_");
		strcpy_s(sfig_name,_countof(sfig_name),"$$SXF_P_");
		break;
	default:
		return FALSE;
		break;
	}
	//	JPCERT/CC �w�E �Ǝ㐫�Ή�	T.Matsushima	2015.04.27
	//strcat(sfig_name,IN_Struct.name);
	strcat_s(sfig_name,_countof(sfig_name),IN_Struct.name);

	m_str6 = new SXFD_StrC(sfig_name);

	m_slist = new CStringList();
	m_slist->AddTail(DEF_ANNOTATION_OCCURRENCE);
	m_slist->AddTail(DEF_ANNOTATION_SUBFIGURE_OCCURRENCE);
	m_slist->AddTail(DEF_ANNOTATION_SYMBOL_OCCURRENCE);
	m_slist->AddTail(DEF_DRAUGHTING_ANNOTATION_OCCURRENCE);
	m_slist->AddTail(DEF_GEOMETRIC_REPRESENTATION_ITEM);
	m_aggr4 = new SXFD_AggrC() ;
	m_aggr4->AddElem( m_inst[5] ) ;
	m_inst[6] = new SXFE_styled_itemC(m_str6,m_aggr4,m_inst[4],m_slist) ;
	m_ID = m_inst[6]->GetInsID();

	m_TableManager->SetLayerElement(IN_Struct.layer,m_ID);

	return TRUE;

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFSfiglocMappingC.cpp								�쐬���F2001.06.19

	�P�D�N���X�T�v
	�C���X�^���X���o��

	�Q�D�C���^�[�t�F�[�X
	BOOL SXFSfiglocMappingC::WriteAP202(SXFPart21FileC *IN_File)
	����:	�^					������				���e
			SXFPart21FileC 		*IN_File	�t�@�C���I�u�W�F�N�g�̃A�h���X			

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.19			���X��(FQS)			�Ȃ��B

**/
BOOL SXFSfiglocMappingC::WriteAP202(SXFPart21FileC *IN_File)
{
	m_inst[6]->WriteP21(IN_File);
	return TRUE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFSfiglocMappingC.cpp								�쐬���F2001.06.19

	�P�D�N���X�T�v
	�C���X�^���X��ID��Ԃ��B

	�Q�D�C���^�[�t�F�[�X
	int	SXFSfiglocMappingC::GetID()
	����:	�^				������				���e
			�Ȃ�				

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.19			���X��(FQS)			�Ȃ��B

**/
int SXFSfiglocMappingC::GetID()
{
	return m_ID;
}
