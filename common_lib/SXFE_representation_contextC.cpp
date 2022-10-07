/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_representation_contextC.cpp								�쐬���F2000.4.18

	�P�D�N���X�T�v
	�G���e�B�e�B�f�[�^�Ǘ�

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/

#include "stdafx.h"
#include "SXFE_representation_contextC.h"
#include "SXF_EXT.h"
#include "SXFPart21FileC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_representation_contextC.cpp								�쐬���F2000.4.18

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
	void SXFE_representation_contextC::SXFE_representation_contextC()
	
	����:	�^				������			���e
			�Ȃ��B

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/
SXFE_representation_contextC
::SXFE_representation_contextC(){

	m_Flg = 1;

	m_InstanceID = gl_InstanceID+20;
	gl_InstanceID += 30;

	m_Entity = DEF_REPRESENTATION_CONTEXT;
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_representation_contextC.cpp								�쐬���F2000.4.18

	�P�D�@�\�T�v
		�C���X�^���X�o��

	�Q�D�C���^�[�t�F�[�X
	void	WriteP21(SXFPart21FileC *IN_file)
	����:	�^				������			���e
			SXFPart21FileC 	*IN_file	�t�@�C���I�u�W�F�N�g�̃A�h���X

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/
void SXFE_representation_contextC::WriteP21(SXFPart21FileC *IN_file){


	CString unit_instance;
	CString endline("\n");
	CString angle_unit;
	angle_unit.Format("#%d",m_InstanceID-20);
	unit_instance += angle_unit;
	unit_instance += "=(";
	unit_instance += endline;
	unit_instance += "NAMED_UNIT(*)";
	unit_instance += endline;
	unit_instance += "PLANE_ANGLE_UNIT()";
	unit_instance += endline;
	unit_instance += "SI_UNIT($,.RADIAN.)";
	unit_instance += endline;
	unit_instance += ");";
	unit_instance += endline;
	CString length_unit;
	length_unit.Format("#%d",m_InstanceID-10);
	unit_instance += length_unit;
	unit_instance += "=(";
	unit_instance += endline;
	unit_instance += "LENGTH_UNIT()";
	unit_instance += endline;
	unit_instance += "NAMED_UNIT(*)";
	unit_instance += endline;
	unit_instance += "SI_UNIT(.MILLI.,.METRE.)";
	unit_instance += endline;
	unit_instance += ");";
	unit_instance += endline;
	CString rep_context;
	rep_context.Format("#%d",m_InstanceID);
	unit_instance += rep_context;
	unit_instance += "=(";
	unit_instance += endline;
	unit_instance += "GEOMETRIC_REPRESENTATION_CONTEXT(2)";
	unit_instance += endline;
	unit_instance += "GLOBAL_UNIT_ASSIGNED_CONTEXT((";
	unit_instance += angle_unit;
	unit_instance += ",";
	unit_instance += length_unit;
	unit_instance += "))";
	unit_instance += endline;
	unit_instance += "REPRESENTATION_CONTEXT('ID1','2D')";
	unit_instance += endline;
	unit_instance += ");";
	unit_instance += endline;
	IN_file->WriteString(unit_instance);

}
