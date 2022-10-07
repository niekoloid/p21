//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFWriteManagerC.cpp                    �쐬���F2001.06.18
//
//	�P�D�N���X�T�v
//      �o�͎��̃A�Z���u���Ԃ̎Q�Ɗ֌W���Ǘ�����
//
//	�Q�D����
//	    ����ԍ�    ���t��         �S����    �T�v
//      �쐬		2001.06.18    ���X��(FQS)
//
//------------------------------------------------------------

#include "stdafx.h"
#include "SXFWriteManagerC.h"
#include "SXFPart21FileC.h"
#include "SXFTableManagerC.h"
#include "SXFErrorMsgC.h"
#include "SXFPart21FileWriteC.h"
#include "SXFComInfoC.h"
#include "SXFInstanceIDC.h"
#include "SXFComndef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFWriteManagerC.cpp                    �쐬���F2001.06.18
//
//  �P�D�@�\�T�v
//      �N���X�\�z
//
//  �Q�D�C���^�[�t�F�[�X
//	void	SXFWriteManagerC::SXFWriteManagerC()
//	����:	�^								������				���e
//			�Ȃ�					
//
//  �R�D����
//	    ����ԍ�    ���t��         �S����    �T�v
//      �쐬		2001.06.18    ���X��(FQS)
//
//------------------------------------------------------------
SXFWriteManagerC::SXFWriteManagerC()
{
	//initialization
	m_ChildrenArray = NULL;
	m_CurrentAssembly = NULL;
	m_SheetAssemblyFlag=FALSE;
	m_CurrentChild = NULL;
	m_FirstAssemblyFlag=TRUE;
	m_AssemType = -1;
	m_CurveViewFlag = -1;
	m_SfigFlag = -1;
	m_SfigTableIndex = 0;
	m_PointX = 0.0;
	m_PointY = 0.0;
	m_PointN = 0;
	m_ErrorFlag = FALSE;
	m_CurveFlag = 0;
	m_AssemblyCode = 1;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFWriteManagerC.cpp                    �쐬���F2001.06.18
//
//  �P�D�@�\�T�v
//      �N���X�\�z
//
//  �Q�D�C���^�[�t�F�[�X
//		void	SXFWriteManagerC::SXFWriteManagerC(
//								SXFPart21FileWriteC* IN_WriteFile,
//								SXFInstanceIDC* IN_InstanceIDManager)
//
//		
//	�����F�^					������					���e
//		  SXFPart21FileWriteC*	IN_WriteFile			̧�ُo�͵�޼ު��
//		  SXFInstanceIDC*		IN_InstanceIDManager	�ݽ�ݽID��޼ު��
//
//  �R�D����
//	    ����ԍ�    ���t��         �S����    �T�v
//      �쐬		2001.06.18    ���X��(FQS)
//
//------------------------------------------------------------
SXFWriteManagerC::SXFWriteManagerC(
						SXFPart21FileC*			IN_File,
						SXFTableManagerC*		IN_TableManager,
						SXFComInfoC*			IN_ComInfo,
						SXFPart21FileWriteC*	IN_WriteFile,
						SXFInstanceIDC*			IN_InstanceIDManager)
{
	//initialization
	m_ChildrenArray = NULL;
	m_CurrentAssembly = NULL;
	m_SheetAssemblyFlag=FALSE;
	m_CurrentChild = NULL;
	m_FirstAssemblyFlag=TRUE;
	m_Part21File = IN_File;
	m_TableManager = IN_TableManager;
	m_ComInfo = IN_ComInfo;
	m_WriteFile = IN_WriteFile;
	m_InstanceIDManager = IN_InstanceIDManager;
	m_AssemType = -1;
	m_CurveViewFlag = -1;
	m_SfigFlag = -1;
	m_SfigTableIndex = 0;
	m_PointX = 0.0;
	m_PointY = 0.0;
	m_PointN = 0;
	m_ErrorFlag = FALSE;
	m_CurveFlag = 0;
	m_AssemblyCode = 1;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFWriteManagerC.cpp                    �쐬���F2001.06.18
//
//  �P�D�@�\�T�v
//      �N���X����
//
//  �Q�D�C���^�[�t�F�[�X
//	void	SXFWriteManagerC::~SXFWriteManagerC()
//	����:	�^								������				���e
//			�Ȃ�					
//
//  �R�D����
//	    ����ԍ�    ���t��         �S����    �T�v
//      �쐬		2001.06.18    ���X��(FQS)
//
//------------------------------------------------------------
SXFWriteManagerC::~SXFWriteManagerC()
{
	if (m_CurrentAssembly != NULL)
		delete m_CurrentAssembly;
	if (m_ChildrenArray != NULL)
		delete m_ChildrenArray;
	if (m_CurrentChild != NULL)
		delete m_CurrentChild;

//	MOD(S)	�`���[�j���O�Ή�	K.Naono	03.07.08
	for( POSITION pos = m_SfigorgTable.GetHeadPosition(); pos; ) {
		SXFSFIGORGCHECK*	pSfigOrg = m_SfigorgTable.GetNext(pos) ;
		delete pSfigOrg ;
	}
//	MOD(E)	�`���[�j���O�Ή�	K.Naono	03.07.08
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFWriteManagerC.cpp                    �쐬���F2001.06.18
//
//  �P�D�@�\�T�v
//      Assembly�v�f�̓o�^
//
//  �Q�D�C���^�[�t�F�[�X
//      int RegisterAssembly(int IN_AssemblyType,LPVOID IN_Struct)
//
//	    ����: �^			  ������			    ���e
//            int             IN_AssemblyType      Assembly Type
//            LPVOID          IN_Struct            Assembly�v�f��
//                                                 �\���̂̃A�h���X
//      
//	    ���A�l	
//            ���펞�FAssembly�v�f��Code
//			  �ُ펞�F-1
//
//  �R�D����
//	    ����ԍ�    ���t��         �S����    �T�v
//      �쐬		2001.06.18    ���X��(FQS)
//		�X�V		2001.09.18		K.Naono		�n�b�`���O��Q�Ή�
//
//------------------------------------------------------------
int SXFWriteManagerC::RegisterAssembly(int IN_AssemblyType,LPVOID IN_Struct)
{
	/** ���łɗp��������ꍇ **/
	if( m_SheetAssemblyFlag == TRUE){
		m_AssemType = -1;	/* �A�Z���u���͊J����Ă��Ȃ� */
		/* �p�� */
		if (IN_AssemblyType == 1){
			/* �p���͂P�����ݒ�ł��Ȃ� */
			SXFErrorMsgC::RecordError(SXFSHEETONE,
										DEF_SHEET,
										0);
			return SXFSHEETONE;
		}
		else if (IN_AssemblyType == 2){
			/* �����}�`��ɗp���͔z�u�ł��Ȃ� */
			SXFErrorMsgC::RecordError(SXFSFIGLOCERR,
										DEF_SFIG_ORG,
										0);
			return SXFSFIGLOCERR;
		}
		else if (IN_AssemblyType == 3){
			/* �����Ȑ���ɂ͗p���͔z�u�ł��Ȃ� */
			SXFErrorMsgC::RecordError(SXFCURVELOCERR,
										DEF_COMPOSITE_CURVE_ORG,
										0);
			return SXFCURVELOCERR;
		}
	}
	/** �p�� **/
	if(IN_AssemblyType == 1)
		m_SheetAssemblyFlag=TRUE;
	/** �����}�` **/
	if(IN_AssemblyType == 2){
//	MOD(S)	�`���[�j���O�Ή�	K.Naono	03.07.08
/*
		SXFSFIGORGCHECK sfigorgcheck;
		sfigorgcheck.name = ((Sfigorg_Struct*)IN_Struct)->name;
		sfigorgcheck.type = ((Sfigorg_Struct*)IN_Struct)->flag;
		sfigorgcheck.flag = -1;
		sfigorgcheck.ID = -1;
		sfigorgcheck.locate_flag = -1;
		sfigorgcheck.error = -1;
		m_SfigorgTable.Add(sfigorgcheck );
*/
		SXFSFIGORGCHECK*	pSfigOrg = new SXFSFIGORGCHECK ;
		pSfigOrg->name = ((Sfigorg_Struct*)IN_Struct)->name ;
		pSfigOrg->type = ((Sfigorg_Struct*)IN_Struct)->flag ;
		m_SfigorgTable.AddTail(pSfigOrg) ;
		m_mapSfigOrg.SetAt(pSfigOrg->name, pSfigOrg) ;
//	MOD(E)	�`���[�j���O�Ή�	K.Naono	03.07.08
	}

	//AssemblyType set
	m_AssemType = IN_AssemblyType;
	//�ŏ��̃A�Z���u��
	if(m_FirstAssemblyFlag){
		/** WriteMapping�Ǘ��I�u�W�F�N�g���� **/
		m_CurrentAssembly = new SXFWriteMappingManagerC(m_Part21File,m_TableManager,
									m_AssemType,&m_AssemblyTable,&m_PointTable,
//	MOD(S)	�`���[�j���O�Ή�	K.Naono	03.07.08
//									&m_SfigorgTable,m_ComInfo,m_WriteFile,
									&m_mapSfigOrg,m_ComInfo,m_WriteFile,
//	MOD(E)	�`���[�j���O�Ή�	K.Naono	03.07.08
									m_InstanceIDManager);
		/**�\���̾��**/
		m_CurrentAssembly->SetStructData(IN_AssemblyType,IN_Struct);
		/** FirstAssemblyFlag ��OFF **/
		m_FirstAssemblyFlag=!m_FirstAssemblyFlag;
		/** ChildrenArray�𐶐� **/
		m_ChildrenArray = new CUIntArray();
		if(IN_AssemblyType == 3 &&
			((Ccurve_Org_Struct*)IN_Struct)->flag == 0 ){
			m_CurveViewFlag = 0;
		}else{
			m_CurveViewFlag = 1;
		}

		if (IN_AssemblyType == 2)
			m_SfigFlag = 1;
		else
			m_SfigFlag = 0;
	}else{ //not the first assembly
		//assembly must have children
		if (m_ChildrenArray->GetSize() <= 0){
			/* �O��Ă��������ؗv�f���װ */
			if (m_ErrorFlag)
				m_ErrorFlag = FALSE;
			else{
				if (m_SfigFlag == 1){
					/** �����}�`��`���G���[ **/
//	MOD(S)	�`���[�j���O�Ή�	K.Naono	03.07.08
/*
					m_SfigorgTable[m_SfigTableIndex].error = -1;
*/
					POSITION	pos = m_SfigorgTable.FindIndex(m_SfigTableIndex) ;
					if( pos != NULL ) {
						SXFSFIGORGCHECK*	pSfigOrg = m_SfigorgTable.GetAt(pos) ;
						pSfigOrg->error = -1 ;
					}
//	MOD(E)	�`���[�j���O�Ή�	K.Naono	03.07.08
					m_SfigTableIndex++;
				}
				/* �����Ȑ� */
				if (m_CurveFlag == 1)
					/* �����Ȑ��e�[�u������G���[�̃A�Z���u���R�[�h���폜 */
//	MOD(S)	�`���[�j���O�Ή�	K.Naono	03.07.09
//					m_CurveTable.RemoveAt(m_CurveTable.GetSize()-1);
					m_CurveTable.RemoveTail() ;
//	MOD(E)	�`���[�j���O�Ή�	K.Naono	03.07.09
					/* �A�Z���u���v�f��ɗv�f���Ȃ� */
					SXFErrorMsgC::RecordError(SXFNOTFEATURE,"",0);
			}
		}
		else{
			int assemblyid1 = 0;
			int assemblyid2 = 0;
			int pointid = 0;

			double pointx = 0.0;
			double pointy = 0.0;

			if( m_PointN && m_PointX )
				pointx=m_PointX/m_PointN;
			if( m_PointN && m_PointY )
				pointy=m_PointY/m_PointN;
			/** �A�Z���u���v�f��Mapping **/
			if(! m_CurrentAssembly->MappingAssembly(m_ChildrenArray,
						assemblyid1, assemblyid2, pointid, pointx, pointy )) {
				/* Mapping�Ɏ��s */

				/** �����}�`��` **/
				if (m_SfigFlag == 1){
					/* �����}�`�e�[�u���̃G���[�t���O��ON */
//	MOD(S)	�`���[�j���O�Ή�	K.Naono	03.07.08
/*
					m_SfigorgTable[m_SfigTableIndex].error = -1;
*/
					POSITION	pos = m_SfigorgTable.FindIndex(m_SfigTableIndex) ;
					if( pos != NULL ) {
						SXFSFIGORGCHECK*	pSfigOrg = m_SfigorgTable.GetAt(pos) ;
						pSfigOrg->error = -1 ;
					}
//	MOD(E)	�`���[�j���O�Ή�	K.Naono	03.07.08
					m_SfigTableIndex++;
				}
				/* �����Ȑ� */
				if (m_CurveFlag == 1)
					/* �����Ȑ��e�[�u������G���[�̃A�Z���u���R�[�h���폜 */
//	MOD(S)	�`���[�j���O�Ή�	K.Naono	03.07.09
//					m_CurveTable.RemoveAt(m_CurveTable.GetSize()-1);
					m_CurveTable.RemoveTail() ;
//	MOD(E)	�`���[�j���O�Ή�	K.Naono	03.07.09
			}
			else{
				if (m_SfigFlag == 1){
					/* �����}�`�e�[�u���̃G���[�t���O��OFF */
//	MOD(S)	�`���[�j���O�Ή�	K.Naono	03.07.08
/*
					m_SfigorgTable[m_SfigTableIndex].error = 1;
					m_SfigorgTable[m_SfigTableIndex].ID = assemblyid1;
*/
					POSITION	pos = m_SfigorgTable.FindIndex(m_SfigTableIndex) ;
					if( pos != NULL ) {
						SXFSFIGORGCHECK*	pSfigOrg = m_SfigorgTable.GetAt(pos) ;
						pSfigOrg->error	= 1 ;
						pSfigOrg->ID	= assemblyid1 ;
					}
//	MOD(S)	�`���[�j���O�Ή�	K.Naono	03.07.08
					m_SfigTableIndex++;
				}
				/** �A�Z���u���R�[�h���{�P **/
				m_AssemblyCode++;
			}
			/* �f�[�^�̃N���A */
			m_ChildrenArray->RemoveAll();	
			m_CurrentAssembly->ClearData();

			m_PointX = 0.0;
			m_PointY = 0.0;
			m_PointN = 0;

			//CARTESIAN_POINT_TABLE
//	MOD(S)	�n�b�`���O��Q�Ή�	K.Naono		01.09.18
//			m_PointTable.Add(pointid);
			SXF_POINT	point ;
			point.x = pointx ; point.y = pointy ;
			m_PointTable.Add(point) ;
//	MOD(E)	�n�b�`���O��Q�Ή�	K.Naono		01.09.18

			if(m_CurveViewFlag == 0){
				m_InvisibilityCurveTable.Add(assemblyid1);
			}

			m_AssemblyTable.Add(assemblyid2);
		}
	}

	/** �����Ȑ���` **/
	if(IN_AssemblyType == 3){
		/* �����Ȑ��t���OON */
		m_CurveFlag = 1;
		/* �����Ȑ��e�[�u���ɃA�Z���u���R�[�h�ǉ� */
//	MOD(S)	�`���[�j���O�Ή�	K.Naono	03.07.09
//		m_CurveTable.Add(m_AssemblyCode);
		m_CurveTable.AddTail(m_AssemblyCode) ;
//	MOD(E)	�`���[�j���O�Ή�	K.Naono	03.07.09
	}else{
		m_CurveFlag = 0 ;
	}
	/** �����}�` **/
	if (IN_AssemblyType == 2)
		m_SfigFlag = 1;	/* SfigFlag ��ON */
	else
		m_SfigFlag = -1;	/* SfigFlag ��OFF */

	if(IN_AssemblyType == 3 &&
		((Ccurve_Org_Struct*)IN_Struct)->flag == 0 ){
		m_CurveViewFlag = 0;	/* CurveViewFlag ��ON */
	}else{
		m_CurveViewFlag = 1;	/* CurveViewFlag ��OFF */
	}
	/** �A�Z���u���\���̂��Z�b�g **/
	m_CurrentAssembly->SetStructData(IN_AssemblyType,IN_Struct);

	return m_AssemblyCode;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFWriteManagerC.cpp                    �쐬���F2001.06.18
//
//  �P�D�@�\�T�v
//      Feature�v�f�\���̂̓o�^
//
//  �Q�D�C���^�[�t�F�[�X
//      int RegisterFeature(char* IN_FeatureType,LPVOID IN_Struct)
//
//	    ����: �^			  ������			    ���e
//            char*          IN_FeatureType        Feature�v�f��
//                                                 TypeName
//            LPVOID          IN_Struct            Feature�v�f��
//                                                 �\���̂̃A�h���X
//      
//	    ���A�l	
//            ���펞�F�v�f��ID
//			  �ُ펞�F���̑�-1
//      
//  �R�D����
//	    ����ԍ�    ���t��         �S����    �T�v
//      �쐬		2001.06.18    ���X��(FQS)
//
//------------------------------------------------------------

int SXFWriteManagerC::RegisterFeature(char* IN_FeatureType,LPVOID IN_Struct)
{
	/* �A�Z���u���v�f���J����Ă��Ȃ� */
	if (m_AssemType == -1){
		SXFErrorMsgC::RecordError(SXFNOTASSEMBLY,IN_FeatureType,0);
		return SXFNOTASSEMBLY;
	}
	/* Mapping�Ǘ���޼ު�Ă𐶐� */
	m_CurrentChild = new SXFWriteMappingManagerC(m_Part21File,m_TableManager,
								m_AssemType,&m_AssemblyTable,&m_PointTable,
//	MOD(S)	�`���[�j���O�Ή�	K.Naono	03.07.08
//								&m_SfigorgTable,m_ComInfo,m_WriteFile,m_InstanceIDManager);
								&m_mapSfigOrg,m_ComInfo,m_WriteFile,m_InstanceIDManager);
//	MOD(E)	�`���[�j���O�Ή�	K.Naono	03.07.08

	int childid1=-1;
	int childid2=-1;
	if (!m_CurrentChild->MappingFeature(IN_FeatureType,IN_Struct,childid1,
								childid2,m_PointX,m_PointY,m_PointN))
		return childid1;

//	MOD(S)	Ver3.0�Ή�	K.Naono	04.01.30
//	if (childid1 != -1)
	if (childid1 != -1 && childid1 != 0 )
//	MOD(E)	Ver3.0�Ή�	K.Naono	04.01.30
		m_ChildrenArray->Add(childid1);
	if (childid2 != -1)
		m_ChildrenArray->Add(childid2);

	delete	m_CurrentChild;
	m_CurrentChild = NULL;

	return childid1;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFWriteManagerC.cpp                    �쐬���F2001.06.18
//
//  �P�D�@�\�T�v
//      Sheet Assembly �v�f�̏o��
//
//  �Q�D�C���^�[�t�F�[�X
//      BOOL CloseAssembly()
//
//	    ����: �^			  ������			    ���e
//      		�Ȃ�
//
//	    ���A�l	
//            ���펞�FTRUE
//			  �ُ펞�FFALSE
//      
//  �R�D����
//	    ����ԍ�    ���t��         �S����    �T�v
//      �쐬		2001.06.18    ���X��(FQS)
//
//------------------------------------------------------------

BOOL SXFWriteManagerC::CloseAssembly()
{
	/* �p�����ݒ肳��Ă��Ȃ� */
	if( m_SheetAssemblyFlag != TRUE){
		SXFErrorMsgC::RecordError(SXFNOTSETSHEET,DEF_SHEET,0);
		return FALSE;//no sheet assembly
	}

	//assembly have not child error
	if (m_ChildrenArray->GetSize() <= 0){
		SXFErrorMsgC::RecordError(SXFNOTFEATURE,"",0);
		return FALSE;
	}

	int assemblyid1 = 0;
	int assemblyid2 = 0;
	int pointid = 0;
	double pointx = 0.0;
	double pointy = 0.0;
	/* �A�Z���u���v�f��Mapping */
	if(! m_CurrentAssembly->MappingAssembly(m_ChildrenArray,
			assemblyid1, assemblyid2, pointid, pointx, pointy ))
		return FALSE;

	return TRUE;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFWriteManagerC.cpp                    �쐬���F2001.06.18
//
//  �P�D�@�\�T�v
//      Assembly Type�̎擾
//
//  �Q�D�C���^�[�t�F�[�X
//      int GetAssemType()
//
//	    ����: �^			  ������			    ���e
//      		�Ȃ�
//
//	    ���A�l	
//            ���펞�FAssembly Type
//			  �ُ펞�F
//      
//  �R�D����
//	    ����ԍ�    ���t��         �S����    �T�v
//      �쐬		2001.06.18    ���X��(FQS)
//
//------------------------------------------------------------
int SXFWriteManagerC::GetAssemType()
{
	return m_AssemType;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFWriteManagerC.cpp                    �쐬���F2001.06.18
//
//  �P�D�@�\�T�v
//      ����Sfig Assembly�o�^���邱�Ƃ����邩�ǂ���Check
//
//  �Q�D�C���^�[�t�F�[�X
//      BOOL CheckSameSfig( LPCTSTR IN_Name)
//
//	    ����: �^			  ������			    ���e
//            LPCTSTR         IN_Name              Sfig Name
//
//	    ���A�l	
//            ���펞�FTRUE
//			  �ُ펞�FFALSE
//      
//  �R�D����
//	    ����ԍ�    ���t��         �S����    �T�v
//      �쐬		2001.06.18    ���X��(FQS)
//
//------------------------------------------------------------
BOOL SXFWriteManagerC::CheckSameSfig( LPCTSTR IN_Name)
{
//	MOD(S)	�`���[�j���O�Ή�	K.Naono	03.07.08
/*
	for(int i=0;i<m_SfigorgTable.GetSize();i++){
		if(IN_Name == m_SfigorgTable[i].name)
			return FALSE;
	}
*/
	SXFSFIGORGCHECK*	pSfigOrg = NULL ;
	if( m_mapSfigOrg.Lookup(IN_Name, (void*&)pSfigOrg) ) {
		return FALSE;
	}
//	MOD(S)	�`���[�j���O�Ή�	K.Naono	03.07.08

	return TRUE;
}

//	DEL(S)	�`���[�j���O�Ή�	K.Naono	03.07.08
/*
//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFWriteManagerC.cpp                    �쐬���F2001.06.18
//
//  �P�D�@�\�T�v
//      ����Sfig Assembly�o�^���邱�Ƃ����邩�ǂ���Check
//
//  �Q�D�C���^�[�t�F�[�X
//      BOOL CheckSameSfig( LPCTSTR IN_Name)
//
//	    ����: �^			  ������			    ���e
//            LPCTSTR         IN_Name              Sfig Name
//
//	    ���A�l	
//            ���펞�FTRUE
//			  �ُ펞�FFALSE
//      
//  �R�D����
//	    ����ԍ�    ���t��         �S����    �T�v
//      �쐬		2001.06.18    ���X��(FQS)
//
//------------------------------------------------------------
BOOL SXFWriteManagerC::SfigNameCheck( LPCTSTR IN_Name)
{
	for(int i=0;i<m_SfigorgTable.GetSize();i++){
		if ( m_SfigorgTable[i].name == IN_Name && m_SfigorgTable[i].error == 1){ 
			return TRUE;
		}
	}
	return FALSE;

}
*/
//	DEL(E)	�`���[�j���O�Ή�	K.Naono	03.07.08

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFWriteManagerC.cpp                    �쐬���F2001.06.18
//
//  �P�D�@�\�T�v
//      Invisibility�v�f��Mapping
//
//  �Q�D�C���^�[�t�F�[�X
//      BOOL MappingInvisibility()
//
//	    ����: �^			  ������			    ���e
//				�Ȃ�
//
//	    ���A�l	
//            ���펞�FTRUE
//			  �ُ펞�FFALSE
//      
//  �R�D����
//	    ����ԍ�    ���t��         �S����    �T�v
//      �쐬		2001.06.18    ���X��(FQS)
//
//------------------------------------------------------------
BOOL SXFWriteManagerC::MappingInvisibility()
{

	if (m_InvisibilityCurveTable.GetSize() > 0){
		SXFWriteMappingManagerC* mappingmanager = new SXFWriteMappingManagerC(m_Part21File); 
		if( !mappingmanager->MappingInvisibility(&m_InvisibilityCurveTable)) {
			delete mappingmanager;
			return FALSE;
		}
		delete mappingmanager;
		return TRUE;
	}
	else
		return FALSE;

}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFWriteManagerC.cpp                    �쐬���F2001.06.18
//
//  �P�D�@�\�T�v
//      �A�Z���u���v�f�̍\���̂��G���[�������ꍇ�̏���
//      set����Ă���A�Z���u����Mapping����
//
//  �Q�D�C���^�[�t�F�[�X
//      int ErrorAssembly()
//
//	    ����: �^			  ������			    ���e
//				�Ȃ�
//
//	    ���A�l	
//            ���펞�F1
//			  �ُ펞�F-1
//      
//  �R�D����
//	    ����ԍ�    ���t��         �S����    �T�v
//      �쐬		2001.06.18    ���X��(FQS)
//		�X�V		2001.09.18		K.Naono		�n�b�`���O��Q�Ή�
//
//------------------------------------------------------------
int SXFWriteManagerC::ErrorAssembly()
{
	//�A�Z���u���͊J���Ȃ�
	m_AssemType = -1;
	//assembly must have children
	if ( m_ChildrenArray !=NULL && m_ChildrenArray->GetSize() > 0){
		int assemblyid1 = 0;
		int assemblyid2 = 0;
		int pointid = 0;

		double pointx = 0.0;
		double pointy = 0.0;

		if( m_PointN && m_PointX )
			pointx=m_PointX/m_PointN;
		if( m_PointN && m_PointY )
			pointy=m_PointY/m_PointN;
		/* Mapping */
		if(! m_CurrentAssembly->MappingAssembly(m_ChildrenArray,
							assemblyid1, assemblyid2, pointid, pointx, pointy ))
			return -1;

		m_PointX = 0.0;
		m_PointY = 0.0;
		m_PointN = 0;

//	MOD(S)	�n�b�`���O��Q�Ή�	K.Naono		01.09.18
//		m_PointTable.Add(pointid);
		SXF_POINT	point ;
		point.x = pointx ; point.y = pointy ;
		m_PointTable.Add(point) ;
//	MOD(E)	�n�b�`���O��Q�Ή�	K.Naono		01.09.18
		if(m_CurveViewFlag == 0){
			m_InvisibilityCurveTable.Add(assemblyid1);
		}
		/*������ð��قɒǉ�*/
		m_AssemblyTable.Add(assemblyid2);
		/*�ް��̸ر*/
		m_ChildrenArray->RemoveAll();
	}
	else{
		if (!m_FirstAssemblyFlag && !m_ErrorFlag)
			/* �A�Z���u���v�f��ɗv�f���Ȃ� */
			SXFErrorMsgC::RecordError(SXFNOTFEATURE,"",0);
	}

	/*�������ް���ر*/
	if(m_CurrentAssembly != NULL)
		m_CurrentAssembly->ClearData();

	/* ErrorFlag��ON */
	m_ErrorFlag = TRUE;

	return 1;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFWriteManagerC.cpp                    �쐬���F2001.07.08
//
//  �P�D�@�\�T�v
//      ���ɔz�u���ꂽ���`�F�b�N
//
//  �Q�D�C���^�[�t�F�[�X
//      BOOL SfigLocateCheck( LPCTSTR IN_Name)
//
//	    ����: �^			  ������			    ���e
//            LPCTSTR         IN_Name              Sfig Name
//
//	    ���A�l	
//            ���펞�FTRUE
//			  �ُ펞�FFALSE
//      
//  �R�D����
//	    ����ԍ�    ���t��         �S����    �T�v
//      �쐬		2001.07.08     ���X��(FQS)
//
//------------------------------------------------------------
BOOL SXFWriteManagerC::SfigLocateCheck(LPCTSTR IN_Name)
{
//	MOD(S)	�`���[�j���O�Ή�	K.Naono	03.07.08
/*
	for(int i=0;i<m_SfigorgTable.GetSize();i++){
		if ( m_SfigorgTable[i].name == IN_Name){
			if (m_SfigorgTable[i].locate_flag == -1){
				m_SfigorgTable[i].locate_flag = 1;
				return TRUE;
			}
		}
	}
*/
	SXFSFIGORGCHECK*	pSfigOrg = NULL ;
	if( m_mapSfigOrg.Lookup(IN_Name, (void*&)pSfigOrg) ) {
		if( pSfigOrg->locate_flag == -1 ) {
			pSfigOrg->locate_flag = 1 ;
			return TRUE ;
		}
	}
//	MOD(E)	�`���[�j���O�Ή�	K.Naono	03.07.08
	return FALSE;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFWriteManagerC.cpp                    �쐬���F2001.2.23
//
//  �P�D�@�\�T�v
//      �����}�`���ɑΉ����镡���}�`��ʂ��擾����
//
//  �Q�D�C���^�[�t�F�[�X
//      BOOL GetSfigFlg( LPCTSTR IN_Name,
//							int* OUT_Type,
//							int* OUT_LocFlg)
//
//	    ����: �^			  ������	    ���e
//            LPCTSTR         IN_Name       Sfig Name
//			  int*			  OUT_Type		�����}�`���
//			  int*			  OUT_LocFlg	�z�u�t���O
//											(0�F���z�u 1:�z�u��)
//
//	    ���A�l	
//            ���펞�FTRUE		�Ή������ʂ���
//			  �ُ펞�FFALSE		�Ή������ʂȂ�
//      
//  �R�D����
//	    ����ԍ�    ���t��         �S����    �T�v
//      �쐬		2001.2.23	   ���X��(FQS)(FQS)
//
//------------------------------------------------------------
BOOL SXFWriteManagerC::GetSfigFlg( LPCTSTR IN_Name,
									int* OUT_Type,
									int* OUT_LocFlg)
{
	*OUT_Type = -1;
	*OUT_LocFlg = -1;

//	MOD(S)	�`���[�j���O�Ή�	K.Naono	03.07.08
/*
	for(int i=0;i<m_SfigorgTable.GetSize();i++){
		if ( m_SfigorgTable[i].name == IN_Name 
					&& m_SfigorgTable[i].error == 1){ 
			*OUT_Type = m_SfigorgTable[i].type;
			*OUT_LocFlg = m_SfigorgTable[i].locate_flag;
			return TRUE;
		}
	}
*/
	SXFSFIGORGCHECK*	pSfigOrg = NULL ;
	if( m_mapSfigOrg.Lookup(IN_Name, (void*&)pSfigOrg) ) {
		if( pSfigOrg->error == 1 ) {
			*OUT_Type	= pSfigOrg->type ;
			*OUT_LocFlg	= pSfigOrg->locate_flag ;
			return TRUE ;
		}
	}
//	MOD(E)	�`���[�j���O�Ή�	K.Naono	03.07.08
	return FALSE;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFWriteManagerC.cpp                    �쐬���F2001.2.23
//
//  �P�D�@�\�T�v
//      �����}�`���ɑΉ����镡���}�`��ʂ��擾����
//
//  �Q�D�C���^�[�t�F�[�X
//      BOOL SetLocFlg( LPCTSTR IN_Name)
//
//	    ����: �^			  ������	    ���e
//            LPCTSTR         IN_Name       Sfig Name
//
//	    ���A�l	
//            ���펞�FTRUE		�Ή�����t���O����
//			  �ُ펞�FFALSE		�Ή�����t���O�Ȃ�
//      
//  �R�D����
//	    ����ԍ�    ���t��         �S����		�T�v
//      �쐬		2001.2.23		���X��(FQS)(FQS)
//
//------------------------------------------------------------
BOOL SXFWriteManagerC::SetLocFlg( LPCTSTR IN_Name)
{
//	MOD(S)	�`���[�j���O�Ή�	K.Naono	03.07.08
/*
	for(int i=0;i<m_SfigorgTable.GetSize();i++){
		if ( m_SfigorgTable[i].name == IN_Name 
			&& m_SfigorgTable[i].error == 1){ 
			m_SfigorgTable[i].locate_flag = 1;
			return TRUE;
		}
	}
*/
	SXFSFIGORGCHECK*	pSfigOrg = NULL ;
	if( m_mapSfigOrg.Lookup(IN_Name, (void*&)pSfigOrg) ) {
		if( pSfigOrg->error == 1 ) {
			pSfigOrg->locate_flag = 1 ;
			return TRUE ;
		}
	}
//	MOD(E)	�`���[�j���O�Ή�	K.Naono	03.07.08
	return FALSE;
}

//------------------------------------------------------------
//	All Rights Reserved,(c) JACIC 2001
//	SXFWriteManagerC.cpp                    �쐬���F2001.2.23
//
//  �P�D�@�\�T�v
//      ʯ�ݸފO�`�E������ID����`����Ă��邩�`�F�b�N����
//
//  �Q�D�C���^�[�t�F�[�X
//      BOOL CheckHatchID( int IN_ID)
//
//	    ����: �^	������	    ���e
//            int   IN_ID       ʯ�ݸނ̊O�`��������ID
//								(�����Ȑ��̱����غ���)
//
//	    ���A�l	
//            ���펞�FTRUE		ʯ�ݸނ̊O�`����`����Ă���
//			  �ُ펞�FFALSE		ʯ�ݸނ̊O�`����`����Ă��Ȃ�
//      
//  �R�D����
//	    ����ԍ�    ���t��         �S����		�T�v
//      �쐬		2001.2.23		���X��(FQS)(FQS)
//
//------------------------------------------------------------
BOOL SXFWriteManagerC::CheckHatchID( unsigned int IN_ID){
//	MOD(S)	�`���[�j���O�Ή�	K.Naono	03.07.09
/*
	for (int i = 0; i < m_CurveTable.GetSize(); i++){
		if (m_CurveTable[i] == IN_ID)
			return TRUE;
	}
*/
	for(POSITION pos = m_CurveTable.GetHeadPosition(); pos; ) {
		if( m_CurveTable.GetNext(pos) == (int)IN_ID ) {
			return TRUE ;
		}
	}
//	MOD(E)	�`���[�j���O�Ή�	K.Naono	03.07.09
	return FALSE;
}
