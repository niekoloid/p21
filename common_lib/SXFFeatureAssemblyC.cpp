//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFFeatureAssemblyC.cpp				   �쐬���F2001.06.20
//
//	�P�D�N���X�T�v
//		Feature Assembly�̐e�q�֌W���Ǘ�����
//
//	�Q�D����
//		����ԍ�	���t��		   �S����	 �T�v
//		�쐬		2001.06.20	   ���X��(FQS)		  �Ȃ�
//
//------------------------------------------------------------
#include "stdafx.h"
#include "SXFFeatureAssemblyC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFFeatureAssemblyC.cpp					�쐬���F2001.06.20
//
//  �P�D�@�\�T�v
//      �R���X�g���N�^
//
//  �Q�D�C���^�[�t�F�[�X
//		void	SXFFeatureAssemblyC::SXFFeatureAssemblyC()
//		
//	����	�F	�^		������				���e
//		�Ȃ�
//
//	�R�D����
//		����ԍ�	���t��		   �S����	 �T�v
//		�쐬		2001.06.20	   ���X��(FQS)		  �Ȃ�
//
//------------------------------------------------------------
SXFFeatureAssemblyC::SXFFeatureAssemblyC()
{
	AssemblyCode = -1;
	AssemblyID = -1;
	ChildList = NULL;
	AssemSymbolType = -1;
	AssemSheetType = -1;
	AssemSheetX = 0;
	AssemSheetY = 0;
	AssemSheetOrient = -1;
	AssemCurveFlag = -1;
	m_CurveColour = 0;
	m_CurveType = 0;
	m_CurveWidth = 0;
	m_SfigLocateFlag = -1;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFFeatureAssemblyC.cpp				   �쐬���F2001.06.20
//
//  �P�D�@�\�T�v
//      �f�X�g���N�^
//
//  �Q�D�C���^�[�t�F�[�X
//		void	SXFFeatureAssemblyC::~SXFFeatureAssemblyC()
//		
//	����	�F	�^		������				���e
//		�Ȃ�
//
//	�R�D����
//		����ԍ�	���t��		   �S����	 �T�v
//		�쐬		2001.06.20	   ���X��(FQS)		  �Ȃ�
//
//------------------------------------------------------------
SXFFeatureAssemblyC::~SXFFeatureAssemblyC()
{
	if(ChildList != NULL){
		POSITION childpos = ChildList->GetHeadPosition();
		while(childpos!=NULL){
			SXFFeatureChildC* child = ChildList->GetAt(childpos);
			if(child!=NULL)
				delete child;
			ChildList->GetNext(childpos);
		}
		delete ChildList;
	}
}
