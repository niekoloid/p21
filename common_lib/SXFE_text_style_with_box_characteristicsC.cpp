/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_text_style_with_box_characteristicsC.cpp								�쐬���F2000.4.18

	�P�D�N���X�T�v
	�G���e�B�e�B�f�[�^�Ǘ�

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/

#include "stdafx.h"
#include "SXFD_StrC.h"
#include "SXFD_TypeC.h"
#include "SxFD_RealC.h"
#include "SXFD_AggrC.h"
#include "SXFE_text_style_with_box_characteristicsC.h"
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
	SXFE_text_style_with_box_characteristicsC.cpp								�쐬���F2000.4.18

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
	void	SXFE_text_style_with_box_characteristicsC(SXFD_StrC *str,
													  SXFD_InstC *inst,
													  SXFD_AggrC *aggr,
													  SXFD_TypeC *type1)
	����:	�^				������			���e
			SXFD_StrC 		*str				��èè�ް�
			SXFD_InstC 		*inst				��èè�ް�
			SXFD_AggrC 		*aggr				��èè�ް�
			SXFD_TypeC 		*type1				��èè�ް�

	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/
SXFE_text_style_with_box_characteristicsC
:: SXFE_text_style_with_box_characteristicsC(SXFD_StrC *str,SXFD_InstC *inst,SXFD_AggrC *aggr,SXFD_TypeC *type1){

	m_Flg = 1;

	m_InstanceID = gl_InstanceID;
	gl_InstanceID += 10;

	m_Entity = DEF_TEXT_STYLE_WITH_BOX_CHARACTERISTICS;

	m_Data.AddTail(str);
	m_Data.AddTail(inst);
	m_Data.AddTail(aggr);
	m_Data.AddTail(type1);

}

/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_text_style_with_box_characteristicsC.cpp								�쐬���F2000.4.18

	�P�D�@�\�T�v
		�C���X�^���X�̏o��

	�Q�D�C���^�[�t�F�[�X
	SXFE_text_style_with_box_characteristicsC::WriteP21(SXFPart21FileC *IN_file)
	����:	�^				������			���e
	SXFPart21FileC		 *IN_file	̧�ٵ�޼ު��
  
	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/
void	SXFE_text_style_with_box_characteristicsC::WriteP21(SXFPart21FileC *IN_file) {
	if(m_Flg){

		for( POSITION pos = m_Data.GetTailPosition(); pos != NULL;) {

			((SXFInstanceC*)m_Data.GetPrev(pos))->WriteP21(IN_file);

		}

		pos = m_Data.GetHeadPosition();
		CString insID;
		insID.Format("#%d=(",m_InstanceID);
		IN_file->WriteString(insID);
		IN_file->WriteString("\n");
		IN_file->WriteString("TEXT_STYLE(") ;
		((SXFInstanceC*)m_Data.GetNext(pos))->WriteAttr(IN_file);
		IN_file->WriteString(",") ;
		((SXFInstanceC*)m_Data.GetNext(pos))->WriteAttr(IN_file);
		IN_file->WriteString(")\n") ;
		IN_file->WriteString("TEXT_STYLE_WITH_BOX_CHARACTERISTICS(") ;
		((SXFInstanceC*)m_Data.GetNext(pos))->WriteAttr(IN_file);
		IN_file->WriteString(")\n") ;
		IN_file->WriteString("TEXT_STYLE_WITH_SPACING(") ;
		((SXFInstanceC*)m_Data.GetNext(pos))->WriteAttr(IN_file);
		IN_file->WriteString(")\n") ;
		IN_file->WriteString(");\n") ;

		m_Flg = 0;

	}
}
