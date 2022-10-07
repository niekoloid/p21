/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_presentation_sizeC.cpp								�쐬���F2000.4.18

	�P�D�N���X�T�v
	�G���e�B�e�B�f�[�^�Ǘ�

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/

#include "stdafx.h"
#include "SXFE_presentation_sizeC.h"
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
	SXFE_presentation_sizeC.cpp								�쐬���F2000.4.18

	�P�D�@�\�T�v
		�R���X�g���N�^
	
	�Q�D�C���^�[�t�F�[�X
	void	SXFE_presentation_sizeC(SXFD_InstC *inst1,SXFD_InstC *inst2)
	����:	�^				������			���e
			SXFD_InstC 		*inst1				��èè�ް�
			SXFD_InstC 		*inst2				��èè�ް�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/
SXFE_presentation_sizeC
::SXFE_presentation_sizeC(SXFD_InstC *inst1,SXFD_InstC *inst2){

	m_Flg = 1;

	m_InstanceID = gl_InstanceID;
	gl_InstanceID += 10;

	m_Entity = DEF_PRESENTATION_SIZE;

	m_Data.AddTail(inst1);
	m_Data.AddTail(inst2);
}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_presentation_sizeC.cpp								�쐬���F2000.4.18

	�P�D�@�\�T�v
		�C���X�^���X�̏o��

	�Q�D�C���^�[�t�F�[�X
	void	SXFE_presentation_sizeC::WriteP21(SXFPart21FileC *IN_file)
	����:	�^				������			���e
			SXFPart21FileC 	*IN_file	�t�@�C���I�u�W�F�N�g�̃A�h���X

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/
void	SXFE_presentation_sizeC::WriteP21(SXFPart21FileC *IN_file) {

	if(m_Flg){

		CString instID;
		instID.Format("#%d=%s",m_InstanceID,m_Entity);
		IN_file->WriteString(instID);
		int Flg = 0;
		for(POSITION pos = m_Data.GetHeadPosition(); pos != NULL;) {

			if(Flg == 0){
				IN_file->WriteString("(");
				Flg =1;
			}
			else{
				IN_file->WriteString(",");
			}

			((SXFInstanceC*)m_Data.GetNext(pos))->WriteAttr(IN_file);

		}
		IN_file->WriteString(");");
		IN_file->WriteString("\n");
		m_Flg = 0;
	}
}
