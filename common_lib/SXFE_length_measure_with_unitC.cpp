/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_length_measure_with_unitC.cpp								�쐬���F2000.4.18

	�P�D�N���X�T�v
	�G���e�B�e�B�f�[�^�Ǘ�

	�Q�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/

#include "stdafx.h"
#include "SXFD_TypeC.h"
#include "SXFE_length_measure_with_unitC.h"
#include "SXF_EXT.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c) JACIC 2001
	SXFE_length_measure_with_unitC.cpp								�쐬���F2000.4.18

	�P�D�@�\�T�v
		�R���X�g���N�^

	�Q�D�C���^�[�t�F�[�X
	void	SXFE_length_measure_with_unitC(SXFD_TypeC *type1,SXFD_InstC *inst)
	����:	�^						������				���e
			SXFD_TypeC				*type1				��èè�ް�
			SXFD_InstC				*inst				��èè�ް�
								
	�R�D����
	����ԍ�		���t��				�S����				�T�v
	�쐬			2000.4.18			�{��(FQS)			�Ȃ��B

**/
SXFE_length_measure_with_unitC 
:: SXFE_length_measure_with_unitC(SXFD_TypeC *type1,SXFD_InstC *inst){

	m_Flg = 1;

	m_InstanceID = gl_InstanceID;
	gl_InstanceID += 10;

	m_Entity = DEF_LENGTH_MEASURE_WITH_UNIT;

	m_Data.AddTail(type1);
	m_Data.AddTail(inst);

}
