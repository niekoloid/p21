/**
	All Rights Reserved,(c) JACIC 2001
	SXFSfigMappingC.cpp								�쐬���F2001.06.14

	�P�D�N���X�T�v
	�����}�`��`��Mapping

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.14			���X��(FQS)			�Ȃ��B

**/
#include "stdafx.h"
#include "SXFSfigMappingC.h"
#include "SXFD_InstC.h"
#include "SXFD_RealC.h"
#include "SXFD_StrC.h"
#include "SXFD_AggrC.h"
#include "SXFPart21FileC.h"
#include "SXFE_representation_contextC.h"
#include "SXFE_draughting_subfigure_representationC.h"
#include "SXFE_cartesian_pointC.h"
#include "SXFE_axis2_placement_2dC.h"
#include "SXFE_symbol_representation_mapC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFSfigMappingC.cpp								�쐬���F2001.06.14

	�P�D�@�\�T�v
	�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
	void	SXFSfigMappingC::SXFSfigMappingC()
	����:	�^				������				���e
			�Ȃ�				

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.14			���X��(FQS)			�Ȃ��B

**/
SXFSfigMappingC::SXFSfigMappingC()
{
	for (int i = 0; i < 5; i++){
		m_inst[i] = NULL;
	}
	m_elem_inst = NULL;
	m_aggr1 = NULL;
	m_aggr2 = NULL;
	m_str1 = NULL;
	m_str2 = NULL;
	m_str3 = NULL;
	m_str4 = NULL;
	m_real1 = NULL;
	m_real2 = NULL;

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFSfigMappingC.cpp								�쐬���F2001.06.14

	�P�D�@�\�T�v
	�f�X�g���N�^

	�Q�D�C���^�[�t�F�[�X
	void	SXFSfigMappingC::~SXFSfigMappingC()
	����:	�^				������				���e
			�Ȃ�				


	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.14			���X��(FQS)			�Ȃ��B

**/
SXFSfigMappingC::~SXFSfigMappingC()
{
#if 1
	SXFInstanceC::InitDeleteMap();
	if (m_inst[4] != NULL)
		delete m_inst[4];
	SXFInstanceC::EndDeleteMap();
#endif
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFSfigMappingC.cpp								�쐬���F2001.06.14

	�P�D�@�\�T�v
	Mapping���s���B

	�Q�D�C���^�[�t�F�[�X
	BOOL MappingStruct(Sfigorg_Struct IN_Struct,CUIntArray* IN_ChildrenID)
	����:	�^				������				���e
			Sfigorg_Struct	IN_Struct			�\����
			CUIntArray*		IN_ChildrenID		�����}�`��`���w���t�B�[�`���v�f��ID�z��
	���A�l	���펞�FTRUE
			�ُ펞�FFALSE

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.14			���X��(FQS)			�Ȃ��B

**/
BOOL SXFSfigMappingC::MappingStruct(Sfigorg_Struct IN_Struct,CUIntArray* IN_ChildrenID)
{

	////////////////////////////
	//�P�ʃC���X�^���X
	////////////////////////////
	m_inst[0] = new SXFE_representation_contextC();

	m_str1 = new SXFD_StrC(" ");
	m_aggr1 = new SXFD_AggrC() ;
	m_real1 = new SXFD_RealC(0.0);
	m_real2 = new SXFD_RealC(0.0);
	m_aggr1->AddElem(m_real1);
	m_aggr1->AddElem(m_real2);
	m_inst[1] = new SXFE_cartesian_pointC(m_str1,m_aggr1) ;

	m_str2 = new SXFD_StrC(" ");
	m_str3 = new SXFD_StrC(DEF_DOLLAR);
	m_inst[2] = new SXFE_axis2_placement_2dC(m_str2,m_inst[1],m_str3);

	char sfig_name[310];
	switch(IN_Struct.flag){
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
	m_str4 = new SXFD_StrC(sfig_name);
	///////////////////////////
	//�����}�`���w���v�f�̓o�^
	///////////////////////////
	m_aggr2 = new SXFD_AggrC();
	for (int i = 0; i < IN_ChildrenID->GetSize(); i++){
		m_elem_inst = new SXFD_InstC(IN_ChildrenID->GetAt(i));
		m_aggr2->AddElem(m_elem_inst);
	}
	m_aggr2->AddElem(m_inst[2]);
	m_inst[3] = new SXFE_draughting_subfigure_representationC(m_str4,m_aggr2,m_inst[0]);
	//
	m_inst[4] = new SXFE_symbol_representation_mapC(m_inst[2],m_inst[3]);
	m_ID = m_inst[4]->GetInsID();////////�����}�`�̂h�c

	return TRUE;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFSfigMappingC.cpp								�쐬���F2001.06.14

	�P�D�@�\�T�v
	�����}�`��`�̃L�[�C���X�^���X��ID��Ԃ��B

	�Q�D�C���^�[�t�F�[�X
	int GetID()
	����:	�^				������				���e
			�Ȃ�
	���A�l	�C���X�^���XID

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.14			���X��(FQS)			�Ȃ��B

**/
int SXFSfigMappingC::GetID()
{
	return m_ID;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFSfigMappingC.cpp								�쐬���F2001.06.14

	�P�D�@�\�T�v
	�����}�`��`���t�@�C���֏o�͂���

	�Q�D�C���^�[�t�F�[�X
	BOOL WriteAP202(SXFPart21FileC *IN_File)
	����:	�^					������				���e
			SXFPart21FileC*		IN_File				�t�@�C���I�u�W�F�N�g�̃A�h���X

	���A�l	���펞�FTRUE
			�ُ펞�FFALSE

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2001.06.14			���X��(FQS)			�Ȃ��B

**/
BOOL SXFSfigMappingC::WriteAP202(SXFPart21FileC *IN_File)
{
	m_inst[4]->WriteP21(IN_File);
	return TRUE;
}
