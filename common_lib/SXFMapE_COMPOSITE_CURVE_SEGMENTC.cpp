/**
	All Rights Reserved,(c) JACIC 2001
	SXFMapE_COMPOSITE_CURVE_SEGMENTC.cpp						�쐬���F2000.04.17

	�P�D�N���X�T�v
		COMPOSITE_CURVE_SEGMENT���Ǘ�����N���X

	�Q�D����
		����ԍ�	���t��		�S����		�T�v
		�쐬		2000.04.17	

**/
#include "stdafx.h"
#include "SXFMapE_COMPOSITE_CURVE_SEGMENTC.h"
#include "SXFMapE_CARTESIAN_POINTC.h"
#include "SXFMapE_LINEC.h"
#include "SXFMapE_CIRCLEC.h"
#include "SXFMapEntAConvC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_COMPOSITE_CURVE_SEGMENTC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�f�t�H���g�R���X�g���N�^

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_COMPOSITE_CURVE_SEGMENTC::SXFMapE_COMPOSITE_CURVE_SEGMENTC()

	����  �F	�^			������				���e
			�Ȃ�
	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_COMPOSITE_CURVE_SEGMENTC::SXFMapE_COMPOSITE_CURVE_SEGMENTC()
{
//	<������>
	m_EntityName = DEF_COMPOSITE_CURVE_SEGMENT;

//<�G���e�B�e�B�f�[�^>
//#1201 = ANNOTATION_FILL_AREA('annotation_fill_area2', (#1121, #1181));
//#1181 = COMPOSITE_CURVE('composite_curve4', (#1140, #1160), .F.);
//#1160 = COMPOSITE_CURVE_SEGMENT(.CONTINUOUS., .T., #1165);

	//1.transition_code
	m_tran_code =0;
//		1:discontinuous,
//		2:continuous,//
//		3:cont_same_gradient,
//		4:cont_same_gradient_same_curvature

	//2.parent_curve �ւ̃C���X�^���XID
	m_parent_curve_Inst=0;

	//parent_curve�ւ̃|�C���^
	m_parent_curve_P =NULL;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_COMPOSITE_CURVE_SEGMENTC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�C���X�^���X�h�c�ւ̃|�C���^���w�肵�Đ�������ꍇ
		(�R���X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_COMPOSITE_CURVE_SEGMENTC::SXFMapE_COMPOSITE_CURVE_SEGMENTC(
						SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
					

	�����F	�^				������				���e
			SXFInstanceIDC* IN_InstanceIDManeger	�ݽ�ݽID�Ǘ���޼ު��

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_COMPOSITE_CURVE_SEGMENTC::SXFMapE_COMPOSITE_CURVE_SEGMENTC(
		SXFInstanceIDC* IN_InstanceIDManeger)
		:SXFMapEntityBaseC(IN_InstanceIDManeger)
{
//	<������>
	m_EntityName = DEF_COMPOSITE_CURVE_SEGMENT;
//<�G���e�B�e�B�f�[�^>
//#1201 = ANNOTATION_FILL_AREA('annotation_fill_area2', (#1121, #1181));
//#1181 = COMPOSITE_CURVE('composite_curve4', (#1140, #1160), .F.);
//#1160 = COMPOSITE_CURVE_SEGMENT(.CONTINUOUS., .T., #1165);

	//1.transition_code
	m_tran_code =0;
//		1:discontinuous,
//		2:continuous,//
//		3:cont_same_gradient,
//		4:cont_same_gradient_same_curvature

	//2.parent_curve �ւ̃C���X�^���XID
	m_parent_curve_Inst=0;

	//parent_curve�ւ̃|�C���^
	m_parent_curve_P =NULL;

}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_COMPOSITE_CURVE_SEGMENTC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		(�f�X�g���N�^)

	�Q�D�C���^�[�t�F�C�X
		void	SXFMapE_COMPOSITE_CURVE_SEGMENTC::~SXFMapE_COMPOSITE_CURVE_SEGMENTC()

	����  �F	�^			������				���e
			�Ȃ�

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/
SXFMapE_COMPOSITE_CURVE_SEGMENTC::~SXFMapE_COMPOSITE_CURVE_SEGMENTC()
{
}

/**
	All Rights Reserved,(c)JACIC 2001
	SXFMapE_COMPOSITE_CURVE_SEGMENTC.cpp						�쐬���F2000.04.17

	�P�D�@�\�T�v
		�G���e�B�e�B�̃p�����^�ݒ�

	�Q�D�C���^�[�t�F�C�X
		int		SXFMapE_COMPOSITE_CURVE_SEGMENTC::SetParameter()

	����  �F	�^			������				���e

	���A�l�F�Ȃ�

	�R�D����
	����ԍ�	���t��		�S����			�T�v
	�쐬		2000.04.17	
**/

int SXFMapE_COMPOSITE_CURVE_SEGMENTC::SetParameter()

{
//	<1. �G���e�B�e�B�p�����^�̐ݒ�> ////////////////////////////////////////

//<�G���e�B�e�B�f�[�^>
//#1201 = ANNOTATION_FILL_AREA('annotation_fill_area2', (#1121, #1181));
//#1181 = COMPOSITE_CURVE('composite_curve4', (#1140, #1160), .F.);
//#1160 = COMPOSITE_CURVE_SEGMENT(.CONTINUOUS., .T., #1165);

	SXFMapEntAConvC convert(m_EntityArray);
	//1.transition_code
//	m_tran_code =0;           ///////////////////////�ۗ�
//		1:discontinuous,
//		2:continuous,//
//		3:cont_same_gradient,
//		4:cont_same_gradient_same_curvature	convent.GetCString(0,m_name);

	//2.sense_agreement
	convert.GetBOOL(1,m_sense);	

	//	2.parent_curve �ւ̃C���X�^���XID
	convert.GetInst(2,m_parent_curve_Inst);

//	<3. parent_curve //////////////////////////////////////////////////////////

	return 0;
}
