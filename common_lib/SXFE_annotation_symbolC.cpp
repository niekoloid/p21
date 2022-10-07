/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_annotation_symbolC.cpp								�쐬���F2000.4.18

	�P�D�N���X�T�v
	annotation_fill_area�̃G���e�B�e�B�f�[�^�Ǘ�

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/

#include "stdafx.h"
#include "SXFE_annotation_symbolC.h"
#include "SXFD_StrC.h"
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
	SXFE_annotation_symbolC.cpp								�쐬���F2000.4.18

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
	void	SXFE_annotation_symbolC(SXFD_InstC* ins1,SXFD_InstC* ins2,SXFD_StrC* str1)
	����:	�^								������				���e
			SXFD_InstC*						ins1		��èè�ް�
			SXFD_InstC* 					ins2		��èè�ް�
			SXFD_StrC*						str1		��èè�ް�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/
SXFE_annotation_symbolC
:: SXFE_annotation_symbolC(SXFD_InstC* ins1,SXFD_InstC* ins2,SXFD_StrC* str1){

	m_Flg = 1;

	m_InstanceID = gl_InstanceID;
	gl_InstanceID += 10;

	m_Entity = DEF_ANNOTATION_SYMBOL;

	m_Data.AddTail(ins1);
	m_Data.AddTail(ins2);
	m_Data.AddTail(str1);
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_annotation_symbolC.cpp								�쐬���F2000.4.18

	�P�D�@�\�T�v

	�Q�D�C���^�[�t�F�[�X
	void	WriteP21(SXFPart21FileC *IN_file)
	����:	�^								������				���e
			SXFPart21FileC					*IN_file	�t�@�C���I�u�W�F�N�g�̃A�h���X

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/
void SXFE_annotation_symbolC::WriteP21(SXFPart21FileC *IN_file)
{
	if(m_Flg){

		for( POSITION pos = m_Data.GetTailPosition(); pos != NULL;) {

			((SXFInstanceC*)m_Data.GetPrev(pos))->WriteP21(IN_file);

		}

		pos = m_Data.GetHeadPosition();
		CString insID;
		insID.Format("#%d=(",m_InstanceID);
		IN_file->WriteString(insID);
		IN_file->WriteString("\n");

		IN_file->WriteString("ANNOTATION_SYMBOL()\n");
		IN_file->WriteString("GEOMETRIC_REPRESENTATION_ITEM()\n");
		IN_file->WriteString("MAPPED_ITEM(") ;
		((SXFInstanceC*)m_Data.GetNext(pos))->WriteAttr(IN_file);
		IN_file->WriteString(",") ;
		((SXFInstanceC*)m_Data.GetNext(pos))->WriteAttr(IN_file);
		IN_file->WriteString(")\n");
		IN_file->WriteString("REPRESENTATION_ITEM(") ;
		((SXFInstanceC*)m_Data.GetNext(pos))->WriteAttr(IN_file);
		IN_file->WriteString(")\n");
		IN_file->WriteString(");\n");

		m_Flg = 0;

	}
}
