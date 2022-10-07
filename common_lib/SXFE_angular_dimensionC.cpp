/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_angular_dimensionC.cpp								�쐬���F2000.4.18

	�P�D�N���X�T�v
	angular_dimension�̃G���e�B�e�B�f�[�^�Ǘ�

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/

#include "stdafx.h"
#include "SXFE_angular_dimensionC.h"
#include "SXFD_StrC.h"
#include "SXFD_AggrC.h"
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
	SXFE_angular_dimensionC.cpp								�쐬���F2000.4.18

	�P�D�@�\�T�v
	�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
	void	SXFE_angular_dimensionC(SXFD_StrC *str,SXFD_AggrC *aggr)
	����:	�^								������				���e
			SXFD_StrC						*str			��èè�ް�
			SXFD_StrC						*aggr			��èè�ް�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/
SXFE_angular_dimensionC::SXFE_angular_dimensionC(SXFD_StrC *str,SXFD_AggrC *aggr){

	m_Flg = 1;

	m_InstanceID = gl_InstanceID;
	gl_InstanceID += 10;

	m_Entity = DEF_ANGULAR_DIMENSION;

	m_Data.AddTail(str);
	m_Data.AddTail(aggr);

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_angular_dimensionC.cpp								�쐬���F2000.4.18

	�P�D�@�\�T�v
		�C���X�^���X���o��

	�Q�D�C���^�[�t�F�[�X
	void	WriteP21(SXFPart21FileC *IN_file)
	����:	�^								������				���e
			SXFPart21FileC					*IN_file		�t�@�C���I�u�W�F�N�g�̃A�h���X

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/
void	SXFE_angular_dimensionC::WriteP21(SXFPart21FileC *IN_file) {
	if(m_Flg){

		for( POSITION pos = m_Data.GetTailPosition(); pos != NULL;) {

			((SXFInstanceC*)m_Data.GetPrev(pos))->WriteP21(IN_file);

		}

		CString insID;
		insID.Format("#%d=(",m_InstanceID);
		IN_file->WriteString(insID);
		IN_file->WriteString("\n");

		IN_file->WriteString("ANGULAR_DIMENSION()\n");
		pos = m_Data.GetTailPosition();
		IN_file->WriteString("DIMENSION_CURVE_DIRECTED_CALLOUT()\n");
		IN_file->WriteString("DRAUGHTING_CALLOUT(");
		((SXFInstanceC*)m_Data.GetPrev(pos))->WriteAttr(IN_file);
		IN_file->WriteString(")\n");
		IN_file->WriteString("DRAUGHTING_ELEMENTS()\n");
		IN_file->WriteString("GEOMETRIC_REPRESENTATION_ITEM()\n");
		IN_file->WriteString("REPRESENTATION_ITEM(");
		((SXFInstanceC*)m_Data.GetPrev(pos))->WriteAttr(IN_file);
		IN_file->WriteString(")\n);\n");

		m_Flg = 0;

	}
}
